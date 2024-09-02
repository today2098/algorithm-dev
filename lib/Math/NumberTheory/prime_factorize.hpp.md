---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_A-prime_factorize.test.cpp
    title: test/aoj-NTL_1_A-prime_factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/prime_factorize.md
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"lib/Math/NumberTheory/prime_factorize.hpp\"\n\n\n\n/**\n\
    \ * @brief \u7D20\u56E0\u6570\u5206\u89E3\n * @docs docs/Math/NumberTheory/prime_factorize.md\n\
    \ */\n\n#include <cassert>\n#include <map>\n\nnamespace algorithm {\n\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <typename Type>\nstd::map<Type,\
    \ int> prime_factorize(Type n) {\n    assert(n >= 0);\n    std::map<Type, int>\
    \ res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\
    \u6570p\u306E\u500B\u6570).\n    while(n % 2 == 0) res[2]++, n /= 2;\n    for(Type\
    \ p = 3; p * p <= n; p += 2) {\n        while(n % p == 0) res[p]++, n /= p;\n\
    \    }\n    if(n > 1) res[n] = 1;\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_PRIME_FACTORIZE_HPP\n#define ALGORITHM_PRIME_FACTORIZE_HPP\
    \ 1\n\n/**\n * @brief \u7D20\u56E0\u6570\u5206\u89E3\n * @docs docs/Math/NumberTheory/prime_factorize.md\n\
    \ */\n\n#include <cassert>\n#include <map>\n\nnamespace algorithm {\n\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <typename Type>\nstd::map<Type,\
    \ int> prime_factorize(Type n) {\n    assert(n >= 0);\n    std::map<Type, int>\
    \ res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\
    \u6570p\u306E\u500B\u6570).\n    while(n % 2 == 0) res[2]++, n /= 2;\n    for(Type\
    \ p = 3; p * p <= n; p += 2) {\n        while(n % p == 0) res[p]++, n /= p;\n\
    \    }\n    if(n > 1) res[n] = 1;\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/NumberTheory/prime_factorize.hpp
  requiredBy: []
  timestamp: '2024-09-02 23:37:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_A-prime_factorize.test.cpp
documentation_of: lib/Math/NumberTheory/prime_factorize.hpp
layout: document
redirect_from:
- /library/lib/Math/NumberTheory/prime_factorize.hpp
- /library/lib/Math/NumberTheory/prime_factorize.hpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---
## 概要

自然数 $n$ に対して素因数分解を行う．

本実装では「試し割り法 (trial division)」を利用しており，計算量は $\mathcal{O}(\sqrt n)$ となる．


## 参考文献

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
