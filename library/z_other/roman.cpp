#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* ローマ数字に変換する */
/* 1以上4000未満 */
const string r = "IVXLCDM";
string roman(int n){
    int k = 0; // r参照idx
    string a = "";
    for(; n > 0; n /= 10){
        int d = n % 10;
        if(d == 9){
            a = a + r[k+2] + r[k];
        }
        else {
            if(d != 4) a += string(d%5, r[k]);
            else a = a + r[k+1] + r[k];
            if(d > 4) a += r[k+1];
        }
        k += 2;
    }
    reverse(a.begin(), a.end());
    return a;
}

/* =========================================== */

int main(){
    int n;
    cin >> n;
    cout << roman(n) << el;
    return 0;
}
