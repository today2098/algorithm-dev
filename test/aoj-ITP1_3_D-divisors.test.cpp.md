---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/divisors.hpp
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
  bundledCode: "#line 1 \"test/aoj-ITP1_3_D-divisors.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/divisors.hpp\"\
    \n\n\n\n/**\n * @brief \u7D04\u6570\u5217\u6319\n * @docs docs/Math/NumberTheory/divisors.md\n\
    \ */\n\n#line 10 \"lib/Math/NumberTheory/divisors.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7D04\u6570\u5217\u6319\uFF0E\
    O(\u221AN).\ntemplate <typename Type>\nstd::vector<Type> divisors(Type n) {\n\
    \    assert(n >= 1);\n    std::vector<Type> res;  // res[]:=(\u81EA\u7136\u6570\
    n\u306E\u7D04\u6570\u306E\u96C6\u5408).\n    for(Type p = 1; p * p <= n; ++p)\
    \ {\n        if(n % p == 0) {\n            res.push_back(p);\n            Type\
    \ q = n / p;\n            if(q != p) res.push_back(q);\n        }\n    }\n   \
    \ std::sort(res.begin(), res.end());\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 7 \"test/aoj-ITP1_3_D-divisors.test.cpp\"\n\nint main() {\n    int a,\
    \ b, c;\n    std::cin >> a >> b >> c;\n\n    const auto &&divs = algorithm::divisors(c);\n\
    \n    auto ans = std::upper_bound(divs.begin(), divs.end(), b) - std::lower_bound(divs.begin(),\
    \ divs.end(), a);\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/divisors.hpp\"\
    \n\nint main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n\n    const\
    \ auto &&divs = algorithm::divisors(c);\n\n    auto ans = std::upper_bound(divs.begin(),\
    \ divs.end(), b) - std::lower_bound(divs.begin(), divs.end(), a);\n    std::cout\
    \ << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/divisors.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_3_D-divisors.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 00:09:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_3_D-divisors.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_3_D-divisors.test.cpp
- /verify/test/aoj-ITP1_3_D-divisors.test.cpp.html
title: test/aoj-ITP1_3_D-divisors.test.cpp
---
