#ifndef ALGORITHM_LINEAR_SIEVE_HPP
#define ALGORITHM_LINEAR_SIEVE_HPP 1

/**
 * @brief 線形篩
 * @docs docs/Math/NumberTheory/linear_sieve.md
 */

#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

namespace algorithm {

// 線形篩．
class LinearSieve {
    int m_mx;  // m_mx:=(篩にかける最大の自然数).
    // m_lpf[n]:=(自然数nの最小の素因数). Least prime factor. m_lpf[n]==n のとき，nは素数．
    std::vector<int> m_lpf;
    std::vector<int> m_primes;  // m_primes[]:=(自然数n以下の素数リスト).

public:
    // constructor. n以下の自然数を篩にかける．O(N).
    LinearSieve() : LinearSieve(51e4) {}
    explicit LinearSieve(int n) : m_mx(n), m_lpf(n + 1, -1) {
        assert(n >= 0);
        for(int p = 2; p <= m_mx; ++p) {
            if(m_lpf[p] == -1) {
                m_lpf[p] = p;
                m_primes.push_back(p);
            }
            for(int prime : m_primes) {
                if(prime > m_lpf[p] or (long long) prime * p > m_mx) break;
                m_lpf[prime * p] = prime;
            }
        }
    }

    // 素数判定．O(1).
    bool is_prime(int n) const {
        assert(0 <= n and n <= m_mx);
        return m_lpf[n] == n;
    }
    // 自然数nの最小の素因数を返す．O(1).
    int lpf(int n) const {
        assert(0 <= n and n <= m_mx);
        return m_lpf[n];
    }
    // 高速素因数分解．O(logN).
    std::map<int, int> prime_factorize(int n) const {
        assert(1 <= n and n <= m_mx);
        std::map<int, int> res;
        while(n > 1) {
            res[m_lpf[n]]++;
            n /= m_lpf[n];
        }
        return res;
    }
    // 高速約数列挙．
    std::vector<int> divisors(int n) const {
        assert(1 <= n and n <= m_mx);
        std::vector<int> res({1});
        const std::map<int, int> &&pf = prime_factorize(n);
        for(const auto &[p, cnt] : pf) {
            const int sz = res.size();
            int b = 1;
            for(int i = 0; i < cnt; ++i) {
                b *= p;
                for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
    // 素数リストを参照する．O(1).
    const std::vector<int> &primes() const { return m_primes; }
};

}  // namespace algorithm

#endif
