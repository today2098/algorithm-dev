#ifndef ALGORITHM_PRIME_FACTORIZE_HPP
#define ALGORITHM_PRIME_FACTORIZE_HPP 1

#include <cassert>
#include <map>

namespace algorithm {

// 素因数分解．O(√N).
template <typename Type>
std::map<Type, int> prime_factorize(Type n) {
    assert(n >= 0);
    std::map<Type, int> res;  // res[p]:=(自然数nに含まれる素因数pの個数).
    for(; n % 2 == 0; n /= 2) res[2]++;
    for(Type p = 3; p * p <= n; p += 2) {
        for(; n % p == 0; n /= p) res[p]++;
    }
    if(n > 1) res[n] = 1;
    return res;
}

}  // namespace algorithm

#endif
