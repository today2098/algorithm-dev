#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B"

#include <iostream>

#include "../lib/Math/NumberTheory/big_integer.hpp"

int main() {
    algorithm::BigInteger a, b;
    std::cin >> a >> b;

    auto &&ans = a - b;
    std::cout << ans << std::endl;
}
