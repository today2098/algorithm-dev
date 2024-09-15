#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

/**
 * @brief 組合せ（mod付き）
 * @docs docs/Math/Combinatorics/combination.md
 */

#include <cassert>
#include <vector>

namespace algorithm {

// 組合せ（mod付き）．
template <int mod>
class Combination {
    int m_mx;                       // m_mx:=(引数nの最大値).
    std::vector<long long> m_fact;  // m_fact[n]:=(nの階乗).
    std::vector<long long> m_inv;   // m_inv[n]:=(nの逆元).
    std::vector<long long> m_finv;  // m_finv[n]:=(nの階乗の逆元).

public:
    // constructor. 制約は，modが素数かつ mx<mod であること．O(N).
    Combination() : Combination(51e4) {}
    explicit Combination(int mx) : m_mx(mx), m_fact(mx + 1), m_inv(mx + 1), m_finv(mx + 1) {
        static_assert(mod >= 1);
        assert(1 <= m_mx and m_mx < mod);
        m_fact[0] = m_fact[1] = 1;
        m_inv[1] = 1;
        m_finv[0] = m_finv[1] = 1;
        for(int n = 2; n <= m_mx; ++n) {
            m_fact[n] = m_fact[n - 1] * n % mod;
            m_inv[n] = mod - m_inv[mod % n] * (mod / n) % mod;
            m_finv[n] = m_finv[n - 1] * m_inv[n] % mod;
        }
    }

    static constexpr int modulus() { return mod; }
    // 階乗．O(1).
    long long factorial(int n) const {
        assert(0 <= n and n <= m_mx);
        return m_fact[n];
    }
    // 逆元．O(1).
    long long inverse(int n) const {
        assert(1 <= n and n <= m_mx);
        return m_inv[n];
    }
    // 階乗の逆元．O(1).
    long long inverse_fact(int n) const {
        assert(0 <= n and n <= m_mx);
        return m_finv[n];
    }
    // 順列．O(1).
    long long nPk(int n, int k) const {
        assert(0 <= k and k <= n and n <= m_mx);
        return m_fact[n] * m_finv[n - k] % mod;
    }
    // 組合せ．O(1).
    long long nCk(int n, int k) const {
        assert(0 <= k and k <= n and n <= m_mx);
        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;
    }
    // 重複組合せ．O(1).
    long long nHk(int n, int k) const {
        assert(n >= 1 and k >= 0);
        return nCk(k + n - 1, k);
    }
};

using Combination998244353 = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

}  // namespace algorithm

#endif
