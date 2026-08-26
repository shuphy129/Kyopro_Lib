#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

// https://github.com/atcoder/live_library/blob/master/cc.cpp
/* 座標圧縮 */
template <class T>
struct CC {
    bool initialized;
    vector<T> xs;
    CC() : initialized(false) {}

    // 圧縮前のデータを1つずつ追加
    void add(T val) { xs.emplace_back(val); }
    // 圧縮前の配列を丸ごと追加
    void add(vector<T> v) {
        for(auto val : v){
            xs.emplace_back(val);
        }
    }

    // 座標圧縮 勝手に実行されます
    void init() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        initialized = true;
    }

    // 圧縮前のデータから圧縮後のインデックスを取得 O(logN)
    ll operator()(T tar) {
        if(!initialized) init();
        auto itr = lower_bound(xs.begin(), xs.end(), tar);
        if(itr == xs.end() || *itr != tar){ // 存在しなければ警告だけ出す
            MEMO("CC(): not exist WARNING! val =");
            MEMO_el(tar);
        }
        return itr - xs.begin();
    }

    // 圧縮後のインデックスから元データを取得
    T operator[](ll i) {
        if(!initialized) init();
        if(i >= (ll)xs.size()){ // 配列外
            MEMO("CC[]: idx ERROR! max_idx =");
            MEMO_el((int)xs.size() - 1);
            return -1; // 仮で-1を返す
        }
        return xs[i];
    }

    int size() {
        if(!initialized) init();
        return (int)xs.size();
    }
};

/* =========================================== */

int main(){
    CC<int> cc;

    // 圧縮前のデータ
    vc<int> v = {1, 5, 7, 9, 100};
    int a = 12;

    // データの追加
    cc.add(v);
    cc.add(a);

    // 圧縮は他メソッド呼び出し時に勝手に実行

    // 元データが何番目か取得 cc(data)
    rep(i, len(v)){
        cout << v[i] << " => ";
        cout << cc(v[i]) << el;
    }
    cout << a << " => ";
    cout << cc(a) << el;



    cout << "====================" << el;
    rep(i, cc.size()){
        cout << cc[i] << " ";
    }
    cout << el;

    return 0;
}

/*
-I .
*/