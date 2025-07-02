#ifndef ALGORITHM_MOD_INV_HPP
#define ALGORITHM_MOD_INV_HPP 1

#include <cassert>
#include <utility>

namespace algorithm {

// モジュラ逆数（乗法逆元）．
// a^-1 mod m を求める．解が存在する必要十分条件は，aとmが互いに素であること．O(log a).
constexpr long long mod_inv(long long a, int mod) {
    assert(mod >= 1);
    long long b = mod, u = 1, v = 0;
    while(b != 0) {
        long long t = a / b;
        a -= b * t, u -= v * t;
        std::swap(a, b), std::swap(u, v);
    }
    if(u < 0) u += mod;
    return u;
}

}  // namespace algorithm

#endif
