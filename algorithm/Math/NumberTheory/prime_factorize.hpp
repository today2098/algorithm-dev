#ifndef ALGORITHM_PRIME_FACTORIZE_HPP
#define ALGORITHM_PRIME_FACTORIZE_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>
#include <map>

namespace algorithm {

// 素因数分解．O(√n).
template <std::integral Type>
std::map<Type, int> prime_factorize(Type n) {
    assert(n > 0);
    std::map<Type, int> res;  // res[p]:=(自然数nに含まれる素因数pの個数).
    std::uint64_t m = n;
    for(; m % 2 == 0; m /= 2) ++res[2];
    for(std::uint64_t p = 3; p * p <= m; p += 2) {
        for(; m % p == 0; m /= p) ++res[p];
    }
    if(m > 1) res[m] = 1;
    return res;
}

}  // namespace algorithm

#endif
