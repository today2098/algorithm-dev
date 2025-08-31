#ifndef ALGORITHM_PRIME_FACTORIZE_HPP
#define ALGORITHM_PRIME_FACTORIZE_HPP 1

#include <algorithm>
#include <bit>
#include <cassert>
#include <concepts>
#include <cstdint>
#include <map>
#include <vector>

namespace algorithm {

namespace internal {

template <std::integral Res>
constexpr std::vector<Res> distinct_prime_factorize(std::uint64_t n) {
    std::vector<Res> factors;  // factors[]:=(自然数nの素因数のリスト).
    factors.reserve(15);
    if(n % 2 == 0) {
        factors.push_back(2);
        auto c = std::countr_zero(n);
        n >>= c;
    }
    for(std::uint64_t p = 3; p < 1ULL << 32 and p * p <= n; p += 2) {
        if(n % p != 0) continue;
        factors.push_back(p);
        do {
            n /= p;
        } while(n % p == 0);
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

template <std::integral Res>
std::map<Res, int> prime_factorize(std::uint64_t n) {
    std::map<Res, int> res;  // res[p]:=(自然数nに含まれる素因数pの個数).
    if(n % 2 == 0) {
        auto c = std::countr_zero(n);
        res.emplace_hint(res.end(), 2, c);
        n >>= c;
    }
    for(std::uint64_t p = 3; p < 1ULL << 32 and p * p <= n; p += 2) {
        int c = 0;
        while(n % p == 0) n /= p, ++c;
        if(c > 0) res.emplace_hint(res.end(), p, c);
    }
    if(n > 1) res.emplace_hint(res.end(), n, 1);
    return res;
}

}  // namespace internal

// 自然数nの素因数を求める．O(√n).
template <std::integral Type>
constexpr std::vector<Type> distinct_prime_factorize(Type n) {
    assert(n > 0);
    return internal::distinct_prime_factorize<Type>(n);
}

// 素因数分解．O(√n).
template <std::integral Type>
std::map<Type, int> prime_factorize(Type n) {
    assert(n > 0);
    return internal::prime_factorize<Type>(n);
}

// 高速約数列挙．
template <typename Type>
std::vector<Type> divisors(const std::map<Type, int> &pf) {
    std::vector<Type> divs({1});
    for(const auto &[p, c] : pf) {
        const int sz = divs.size();
        Type d = 1;
        for(int i = 0; i < c; ++i) {
            d *= p;
            for(int j = 0; j < sz; ++j) divs.push_back(divs[j] * d);
        }
    }
    divs.shrink_to_fit();
    std::sort(divs.begin(), divs.end());
    return divs;
}

}  // namespace algorithm

#endif
