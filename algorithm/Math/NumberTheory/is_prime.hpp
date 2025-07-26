#ifndef ALGORITHM_IS_PRIME_HPP
#define ALGORITHM_IS_PRIME_HPP 1

#include <cassert>
#include <concepts>

namespace algorithm {

// 素数判定．O(√N).
template <std::integral Type>
constexpr bool is_prime(Type n) {
    assert(n >= 0);
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(unsigned long long p = 3, m = n; p * p <= m; p += 2) {
        if(m % p == 0) return false;
    }
    return true;
}

}  // namespace algorithm

#endif
