#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 引数が素数かどうか返す 1回当たりO(√N) */
/* N = 10^12程度 */
bool is_prime(ll n){
    if(n < 2){
        return false;
    }

    bool ret = true;
    for(ll p=2; p*p <= n; ++p){ // 試し割り法
        if(n % p == 0){ // pは素因数 nは素数ではない
            ret = false;
            while(n % p == 0){
                n /= p;
            }
        }
    }
    // ここで n > 1 だと素因数分解しきれていないことを示す
    // ret = false であれば n は素数
    // ret = true かつ n = 1 であれば素因数を1種類しか持たない(1素数のべき乗)

    return ret;
}

/* =========================================== */

int main(){
    ll n;
    cin >> n;

    if(is_prime(n)){
        YES;
    } else {
        NO;
    }
    return 0;
}

/*
-I .
*/