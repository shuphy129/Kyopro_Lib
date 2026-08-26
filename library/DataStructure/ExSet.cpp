#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

/* 重複[無し]昇順set */
/* 拡張set */
template <class T>
struct ExSet {
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> st;

    bool insert(T val) {
        st.insert(val);
        return true;
    }

    bool erase(T val) {
        if(st.erase(val) == 0){
            MEMO("ExSet(erase): not exist! val =");
            MEMO_el(val);
            return false; // 削除対象なし
        }
        return true;
    }

    // 存在判定(01)
    int count(T val) {
        int idx = st.order_of_key(val);
        if(idx >= (int)st.size()) return 0;
        return ((*st.find_by_order(idx) == val) ? 1 : 0);
    }

    // 種類数 (size()と同値)
    int val_count() { return (int)st.size(); }

    // 二分探索(返り値はidx)
    int lower_bound(T val) { return st.order_of_key(val); }
    int upper_bound(T val) { return st.order_of_key(val+1); } // 整数型前提

    // st.find_by_order(k); // k番目(0-indexed)のイテレータを返す
    // st.order_of_key(引数); // 引数以上の最初の要素がtreeの何番目か返す(idxが返るlower_bound)

    T operator[](int i) const {
        if(i >= (int)st.size()){
            MEMO("ExSet(random access): idx ERROR! max_idx =");
            MEMO_el((int)st.size() - 1);
            return -1; // エラー戻り値は場合によって変える
        }
        return *st.find_by_order(i);
    }
    int size() const { return (int)st.size(); }

    auto begin() const { return st.begin(); }
    auto end() const { return st.end(); }
};

/* =========================================== */

int main(){
    vector<int> v = {5, 3, 2, 7, 2, 4, 3};
    ExSet<int> exs;

    rep(i, (int)v.size()){
        exs.insert(v[i]);
    }
    DBG_st(exs);

    MEMO_el("[count]");
    cout << exs.count(3) << el;
    cout << exs.count(6) << el;
    cout << exs.count(8) << el;

    MEMO_el("[val_count(1)]");
    cout << exs.val_count() << el;

    MEMO_el("[lower_bound]");
    cout << exs.lower_bound(3) << el;
    cout << exs.lower_bound(6) << el;
    cout << exs.lower_bound(8) << el;

    MEMO_el("[upper_bound]");
    cout << exs.upper_bound(3) << el;
    cout << exs.upper_bound(6) << el;
    cout << exs.upper_bound(8) << el;

    MEMO_el("[erase]");
    exs.erase(3);
    exs.erase(8); // 存在しない値を消してみる
    DBG_st(exs);

    MEMO_el("[random access]");
    cout << exs[3] << el; // ランダムアクセス
    cout << exs[6] << el; // ランダムアクセス(配列外)

    MEMO_el("[size]");
    cout << exs.size() << el;

    MEMO_el("[val_count(2)]");
    cout << exs.val_count() << el;

    DBG_st(exs);

    return 0;
}

/*
・setのランダムアクセスが O(logN) で可能
・setの二分探索からのindex取得が O(logN) で可能
・定数倍は若干重い
・ソート不可のvectorの挿入・削除目的であれば rope を使用(定数倍はかなり重い)

[特に拡張multisetについて]
・種類数(val_count)のみ知りたい場合はmap単体を使う方が速い
  => 特に種類番号が 1 ~ 1e6 程度であればvectorで十分
・挿入するvalが 1 ~ 1e6 程度であればmapをvectorにして若干速くできる
  => 高速化としては弱く、Tをintに置き換える必要もある
*/