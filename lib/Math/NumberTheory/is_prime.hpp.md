---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ALDS1_1_C-is_prime.test.cpp
    title: test/aoj-ALDS1_1_C-is_prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/is_prime.md
    document_title: "\u7D20\u6570\u5224\u5B9A"
    links: []
  bundledCode: "#line 1 \"lib/Math/NumberTheory/is_prime.hpp\"\n\n\n\n/**\n * @brief\
    \ \u7D20\u6570\u5224\u5B9A\n * @docs docs/Math/NumberTheory/is_prime.md\n */\n\
    \n#include <cassert>\n\nnamespace algorithm {\n\n// \u7D20\u6570\u5224\u5B9A\uFF0E\
    O(\u221AN).\ntemplate <typename Type>\nconstexpr bool is_prime(Type n) {\n   \
    \ assert(n >= 0);\n    if(n < 2) return false;\n    if(n == 2) return true;\n\
    \    if(n % 2 == 0) return false;\n    for(Type p = 3; p * p <= n; p += 2) {\n\
    \        if(n % p == 0) return false;\n    }\n    return true;\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_IS_PRIME_HPP\n#define ALGORITHM_IS_PRIME_HPP 1\n\n/**\n\
    \ * @brief \u7D20\u6570\u5224\u5B9A\n * @docs docs/Math/NumberTheory/is_prime.md\n\
    \ */\n\n#include <cassert>\n\nnamespace algorithm {\n\n// \u7D20\u6570\u5224\u5B9A\
    \uFF0EO(\u221AN).\ntemplate <typename Type>\nconstexpr bool is_prime(Type n) {\n\
    \    assert(n >= 0);\n    if(n < 2) return false;\n    if(n == 2) return true;\n\
    \    if(n % 2 == 0) return false;\n    for(Type p = 3; p * p <= n; p += 2) {\n\
    \        if(n % p == 0) return false;\n    }\n    return true;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/NumberTheory/is_prime.hpp
  requiredBy: []
  timestamp: '2024-09-02 01:46:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ALDS1_1_C-is_prime.test.cpp
documentation_of: lib/Math/NumberTheory/is_prime.hpp
layout: document
redirect_from:
- /library/lib/Math/NumberTheory/is_prime.hpp
- /library/lib/Math/NumberTheory/is_prime.hpp.html
title: "\u7D20\u6570\u5224\u5B9A"
---
## 概要

自然数 $n$ に対して素数判定を行う．

本実装では「試し割り法 (trial division)」を利用しており，計算量は $\mathcal{O}(\sqrt n)$ となる．


## 参考文献

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
