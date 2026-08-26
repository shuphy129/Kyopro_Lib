#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

/* 基本群 */

// https://github.com/maspypy/library/blob/main/geo/base.hpp
/* 2次元座標 */
template <class T>
struct Point {
    T x, y;

    // コンストラクタ
    Point() : x(0), y(0) {}

    template <class A, class B>
    Point(A x, B y) : x(x), y(y) {}

    template <class A, class B>
    Point(pair<A, B> p) : x(p.fi), y(p.se) {}

    template <class U>
    Point(Point<U> p) : x(p.x), y(p.y) {}

    // cinでx, yの順に入力を受け取る
    friend std::istream& operator>>(std::istream &is, Point &p){
        is >> p.x >> p.y;
        return is;
    }

    // ベクトル演算
    Point operator+(Point p) const { return {x + p.x, y + p.y}; }
    Point operator-(Point p) const { return {x - p.x, y - p.y}; }
    Point operator-() const { return {-x, -y}; }
    Point operator*(T t) const { return {x * t, y * t}; }
    Point operator/(T t) const { return {x / t, y / t}; }
    bool operator==(Point p) const { return x == p.x && y == p.y; }
    bool operator!=(Point p) const { return x != p.x || y != p.y; }
    bool operator<(Point p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }

    // ベクトル演算&更新
    Point operator+=(const Point p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point operator-=(const Point p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    // a.dot(b) = aとbの内積
    T dot(const Point& other) const { return x * other.x + y * other.y; }
    // a.det(b) = aとbの外積 +:左回り -:右回り 0:一直線
    T det(const Point& other) const { return x * other.y - y * other.x; }

    T abs_int() { return (x * x + y * y); } // ベクトルの大きさの2乗
    long double abs() { return sqrtl(x * x + y * y); } // ベクトルの大きさ
    long double angle() { return atan2l(y, x); } // 偏角(ラジアン)

    // theta回転 整数型非対応
    Point rotate(double theta) {
        static_assert(!is_integral<T>::value);
        double c = cos(theta), s = sin(theta);
        return Point{c * x - s * y, s * x + c * y};
    }
    // 90度回転 ccw = true:反時計回り false:時計回り
    Point rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x}); }
};

/* A -> B -> C と進むときに、左に曲がるならば +1、右に曲がるならば -1 */
template <class T>
int ccw(Point<T> A, Point<T> B, Point<T> C) {
    T x = (B - A).det(C - A);
    if (x > 0) return 1;  // 左に曲がる
    if (x < 0) return -1; // 右に曲がる
    return 0;             // 一直線(Uターン含む)
}

/* 2点間の距離 */
template <class T> // 2乗値
T dist_int(Point<T> A, Point<T> B){
    T dx = A.x - B.x;
    T dy = A.y - B.y;
    return (dx * dx + dy * dy);
}
// dist<double>(a, b)
template <class REAL, class T, class U>
REAL dist(Point<T> A, Point<U> B) {
    REAL dx = REAL(A.x) - REAL(B.x);
    REAL dy = REAL(A.y) - REAL(B.y);
    return sqrt(dx * dx + dy * dy);
}

/* 直線 ax+by+cの形 */
template <class T>
struct Line {
    T a, b, c;

    // コンストラクタ
    Line(T a, T b, T c) : a(a), b(b), c(c) {}
    Line(Point<T> A, Point<T> B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.x * B.y - A.y * B.x;
    }
    Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}

    template <class U> // 点と直線の位置関係
    U eval(Point<U> P) { // 戻り値0: 座標Pが直線上にある
        return U(a) * P.x + U(b) * P.y + U(c);
    }
    template <class U>
    T eval(U x, U y) {
        return a * x + b * y + c;
    }

    // 正規化 同じ直線が同じ a,b,c で表現されるようにする
    void normalize() {
        static_assert(is_same_v<T, int> || is_same_v<T, long long>);
        T g = gcd(gcd(abs(a), abs(b)), abs(c));
        a /= g, b /= g, c /= g;
        if (b < 0) {
        a = -a, b = -b, c = -c;
        }
        if (b == 0 && a < 0) {
        a = -a, b = -b, c = -c;
        }
    }

    // 平行ならtrue
    bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }
    // 垂直ならtrue
    bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }
    // 同じ直線ならtrue
    bool is_same(Line other) {
        if (a * other.b != b * other.a) return false;
        if (a * other.c != c * other.a) return false;
        if (b * other.c != c * other.b) return false;
        return true;
    }
    bool operator==(Line other) const { return is_same(other); }
    bool operator!=(Line other) const { return is_same(other); }
};

