#ifndef ALGORITHM_NAIVE_COMBINATION_HPP
#define ALGORITHM_NAIVE_COMBINATION_HPP 1

/**
 * @brief 順列，組合せ，重複組合せ
 * @docs docs/Math/Combinatorics/naive_combination.md
 */

#include <algorithm>
#include <cassert>

namespace algorithm {

// 順列．O(K).
constexpr long long nPk(long long n, int k) {
    assert(0 <= k and k <= n);
    long long res = 1;
    for(int i = 0; i < k; ++i) res = res * (n - i);
    return res;
}

// 組合せ．O(min(K,N-K)).
constexpr long long nCk(long long n, int k) {
    assert(n >= 0 and k >= 0);
    if(k > n) return 0;
    long long res = 1;
    k = std::min<long long>(k, n - k);
    for(int i = 0; i < k; ++i) res = res * (n - i) / (i + 1);
    return res;
}

// 重複組合せ．O(min(N-1,K)).
constexpr long long nHk(long long n, long long k) {
    assert(n >= 1 and k >= 0);
    return nCk(k + n - 1, k);
}

}  // namespace algorithm

#endif
