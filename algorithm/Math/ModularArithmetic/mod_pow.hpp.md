---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: algorithm/Math/ModularArithmetic/modulo.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
    title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
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
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\n\n\n#line 7 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \n#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return x mod m.\ntemplate\
    \ <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t\
    \ mod) { return x % mod; }\n\n// return x mod m.\ntemplate <std::unsigned_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::int32_t mod) { return modulo(x,\
    \ static_cast<std::uint32_t>(mod)); }\n\n// return x mod m.\ntemplate <std::signed_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t mod) {\n    x %=\
    \ static_cast<std::int64_t>(mod);\n    if(x < 0) x += static_cast<std::int64_t>(mod);\n\
    \    return x;\n}\n\n// return x mod m.\ntemplate <std::signed_integral Type>\n\
    constexpr std::uint32_t modulo(Type x, std::int32_t mod) {\n    x %= mod;\n  \
    \  if(x < 0) x += mod;\n    return x;\n}\n\n}  // namespace internal\n\n}  //\
    \ namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return pair of (x, g)\
    \ s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.\nconstexpr std::pair<std::uint32_t,\
    \ std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {\n    if(a == 0) return\
    \ {0, m};\n    std::uint32_t s = m, t = a;\n    std::uint32_t u = m, v = 1;\n\
    \    while(true) {\n        std::uint32_t q = s / t;\n        s -= t * q, u -=\
    \ v * q;\n        if(s == 0) return {v, t};\n        q = t / s;\n        t -=\
    \ s * q, v += (m - u) * q;\n        if(t == 0) return {u, s};\n    }\n}\n\n} \
    \ // namespace internal\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\ntemplate <std::integral Type>\nconstexpr std::int64_t mod_inv(Type a, std::int32_t\
    \ m) {\n    assert(m >= 1);\n    auto [x, g] = internal::mod_inv(::algorithm::internal::modulo(a,\
    \ m), m);\n    assert(g == 1);\n    return x;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\nnamespace algorithm\
    \ {\n\nnamespace internal {\n\n// return n^k mod m.\nconstexpr std::uint32_t mod_pow(std::uint64_t\
    \ n, unsigned long long k, std::uint32_t mod) {\n    std::uint64_t res = 1;\n\
    \    for(; k > 0; k >>= 1) {\n        if(k & 1ULL) res = res * n % mod;\n    \
    \    n = n * n % mod;\n    }\n    return res;\n}\n\n}  // namespace internal\n\
    \n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0E\
    O(log k).\ntemplate <std::integral Type>\nconstexpr std::int64_t mod_pow(Type\
    \ n, long long k, std::int32_t mod) {\n    assert(mod >= 1);\n    auto r = ::algorithm::internal::modulo(n,\
    \ mod);\n    if(k < 0) {\n        auto [x, g] = ::algorithm::internal::mod_inv(r,\
    \ mod);\n        assert(g == 1);\n        r = x, k = -k;\n    }\n    return internal::mod_pow(r,\
    \ k, mod);\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n\n#include \"mod_inv.hpp\"\
    \n#include \"modulo.hpp\"\n\nnamespace algorithm {\n\nnamespace internal {\n\n\
    // return n^k mod m.\nconstexpr std::uint32_t mod_pow(std::uint64_t n, unsigned\
    \ long long k, std::uint32_t mod) {\n    std::uint64_t res = 1;\n    for(; k >\
    \ 0; k >>= 1) {\n        if(k & 1ULL) res = res * n % mod;\n        n = n * n\
    \ % mod;\n    }\n    return res;\n}\n\n}  // namespace internal\n\n// \u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(log k).\ntemplate\
    \ <std::integral Type>\nconstexpr std::int64_t mod_pow(Type n, long long k, std::int32_t\
    \ mod) {\n    assert(mod >= 1);\n    auto r = ::algorithm::internal::modulo(n,\
    \ mod);\n    if(k < 0) {\n        auto [x, g] = ::algorithm::internal::mod_inv(r,\
    \ mod);\n        assert(g == 1);\n        r = x, k = -k;\n    }\n    return internal::mod_pow(r,\
    \ k, mod);\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/mod_pow.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  timestamp: '2025-08-31 12:12:17+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/aoj-NTL_1_B-mod_pow.test.cpp
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/mod_pow.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
---


## 概要

$n, k \in \mathbb{Z}, m \in \mathbb{N}$ について，$n^k \bmod m$ を求める．

本実装では「繰り返し二乗法」を用いており，計算量は $\mathcal{O}(\log k)$ である．

## 問題

- "B - n^p mod m". AtCoder Typical Contest 002. AtCoder. <https://atcoder.jp/contests/atc002/tasks/atc002_b>.
