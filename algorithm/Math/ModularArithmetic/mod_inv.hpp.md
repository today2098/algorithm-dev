---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/Math/Combinatorics/naive_combination.hpp
    title: algorithm/Math/Combinatorics/naive_combination.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <utility>\n\nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\
    \u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\
    \u6C42\u3081\u308B\uFF0E\u89E3\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\
    \u5206\u6761\u4EF6\u306F\uFF0Ca\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log a).\nconstexpr long long mod_inv(long long a, int\
    \ mod) {\n    assert(mod >= 1);\n    long long b = mod, u = 1, v = 0;\n    while(b\
    \ != 0) {\n        long long t = a / b;\n        a -= b * t, u -= v * t;\n   \
    \     std::swap(a, b), std::swap(u, v);\n    }\n    if(u < 0) u += mod;\n    return\
    \ u;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_INV_HPP\n#define ALGORITHM_MOD_INV_HPP 1\n\n#include\
    \ <cassert>\n#include <utility>\n\nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\
    \u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\
    \u6C42\u3081\u308B\uFF0E\u89E3\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\
    \u5206\u6761\u4EF6\u306F\uFF0Ca\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(log a).\nconstexpr long long mod_inv(long long a, int\
    \ mod) {\n    assert(mod >= 1);\n    long long b = mod, u = 1, v = 0;\n    while(b\
    \ != 0) {\n        long long t = a / b;\n        a -= b * t, u -= v * t;\n   \
    \     std::swap(a, b), std::swap(u, v);\n    }\n    if(u < 0) u += mod;\n    return\
    \ u;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/mod_inv.hpp
  requiredBy:
  - algorithm/Math/Combinatorics/naive_combination.hpp
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/ModularArithmetic/mod_inv.hpp
layout: document
redirect_from:
- /library/algorithm/Math/ModularArithmetic/mod_inv.hpp
- /library/algorithm/Math/ModularArithmetic/mod_inv.hpp.html
title: algorithm/Math/ModularArithmetic/mod_inv.hpp
---
