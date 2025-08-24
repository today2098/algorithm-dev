#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include <iostream>

#include "../algorithm/Math/NumberTheory/extgcd.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;

    auto [x, y, g] = algorithm::extgcd(a, b);
    std::cout << x << " " << y << std::endl;
}
