#ifndef ALGORITHM_BINARY_SEARCH_HPP
#define ALGORITHM_BINARY_SEARCH_HPP 1

#include <concepts>
#include <functional>
#include <type_traits>

namespace algorithm {

template <std::integral Type, class Eval>
constexpr Type bisearch(Type ok, Type ng, Eval eval) {
    static_assert(std::is_convertible_v<Eval, std::function<bool(Type)>>);
    while(ng - ok > 1) {
        Type mid = ok + (ng - ok) / 2;
        (eval(mid) ? ok : ng) = mid;
    }
    return ng;
}

template <std::floating_point Type, class Eval>
constexpr Type bisearch(Type ok, Type ng, Type eps, Eval eval) {
    static_assert(std::is_convertible_v<Eval, std::function<bool(Type)>>);
    while(ng - ok > eps) {
        Type mid = ok + (ng - ok) / 2;
        (eval(mid) ? ok : ng) = mid;
    }
    return ng;
}

}  // namespace algorithm

#endif
