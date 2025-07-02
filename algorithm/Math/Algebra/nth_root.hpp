#ifndef ALGORITHM_NTH_ROOT_HPP
#define ALGORITHM_NTH_ROOT_HPP 1

#include <cassert>
#include <cmath>

#include "power.hpp"

namespace algorithm {

// 累乗根（ニュートン法）．xのn乗根を求める．
constexpr double nth_root(double x, long long n, double eps = 1e-10) {
    assert(x >= 0.0);
    assert(n >= 1);
    double res = 1.0;
    while(true) {
        double tmp = (x / pow(res, n - 1) + (n - 1) * res) / n;
        if(std::abs(tmp - res) < eps) break;
        res = tmp;
    }
    return res;
}

}  // namespace algorithm

#endif
