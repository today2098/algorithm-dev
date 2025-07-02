#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D"
#define ERROR 1e-5

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "../algorithm/Math/Algebra/nth_root.hpp"
#include "../algorithm/Math/Algebra/power.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), y(n);
    for(auto &elem : x) std::cin >> elem;
    for(auto &elem : y) std::cin >> elem;

    auto f = [&](int p) -> double {
        double tmp = 0.0;
        for(int i = 0; i < n; ++i) tmp += algorithm::pow(std::abs(x[i] - y[i]), p);
        return algorithm::nth_root(tmp, p, 1e-10);
    };
    auto g = [&]() -> int {
        int res = 0;
        for(int i = 0; i < n; ++i) res = std::max(res, std::abs(x[i] - y[i]));
        return res;
    };

    for(int p = 1; p <= 3; ++p) printf("%.8lf\n", f(p));
    std::cout << g() << std::endl;
}
