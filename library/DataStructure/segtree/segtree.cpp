#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <shuphy.hpp>
/* =========================================== */

#include <atcoder/segtree>
using namespace atcoder;

// セグ木にのせる型 必要に応じて変える
using S = ll;

S op_sum (S a, S b) { return (a + b); }
S op_mul (S a, S b) { return (a * b); }
S op_min (S a, S b) { return min(a, b); }
S op_max (S a, S b) { return max(a, b); }
S op_lcm (S a, S b) { return lcm(a, b); }
S op_gcd (S a, S b) { return gcd(a, b); }
S op_and (S a, S b) { return (a & b); }
S op_or  (S a, S b) { return (a | b); }
S op_xor (S a, S b) { return (a ^ b); }

S e_00 () { return 0; }
S e_p1 () { return 1; }
S e_m1 () { return -1; }
S e_max () { return INFL; }
S e_min () { return -INFL; }

using sumseg = segtree<S, op_sum, e_00>;
using mulseg = segtree<S, op_mul, e_p1>;
using minseg = segtree<S, op_min, e_max>;
using maxseg = segtree<S, op_max, e_min>;
using lcmseg = segtree<S, op_lcm, e_p1>;
using gcdseg = segtree<S, op_gcd, e_00>;
using andseg = segtree<S, op_and, e_m1>;
using orseg  = segtree<S, op_or,  e_00>;
using xorseg = segtree<S, op_xor, e_00>;

int main(){
    return 0;
}
