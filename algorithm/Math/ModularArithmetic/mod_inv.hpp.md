---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: algorithm/Math/ModularArithmetic/modulo.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/Math/Combinatorics/naive_combination.hpp
    title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B"
  - icon: ':warning:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_B-mod_pow.test.cpp
    title: verify/aoj-NTL_1_B-mod_pow.test.cpp
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
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n#include <utility>\n\n#line\
    \ 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
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
    \n\n"
  code: "#ifndef ALGORITHM_MOD_INV_HPP\n#define ALGORITHM_MOD_INV_HPP 1\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n#include <utility>\n\n#include\
    \ \"modulo.hpp\"\n\nnamespace algorithm {\n\nnamespace internal {\n\n// return\
    \ pair of (x, g) s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.\nconstexpr std::pair<std::uint32_t,\
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
    \n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/modulo.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/mod_inv.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/Combinatorics/naive_combination.hpp
  timestamp: '2025-08-31 07:47:07+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/aoj-NTL_1_B-mod_pow.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/mod_inv.hpp
layout: document
title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
---


## 概要

法 $m \in \mathbb{N}$ における整数 $a$ のモジュラ逆数 (modular multiplicative inverse)，つまり次の条件を満たす $x$ を求める．

$$
ax \equiv 1 \pmod m, \ 0 \leq x < m.
$$

この解が存在する必要十分条件は，$a$ と $m$ が互いに素であること．

アルゴリズムの計算量は $\mathcal{O}(\log m)$ である．

### アルゴリズムの説明

#### 解の存在条件

剰余類環 $\mathbb{Z}/m\mathbb{Z}$ において，元 $[a]$ の乗法逆元 $[x]$ を求めることは，次の合同方程式を解くことと同じ．

$$
ax \equiv 1 \pmod m, \ 0 \leq a < m.
$$

ここで適当な整数 $q$ を用いると，$ax - qm = 1$ が成り立つ．

これから拡張ユークリッドの互除法により，解 $x$ が存在する必要十分条件は $\gcd(a,m) = 1$ であることとわかる．

#### 解の構成

次のような形の合同式を考える．

$$
s \equiv t \cdot a \pmod m, \ 0 \leq a < m.
$$

$m=1$ のとき，$\mathbb{Z}/1 \mathbb{Z}$ は零環であるため，$0$ が逆元となる．

$m>1$ かつ $a=0$ のとき，$0 \cdot x \not\equiv 1$ より，解なし．

以降，$m>1, \ a>0$ とする．

このとき，明らかに

$$
m \equiv 0 \cdot a, \quad a \equiv 1 \cdot a
$$

が成り立つ．

この2式から左辺について剰余をとると新たな合同式を得る．
この操作をユークリッドの互除法のように繰り返す．

$$
\begin{align}
&s_0 \equiv t_0 \cdot a \quad \left( s_0 = m, \ t_0 = 0 \right), \notag \\
&s_1 \equiv t_1 \cdot a \quad \left( s_1 = a, \ t_1 = 1 \right), \notag \\
&s_2 \equiv t_2 \cdot a \quad \left( s_2 = s_0 - \left\lfloor \frac{s_0}{s_1} \right\rfloor \cdot s_1, \ t_2 = t_0 - \left\lfloor \frac{s_0}{s_1} \right\rfloor \cdot t_1 \right), \notag \\
&\cdots \notag \\
&s_i \equiv t_i \cdot a \quad \left( s_i = s_{i-2} - \left\lfloor \frac{s_{i-2}}{s_{i-1}} \right\rfloor \cdot s_{i-1}, \ t_i = t_{i-2} - \left\lfloor \frac{s_{i-2}}{s_{i-1}} \right\rfloor \cdot t_{i-1} \right), \notag \\
&\cdots \notag \\
&s_n \equiv t_n \cdot a \quad \left( s_n = s_{n-2} - \left\lfloor \frac{s_{n-2}}{s_{n-1}} \right\rfloor \cdot s_{n-1}, \ t_n = t_{n-2} - \left\lfloor \frac{s_{n-2}}{s_{n-1}} \right\rfloor \cdot t_{n-1} \right). \notag \\
\end{align}
$$

このとき $s_n = \gcd(a,m)$ となる $n$ が現れる．

$\gcd(a,m) = 1$ のとき，$t_n \cdot a \equiv s_n = 1$ より，$t_n \mod m$ が求めたい解となる．

#### 計算過程における値の範囲

$s_i \cdot \lvert t_{i+1} \rvert + s_{i+1} \cdot \lvert t_i \rvert \leq m$ となることを示す．

$i=0$ のとき，$s_0 \cdot \lvert t_1 \rvert + s_1 \cdot \lvert t_0 \rvert = m \cdot 1 + a \cdot 0 = m$ である．

