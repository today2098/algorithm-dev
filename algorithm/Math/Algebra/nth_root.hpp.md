---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/power.hpp
    title: algorithm/Math/Algebra/power.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_10_D-nth_root.test.cpp
    title: verify/aoj-ITP1_10_D-nth_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Algebra/nth_root.hpp\"\n\n\n\n#include <cassert>\n\
    #include <cmath>\n\n#line 1 \"algorithm/Math/Algebra/power.hpp\"\n\n\n\n#line\
    \ 5 \"algorithm/Math/Algebra/power.hpp\"\n\nnamespace algorithm {\n\n// \u7E70\
    \u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF0EO(logK).\ntemplate <typename Type>\n\
    constexpr Type pow(Type n, long long k) {\n    assert(k >= 0);\n    Type res =\
    \ 1;\n    while(k > 0) {\n        if(k & 1LL) res *= n;\n        n *= n;\n   \
    \     k >>= 1;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\n#line\
    \ 8 \"algorithm/Math/Algebra/nth_root.hpp\"\n\nnamespace algorithm {\n\n// \u7D2F\
    \u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0Ex\u306En\u4E57\
    \u6839\u3092\u6C42\u3081\u308B\uFF0E\nconstexpr double nth_root(double x, long\
    \ long n, double eps = 1e-10) {\n    assert(x >= 0.0);\n    assert(n >= 1);\n\
    \    double res = 1.0;\n    while(true) {\n        double tmp = (x / pow(res,\
    \ n - 1) + (n - 1) * res) / n;\n        if(std::abs(tmp - res) < eps) break;\n\
    \        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\
    \n"
  code: "#ifndef ALGORITHM_NTH_ROOT_HPP\n#define ALGORITHM_NTH_ROOT_HPP 1\n\n#include\
    \ <cassert>\n#include <cmath>\n\n#include \"power.hpp\"\n\nnamespace algorithm\
    \ {\n\n// \u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0E\
    x\u306En\u4E57\u6839\u3092\u6C42\u3081\u308B\uFF0E\nconstexpr double nth_root(double\
    \ x, long long n, double eps = 1e-10) {\n    assert(x >= 0.0);\n    assert(n >=\
    \ 1);\n    double res = 1.0;\n    while(true) {\n        double tmp = (x / pow(res,\
    \ n - 1) + (n - 1) * res) / n;\n        if(std::abs(tmp - res) < eps) break;\n\
    \        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn:
  - algorithm/Math/Algebra/power.hpp
  isVerificationFile: false
  path: algorithm/Math/Algebra/nth_root.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_10_D-nth_root.test.cpp
documentation_of: algorithm/Math/Algebra/nth_root.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Algebra/nth_root.hpp
- /library/algorithm/Math/Algebra/nth_root.hpp.html
title: algorithm/Math/Algebra/nth_root.hpp
---
