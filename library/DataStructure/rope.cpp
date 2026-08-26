#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

#include <ext/rope>
using namespace __gnu_cxx;

/* 配列の挿入と削除をO(log N)で行う */
/* 最悪時間計算量がO(N) */
int main(){
    rope<int> v;
    rep(i, 5){
        // cin >> v[i]; // NG
        v.push_back(i);
    }
    cout << v[1] << el; // OK

    // v[i]++; // NG

    // 0-indexed
    v.erase(1, 1); // 1番目から1要素削除
    DBG_st(v);

    v.insert(3, 6); // 3番目に6を挿入
    DBG_st(v);

    return 0;
}
