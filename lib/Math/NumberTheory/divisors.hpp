#ifndef ALGORITHM_DIVISORS_HPP
#define ALGORITHM_DIVISORS_HPP 1

/**
 * @brief 約数列挙
 * @docs docs/Math/NumberTheory/divisors.md
 */

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 約数列挙．O(√N).
template <typename Type>
std::vector<Type> divisors(Type n) {
    assert(n >= 1);
    std::vector<Type> res;  // res[]:=(自然数nの約数の集合).
    for(Type p = 1; p * p <= n; ++p) {
        if(n % p == 0) {
            res.push_back(p);
            Type q = n / p;
            if(q != p) res.push_back(q);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

}  // namespace algorithm

#endif
