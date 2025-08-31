#ifndef ALGORITHM_TOTIENT_HPP
#define ALGORITHM_TOTIENT_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>
#include <ranges>
#include <type_traits>

#include "prime_factorize.hpp"

namespace algorithm {

namespace internal {

template <std::ranges::range R>
    requires std::is_integral_v<std::ranges::range_value_t<R>>
constexpr std::uint64_t totient(std::uint64_t n, const R &factors) {
    for(auto p : factors) n = n / p * (p - 1);
    return n;
}

constexpr std::uint64_t totient(std::uint64_t n) { return totient(n, ::algorithm::internal::distinct_prime_factorize<std::uint64_t>(n)); }

}  // namespace internal

// オイラーのトーシェント関数．nと互いに素であるn未満の自然数の個数を求める．
template <std::integral Type>
constexpr std::uint64_t totient(Type n) {
    assert(n > 0);
    return internal::totient(n);
}

}  // namespace algorithm

#endif
