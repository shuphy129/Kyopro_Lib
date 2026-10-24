#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 偏角ソート by GPT */
// O(NlogN)

// 偏角ソート用の座標構造体
struct P {
    ll x, y; // x, y座標

    // 以下にその他の情報
    ll idx;
};

using MUL = ll; // x,y座標の値が10^10を超える場合は128bitにしてください

bool arg_cmp(const P &a, const P &b){
    auto half = [](const P &p){
        return p.y > 0 || (p.y == 0 && p.x >= 0);
    };

    bool ha = half(a), hb = half(b);
    if(ha != hb) return ha > hb;

    MUL cross = (MUL)a.x * b.y - (MUL)a.y * b.x;
    return cross > 0;
}

inline void angle_sort(vector<P> &v){
    sort(v.begin(), v.end(), arg_cmp);
}

int main(){
    vc<P> point = {
        {1, 0, 0},
        {1, 1, 1},
        {0, 1, 2},
        {-1, 1, 3},
        {-1, 0, 4},
        {-1, -1, 5},
        {0, -1, 6},
        {1, -1, 7},
        {4, 4, 8} // {1, 1} (idx:1) と偏角が同じ
    };

    angle_sort(point);
    for(auto [x, y, idx] : point){
        cout << x << ", " << y << " | " << idx << el;
    }
    return 0;
}

/*
Ctrl + /
Shift + Alt + A
*/
