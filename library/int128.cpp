#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include "shuphy.hpp"
/* =========================================== */

// https://drken1215.hatenablog.com/entry/2023/11/21/020301
// 128 ビット整数
struct i128 {
    // inner value
    __int128 val;
    
    // constructor
    constexpr i128() : val(0) {}
    constexpr i128(long long v) : val(v) {}
    i128(const string &s) : val(0) {
        parse(s);
    }
    void parse(const string &s) {
        val = 0;
        for (auto c : s) {
            if (isdigit(c)) val = val * 10 + (c - '0');
        }
        if (s[0] == '-') val *= -1;
    }
    constexpr __int128 get() const {
        return val;
    }
    constexpr i128 abs() {
        if (val < 0) return -val;
        else return val;
    }
    
    // comparison operators
    constexpr bool operator == (const i128 &r) const {
        return this->val == r.val;
    }
    constexpr bool operator != (const i128 &r) const {
        return this->val != r.val;
    }
    constexpr bool operator < (const i128 &r) const {
        return this->val < r.val;
    }
    constexpr bool operator > (const i128 &r) const {
        return this->val > r.val;
    }
    constexpr bool operator <= (const i128 &r) const {
        return this->val <= r.val;
    }
    constexpr bool operator >= (const i128 &r) const {
        return this->val >= r.val;
    }
    
    // arithmetic operators
    constexpr i128& operator += (const i128 &r) {
        val += r.val;
        return *this;
    }
    constexpr i128& operator -= (const i128 &r) {
        val -= r.val;
        return *this;
    }
    constexpr i128& operator *= (const i128 &r) {
        val *= r.val;
        return *this;
    }
    constexpr i128& operator /= (const i128 &r) {
        val /= r.val;
        return *this;
    }
    constexpr i128& operator %= (const i128 &r) {
        val %= r.val;
        return *this;
    }
    constexpr i128 operator + () const {
        return i128(*this);
    }
    constexpr i128 operator - () const {
        return i128(0) - i128(*this);
    }
    constexpr i128 operator + (const i128 &r) const {
        return i128(*this) += r;
    }
    constexpr i128 operator - (const i128 &r) const {
        return i128(*this) -= r;
    }
    constexpr i128 operator * (const i128 &r) const {
        return i128(*this) *= r;
    }
    constexpr i128 operator / (const i128 &r) const {
        return i128(*this) /= r;
    }
    constexpr i128 operator % (const i128 &r) const {
        return i128(*this) %= r;
    }
    
    // other operators
    constexpr i128& operator ++ () {
        ++val;
        return *this;
    }
    constexpr i128& operator -- () {
        --val;
        return *this;
    }
    constexpr i128 operator ++ (int) {
        i128 res = *this;
        ++*this;
        return res;
    }
    constexpr i128 operator -- (int) {
        i128 res = *this;
        --*this;
        return res;
    }
    friend istream& operator >> (istream &is, i128 &x) {
        string s;
        is >> s;
        x.parse(s);
        return is;
    }
    friend ostream& operator << (ostream &os, const i128 &x) {
        auto tmp = x.val < 0 ? -x.val : x.val;
        char buffer[128];
        char *d = end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (x.val < 0) {
            --d;
            *d = '-';
        }
        int len = end(buffer) - d;
        if (os.rdbuf()->sputn(d, len) != len) {
            os.setstate(ios_base::badbit);
        }
        return os;
    }
};

i128 gcd128(i128 a, i128 b){
    if(b == 0) return a;
    return gcd128(b, a % b);
}

int main(){
    return 0;
}
