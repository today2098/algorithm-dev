---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_A-prime_factorize.test.cpp
    title: verify/aoj-NTL_1_A-prime_factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/prime_factorize.hpp\"\n\n\n\n\
    #include <cassert>\n#include <concepts>\n#include <map>\n\nnamespace algorithm\
    \ {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <std::integral\
    \ Type>\nstd::map<Type, int> prime_factorize(Type n) {\n    assert(n >= 0);\n\
    \    if(n == 0) return std::map<Type, int>();\n    std::map<Type, int> res;  //\
    \ res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\u6570\
    p\u306E\u500B\u6570).\n    unsigned long long m = n;\n    for(; m % 2 == 0; m\
    \ /= 2) ++res[2];\n    for(unsigned long long p = 3; p * p <= m; p += 2) {\n \
    \       for(; m % p == 0; m /= p) ++res[p];\n    }\n    if(m > 1) res[m] = 1;\n\
    \    return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PRIME_FACTORIZE_HPP\n#define ALGORITHM_PRIME_FACTORIZE_HPP\
    \ 1\n\n#include <cassert>\n#include <concepts>\n#include <map>\n\nnamespace algorithm\
    \ {\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <std::integral\
    \ Type>\nstd::map<Type, int> prime_factorize(Type n) {\n    assert(n >= 0);\n\
    \    if(n == 0) return std::map<Type, int>();\n    std::map<Type, int> res;  //\
    \ res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\u6570\
    p\u306E\u500B\u6570).\n    unsigned long long m = n;\n    for(; m % 2 == 0; m\
    \ /= 2) ++res[2];\n    for(unsigned long long p = 3; p * p <= m; p += 2) {\n \
    \       for(; m % p == 0; m /= p) ++res[p];\n    }\n    if(m > 1) res[m] = 1;\n\
    \    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/prime_factorize.hpp
  requiredBy: []
  timestamp: '2025-07-22 02:54:24+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-NTL_1_A-prime_factorize.test.cpp
documentation_of: algorithm/Math/NumberTheory/prime_factorize.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---


## 概要

与えられる自然数 $n$ に対して素因数分解を行う．

本実装では「試し割り法 (trial division)」を用いており，計算量は $\mathcal{O}(\sqrt n)$ となる．


## 参考

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
