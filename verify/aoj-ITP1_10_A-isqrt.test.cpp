#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_A"
#define ERROR 1e-4

#include <iostream>

#include "../lib/Math/Algebra/square_root.hpp"

int main() {
    double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    auto tmp = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    auto &&ans = algorithm::isqrt(tmp, 1e-8);
    printf("%.6f\n", ans);
}
