#ifndef ALGORITHM_LINEAR_SIEVE_HPP
#define ALGORITHM_LINEAR_SIEVE_HPP 1

#include <algorithm>
#include <cassert>
#include <map>
#include <ranges>
#include <vector>

namespace algorithm {

// 線形篩．
class LinearSieve {
    int m_sz;
    // m_lpf[i]:=(正の奇数2*i+1の最小素因数). Least prime factor. m_lpf[i]==2*i+1 のとき，2*i+1は素数．
    std::vector<int> m_lpf;
    std::vector<int> m_primes;  // m_primes[]:=(自然数n未満の素数リスト).

public:
    // constructor. n未満の自然数を篩にかける．O(N).
    LinearSieve() : LinearSieve(0) {}
    explicit LinearSieve(int n) : m_sz(n), m_lpf(n / 2, -1) {
        assert(n >= 0);
        if(m_sz <= 2) return;
        m_primes.push_back(2);
        int p = 3;
        for(int i = 1, end = m_lpf.size(); i < end; ++i) {
            if(m_lpf[i] == -1) {
                m_lpf[i] = p;
                m_primes.push_back(p);
            }
            int limit = (m_sz - 1) / p;
            for(const auto &prime : m_primes | std::ranges::views::drop(1) | std::ranges::views::take_while([&](int prime) -> bool { return prime <= m_lpf[i] and prime <= limit; })) m_lpf[p * prime / 2] = prime;
            p += 2;
        }
        m_primes.shrink_to_fit();
    }

    int size() const { return m_sz; }
    // 素数判定．O(1).
    bool is_prime(int n) const {
        assert(0 <= n and n < size());
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        return m_lpf[n / 2] == n;
    }
    // 自然数nの最小素因数を取得する．O(1).
    int lpf(int n) const {
        assert(0 <= n and n < size());
        if(n < 2) return -1;
        if(n % 2 == 0) return 2;
        return m_lpf[n / 2];
    }
    // 高速素因数分解．O(log N).
    std::map<int, int> prime_factorize(int n) const {
        assert(1 <= n and n < size());
        std::map<int, int> res;
        for(; n % 2 == 0; n /= 2) ++res[2];
        for(; n > 1; n /= m_lpf[n / 2]) ++res[m_lpf[n / 2]];
        return res;
    }
    // 素数リストを参照する．O(1).
    const std::vector<int> &primes() const { return m_primes; }
};

}  // namespace algorithm

#endif
