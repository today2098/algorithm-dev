---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_10_A-isqrt.test.cpp
    title: verify/aoj-ITP1_10_A-isqrt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Algebra/square_root.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <cmath>\n\nnamespace algorithm {\n\n// \u5E73\u65B9\u6839\
    \uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0E\nconstexpr double sqrt(double\
    \ x, double eps = 1e-10) {\n    assert(x >= 0.0);\n    double res = 1.0;\n   \
    \ while(true) {\n        double tmp = (x / res + res) / 2;\n        if(std::abs(tmp\
    \ - res) < eps) break;\n        res = tmp;\n    }\n    return res;\n}\n\n}  //\
    \ namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SQUARE_ROOT_HPP\n#define ALGORITHM_SQUARE_ROOT_HPP 1\n\n\
    #include <cassert>\n#include <cmath>\n\nnamespace algorithm {\n\n// \u5E73\u65B9\
    \u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0E\nconstexpr double\
    \ sqrt(double x, double eps = 1e-10) {\n    assert(x >= 0.0);\n    double res\
    \ = 1.0;\n    while(true) {\n        double tmp = (x / res + res) / 2;\n     \
    \   if(std::abs(tmp - res) < eps) break;\n        res = tmp;\n    }\n    return\
    \ res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Algebra/square_root.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_10_A-isqrt.test.cpp
documentation_of: algorithm/Math/Algebra/square_root.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Algebra/square_root.hpp
- /library/algorithm/Math/Algebra/square_root.hpp.html
title: algorithm/Math/Algebra/square_root.hpp
---
