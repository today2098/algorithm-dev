#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_C"

#include <iostream>

#include "../lib/Math/NumberTheory/big_integer.hpp"

int main() {
    algorithm::Bigint a, b;
    std::cin >> a >> b;

    auto ans = a * b;
    std::cout << ans << std::endl;
}
