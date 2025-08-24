#ifndef ALGORITHM_ABSOLUTE_HPP
#define ALGORITHM_ABSOLUTE_HPP 1

#include <concepts>
#include <type_traits>

namespace algorithm {

namespace internal {

// Returns the absolute value as type Res.
template <std::integral Res, std::unsigned_integral Type>
constexpr Res abs(Type n) {
    static_assert(sizeof(Res) >= sizeof(Type));
    return static_cast<Res>(n);
}

// Returns the absolute value as type Res.
template <std::integral Res, std::signed_integral Type>
constexpr Res abs(Type n) {
    static_assert(sizeof(Res) >= sizeof(Type));
    return static_cast<Res>(std::make_unsigned_t<Type>(n < 0 ? -n : n));
}

}  // namespace internal

}  // namespace algorithm

#endif
