#ifndef ALGORITHM_IS_PRIME_HPP
#define ALGORITHM_IS_PRIME_HPP 1

/**
 * @brief 素数判定
 * @docs docs/Math/NumberTheory/is_prime.md
 */

#include <cassert>

namespace algorithm {

// 素数判定．O(√N).
template <typename Type>
constexpr bool is_prime(Type n) {
    assert(n >= 0);
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(Type p = 3; p * p <= n; p += 2) {
        if(n % p == 0) return false;
    }
    return true;
}

}  // namespace algorithm

#endif
