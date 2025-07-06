---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"verify/aoj-NTL_1_B-mod_pow.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\n\n#include\
    \ <iostream>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\
    \n#include <cassert>\n\nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\
    \u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(logK).\nconstexpr long long mod_pow(long\
    \ long n, long long k, int mod) {\n    assert(k >= 0);\n    assert(mod >= 1);\n\
    \    long long res = 1;\n    n %= mod;\n    while(k > 0) {\n        if(k & 1LL)\
    \ res = res * n % mod;\n        n = n * n % mod;\n        k >>= 1;\n    }\n  \
    \  return res;\n}\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-NTL_1_B-mod_pow.test.cpp\"\
    \n\nint main() {\n    constexpr int MOD = 1e9 + 7;\n\n    int m, n;\n    std::cin\
    \ >> m >> n;\n\n    auto ans = algorithm::mod_pow(m, n, MOD);\n    std::cout <<\
    \ ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/Math/ModularArithmetic/mod_pow.hpp\"\
    \n\nint main() {\n    constexpr int MOD = 1e9 + 7;\n\n    int m, n;\n    std::cin\
    \ >> m >> n;\n\n    auto ans = algorithm::mod_pow(m, n, MOD);\n    std::cout <<\
    \ ans << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  isVerificationFile: true
  path: verify/aoj-NTL_1_B-mod_pow.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-NTL_1_B-mod_pow.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-NTL_1_B-mod_pow.test.cpp
- /verify/verify/aoj-NTL_1_B-mod_pow.test.cpp.html
title: verify/aoj-NTL_1_B-mod_pow.test.cpp
---
