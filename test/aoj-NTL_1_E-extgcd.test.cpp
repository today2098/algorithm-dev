#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include <iostream>

#include "../lib/Math/NumberTheory/extgcd.hpp"

int main() {
    int a, b;
    std::cin >> a >> b;

    int x, y;
    algorithm::extgcd(a, b, x, y);

    std::cout << x << " " << y << std::endl;
}
