---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: algorithm/Math/ModularArithmetic/modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n#include <functional>\n\
    #include <iostream>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\n\n\n#line 7 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \n#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return x mod m.\ntemplate\
    \ <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t\
    \ mod) { return x % mod; }\n\n// return x mod m.\ntemplate <std::unsigned_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::int32_t mod) { return modulo(x,\
    \ static_cast<std::uint32_t>(mod)); }\n\n// return x mod m.\ntemplate <std::signed_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t mod) {\n    x %=\
    \ static_cast<std::int64_t>(mod);\n    if(x < 0) x += static_cast<std::int64_t>(mod);\n\
    \    return x;\n}\n\n// return x mod m.\ntemplate <std::signed_integral Type>\n\
    constexpr std::uint32_t modulo(Type x, std::int32_t mod) {\n    x %= mod;\n  \
    \  if(x < 0) x += mod;\n    return x;\n}\n\n}  // namespace internal\n\n}  //\
    \ namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return pair of (x, g)\
    \ s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.\nconstexpr std::pair<std::uint32_t,\
    \ std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {\n    if(a == 0) return\
    \ {0, m};\n    std::uint32_t s = m, t = a;\n    std::uint32_t u = m, v = 1;\n\
    \    while(true) {\n        std::uint32_t q = s / t;\n        s -= t * q, u -=\
    \ v * q;\n        if(s == 0) return {v, t};\n        q = t / s;\n        t -=\
    \ s * q, v += (m - u) * q;\n        if(t == 0) return {u, s};\n    }\n}\n\n} \
    \ // namespace internal\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\ntemplate <std::integral Type>\nconstexpr std::int64_t mod_inv(Type a, std::int32_t\
    \ m) {\n    assert(m >= 1);\n    auto [x, g] = internal::mod_inv(::algorithm::internal::modulo(a,\
    \ m), m);\n    assert(g == 1);\n    return x;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n#line 7 \"\
    algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return n^k mod m.\nconstexpr\
    \ std::uint32_t mod_pow(std::uint64_t n, unsigned long long k, std::uint32_t mod)\
    \ {\n    std::uint64_t res = 1;\n    for(; k > 0; k >>= 1) {\n        if(k & 1ULL)\
    \ res = res * n % mod;\n        n = n * n % mod;\n    }\n    return res;\n}\n\n\
    }  // namespace internal\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0EO(log k).\ntemplate <std::integral Type>\nconstexpr\
    \ std::int64_t mod_pow(Type n, long long k, std::int32_t mod) {\n    assert(mod\
    \ >= 1);\n    auto r = ::algorithm::internal::modulo(n, mod);\n    if(k < 0) {\n\
    \        auto [x, g] = ::algorithm::internal::mod_inv(r, mod);\n        assert(g\
    \ == 1);\n        r = x, k = -k;\n    }\n    return internal::mod_pow(r, k, mod);\n\
    }\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\
    \ntemplate <typename T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\n\
    template <typename T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\
    \ntemplate <typename T>\nconcept modint = is_modint_v<T>;\n\n}  // namespace algorithm\n\
    \n\n#line 14 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n\nnamespace algorithm\
    \ {\n\ntemplate <std::int32_t mod>\nclass Modint : public ModintBase {\n    static_assert(mod\
    \ >= 1);\n\n    std::uint32_t val;\n\n    static constexpr std::uint32_t umod()\
    \ { return mod; }\n\npublic:\n    constexpr Modint() : val(0) {}\n    template\
    \ <std::integral Type>\n    constexpr Modint(Type val) : val(::algorithm::internal::modulo(val,\
    \ mod)) {}\n\n    constexpr Modint operator+() const { return Modint(*this); }\n\
    \    constexpr Modint operator-() const {\n        if(val == 0) Modint();\n  \
    \      return raw(umod() - val);\n    }\n    constexpr Modint &operator++() {\n\
    \        ++val;\n        if(val == umod()) val = 0;\n        return *this;\n \
    \   }\n    constexpr Modint &operator--() {\n        if(val == 0) val = umod();\n\
    \        --val;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        if(rhs.val >= umod() - val) val -= umod();\n       \
    \ val += rhs.val;\n        return *this;\n    }\n    constexpr Modint &operator-=(const\
    \ Modint &rhs) {\n        if(rhs.val > val) val += umod();\n        val -= rhs.val;\n\
    \        return *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs)\
    \ {\n        val = static_cast<std::uint64_t>(val) * rhs.val % umod();\n     \
    \   return *this;\n    }\n    constexpr Modint &operator/=(const Modint &rhs)\
    \ { return *this *= rhs.inv(); }\n\n    friend constexpr bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr\
    \ Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ += rhs; }\n    friend constexpr Modint operator-(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend constexpr\
    \ Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ /= rhs; }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs)\
    \ {\n        std::int64_t val;\n        is >> val;\n        rhs.val = ::algorithm::internal::modulo(val,\
    \ mod);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr std::int32_t\
    \ modulus() { return mod; }\n    static constexpr Modint raw(std::uint32_t val)\
    \ {\n        Modint res;\n        res.val = val;\n        return res;\n    }\n\
    \n    constexpr std::int64_t value() const { return val; }\n    constexpr Modint\
    \ inv() const {\n        auto [x, g] = ::algorithm::internal::mod_inv(val, umod());\n\
    \        assert(g == 1);\n        return raw(x);\n    }\n    constexpr Modint\
    \ pow(long long k) const {\n        if(k < 0) return raw(::algorithm::internal::mod_pow(val,\
    \ -k, umod())).inv();\n        return raw(::algorithm::internal::mod_pow(val,\
    \ k, umod()));\n    }\n\n    friend constexpr Modint mod_inv(const Modint &a)\
    \ { return a.inv(); }\n    friend constexpr Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    template <std::int32_t mod>\nstruct std::hash<algorithm::Modint<mod>> {\n    std::size_t\
    \ operator()(const algorithm::Modint<mod> &ob) const { return ob.value(); }\n\
    };\n\n\n"
  code: "#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP 1\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n#include <functional>\n\
    #include <iostream>\n\n#include \"mod_inv.hpp\"\n#include \"mod_pow.hpp\"\n#include\
    \ \"modint_base.hpp\"\n#include \"modulo.hpp\"\n\nnamespace algorithm {\n\ntemplate\
    \ <std::int32_t mod>\nclass Modint : public ModintBase {\n    static_assert(mod\
    \ >= 1);\n\n    std::uint32_t val;\n\n    static constexpr std::uint32_t umod()\
    \ { return mod; }\n\npublic:\n    constexpr Modint() : val(0) {}\n    template\
    \ <std::integral Type>\n    constexpr Modint(Type val) : val(::algorithm::internal::modulo(val,\
    \ mod)) {}\n\n    constexpr Modint operator+() const { return Modint(*this); }\n\
    \    constexpr Modint operator-() const {\n        if(val == 0) Modint();\n  \
    \      return raw(umod() - val);\n    }\n    constexpr Modint &operator++() {\n\
    \        ++val;\n        if(val == umod()) val = 0;\n        return *this;\n \
    \   }\n    constexpr Modint &operator--() {\n        if(val == 0) val = umod();\n\
    \        --val;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        if(rhs.val >= umod() - val) val -= umod();\n       \
    \ val += rhs.val;\n        return *this;\n    }\n    constexpr Modint &operator-=(const\
    \ Modint &rhs) {\n        if(rhs.val > val) val += umod();\n        val -= rhs.val;\n\
    \        return *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs)\
    \ {\n        val = static_cast<std::uint64_t>(val) * rhs.val % umod();\n     \
    \   return *this;\n    }\n    constexpr Modint &operator/=(const Modint &rhs)\
    \ { return *this *= rhs.inv(); }\n\n    friend constexpr bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr\
    \ Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ += rhs; }\n    friend constexpr Modint operator-(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend constexpr\
    \ Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ /= rhs; }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs)\
    \ {\n        std::int64_t val;\n        is >> val;\n        rhs.val = ::algorithm::internal::modulo(val,\
    \ mod);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr std::int32_t\
    \ modulus() { return mod; }\n    static constexpr Modint raw(std::uint32_t val)\
    \ {\n        Modint res;\n        res.val = val;\n        return res;\n    }\n\
    \n    constexpr std::int64_t value() const { return val; }\n    constexpr Modint\
    \ inv() const {\n        auto [x, g] = ::algorithm::internal::mod_inv(val, umod());\n\
    \        assert(g == 1);\n        return raw(x);\n    }\n    constexpr Modint\
    \ pow(long long k) const {\n        if(k < 0) return raw(::algorithm::internal::mod_pow(val,\
    \ -k, umod())).inv();\n        return raw(::algorithm::internal::mod_pow(val,\
    \ k, umod()));\n    }\n\n    friend constexpr Modint mod_inv(const Modint &a)\
    \ { return a.inv(); }\n    friend constexpr Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    template <std::int32_t mod>\nstruct std::hash<algorithm::Modint<mod>> {\n    std::size_t\
    \ operator()(const algorithm::Modint<mod> &ob) const { return ob.value(); }\n\
    };\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modint.hpp
  requiredBy: []
  timestamp: '2025-08-31 12:36:13+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modint.hpp
layout: document
title: "Modint\u69CB\u9020\u4F53"
---


## 概要

法 $m \in \mathbb{N}$ における剰余類環 $\mathbb{Z}/m\mathbb{Z}$ の要素を表す構造体．

$0$ 以上 $m$ 未満の整数を値として保存し，剰余類環 $\mathbb{Z}/m\mathbb{Z}$ における加法と乗法の演算をサポートする．

$$
\begin{align}
&a + m \mathbb{Z}, \ b + m \mathbb{Z} \in \mathbb{Z} / m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z}) + (b + m \mathbb{Z}) = (a + b) + m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z})(b + m \mathbb{Z}) = a b + m \mathbb{Z}. \notag\\
\end{align}
$$

また，法 $m$ が素数 $p$ であるとき，剰余類環 $\mathbb{Z}/p\mathbb{Z}$ の零元 $0+p\mathbb{Z}$ を除くすべての元 $a+p\mathbb{Z}$ は乗法逆元 $a^{-1}$ をもち，除法の演算も定義できる．

$$
\frac{b + m \mathbb{Z}}{a + m \mathbb{Z}} = b \cdot a^{-1} + m \mathbb{Z}.
$$

## 参考

1. "整数の合同". Wikipedia. <https://ja.wikipedia.org/wiki/整数の合同>.
1. "剰余類環". Wikipedia. <https://ja.wikipedia.org/wiki/剰余類環>.
1. "モジュラ逆数". Wikipedia. <https://ja.wikipedia.org/wiki/モジュラ逆数>.
1. drken. "「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜". Qiita. <https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a>.
1. "群・環・体". HatenaBlog. <https://zellij.hatenablog.com/entry/20121211/p1>.

## 問題

- "D - Writing a Numeral". AtCoder Beginner Contest 298. AtCoder. <https://atcoder.jp/contests/abc298/tasks/abc298_d>.
