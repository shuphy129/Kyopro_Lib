#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

// 文字列を連結したときに辞書順で降順になる (辞書順最大の連結)
bool cmp_concat(const string &a, const string &b){
    return a+b > b+a;
}

// 文字列を10進表記にしたときに降順になる(leading-0に注意)
bool cmp_strnum(const string &a, const string &b){
    if(a.size() == b.size()) return a > b;
    return a.size() > b.size();
}

/* =========================================== */

struct Frac {
    ll top; // 分子 top
    ll btm; // 分母 bottom
    int idx;

    friend std::ostream& operator<<(std::ostream& os, const Frac& f){
        os << f.top << " / " << f.btm << " [idx: " << f.idx << "]";
        return os;
    }
};
// 分数ソート 昇順になる(同じならidx昇順)
bool cmp_frac(const Frac &a, const Frac &b){
    if(a.top * b.btm == b.top * a.btm) return a.idx < b.idx;
    return a.top * b.btm < b.top * a.btm;
}

/* =========================================== */

int main(){
    vc<Frac> v = {{4, 6, 2}, {2, 3, 0}, {2, 7, 1}};
    sort(all(v), cmp_frac);
    rep(i, 3){
        cout << v[i] << el;
    }
    return 0;
}

/*
-I .
*/