#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include "shuphy.hpp"
/* =========================================== */

/* 4方向 右下左上 */
const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};
//const char dc[4] = {'R', 'D', 'L', 'U'};

/*
const int di[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
*/

int h, w;

/* 範囲外ならtrue */
bool out_grid(const int i, const int j){
    return (!(i >= 0 && i < h && j >= 0 && j < w));
}

/* 左上から右下に番号(0-indexed)を付ける */
int get_id(int i, int j){
    return i*w + j;
}
/*
0 1 2 3
4 5 6 7
*/

/* 方向をidxに変換 */
int dir2idx(const char c){
    if(c == 'R') return 0; // 右
    if(c == 'D') return 1; // グリッド下 2次元平面上
    if(c == 'L') return 2; // 左
    if(c == 'U') return 3; // グリッド上 2次元平面下
    return -1; // 配列外参照に注意
}

/* 移動先の座標を取得 */
void n_pos(int &ni, int &nj, const int ci, const int cj, const int d){
    ni = ci + di[d]; nj = cj + dj[d];
}

int main(){
    return 0;
}
