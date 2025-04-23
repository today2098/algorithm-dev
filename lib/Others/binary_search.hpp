#ifndef ALGORITHM_BINARY_SEARCH_HPP
#define ALGORITHM_BINARY_SEARCH_HPP 1

#include <cassert>
#include <concepts>
#include <functional>
#include <numeric>
#include <type_traits>

namespace algorithm {

template <std::integral Type, class Pred>
constexpr Type bisearch(Type ok, Type ng, Pred pred) {
    static_assert(std::is_convertible_v<Pred, std::function<bool(Type)>>);
    assert(ok <= ng);
    if(!pred(ok)) return ok;
    while(ng - ok > 1) {
        Type mid = std::midpoint(ok, ng);
        (pred(mid) ? ok : ng) = mid;
    }
    return ng;
}

template <std::floating_point Type, class Pred>
constexpr Type bisearch(Type ok, Type ng, Type eps, Pred pred) {
    static_assert(std::is_convertible_v<Pred, std::function<bool(Type)>>);
    assert(ok <= ng);
    if(!pred(ok)) return ok;
    while(ng - ok > eps) {
        Type mid = std::midpoint(ok, ng);
        (pred(mid) ? ok : ng) = mid;
    }
    return ng;
}

}  // namespace algorithm

#endif
