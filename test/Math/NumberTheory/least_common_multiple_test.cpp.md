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
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/least_common_multiple.hpp\"\n\
    \n\n\n#include <concepts>\n#include <type_traits>\n\n#line 1 \"algorithm/internal/absolute.hpp\"\
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
    \ }\n\n}  // namespace algorithm\n\n\n#line 2 \"test/Math/NumberTheory/least_common_multiple_test.cpp\"\
    \n\n#include <gtest/gtest.h>\n\n#include <cstdint>\n#include <limits>\n#include\
    \ <numeric>\n#include <random>\n#line 10 \"test/Math/NumberTheory/least_common_multiple_test.cpp\"\
    \n\nclass LcmTest : public ::testing::Test {\nprotected:\n    std::mt19937_64\
    \ rng;\n\n    void SetUp() override {\n        std::random_device seed;\n    \
    \    rng.seed(seed());\n    }\n};\n\nTEST_F(LcmTest, TwoArguments) {\n    using\
    \ type = std::int32_t;\n    auto min = std::numeric_limits<type>::min();\n   \
    \ auto max = std::numeric_limits<type>::max();\n    std::uniform_int_distribution<type>\
    \ dist(min, max);\n\n    for(int i = 0; i < 100; ++i) {\n        auto a = dist(rng);\n\
    \        auto b = dist(rng);\n\n        auto expected = std::lcm(a, b);\n    \
    \    auto actual = algorithm::lcm(a, b);\n\n        EXPECT_TRUE((std::is_same_v<std::int32_t,\
    \ decltype(actual)>));\n        EXPECT_TRUE((std::is_same_v<decltype(expected),\
    \ decltype(actual)>));\n        EXPECT_EQ(expected, actual);\n    }\n}\n\nTEST_F(LcmTest,\
    \ ThreeArguments) {\n    using type_a = std::int32_t;\n    auto min_a = std::numeric_limits<type_a>::min();\n\
    \    auto max_a = std::numeric_limits<type_a>::max();\n    std::uniform_int_distribution<type_a>\
    \ dist_a(min_a, max_a);\n\n    using type_b = std::uint32_t;\n    auto min_b =\
    \ std::numeric_limits<type_b>::min();\n    auto max_b = std::numeric_limits<type_b>::max();\n\
    \    std::uniform_int_distribution<type_b> dist_b(min_b, max_b);\n\n    using\
    \ type_c = std::int64_t;\n    auto min_c = std::numeric_limits<type_c>::min();\n\
    \    auto max_c = std::numeric_limits<type_c>::max();\n    std::uniform_int_distribution<type_c>\
    \ dist_c(min_c, max_c);\n\n    for(int i = 0; i < 100; ++i) {\n        auto a\
    \ = dist_a(rng);\n        auto b = dist_b(rng);\n        auto c = dist_c(rng);\n\
    \n        auto expected = std::lcm(a, std::lcm(b, c));\n        auto actual =\
    \ algorithm::lcm(a, b, c);\n\n        EXPECT_TRUE((std::is_same_v<std::int64_t,\
    \ decltype(actual)>));\n        EXPECT_TRUE((std::is_same_v<decltype(expected),\
    \ decltype(actual)>));\n        EXPECT_EQ(expected, actual);\n    }\n}\n"
  code: "#include \"../../../algorithm/Math/NumberTheory/least_common_multiple.hpp\"\
    \n\n#include <gtest/gtest.h>\n\n#include <cstdint>\n#include <limits>\n#include\
    \ <numeric>\n#include <random>\n#include <type_traits>\n\nclass LcmTest : public\
    \ ::testing::Test {\nprotected:\n    std::mt19937_64 rng;\n\n    void SetUp()\
    \ override {\n        std::random_device seed;\n        rng.seed(seed());\n  \
    \  }\n};\n\nTEST_F(LcmTest, TwoArguments) {\n    using type = std::int32_t;\n\
    \    auto min = std::numeric_limits<type>::min();\n    auto max = std::numeric_limits<type>::max();\n\
    \    std::uniform_int_distribution<type> dist(min, max);\n\n    for(int i = 0;\
    \ i < 100; ++i) {\n        auto a = dist(rng);\n        auto b = dist(rng);\n\n\
    \        auto expected = std::lcm(a, b);\n        auto actual = algorithm::lcm(a,\
    \ b);\n\n        EXPECT_TRUE((std::is_same_v<std::int32_t, decltype(actual)>));\n\
    \        EXPECT_TRUE((std::is_same_v<decltype(expected), decltype(actual)>));\n\
    \        EXPECT_EQ(expected, actual);\n    }\n}\n\nTEST_F(LcmTest, ThreeArguments)\
    \ {\n    using type_a = std::int32_t;\n    auto min_a = std::numeric_limits<type_a>::min();\n\
    \    auto max_a = std::numeric_limits<type_a>::max();\n    std::uniform_int_distribution<type_a>\
    \ dist_a(min_a, max_a);\n\n    using type_b = std::uint32_t;\n    auto min_b =\
    \ std::numeric_limits<type_b>::min();\n    auto max_b = std::numeric_limits<type_b>::max();\n\
    \    std::uniform_int_distribution<type_b> dist_b(min_b, max_b);\n\n    using\
    \ type_c = std::int64_t;\n    auto min_c = std::numeric_limits<type_c>::min();\n\
    \    auto max_c = std::numeric_limits<type_c>::max();\n    std::uniform_int_distribution<type_c>\
    \ dist_c(min_c, max_c);\n\n    for(int i = 0; i < 100; ++i) {\n        auto a\
    \ = dist_a(rng);\n        auto b = dist_b(rng);\n        auto c = dist_c(rng);\n\
    \n        auto expected = std::lcm(a, std::lcm(b, c));\n        auto actual =\
    \ algorithm::lcm(a, b, c);\n\n        EXPECT_TRUE((std::is_same_v<std::int64_t,\
    \ decltype(actual)>));\n        EXPECT_TRUE((std::is_same_v<decltype(expected),\
    \ decltype(actual)>));\n        EXPECT_EQ(expected, actual);\n    }\n}\n"
  dependsOn:
  - algorithm/Math/NumberTheory/least_common_multiple.hpp
  - algorithm/internal/absolute.hpp
  - algorithm/Math/NumberTheory/greatest_common_divisor.hpp
  isVerificationFile: false
  path: test/Math/NumberTheory/least_common_multiple_test.cpp
  requiredBy: []
  timestamp: '2025-08-23 10:05:58+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/Math/NumberTheory/least_common_multiple_test.cpp
layout: document
redirect_from:
- /library/test/Math/NumberTheory/least_common_multiple_test.cpp
- /library/test/Math/NumberTheory/least_common_multiple_test.cpp.html
title: test/Math/NumberTheory/least_common_multiple_test.cpp
---
