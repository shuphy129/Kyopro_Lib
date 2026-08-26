#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include "shuphy.hpp"
/* =========================================== */

/* [2進]文字列 s を[10進]整数に変更 [2進]はbaseで変更可(2~36) */
ull bin2dec(const string &s, int base = 2){
    if(base < 2 || 36 < base){
        MEMO_el("bin2dec: base ERROR! base = 2 ~ 36");
        return -1;
    }
    return stoull(s, nullptr, base);
}

/* =========================================== */

/* [10進]整数 n を[2進]文字列に変更 [2進]はbaseで変更可(2~36) */
/* 変換後の文字列がlengthに満たない場合 0で埋める */
string dec2bin(ull n, int length = -1, int base = 2){
    if(base < 2 || 36 < base){
        MEMO_el("dec2bin: base ERROR! base = 2 ~ 36");
        return "0";
    }

    constexpr char Digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret = "";

    // 変換
    do {
        ret.push_back(Digits[n % base]);
        n /= base;
    } while (n);

    // 0で埋める
    int cnt = length - (int)ret.size();
    while(cnt > 0){
        ret += '0';
        --cnt;
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

/* =========================================== */

int main(){
    return 0;
}