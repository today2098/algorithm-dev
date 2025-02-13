#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 数え上げ（mod付き）．
template <int mod>
class Combination {
    static_assert(mod >= 2);

    static int s_sz, s_cap;
    static std::vector<long long> s_fact;  // s_fact[n]:=(nの階乗).
    static std::vector<long long> s_inv;   // s_inv[n]:=(nの逆元).
    static std::vector<long long> s_finv;  // s_finv[n]:=(nの階乗の逆元).

    Combination() = default;

    static void calc(int mx) {
        assert(mx < mod);
        if(mx < s_sz) return;
        reserve(mx);
        for(int n = s_sz; n <= mx; ++n) {
            s_fact.push_back(s_fact[n - 1] * n % mod);
            s_inv.push_back(mod - s_inv[mod % n] * (mod / n) % mod);
            s_finv.push_back(s_finv[n - 1] * s_inv[n] % mod);
        }
        s_sz = mx + 1;
    }

public:
    static constexpr int modulus() { return mod; }
    static void reserve(int mx) {
        if(mx < s_cap) return;
        s_cap = mx + 1;
        s_fact.reserve(s_cap);
        s_inv.reserve(s_cap);
        s_finv.reserve(s_cap);
    }
    // 階乗．O(1).
    static long long factorial(int n) {
        assert(0 <= n);
        calc(n);
        return s_fact[n];
    }
    // 逆元．O(1).
    static long long inverse(int n) {
        assert(1 <= n);
        calc(n);
        return s_inv[n];
    }
    // 階乗の逆元．O(1).
    static long long inverse_fact(int n) {
        assert(0 <= n);
        calc(n);
        return s_finv[n];
    }
    // 順列．O(1).
    static long long nPk(int n, int k) {
        assert(0 <= k and k <= n);
        calc(n);
        return s_fact[n] * s_finv[n - k] % mod;
    }
    // 組合せ．O(1).
    static long long nCk(int n, int k) {
        assert(0 <= n);
        assert(0 <= k);
        if(k > n) return 0;
        calc(n);
        return s_fact[n] * s_finv[n - k] % mod * s_finv[k] % mod;
    }
    // 重複組合せ．O(1).
    static long long nHk(int n, int k) {
        assert(1 <= n);
        assert(0 <= k);
        return nCk(k + n - 1, k);
    }
};

template <int mod>
int Combination<mod>::s_sz = 2;

template <int mod>
int Combination<mod>::s_cap = 2;

template <int mod>
std::vector<long long> Combination<mod>::s_fact({1, 1});

template <int mod>
std::vector<long long> Combination<mod>::s_inv({-1, 1});

template <int mod>
std::vector<long long> Combination<mod>::s_finv({1, 1});

using Combination998244353 = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

}  // namespace algorithm

#endif
