#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/*
mod 2^61 - 1 の RollingHash です  結構強いです
名前の衝突がある場合は namespace で囲うと良いです
hashed[i] : s[0, i) のハッシュ結果  hashed[i + 1] = s[i] + s[i-1] * power[1] + s[i-2] * power[2] + ...
power[i] : BASE_RH ** i
get(l, r) : s[l, r) のハッシュ結果  s[r-1] + s[r-2] * power[1] + ... + s[l] * power[r - l + 1]
connect(h1, h2, h2len) : 2つのハッシュ結果からそれらを繋げたときのハッシュ結果を得ます
connect(s) : コンストラクタで渡した文字列に s を繋げたことにします  過去必要になったやつ
LCP(...) : Longest Common Prefix の長さ

head(n) : 先頭n文字のハッシュ結果 | n > s.size() の場合 s[0, i) のハッシュ結果になります
tail(n) : 末尾n文字のハッシュ結果 | n > s.size() の場合 s[0, i) のハッシュ結果になります
*/

// https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp
/* ローリングハッシュ */
const ull MOD_RH = 0x1fffffffffffffff, BASE_RH = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count() % MOD_RH;
struct RollingHash {
    vector<ull> hashed, power;
    bool set_up;
    
    static constexpr ull mask(ll a){ return (1ULL << a) - 1; }
    
    inline ull mul(ull a, ull b) const {
        //*
        __uint128_t ans = __uint128_t(a) * b;
        /*/
         // without __uint128_t
         ull a31 = a >> 31, b31 = b >> 31;
         a &= mask(31);
         b &= mask(31);
         ull x = a * b31 + b * a31;
         ull ans = (a31 * b31 << 1) + (x >> 30) + ((x & mask(30)) << 31) + a * b;
         //*/
        ans = (ans >> 61) + (ans & MOD_RH);
        if(ans >= MOD_RH) ans -= MOD_RH;
        return ans;
    }
    
    RollingHash() : set_up(false) {}
    RollingHash(const string &s) : set_up(true) {
        ll n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for(ll i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], BASE_RH);
            hashed[i + 1] = mul(hashed[i], BASE_RH) + s[i];
            if(hashed[i + 1] >= MOD_RH) hashed[i + 1] -= MOD_RH;
        }
    }

    void set(const string &s) {
        if(set_up) return;
        ll n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for(ll i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], BASE_RH);
            hashed[i + 1] = mul(hashed[i], BASE_RH) + s[i];
            if(hashed[i + 1] >= MOD_RH) hashed[i + 1] -= MOD_RH;
        }
        set_up = true;
    }
    
    /* s[l, r)のハッシュ結果 */
    ull get(ll l, ll r) const {
        ull ret = hashed[r] + MOD_RH - mul(hashed[l], power[r - l]);
        if(ret >= MOD_RH) ret -= MOD_RH;
        return ret;
    }

    /* 先頭n文字のハッシュ結果 */
    ull head(ll n) {
        ll s_len = (ll)hashed.size() - 1;
        if(n > s_len){
            n = s_len;
            MEMO("RHash.head(): WARNING! size ="); // 文字数オーバーは警告だけ出す
            MEMO_el(s_len);
        }
        return get(0, n);
    }

    /* 末尾n文字のハッシュ結果 */
    ull tail(ll n) {
        ll s_len = (ll)hashed.size() - 1;
        if(n > s_len){
            n = s_len;
            MEMO("RHash.tail(): WARNING! size ="); // 文字数オーバーは警告だけ出す
            MEMO_el(s_len);
        }
        return get(s_len - n, s_len);
    }
    
    ull connect(ull h1, ull h2, ll h2len) const {
        ull ret = mul(h1, power[h2len]) + h2;
        if(ret >= MOD_RH) ret -= MOD_RH;
        return ret;
    }
    
    void connect(const string &s){
        ll n = hashed.size() - 1, m = s.size();
        hashed.resize(n + m + 1);
        power.resize(n + m + 1);
        for(ll i = n; i < n + m; i++) {
            power[i + 1] = mul(power[i], BASE_RH);
            hashed[i + 1] = mul(hashed[i], BASE_RH) + s[i - n];
            if(hashed[i + 1] >= MOD_RH) hashed[i + 1] -= MOD_RH;
        }
    }
    
    ll LCP(const RollingHash &b, ll l1, ll r1, ll l2, ll r2) {
        ll len = min(r1 - l1, r2 - l2);
        ll low = -1, high = len + 1;
        while(high - low > 1) {
            ll mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};

/* =========================================== */

/* 文字列sから文字列tを検索 */
struct StringSearch {
    string s, t;
    int len_s, len_t;
    RollingHash rh_s, rh_t;
    ull hash_t;

    StringSearch(const string &ss, const string &tt) {
        s = ss;
        t = tt;
        len_s = s.size();
        len_t = t.size();
        rh_s.set(s);
        rh_t.set(t);
        hash_t = rh_t.hashed[len_t];
    }

    // 区間の重複ありで一致する連続部分文字列数を数える(aaaからaaが2個検出) O(|S|)
    ll count() {
        ll ret = 0;
        // [0, len_s) = 全区間から検索
        for (int i = 0; i + len_t <= len_s; ++i) {
            if(hash_t == rh_s.get(i, i + len_t)){
                ++ret;
            }
        }
        return ret;
    }

    // 区間の重複なしで一致する連続部分文字列数を数える(aaaからaaが1個検出) O(|S|)
    ll count_unique() {
        ll ret = 0;
        // [0, len_s) = 全区間から検索
        for (int i = 0; i + len_t <= len_s; ++i) {
            if(hash_t == rh_s.get(i, i + len_t)){
                ++ret;
                i += len_t - 1;
            }
        }
        return ret;
    }

    // tと初めて一致するときのsのインデックス なければ-1 O(|S|)
    int first_idx() {
        for (int i = 0; i + len_t <= len_s; ++i) {
            if(hash_t == rh_s.get(i, i + len_t)){
                return i;
            }
        }
        return -1;
    }
};

/* =========================================== */

void test_StringSearch(){
    string s = "baaacaa";
    string t = "aa";

    // baaacaa から aa を検索
    StringSearch ss(s, t);
    cout << ss.count() << el; // aaaから2個 aaから1個検出
    cout << ss.count_unique() << el; // aaaから1個 aaから1個検出
    cout << ss.first_idx() << el; // 最初にaaが現れるidxは 1
}

int main(){
    test_StringSearch();
    return 0;
}

/*
-I .
*/