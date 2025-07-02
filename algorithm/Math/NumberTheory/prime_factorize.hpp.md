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
    #include <cassert>\n#include <map>\n\nnamespace algorithm {\n\n// \u7D20\u56E0\
    \u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <typename Type>\nstd::map<Type,\
    \ int> prime_factorize(Type n) {\n    assert(n >= 0);\n    std::map<Type, int>\
    \ res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\
    \u6570p\u306E\u500B\u6570).\n    for(; n % 2 == 0; n /= 2) res[2]++;\n    for(Type\
    \ p = 3; p * p <= n; p += 2) {\n        for(; n % p == 0; n /= p) res[p]++;\n\
    \    }\n    if(n > 1) res[n] = 1;\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_PRIME_FACTORIZE_HPP\n#define ALGORITHM_PRIME_FACTORIZE_HPP\
    \ 1\n\n#include <cassert>\n#include <map>\n\nnamespace algorithm {\n\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\uFF0EO(\u221AN).\ntemplate <typename Type>\nstd::map<Type,\
    \ int> prime_factorize(Type n) {\n    assert(n >= 0);\n    std::map<Type, int>\
    \ res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\u56E0\
    \u6570p\u306E\u500B\u6570).\n    for(; n % 2 == 0; n /= 2) res[2]++;\n    for(Type\
    \ p = 3; p * p <= n; p += 2) {\n        for(; n % p == 0; n /= p) res[p]++;\n\
    \    }\n    if(n > 1) res[n] = 1;\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/prime_factorize.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-NTL_1_A-prime_factorize.test.cpp
documentation_of: algorithm/Math/NumberTheory/prime_factorize.hpp
layout: document
redirect_from:
- /library/algorithm/Math/NumberTheory/prime_factorize.hpp
- /library/algorithm/Math/NumberTheory/prime_factorize.hpp.html
title: algorithm/Math/NumberTheory/prime_factorize.hpp
---
