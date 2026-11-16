#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* Kadane's Algorithm */
/* 連続部分列の和の最大値とその区間を求める O(N) */
struct KadaneRes {
    ll sum;
    ll l, r;  // [l, r)
};
/* [最大区間和, 左端, 右端] を返す、半開区間[l, r) */
/* 複数ある場合は最も左から始まり、その中で最も短い区間 */
/* 一つも選ばない が許可されるときは第2引数をtrue */
KadaneRes kadane(const vc<ll> &v, bool emp = false){
    if(v.empty()){
        return {-INFL, -INFL, -INFL};
    }

    int n = len(v);
    ll cur_sum = v[0];
    ll cur_l = 0;
    KadaneRes best{cur_sum, 0, 1};

    repa(i, 1, n){
        ll x = v[i];

        if(cur_sum < 0){
            cur_sum = x;
            cur_l = i;
        }
        else {
            cur_sum += x;
        }

        if(cur_sum > best.sum){
            best = {cur_sum, cur_l, i+1};
        }
    }

    if(emp && best.sum < 0){
        best = {0, -2, -1}; // 1つも選ばない
    }
    return best;
}

/* =========================================== */

/* 実行テスト */
int main(){
    vc<ll> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto [sum, l, r] = kadane(a);
    OUT(sum, l, r);
    return 0;
}

/*
ベースはGPT作成
subarray sum max
*/
