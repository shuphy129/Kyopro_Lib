#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include "shuphy.hpp"
/* =========================================== */

/* 2点間の直線距離(2乗値 ユークリッド距離) */
ll dist_euc(const ll x1, const ll y1, const ll x2, const ll y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

/* マンハッタン距離 */
ll dist_man(const ll x1, const ll y1, const ll x2, const ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

/* 2次元配列 外周からの距離(0-indexed) */
ll dist_from_out(const ll ci, const ll cj, const ll h, const ll w){
    return min({ci, cj, h-ci-1, w-cj-1});
}

/* =========================================== */

int main(){
    int h, w;
    cin >> h >> w;
    vc<vc<int>> vv(h, vc<int>(w));
    rep(i, h){
        rep(j, w){
            vv[i][j] = dist_from_out(i, j, h, w);
        }
    }

    print_vv(vv);
    return 0;
}

/*
-I .
*/