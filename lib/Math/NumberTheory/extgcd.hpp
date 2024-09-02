#ifndef ALGORITHM_EXTGCD_HPP
#define ALGORITHM_EXTGCD_HPP 1

/**
 * @brief 拡張ユークリッドの互除法
 * @docs docs/Math/NumberTheory/extgcd.md
 */

namespace algorithm {

// 拡張ユークリッドの互除法．
// ax+by=gcd(a,b) を満たす整数の組(x,y)を求め，gcd(a,b)を返す．O(log(min(a,b))).
template <typename Type>
Type extgcd(Type a, Type b, Type &x, Type &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    Type &&d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

}  // namespace algorithm

#endif
