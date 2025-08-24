---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"algorithm/internal/absolute.hpp\"\n\n\n\n#include <concepts>\n\
    #include <type_traits>\n\nnamespace algorithm {\n\nnamespace internal {\n\n//\
    \ Returns the absolute value as type Res.\ntemplate <std::integral Res, std::unsigned_integral\
    \ Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n\
    \    return static_cast<Res>(n);\n}\n\n// Returns the absolute value as type Res.\n\
    template <std::integral Res, std::signed_integral Type>\nconstexpr Res abs(Type\
    \ n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    return static_cast<Res>(std::make_unsigned_t<Type>(n\
    \ < 0 ? -n : n));\n}\n\n}  // namespace internal\n\n}  // namespace algorithm\n\
    \n\n#line 2 \"test/internal/absolute_test.cpp\"\n\n#include <gtest/gtest.h>\n\n\
    #include <cstdint>\n#include <limits>\n#include <tuple>\n#include <vector>\n\n\
    TEST(AbsTest, CornerCase) {\n    using type = std::int32_t;\n    using res = std::int32_t;\n\
    \n    auto min = std::numeric_limits<type>::min();  // -2^31 = -2'147'483'648.\n\
    \    EXPECT_EQ(min, algorithm::internal::abs<res>(min));\n}\n\nTEST(AbsTest, Unsigned)\
    \ {\n    using type = std::uint32_t;\n    using res = std::uint64_t;\n\n    using\
    \ tuple = std::tuple<type, res>;  // tuple of (arg, expected).\n    std::vector<tuple>\
    \ table(\n        {{10, 10}});\n\n    for(const auto &[arg, expected] : table)\
    \ {\n        auto actual = algorithm::internal::abs<res>(arg);\n\n        EXPECT_TRUE((std::is_same_v<res,\
    \ decltype(actual)>));\n        EXPECT_EQ(expected, actual);\n    }\n}\n\nTEST(AbsTest,\
    \ Signed) {\n    using type = std::int32_t;\n    using res = std::uint64_t;\n\n\
    \    using tuple = std::tuple<type, res>;  // tuple of (arg, expected).\n    std::vector<tuple>\
    \ table(\n        {{10, 10},\n         {-10, 10},\n         {std::numeric_limits<type>::min(),\
    \ 1ULL << 31}});\n\n    for(const auto &[arg, expected] : table) {\n        auto\
    \ actual = algorithm::internal::abs<res>(arg);\n\n        EXPECT_TRUE((std::is_same_v<res,\
    \ decltype(actual)>));\n        EXPECT_EQ(expected, actual);\n    }\n}\n"
  code: "#include \"../../algorithm/internal/absolute.hpp\"\n\n#include <gtest/gtest.h>\n\
    \n#include <cstdint>\n#include <limits>\n#include <tuple>\n#include <vector>\n\
    \nTEST(AbsTest, CornerCase) {\n    using type = std::int32_t;\n    using res =\
    \ std::int32_t;\n\n    auto min = std::numeric_limits<type>::min();  // -2^31\
    \ = -2'147'483'648.\n    EXPECT_EQ(min, algorithm::internal::abs<res>(min));\n\
    }\n\nTEST(AbsTest, Unsigned) {\n    using type = std::uint32_t;\n    using res\
    \ = std::uint64_t;\n\n    using tuple = std::tuple<type, res>;  // tuple of (arg,\
    \ expected).\n    std::vector<tuple> table(\n        {{10, 10}});\n\n    for(const\
    \ auto &[arg, expected] : table) {\n        auto actual = algorithm::internal::abs<res>(arg);\n\
    \n        EXPECT_TRUE((std::is_same_v<res, decltype(actual)>));\n        EXPECT_EQ(expected,\
    \ actual);\n    }\n}\n\nTEST(AbsTest, Signed) {\n    using type = std::int32_t;\n\
    \    using res = std::uint64_t;\n\n    using tuple = std::tuple<type, res>;  //\
    \ tuple of (arg, expected).\n    std::vector<tuple> table(\n        {{10, 10},\n\
    \         {-10, 10},\n         {std::numeric_limits<type>::min(), 1ULL << 31}});\n\
    \n    for(const auto &[arg, expected] : table) {\n        auto actual = algorithm::internal::abs<res>(arg);\n\
    \n        EXPECT_TRUE((std::is_same_v<res, decltype(actual)>));\n        EXPECT_EQ(expected,\
    \ actual);\n    }\n}\n"
  dependsOn:
  - algorithm/internal/absolute.hpp
  isVerificationFile: false
  path: test/internal/absolute_test.cpp
  requiredBy: []
  timestamp: '2025-08-23 10:05:58+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/internal/absolute_test.cpp
layout: document
redirect_from:
- /library/test/internal/absolute_test.cpp
- /library/test/internal/absolute_test.cpp.html
title: test/internal/absolute_test.cpp
---
