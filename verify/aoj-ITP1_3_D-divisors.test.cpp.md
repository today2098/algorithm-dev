---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/divisors.hpp
    title: algorithm/Math/NumberTheory/divisors.hpp
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
    \ <algorithm>\n#include <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/divisors.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/NumberTheory/divisors.hpp\"\n#include <cassert>\n\
    #include <map>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D04\u6570\u5217\
    \u6319\uFF0EO(\u221AN).\ntemplate <typename Type>\nstd::vector<Type> divisors(Type\
    \ n) {\n    assert(n >= 1);\n    std::vector<Type> res;  // res[]:=(\u81EA\u7136\
    \u6570n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n    for(Type p = 1; p * p <= n;\
    \ ++p) {\n        if(n % p == 0) {\n            res.push_back(p);\n          \
    \  Type q = n / p;\n            if(q != p) res.push_back(q);\n        }\n    }\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n// \u9AD8\u901F\
    \u7D04\u6570\u5217\u6319\uFF0E\ntemplate <typename Type>\nstd::vector<Type> divisors(const\
    \ std::map<Type, int> &pf) {\n    std::vector<Type> res({1});\n    for(const auto\
    \ &[p, cnt] : pf) {\n        const int sz = res.size();\n        Type b = 1;\n\
    \        for(int i = 0; i < cnt; ++i) {\n            b *= p;\n            for(int\
    \ j = 0; j < sz; ++j) res.push_back(res[j] * b);\n        }\n    }\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\n}  // namespace algorithm\n\n\n#line 7 \"\
    verify/aoj-ITP1_3_D-divisors.test.cpp\"\n\nint main() {\n    int a, b, c;\n  \
    \  std::cin >> a >> b >> c;\n\n    const auto &&divs = algorithm::divisors(c);\n\
    \    auto left = std::lower_bound(divs.cbegin(), divs.cend(), a);\n    auto right\
    \ = std::upper_bound(divs.cbegin(), divs.cend(), b);\n\n    auto ans = right -\
    \ left;\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#include \"../algorithm/Math/NumberTheory/divisors.hpp\"\
    \n\nint main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n\n    const\
    \ auto &&divs = algorithm::divisors(c);\n    auto left = std::lower_bound(divs.cbegin(),\
    \ divs.cend(), a);\n    auto right = std::upper_bound(divs.cbegin(), divs.cend(),\
    \ b);\n\n    auto ans = right - left;\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/NumberTheory/divisors.hpp
  isVerificationFile: true
  path: verify/aoj-ITP1_3_D-divisors.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ITP1_3_D-divisors.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ITP1_3_D-divisors.test.cpp
- /verify/verify/aoj-ITP1_3_D-divisors.test.cpp.html
title: verify/aoj-ITP1_3_D-divisors.test.cpp
---
