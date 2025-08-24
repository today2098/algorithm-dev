#ifndef ALGORITHM_MOD_POW_HPP
#define ALGORITHM_MOD_POW_HPP 1

#include <cassert>

#include "mod_inv.hpp"

namespace algorithm {

// 繰り返し二乗法（mod付き）．O(log k).
constexpr long long mod_pow(long long n, long long k, int mod) {
    assert(mod >= 1);
    if(n < -mod or mod <= n) n %= mod;
    if(n < 0) n += mod;
    if(k < 0) n = mod_inv(n, mod), k = -k;
    long long res = 1;
    for(; k > 0; k >>= 1) {
        if(k & 1LL) res = res * n % mod;
        n = n * n % mod;
    }
    return res;
}

}  // namespace algorithm

#endif
