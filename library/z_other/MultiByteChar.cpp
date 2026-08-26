#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 1文字ずつ切り出す関数 */
vector<string> substr_kana(string &str) {
    vector<string> ret;
    
    for (size_t i = 0; i < str.length(); ) {
        // 1文字のバイト数を判別 (UTF-8の先頭バイトのルールを利用)
        unsigned char c = str[i];
        int char_len = 1; 
        if (c >= 0xF0) char_len = 4;      // 4バイト文字（絵文字など）
        else if (c >= 0xE0) char_len = 3; // 3バイト文字（漢字・ひらがな等）
        else if (c >= 0xC0) char_len = 2; // 2バイト文字
        
        // 切り出し
        string one_char = str.substr(i, char_len);
        ret.push_back(one_char);
        
        i += char_len;
    }

    return ret;
}

/* =========================================== */

int main(){
    string s = "Hello 世界";
    vc<string> t = substr_kana(s);
    cout << len(t) << el;
    for(auto c : t){
        cout << c << el;
    }
    return 0;
}
