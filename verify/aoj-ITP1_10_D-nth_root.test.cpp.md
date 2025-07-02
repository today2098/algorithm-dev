---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/nth_root.hpp
    title: algorithm/Math/Algebra/nth_root.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/power.hpp
    title: algorithm/Math/Algebra/power.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/power.hpp
    title: algorithm/Math/Algebra/power.hpp
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
    #include <vector>\n\n#line 1 \"algorithm/Math/Algebra/nth_root.hpp\"\n\n\n\n#include\
    \ <cassert>\n#line 6 \"algorithm/Math/Algebra/nth_root.hpp\"\n\n#line 1 \"algorithm/Math/Algebra/power.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/Algebra/power.hpp\"\n\nnamespace algorithm {\n\
    \n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF0EO(logK).\ntemplate <typename\
    \ Type>\nconstexpr Type pow(Type n, long long k) {\n    assert(k >= 0);\n    Type\
    \ res = 1;\n    while(k > 0) {\n        if(k & 1LL) res *= n;\n        n *= n;\n\
    \        k >>= 1;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\n\
    #line 8 \"algorithm/Math/Algebra/nth_root.hpp\"\n\nnamespace algorithm {\n\n//\
    \ \u7D2F\u4E57\u6839\uFF08\u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\uFF09\uFF0Ex\u306E\
    n\u4E57\u6839\u3092\u6C42\u3081\u308B\uFF0E\nconstexpr double nth_root(double\
    \ x, long long n, double eps = 1e-10) {\n    assert(x >= 0.0);\n    assert(n >=\
    \ 1);\n    double res = 1.0;\n    while(true) {\n        double tmp = (x / pow(res,\
    \ n - 1) + (n - 1) * res) / n;\n        if(std::abs(tmp - res) < eps) break;\n\
    \        res = tmp;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\
    \n#line 11 \"verify/aoj-ITP1_10_D-nth_root.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    std::cin >> n;\n\n    std::vector<int> x(n), y(n);\n    for(auto &elem\
    \ : x) std::cin >> elem;\n    for(auto &elem : y) std::cin >> elem;\n\n    auto\
    \ f = [&](int p) -> double {\n        double tmp = 0.0;\n        for(int i = 0;\
    \ i < n; ++i) tmp += algorithm::pow(std::abs(x[i] - y[i]), p);\n        return\
    \ algorithm::nth_root(tmp, p, 1e-10);\n    };\n    auto g = [&]() -> int {\n \
    \       int res = 0;\n        for(int i = 0; i < n; ++i) res = std::max(res, std::abs(x[i]\
    \ - y[i]));\n        return res;\n    };\n\n    for(int p = 1; p <= 3; ++p) printf(\"\
    %.8lf\\n\", f(p));\n    std::cout << g() << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/10/ITP1_10_D\"\
    \n#define ERROR 1e-5\n\n#include <algorithm>\n#include <cmath>\n#include <iostream>\n\
    #include <vector>\n\n#include \"../algorithm/Math/Algebra/nth_root.hpp\"\n#include\
    \ \"../algorithm/Math/Algebra/power.hpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    std::vector<int> x(n), y(n);\n    for(auto &elem : x) std::cin\
    \ >> elem;\n    for(auto &elem : y) std::cin >> elem;\n\n    auto f = [&](int\
    \ p) -> double {\n        double tmp = 0.0;\n        for(int i = 0; i < n; ++i)\
    \ tmp += algorithm::pow(std::abs(x[i] - y[i]), p);\n        return algorithm::nth_root(tmp,\
    \ p, 1e-10);\n    };\n    auto g = [&]() -> int {\n        int res = 0;\n    \
    \    for(int i = 0; i < n; ++i) res = std::max(res, std::abs(x[i] - y[i]));\n\
    \        return res;\n    };\n\n    for(int p = 1; p <= 3; ++p) printf(\"%.8lf\\\
    n\", f(p));\n    std::cout << g() << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/Algebra/nth_root.hpp
  - algorithm/Math/Algebra/power.hpp
  - algorithm/Math/Algebra/power.hpp
  isVerificationFile: true
  path: verify/aoj-ITP1_10_D-nth_root.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ITP1_10_D-nth_root.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ITP1_10_D-nth_root.test.cpp
- /verify/verify/aoj-ITP1_10_D-nth_root.test.cpp.html
title: verify/aoj-ITP1_10_D-nth_root.test.cpp
---
