#ifndef ALGORITHM_PRIME_FACTORIZE_HPP
#define ALGORITHM_PRIME_FACTORIZE_HPP 1

/**
 * @brief 素因数分解
 * @docs docs/Math/NumberTheory/prime_factorize.md
 */

#include <cassert>
#include <map>

namespace algorithm {

// 素因数分解．O(√N).
template <typename Type>
std::map<Type, int> prime_factorize(Type n) {
    assert(n >= 0);
    std::map<Type, int> res;  // res[p]:=(自然数nに含まれる素因数pの個数).
    while(n % 2 == 0) res[2]++, n /= 2;
    for(Type p = 3; p * p <= n; p += 2) {
        while(n % p == 0) res[p]++, n /= p;
    }
    if(n > 1) res[n] = 1;
    return res;
}

}  // namespace algorithm

#endif
