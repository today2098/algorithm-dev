---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_10_A-isqrt.test.cpp
    title: test/aoj-ITP1_10_A-isqrt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/Algebra/square_root.md
    document_title: "\u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/Algebra/square_root.hpp\"\n\n\n\n/**\n * @brief\
    \ \u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\n * @docs\
    \ docs/Math/Algebra/square_root.md\n */\n\n#include <cassert>\n#include <cmath>\n\
    \nnamespace algorithm {\n\n// \u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\
    \u30F3\u6CD5\uFF09\uFF0E\nconstexpr double isqrt(double x, const double eps =\
    \ 1e-10) {\n    assert(x >= 0.0);\n    double res = 1.0;\n    while(1) {\n   \
    \     double tmp = (x / res + res) / 2;\n        if(std::abs(tmp - res) < eps)\
    \ break;\n        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_SQUARE_ROOT_HPP\n#define ALGORITHM_SQUARE_ROOT_HPP 1\n\n\
    /**\n * @brief \u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\
    \n * @docs docs/Math/Algebra/square_root.md\n */\n\n#include <cassert>\n#include\
    \ <cmath>\n\nnamespace algorithm {\n\n// \u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\uFF09\uFF0E\nconstexpr double isqrt(double x, const double\
    \ eps = 1e-10) {\n    assert(x >= 0.0);\n    double res = 1.0;\n    while(1) {\n\
    \        double tmp = (x / res + res) / 2;\n        if(std::abs(tmp - res) < eps)\
    \ break;\n        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Algebra/square_root.hpp
  requiredBy: []
  timestamp: '2024-09-17 18:35:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ITP1_10_A-isqrt.test.cpp
documentation_of: lib/Math/Algebra/square_root.hpp
layout: document
redirect_from:
- /library/lib/Math/Algebra/square_root.hpp
- /library/lib/Math/Algebra/square_root.hpp.html
title: "\u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
---
## 概要

非負の実数 $x$ に対して，非負の平方根 $\sqrt x$ を求める．

本実装では「ニュートン法」を用いており，近似解を計算する．


## 参考文献

1. 吉田 俊之ほか. "4.3 ニュートン法". 工学のための数値計算. 数理工学社, 2008, p.62-64.
1. "平方根". Wikipedia. <https://ja.wikipedia.org/wiki/平方根>.
1. "ニュートン法". Wikipedia. <https://ja.wikipedia.org/wiki/ニュートン法>.
