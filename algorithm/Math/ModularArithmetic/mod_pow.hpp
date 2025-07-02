#ifndef ALGORITHM_MOD_POW_HPP
#define ALGORITHM_MOD_POW_HPP 1

#include <cassert>

namespace algorithm {

// 繰り返し二乗法（mod付き）．O(logK).
constexpr long long mod_pow(long long n, long long k, int mod) {
    assert(k >= 0);
    assert(mod >= 1);
    long long res = 1;
    n %= mod;
    while(k > 0) {
        if(k & 1LL) res = res * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return res;
}

}  // namespace algorithm

#endif
