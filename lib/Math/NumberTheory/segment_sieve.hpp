#ifndef ALGORITHM_SEGMENT_SIEVE_HPP
#define ALGORITHM_SEGMENT_SIEVE_HPP 1

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
    long long m_sr;                                 // m_sr:=√r.
    std::vector<long long> m_small;                 // m_small[n]:=(区間[2,√r)の自然数nにおける最小素因数).
    std::vector<std::map<long long, int>> m_large;  // m_large[n-l][]:=(区間[l,r)の自然数nにおける区間[2,√r)のいくつかの素因数).
    std::vector<long long> m_aux;                   // m_aux[n-l]:=(m_large[n-l][]の積).

public:
    // constructor. 区間[l,r)の自然数を篩にかける．制約の目安はおおよそ 2<=l<r<=1e12, r-l<=1e6．
    SegmentSieve() : SegmentSieve(2, 3) {}
    explicit SegmentSieve(long long l, long long r) : m_l(l), m_r(r) {
        assert(2 <= l and l < r);
        m_sr = std::sqrt(m_r) + 1;
        m_small.assign(m_sr, -1);
        std::iota(m_small.begin() + 2, m_small.end(), 2);
        m_large.resize(r - l);
        m_aux.assign(r - l, 1);
        for(long long p = 2; p * p < m_r; ++p) {
            if(m_small[p] == p) {
                for(long long q = p * p; q < m_sr; q += p) m_small[q] = p;
                for(long long q = std::max((m_l + p - 1) / p, 2LL) * p; q < m_r; q += p) {
                    long long tmp = q;
                    while(m_aux[q - m_l] * m_aux[q - m_l] < m_r and tmp % p == 0) {
                        ++m_large[q - m_l][p];
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
            ++res[n];
            return res;
        }
        while(n > 1) {
            ++res[m_small[n]];
            n /= m_small[n];
        }
        return res;
    }
};

}  // namespace algorithm

#endif
