---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/prime_factorize.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/totient.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n#include <ranges>\n#include\
    \ <type_traits>\n\n#line 1 \"algorithm/Math/NumberTheory/prime_factorize.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#line 9 \"algorithm/Math/NumberTheory/prime_factorize.hpp\"\
    \n#include <map>\n#include <vector>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\ntemplate <std::integral Res>\nconstexpr std::vector<Res> distinct_prime_factorize(std::uint64_t\
    \ n) {\n    std::vector<Res> factors;  // factors[]:=(\u81EA\u7136\u6570n\u306E\
    \u7D20\u56E0\u6570\u306E\u30EA\u30B9\u30C8).\n    factors.reserve(15);\n    if(n\
    \ % 2 == 0) {\n        factors.push_back(2);\n        auto c = std::countr_zero(n);\n\
    \        n >>= c;\n    }\n    for(std::uint64_t p = 3; p < 1ULL << 32 and p *\
    \ p <= n; p += 2) {\n        if(n % p != 0) continue;\n        factors.push_back(p);\n\
    \        do {\n            n /= p;\n        } while(n % p == 0);\n    }\n    if(n\
    \ > 1) factors.push_back(n);\n    return factors;\n}\n\ntemplate <std::integral\
    \ Res>\nstd::map<Res, int> prime_factorize(std::uint64_t n) {\n    std::map<Res,\
    \ int> res;  // res[p]:=(\u81EA\u7136\u6570n\u306B\u542B\u307E\u308C\u308B\u7D20\
    \u56E0\u6570p\u306E\u500B\u6570).\n    if(n % 2 == 0) {\n        auto c = std::countr_zero(n);\n\
    \        res.emplace_hint(res.end(), 2, c);\n        n >>= c;\n    }\n    for(std::uint64_t\
    \ p = 3; p < 1ULL << 32 and p * p <= n; p += 2) {\n        int c = 0;\n      \
    \  while(n % p == 0) n /= p, ++c;\n        if(c > 0) res.emplace_hint(res.end(),\
    \ p, c);\n    }\n    if(n > 1) res.emplace_hint(res.end(), n, 1);\n    return\
    \ res;\n}\n\n}  // namespace internal\n\n// \u81EA\u7136\u6570n\u306E\u7D20\u56E0\
    \u6570\u3092\u6C42\u3081\u308B\uFF0EO(\u221An).\ntemplate <std::integral Type>\n\
    constexpr std::vector<Type> distinct_prime_factorize(Type n) {\n    assert(n >\
    \ 0);\n    return internal::distinct_prime_factorize<Type>(n);\n}\n\n// \u7D20\
    \u56E0\u6570\u5206\u89E3\uFF0EO(\u221An).\ntemplate <std::integral Type>\nstd::map<Type,\
    \ int> prime_factorize(Type n) {\n    assert(n > 0);\n    return internal::prime_factorize<Type>(n);\n\
    }\n\n// \u9AD8\u901F\u7D04\u6570\u5217\u6319\uFF0E\ntemplate <typename Type>\n\
    std::vector<Type> divisors(const std::map<Type, int> &pf) {\n    std::vector<Type>\
    \ divs({1});\n    for(const auto &[p, c] : pf) {\n        const int sz = divs.size();\n\
    \        Type d = 1;\n        for(int i = 0; i < c; ++i) {\n            d *= p;\n\
    \            for(int j = 0; j < sz; ++j) divs.push_back(divs[j] * d);\n      \
    \  }\n    }\n    divs.shrink_to_fit();\n    std::sort(divs.begin(), divs.end());\n\
    \    return divs;\n}\n\n}  // namespace algorithm\n\n\n#line 11 \"algorithm/Math/NumberTheory/totient.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\ntemplate <std::ranges::range\
    \ R>\n    requires std::is_integral_v<std::ranges::range_value_t<R>>\nconstexpr\
    \ std::uint64_t totient(std::uint64_t n, const R &factors) {\n    for(auto p :\
    \ factors) n = n / p * (p - 1);\n    return n;\n}\n\nconstexpr std::uint64_t totient(std::uint64_t\
    \ n) { return totient(n, ::algorithm::internal::distinct_prime_factorize<std::uint64_t>(n));\
    \ }\n\n}  // namespace internal\n\n// \u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\
    \u30B7\u30A7\u30F3\u30C8\u95A2\u6570\uFF0En\u3068\u4E92\u3044\u306B\u7D20\u3067\
    \u3042\u308Bn\u672A\u6E80\u306E\u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\
    \u3081\u308B\uFF0E\ntemplate <std::integral Type>\nconstexpr std::uint64_t totient(Type\
    \ n) {\n    assert(n > 0);\n    return internal::totient(n);\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TOTIENT_HPP\n#define ALGORITHM_TOTIENT_HPP 1\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n#include <ranges>\n#include\
    \ <type_traits>\n\n#include \"prime_factorize.hpp\"\n\nnamespace algorithm {\n\
    \nnamespace internal {\n\ntemplate <std::ranges::range R>\n    requires std::is_integral_v<std::ranges::range_value_t<R>>\n\
    constexpr std::uint64_t totient(std::uint64_t n, const R &factors) {\n    for(auto\
    \ p : factors) n = n / p * (p - 1);\n    return n;\n}\n\nconstexpr std::uint64_t\
    \ totient(std::uint64_t n) { return totient(n, ::algorithm::internal::distinct_prime_factorize<std::uint64_t>(n));\
    \ }\n\n}  // namespace internal\n\n// \u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\
    \u30B7\u30A7\u30F3\u30C8\u95A2\u6570\uFF0En\u3068\u4E92\u3044\u306B\u7D20\u3067\
    \u3042\u308Bn\u672A\u6E80\u306E\u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\
    \u3081\u308B\uFF0E\ntemplate <std::integral Type>\nconstexpr std::uint64_t totient(Type\
    \ n) {\n    assert(n > 0);\n    return internal::totient(n);\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/NumberTheory/prime_factorize.hpp
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/totient.hpp
  requiredBy: []
  timestamp: '2025-08-30 05:48:04+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/NumberTheory/totient.hpp
layout: document
title: "Euler's Totient Function\uFF08\u30AA\u30A4\u30E9\u30FC\u306E\u30C8\u30FC\u30B7\
  \u30A7\u30F3\u30C8\u95A2\u6570\uFF09"
---

## 概要

自然数 $n$ に対して，$n$ と互いに素である $1$ 以上 $n$ 未満の自然数の個数を求める．

$$
\varphi(n) = \sum_{\substack{1 \leq m < n \\ \gcd(m,n) = 1}} 1.
$$

「オイラーの $\varphi$ 関数」とも呼ぶばれる．

## 参考

1. "オイラーのφ関数". Wikipedia. <https://ja.wikipedia.org/wiki/オイラーのφ関数>.
1. "オイラー関数の定義・性質4つとその証明". 数学の景色. <https://mathlandscape.com/euler-function/>.
