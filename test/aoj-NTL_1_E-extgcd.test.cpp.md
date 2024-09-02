---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/extgcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
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
  bundledCode: "#line 1 \"test/aoj-NTL_1_E-extgcd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/extgcd.hpp\"\n\n\n\n\
    /**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5\n * @docs docs/Math/NumberTheory/extgcd.md\n */\n\nnamespace algorithm\
    \ {\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
    \uFF0E\n// ax+by=gcd(a,b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\
    \u6C42\u3081\uFF0Cgcd(a,b)\u3092\u8FD4\u3059\uFF0EO(log(min(a,b))).\ntemplate\
    \ <typename Type>\nType extgcd(Type a, Type b, Type &x, Type &y) {\n    if(b ==\
    \ 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    Type &&d = extgcd(b,\
    \ a % b, y, x);\n    y -= a / b * x;\n    return d;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 6 \"test/aoj-NTL_1_E-extgcd.test.cpp\"\n\nint main() {\n    int a, b;\n\
    \    std::cin >> a >> b;\n\n    int x, y;\n    algorithm::extgcd(a, b, x, y);\n\
    \n    std::cout << x << \" \" << y << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/extgcd.hpp\"\n\n\
    int main() {\n    int a, b;\n    std::cin >> a >> b;\n\n    int x, y;\n    algorithm::extgcd(a,\
    \ b, x, y);\n\n    std::cout << x << \" \" << y << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/extgcd.hpp
  isVerificationFile: true
  path: test/aoj-NTL_1_E-extgcd.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 00:12:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_1_E-extgcd.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_1_E-extgcd.test.cpp
- /verify/test/aoj-NTL_1_E-extgcd.test.cpp.html
title: test/aoj-NTL_1_E-extgcd.test.cpp
---
