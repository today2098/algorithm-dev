#ifndef ALGORITHM_NUMBER_THEORETIC_TRANSFORM_HPP
#define ALGORITHM_NUMBER_THEORETIC_TRANSFORM_HPP 1

/**
 * @brief Number Theoretic Transform（数論変換）
 * @docs docs/Math/Convolution/number_theoretic_transform.md
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>

#include "../ModularArithmetic/modint_base.hpp"

namespace algorithm {

namespace ntt {

constexpr int MOD = 998'244'353;     // 998'244'353 = 2^23 * 7 * 17 + 1.
constexpr int MOD2 = 167'772'161;    // 167'772'161 = 2^25 * 5 + 1.
constexpr int MOD3 = 469'762'049;    // 469'762'049 = 2^26 * 7 + 1.
constexpr int MOD4 = 754'974'721;    // 754'974'721 = 2^24 * 3^2 * 5 + 1.
constexpr int MOD5 = 1'107'296'257;  // 1'107'296'257 = 2^25 * 3 * 11 + 1.
constexpr int MOD6 = 1'224'736'769;  // 1'224'736'769 = 2^24 * 73 + 1.
constexpr int MOD7 = 1'711'276'033;  // 1'224'736'769 = 2^25 * 3 * 17 + 1.
constexpr int MOD8 = 1'811'939'329;  // 1'224'736'769 = 2^26 * 3^3 + 1.

// 素数判定．O(√N).
template <typename Type>
constexpr bool is_prime(Type n) {
    assert(n >= 0);
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(Type p = 3; p * p <= n; p += 2) {
        if(n % p == 0) return false;
    }
    return true;
}

// 繰り返し二乗法（mod付き）．n^k (mod m) を求める．O(logK).
constexpr int mod_pow(long long n, long long k, int m) {
    assert(k >= 0);
    assert(m >= 1);
    long long res = 1;
    n %= m;
    while(k > 0) {
        if(k & 1LL) res = res * n % m;
        n = n * n % m;
        k >>= 1;
    }
    return res;
}

// 素数pを法とする最小の原始根を求める．
constexpr int primitive_root(int p) {
    assert(p >= 2);
    if(p == 2) return 1;
    if(p == MOD) return 3;
    if(p == MOD2) return 3;
    if(p == MOD3) return 3;
    if(p == MOD4) return 11;
    if(p == MOD5) return 10;
    if(p == MOD6) return 3;
    if(p == MOD7) return 29;
    if(p == MOD8) return 13;
    assert(is_prime(p));
    std::array<int, 20> divs({2});  // divs[]:=(p-1の素因数).
    int cnt = 1;
    int n = (p - 1) / 2;
    while(n % 2 == 0) n /= 2;
    for(int q = 3; q * q <= n; q += 2) {
        if(n % q == 0) {
            divs[cnt++] = q;
            while(n % q == 0) n /= q;
        }
    }
    if(n > 1) divs[cnt++] = n;
    for(int g = 2;; ++g) {
        bool ok = true;
        for(int i = 0; i < cnt; ++i) {
            if(mod_pow(g, (p - 1) / divs[i], p) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
}

// Number Theoretic Transform（数論変換）.
// 引数の数列の長さは2のべき乗であること．O(N*logN).
template <class mint, typename std::enable_if_t<is_modint_v<mint>, bool> = false>
void transform(std::vector<mint> &a, bool inv = false) {
    const int n = a.size();
    if(n == 0) return;
    assert((mint::modulus() - 1) % n == 0);
    static bool first = true;
    static std::array<mint, 30> ws, inv_ws;  // ws[k]:=(2^k乗根), inv_ws[k]:=(2^k乗根の逆元).
    if(first) {
        mint &&pr = primitive_root(mint::modulus());
        int rank = 0;
        while(!((mint::modulus() - 1) & 1 << rank)) rank++;
        ws[rank] = pr.pow((mint::modulus() - 1) >> rank);
        inv_ws[rank] = ws[rank].inv();
        for(int k = rank - 1; k >= 0; --k) {
            ws[k] = ws[k + 1] * ws[k + 1];
            inv_ws[k] = inv_ws[k + 1] * inv_ws[k + 1];
        }
        first = false;
    }
    int lb = 0;  // lb:=log2(n).
    while(1 << lb < n) lb++;
    assert(n == 1 << lb);
    for(int i = 0; i < n; ++i) {
        int j = 0;
        for(int k = 0; k < lb; ++k) j |= (i >> k & 1) << (lb - 1 - k);
        if(i < j) std::swap(a[i], a[j]);
    }
    for(int b = 1, k = 1; b < n; b <<= 1, ++k) {
        mint w = 1;
        for(int i = 0; i < b; ++i) {
            for(int j = 0; j < n; j += b << 1) {
                mint &&tmp = a[i + j + b] * w;
                a[i + j + b] = a[i + j] - tmp;
                a[i + j] += tmp;
            }
            w *= (inv ? inv_ws[k] : ws[k]);
        }
    }
    if(inv) {
        mint &&tmp = mint(n).inv();
        for(int i = 0; i < n; ++i) a[i] *= tmp;
    }
}

// 畳み込み．
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N^2).
template <typename Type>
std::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type> &b) {
    const int n = a.size(), m = b.size();
    if(n == 0 or m == 0) return std::vector<Type>();
    std::vector<Type> res(n + m - 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) res[i + j] += a[i] * b[j];
    }
    return res;
}

// 畳み込み．
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N*logN).
template <class mint, typename std::enable_if_t<is_modint_v<mint>, bool> = false>
std::vector<mint> convolve(std::vector<mint> a, std::vector<mint> b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<mint>();
    const int n = a.size() + b.size() - 1;
    int m = 1;
    while(m < n) m <<= 1;
    a.resize(m, 0), b.resize(m, 0);
    transform(a), transform(b);
    for(int i = 0; i < m; ++i) a[i] *= b[i];
    transform(a, true);
    a.resize(n);
    return a;
}

}  // namespace ntt

}  // namespace algorithm

#endif