/* 線分 */
template <class T>
struct Segment {
    Point<T> A, B;

    Segment(Point<T> A, Point<T> B) : A(A), B(B) {}
    Segment(T x1, T y1, T x2, T y2)
        : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}

    bool contain(Point<T> C) { // 戻り値true: 座標Cが線分上にある
        T det = (C - A).det(B - A);
        if (det != 0) return false;
        return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;
    }

    // 線分を直線に変換
    Line<T> to_Line() { return Line(A, B); }
};

/* 円 */
template <class T>
struct Circle {
    Point<T> O; // 中心
    T r; // 半径

    Circle() {}
    Circle(Point<T> O, T r) : O(O), r(r) {}
    Circle(T x, T y, T r) : O(x, y), r(r) {}

    bool operator==(Circle other) const { return O == other.O && r == other.r; }
    bool operator!=(Circle other) const { return O != other.O || r != other.r; }

    template <class U> // 点と円の位置関係 その1
    bool contain(Point<U> p) { // 戻り値true: 座標pが円の内部(境界含む)
        T dx = p.x - O.x, dy = p.y - O.y;
        return dx * dx + dy * dy <= r * r;
    }

    template <class U> // 点と円の位置関係 詳細
    int eval(Point<U> p) {
        T dx = p.x - O.x, dy = p.y - O.y;
        if(dx * dx + dy * dy < r * r) return 0; // 0: 内包する
        if(dx * dx + dy * dy == r * r) return 1; // 1: 円周上
        return 2; // 2: 外部
    }

    template <class U> // 円と円の交点の個数
    int common_point(Circle<U> other) {
        if(O == other.O && r == other.r) return 3; // 3(INF)個: 完全一致
        T dx = other.O.x - O.x, dy = other.O.y - O.y;
        if(dx * dx + dy * dy < (other.r - r) * (other.r - r))  return 0;  // 0個: 内包する
        if(dx * dx + dy * dy == (other.r - r) * (other.r - r)) return 1; // 1: 内接する(完全一致含む)
        if(dx * dx + dy * dy < (other.r + r) * (other.r + r))  return 2;  // 2: 2点で交わる
        if(dx * dx + dy * dy == (other.r + r) * (other.r + r)) return 1; // 1: 外接する
        return 0;  // 0個: 外部
    }

    template <class U> // 円と円の位置関係 詳細
    int eval(Circle<U> other) {
        T dx = other.O.x - O.x, dy = other.O.y - O.y;
        if(dx * dx + dy * dy < (other.r - r) * (other.r - r))  return 0;  // 0: 内包する
        if(dx * dx + dy * dy == (other.r - r) * (other.r - r)) return 1; // 1: 内接する(完全一致含む)
        if(dx * dx + dy * dy < (other.r + r) * (other.r + r))  return 2;  // 2: 2点で交わる
        if(dx * dx + dy * dy == (other.r + r) * (other.r + r)) return 3; // 3: 外接する
        return 4;  // 4: 外部
    }
};

// using P = Point<ll>;

int main(){
    Circle a(0, 0, 2);
    Circle b(0, 0, 2); // 一致
    Circle c(0, 0, 4); // 内包 
    Circle d(1, 0, 1); // 内接
    Circle e(1, 0, 2); // 2点で交わる
    Circle f(3, 0, 1); // 外接
    Circle g(5, 0, 2); // 外部

    DBG(a.eval(b));
    DBG(a.eval(c));
    DBG(a.eval(d));
    DBG(a.eval(e));
    DBG(a.eval(f));
    DBG(a.eval(g));
    return 0;
}

/*
Ctrl + /
Shift + Alt + A
*/