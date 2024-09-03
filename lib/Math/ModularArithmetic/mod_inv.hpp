#ifndef ALGORITHM_MOD_INV_HPP
#define ALGORITHM_MOD_INV_HPP 1

/**
 * @brief モジュラ逆数（乗法逆元）
 * @docs docs/Math/ModularArithmetic/mod_inv.md
 */

#include <cassert>
#include <utility>

namespace algorithm {

// モジュラ逆数（乗法逆元）．
// a^-1 mod m を求める．解が存在する必要十分条件は，aとmが互いに素であること．O(log a).
template <typename Type>
Type mod_inv(long long a, Type m) {
    assert(m > 1);
    long long b = m, u = 1, v = 0;
    while(b != 0) {
        long long t = a / b;
        a -= b * t, u -= v * t;
        std::swap(a, b), std::swap(u, v);
    }
    // assert(("a and m need to be coprime.", a == 1));
    if(u < 0) u += m;
    return u;
}

}  // namespace algorithm

#endif
