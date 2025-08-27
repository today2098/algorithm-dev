---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/extgcd.hpp
    title: "Extended Euclidean Algorithm\uFF08\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
      \u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"verify/aoj-NTL_1_E-extgcd.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\n\n#include\
    \ <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/extgcd.hpp\"\n\n\n\n#include\
    \ <concepts>\n#include <tuple>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\ntemplate <std::signed_integral Type>\nconstexpr Type extgcd(Type a, Type\
    \ b, Type &x, Type &y) {\n    if(b == 0) {\n        x = 1, y = 0;\n        return\
    \ a;\n    }\n    Type g = extgcd(b, a % b, y, x);\n    y -= a / b * x;\n    return\
    \ g;\n}\n\n}  // namespace internal\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF0EO(log(min(a,b))).\ntemplate <std::signed_integral\
    \ T, std::signed_integral U>\nconstexpr auto extgcd(T a, U b) {\n    using ct\
    \ = std::common_type_t<T, U>;\n    ct x, y;\n    ct g = internal::extgcd<ct>(a,\
    \ b, x, y);\n    if(g < 0) x = -x, y = -y, g = -g;\n    return std::tuple<ct,\
    \ ct, ct>(x, y, g);  // returns the tuple of (x, y, g) s.t. g=gcd(a,b), ax+by=g,\
    \ |x|<=|b|/g, |y|<=|a|/g.\n}\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-NTL_1_E-extgcd.test.cpp\"\
    \n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n\n    auto [x, y, g]\
    \ = algorithm::extgcd(a, b);\n    std::cout << x << \" \" << y << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/Math/NumberTheory/extgcd.hpp\"\
    \n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n\n    auto [x, y, g]\
    \ = algorithm::extgcd(a, b);\n    std::cout << x << \" \" << y << std::endl;\n\
    }\n"
  dependsOn:
  - algorithm/Math/NumberTheory/extgcd.hpp
  isVerificationFile: true
  path: verify/aoj-NTL_1_E-extgcd.test.cpp
  requiredBy: []
  timestamp: '2025-08-27 15:27:12+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-NTL_1_E-extgcd.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-NTL_1_E-extgcd.test.cpp
- /verify/verify/aoj-NTL_1_E-extgcd.test.cpp.html
title: verify/aoj-NTL_1_E-extgcd.test.cpp
---
