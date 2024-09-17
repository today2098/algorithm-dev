#ifndef ALGORITHM_NTH_ROOT_HPP
#define ALGORITHM_NTH_ROOT_HPP 1

/**
 * @brief 累乗根（ニュートン法）
 * @docs docs/Math/Algebra/nth_root.md
 */

#include <cassert>
#include <cmath>

#include "power.hpp"

namespace algorithm {

// 累乗根（ニュートン法）．xのn乗根を求める．
constexpr double root(double x, long long n, const double eps = 1e-10) {
    assert(x >= 0.0);
    assert(n >= 1);
    double res = 1.0;
    while(1) {
        double tmp = (x / ipow(res, n - 1) + (n - 1) * res) / n;
        if(std::abs(tmp - res) < eps) break;
        res = tmp;
    }
    return res;
}

}  // namespace algorithm

#endif
