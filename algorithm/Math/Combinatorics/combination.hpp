#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

template <int mod>
class Combination {
    static_assert(mod >= 2);

    int m_sz;
    std::vector<long long> m_fact;      // m_fact[n]:=(nの階乗).
    std::vector<long long> m_inv;       // m_inv[n]:=(nの逆元).
    std::vector<long long> m_inv_fact;  // m_inv_fact[n]:=(nの階乗の逆元).

    void build(int n) {
        if(n <= m_sz) return;
        m_fact.resize(n);
        m_inv.resize(n);
        m_inv_fact.resize(n);
        for(int i = m_sz; i < n; ++i) {
            m_fact[i] = m_fact[i - 1] * i % mod;
            m_inv[i] = mod - m_inv[mod % i] * (mod / i) % mod;
            m_inv_fact[i] = m_inv_fact[i - 1] * m_inv[i] % mod;
        }
        m_sz = n;
    }

public:
    Combination() : Combination(2) {}
    explicit Combination(int n) : m_sz(2), m_fact(n), m_inv(n), m_inv_fact(n) {
        assert(n >= 2);
        m_fact[0] = m_fact[1] = 1;
        m_inv[1] = 1;
        m_inv_fact[0] = m_inv_fact[1] = 1;
        build(n);
    }

    static constexpr int modulus() { return mod; }
    // 階乗．O(1).
    long long factorial(int n) {
        assert(n >= 0);
        build(n + 1);
        return m_fact[n];
    }
    // 逆元．O(1).
    long long inverse(int n) {
        assert(n >= 1);
        build(n + 1);
        return m_inv[n];
    }
    // 階乗の逆元．O(1).
    long long inverse_factorial(int n) {
        assert(n >= 0);
        build(n + 1);
        return m_inv_fact[n];
    }
    // 順列．O(1).
    long long nPk(int n, int k) {
        assert(n >= 0);
        assert(k >= 0);
        if(n < k) return 0;
        build(n + 1);
        return m_fact[n] * m_inv_fact[n - k] % mod;
    }
    // 組合せ．O(1).
    long long nCk(int n, int k) {
        assert(n >= 0);
        assert(k >= 0);
        if(n < k) return 0;
        build(n + 1);
        return m_fact[n] * m_inv_fact[n - k] % mod * m_inv_fact[k] % mod;
    }
    // 重複組合せ．O(1).
    long long nHk(int n, int k) {
        assert(n >= 0);
        assert(k >= 0);
        if(k == 0) return 1;
        if(n == 0) return 0;
        return nCk(k + n - 1, k);
    }
};

using Combination998244353 = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

}  // namespace algorithm

#endif
