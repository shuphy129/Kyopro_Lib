#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* エラトステネスの篩 + 高速素因数分解 */
/* 2~Nの連続した値を素因数分解できる N = 10^6程度 */
struct Era{
    // 素数booleanテーブル
    vector<bool> isprime;
    
    // 整数 i を割り切る最小の素数
    vector<int> minfactor;

    // コンストラクタ
    Era(int N) : isprime(N+1, true), minfactor(N+1, -1){
        isprime[1] = false;
        minfactor[1] = 1;

        // 篩
        for(int p = 2; p <= N; ++p){
            if(!isprime[p]) continue;
            minfactor[p] = p;
            
            for(int q = p * 2; q <= N; q += p){
                isprime[q] = false;
                if(minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解
    // pair <素因子, 指数> の vector を返す
    vector<pair<int, int>> factorize(int n){
        vector<pair<int, int>> res;
        while(n > 1){
            int p = minfactor[n];
            int exp = 0;

            while(minfactor[n] == p){
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }  
};

/* 使用例 */
void testEra(){
    int n = 6;
    // 2~nまで素因数分解する
    Era er(n); // コンストラクタで素因数分解の下準備

    repa(i, 2, n+1){
        auto pf = er.factorize(i); // iを素因数分解
        cout << i << ": ";
        rep(j, len(pf)){
            // pf[j].fi = 素因数, pf[j].se = 指数
            if(j > 0) cout << " * ";
            cout << pf[j].fi << "^" << pf[j].se;
        }
        cout << el;
    }
}

int main(){
    testEra();
    return 0;
}

/*
-I .
*/