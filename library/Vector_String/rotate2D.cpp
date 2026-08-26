#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 2次元配列の回転 O(H*W) */
/* 右に90度 */
template <class T>
vc<vc<T>> rotate_r90(const vc<vc<T>>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<vc<T>> ret(w, vc<T>(h));
    rep(j, w){
        drep(i, h){
            ret[j][h-i-1] = vv[i][j];
        }
    }
    return ret;
}

/* 左に90度 */
template <class T>
vc<vc<T>> rotate_l90(const vc<vc<T>>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<vc<T>> ret(w, vc<T>(h));
    drep(j, w){
        rep(i, h){
            ret[w-j-1][i] = vv[i][j];
        }
    }
    return ret;
}

/* 180度 */
template <class T>
vc<vc<T>> rotate_180(const vc<vc<T>>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<vc<T>> ret(h, vc<T>(w));
    rep(i, h){
        rep(j, w){
            ret[h-i-1][w-j-1] = vv[i][j];
        }
    }
    return ret;
}

/* 転置 */
template <class T>
vc<vc<T>> transpose(const vc<vc<T>>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<vc<T>> ret(w, vc<T>(h));
    rep(j, w){
        rep(i, h){
            ret[j][i] = vv[i][j];
        }
    }
    return ret;
}

/* =========================================== */

/* 右に90度 string用 */
vc<string> rotate_r90(const vc<string>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<string> ret(w, "");
    rep(j, w){
        drep(i, h){
            ret[j] += vv[i][j];
        }
    }
    return ret;
}

/* 左に90度 string用 */
vc<string> rotate_l90(const vc<string>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<string> ret(w, "");
    drep(j, w){
        rep(i, h){
            ret[w-j-1] += vv[i][j];
        }
    }
    return ret;
}

/* 180度 string用 */
vc<string> rotate_180(const vc<string>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<string> ret(h, "");
    rep(i, h){
        rep(j, w){
            ret[h-i-1] += vv[i][w-j-1];
        }
    }
    return ret;
}

/* 転置 string用 */
vc<string> transpose(const vc<string>& vv){
    int h = vv.size();
    int w = vv[0].size();
    vc<string> ret(w, "");
    rep(j, w){
        rep(i, h){
            ret[j] += vv[i][j];
        }
    }
    return ret;
}

/* =========================================== */

int main(){
    vc<vc<char>> vv = {{'a', 'b', 'c'}, {'x', 'y', 'z'}};
    print_vv(vv);

    vc<vc<char>> rv = rotate_r90(vv);
    print_vv(rv);

    rv = rotate_180(vv);
    print_vv(rv);

    rv = rotate_l90(vv);
    print_vv(rv);

    vc<string> vvi = {"123", "456"};
    vc<string> rvi = transpose(vvi);
    print_vc(rvi, true);

    rvi = transpose(rvi);
    print_vc(rvi, true);

    return 0;
}

/*
-I .
*/