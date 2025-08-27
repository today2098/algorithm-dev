---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/internal/absolute.hpp
    title: algorithm/internal/absolute.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
    title: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\
    \n\n\n\n#include <concepts>\n#include <type_traits>\n\n#line 1 \"algorithm/internal/absolute.hpp\"\
    \n\n\n\n#line 6 \"algorithm/internal/absolute.hpp\"\n\nnamespace algorithm {\n\
    \nnamespace internal {\n\n// Returns the absolute value as type Res.\ntemplate\
    \ <std::integral Res, std::unsigned_integral Type>\nconstexpr Res abs(Type n)\
    \ {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    return static_cast<Res>(n);\n\
    }\n\n// Returns the absolute value as type Res.\ntemplate <std::integral Res,\
    \ std::signed_integral Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res)\
    \ >= sizeof(Type));\n    return static_cast<Res>(std::make_unsigned_t<Type>(n\
    \ < 0 ? -n : n));\n}\n\n}  // namespace internal\n\n}  // namespace algorithm\n\
    \n\n#line 8 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\n\nnamespace\
    \ algorithm {\n\nnamespace internal {\n\ntemplate <std::integral Type>\nconstexpr\
    \ Type gcd(Type a, Type b) {\n    if(b == 0) return a;\n    return gcd(b, a %\
    \ b);\n}\n\n}  // namespace internal\n\n// Returns the greatest common divisor\
    \ (GCD) of |a| and |b|.\ntemplate <std::integral T, std::integral U>\nconstexpr\
    \ std::common_type_t<T, U> gcd(T a, U b) {\n    using ct = std::common_type_t<T,\
    \ U>;\n    using ut = std::make_unsigned_t<ct>;\n    ut ua = ::algorithm::internal::abs<ut>(a);\n\
    \    ut ub = ::algorithm::internal::abs<ut>(b);\n    return internal::gcd(ua,\
    \ ub);\n}\n\n// Returns the greatest common divisor (GCD) of all arguments.\n\
    template <std::integral Type, std::integral... Args>\nconstexpr auto gcd(Type\
    \ first, Args... args) { return gcd(first, gcd(args...)); }\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GREATEST_COMMON_DIVISOR_HPP\n#define ALGORITHM_GREATEST_COMMON_DIVISOR_HPP\
    \ 1\n\n#include <concepts>\n#include <type_traits>\n\n#include \"../../internal/absolute.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\ntemplate <std::integral Type>\n\
    constexpr Type gcd(Type a, Type b) {\n    if(b == 0) return a;\n    return gcd(b,\
    \ a % b);\n}\n\n}  // namespace internal\n\n// Returns the greatest common divisor\
    \ (GCD) of |a| and |b|.\ntemplate <std::integral T, std::integral U>\nconstexpr\
    \ std::common_type_t<T, U> gcd(T a, U b) {\n    using ct = std::common_type_t<T,\
    \ U>;\n    using ut = std::make_unsigned_t<ct>;\n    ut ua = ::algorithm::internal::abs<ut>(a);\n\
    \    ut ub = ::algorithm::internal::abs<ut>(b);\n    return internal::gcd(ua,\
    \ ub);\n}\n\n// Returns the greatest common divisor (GCD) of all arguments.\n\
    template <std::integral Type, std::integral... Args>\nconstexpr auto gcd(Type\
    \ first, Args... args) { return gcd(first, gcd(args...)); }\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/internal/absolute.hpp
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/greatest_common_divisor.hpp
  requiredBy:
  - algorithm/Math/NumberTheory/least_common_multiple.hpp
  timestamp: '2025-08-23 10:05:58+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-NTL_1_C-least_common_multiple.test.cpp
documentation_of: algorithm/Math/NumberTheory/greatest_common_divisor.hpp
layout: document
title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
---


## 概要

2つの整数 $a, b$ の最大公約数 (GCD: Greatest Common Divisor) を求める．

本実装では「ユークリッドの互除法 (Euclidean algorithm)」を用いており，計算量は $\mathcal{O}(\log(\min(a,b)))$ となる．

### アルゴリズムの説明

ユークリッドの互除法が最大公約数を求める原理とその計算量を説明する．

#### 剰余と公約数の関係

$a, b \in \mathbb{Z}, \ a \geq b > 0$ に対して，$a$ を $b$ で割ったときの商を $q$，余りを $r$ とすると，$a = qb + r$ となる．

ここで $d \in \mathbb{N}$ を $d \mid a, \ d \mid b$ を満たす数とする．
このとき，$d \mid a-qb$ となるから，$d \mid r$ が成り立つ．

逆に，$d' \in \mathbb{N}$ を $d' \mid b, \ d' \mid r$ を満たす数とすると，$d' \mid qb+r$ であるから，$d' \mid a$ が成り立つ．

よって，$a$ と $b$ の公約数全体の集合は $b$ と $r$ の公約数全体の集合に等しく，特に $\gcd(a,b)$ は $\gcd(b,r)$ に等しい．

#### ユークリッドの互除法の説明

ユークリッドの互除法は上記の性質を利用する．

$r_0, r_1 \in \mathbb{Z}, \ r_0 \geq r_1 > 0$ に対して，次のように剰余算を繰り返す．

$$
\begin{align}
&r_0 - \lfloor r_0 / r_1 \rfloor \cdot r_1 = r_2, \notag \\
&r_1 - \lfloor r_1 / r_2 \rfloor \cdot r_2 = r_3, \notag \\
&\ldots \notag \\
&r_i - \lfloor r_i / r_{i+1} \rfloor \cdot r_{i+1} = r_{i+2}, \notag \\
&\ldots \notag \\
&r_{n-1} - \lfloor r_{n-1} / r_n \rfloor \cdot r_n = 0. \notag \\
\end{align}
$$

$r_{i+2} < r_{i+1} \leq r_i$ であるから，必ず $r_{n+1} = 0$ となる $n$ が存在し，$r_n$ が求める最大公約数となる．

#### 計算量の導出

先の式 $r_i - \lfloor r_i / r_{i+1} \rfloor \cdot r_{i+1} = r_{i+2}$ において，$r_{i+2} < r_i / 2$ である．

したがって，繰り返しは高々 $2 \log b$ 回であり，計算量は $\mathcal{O}(\log b)$ となる．

## 参考

1. H.H. シルヴァーマン. "第5章 割り切れる関係 —— 整除性と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.29-33.
1. "最大公約数". Wikipedia. <https://ja.wikipedia.org/wiki/最大公約数>.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "ユークリッドの互除法の証明と不定方程式". 高校数学の美しい物語. <https://manabitimes.jp/math/672>.
