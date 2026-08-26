#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* LIS 最長増加部分列 O(NlogN) */
/* 長さのみ返す */
ll lis(const vector<ll>& v){
    ll n = v.size();
    if(n == 0) return 0;

    vector<ll> dp(n, INFL);

    rep(i, n){
        auto itr = lower_bound(dp.begin(), dp.end(), v[i]);
        *itr = v[i];
    }
    // dpに格納されている値が部分列の条件を満たしているとは限らない

    ll ret = 0;
    rep(i, n){
        if(dp[i] >= INFL) break;
        ++ret;
    }
    return ret;
}

/* =========================================== */

/* 最長増加部分列（要素復元あり）*/
vector<ll> get_lis(const vector<ll>& a) {
    int n = a.size();
    if (n == 0) return {};

    vector<ll> dp;
    // id[i] : 元の配列のどのインデックスの要素が dp[i] に対応しているか
    vector<int> id;
    // prev_idx[i] : LISにおいて、インデックス i の要素の直前に来る要素のインデックス
    vector<int> prev_idx(n, -1);

    for (int i = 0; i < n; ++i) {
        // dp 内で a[i] 以上の最初の要素を二分探索
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        int pos = distance(dp.begin(), it);

        if (it == dp.end()) {
            dp.emplace_back(a[i]);
            id.emplace_back(i);
        } else {
            *it = a[i];
            id[pos] = i;
        }

        // LIS の先頭でない限り、直前の要素のインデックスを記録
        if (pos > 0) {
            prev_idx[i] = id[pos - 1];
        }
    }

    // 復元処理
    vector<ll> lis;
    int curr = id.back();
    while (curr != -1) {
        lis.emplace_back(a[curr]);
        curr = prev_idx[curr];
    }
    reverse(lis.begin(), lis.end());

    return lis;
}

/* =========================================== */

int main(){
    vc<ll> v1 = {1, 3, 4, 4, 2, 5};
    vc<ll> v2 = {1, 5, 4, 3, 2};

    cout << lis(v1) << el;
    cout << lis(v2) << el;

    print_vc(get_lis(v1));
    print_vc(get_lis(v2));
    return 0;
}

/*
-I .
*/