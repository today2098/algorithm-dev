#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include <iostream>

#include "../algorithm/Math/NumberTheory/is_prime.hpp"

int main() {
    int n;
    std::cin >> n;

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;

        if(algorithm::is_prime(a)) ans++;
    }

    std::cout << ans << std::endl;
}
