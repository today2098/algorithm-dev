---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_1_C-is_prime.test.cpp
    title: verify/aoj-ALDS1_1_C-is_prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/is_prime.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\
    \nnamespace internal {\n\nconstexpr bool is_prime(std::uint64_t n) {\n    if(n\
    \ < 2) return false;\n    if(n == 2) return true;\n    if(n % 2 == 0) return false;\n\
    \    for(std::uint64_t p = 3; p * p <= n; p += 2) {\n        if(n % p == 0) return\
    \ false;\n    }\n    return true;\n}\n\n}  // namespace internal\n\n// \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(\u221An).\ntemplate <std::unsigned_integral Type>\nconstexpr\
    \ bool is_prime(Type n) { return internal::is_prime(n); }\n\n// \u7D20\u6570\u5224\
    \u5B9A\uFF0EO(\u221An).\ntemplate <std::signed_integral Type>\nconstexpr bool\
    \ is_prime(Type n) {\n    assert(n >= 0);\n    return internal::is_prime(n);\n\
    }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_IS_PRIME_HPP\n#define ALGORITHM_IS_PRIME_HPP 1\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\
    \nnamespace internal {\n\nconstexpr bool is_prime(std::uint64_t n) {\n    if(n\
    \ < 2) return false;\n    if(n == 2) return true;\n    if(n % 2 == 0) return false;\n\
    \    for(std::uint64_t p = 3; p * p <= n; p += 2) {\n        if(n % p == 0) return\
    \ false;\n    }\n    return true;\n}\n\n}  // namespace internal\n\n// \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(\u221An).\ntemplate <std::unsigned_integral Type>\nconstexpr\
    \ bool is_prime(Type n) { return internal::is_prime(n); }\n\n// \u7D20\u6570\u5224\
    \u5B9A\uFF0EO(\u221An).\ntemplate <std::signed_integral Type>\nconstexpr bool\
    \ is_prime(Type n) {\n    assert(n >= 0);\n    return internal::is_prime(n);\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/is_prime.hpp
  requiredBy: []
  timestamp: '2025-08-12 15:28:11+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_1_C-is_prime.test.cpp
documentation_of: algorithm/Math/NumberTheory/is_prime.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A"
---


## 概要

与えられる自然数 $n$ が素数かどうか判定する．

本実装では「試し割り法 (trial division)」を用いており，計算量は $\mathcal{O}(\sqrt n)$ となる．

## 参考

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
