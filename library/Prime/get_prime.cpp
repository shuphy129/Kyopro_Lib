#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 1 以上 N 以下の整数が素数かどうかを返す */
/* N = 10^6程度 */
vector<bool> era(int N) {
    vector<bool> isprime(N+1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int p = 2; p <= N; ++p) {
        if(!isprime[p]) continue;
        for(int q = p * 2; q <= N; q += p){
            isprime[q] = false;
        }
    }
    return isprime;
}

// 1 以上 N 以下の素数のみを抽出して返す
vector<int> get_prime(int N){
    vector<bool> isprime = era(N);
    vector<int> prime;
    rep(i, N+1){
        if(isprime[i]){
            prime.emplace_back(i);
        }
    }
    return prime;
}

/* =========================================== */

int main(){
    vc<int> prime = get_prime(1500000);
    for(int p : prime){
        cout << p << " ";
    }
    cout << el;
    return 0;
}

/*
-I .
*/