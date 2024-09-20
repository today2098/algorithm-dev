---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/square_root.hpp
    title: "\u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-4
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_A
  bundledCode: "#line 1 \"test/aoj-ITP1_10_A-isqrt.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_A\"\n#define\
    \ ERROR 1e-4\n\n#include <iostream>\n\n#line 1 \"lib/Math/Algebra/square_root.hpp\"\
    \n\n\n\n/**\n * @brief \u5E73\u65B9\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\
    \uFF09\n * @docs docs/Math/Algebra/square_root.md\n */\n\n#include <cassert>\n\
    #include <cmath>\n\nnamespace algorithm {\n\n// \u5E73\u65B9\u6839\uFF08\u30CB\
    \u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0E\nconstexpr double isqrt(double x, const\
    \ double eps = 1e-10) {\n    assert(x >= 0.0);\n    double res = 1.0;\n    while(1)\
    \ {\n        double tmp = (x / res + res) / 2;\n        if(std::abs(tmp - res)\
    \ < eps) break;\n        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n\n#line 7 \"test/aoj-ITP1_10_A-isqrt.test.cpp\"\n\nint main() {\n\
    \    double x1, y1, x2, y2;\n    std::cin >> x1 >> y1 >> x2 >> y2;\n\n    auto\
    \ tmp = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);\n    auto &&ans = algorithm::isqrt(tmp,\
    \ 1e-8);\n    printf(\"%.6f\\n\", ans);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_A\"\
    \n#define ERROR 1e-4\n\n#include <iostream>\n\n#include \"../lib/Math/Algebra/square_root.hpp\"\
    \n\nint main() {\n    double x1, y1, x2, y2;\n    std::cin >> x1 >> y1 >> x2 >>\
    \ y2;\n\n    auto tmp = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);\n    auto\
    \ &&ans = algorithm::isqrt(tmp, 1e-8);\n    printf(\"%.6f\\n\", ans);\n}\n"
  dependsOn:
  - lib/Math/Algebra/square_root.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_10_A-isqrt.test.cpp
  requiredBy: []
  timestamp: '2024-09-20 22:10:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_10_A-isqrt.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_10_A-isqrt.test.cpp
- /verify/test/aoj-ITP1_10_A-isqrt.test.cpp.html
title: test/aoj-ITP1_10_A-isqrt.test.cpp
---
