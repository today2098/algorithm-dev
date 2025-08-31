#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include <iostream>

#include "../algorithm/Math/ModularArithmetic/mod_pow.hpp"

int main() {
    constexpr int MOD = 1'000'000'007;

    int m, n;
    std::cin >> m >> n;

    auto ans = algorithm::mod_pow(m, n, MOD);
    std::cout << ans << std::endl;
}
