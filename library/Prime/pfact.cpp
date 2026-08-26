#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 素因数分解 1回当たりO(√N) */
/* N = 10^12程度 */
/* pair<素因子, 指数> の vector を返す */
vector<pair<ll, ll>> pfact(ll n){
    if(n < 2){
        return {};
    }

    vector<pair<ll, ll>> ret;
    for(ll p=2; p*p <= n; ++p){ // 試し割り法
        ll k = 0; // 指数
        while(n % p == 0){
            n /= p;
            ++k;
        }

        if(k > 0){
            ret.emplace_back(p, k);
        }
    }
    if(n > 1){
        ret.emplace_back(n, 1);
    }

    return ret;
}

/* =========================================== */

int main(){
    ll n;
    cin >> n;

    auto res = pfact(n);
    for(auto [p, k] : res){
        cout << p << '^' << k << ' ';
    }
    cout << el;
    return 0;
}

/*
-I .
*/