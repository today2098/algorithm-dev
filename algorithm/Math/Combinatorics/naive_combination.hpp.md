---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Combinatorics/naive_combination.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <cassert>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\nconstexpr long long mod_inv(long long a, int mod) {\n    assert(mod >=\
    \ 1);\n    long long b = mod, u = 1, v = 0;\n    while(b != 0) {\n        long\
    \ long t = a / b;\n        a -= b * t, u -= v * t;\n        std::swap(a, b), std::swap(u,\
    \ v);\n    }\n    if(u < 0) u += mod;\n    return u;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 8 \"algorithm/Math/Combinatorics/naive_combination.hpp\"\n\nnamespace\
    \ algorithm {\n\n// \u9806\u5217\uFF0EO(K).\nconstexpr long long nPk(long long\
    \ n, long long k) {\n    assert(n >= 0);\n    assert(k >= 0);\n    if(n < k) return\
    \ 0;\n    long long res = 1;\n    for(long long i = 0; i < k; ++i) res *= (n -\
    \ i);\n    return res;\n}\n\n// \u9806\u5217\uFF08mod\u4ED8\u304D\uFF09\uFF0E\
    O(K).\nconstexpr long long nPk(long long n, long long k, int mod) {\n    assert(n\
    \ >= 0);\n    assert(k >= 0);\n    assert(mod >= 1);\n    if(n < k) return 0;\n\
    \    n %= mod;\n    long long res = 1 % mod;\n    for(long long i = 0; i < k;\
    \ ++i) {\n        long long tmp = n - i;\n        if(tmp < 0) tmp += mod;\n  \
    \      res = res * tmp % mod;\n    }\n    return res;\n}\n\n// \u7D44\u5408\u305B\
    \uFF0EO(min(K,N-K)).\nconstexpr long long nCk(long long n, long long k) {\n  \
    \  assert(n >= 0);\n    assert(k >= 0);\n    if(n < k) return 0;\n    k = std::min(k,\
    \ n - k);\n    long long res = 1;\n    for(long long i = 0; i < k; ++i) res =\
    \ res * (n - i) / (i + 1);\n    return res;\n}\n\n// \u7D44\u5408\u305B\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0E\nconstexpr long long nCk(long long n, long long k,\
    \ int mod) {\n    assert(n >= 0);\n    assert(k >= 0);\n    assert(mod >= 1);\n\
    \    if(n < k) return 0;\n    k = std::min(k, n - k);\n    return nPk(n, k, mod)\
    \ * mod_inv(nPk(k, k, mod), mod) % mod;\n}\n\n// \u91CD\u8907\u7D44\u5408\u305B\
    \uFF0EO(min(N-1,K)).\nconstexpr long long nHk(long long n, long long k) {\n  \
    \  assert(n >= 0);\n    assert(k >= 0);\n    if(k == 0) return 1;\n    if(n ==\
    \ 0) return 0;\n    return nCk(k + n - 1, k);\n}\n\n// \u91CD\u8907\u7D44\u5408\
    \u305B\uFF08mod\u4ED8\u304D\uFF09\uFF0E\nconstexpr long long nHk(long long n,\
    \ long long k, int mod) {\n    assert(n >= 0);\n    assert(k >= 0);\n    assert(mod\
    \ >= 1);\n    if(k == 0) return 1 % mod;\n    if(n == 0) return 0;\n    return\
    \ nCk(k + n - 1, k, mod);\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_NAIVE_COMBINATION_HPP\n#define ALGORITHM_NAIVE_COMBINATION_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n\n#include \"../ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\n// \u9806\u5217\uFF0EO(K).\nconstexpr long long nPk(long\
    \ long n, long long k) {\n    assert(n >= 0);\n    assert(k >= 0);\n    if(n <\
    \ k) return 0;\n    long long res = 1;\n    for(long long i = 0; i < k; ++i) res\
    \ *= (n - i);\n    return res;\n}\n\n// \u9806\u5217\uFF08mod\u4ED8\u304D\uFF09\
    \uFF0EO(K).\nconstexpr long long nPk(long long n, long long k, int mod) {\n  \
    \  assert(n >= 0);\n    assert(k >= 0);\n    assert(mod >= 1);\n    if(n < k)\
    \ return 0;\n    n %= mod;\n    long long res = 1 % mod;\n    for(long long i\
    \ = 0; i < k; ++i) {\n        long long tmp = n - i;\n        if(tmp < 0) tmp\
    \ += mod;\n        res = res * tmp % mod;\n    }\n    return res;\n}\n\n// \u7D44\
    \u5408\u305B\uFF0EO(min(K,N-K)).\nconstexpr long long nCk(long long n, long long\
    \ k) {\n    assert(n >= 0);\n    assert(k >= 0);\n    if(n < k) return 0;\n  \
    \  k = std::min(k, n - k);\n    long long res = 1;\n    for(long long i = 0; i\
    \ < k; ++i) res = res * (n - i) / (i + 1);\n    return res;\n}\n\n// \u7D44\u5408\
    \u305B\uFF08mod\u4ED8\u304D\uFF09\uFF0E\nconstexpr long long nCk(long long n,\
    \ long long k, int mod) {\n    assert(n >= 0);\n    assert(k >= 0);\n    assert(mod\
    \ >= 1);\n    if(n < k) return 0;\n    k = std::min(k, n - k);\n    return nPk(n,\
    \ k, mod) * mod_inv(nPk(k, k, mod), mod) % mod;\n}\n\n// \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0EO(min(N-1,K)).\nconstexpr long long nHk(long long n, long long k)\
    \ {\n    assert(n >= 0);\n    assert(k >= 0);\n    if(k == 0) return 1;\n    if(n\
    \ == 0) return 0;\n    return nCk(k + n - 1, k);\n}\n\n// \u91CD\u8907\u7D44\u5408\
    \u305B\uFF08mod\u4ED8\u304D\uFF09\uFF0E\nconstexpr long long nHk(long long n,\
    \ long long k, int mod) {\n    assert(n >= 0);\n    assert(k >= 0);\n    assert(mod\
    \ >= 1);\n    if(k == 0) return 1 % mod;\n    if(n == 0) return 0;\n    return\
    \ nCk(k + n - 1, k, mod);\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  isVerificationFile: false
  path: algorithm/Math/Combinatorics/naive_combination.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/Combinatorics/naive_combination.hpp
layout: document
title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B"
---


## 概要

順列，組合せ，重複組合せの総数を $\mathcal{O}(K)$ で数え上げる．


#### 順列

$$
{}_n \mathrm{P}_k = n \times (n-1) \times (n-2) \times \cdots \times (n-k+1)
$$


#### 組合せ

$$
\begin{equation}
    {}_n \mathrm{C}_k = 
    \begin{cases}
        0 & \text{if $n<k$,} \\
        {}_n \mathrm{P}_k / k! & \text{otherwise}
    \end{cases}
    \notag
\end{equation}
$$


#### 重複組合せ

$$
\begin{equation}
    {}_n \mathrm{H}_k = 
    \begin{cases}
        1 & \text{if $k=0$,} \\
        0 & \text{if $n=0$ and $k>0$,} \\
        {}_{k+n-1} \mathrm{C}_k & \text{otherwise}
    \end{cases}
    \notag
\end{equation}
$$


## 参考文献

1. "数え上げ数学". Wikipedia. <https://ja.wikipedia.org/wiki/数え上げ数学>.
1. "組合せ数学". Wikipedia. <https://ja.wikipedia.org/wiki/組合せ数学>.
1. "順列". Wikipedia. <https://ja.wikipedia.org/wiki/順列>.
1. "組合せ (数学)". Wikipedia. <https://ja.wikipedia.org/wiki/組合せ_(数学)>.
1. "重複組合せ". Wikipedia. <https://ja.wikipedia.org/wiki/重複組合せ>.


## 問題

- "D - 表現の自由 ( Freedom of expression )". AtCoder Regular Contest 004. <https://atcoder.jp/contests/arc004/tasks/arc004_4>.
- "D - 多重ループ". AtCoder Beginner Contest 021. <https://atcoder.jp/contests/abc021/tasks/abc021_d>.
