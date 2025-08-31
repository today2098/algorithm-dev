---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/Math/Combinatorics/naive_combination.hpp
    title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B"
  - icon: ':warning:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-NTL_1_B-mod_pow.test.cpp
    title: verify/aoj-NTL_1_B-mod_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#include\
    \ <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\n// return x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t mod) { return x % mod; }\n\n// return x mod m.\n\
    template <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type x,\
    \ std::int32_t mod) { return modulo(x, static_cast<std::uint32_t>(mod)); }\n\n\
    // return x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t mod) {\n    x %= static_cast<std::int64_t>(mod);\n\
    \    if(x < 0) x += static_cast<std::int64_t>(mod);\n    return x;\n}\n\n// return\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t mod) {\n    x %= mod;\n    if(x < 0) x += mod;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MODULO_HPP\n#define ALGORITHM_MODULO_HPP 1\n\n#include\
    \ <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\n// return x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t mod) { return x % mod; }\n\n// return x mod m.\n\
    template <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type x,\
    \ std::int32_t mod) { return modulo(x, static_cast<std::uint32_t>(mod)); }\n\n\
    // return x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t mod) {\n    x %= static_cast<std::int64_t>(mod);\n\
    \    if(x < 0) x += static_cast<std::int64_t>(mod);\n    return x;\n}\n\n// return\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t mod) {\n    x %= mod;\n    if(x < 0) x += mod;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modulo.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/Combinatorics/naive_combination.hpp
  timestamp: '2025-08-31 07:47:07+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/aoj-NTL_1_B-mod_pow.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modulo.hpp
layout: document
redirect_from:
- /library/algorithm/Math/ModularArithmetic/modulo.hpp
- /library/algorithm/Math/ModularArithmetic/modulo.hpp.html
title: algorithm/Math/ModularArithmetic/modulo.hpp
---
