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
    // m_lpf[i]:=(正の奇数2*i+1の最小素因数). Least prime factor. m_lpf[i]==2*i+1 のとき，2*i+1は素数．
    std::vector<int> m_lpf;

public:
    // constructor. n未満の自然数を篩にかける．O(N*loglogN).
    Sieve() : Sieve(0) {}
    explicit Sieve(int n) : m_sz(n), m_lpf(n / 2, -1) {
        assert(n >= 0);
        for(long long p = 3; p < m_sz; p += 2) {
            if(m_lpf[p / 2] == -1) {
                m_lpf[p / 2] = p;
                for(long long q = p * p; q < m_sz; q += 2 * p) {
                    if(m_lpf[q / 2] == -1) m_lpf[q / 2] = p;
                }
            }
        }
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
    // 高速素因数分解．O(logN).
    std::map<int, int> prime_factorize(int n) const {
        assert(1 <= n and n < size());
        std::map<int, int> res;
        for(; n % 2 == 0; n /= 2) ++res[2];
        for(; n > 1; n /= m_lpf[n / 2]) ++res[m_lpf[n / 2]];
        return res;
    }
    // オイラーのファイ関数．n以下でnと互いに素な自然数の個数を求める．O(logN).
    int totient(int n) const {
        assert(1 <= n and n < size());
        int res = n;
        for(const auto &[p, _] : prime_factorize(n)) res -= res / p;
        return res;
    }
    // メビウス関数．O(N*loglogN).
    std::vector<int> mobius() const {
        std::vector<int> res(m_sz, 1);  // res[n]:=μ(n).
        for(int p = 2; p < m_sz; ++p) {
            if(lpf(p) == p) {
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
