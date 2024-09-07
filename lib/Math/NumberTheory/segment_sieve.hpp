#ifndef ALGORITHM_SEGMENT_SIEVE_HPP
#define ALGORITHM_SEGMENT_SIEVE_HPP 1

/**
 * @brief 区間篩
 * @docs docs/Math/NumberTheory/segment_sieve.md
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <numeric>
#include <vector>

namespace algorithm {

// 区間篩．
class SegmentSieve {
    long long m_l, m_r;
    long long m_sr;                                  // m_sr:=√r.
    std::vector<long long> m_small;                  // m_small[n]:=(区間[2,√r)の自然数nにおける最小素因数).
    std::vector<std::map<long long, int> > m_large;  // m_large[n-l][]:=(区間[l,r)の自然数nにおける区間[2,√r)のいくつかの素因数).
    std::vector<long long> m_aux;                    // m_aux[n-l]:=(m_large[n-l][]の積).

public:
    // constructor. 区間[l,r)の自然数を篩にかける．制約の目安はおおよそ 2<=l<r<=1e12, r-l<=1e6．
    SegmentSieve() : SegmentSieve(2, 3) {}
    explicit SegmentSieve(long long l, long long r) : m_l(l), m_r(r), m_large(r - l), m_aux(r - l, 1) {
        assert(2 <= l and l < r);
        m_sr = std::sqrt(m_r) + 1;
        m_small.assign(m_sr, -1);
        std::iota(m_small.begin() + 2, m_small.end(), 2);
        for(long long p = 2; p * p < m_r; ++p) {
            if(m_small[p] == p) {
                for(long long q = p * p; q < m_sr; q += p) m_small[q] = p;
                for(long long q = (m_l + p - 1) / p * p; q < m_r; q += p) {
                    long long tmp = q;
                    while(m_aux[q - m_l] * m_aux[q - m_l] < m_r and tmp % p == 0) {
                        m_large[q - m_l][p]++;
                        m_aux[q - m_l] *= p;
                        tmp /= p;
                    }
                }
            }
        }
    }

    // 素数判定．O(1).
    bool is_prime(long long n) const {
        assert(m_l <= n and n < m_r);
        return m_large[n - m_l].size() == 0;
    }
    // 高速素因数分解．
    std::map<long long, int> prime_factorize(long long n) const {
        assert(m_l <= n and n < m_r);
        std::map<long long, int> res = m_large[n - m_l];
        n /= m_aux[n - m_l];
        if(n >= m_sr) {
            res[n]++;
            return res;
        }
        while(n > 1) {
            res[m_small[n]]++;
            n /= m_small[n];
        }
        return res;
    }
    // 高速約数列挙．
    std::vector<long long> divisors(long long n) const {
        assert(m_l <= n and n < m_r);
        std::vector<long long> res({1});
        const std::map<long long, int> &&pf = prime_factorize(n);
        int capacity = 1;
        for(const auto &[_, cnt] : pf) capacity *= (cnt + 1);
        res.reserve(capacity);
        for(const auto &[p, cnt] : pf) {
            const int sz = res.size();
            long long b = 1;
            for(int i = 0; i < cnt; ++i) {
                b *= p;
                for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

}  // namespace algorithm

#endif
