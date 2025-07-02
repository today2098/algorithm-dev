#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_A"

#include <iostream>

#include "../algorithm/Math/Algebra/kitamasa.hpp"

int main() {
    int n;
    std::cin >> n;

    algorithm::Kitamasa<int> kitamasa({1, 1}, {1, 1});

    auto ans = kitamasa[n];
    std::cout << ans << std::endl;
}
