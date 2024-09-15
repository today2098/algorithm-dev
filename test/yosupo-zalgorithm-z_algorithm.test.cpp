#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>

#include "../lib/String/z_algorithm.hpp"

int main() {
    std::string s;
    std::cin >> s;

    auto &&z = algorithm::z_algorithm(s);

    for(auto elem : z) std::cout << elem << " ";
    std::cout << std::endl;
}
