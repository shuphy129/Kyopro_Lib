#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* string用 ランレングス圧縮 */
/* <文字, 連続数>のpair配列を返す */
vector<pair<char, int>> rle(const string &s){
    int n = s.size();
    vector<pair<char, int>> ret;

    for(int i = 0; i < n; ++i){
        if(ret.empty() || ret.back().fi != s[i]){
            ret.emplace_back(s[i], 1);
        } else {
            ++ret.back().se;
        }
    }

    return ret;
}

/* vector用 ランレングス圧縮 */
/* <要素, 連続数>のpair配列を返す */
template <class T>
vector<pair<T, int>> rle(const vector<T> &v){
    int n = v.size();
    vector<pair<T, int>> ret;

    for(int i = 0; i < n; ++i){
        if(ret.empty() || ret.back().fi != v[i]){
            ret.emplace_back(v[i], 1);
        } else {
            ++ret.back().se;
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