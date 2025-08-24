#ifndef ALGORITHM_LEAST_COMMON_MULTIPLE_HPP
#define ALGORITHM_LEAST_COMMON_MULTIPLE_HPP 1

#include <concepts>
#include <type_traits>

#include "../../internal/absolute.hpp"
#include "greatest_common_divisor.hpp"

namespace algorithm {

namespace internal {

template <std::integral Type>
constexpr Type lcm(Type a, Type b) {
    if(a == 0 or b == 0) return 0;
    return a / ::algorithm::internal::gcd(a, b) * b;
}

}  // namespace internal

// Returns the least common multiple (LCM) of |a| and |b|.
template <std::integral T, std::integral U>
constexpr std::common_type_t<T, U> lcm(T a, U b) {
    using ct = std::common_type_t<T, U>;
    using ut = std::make_unsigned_t<ct>;
    ut ua = ::algorithm::internal::abs<ut>(a);
    ut ub = ::algorithm::internal::abs<ut>(b);
    return internal::lcm(ua, ub);
}

// Returns the least common multiple (LCM) of all arguments.
template <std::integral Type, std::integral... Args>
constexpr auto lcm(Type first, Args... args) { return lcm(first, lcm(args...)); }

}  // namespace algorithm

#endif
