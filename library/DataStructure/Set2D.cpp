#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 行と列方向のsetを持つ */
struct Set2D {
    vc<set<int>> row, col;
    int H, W;

    Set2D(int h, int w) : row(h), col(w), H(h), W(w) {}

    // 挿入 0-indexed
    void insert(int i, int j) {
        row[i].insert(j);
        col[j].insert(i);
    }

    // 削除 0-indexed 削除した要素数を返す
    int erase(int i, int j) {
        if(i < 0 || j < 0) return 0;
        if(!row[i].count(j)) return 0;
        row[i].erase(j);
        col[j].erase(i);
        return 1;
    }

    // i行目の要素をすべて削除 0-indexed 削除した要素数を返す
    int erase_row(int i) {
        for(auto c : row[i]) {
            col[c].erase(i);
        }
        int ret = row[i].size();
        row[i].clear();
        return ret;
    }

    // j列目の要素をすべて削除 0-indexed 削除した要素数を返す
    int erase_col(int j) {
        for(auto r : col[j]) {
            row[r].erase(j);
        }
        int ret = col[j].size();
        col[j].clear();
        return ret;
    }

    // 存在判定
    int contain(int i, int j) {
        return row[i].count(j);
    }
    int count(int i, int j) {
        return row[i].count(j);
    }

    // 二分探索 イテレータを返す
    auto lower_row(int i, int tar) {
        return row[i].lower_bound(tar);
    }
    auto upper_row(int i, int tar) {
        return row[i].upper_bound(tar);
    }
    auto lower_col(int j, int tar) {
        return col[j].lower_bound(tar);
    }
    auto upper_col(int j, int tar) {
        return col[j].upper_bound(tar);
    }

    // i行目の内、jの一つ左の要素を返す((i, j)を含まない) なければ-1
    int left(int i, int j) {
        auto it = row[i].lower_bound(j);
        if(it == row[i].begin()) return -1;
        return *prev(it);
    }
    // i行目の内、jの一つ右の要素を返す((i, j)を含まない) なければ-1
    int right(int i, int j) {
        auto it = row[i].upper_bound(j);
        if(it == row[i].end()) return -1;
        return *it;
    }
    // j列目の内、iの一つ上の要素を返す((i, j)を含まない) なければ-1
    int up(int i, int j) {
        auto it = col[j].lower_bound(i);
        if(it == col[j].begin()) return -1;
        return *prev(it);
    }
    // j列目の内、iの一つ下の要素を返す((i, j)を含まない) なければ-1
    int down(int i, int j) {
        auto it = col[j].upper_bound(i);
        if(it == col[j].end()) return -1;
        return *it;
    }

    auto begin_row(int i) const { return row[i].begin(); }
    auto end_row(int i) const { return row[i].end(); }
    auto begin_col(int j) const { return col[j].begin(); }
    auto end_col(int j) const { return col[j].end(); }

    int size_row(int i) const { return (int)row[i].size(); } // i行目の要素数
    int size_col(int j) const { return (int)col[j].size(); } // j列目の要素数

    // 全要素数 O(min(H, W)) eraseの戻り値で差分更新もできます
    int count_all() {
        int ret = 0;
        if(H < W){
            for(int i = 0; i < H; ++i) {
                ret += (int)row[i].size();
            }
        }
        else {
            for(int j = 0; j < W; ++j) {
                ret += (int)col[j].size();
            }
        }
        return ret;
    }
};

/* =========================================== */

// ABC370-Dの例
int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int h, w, q;
    IN(h, w, q);
    Set2D st(h, w);
    rep(i, h){
        rep(j, w){
            st.insert(i, j);
        }
    }

    int rem = h * w;
    while(q--){
        int r, c;
        IN(r, c);
        --r; --c;

        if(st.count(r, c)){
            // (r, c)を削除
            rem--;
            st.erase(r, c);
        }
        else {
            // (r, c)の上下左右を削除
            int le = st.left(r, c);
            int ri = st.right(r, c);
            int u = st.up(r, c);
            int d = st.down(r, c);

            rem -= st.erase(r, le);
            rem -= st.erase(r, ri);
            rem -= st.erase(u, c);
            rem -= st.erase(d, c);
        }
    }

    cout << rem << el;
    return 0;
}
