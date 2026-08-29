#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
using ll = long long; // 9e18 = 9*10^18
using ull = unsigned long long;

#define rep(i, n) for(int i=0; i<(n); ++i)       //  0  => n-1 [0-index]
#define rep1(i, n) for(int i=1; i<=(n); ++i)     //  1  =>  n  [1-index]
#define drep(i, n) for(int i=(n)-1; i>=0; --i)   // n-1 =>  0  [0-index]
#define drep1(i, n) for(int i=(n); i>0; --i)     //  n  =>  1  [1-index]
#define repa(i, a, n) for(int i=(a); i<(n); ++i) //  a  => n-1
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
inline ll ceil_int(ll a, ll b){ // doubleキャスト不要の切り上げ
    if(a >= 0) return (a + b - 1) / b;
    return a / b;
}
inline ll floor_int(ll a, ll b){ // doubleキャスト不要の切り捨て
    if(a % b < 0) return (a / b) - 1;
    return a / b;
}
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
using vc = vector<T>; // vc<int> = vector<int>
template <class T>
using dheap = priority_queue<T>; // 降順優先度付きキュー
template <class T>
using uheap = priority_queue<T, vector<T>, greater<>>; // 昇順優先度付きキュー
template <class T1, class T2> // pairの出力 cout << pair << el
std::ostream &operator<< (std::ostream &os, std::pair<T1,T2> p){
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <class T> // 1次元配列の出力関数 デバッグ用
inline void print_vc(const vector<T> &v, bool split_line = false) {
    if (v.empty()) { cerr << '\n'; return; }
    for (int i = 0; i < (int)v.size(); ++i) {
        cerr << v[i] << " \n"[split_line || i + 1 == (int)v.size()];
    }
}
template <class T> // 2次元配列の出力関数 デバッグ用
void print_vv(const vector<vector<T>> &vv, bool idx_print = false){
    if (vv.empty()) { cerr << '\n'; return; }
    for (int i = 0; i < (int)vv.size(); ++i) {
        if(idx_print) cerr << i << ": ";
        print_vc(vv[i]);
    }
}
template <class T, class... Ts> // デバッグ出力用
void OUT_DBG(std::string_view name, const T& a, Ts&&... b){
    const auto end = name.find_first_of(',');
    cerr << name.substr(0, end) << ": " << a;
    if constexpr (sizeof...(b) > 0){
        cerr << " | ";
        OUT_DBG(name.substr(name.find_first_not_of(' ', end + 1)), std::forward<Ts>(b)...);
    }
}
/* デバッグ出力 */
#ifndef ONLINE_JUDGE
#define MEMO(s) cerr << "\033[31m" << s << " \033[m"     // 改行なし
#define MEMO_el(s) cerr << "\033[31m" << s << "\033[m\n" // 改行あり
#define DBG(...)                                      \
    {                                                 \
        cerr << "\033[33m(line:" << __LINE__ << ") "; \
        OUT_DBG(#__VA_ARGS__, __VA_ARGS__);           \
        cerr << "\033[m\n";                           \
    }
#define DBG_vc(v)                                    \
    {                                                \
        cerr << "\033[33m(line:" << __LINE__ << ") " \
        << #v  << "(" << (int)v.size() << "):\n";    \
        print_vc(v); cerr << "\033[m";               \
    } // 1次元配列
#define DBG_vv(vv)                                   \
    {                                                \
        cerr << "\033[33m(line:" << __LINE__ << ") " \
        << #vv << "(" << (int)vv.size() << "):\n";   \
        print_vv(vv, true); cerr << "\033[m";        \
    } // 2次元配列
#define DBG_st(st)                                   \
    {                                                \
        cerr << "\033[33m(line:" << __LINE__ << ") " \
        << #st << "(" << (int)st.size() << "):\n";   \
        for(auto e : st) { cerr << e << ' '; }       \
        cerr << "\033[m\n";                          \
    } // set multiset rope
constexpr bool DEBUG = true;
#else
#define MEMO(s)
#define MEMO_el(s)
#define DBG(...)
#define DBG_vc(v)
#define DBG_vv(vv)
#define DBG_st(st)
constexpr bool DEBUG = false;
#endif
constexpr int INF = 2e9;  // 2*10^9
constexpr ll INFL = 2e18; // 2*10^18
// https://github.com/shuphy129/Kyopro_Lib/tree/main/library
/* =========================================== */

uint32_t xor128(){
    static uint32_t x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    uint32_t t;
    t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

class Timer{
    system_clock::time_point start;
    public:
        Timer() : start(system_clock::now()) {}
    
        double count(){
            duration<double> Time_ = system_clock::now() - start;
            return Time_.count();
        }

        bool is_under(double x){
            return (this -> count()) < x;
        }
};
Timer timer;

constexpr double TIME_LIMIT = 1.9; // 制限時間

/* =========================================== */

/* グローバル変数 */

/* =========================================== */

/* 入力 */
void input(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    //
}

/* 出力 */
void output(){
    //
}

/* =========================================== */

void solve(){
    //
}

/* =========================================== */

int main(){
    input();
    solve();
    output();
    if(DEBUG){
        cerr << "TIME: " << timer.count() << endl;
    }
    return 0;
}

/*

*/
