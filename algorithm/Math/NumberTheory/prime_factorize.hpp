#ifndef ALGORITHM_PRIME_FACTORIZE_HPP
#define ALGORITHM_PRIME_FACTORIZE_HPP 1

#include <cassert>
#include <concepts>
#include <map>

namespace algorithm {

// 素因数分解．O(√N).
template <std::integral Type>
std::map<Type, int> prime_factorize(Type n) {
    assert(n >= 0);
    if(n == 0) return std::map<Type, int>();
    std::map<Type, int> res;  // res[p]:=(自然数nに含まれる素因数pの個数).
    unsigned long long m = n;
    for(; m % 2 == 0; m /= 2) ++res[2];
    for(unsigned long long p = 3; p * p <= m; p += 2) {
        for(; m % p == 0; m /= p) ++res[p];
    }
    if(m > 1) res[m] = 1;
    return res;
}

}  // namespace algorithm

#endif
