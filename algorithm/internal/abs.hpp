#ifndef ALGORITHM_ABS_HPP
#define ALGORITHM_ABS_HPP 1

#include <concepts>

namespace algorithm {

namespace internal {

template <std::unsigned_integral Type>
constexpr Type abs(Type n) { return n; }

template <std::signed_integral Type>
constexpr Type abs(Type n) { return (n < 0 ? -n : n); }

template <std::floating_point Type>
constexpr Type abs(Type n) { return (n < 0 ? -n : n); }

}  // namespace internal

}  // namespace algorithm

#endif
