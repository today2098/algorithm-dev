---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/nth_root.hpp
    title: "\u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09"
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/power.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/power.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-5
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D
  bundledCode: "#line 1 \"verify/aoj-ITP1_10_D-nth_root.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D\"\n#define\
    \ ERROR 1e-5\n\n#include <algorithm>\n#include <cmath>\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"lib/Math/Algebra/nth_root.hpp\"\n\n\n\n/**\n *\
    \ @brief \u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\n\
    \ * @docs docs/Math/Algebra/nth_root.md\n */\n\n#include <cassert>\n#line 11 \"\
    lib/Math/Algebra/nth_root.hpp\"\n\n#line 1 \"lib/Math/Algebra/power.hpp\"\n\n\n\
    \n/**\n * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n * @docs docs/Math/Algebra/power.md\n\
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
    \n#line 11 \"verify/aoj-ITP1_10_D-nth_root.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    std::cin >> n;\n\n    std::vector<int> x(n), y(n);\n    for(auto &in\
    \ : x) std::cin >> in;\n    for(auto &in : y) std::cin >> in;\n\n    auto f =\
    \ [&](int p) -> double {\n        double tmp = 0.0;\n        for(int i = 0; i\
    \ < n; ++i) tmp += algorithm::ipow(std::abs(x[i] - y[i]), p);\n        return\
    \ algorithm::nth_root(tmp, p, 1e-10);\n    };\n\n    for(int p = 1; p <= 3; ++p)\
    \ {\n        auto &&ans = f(p);\n        printf(\"%.8lf\\n\", ans);\n    }\n\n\
    \    int ans = 0;\n    for(int i = 0; i < n; ++i) ans = std::max(ans, std::abs(x[i]\
    \ - y[i]));\n\n    printf(\"%.8lf\\n\", (double)ans);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D\"\
    \n#define ERROR 1e-5\n\n#include <algorithm>\n#include <cmath>\n#include <iostream>\n\
    #include <vector>\n\n#include \"../lib/Math/Algebra/nth_root.hpp\"\n#include \"\
    ../lib/Math/Algebra/power.hpp\"\n\nint main() {\n    int n;\n    std::cin >> n;\n\
    \n    std::vector<int> x(n), y(n);\n    for(auto &in : x) std::cin >> in;\n  \
    \  for(auto &in : y) std::cin >> in;\n\n    auto f = [&](int p) -> double {\n\
    \        double tmp = 0.0;\n        for(int i = 0; i < n; ++i) tmp += algorithm::ipow(std::abs(x[i]\
    \ - y[i]), p);\n        return algorithm::nth_root(tmp, p, 1e-10);\n    };\n\n\
    \    for(int p = 1; p <= 3; ++p) {\n        auto &&ans = f(p);\n        printf(\"\
    %.8lf\\n\", ans);\n    }\n\n    int ans = 0;\n    for(int i = 0; i < n; ++i) ans\
    \ = std::max(ans, std::abs(x[i] - y[i]));\n\n    printf(\"%.8lf\\n\", (double)ans);\n\
    }\n"
  dependsOn:
  - lib/Math/Algebra/nth_root.hpp
  - lib/Math/Algebra/power.hpp
  - lib/Math/Algebra/power.hpp
  isVerificationFile: true
  path: verify/aoj-ITP1_10_D-nth_root.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ITP1_10_D-nth_root.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ITP1_10_D-nth_root.test.cpp
- /verify/verify/aoj-ITP1_10_D-nth_root.test.cpp.html
title: verify/aoj-ITP1_10_D-nth_root.test.cpp
---
