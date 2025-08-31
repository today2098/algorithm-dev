#ifndef ALGORITHM_MOD_POW_HPP
#define ALGORITHM_MOD_POW_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>

#include "mod_inv.hpp"
#include "modulo.hpp"

namespace algorithm {

namespace internal {

// return n^k mod m.
constexpr std::uint32_t mod_pow(std::uint64_t n, unsigned long long k, std::uint32_t mod) {
    std::uint64_t res = 1;
    for(; k > 0; k >>= 1) {
        if(k & 1ULL) res = res * n % mod;
        n = n * n % mod;
    }
    return res;
}

}  // namespace internal

// 繰り返し二乗法（mod付き）．O(log k).
template <std::integral Type>
constexpr std::int64_t mod_pow(Type n, long long k, std::int32_t mod) {
    assert(mod >= 1);
    auto r = ::algorithm::internal::modulo(n, mod);
    if(k < 0) {
        auto [x, g] = ::algorithm::internal::mod_inv(r, mod);
        assert(g == 1);
        r = x, k = -k;
    }
    return internal::mod_pow(r, k, mod);
}

}  // namespace algorithm

#endif
