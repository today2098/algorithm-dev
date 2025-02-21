---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: lib/Math/Combinatorics/naive_combination.hpp
    title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <utility>\n\nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\
    \u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\
    \u6C42\u3081\u308B\uFF0E\u89E3\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\
    \u5206\u6761\u4EF6\u306F\uFF0Ca\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log a).\nconstexpr long long mod_inv(long long a, int\
    \ mod) {\n    assert(mod >= 1);\n    long long b = mod, u = 1, v = 0;\n    while(b\
    \ != 0) {\n        long long t = a / b;\n        a -= b * t, u -= v * t;\n   \
    \     std::swap(a, b), std::swap(u, v);\n    }\n    if(u < 0) u += mod;\n    return\
    \ u;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_INV_HPP\n#define ALGORITHM_MOD_INV_HPP 1\n\n#include\
    \ <cassert>\n#include <utility>\n\nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\
    \u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\
    \u6C42\u3081\u308B\uFF0E\u89E3\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\
    \u5206\u6761\u4EF6\u306F\uFF0Ca\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log a).\nconstexpr long long mod_inv(long long a, int\
    \ mod) {\n    assert(mod >= 1);\n    long long b = mod, u = 1, v = 0;\n    while(b\
    \ != 0) {\n        long long t = a / b;\n        a -= b * t, u -= v * t;\n   \
    \     std::swap(a, b), std::swap(u, v);\n    }\n    if(u < 0) u += mod;\n    return\
    \ u;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/ModularArithmetic/mod_inv.hpp
  requiredBy:
  - lib/Math/Combinatorics/naive_combination.hpp
  timestamp: '2025-02-22 06:53:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/ModularArithmetic/mod_inv.hpp
layout: document
title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
---


## 概要

法 $m > 1$ における整数 $a$ のモジュラ逆数 (modular multiplicative inverse) ，つまり

$$
a^{-1} \bmod m
$$

を求める．
解が存在する必要十分条件は，$a$ と $m$ が互いに素であること． 

アルゴリズムの計算量は $\mathcal{O}(\log a)$ ．


### アルゴリズムの説明

法 $m$ における整数 $a$ の逆元（モジュラ逆数）を求めることは，合同方程式

$$
a x \equiv 1 \pmod m
$$

を解くことと同じ．
ここで適当な整数 $q$ を用いると

$$
a x - 1 = q m
$$

が成り立ち，整理すると

$$
a x - q m = 1
$$

となる．

これから拡張ユークリッドの互除法により，解 $x$ が存在する必要十分条件は $\gcd(a,m) = 1$ であることと分かる．
以降 $a$ と $m$ は互いに素であるものとする．

次に以下のような形の合同式を考える．

$$
s \equiv t a \pmod m
$$

明らかに次の2式が成り立つ．

$$
\begin{align}
m &\equiv 0 \cdot a, \tag{1}\\
a &\equiv 1 \cdot a \tag{2}\\
\end{align}
$$

この2式を足し引きし，左辺について剰余をとるような新たな合同式を得る．
この操作をユークリッドの互除法のように繰り返す．


$$
\begin{align}
s_0 &\equiv t_0 \cdot a \ &\left( s_0 = M - \left\lfloor \frac{M}{a} \right\rfloor \cdot a, \ t_0 = 0 - \left\lfloor \frac{M}{a} \right\rfloor \cdot 1 \right) \ &\left( (1)-(2) \times \left\lfloor \frac{M}{a} \right\rfloor \right), \tag{3}\\
s_1 &\equiv t_1 \cdot a \ &\left( s_1 = a - \left\lfloor \frac{a}{s_0} \right\rfloor \cdot s_0, \ t_1 = 1 - \left\lfloor \frac{a}{s_0} \right\rfloor \cdot t_0 \right) \ &\left( (2)-(3) \times \left\lfloor \frac{a}{s_0} \right\rfloor \right), \tag{4}\\
s_2 &\equiv t_2 \cdot a \ &\left( s_2 = s_0 - \left\lfloor \frac{s_0}{s_1} \right\rfloor \cdot s_1, \ t_2 = t_0 - \left\lfloor \frac{s_0}{s_1} \right\rfloor \cdot t_1 \right) \ &\left( (3)-(4) \times \left\lfloor \frac{s_0}{s_1} \right\rfloor \right), \tag{5}\\
&\cdots \notag
\end{align}
$$

ここで $a$ と $m$ は互いに素であるから，必ずある $n$ 回目で値が $1$ となる $s_n$ が現れる．

$$
\begin{align}
s_n \equiv 1 \equiv t_n \cdot a \ \left( s_n = s_{n-2} - \left\lfloor \frac{s_{n-2}}{s_{n-1}} \right\rfloor \cdot s_{n-1}, \ t_n = t_{n-2} - \left\lfloor \frac{s_{n-2}}{s_{n-1}} \right\rfloor \cdot t_{n-1} \right) \tag{6}\\
\end{align}
$$

よって，求める解は $t_n$ となる．

また，操作回数も高々 $2 \log a$ 回なので，計算量は $\mathcal{O}(\log a)$ である． 


## 参考文献

1. "モジュラ逆数". Wikipedia. <https://ja.wikipedia.org/wiki/モジュラ逆数>.
1. "零環". Wikipedia. <https://ja.wikipedia.org/wiki/零環>.
1. ei1333. "mod1における逆元". HatenaBlog. <https://ei1333.hateblo.jp/entry/2021/08/18/225417>.
1. noshi91. "mod 逆元と拡張ユークリッド互除法". HatenaBlog. <https://noshi91.hatenablog.com/entry/2019/10/18/182935>.


## 問題

- "mod の逆元 (paizaランク C 相当)". paizaラーニング. <https://paiza.jp/works/mondai/euclidean_primer/euclidean_primer__mod_inverse>.
