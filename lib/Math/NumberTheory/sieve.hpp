#ifndef ALGORITHM_SIEVE_HPP
#define ALGORITHM_SIEVE_HPP 1

#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <vector>

namespace algorithm {

// Sieve of Eratosthenes（エラトステネスの篩）.
class Sieve {
    int m_sz;
    // m_lpf[n]:=(自然数nの最小素因数). Least prime factor. m_lpf[n]==n のとき，nは素数．
    std::vector<int> m_lpf;

public:
    // constructor. n未満の自然数を篩にかける．O(N*loglogN).
    Sieve() : Sieve(0) {}
    explicit Sieve(int n) : m_sz(n), m_lpf(n, -1) {
        assert(n >= 0);
        if(m_sz <= 2) return;
        std::iota(m_lpf.begin() + 2, m_lpf.end(), 2);
        for(int p = 2; p * p < m_sz; ++p) {
            if(m_lpf[p] == p) {
                for(int q = p * p; q < m_sz; q += p) {
                    if(m_lpf[q] == q) m_lpf[q] = p;
                }
            }
        }
    }

    // 素数判定．O(1).
    bool is_prime(int n) const {
        assert(0 <= n and n < m_sz);
        return m_lpf[n] == n;
    }
    // 自然数nの最小素因数を返す．O(1).
    int lpf(int n) const {
        assert(0 <= n and n < m_sz);
        return m_lpf[n];
    }
    // 高速素因数分解．O(logN).
    std::map<int, int> prime_factorize(int n) const {
        assert(1 <= n and n < m_sz);
        std::map<int, int> res;
        while(n > 1) {
            res[m_lpf[n]]++;
            n /= m_lpf[n];
        }
        return res;
    }
    // 高速約数列挙．
    std::vector<int> divisors(int n) const {
        assert(1 <= n and n < m_sz);
        std::vector<int> res({1});
        for(const auto &[p, cnt] : prime_factorize(n)) {
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
    // オイラーのファイ関数．n以下でnと互いに素な自然数の個数を求める．O(logN).
    int totient(int n) const {
        assert(1 <= n and n < m_sz);
        int res = n;
        for(const auto &[p, _] : prime_factorize(n)) res -= res / p;
        return res;
    }
    // メビウス関数．O(N*loglogN).
    std::vector<int> mobius() const {
        std::vector<int> res(m_sz, 1);  // res[n]:=μ(n).
        for(int p = 2; p < m_sz; ++p) {
            if(m_lpf[p] == p) {
                res[p] = -1;
                for(int q = 2 * p; q < m_sz; q += p) {
                    if((q / p) % p == 0) res[q] = 0;  // nがある素数pで2回以上割り切れるとき，μ(n)=0.
                    else res[q] = -res[q];            // nがk個の相異なる素因数で分解できるとき，μ(n)=(-1)^k.
                }
            }
        }
        return res;
    }
};

}  // namespace algorithm

#endif
