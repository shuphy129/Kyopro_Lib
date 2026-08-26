#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* うるう年か判定 */
bool is29day(int y) {
    if (y % 400 == 0) {
        return true; // うるう年
    }
    if (y % 100 == 0) {
        return false; // うるう年でない
    }
    if (y % 4 == 0) {
        return true; // うるう年
    }
    return false; // うるう年でない
}

/* 30日までの月かどうかを判定 */
bool is30day(int m) {
    return ( m == 4 || m == 6 || m == 9 || m == 11 );
}

/* YYYYMMDD形式のための構造体 */
struct Day {
    int y, m, d;
    int ymd; // YYYYMMDD形式の8桁
    int end_ymd = 20360102; // [20000101, 20360102)

    // 開始年, 開始月, 開始日
    Day(int sy, int sm, int sd) {
        y = sy;
        m = sm;
        d = sd;
        make_ymd();
    }

    // 開始年, 開始月, 開始日, 終了年月日のYYYYMMDD形式整数
    Day(int sy, int sm, int sd, int end) {
        y = sy;
        m = sm;
        d = sd;
        make_ymd();

        end_ymd = end;
    }

    // YYYYMMDD形式の8桁整数を生成
    void make_ymd() {
        ymd = 0;
        ymd += y * 10000;
        ymd += m * 100;
        ymd += d;
    }

    // 次の日にする
    bool next_day() {
        // 次の日へ
        d++;

        // 次の月へ
        if (m == 2) { // 2月の場合
            if (is29day(y)) { // うるう年の場合(2000~2036年の場合は4の倍数がすべて該当します)
                // 29日を超えたら次の月
                if (d > 29) {
                    d = 1;
                    m++;
                }
            } else { // うるう年でない場合
                // 28日を超えたら次の月
                if (d > 28) {
                    d = 1;
                    m++;
                }
            }
        }
        else if (is30day(m)) { // 30日まである月
            if (d > 30) {
                d = 1;
                m++;
            }
        }
        else { // 31日まである月
            if (d > 31) {
                d = 1;
                m++;
            }
        }

        // 次の年へ
        if (m > 12) {
            m = 1;
            y++;
        }

        make_ymd();

        // 終了条件
        if (ymd >= end_ymd) return false;
        return true;
    }
};

/* =========================================== */

int main(){
    Day ymd(2026, 1, 1, 20260106);
    do {
        cout << ymd.ymd << el;
    } while(ymd.next_day());
    return 0;
}
