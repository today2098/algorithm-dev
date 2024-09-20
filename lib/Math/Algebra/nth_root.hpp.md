---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/power.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_10_D-nth_root.test.cpp
    title: test/aoj-ITP1_10_D-nth_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/Algebra/nth_root.md
    document_title: "\u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/Algebra/nth_root.hpp\"\n\n\n\n/**\n * @brief \u7D2F\
    \u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\n * @docs docs/Math/Algebra/nth_root.md\n\
    \ */\n\n#include <cassert>\n#include <cmath>\n\n#line 1 \"lib/Math/Algebra/power.hpp\"\
    \n\n\n\n/**\n * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n * @docs docs/Math/Algebra/power.md\n\
    \ */\n\n#line 10 \"lib/Math/Algebra/power.hpp\"\n\nnamespace algorithm {\n\n//\
    \ \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF0EO(logK).\ntemplate <typename\
    \ Type>\nconstexpr Type ipow(Type n, long long k) {\n    assert(k >= 0);\n   \
    \ Type res = 1;\n    while(k > 0) {\n        if(k & 1LL) res *= n;\n        n\
    \ *= n;\n        k >>= 1;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 13 \"lib/Math/Algebra/nth_root.hpp\"\n\nnamespace algorithm {\n\n//\
    \ \u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0Ex\u306E\
    n\u4E57\u6839\u3092\u6C42\u3081\u308B\uFF0E\nconstexpr double nth_root(double\
    \ x, long long n, const double eps = 1e-10) {\n    assert(x >= 0.0);\n    assert(n\
    \ >= 1);\n    double res = 1.0;\n    while(1) {\n        double tmp = (x / ipow(res,\
    \ n - 1) + (n - 1) * res) / n;\n        if(std::abs(tmp - res) < eps) break;\n\
    \        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\
    \n"
  code: "#ifndef ALGORITHM_NTH_ROOT_HPP\n#define ALGORITHM_NTH_ROOT_HPP 1\n\n/**\n\
    \ * @brief \u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\n\
    \ * @docs docs/Math/Algebra/nth_root.md\n */\n\n#include <cassert>\n#include <cmath>\n\
    \n#include \"power.hpp\"\n\nnamespace algorithm {\n\n// \u7D2F\u4E57\u6839\uFF08\
    \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0Ex\u306En\u4E57\u6839\u3092\u6C42\
    \u3081\u308B\uFF0E\nconstexpr double nth_root(double x, long long n, const double\
    \ eps = 1e-10) {\n    assert(x >= 0.0);\n    assert(n >= 1);\n    double res =\
    \ 1.0;\n    while(1) {\n        double tmp = (x / ipow(res, n - 1) + (n - 1) *\
    \ res) / n;\n        if(std::abs(tmp - res) < eps) break;\n        res = tmp;\n\
    \    }\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - lib/Math/Algebra/power.hpp
  isVerificationFile: false
  path: lib/Math/Algebra/nth_root.hpp
  requiredBy: []
  timestamp: '2024-09-20 04:48:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ITP1_10_D-nth_root.test.cpp
documentation_of: lib/Math/Algebra/nth_root.hpp
layout: document
redirect_from:
- /library/lib/Math/Algebra/nth_root.hpp
- /library/lib/Math/Algebra/nth_root.hpp.html
title: "\u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
---
## 概要

非負の実数 $x$ に対して，非負の $n$ 乗根 $\sqrt[n]{x}$ を求める（ただし，$n$ は自然数）．

本実装では「ニュートン法」を用いており，近似解を計算する．


## 参考文献

1. 吉田 俊之ほか. "4.3 ニュートン法". 工学のための数値計算. 数理工学社, 2008, p.62-64.
1. "冪根". Wikipedia. <https://ja.wikipedia.org/wiki/冪根>.
1. "ニュートン法". Wikipedia. <https://ja.wikipedia.org/wiki/ニュートン法>.
