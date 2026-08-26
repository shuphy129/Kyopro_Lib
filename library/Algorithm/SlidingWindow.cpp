#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>

/* SlidingWindow */
struct Swindow {
    vector<ll> v;
    int sz, n; // sz:区間長, n:配列長
    ll res; // 区間の演算結果
    int left, right; // [left, right)
    deque<ll> q;
    bool initialized;

    Swindow(vector<ll> &vec, int k) : initialized(false) {
        v = vec;
        sz = k;
        n = v.size();
    }

    // next: 区間を進める 進めない場合はfalseを返す
    bool next_sum(){
        if(!initialized){
            if(sz < 1) return false;
            left = 0; right = sz;
            if(right > n) return false;

            res = 0;
            for(int i = left; i < right; ++i){
                res += v[i];
            }
            initialized = true;
            return true;
        } else {
            ++left; ++right;
            if(right > n) return false;

            res -= v[left - 1];
            res += v[right - 1];
            return true;
        }
    }

    bool next_min(){
        if(!initialized){
            if(sz < 1) return false;
            left = 0; right = sz;
            if(right > n) return false;

            for(int i = left; i < right; ++i){
                while(!q.empty() && v[q.back()] >= v[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            res = v[q.front()];
            initialized = true;
            return true;
        } else {
            ++left; ++right;
            if(right > n) return false;

            while(!q.empty() && v[q.back()] >= v[right-1]){
                q.pop_back();
            }
            q.push_back(right - 1);

            if(!q.empty() && q.front() == left-1){
                q.pop_front();
            }
            res = v[q.front()];
            return true;
        }
    }

    bool next_max(){
        if(!initialized){
            if(sz < 1) return false;
            left = 0; right = sz;
            if(right > n) return false;

            for(int i = left; i < right; ++i){
                while(!q.empty() && v[q.back()] <= v[i]){
                    q.pop_back();
                }
                q.push_back(i);
            }
            res = v[q.front()];
            initialized = true;
            return true;
        } else {
            ++left; ++right;
            if(right > n) return false;

            while(!q.empty() && v[q.back()] <= v[right-1]){
                q.pop_back();
            }
            q.push_back(right - 1);

            if(!q.empty() && q.front() == left-1){
                q.pop_front();
            }
            res = v[q.front()];
            return true;
        }
    }

    ll get() { return res; }      // 現在の区間の演算結果
    int get_l() { return left; }  // 現在の区間の左端idx
    int get_r() { return right; } // 現在の区間の右端idx+1(区間外)
};

/* =========================================== */

int main(){
    vc<ll> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    Swindow sw(v, 3); // 長さ3のウィンドウ
    while(sw.next_sum()){
        cout << sw.get() << ' ';
    }
    cout << el;

    Swindow sw2(v, 3);
    while(sw2.next_min()){
        cout << sw2.get() << ' ';
    }
    cout << el;

    Swindow sw3(v, 3);
    while(sw3.next_max()){
        cout << sw3.get() << ' ';
    }
    cout << el;
    return 0;
}

/*
Ctrl + /
Shift + Alt + A
*/