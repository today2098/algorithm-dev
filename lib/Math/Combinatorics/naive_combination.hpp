#ifndef ALGORITHM_NAIVE_COMBINATION_HPP
#define ALGORITHM_NAIVE_COMBINATION_HPP 1

#include <algorithm>
#include <cassert>

#include "../ModularArithmetic/mod_inv.hpp"

namespace algorithm {

// 順列．O(K).
constexpr long long nPk(long long n, long long k) {
    assert(0 <= k and k <= n);
    long long res = 1;
    for(long long i = 0; i < k; ++i) res *= (n - i);
    return res;
}

// 順列（mod付き）．O(K).
constexpr int nPk(long long n, long long k, int mod) {
    assert(0 <= k and k <= n);
    assert(mod >= 1);
    long long res = 1;
    for(long long i = 0; i < k; ++i) res = res * (n - i) % mod;
    return res;
}

// 組合せ．O(min(K,N-K)).
constexpr long long nCk(long long n, long long k) {
    assert(n >= 0);
    assert(k >= 0);
    if(n < k) return 0;
    k = std::min(k, n - k);
    long long res = 1;
    for(long long i = 0; i < k; ++i) res = res * (n - i) / (i + 1);
    return res;
}

// 組合せ（mod付き）．
constexpr int nCk(long long n, long long k, int mod) {
    assert(n >= 0);
    assert(k >= 0);
    assert(mod >= 1);
    if(n < k) return 0;
    k = std::min(k, n - k);
    return (long long)nPk(n, k, mod) * mod_inv(nPk(k, k, mod), mod) % mod;
}

// 重複組合せ．O(min(N-1,K)).
constexpr long long nHk(long long n, long long k) {
    assert(n >= 1);
    assert(k >= 0);
    return nCk(k + n - 1, k);
}

// 重複組合せ（mod付き）．
constexpr int nHk(long long n, long long k, int mod) {
    assert(n >= 1);
    assert(k >= 0);
    assert(mod >= 1);
    return nCk(k + n - 1, k, mod);
}

}  // namespace algorithm

#endif
