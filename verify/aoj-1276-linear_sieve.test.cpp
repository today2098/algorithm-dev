#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1276"

#include <algorithm>
#include <iostream>
#include <iterator>

#include "../algorithm/Math/NumberTheory/linear_sieve.hpp"

int main() {
    constexpr int mx = 1299709;
    algorithm::LinearSieve sieve(mx + 1);
    const auto &primes = sieve.primes();

    while(true) {
        int a;
        std::cin >> a;
        if(a == 0) break;

        auto iter = std::lower_bound(primes.cbegin(), primes.cend(), a);
        auto ans = (*iter == a ? 0 : *iter - *prev(iter));
        std::cout << ans << "\n";
    }
}
