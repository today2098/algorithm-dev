---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/greatest_common_divisor.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C
  bundledCode: "#line 1 \"test/aoj-NTL_1_C-least_common_multiple.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#include <cstdint>\n#include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/least_common_multiple.hpp\"\
    \n\n\n\n/**\n * @brief Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\
    \uFF09\n * @docs docs/Math/NumberTheory/least_common_multiple.md\n */\n\n#line\
    \ 1 \"lib/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n\n\n/**\n * @brief\
    \ Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09\n * @docs\
    \ docs/Math/NumberTheory/greatest_common_divisor.md\n */\n\nnamespace algorithm\
    \ {\n\ntemplate <typename Type>\nconstexpr Type igcd(Type a, Type b) { return\
    \ (b == 0 ? a : igcd(b, a % b)); }\n\n}  // namespace algorithm\n\n\n#line 10\
    \ \"lib/Math/NumberTheory/least_common_multiple.hpp\"\n\nnamespace algorithm {\n\
    \ntemplate <typename Type>\nconstexpr Type ilcm(Type a, Type b) { return a / igcd(a,\
    \ b) * b; }\n\n}  // namespace algorithm\n\n\n#line 7 \"test/aoj-NTL_1_C-least_common_multiple.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    uint32_t ans = 1;\n  \
    \  for(int i = 0; i < n; ++i) {\n        uint32_t a;\n        std::cin >> a;\n\
    \n        ans = algorithm::ilcm(ans, a);\n    }\n\n    std::cout << ans << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#include <cstdint>\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/least_common_multiple.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    uint32_t ans = 1;\n  \
    \  for(int i = 0; i < n; ++i) {\n        uint32_t a;\n        std::cin >> a;\n\
    \n        ans = algorithm::ilcm(ans, a);\n    }\n\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - lib/Math/NumberTheory/least_common_multiple.hpp
  - lib/Math/NumberTheory/greatest_common_divisor.hpp
  isVerificationFile: true
  path: test/aoj-NTL_1_C-least_common_multiple.test.cpp
  requiredBy: []
  timestamp: '2024-09-06 22:47:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_1_C-least_common_multiple.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_1_C-least_common_multiple.test.cpp
- /verify/test/aoj-NTL_1_C-least_common_multiple.test.cpp.html
title: test/aoj-NTL_1_C-least_common_multiple.test.cpp
---
