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
    \ <cassert>\n\nnamespace algorithm {\n\n// \u7D20\u6570\u5224\u5B9A\uFF0EO(\u221A\
    N).\ntemplate <typename Type>\nconstexpr bool is_prime(Type n) {\n    assert(n\
    \ >= 0);\n    if(n < 2) return false;\n    if(n == 2) return true;\n    if(n %\
    \ 2 == 0) return false;\n    for(Type p = 3; p * p <= n; p += 2) {\n        if(n\
    \ % p == 0) return false;\n    }\n    return true;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_IS_PRIME_HPP\n#define ALGORITHM_IS_PRIME_HPP 1\n\n#include\
    \ <cassert>\n\nnamespace algorithm {\n\n// \u7D20\u6570\u5224\u5B9A\uFF0EO(\u221A\
    N).\ntemplate <typename Type>\nconstexpr bool is_prime(Type n) {\n    assert(n\
    \ >= 0);\n    if(n < 2) return false;\n    if(n == 2) return true;\n    if(n %\
    \ 2 == 0) return false;\n    for(Type p = 3; p * p <= n; p += 2) {\n        if(n\
    \ % p == 0) return false;\n    }\n    return true;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/is_prime.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_1_C-is_prime.test.cpp
documentation_of: algorithm/Math/NumberTheory/is_prime.hpp
layout: document
redirect_from:
- /library/algorithm/Math/NumberTheory/is_prime.hpp
- /library/algorithm/Math/NumberTheory/is_prime.hpp.html
title: algorithm/Math/NumberTheory/is_prime.hpp
---
