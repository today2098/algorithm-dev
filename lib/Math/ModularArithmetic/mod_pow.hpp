#ifndef ALGORITHM_MOD_POW_HPP
#define ALGORITHM_MOD_POW_HPP 1

/**
 * @brief 繰り返し二乗法（mod付き）
 * @docs docs/Math/ModularArithmetic/mod_pow.md
 */

#include <cassert>

namespace algorithm {

// 繰り返し二乗法（mod付き）．n^k mod m を求める．O(logK).
constexpr int mod_pow(long long n, long long k, int m) {
    assert(k >= 0);
    assert(m >= 1);
    long long res = 1;
    n %= m;
    while(k > 0) {
        if(k & 1LL) res = res * n % m;
        n = n * n % m;
        k >>= 1;
    }
    return res;
}

}  // namespace algorithm

#endif
