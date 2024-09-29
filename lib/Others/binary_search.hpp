#ifndef ALGORITHM_BINARY_SEARCH_HPP
#define ALGORITHM_BINARY_SEARCH_HPP 1

/**
 * @brief 二分探索
 * @docs docs/Others/binary_search.md
 */

#include <type_traits>

namespace algorithm {

// 二分探索．O(logN).
template <typename Type, class Func, typename std::enable_if_t<std::is_integral_v<Type>, bool> = false>
constexpr Type bisearch(Type ok, Type ng, const Func &eval) {
    while(ng - ok > 1) {
        Type mid = ok + (ng - ok) / 2;
        (eval(mid) ? ok : ng) = mid;
    }
    return ng;
}

// 二分探索．O(logN).
template <typename Type, class Func, typename std::enable_if_t<std::is_floating_point_v<Type>, bool> = false>
constexpr Type bisearch(Type ok, Type ng, Type eps, const Func &eval) {
    while(ng - ok > eps) {
        Type mid = ok + (ng - ok) / 2;
        (eval(mid) ? ok : ng) = mid;
    }
    return ng;
}

}  // namespace algorithm

#endif
