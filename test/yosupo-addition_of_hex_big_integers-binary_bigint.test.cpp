#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_hex_big_integers"

#include <iostream>

#include "../lib/Math/NumberTheory/signed_binary_bigint.hpp"

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i) {
        algorithm::SignedBinaryBigint a, b;
        std::cin >> a >> b;

        auto &&ans = a + b;
        std::cout << std::uppercase << ans << "\n";
    }
}
