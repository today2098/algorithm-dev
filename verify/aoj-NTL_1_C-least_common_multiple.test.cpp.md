---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/greatest_common_divisor.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/internal/absolute.hpp
    title: algorithm/internal/absolute.hpp
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
  bundledCode: "#line 1 \"verify/aoj-NTL_1_C-least_common_multiple.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#include <cstdint>\n#include <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/least_common_multiple.hpp\"\
    \n\n\n\n#include <concepts>\n#include <type_traits>\n\n#line 1 \"algorithm/internal/absolute.hpp\"\
    \n\n\n\n#line 6 \"algorithm/internal/absolute.hpp\"\n\nnamespace algorithm {\n\
    \nnamespace internal {\n\n// Returns the absolute value as type Res.\ntemplate\
    \ <std::integral Res, std::unsigned_integral Type>\nconstexpr Res abs(Type n)\
    \ {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    return static_cast<Res>(n);\n\
    }\n\n// Returns the absolute value as type Res.\ntemplate <std::integral Res,\
    \ std::signed_integral Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res)\
    \ >= sizeof(Type));\n    return static_cast<Res>(std::make_unsigned_t<Type>(n\
    \ < 0 ? -n : n));\n}\n\n}  // namespace internal\n\n}  // namespace algorithm\n\
    \n\n#line 1 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n\n\n\
    #line 6 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n#line 8\
    \ \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\n\nnamespace algorithm\
    \ {\n\nnamespace internal {\n\ntemplate <std::integral Type>\nconstexpr Type gcd(Type\
    \ a, Type b) {\n    if(b == 0) return a;\n    return gcd(b, a % b);\n}\n\n}  //\
    \ namespace internal\n\n// Returns the greatest common divisor (GCD) of |a| and\
    \ |b|.\ntemplate <std::integral T, std::integral U>\nconstexpr std::common_type_t<T,\
    \ U> gcd(T a, U b) {\n    using ct = std::common_type_t<T, U>;\n    using ut =\
    \ std::make_unsigned_t<ct>;\n    ut ua = ::algorithm::internal::abs<ut>(a);\n\
    \    ut ub = ::algorithm::internal::abs<ut>(b);\n    return internal::gcd(ua,\
    \ ub);\n}\n\n// Returns the greatest common divisor (GCD) of all arguments.\n\
    template <std::integral Type, std::integral... Args>\nconstexpr auto gcd(Type\
    \ first, Args... args) { return gcd(first, gcd(args...)); }\n\n}  // namespace\
    \ algorithm\n\n\n#line 9 \"algorithm/Math/NumberTheory/least_common_multiple.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\ntemplate <std::integral Type>\n\
    constexpr Type lcm(Type a, Type b) {\n    if(a == 0 or b == 0) return 0;\n   \
    \ return a / ::algorithm::internal::gcd(a, b) * b;\n}\n\n}  // namespace internal\n\
    \n// Returns the least common multiple (LCM) of |a| and |b|.\ntemplate <std::integral\
    \ T, std::integral U>\nconstexpr std::common_type_t<T, U> lcm(T a, U b) {\n  \
    \  using ct = std::common_type_t<T, U>;\n    using ut = std::make_unsigned_t<ct>;\n\
    \    ut ua = ::algorithm::internal::abs<ut>(a);\n    ut ub = ::algorithm::internal::abs<ut>(b);\n\
    \    return internal::lcm(ua, ub);\n}\n\n// Returns the least common multiple\
    \ (LCM) of all arguments.\ntemplate <std::integral Type, std::integral... Args>\n\
    constexpr auto lcm(Type first, Args... args) { return lcm(first, lcm(args...));\
    \ }\n\n}  // namespace algorithm\n\n\n#line 7 \"verify/aoj-NTL_1_C-least_common_multiple.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::uint32_t ans = 1;\n\
    \    for(int i = 0; i < n; ++i) {\n        std::uint32_t a;\n        std::cin\
    \ >> a;\n\n        ans = algorithm::lcm(ans, a);\n    }\n\n    std::cout << ans\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C\"\
    \n\n#include <cstdint>\n#include <iostream>\n\n#include \"../algorithm/Math/NumberTheory/least_common_multiple.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::uint32_t ans = 1;\n\
    \    for(int i = 0; i < n; ++i) {\n        std::uint32_t a;\n        std::cin\
    \ >> a;\n\n        ans = algorithm::lcm(ans, a);\n    }\n\n    std::cout << ans\
    \ << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/NumberTheory/least_common_multiple.hpp
  - algorithm/internal/absolute.hpp
  - algorithm/Math/NumberTheory/greatest_common_divisor.hpp
  isVerificationFile: true
  path: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
  requiredBy: []
  timestamp: '2025-08-23 10:05:58+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-NTL_1_C-least_common_multiple.test.cpp
- /verify/verify/aoj-NTL_1_C-least_common_multiple.test.cpp.html
title: verify/aoj-NTL_1_C-least_common_multiple.test.cpp
---
