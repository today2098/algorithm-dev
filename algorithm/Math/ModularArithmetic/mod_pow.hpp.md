---
data:
  _extendedDependsOn: []
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
    \ <cassert>\n\nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\
    \u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(logK).\nconstexpr long long mod_pow(long\
    \ long n, long long k, int mod) {\n    assert(k >= 0);\n    assert(mod >= 1);\n\
    \    long long res = 1;\n    n %= mod;\n    while(k > 0) {\n        if(k & 1LL)\
    \ res = res * n % mod;\n        n = n * n % mod;\n        k >>= 1;\n    }\n  \
    \  return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n#include\
    \ <cassert>\n\nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\
    \u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(logK).\nconstexpr long long mod_pow(long\
    \ long n, long long k, int mod) {\n    assert(k >= 0);\n    assert(mod >= 1);\n\
    \    long long res = 1;\n    n %= mod;\n    while(k > 0) {\n        if(k & 1LL)\
    \ res = res * n % mod;\n        n = n * n % mod;\n        k >>= 1;\n    }\n  \
    \  return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/mod_pow.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
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
