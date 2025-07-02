---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/nth_root.hpp
    title: algorithm/Math/Algebra/nth_root.hpp
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
  bundledCode: "#line 1 \"algorithm/Math/Algebra/power.hpp\"\n\n\n\n#include <cassert>\n\
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
  path: algorithm/Math/Algebra/power.hpp
  requiredBy:
  - algorithm/Math/Algebra/nth_root.hpp
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_10_D-nth_root.test.cpp
  - verify/aoj-ITP1_10_D-nth_root.test.cpp
documentation_of: algorithm/Math/Algebra/power.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Algebra/power.hpp
- /library/algorithm/Math/Algebra/power.hpp.html
title: algorithm/Math/Algebra/power.hpp
---
