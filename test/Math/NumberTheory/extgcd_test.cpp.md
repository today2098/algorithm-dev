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
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/extgcd.hpp\"\n\n\n\n#include\
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
    \ |x|<|b|/g, |y|<|a|/g.\n}\n\n}  // namespace algorithm\n\n\n#line 2 \"test/Math/NumberTheory/extgcd_test.cpp\"\
    \n\n#include <gtest/gtest.h>\n\n#include <cmath>\n#include <cstdint>\n#include\
    \ <limits>\n#include <numeric>\n#include <random>\n\nclass ExtgcdTest : public\
    \ ::testing::Test {\nprotected:\n    std::mt19937_64 rng;\n\n    void SetUp()\
    \ override {\n        std::random_device seed;\n        rng.seed(seed());\n  \
    \  }\n};\n\nTEST_F(ExtgcdTest, Positive) {\n    using type = std::int32_t;\n \
    \   auto min = std::numeric_limits<type>::min();\n    auto max = std::numeric_limits<type>::max();\n\
    \    std::uniform_int_distribution<type> dist(min, max);\n\n    for(int i = 0;\
    \ i < 100; ++i) {\n        auto a = dist(rng);\n        auto b = dist(rng);\n\n\
    \        auto [x, y, g] = algorithm::extgcd(a, b);\n\n        EXPECT_TRUE(g >=\
    \ 0);\n        EXPECT_EQ(std::gcd(a, b), g);\n\n        EXPECT_TRUE(std::abs(x)\
    \ <= std::abs(b) / g);\n        EXPECT_TRUE(std::abs(y) <= std::abs(a) / g);\n\
    \        EXPECT_EQ((std::int64_t)a * x + (std::int64_t)b * y, g);\n    }\n}\n"
  code: "#include \"../../../algorithm/Math/NumberTheory/extgcd.hpp\"\n\n#include\
    \ <gtest/gtest.h>\n\n#include <cmath>\n#include <cstdint>\n#include <limits>\n\
    #include <numeric>\n#include <random>\n\nclass ExtgcdTest : public ::testing::Test\
    \ {\nprotected:\n    std::mt19937_64 rng;\n\n    void SetUp() override {\n   \
    \     std::random_device seed;\n        rng.seed(seed());\n    }\n};\n\nTEST_F(ExtgcdTest,\
    \ Positive) {\n    using type = std::int32_t;\n    auto min = std::numeric_limits<type>::min();\n\
    \    auto max = std::numeric_limits<type>::max();\n    std::uniform_int_distribution<type>\
    \ dist(min, max);\n\n    for(int i = 0; i < 100; ++i) {\n        auto a = dist(rng);\n\
    \        auto b = dist(rng);\n\n        auto [x, y, g] = algorithm::extgcd(a,\
    \ b);\n\n        EXPECT_TRUE(g >= 0);\n        EXPECT_EQ(std::gcd(a, b), g);\n\
    \n        EXPECT_TRUE(std::abs(x) <= std::abs(b) / g);\n        EXPECT_TRUE(std::abs(y)\
    \ <= std::abs(a) / g);\n        EXPECT_EQ((std::int64_t)a * x + (std::int64_t)b\
    \ * y, g);\n    }\n}\n"
  dependsOn:
  - algorithm/Math/NumberTheory/extgcd.hpp
  isVerificationFile: false
  path: test/Math/NumberTheory/extgcd_test.cpp
  requiredBy: []
  timestamp: '2025-08-24 09:11:22+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/Math/NumberTheory/extgcd_test.cpp
layout: document
redirect_from:
- /library/test/Math/NumberTheory/extgcd_test.cpp
- /library/test/Math/NumberTheory/extgcd_test.cpp.html
title: test/Math/NumberTheory/extgcd_test.cpp
---
