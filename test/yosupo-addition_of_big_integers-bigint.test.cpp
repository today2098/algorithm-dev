#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_big_integers"

#include <iostream>

#include "../lib/Math/NumberTheory/bigint.hpp"

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i) {
        algorithm::Bigint a, b;
        std::cin >> a >> b;

        a += b;
        std::cout << a << "\n";
    }
}
