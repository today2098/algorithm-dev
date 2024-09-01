#ifndef ALGORITHM_GREATEST_COMMON_DIVISOR_HPP
#define ALGORITHM_GREATEST_COMMON_DIVISOR_HPP 1

/**
 * @brief Greatest Common Divisor（最大公約数）
 * @docs docs/Math/NumberTheory/greatest_common_divisor.md
 */

namespace algorithm {

template <typename Type>
constexpr Type igcd(Type a, Type b) { return (b == 0) ? a : igcd(b, a % b); }

}  // namespace algorithm

#endif
