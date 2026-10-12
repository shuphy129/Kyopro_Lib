#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 頂点rootを根としたときの部分木のサイズを計算してvectorを返す */
/* 部分木のサイズ = 自分+子孫の頂点数 */
/* 基本的に無向木 */
ll dfs_subtree_size(int v, int p, vc<vc<int>> &g, vc<ll> &ret){
    ++ret[v];
    for(int nv : g[v]){
        if(nv == p) continue; // 親
        ret[v] += dfs_subtree_size(nv, v, g, ret);
    }
    return ret[v];
}
// 呼び出す関数はコレ↓
// root = 根とする頂点番号(0-indexed), g = (無向)木
vc<ll> subtree_size(int root, vc<vc<int>> &g){
    int n = len(g);
    vc<ll> ret(n, 0);
    dfs_subtree_size(root, -1, g, ret);
    return ret;
}

/* =========================================== */

/* 木上のimos */
/* 頂点rootを根として葉の方向へ 配列imos の累積和を取る */
/* imos自体を書き換えるので注意 */
/* root = 根とする頂点番号(0-indexed), imos = 累積和を取る前の配列, g = (無向)木 */
void tree_imos(int root, vc<ll> &imos, vc<vc<int>> &g){
    int n = len(g);
    vc<bool> vis(n, false);
    vis[root] = true;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv : g[v]){
            if(vis[nv]) continue;

            vis[nv] = true;
            imos[nv] += imos[v];
            q.push(nv);
        }
    }
}

/* =========================================== */

int main(){
    return 0;
}

/*
-I .
*/