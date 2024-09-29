#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_A"

#include <iostream>

#include "../lib/Math/Algebra/kitamasa.hpp"

int main() {
    int n;
    std::cin >> n;

    algorithm::Kitamasa kitamasa({1, 1}, {1, 1});
    std::cout << kitamasa[n] << std::endl;
}
