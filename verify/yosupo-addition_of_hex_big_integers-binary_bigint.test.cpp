#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_hex_big_integers"

#include <iostream>

#include "../lib/Math/NumberTheory/binary_bigint.hpp"

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i) {
        algorithm::BinaryBigint a, b;
        std::cin >> a >> b;

        a += b;
        std::cout << std::uppercase << a << "\n";
    }
}
