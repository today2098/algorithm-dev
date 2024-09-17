#ifndef ALGORITHM_SQUARE_ROOT_HPP
#define ALGORITHM_SQUARE_ROOT_HPP 1

/**
 * @brief 平方根（ニュートン法）
 * @docs docs/Math/Algebra/square_root.md
 */

#include <cassert>
#include <cmath>

namespace algorithm {

// 平方根（ニュートン法）．
constexpr double isqrt(double x, const double eps = 1e-10) {
    assert(x >= 0.0);
    double res = 1.0;
    while(1) {
        double tmp = (x / res + res) / 2;
        if(std::abs(tmp - res) < eps) break;
        res = tmp;
    }
    return res;
}

}  // namespace algorithm

#endif
