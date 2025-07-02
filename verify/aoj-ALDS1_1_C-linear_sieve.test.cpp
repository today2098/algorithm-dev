#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C"

#include <iostream>

#include "../algorithm/Math/NumberTheory/linear_sieve.hpp"

int main() {
    constexpr int mx = 1e8;

    int n;
    std::cin >> n;

    int ans = 0;
    algorithm::LinearSieve sieve(mx + 1);
    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;

        if(sieve.is_prime(a)) ans++;
    }

    std::cout << ans << std::endl;
}
