#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1276"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "../lib/Math/NumberTheory/sieve.hpp"

int main() {
    constexpr int mx = 1299709;
    algorithm::Sieve sieve(mx);

    std::vector<int> primes;
    primes.reserve(100000);
    for(int p = 2; p <= mx; ++p) {
        if(sieve.is_prime(p)) primes.push_back(p);
    }

    while(1) {
        int a;
        std::cin >> a;
        if(a == 0) break;

        auto itr = std::lower_bound(primes.cbegin(), primes.cend(), a);
        if(*itr == a) std::cout << 0 << "\n";
        else std::cout << *itr - *std::prev(itr) << "\n";
    }
}
