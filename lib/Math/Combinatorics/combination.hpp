#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

template <int mod>
class Combination {
    static_assert(2 <= mod);

    static Combination *s_instance;
    int m_sz;
    std::vector<long long> m_fact;  // m_fact[n]:=(nの階乗).
    std::vector<long long> m_inv;   // m_inv[n]:=(nの逆元).
    std::vector<long long> m_finv;  // m_finv[n]:=(nの階乗の逆元).

    Combination() : m_sz(2), m_fact({1, 1}), m_inv({-1, 1}), m_finv({1, 1}) {}

    static Combination *instance() {
        if(!s_instance) s_instance = new Combination;
        return s_instance;
    }
    void calc(int limit) {
        assert(limit <= mod);
        if(limit <= m_sz) return;
        reserve_internal(limit);
        for(int n = m_sz; n < limit; ++n) {
            m_fact.push_back(m_fact[n - 1] * n % mod);
            m_inv.push_back(mod - m_inv[mod % n] * (mod / n) % mod);
            m_finv.push_back(m_finv[n - 1] * m_inv[n] % mod);
        }
        m_sz = limit;
    }
    long long fact(int n) {
        assert(0 <= n);
        calc(n + 1);
        return m_fact[n];
    }
    long long inv(int n) {
        assert(1 <= n);
        calc(n + 1);
        return m_inv[n];
    }
    long long finv(int n) {
        assert(0 <= n);
        calc(n + 1);
        return m_finv[n];
    }
    long long nPk_internal(int n, int k) {
        assert(0 <= k and k <= n);
        calc(n + 1);
        return m_fact[n] * m_finv[n - k] % mod;
    }
    long long nCk_internal(int n, int k) {
        assert(0 <= n);
        assert(0 <= k);
        if(k > n) return 0;
        calc(n + 1);
        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;
    }
    void resize_internal(int limit) {
        assert(0 <= limit);
        if(limit < 2) return;
        if(m_sz < limit) {
            reserve_internal(limit);
            return;
        }
        m_fact.resize(limit);
        m_inv.resize(limit);
        m_finv.resize(limit);
        m_sz = limit;
    }
    void reserve_internal(int cap) {
        assert(0 <= cap);
        m_fact.reserve(cap);
        m_inv.reserve(cap);
        m_finv.reserve(cap);
    }
    void shrink_to_fit_internal() {
        m_fact.shrink_to_fit();
        m_inv.shrink_to_fit();
        m_finv.shrink_to_fit();
    }

public:
    static constexpr int modulus() { return mod; }
    // 階乗．O(1).
    static long long factorial(int n) { return instance()->fact(n); }
    // 逆元．O(1).
    static long long inverse(int n) { return instance()->inv(n); }
    // 階乗の逆元．O(1).
    static long long inverse_fact(int n) { return instance()->finv(n); }
    // 順列．O(1).
    static long long nPk(int n, int k) { return instance()->nPk_internal(n, k); }
    // 組合せ．O(1).
    static long long nCk(int n, int k) { return instance()->nCk_internal(n, k); }
    // 重複組合せ．O(1).
    static long long nHk(int n, int k) {
        assert(1 <= n);
        assert(0 <= k);
        return instance()->nCk_internal(k + n - 1, k);
    }
    static void resize(int limit) { instance()->resize_internal(limit); }
    static void reserve(int cap) { instance()->reserve_internal(cap); }
    static void shrink_to_fit() { instance()->shrink_to_fit_internal(); }
    static void destroy() {
        delete s_instance;
        s_instance = nullptr;
    }
};

template <int mod>
Combination<mod> *Combination<mod>::s_instance = nullptr;

using Combination998244353 = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

}  // namespace algorithm

#endif
