---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
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
  bundledCode: "#line 1 \"lib/Math/ModularArithmetic/modint.hpp\"\n\n\n\n#include\
    \ <iostream>\n#include <utility>\n\n#line 1 \"lib/Math/ModularArithmetic/modint_base.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\
    \ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate\
    \ <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\n}  //\
    \ namespace algorithm\n\n\n#line 8 \"lib/Math/ModularArithmetic/modint.hpp\"\n\
    \nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n \
    \   static_assert(mod >= 1);\n\n    long long val;\n\n    constexpr void normalize()\
    \ {\n        if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val\
    \ += mod;\n    }\n\npublic:\n    constexpr Modint() : val(0) {}\n    constexpr\
    \ Modint(long long val) : val(val) {\n        normalize();\n    }\n\n    constexpr\
    \ Modint operator+() const { return Modint(*this); }\n    constexpr Modint operator-()\
    \ const {\n        if(val == 0) Modint();\n        Modint res = *this;\n     \
    \   res.val = mod - res.val;\n        return res;\n    }\n    constexpr Modint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator--() {\n        if(val == 0) val\
    \ = mod;\n        val--;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n     \
    \   val = val * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend\
    \ constexpr bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val\
    \ == rhs.val; }\n    friend constexpr Modint operator+(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) += rhs; }\n    friend constexpr Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr\
    \ Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ *= rhs; }\n    friend constexpr Modint operator/(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    constexpr long long value() const { return val; }\n   \
    \ constexpr Modint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return Modint(u);\n    }\n    constexpr Modint pow(long long\
    \ k) const {\n        if(k < 0) return inv().pow(-k);\n        Modint res = 1,\
    \ mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    friend constexpr Modint mod_inv(const Modint &a) { return a.inv();\
    \ }\n    friend constexpr Modint mod_pow(const Modint &a, long long k) { return\
    \ a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\nusing mint1000000007\
    \ = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP 1\n\n#include\
    \ <iostream>\n#include <utility>\n\n#include \"modint_base.hpp\"\n\nnamespace\
    \ algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n    static_assert(mod\
    \ >= 1);\n\n    long long val;\n\n    constexpr void normalize() {\n        if(val\
    \ < -mod or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\n\
    public:\n    constexpr Modint() : val(0) {}\n    constexpr Modint(long long val)\
    \ : val(val) {\n        normalize();\n    }\n\n    constexpr Modint operator+()\
    \ const { return Modint(*this); }\n    constexpr Modint operator-() const {\n\
    \        if(val == 0) Modint();\n        Modint res = *this;\n        res.val\
    \ = mod - res.val;\n        return res;\n    }\n    constexpr Modint &operator++()\
    \ {\n        val++;\n        if(val == mod) val = 0;\n        return *this;\n\
    \    }\n    constexpr Modint &operator--() {\n        if(val == 0) val = mod;\n\
    \        val--;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n     \
    \   val = val * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend\
    \ constexpr bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val\
    \ == rhs.val; }\n    friend constexpr Modint operator+(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) += rhs; }\n    friend constexpr Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr\
    \ Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ *= rhs; }\n    friend constexpr Modint operator/(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    constexpr long long value() const { return val; }\n   \
    \ constexpr Modint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return Modint(u);\n    }\n    constexpr Modint pow(long long\
    \ k) const {\n        if(k < 0) return inv().pow(-k);\n        Modint res = 1,\
    \ mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    friend constexpr Modint mod_inv(const Modint &a) { return a.inv();\
    \ }\n    friend constexpr Modint mod_pow(const Modint &a, long long k) { return\
    \ a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\nusing mint1000000007\
    \ = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - lib/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: lib/Math/ModularArithmetic/modint.hpp
  requiredBy: []
  timestamp: '2025-03-18 02:00:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
documentation_of: lib/Math/ModularArithmetic/modint.hpp
layout: document
title: "Modint\u69CB\u9020\u4F53"
---


## 概要

任意の自然数 $m \geq 1$ を法として，四則演算時に剰余をとる構造体．

自然数 $m$ を法とする剰余類の代表元（$0$ 以上 $m$ 未満）を値として保存し，剰余類環 $\mathbb{Z}/m\mathbb{Z}$ における加法と乗法の演算をサポートする．

$$
\begin{align}
&a + m \mathbb{Z}, \ b + m \mathbb{Z} \in \mathbb{Z} / m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z}) + (b + m \mathbb{Z}) = (a + b) + m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z})(b + m \mathbb{Z}) = a b + m \mathbb{Z} \notag\\
\end{align}
$$

また，任意の素数 $p$ を法としたときは，剰余体 $\mathbb{Z}/p\mathbb{Z}$ において $0+p\mathbb{Z}$ 以外の剰余類  $a+p\mathbb{Z} \in \mathbb{Z}/p\mathbb{Z}$ は乗法逆元 $a^{-1}$ をもち，除法の演算もサポートする．

$$
\frac{b + m \mathbb{Z}}{a + m \mathbb{Z}} = b \cdot a^{-1} + m \mathbb{Z}
$$


## 参考文献

1. "剰余類環". Wikipedia. <https://ja.wikipedia.org/wiki/剰余類環>.
1. "モジュラ逆数". Wikipedia. <https://ja.wikipedia.org/wiki/モジュラ逆数>.
1. drken. "「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜". Qiita. <https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a>.
1. "群・環・体". HatenaBlog. <https://zellij.hatenablog.com/entry/20121211/p1>.
