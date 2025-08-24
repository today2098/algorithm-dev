---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_3_D-divisors.test.cpp
    title: verify/aoj-ITP1_3_D-divisors.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/divisors.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n#include\
    \ <map>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D04\u6570\u5217\u6319\
    \uFF0EO(\u221An).\ntemplate <std::integral Type>\nstd::vector<Type> divisors(Type\
    \ n) {\n    assert(n > 0);\n    std::vector<Type> res;  // res[]:=(\u81EA\u7136\
    \u6570n\u306E\u7D04\u6570\u306E\u30EA\u30B9\u30C8).\n    for(std::uint64_t p =\
    \ 1, m = n; p * p <= m; ++p) {\n        if(m % p != 0) continue;\n        res.push_back(p);\n\
    \        auto q = m / p;\n        if(q != p) res.push_back(q);\n    }\n    res.shrink_to_fit();\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n// \u9AD8\u901F\
    \u7D04\u6570\u5217\u6319\uFF0E\ntemplate <typename Type>\nstd::vector<Type> divisors(const\
    \ std::map<Type, int> &pf) {\n    std::vector<Type> res({1});\n    for(const auto\
    \ &[p, cnt] : pf) {\n        const int sz = res.size();\n        Type b = 1;\n\
    \        for(int i = 0; i < cnt; ++i) {\n            b *= p;\n            for(int\
    \ j = 0; j < sz; ++j) res.push_back(res[j] * b);\n        }\n    }\n    res.shrink_to_fit();\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DIVISORS_HPP\n#define ALGORITHM_DIVISORS_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n#include\
    \ <map>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D04\u6570\u5217\u6319\
    \uFF0EO(\u221An).\ntemplate <std::integral Type>\nstd::vector<Type> divisors(Type\
    \ n) {\n    assert(n > 0);\n    std::vector<Type> res;  // res[]:=(\u81EA\u7136\
    \u6570n\u306E\u7D04\u6570\u306E\u30EA\u30B9\u30C8).\n    for(std::uint64_t p =\
    \ 1, m = n; p * p <= m; ++p) {\n        if(m % p != 0) continue;\n        res.push_back(p);\n\
    \        auto q = m / p;\n        if(q != p) res.push_back(q);\n    }\n    res.shrink_to_fit();\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n// \u9AD8\u901F\
    \u7D04\u6570\u5217\u6319\uFF0E\ntemplate <typename Type>\nstd::vector<Type> divisors(const\
    \ std::map<Type, int> &pf) {\n    std::vector<Type> res({1});\n    for(const auto\
    \ &[p, cnt] : pf) {\n        const int sz = res.size();\n        Type b = 1;\n\
    \        for(int i = 0; i < cnt; ++i) {\n            b *= p;\n            for(int\
    \ j = 0; j < sz; ++j) res.push_back(res[j] * b);\n        }\n    }\n    res.shrink_to_fit();\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/divisors.hpp
  requiredBy: []
  timestamp: '2025-08-12 15:28:11+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_3_D-divisors.test.cpp
documentation_of: algorithm/Math/NumberTheory/divisors.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---


## 概要

与えられる自然数 $n$ の約数を列挙する．

本実装では「試し割り法 (trial division)」を用いており，計算量は $\mathcal{O}(\sqrt n)$ となる．

## 参考

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
