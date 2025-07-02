#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E"

#include <iostream>

#include "../algorithm/Math/NumberTheory/bigint.hpp"

int main() {
    algorithm::Bigint a, b;
    std::cin >> a >> b;

    a %= b;
    std::cout << a << std::endl;
}
