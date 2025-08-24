---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_B-mod_pow.test.cpp
    title: verify/aoj-NTL_1_B-mod_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n#include\
    \ <cassert>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n\
    #line 5 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\nconstexpr long long mod_inv(long long a, int mod) {\n    assert(mod >=\
    \ 1);\n    long long b = mod, u = 1, v = 0;\n    while(b != 0) {\n        long\
    \ long t = a / b;\n        a -= b * t, u -= v * t;\n        std::swap(a, b), std::swap(u,\
    \ v);\n    }\n    if(u < 0) u += mod;\n    return u;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 7 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\nnamespace algorithm\
    \ {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\
    \uFF0EO(log k).\nconstexpr long long mod_pow(long long n, long long k, int mod)\
    \ {\n    assert(mod >= 1);\n    if(n < -mod or mod <= n) n %= mod;\n    if(n <\
    \ 0) n += mod;\n    if(k < 0) n = mod_inv(n, mod), k = -k;\n    long long res\
    \ = 1;\n    for(; k > 0; k >>= 1) {\n        if(k & 1LL) res = res * n % mod;\n\
    \        n = n * n % mod;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n#include\
    \ <cassert>\n\n#include \"mod_inv.hpp\"\n\nnamespace algorithm {\n\n// \u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(log k).\nconstexpr\
    \ long long mod_pow(long long n, long long k, int mod) {\n    assert(mod >= 1);\n\
    \    if(n < -mod or mod <= n) n %= mod;\n    if(n < 0) n += mod;\n    if(k < 0)\
    \ n = mod_inv(n, mod), k = -k;\n    long long res = 1;\n    for(; k > 0; k >>=\
    \ 1) {\n        if(k & 1LL) res = res * n % mod;\n        n = n * n % mod;\n \
    \   }\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/mod_pow.hpp
  requiredBy: []
  timestamp: '2025-08-10 09:02:12+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-NTL_1_B-mod_pow.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/mod_pow.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
---


## 概要

自然数 $n, k, m$ に対して，

$$
n^k \bmod m
$$

を求める．

本実装では「繰り返し二乗法」を用いており，計算量は $\mathcal{O}(\log k)$ である．


## 問題

- "B - n^p mod m". AtCoder Typical Contest 002. AtCoder. <https://atcoder.jp/contests/atc002/tasks/atc002_b>.
