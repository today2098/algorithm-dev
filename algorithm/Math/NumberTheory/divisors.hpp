#ifndef ALGORITHM_DIVISORS_HPP
#define ALGORITHM_DIVISORS_HPP 1

#include <algorithm>
#include <cassert>
#include <concepts>
#include <cstdint>
#include <vector>

namespace algorithm {

namespace internal {

template <std::integral Res>
constexpr std::vector<Res> divisors(std::uint64_t n) {
    std::vector<Res> divs;  // divs[]:=(自然数nの約数のリスト).
    for(std::uint64_t p = 1; p < 1ULL << 32 and p * p <= n; ++p) {
        if(n % p != 0) continue;
        divs.push_back(p);
        auto q = n / p;
        if(q != p) divs.push_back(q);
    }
    divs.shrink_to_fit();
    std::sort(divs.begin(), divs.end());
    return divs;
}

}  // namespace internal

// 約数列挙．O(√n).
template <std::integral Type>
constexpr std::vector<Type> divisors(Type n) {
    assert(n > 0);
    return internal::divisors<Type>(n);
}

}  // namespace algorithm

#endif
