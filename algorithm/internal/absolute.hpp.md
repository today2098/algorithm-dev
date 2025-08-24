---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/greatest_common_divisor.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  - icon: ':warning:'
    path: test/Math/NumberTheory/greatest_common_divisor_test.cpp
    title: test/Math/NumberTheory/greatest_common_divisor_test.cpp
  - icon: ':warning:'
    path: test/Math/NumberTheory/least_common_multiple_test.cpp
    title: test/Math/NumberTheory/least_common_multiple_test.cpp
  - icon: ':warning:'
    path: test/internal/absolute_test.cpp
    title: test/internal/absolute_test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
    title: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/internal/absolute.hpp\"\n\n\n\n#include <concepts>\n\
    #include <type_traits>\n\nnamespace algorithm {\n\nnamespace internal {\n\n//\
    \ Returns the absolute value as type Res.\ntemplate <std::integral Res, std::unsigned_integral\
    \ Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n\
    \    return static_cast<Res>(n);\n}\n\n// Returns the absolute value as type Res.\n\
    template <std::integral Res, std::signed_integral Type>\nconstexpr Res abs(Type\
    \ n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    return static_cast<Res>(std::make_unsigned_t<Type>(n\
    \ < 0 ? -n : n));\n}\n\n}  // namespace internal\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_ABSOLUTE_HPP\n#define ALGORITHM_ABSOLUTE_HPP 1\n\n#include\
    \ <concepts>\n#include <type_traits>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\n// Returns the absolute value as type Res.\ntemplate <std::integral Res,\
    \ std::unsigned_integral Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res)\
    \ >= sizeof(Type));\n    return static_cast<Res>(n);\n}\n\n// Returns the absolute\
    \ value as type Res.\ntemplate <std::integral Res, std::signed_integral Type>\n\
    constexpr Res abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n\
    \    return static_cast<Res>(std::make_unsigned_t<Type>(n < 0 ? -n : n));\n}\n\
    \n}  // namespace internal\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/internal/absolute.hpp
  requiredBy:
  - algorithm/Math/NumberTheory/least_common_multiple.hpp
  - algorithm/Math/NumberTheory/greatest_common_divisor.hpp
  - test/internal/absolute_test.cpp
  - test/Math/NumberTheory/greatest_common_divisor_test.cpp
  - test/Math/NumberTheory/least_common_multiple_test.cpp
  timestamp: '2025-08-23 10:05:58+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-NTL_1_C-least_common_multiple.test.cpp
documentation_of: algorithm/internal/absolute.hpp
layout: document
redirect_from:
- /library/algorithm/internal/absolute.hpp
- /library/algorithm/internal/absolute.hpp.html
title: algorithm/internal/absolute.hpp
---
