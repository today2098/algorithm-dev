---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/nth_root.hpp
    title: "\u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_10_D-nth_root.test.cpp
    title: verify/aoj-ITP1_10_D-nth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_10_D-nth_root.test.cpp
    title: verify/aoj-ITP1_10_D-nth_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Math/Algebra/power.hpp\"\n\n\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF0E\
    O(logK).\ntemplate <typename Type>\nconstexpr Type pow(Type n, long long k) {\n\
    \    assert(k >= 0);\n    Type res = 1;\n    while(k > 0) {\n        if(k & 1LL)\
    \ res *= n;\n        n *= n;\n        k >>= 1;\n    }\n    return res;\n}\n\n\
    }  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_POWER_HPP\n#define ALGORITHM_POWER_HPP 1\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF0E\
    O(logK).\ntemplate <typename Type>\nconstexpr Type pow(Type n, long long k) {\n\
    \    assert(k >= 0);\n    Type res = 1;\n    while(k > 0) {\n        if(k & 1LL)\
    \ res *= n;\n        n *= n;\n        k >>= 1;\n    }\n    return res;\n}\n\n\
    }  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Algebra/power.hpp
  requiredBy:
  - lib/Math/Algebra/nth_root.hpp
  timestamp: '2025-04-06 12:44:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_10_D-nth_root.test.cpp
  - verify/aoj-ITP1_10_D-nth_root.test.cpp
documentation_of: lib/Math/Algebra/power.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
---


## 概要

$n$ を $k$ 乗した値 $n^k$ を求める（ただし，$k$ は非負整数）．

本実装では「繰り返し二乗法」を用いており，計算量は $\mathcal{O}(\log k)$ となる．


## 参考文献

1. "冪乗". Wikipedia. <https://ja.wikipedia.org/wiki/冪乗>.
