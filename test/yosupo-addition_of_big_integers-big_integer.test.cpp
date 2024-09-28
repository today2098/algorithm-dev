#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include <iostream>

#include "../lib/Math/NumberTheory/big_integer.hpp"

int main() {
    int t;
    std::cin >> t;

    algorithm::BigInteger a, b;
    for(int i = 0; i < t; ++i) {
        std::cin >> a >> b;

        auto &&ans = a + b;
        std::cout << ans << "\n";
    }
}
