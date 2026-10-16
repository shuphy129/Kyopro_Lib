#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

#include <atcoder/lazysegtree>
using namespace atcoder;

// セグ木にのせる型 必要に応じて変える(区間和は別)
using S = ll;
// 作用素の型
using F = ll;

const F ID = 8e18;

// S op_sum (S a, S b) { return (a + b); }
// S op_mul (S a, S b) { return (a * b); }
S op_min (S a, S b) { return min(a, b); }
S op_max (S a, S b) { return max(a, b); }
// S op_lcm (S a, S b) { return lcm(a, b); }
// S op_gcd (S a, S b) { return gcd(a, b); }
// S op_and (S a, S b) { return (a & b); }
// S op_or  (S a, S b) { return (a | b); }
// S op_xor (S a, S b) { return (a ^ b); }

S e_00 () { return 0; }
S e_p1 () { return 1; }
S e_m1 () { return -1; }
S e_max () { return INFL; }
S e_min () { return -INFL; }

S map_add (F f, S x) { return (f + x); } // 区間加算
S map_upd (F f, S x) { return (f == ID ? x : f); } // 区間変更

F com_add (F f, F g) { return (f + g); }
F com_upd (F f, F g) { return (f == ID ? g : f); }

F id_0 () { return 0; }
F id_upd () { return ID; }

using addmin = lazy_segtree<S, op_min, e_max, F, map_add, com_add, id_0>; // 区間加算・区間最小値
using addmax = lazy_segtree<S, op_max, e_min, F, map_add, com_add, id_0>; // 区間加算・区間最大値
using updmin = lazy_segtree<S, op_min, e_max, F, map_upd, com_upd, id_upd>; // 区間変更・区間最小値
using updmax = lazy_segtree<S, op_max, e_min, F, map_upd, com_upd, id_upd>; // 区間変更・区間最大値
// addmin seg(v); (v は vector<S>)

// 区間和用
struct R {
    ll val;
    int len; // 区間幅が必要なため
};

R op_sum_range (R a, R b) { return {a.val + b.val, a.len + b.len}; }
R e_sum_range () { return {0, 0}; }

R map_add_range (F f, R x) { return {x.val + f*x.len, x.len}; }
R map_upd_range (F f, R x) {
    if(f != ID) x.val = f*x.len;
    return x;
}

F com_add_range (F f, F g) { return (f + g); }
F com_upd_range (F f, F g) { return (f == ID ? g : f); }

vector<R> init(int N){ // 戻り値(vector)をセグ木に載せる
    vector<R> ret(N, {0, 1});
    return ret;
}

using addsum = lazy_segtree<R, op_sum_range, e_sum_range, F, map_add_range, com_add_range, id_0>; // 区間加算・区間和取得
using updsum = lazy_segtree<R, op_sum_range, e_sum_range, F, map_upd_range, com_add_range, id_upd>; // 区間変更・区間和取得
// [l, r)の区間和は seg.prod(l, r).val で取得する
// addsum seg(init(N));

int main(){
    return 0;
}
