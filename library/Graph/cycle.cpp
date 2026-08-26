#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* トポロジカルソートで有向サイクル検出 */
/* 有向グラフと入次数情報が必要 */
bool cycle_tpl(const vc<vc<int>>& g, vc<int>& indeg){
    if(len(g) != len(indeg)){
        MEMO_el("[ERROR] cycle_tpl: 引数の頂点数が不正");
        return false;
    }

    int cnt = 0; // 処理済み頂点数
    queue<int> q;
    rep(i, len(indeg)){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        cnt++;

        for(int nv : g[v]){
            indeg[nv]--;
            if(indeg[nv] == 0){
                q.push(nv);
            }
        }
    }

    // 有向サイクルがある場合 全頂点ソートできない
    if(cnt != len(indeg)) return true; // 有向サイクルあり
    return false; // 有向サイクルなし
}

/* =========================================== */

// 無向グラフ 準備中
// 復元なしならUnionFind
// 復元ありなら直前の頂点に戻らないDFS

/* =========================================== */

int main(){
    return 0;
}

/*
-I .
*/