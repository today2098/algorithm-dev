#ifndef ALGORITHM_EXTGCD_HPP
#define ALGORITHM_EXTGCD_HPP 1

#include <concepts>
#include <tuple>

namespace algorithm {

namespace internal {

template <std::signed_integral Type>
constexpr Type extgcd(Type a, Type b, Type &x, Type &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    Type g = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

}  // namespace internal

// 拡張ユークリッドの互除法．O(log(min(a,b))).
template <std::signed_integral T, std::signed_integral U>
constexpr auto extgcd(T a, U b) {
    using ct = std::common_type_t<T, U>;
    ct x, y;
    ct g = internal::extgcd<ct>(a, b, x, y);
    if(g < 0) x = -x, y = -y, g = -g;
    return std::tuple<ct, ct, ct>(x, y, g);  // returns the tuple of (x, y, g) s.t. g=gcd(a,b), ax+by=g, |x|<=|b|/g, |y|<=|a|/g.
}

}  // namespace algorithm

#endif
