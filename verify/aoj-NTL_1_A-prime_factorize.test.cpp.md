---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/prime_factorize.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"verify/aoj-NTL_1_A-prime_factorize.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\n\n#include\
    \ <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/prime_factorize.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <concepts>\n\
    #include <cstdint>\n#include <map>\n#include <vector>\n\nnamespace algorithm {\n\
    \nnamespace internal {\n\ntemplate <std::integral Res>\nconstexpr std::vector<Res>\
    \ distinct_prime_factorize(std::uint64_t n) {\n    std::vector<Res> factors; \
    \ // factors[]:=(\u81EA\u7136\u6570n\u306E\u7D20\u56E0\u6570\u306E\u30EA\u30B9\
    \u30C8).\n    factors.reserve(15);\n    if(n % 2 == 0) {\n        factors.push_back(2);\n\
    \        auto c = std::countr_zero(n);\n        n >>= c;\n    }\n    for(std::uint64_t\
    \ p = 3; p < 1ULL << 32 and p * p <= n; p += 2) {\n        if(n % p != 0) continue;\n\
    \        factors.push_back(p);\n        do {\n            n /= p;\n        } while(n\
    \ % p == 0);\n    }\n    if(n > 1) factors.push_back(n);\n    return factors;\n\
    }\n\ntemplate <std::integral Res>\nstd::map<Res, int> prime_factorize(std::uint64_t\
    \ n) {\n    std::map<Res, int> res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\
    \u307E\u308C\u308B\u7D20\u56E0\u6570p\u306E\u500B\u6570).\n    if(n % 2 == 0)\
    \ {\n        auto c = std::countr_zero(n);\n        res.emplace_hint(res.end(),\
    \ 2, c);\n        n >>= c;\n    }\n    for(std::uint64_t p = 3; p < 1ULL << 32\
    \ and p * p <= n; p += 2) {\n        int c = 0;\n        while(n % p == 0) n /=\
    \ p, ++c;\n        if(c > 0) res.emplace_hint(res.end(), p, c);\n    }\n    if(n\
    \ > 1) res.emplace_hint(res.end(), n, 1);\n    return res;\n}\n\n}  // namespace\
    \ internal\n\n// \u81EA\u7136\u6570n\u306E\u7D20\u56E0\u6570\u3092\u6C42\u3081\
    \u308B\uFF0EO(\u221An).\ntemplate <std::integral Type>\nconstexpr std::vector<Type>\
    \ distinct_prime_factorize(Type n) {\n    assert(n > 0);\n    return internal::distinct_prime_factorize<Type>(n);\n\
    }\n\n// \u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(\u221An).\ntemplate <std::integral\
    \ Type>\nstd::map<Type, int> prime_factorize(Type n) {\n    assert(n > 0);\n \
    \   return internal::prime_factorize<Type>(n);\n}\n\n// \u9AD8\u901F\u7D04\u6570\
    \u5217\u6319\uFF0E\ntemplate <typename Type>\nstd::vector<Type> divisors(const\
    \ std::map<Type, int> &pf) {\n    std::vector<Type> divs({1});\n    for(const\
    \ auto &[p, c] : pf) {\n        const int sz = divs.size();\n        Type d =\
    \ 1;\n        for(int i = 0; i < c; ++i) {\n            d *= p;\n            for(int\
    \ j = 0; j < sz; ++j) divs.push_back(divs[j] * d);\n        }\n    }\n    divs.shrink_to_fit();\n\
    \    std::sort(divs.begin(), divs.end());\n    return divs;\n}\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"verify/aoj-NTL_1_A-prime_factorize.test.cpp\"\n\nint\
    \ main() {\n    int n;\n    std::cin >> n;\n\n    std::cout << n << \":\";\n \
    \   for(const auto &[p, cnt] : algorithm::prime_factorize(n)) {\n        for(int\
    \ i = 0; i < cnt; ++i) std::cout << \" \" << p;\n    }\n    std::cout << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/Math/NumberTheory/prime_factorize.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::cout << n << \":\"\
    ;\n    for(const auto &[p, cnt] : algorithm::prime_factorize(n)) {\n        for(int\
    \ i = 0; i < cnt; ++i) std::cout << \" \" << p;\n    }\n    std::cout << std::endl;\n\
    }\n"
  dependsOn:
  - algorithm/Math/NumberTheory/prime_factorize.hpp
  isVerificationFile: true
  path: verify/aoj-NTL_1_A-prime_factorize.test.cpp
  requiredBy: []
  timestamp: '2025-08-30 04:07:09+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-NTL_1_A-prime_factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-NTL_1_A-prime_factorize.test.cpp
- /verify/verify/aoj-NTL_1_A-prime_factorize.test.cpp.html
title: verify/aoj-NTL_1_A-prime_factorize.test.cpp
---
