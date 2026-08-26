#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 9e18 = 9*10^18
using ull = unsigned long long;
using ld = long double;
/*
#include <atcoder/all>
using namespace atcoder;
*/
/*
#include <atcoder/modint>
using namespace atcoder;
//using mint = modint; // mint::set_mod(MOD);
//using mint = modint1000000007;
using mint = modint998244353;
std::ostream &operator<< (std::ostream &os, mint x){ // mintデバッグ出力用
    os << x.val(); return os;
}
*/
#define rep(i, n) for(ll i=0; i<(n); ++i)       //  0  => n-1 [0-index]
#define rep1(i, n) for(ll i=1; i<=(n); ++i)     //  1  =>  n  [1-index]
#define drep(i, n) for(ll i=(n)-1; i>=0; --i)   // n-1 =>  0  [0-index]
#define drep1(i, n) for(ll i=(n); i>0; --i)     //  n  =>  1  [1-index]
#define repa(i, a, n) for(ll i=(a); i<(n); ++i) //  a  => n-1
#define el '\n' // フラッシュはendlを使う
#define YES cout << "Yes" << endl
#define NO  cout << "No" << endl
#define ERR cout << -1 << endl
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fi first
#define se second
#define len(v) ((int)(v).size())
#define cout_double cout << fixed << setprecision(20)
inline ll ceil_int(const ll a, const ll b){ // doubleキャスト不要の切り上げ
    if(a >= 0) return (a + b - 1) / b;
    return a / b;
}
inline ll floor_int(const ll a, const ll b){ // doubleキャスト不要の切り捨て
    if(a % b < 0) return (a / b) - 1;
    return a / b;
}
ll isqrt(ll n){ // floor(sqrt(n))を求める
    if(n <= 0) return 0;
    ll x = sqrt(n);
    while((x + 1) * (x + 1) <= n) ++x;
    while(x * x > n) --x;
    return x;
}
inline ll sum_ap(const ll a, const ll l, const ll n){ // 等差数列の和 (初項, 末項, 項数)
    return (a + l) * n / 2;
}
inline ll nc2(const ll n){ return n * (n - 1) / 2; }
inline ll nc3(const ll n){ return n * (n - 1) * (n - 2) / 6; }
template <class T>
inline bool chmax(T &a, const T &b){
    if(a < b){ a = b; return true; }
    return false;
}
template <class T>
inline bool chmin(T &a, const T &b){
    if(b < a){ a = b; return true; }
    return false;
}
template <class T>
inline void unique_erase(vector<T> &v){ // 配列をソートしユニークな値だけ残す
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
inline string substr_head(const string &s, int n){ // 文字列の先頭n文字を切り出す
    int s_len = s.size();
    if(n > s_len) n = s_len; // sの文字数を超えないように調整される
    return s.substr(0, n);
}
inline string substr_tail(const string &s, int n){ // 文字列の末尾n文字を切り出す
    int s_len = s.size();
    if(n > s_len) n = s_len; // sの文字数を超えないように調整される
    return s.substr(s_len - n);
}
template <class T>
using vc = vector<T>; // vc<int> = vector<int>
template <class T>
using vv = vector<vector<T>>;
template <class T>
using vvv = vector<vector<vector<T>>>;
template <class T, int n, size_t idx = 0> // 多次元vector生成
auto make_vc(const int (&d)[n], const T &init) noexcept {
    if constexpr (idx < n) return vector(d[idx], make_vc<T, n, idx+1>(d, init));
    else return init;
} // auto v = make_vc<int>({2, 3}, 0);
template <class T, int n>
auto make_vc(const int (&d)[n]) noexcept {
    return make_vc(d, T{});
}
template <class T>
using dheap = priority_queue<T>; // 降順優先度付きキュー
template <class T>
using uheap = priority_queue<T, vector<T>, greater<>>; // 昇順優先度付きキュー
template <class T1, class T2> // pairの出力 cout << pair << el
std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <class T> // 1次元配列の出力関数 第2引数trueで改行区切り
inline void print_vc(const vector<T> &v, bool split_line = false) {
    if (v.empty()) { cout << '\n'; return; }
    for (int i = 0; i < (int)v.size(); ++i) {
        cout << v[i] << " \n"[split_line || i + 1 == (int)v.size()];
    }
}
template <class T> // 2次元配列の出力関数 第2引数trueでidx表示
void print_vv(const vector<vector<T>> &vv, bool idx_print = false){
    if (vv.empty()) { cout << '\n'; return; }
    for (int i = 0; i < (int)vv.size(); ++i) {
        if(idx_print) cout << i << ": ";
        print_vc(vv[i]);
    }
}
template<class... T> // 可変引数 入力
void IN(T&... a){ (cin >> ... >> a); }
void OUT(){ cout << endl; }
template<class T, class... Ts> // 可変引数 空白区切り出力
void OUT(const T& a, const Ts&... b){
    cout << a;
    if constexpr (sizeof...(b) > 0){ cout << ' '; }
    OUT(b...);
}
template <class T, class... Ts> // デバッグ出力用
void OUT_DBG(std::string_view name, const T& a, Ts&&... b){
    const auto end = name.find_first_of(',');
    cout << name.substr(0, end) << ": " << a;
    if constexpr (sizeof...(b) > 0){
        cout << " | ";
        OUT_DBG(name.substr(name.find_first_not_of(' ', end + 1)), std::forward<Ts>(b)...);
    }
}
/* デバッグ出力 */
#ifndef ONLINE_JUDGE
#define MEMO(s) cout << "\033[31m" << s << " \033[m"     // 改行なし
#define MEMO_el(s) cout << "\033[31m" << s << "\033[m\n" // 改行あり
#define AC cout << "\033[32mAC\033[m\n" // 構築チェック用
#define WA cout << "\033[31mWA\033[m\n"
#define DBG(...)                                      \
    {                                                 \
        cout << "\033[33m(line:" << __LINE__ << ") "; \
        OUT_DBG(#__VA_ARGS__, __VA_ARGS__);           \
        cout << "\033[m\n";                           \
    }
#define DBG_vc(v)                                     \
    {                                                 \
        cout << "\033[33m(line:" << __LINE__ << ") "  \
        << #v  << "(" << (int)v.size() << "):\n";     \
        print_vc(v); cout << "\033[m";                \
    } // 1次元配列
#define DBG_vv(vv)                                    \
    {                                                 \
        cout << "\033[33m(line:" << __LINE__ << ") "  \
        << #vv << "(" << (int)vv.size() << "):\n";    \
        print_vv(vv, true); cout << "\033[m";         \
    } // 2次元配列
#define DBG_st(st)                                    \
    {                                                 \
        cout << "\033[33m(line:" << __LINE__ << ") "  \
        << #st << "(" << (int)st.size() << "):\n";    \
        for(auto e : st) { cout << e << ' '; }        \
        cout << "\033[m\n";                           \
    } // set multiset rope
constexpr bool DEBUG = true;
#else
#define MEMO(s) do {} while(0)
#define MEMO_el(s) do {} while(0)
#define AC do {} while(0)
#define WA do {} while(0)
#define DBG(...) do {} while(0)
#define DBG_vc(v) do {} while(0)
#define DBG_vv(vv) do {} while(0)
#define DBG_st(st) do {} while(0)
constexpr bool DEBUG = false;
#endif
const int INF = 2e9;  // 2*10^9
//const int INF = 1'073'741'823; // 2倍する場合
const ll INFL = 2e18; // 2*10^18
// https://github.com/shuphy129/Kyopro_Lib/tree/main/library
/* =========================================== */

int main(){
    // ios::sync_with_stdio(false);
	// cin.tie(nullptr);
    return 0;
}

/*
Ctrl + /
Shift + Alt + A
*/
