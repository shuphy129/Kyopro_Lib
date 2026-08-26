#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

/* 重複[あり]昇順set */
/* 拡張multiset */
template <class T>
struct ExMultiSet {
  private:
    int val_cnt; // 要素の種類数 同じ要素を重複して数えない
  public:
    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update> st;
    map<T, int> dict; // 重複要素にidを付加する

    ExMultiSet() : val_cnt(0) {}

    // valを重複ありで昇順挿入
    bool insert(T val) {
        int id = dict[val];
        ++dict[val];
        if(id == 0){
            // 種類数が増加
            ++val_cnt;
        }
        st.insert({val, id});
        return true;
    }

    // valを1つ削除
    bool erase(T val) {
        int id = dict[val] - 1;
        if(id < 0){
            MEMO("ExMultiSet(erase): not exist! val =");
            MEMO_el(val);
            return false; // 削除対象なし
        }
        else if(id == 0){
            // 種類数が減少
            --val_cnt;
        }
        --dict[val];
        st.erase({val, id});
        return true;
    }

    // 存在判定(個数)
    int count(T val) { return dict[val]; }

    // 種類数 (同じ要素を1種類としてカウント)
    int val_count() { return val_cnt; }

    // 二分探索(返り値はidx)
    int lower_bound(T val) { return st.order_of_key({val, 0}); }
    int upper_bound(T val) { return st.order_of_key({val+1, 0}); } // 整数型前提

    // st.find_by_order(k); // k番目(0-indexed)のイテレータを返す
    // st.order_of_key(引数); // 引数以上の最初の要素がtreeの何番目か返す(idxが返るlower_bound)

    T operator[](int i) const {
        if(i >= (int)st.size()){
            MEMO("ExMultiSet(random access): idx ERROR! max_idx =");
            MEMO_el((int)st.size() - 1);
            return -1; // エラー戻り値は場合によって変える
        }
        return (*st.find_by_order(i)).fi;
    }
    int size() const { return (int)st.size(); }

    auto begin() const { return st.begin(); }
    auto end() const { return st.end(); }
};

/* =========================================== */

int main(){
    vector<int> v = {5, 3, 2, 7, 2, 4, 3};
    ExMultiSet<int> exm;

    rep(i, (int)v.size()){
        exm.insert(v[i]);
    }
    DBG_st(exm);

    MEMO_el("[count]");
    cout << exm.count(3) << el;
    cout << exm.count(6) << el;
    cout << exm.count(8) << el;

    MEMO_el("[val_count(1)]");
    cout << exm.val_count() << el;

    MEMO_el("[lower_bound]");
    cout << exm.lower_bound(3) << el;
    cout << exm.lower_bound(6) << el;
    cout << exm.lower_bound(8) << el;

    MEMO_el("[upper_bound]");
    cout << exm.upper_bound(3) << el;
    cout << exm.upper_bound(6) << el;
    cout << exm.upper_bound(8) << el;

    MEMO_el("[erase]");
    exm.erase(3);
    exm.erase(8); // 存在しない値を消してみる
    DBG_st(exm);

    MEMO_el("[random access]");
    cout << exm[3] << el; // ランダムアクセス
    cout << exm[6] << el; // ランダムアクセス(配列外)

    MEMO_el("[size]");
    cout << exm.size() << el;

    MEMO_el("[val_count(2)]");
    cout << exm.val_count() << el;

    DBG_st(exm);

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