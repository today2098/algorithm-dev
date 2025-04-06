#ifndef ALGORITHM_SQUARE_ROOT_HPP
#define ALGORITHM_SQUARE_ROOT_HPP 1

#include <cassert>
#include <cmath>

namespace algorithm {

// 平方根（ニュートン法）．
constexpr double sqrt(double x, double eps = 1e-10) {
    assert(x >= 0.0);
    double res = 1.0;
    while(true) {
        double tmp = (x / res + res) / 2;
        if(std::abs(tmp - res) < eps) break;
        res = tmp;
    }
    return res;
}

}  // namespace algorithm

#endif
