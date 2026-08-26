#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include "shuphy.hpp"

#include <atcoder/modint>
using namespace atcoder;
//using mint = modint1000000007;
using mint = modint998244353;
std::ostream &operator<< (std::ostream &os, mint x){ // mintデバッグ出力用
    os << x.val(); return os;
}
/* =========================================== */

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
/* nCr前計算法 rの総和が大きくてもnが小さければ可 */
const int MAX = 510000; // nの最大値 余裕をもって
mint fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }
}

// 二項係数計算
mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n - k];
}

/* 実行テスト */
void test1(){
    // 前処理
    COMinit();

    cout << COM(4, 0).val() << el;
    cout << COM(4, 1).val() << el;
    cout << COM(4, 2).val() << el;
    cout << COM(4, 3).val() << el;
    cout << COM(4, 4).val() << el;
    cout << COM(4, 5).val() << el;

    cout << COM(0, 0).val() << el;
    cout << COM(0, 1).val() << el;
    cout << COM(-1, 0).val() << el;
    cout << COM(2, -1).val() << el;

    cout << COM(100000, 50000).val() << el;
}

/* =========================================== */

/* nCr愚直計算法 nが大きくてもrの総和が小さければ可 */
mint nCr(const ll n, const ll r){
    if(n < r) return 0;
    if (n < 0 || r < 0) return 0;
    ll cnt = min(r, n-r);
    ll tn = n;
    mint bunbo = 1, bunshi = 1;
    while(cnt--){
        bunshi *= tn;
        --tn;
        bunbo *= (cnt + 1);
    }
    return (bunshi / bunbo);
}

/* 実行テスト */
void test2(){
    cout << nCr(4, 0).val() << el;
    cout << nCr(4, 1).val() << el;
    cout << nCr(4, 2).val() << el;
    cout << nCr(4, 3).val() << el;
    cout << nCr(4, 4).val() << el;
    cout << nCr(4, 5).val() << el;

    cout << nCr(0, 0).val() << el;
    cout << nCr(0, 1).val() << el;
    cout << nCr(-1, 0).val() << el;
    cout << nCr(2, -1).val() << el;

    cout << nCr(100000, 50000).val() << el;
}

/* =========================================== */

int main(){
    MEMO_el("test1");
    test1();
    MEMO_el("test2");
    test2();
    return 0;
}

/*
-I .
*/