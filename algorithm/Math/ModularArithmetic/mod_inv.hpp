#ifndef ALGORITHM_MOD_INV_HPP
#define ALGORITHM_MOD_INV_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>
#include <utility>

#include "modulo.hpp"

namespace algorithm {

namespace internal {

// return pair of (x, g) s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.
constexpr std::pair<std::uint32_t, std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {
    if(a == 0) return {0, m};
    std::uint32_t s = m, t = a;
    std::uint32_t u = m, v = 1;
    while(true) {
        std::uint32_t q = s / t;
        s -= t * q, u -= v * q;
        if(s == 0) return {v, t};
        q = t / s;
        t -= s * q, v += (m - u) * q;
        if(t == 0) return {u, s};
    }
}

}  // namespace internal

// モジュラ逆数（乗法逆元）．
// a^-1 mod m を求める．解が存在する必要十分条件は，aとmが互いに素であること．O(log a).
template <std::integral Type>
constexpr std::int64_t mod_inv(Type a, std::int32_t m) {
    assert(m >= 1);
    auto [x, g] = internal::mod_inv(::algorithm::internal::modulo(a, m), m);
    assert(g == 1);
    return x;
}

}  // namespace algorithm

#endif
