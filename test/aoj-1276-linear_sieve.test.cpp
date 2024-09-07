#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1276"

#include <algorithm>
#include <iostream>
#include <iterator>

#include "../lib/Math/NumberTheory/linear_sieve.hpp"

int main() {
    constexpr int mx = 1299709;
    algorithm::LinearSieve sieve(mx);

    while(1) {
        int a;
        std::cin >> a;
        if(a == 0) break;

        auto itr = std::lower_bound(sieve.primes().cbegin(), sieve.primes().cend(), a);
        if(*itr == a) std::cout << 0 << "\n";
        else std::cout << *itr - *std::prev(itr) << "\n";
    }
}
