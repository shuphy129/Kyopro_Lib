#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

// 秒を年日時分秒に変換
struct Time {
    ll y, d, h, m, s;
    ll D = 365; // 365日
    ll H = 24;  // 24時間
    ll M = 60;  // 60分
    ll S = 60;  // 60秒

    Time(ll sec){
        y = sec / (S*M*H*D);
        sec %= (S*M*H*D);

        d = sec / (S*M*H);
        sec %= (S*M*H);

        h = sec / (S*M);
        sec %= (S*M);

        m = sec / S;

        s = sec % S;
    }

    // 区切り文字指定可
    void print(string sep = "/"){
        cout << y << sep
             << d << sep
             << h << sep
             << m << sep
             << s << '\n';
    }
};

/* =========================================== */

int main(){
    //
    return 0;
}
