#ifndef ALGORITHM_IS_PRIME_HPP
#define ALGORITHM_IS_PRIME_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>

namespace algorithm {

namespace internal {

constexpr bool is_prime(std::uint64_t n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(std::uint64_t p = 3; p < 1ULL << 32 and p * p <= n; p += 2) {
        if(n % p == 0) return false;
    }
    return true;
}

}  // namespace internal

// 素数判定．O(√n).
template <std::unsigned_integral Type>
constexpr bool is_prime(Type n) { return internal::is_prime(n); }

// 素数判定．O(√n).
template <std::signed_integral Type>
constexpr bool is_prime(Type n) {
    assert(n >= 0);
    return internal::is_prime(n);
}

}  // namespace algorithm

#endif
