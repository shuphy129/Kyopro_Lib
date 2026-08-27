#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* string用 ランレングス圧縮 */
/* <連続数, 文字>のpair配列を返す */
vector<pair<int, char>> rle(const string &s){
    int n = s.size();
    vector<pair<int, char>> ret;

    for(int i = 0; i < n; ++i){
        if(ret.empty() || ret.back().se != s[i]){
            ret.emplace_back(1, s[i]);
        } else {
            ++ret.back().fi;
        }
    }

    return ret;
}

/* vector用 ランレングス圧縮 */
/* <連続数, 要素>のpair配列を返す */
template <class T>
vector<pair<int, T>> rle(const vector<T> &v){
    int n = v.size();
    vector<pair<int, T>> ret;

    for(int i = 0; i < n; ++i){
        if(ret.empty() || ret.back().se != v[i]){
            ret.emplace_back(1, v[i]);
        } else {
            ++ret.back().fi;
        }
    }
    
    return ret;
}

/* =========================================== */

int main(){
    string s = "aaabbabcc";
    vc<int> v = {1, 1, 1, 20, 20, 1, 30, 30, 4};
    string s2 = "0";

    DBG_vc(rle(s));
    DBG_vc(rle(v));
    DBG_vc(rle(s2));
    return 0;
}

/*
-I .
*/
