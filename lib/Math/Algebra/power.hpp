#ifndef ALGORITHM_POWER_HPP
#define ALGORITHM_POWER_HPP 1

#include <cassert>

namespace algorithm {

// 繰り返し二乗法．O(logK).
template <typename Type>
constexpr Type pow(Type n, long long k) {
    assert(k >= 0);
    Type res = 1;
    while(k > 0) {
        if(k & 1LL) res *= n;
        n *= n;
        k >>= 1;
    }
    return res;
}

}  // namespace algorithm

#endif
