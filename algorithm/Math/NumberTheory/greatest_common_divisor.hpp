#ifndef ALGORITHM_GREATEST_COMMON_DIVISOR_HPP
#define ALGORITHM_GREATEST_COMMON_DIVISOR_HPP 1

#include <concepts>
#include <type_traits>

#include "../../internal/abs.hpp"

namespace algorithm {

namespace internal {

template <std::integral Type>
constexpr Type gcd(Type a, Type b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

}  // namespace internal

template <std::integral T, std::integral U>
constexpr std::common_type_t<T, U> gcd(T a, U b) {
    a = ::algorithm::internal::abs(a);
    b = ::algorithm::internal::abs(b);
    using ct = std::common_type_t<T, U>;
    using ut = std::make_unsigned_t<ct>;
    return internal::gcd<ut>(a, b);
}

template <std::integral Type, std::integral... Args>
constexpr auto gcd(Type first, Args... args) { return gcd(first, gcd(args...)); }

}  // namespace algorithm

#endif
