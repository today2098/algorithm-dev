#ifndef ALGORITHM_NAIVE_COMBINATION_HPP
#define ALGORITHM_NAIVE_COMBINATION_HPP 1

#include <algorithm>
#include <cassert>

#include "../ModularArithmetic/mod_inv.hpp"

namespace algorithm {

// 順列．O(K).
constexpr long long nPk(long long n, long long k) {
    assert(n >= 0);
    assert(k >= 0);
    if(n < k) return 0;
    long long res = 1;
    for(long long i = 0; i < k; ++i) res *= (n - i);
    return res;
}

// 順列（mod付き）．O(K).
constexpr long long nPk(long long n, long long k, int mod) {
    assert(n >= 0);
    assert(k >= 0);
    assert(mod >= 1);
    if(n < k) return 0;
    n %= mod;
    long long res = 1 % mod;
    for(long long i = 0; i < k; ++i) {
        long long tmp = n - i;
        if(tmp < 0) tmp += mod;
        res = res * tmp % mod;
    }
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
constexpr long long nCk(long long n, long long k, int mod) {
    assert(n >= 0);
    assert(k >= 0);
    assert(mod >= 1);
    if(n < k) return 0;
    k = std::min(k, n - k);
    return nPk(n, k, mod) * mod_inv(nPk(k, k, mod), mod) % mod;
}

// 重複組合せ．O(min(N-1,K)).
constexpr long long nHk(long long n, long long k) {
    assert(n >= 0);
    assert(k >= 0);
    if(n == 0) return 0;
    return nCk(k + n - 1, k);
}

// 重複組合せ（mod付き）．
constexpr long long nHk(long long n, long long k, int mod) {
    assert(n >= 0);
    assert(k >= 0);
    assert(mod >= 1);
    if(n == 0) return 0;
    return nCk(k + n - 1, k, mod);
}

}  // namespace algorithm

#endif
