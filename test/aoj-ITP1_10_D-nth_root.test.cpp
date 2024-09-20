#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D"
#define ERROR 1e-5

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "../lib/Math/Algebra/nth_root.hpp"
#include "../lib/Math/Algebra/power.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for(auto &in : x) std::cin >> in;
    for(auto &in : y) std::cin >> in;

    auto f = [&](int p) -> double {
        double tmp = 0.0;
        for(int i = 0; i < n; ++i) tmp += algorithm::ipow(std::abs(x[i] - y[i]), p);
        return algorithm::nth_root(tmp, p, 1e-10);
    };

    for(int p = 1; p <= 3; ++p) {
        auto &&ans = f(p);
        printf("%.8lf\n", ans);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) ans = std::max(ans, std::abs(x[i] - y[i]));

    printf("%.8lf\n", (double)ans);
}
