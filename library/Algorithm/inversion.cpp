#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 転倒数のためのBIT O(NlogN) */
// https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
// 配列の要素は 1以上 N以下 の必要がある
struct BIT {
  private:
    vector<int> bit;
    int N;
 
  public:
    BIT(int size) {
        N = size;
        bit.resize(N + 1);
    }
 
    // 一点更新
    void add(int a, int w) {
        for (int x = a; x <= N; x += x & -x) bit[x] += w;
    }
 
    // 1~Nまでの和を求める
    int sum(int a) {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
};

// /* デバッグ用 配列が入力として適切か */
// bool check_vc(const vc<int>& v){
//     int n = v.size();
//     rep(i, n){
//         if(v[i] <= 0 || v[i] > n) return false;
//     }
//     return true;
// }

/* 配列の転倒数を返す 配列の要素の制約を守る必要がある */
ll inversion(const vc<int>& v){
    ll ret = 0;
    int n = v.size();
    // if(DEBUG){ // 配列チェック デバッグ用
    //     if(!check_vc(v)){
    //         MEMO_el("inversion ERROR!");
    //         return -1;
    //     }
    // }
    BIT b(n);
    rep(i, n){
        ret += (i - b.sum(v[i]));
        b.add(v[i], 1);
    }
    return ret;
}

/* =========================================== */

/* 転倒数を求められるように配列を変形する */
template <class T>
vc<int> rec_vc(const vc<T>& v){
    int n = v.size();
    vc<pair<T, int>> tmp(n);
    rep(i, n){
        tmp[i] = {v[i], i};
    }
    sort(all(tmp));
    vc<int> ret(n);
    rep(i, n){
        ret[tmp[i].se] = i+1;
    }
    DBG_vc(ret);
    return ret;
}

/* =========================================== */

/* 実行テスト */
int main(){
    int n;
    cin >> n;
    vc<int> v(n);
    rep(i, n){
        cin >> v[i];
    }

    // if(!check_vc(v)){
    //     v = rec_vc(v);
    // }

    cout << inversion(v) << el;
    return 0;
}

/*
-I .
*/