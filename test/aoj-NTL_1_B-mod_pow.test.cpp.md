---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/mod_pow.hpp
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
  bundledCode: "#line 1 \"test/aoj-NTL_1_B-mod_pow.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\n\n#include\
    \ <iostream>\n\n#line 1 \"lib/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n/**\n\
    \ * @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\
    \n * @docs docs/Math/ModularArithmetic/mod_pow.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0En^k mod m \u3092\u6C42\u3081\u308B\uFF0EO(logK).\n\
    constexpr int mod_pow(long long n, long long k, int m) {\n    assert(k >= 0);\n\
    \    assert(m >= 1);\n    long long res = 1;\n    n %= m;\n    while(k > 0) {\n\
    \        if(k & 1LL) res = res * n % m;\n        n = n * n % m;\n        k >>=\
    \ 1;\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\n#line 6 \"test/aoj-NTL_1_B-mod_pow.test.cpp\"\
    \n\nint main() {\n    constexpr int MOD = 1e9 + 7;\n\n    int m, n;\n    std::cin\
    \ >> m >> n;\n\n    auto &&ans = algorithm::mod_pow(m, n, MOD);\n    std::cout\
    \ << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/ModularArithmetic/mod_pow.hpp\"\
    \n\nint main() {\n    constexpr int MOD = 1e9 + 7;\n\n    int m, n;\n    std::cin\
    \ >> m >> n;\n\n    auto &&ans = algorithm::mod_pow(m, n, MOD);\n    std::cout\
    \ << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/ModularArithmetic/mod_pow.hpp
  isVerificationFile: true
  path: test/aoj-NTL_1_B-mod_pow.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 18:11:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_1_B-mod_pow.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_1_B-mod_pow.test.cpp
- /verify/test/aoj-NTL_1_B-mod_pow.test.cpp.html
title: test/aoj-NTL_1_B-mod_pow.test.cpp
---