次に $s_i \cdot \lvert t_{i+1} \rvert + s_{i+1} \cdot \lvert t_i \rvert \leq m$ が成り立つと仮定する．
このとき，

$$
\begin{align}
s_{i+1} \cdot \lvert t_{i+2} \rvert + s_{i+2} \cdot \lvert t_{i+1} \rvert &= s_{i+1} \cdot \left\lvert t_i - \left\lfloor \frac{s_i}{s_{i+1}} \right\rfloor \cdot t_{i+1} \right\rvert + \left( s_i- \left\lfloor \frac{s_i}{s_{i+1}} \right\rfloor \cdot s_{i+1} \right) \cdot \lvert t_{i+1} \rvert \notag \\
&\leq s_{i+1} \cdot \lvert t_i \rvert + \left\lfloor \frac{s_i}{s_{i+1}} \right\rfloor \cdot s_{i+1} \cdot \lvert t_{i+1} \rvert + s_i \cdot \lvert t_{i+1} \rvert - \left\lfloor \frac{s_i}{s_{i+1}} \right\rfloor \cdot s_{i+1} \cdot \lvert t_{i+1} \rvert \notag \\
&= s_i \cdot \lvert t_{i+1} \rvert + s_{i+1} \cdot \lvert t_i \rvert \notag \\
&\leq m \notag \\
\end{align}
$$

となる．

よって，帰納法より，$s_i \cdot \lvert t_{i+1} \rvert + s_{i+1} \cdot \lvert t_i \rvert \leq m$ が成り立つ．

また，

$$
\begin{align}
&\left\lvert \left\lfloor \frac{s_i}{s_{i+1}} \right\rfloor \cdot t_{i+1} \right\rvert \leq s_i \cdot \lvert t_{i+1} \rvert \leq m, \notag \\
&\left\lvert t_i - \left\lfloor \frac{s_i}{s_{i+1}} \right\rfloor \cdot t_{i+1} \right\rvert \leq \lvert t_i \rvert + s_i \cdot \lvert t_{i+1} \rvert \leq m \notag \\
\end{align}
$$

であるから，計算過程において値が $m$ を超えることなく，オーバーフローしないことがわかる．

#### 解の範囲

$s_{i-1} > s_i, \ s_n = \gcd(a,m), \ \gcd(a,m) \mid s_i$ であるから，適当な整数 $q > 1$ を用いて，$s_{n-1} = q \cdot \gcd(a,m)$ と表せる．

このとき，不等式 $s_i \cdot \lvert t_{i+1} \rvert + s_{i+1} \cdot \lvert t_i \rvert \leq m$ より，

$$
\begin{align}
&s_{n-1} \cdot \lvert t_{n} \rvert + s_n \cdot \lvert t_{n-1} \rvert \leq m \notag \\
\Rightarrow \quad &s_{n-1} \cdot \lvert t_{n} \rvert \leq m \notag \\
\Leftrightarrow \quad &q \cdot \gcd(a,m) \cdot \lvert t_{n} \rvert \leq m \notag \\
\Rightarrow \quad &\gcd(a,m) \cdot \lvert t_{n} \rvert < m \quad (\because \ q > 1) \notag \\
\Leftrightarrow \quad &\lvert t_{n} \rvert < \frac{m}{\gcd(a,m)} \notag \\
\end{align}
$$

が成り立つ．

よって，得られる解 $t_n$ は $\lvert t_n \rvert < m / \gcd(a,m)$ を満たす．

#### 計算量の解析

$s_{i+2} < s_i / 2$ なので，繰り返し回数は高々 $2 \log a$ 回である．
したがって，計算量は $\mathcal{O}(\log a)$ となる．

## 参考

1. "剰余類環". Wikipedia. <https://ja.wikipedia.org/wiki/剰余類環>.
1. "モジュラ逆数". Wikipedia. <https://ja.wikipedia.org/wiki/モジュラ逆数>.
1. "零環". Wikipedia. <https://ja.wikipedia.org/wiki/零環>.
1. ei1333. "mod1における逆元". HatenaBlog. <https://ei1333.hateblo.jp/entry/2021/08/18/225417>.
1. noshi91. "mod 逆元と拡張ユークリッド互除法". HatenaBlog. <https://noshi91.hatenablog.com/entry/2019/10/18/182935>.
1. rsk0312. "ACL の math の解説をするよ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2021/01/18/065720#internalinv_gcd>.

## 問題

- "mod の逆元 (paizaランク C 相当)". paizaラーニング. <https://paiza.jp/works/mondai/euclidean_primer/euclidean_primer__mod_inverse>.
