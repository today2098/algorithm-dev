---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
  bundledCode: "#line 1 \"verify/aoj-ITP1_3_D-divisors.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\n\n#include\
    \ <algorithm>\n#include <cstdint>\n#include <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/divisors.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/NumberTheory/divisors.hpp\"\n#include <cassert>\n\
    #include <concepts>\n#line 8 \"algorithm/Math/NumberTheory/divisors.hpp\"\n#include\
    \ <vector>\n\nnamespace algorithm {\n\nnamespace internal {\n\ntemplate <std::integral\
    \ Res>\nconstexpr std::vector<Res> divisors(std::uint64_t n) {\n    std::vector<Res>\
    \ divs;  // divs[]:=(\u81EA\u7136\u6570n\u306E\u7D04\u6570\u306E\u30EA\u30B9\u30C8\
    ).\n    for(std::uint64_t p = 1; p < 1ULL << 32 and p * p <= n; ++p) {\n     \
    \   if(n % p != 0) continue;\n        divs.push_back(p);\n        auto q = n /\
    \ p;\n        if(q != p) divs.push_back(q);\n    }\n    divs.shrink_to_fit();\n\
    \    std::sort(divs.begin(), divs.end());\n    return divs;\n}\n\n}  // namespace\
    \ internal\n\n// \u7D04\u6570\u5217\u6319\uFF0EO(\u221An).\ntemplate <std::integral\
    \ Type>\nconstexpr std::vector<Type> divisors(Type n) {\n    assert(n > 0);\n\
    \    return internal::divisors<Type>(n);\n}\n\n}  // namespace algorithm\n\n\n\
    #line 8 \"verify/aoj-ITP1_3_D-divisors.test.cpp\"\n\nint main() {\n    std::uint32_t\
    \ a, b, c;\n    std::cin >> a >> b >> c;\n\n    auto divs = algorithm::divisors(c);\n\
    \    auto ans = std::count_if(divs.cbegin(), divs.cend(), [&](std::uint32_t d)\
    \ -> bool {\n        return a <= d and d <= b;\n    });\n\n    std::cout << ans\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#include <algorithm>\n#include <cstdint>\n#include <iostream>\n\n#include\
    \ \"../algorithm/Math/NumberTheory/divisors.hpp\"\n\nint main() {\n    std::uint32_t\
    \ a, b, c;\n    std::cin >> a >> b >> c;\n\n    auto divs = algorithm::divisors(c);\n\
    \    auto ans = std::count_if(divs.cbegin(), divs.cend(), [&](std::uint32_t d)\
    \ -> bool {\n        return a <= d and d <= b;\n    });\n\n    std::cout << ans\
    \ << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/NumberTheory/divisors.hpp
  isVerificationFile: true
  path: verify/aoj-ITP1_3_D-divisors.test.cpp
  requiredBy: []
  timestamp: '2025-08-30 04:07:09+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ITP1_3_D-divisors.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ITP1_3_D-divisors.test.cpp
- /verify/verify/aoj-ITP1_3_D-divisors.test.cpp.html
title: verify/aoj-ITP1_3_D-divisors.test.cpp
---
