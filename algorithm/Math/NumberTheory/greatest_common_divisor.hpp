#ifndef ALGORITHM_GREATEST_COMMON_DIVISOR_HPP
#define ALGORITHM_GREATEST_COMMON_DIVISOR_HPP 1

#include <concepts>
#include <type_traits>

#include "../../internal/absolute.hpp"

namespace algorithm {

namespace internal {

template <std::integral Type>
constexpr Type gcd(Type a, Type b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

}  // namespace internal

// Returns the greatest common divisor (GCD) of |a| and |b|.
template <std::integral T, std::integral U>
constexpr std::common_type_t<T, U> gcd(T a, U b) {
    using ct = std::common_type_t<T, U>;
    using ut = std::make_unsigned_t<ct>;
    ut ua = ::algorithm::internal::abs<ut>(a);
    ut ub = ::algorithm::internal::abs<ut>(b);
    return internal::gcd(ua, ub);
}

// Returns the greatest common divisor (GCD) of all arguments.
template <std::integral Type, std::integral... Args>
constexpr auto gcd(Type first, Args... args) { return gcd(first, gcd(args...)); }

}  // namespace algorithm

#endif
