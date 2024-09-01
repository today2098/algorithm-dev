---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj-ALDS1_1_C-is_prime.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\n\n\
    #include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/is_prime.hpp\"\n\n\n\n\
    /**\n * @brief \u7D20\u6570\u5224\u5B9A\n * @docs docs/Math/NumberTheory/is_prime.md\n\
    \ */\n\n#include <cassert>\n\nnamespace algorithm {\n\n// \u7D20\u6570\u5224\u5B9A\
    \uFF0EO(\u221AN).\ntemplate <typename Type>\nconstexpr bool is_prime(Type n) {\n\
    \    assert(n >= 0);\n    if(n < 2) return false;\n    if(n == 2) return true;\n\
    \    if(n % 2 == 0) return false;\n    for(Type p = 3; p * p <= n; p += 2) {\n\
    \        if(n % p == 0) return false;\n    }\n    return true;\n}\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"test/aoj-ALDS1_1_C-is_prime.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n\n    int ans = 0;\n    for(int i = 0; i\
    \ < n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(algorithm::is_prime(a))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/is_prime.hpp\"\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n\n    int ans = 0;\n    for(int\
    \ i = 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(algorithm::is_prime(a))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/is_prime.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_1_C-is_prime.test.cpp
  requiredBy: []
  timestamp: '2024-09-02 01:55:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ALDS1_1_C-is_prime.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_1_C-is_prime.test.cpp
- /verify/test/aoj-ALDS1_1_C-is_prime.test.cpp.html
title: test/aoj-ALDS1_1_C-is_prime.test.cpp
---
