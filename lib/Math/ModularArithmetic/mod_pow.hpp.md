---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_B-mod_pow.test.cpp
    title: test/aoj-NTL_1_B-mod_pow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/ModularArithmetic/mod_pow.md
    document_title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n/**\n *\
    \ @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\
    \n * @docs docs/Math/ModularArithmetic/mod_pow.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0En^k mod m \u3092\u6C42\u3081\u308B\uFF0EO(logK).\n\
    constexpr int mod_pow(long long n, long long k, int m) {\n    assert(k >= 0);\n\
    \    assert(m >= 1);\n    long long res = 1;\n    n %= m;\n    while(k > 0) {\n\
    \        if(k & 1LL) res = res * n % m;\n        n = n * n % m;\n        k >>=\
    \ 1;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n/**\n *\
    \ @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\
    \n * @docs docs/Math/ModularArithmetic/mod_pow.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0En^k mod m \u3092\u6C42\u3081\u308B\uFF0EO(logK).\n\
    constexpr int mod_pow(long long n, long long k, int m) {\n    assert(k >= 0);\n\
    \    assert(m >= 1);\n    long long res = 1;\n    n %= m;\n    while(k > 0) {\n\
    \        if(k & 1LL) res = res * n % m;\n        n = n * n % m;\n        k >>=\
    \ 1;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/ModularArithmetic/mod_pow.hpp
  requiredBy: []
  timestamp: '2024-09-01 18:11:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_B-mod_pow.test.cpp
documentation_of: lib/Math/ModularArithmetic/mod_pow.hpp
layout: document
redirect_from:
- /library/lib/Math/ModularArithmetic/mod_pow.hpp
- /library/lib/Math/ModularArithmetic/mod_pow.hpp.html
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
---
## 概要

整数 $n, k, m$ に対して，

$$
n^k \bmod m
$$

を求める．

本実装では「繰り返し二乗法」を用いており，計算量は $\mathcal{O}(\log k)$ である．


## 問題

- "B - n^p mod m". AtCoder Typical Contest 002. AtCoder. <https://atcoder.jp/contests/atc002/tasks/atc002_b>.
