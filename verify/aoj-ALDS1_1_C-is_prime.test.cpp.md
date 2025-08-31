---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/is_prime.hpp
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
  bundledCode: "#line 1 \"verify/aoj-ALDS1_1_C-is_prime.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\n\n\
    #include <cstdint>\n#include <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/is_prime.hpp\"\
    \n\n\n\n#include <cassert>\n#include <concepts>\n#line 7 \"algorithm/Math/NumberTheory/is_prime.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\nconstexpr bool is_prime(std::uint64_t\
    \ n) {\n    if(n < 2) return false;\n    if(n == 2) return true;\n    if(n % 2\
    \ == 0) return false;\n    for(std::uint64_t p = 3; p < 1ULL << 32 and p * p <=\
    \ n; p += 2) {\n        if(n % p == 0) return false;\n    }\n    return true;\n\
    }\n\n}  // namespace internal\n\n// \u7D20\u6570\u5224\u5B9A\uFF0EO(\u221An).\n\
    template <std::unsigned_integral Type>\nconstexpr bool is_prime(Type n) { return\
    \ internal::is_prime(n); }\n\n// \u7D20\u6570\u5224\u5B9A\uFF0EO(\u221An).\ntemplate\
    \ <std::signed_integral Type>\nconstexpr bool is_prime(Type n) {\n    assert(n\
    \ >= 0);\n    return internal::is_prime(n);\n}\n\n}  // namespace algorithm\n\n\
    \n#line 7 \"verify/aoj-ALDS1_1_C-is_prime.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    std::cin >> n;\n\n    int ans = 0;\n    for(int i = 0; i < n; ++i) {\n\
    \        std::uint32_t a;\n        std::cin >> a;\n\n        if(algorithm::is_prime(a))\
    \ ++ans;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <cstdint>\n#include <iostream>\n\n#include \"../algorithm/Math/NumberTheory/is_prime.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    int ans = 0;\n    for(int\
    \ i = 0; i < n; ++i) {\n        std::uint32_t a;\n        std::cin >> a;\n\n \
    \       if(algorithm::is_prime(a)) ++ans;\n    }\n\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - algorithm/Math/NumberTheory/is_prime.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_1_C-is_prime.test.cpp
  requiredBy: []
  timestamp: '2025-08-30 04:07:09+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_1_C-is_prime.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_1_C-is_prime.test.cpp
- /verify/verify/aoj-ALDS1_1_C-is_prime.test.cpp.html
title: verify/aoj-ALDS1_1_C-is_prime.test.cpp
---
