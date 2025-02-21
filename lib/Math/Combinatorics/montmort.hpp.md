---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Math/Combinatorics/montmort.hpp\"\n\n#define ALGORTIHM_MONTMORT_HPP\
    \ 1\n\n#include <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace montmort {\n\n// COMPLETE_PERMUTATIONS_PROBABILITY:=(\u7121\u9650\
    \u500B\u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\u305F\u3068\u304D\u306B\
    \u5B8C\u5168\u9806\u5217\u3068\u306A\u308B\u78BA\u7387).\nconst double COMPLETE_PERMUTATIONS_PROBABILITY\
    \ = std::exp(-1.0);\n\n// \u5B8C\u5168\u9806\u5217\u306E\u7DCF\u6570\uFF0C\u30E2\
    \u30F3\u30E2\u30FC\u30EB\u6570\uFF0E\ntemplate <int mod>\nclass Montmort {\n \
    \   static_assert(mod >= 2);\n\n    static int s_sz;\n    static std::vector<long\
    \ long> s_montmort;  // m_montmort[k]:=(k\u9805\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\
    \u30EB\u6570).\n\n    Montmort() = default;\n    ~Montmort() = default;\n\npublic:\n\
    \    static constexpr int modulus() { return mod; }\n    // k\u9805\u76EE\u306E\
    \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    static\
    \ long long montmort(int k) {\n        assert(k >= 0);\n        if(s_sz <= k)\
    \ resize(k + 1);\n        return s_montmort[k];\n    }\n    static void resize(int\
    \ sz) {\n        assert(0 <= sz);\n        if(sz < 2) sz = 2;\n        s_montmort.resize(sz);\n\
    \        for(int i = s_sz; i < sz; ++i) s_montmort[i] = (i - 1) * (s_montmort[i\
    \ - 2] + s_montmort[i - 1]) % mod;\n        s_sz = sz;\n    }\n};\n\ntemplate\
    \ <int mod>\nint Montmort<mod>::s_sz = 2;\n\ntemplate <int mod>\nstd::vector<long\
    \ long> Montmort<mod>::s_montmort({1, 0});\n\n// \u30E2\u30F3\u30E2\u30FC\u30EB\
    \u6570\uFF0EO(K).\nconstexpr long long montmort(int k) {\n    assert(k >= 0);\n\
    \    if(k == 0) return 1;\n    long long a = 1, b = 0;\n    for(int i = 2; i <=\
    \ k; ++i) {\n        long long c = (i - 1) * (a + b);\n        a = b;\n      \
    \  b = c;\n    }\n    return b;\n}\n\n// \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0EO(K).\nconstexpr long long montmort(int k, int mod)\
    \ {\n    assert(k >= 0);\n    assert(mod >= 1);\n    if(k == 0) return 1 % mod;\n\
    \    long long a = 1, b = 0;\n    for(int i = 2; i <= k; ++i) {\n        long\
    \ long c = (i - 1) * (a + b) % mod;\n        a = b;\n        b = c;\n    }\n \
    \   return b;\n}\n\n}  // namespace montmort\n\n}  // namespace algorithm\n\n\
    #endif\n"
  code: "#ifndef ALGORITHM_MONTMORT_HPP\n#define ALGORTIHM_MONTMORT_HPP 1\n\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm {\n\n\
    namespace montmort {\n\n// COMPLETE_PERMUTATIONS_PROBABILITY:=(\u7121\u9650\u500B\
    \u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\u305F\u3068\u304D\u306B\u5B8C\
    \u5168\u9806\u5217\u3068\u306A\u308B\u78BA\u7387).\nconst double COMPLETE_PERMUTATIONS_PROBABILITY\
    \ = std::exp(-1.0);\n\n// \u5B8C\u5168\u9806\u5217\u306E\u7DCF\u6570\uFF0C\u30E2\
    \u30F3\u30E2\u30FC\u30EB\u6570\uFF0E\ntemplate <int mod>\nclass Montmort {\n \
    \   static_assert(mod >= 2);\n\n    static int s_sz;\n    static std::vector<long\
    \ long> s_montmort;  // m_montmort[k]:=(k\u9805\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\
    \u30EB\u6570).\n\n    Montmort() = default;\n    ~Montmort() = default;\n\npublic:\n\
    \    static constexpr int modulus() { return mod; }\n    // k\u9805\u76EE\u306E\
    \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    static\
    \ long long montmort(int k) {\n        assert(k >= 0);\n        if(s_sz <= k)\
    \ resize(k + 1);\n        return s_montmort[k];\n    }\n    static void resize(int\
    \ sz) {\n        assert(0 <= sz);\n        if(sz < 2) sz = 2;\n        s_montmort.resize(sz);\n\
    \        for(int i = s_sz; i < sz; ++i) s_montmort[i] = (i - 1) * (s_montmort[i\
    \ - 2] + s_montmort[i - 1]) % mod;\n        s_sz = sz;\n    }\n};\n\ntemplate\
    \ <int mod>\nint Montmort<mod>::s_sz = 2;\n\ntemplate <int mod>\nstd::vector<long\
    \ long> Montmort<mod>::s_montmort({1, 0});\n\n// \u30E2\u30F3\u30E2\u30FC\u30EB\
    \u6570\uFF0EO(K).\nconstexpr long long montmort(int k) {\n    assert(k >= 0);\n\
    \    if(k == 0) return 1;\n    long long a = 1, b = 0;\n    for(int i = 2; i <=\
    \ k; ++i) {\n        long long c = (i - 1) * (a + b);\n        a = b;\n      \
    \  b = c;\n    }\n    return b;\n}\n\n// \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0EO(K).\nconstexpr long long montmort(int k, int mod)\
    \ {\n    assert(k >= 0);\n    assert(mod >= 1);\n    if(k == 0) return 1 % mod;\n\
    \    long long a = 1, b = 0;\n    for(int i = 2; i <= k; ++i) {\n        long\
    \ long c = (i - 1) * (a + b) % mod;\n        a = b;\n        b = c;\n    }\n \
    \   return b;\n}\n\n}  // namespace montmort\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/montmort.hpp
  requiredBy: []
  timestamp: '2025-02-22 06:37:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/Combinatorics/montmort.hpp
layout: document
title: "\u5B8C\u5168\u9806\u5217\u306E\u7DCF\u6570\uFF0C\u30E2\u30F3\u30E2\u30FC\u30EB\
  \u6570"
---


## 概要

完全順列 (complete permutations) とは，整数 $1,2,3, \ldots, n$ を要素とする順列において，$i$ 番目の要素が $i$ でないものを指す．
攪乱順列 (derangement)，乱列，混乱順列ともいう．

そして，完全順列の総数をモンモール数 (Montmort number) という．

「$n$ 個の整数 $1,2,3, \ldots, n$ を要素とする順列において，$i$ 番目の要素が $i$ でないものの総数」を $a_n$ とおくと，$a_n$ は次の漸化式で表される．

$$
a_0 = 1, \
a_1 = 0, \
a_n = (n-1)(a_{n-2} + a_{n-1})
$$

モンモール数の日常生活への応用例としては，「プレゼント交換方法の通り数の計算」などが考えられる．


## 参考文献

1. "完全順列". Wikipedia. <https://ja.wikipedia.org/wiki/完全順列>.
1. "攪乱順列（完全順列）の個数を求める公式". 高校数学の美しい物語. <https://manabitimes.jp/math/612>.


## 問題

- "C - 高橋君、24歳". AtCoder Regular Contest 009. AtCoder. <https://atcoder.jp/contests/arc009/tasks/arc009_3>.
