---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-1276-linear_sieve.test.cpp
    title: verify/aoj-1276-linear_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_1_C-linear_sieve.test.cpp
    title: verify/aoj-ALDS1_1_C-linear_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/linear_sieve.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <map>\n#include <ranges>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u7DDA\u5F62\u7BE9\uFF0E\nclass LinearSieve\
    \ {\n    int m_sz;\n    // m_lpf[i]:=(\u6B63\u306E\u5947\u65702*i+1\u306E\u6700\
    \u5C0F\u7D20\u56E0\u6570). Least prime factor. m_lpf[i]==2*i+1 \u306E\u3068\u304D\
    \uFF0C2*i+1\u306F\u7D20\u6570\uFF0E\n    std::vector<int> m_lpf;\n    std::vector<int>\
    \ m_primes;  // m_primes[]:=(\u81EA\u7136\u6570n\u672A\u6E80\u306E\u7D20\u6570\
    \u30EA\u30B9\u30C8).\n\npublic:\n    // constructor. n\u672A\u6E80\u306E\u81EA\
    \u7136\u6570\u3092\u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N).\n    LinearSieve()\
    \ : LinearSieve(0) {}\n    explicit LinearSieve(int n) : m_sz(n), m_lpf(n / 2,\
    \ -1) {\n        assert(n >= 0);\n        if(m_sz <= 2) return;\n        m_primes.push_back(2);\n\
    \        int p = 3;\n        for(int i = 1, end = m_lpf.size(); i < end; ++i)\
    \ {\n            if(m_lpf[i] == -1) {\n                m_lpf[i] = p;\n       \
    \         m_primes.push_back(p);\n            }\n            int limit = (m_sz\
    \ - 1) / p;\n            for(const auto &prime : m_primes | std::ranges::views::drop(1)\
    \ | std::ranges::views::take_while([&](int prime) -> bool { return prime <= m_lpf[i]\
    \ and prime <= limit; })) m_lpf[p * prime / 2] = prime;\n            p += 2;\n\
    \        }\n        m_primes.shrink_to_fit();\n    }\n\n    int size() const {\
    \ return m_sz; }\n    // \u7D20\u6570\u5224\u5B9A\uFF0EO(1).\n    bool is_prime(int\
    \ n) const {\n        assert(0 <= n and n < size());\n        if(n == 2) return\
    \ true;\n        if(n % 2 == 0) return false;\n        return m_lpf[n / 2] ==\
    \ n;\n    }\n    // \u81EA\u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    int lpf(int n) const {\n        assert(0\
    \ <= n and n < size());\n        if(n < 2) return -1;\n        if(n % 2 == 0)\
    \ return 2;\n        return m_lpf[n / 2];\n    }\n    // \u9AD8\u901F\u7D20\u56E0\
    \u6570\u5206\u89E3\uFF0EO(log N).\n    std::map<int, int> prime_factorize(int\
    \ n) const {\n        assert(1 <= n and n < size());\n        std::map<int, int>\
    \ res;\n        for(; n % 2 == 0; n /= 2) ++res[2];\n        for(; n > 1; n /=\
    \ m_lpf[n / 2]) ++res[m_lpf[n / 2]];\n        return res;\n    }\n    // \u7D20\
    \u6570\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\uFF0EO(1).\n    const std::vector<int>\
    \ &primes() const { return m_primes; }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LINEAR_SIEVE_HPP\n#define ALGORITHM_LINEAR_SIEVE_HPP 1\n\
    \n#include <algorithm>\n#include <cassert>\n#include <map>\n#include <ranges>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7DDA\u5F62\u7BE9\uFF0E\nclass\
    \ LinearSieve {\n    int m_sz;\n    // m_lpf[i]:=(\u6B63\u306E\u5947\u65702*i+1\u306E\
    \u6700\u5C0F\u7D20\u56E0\u6570). Least prime factor. m_lpf[i]==2*i+1 \u306E\u3068\
    \u304D\uFF0C2*i+1\u306F\u7D20\u6570\uFF0E\n    std::vector<int> m_lpf;\n    std::vector<int>\
    \ m_primes;  // m_primes[]:=(\u81EA\u7136\u6570n\u672A\u6E80\u306E\u7D20\u6570\
    \u30EA\u30B9\u30C8).\n\npublic:\n    // constructor. n\u672A\u6E80\u306E\u81EA\
    \u7136\u6570\u3092\u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N).\n    LinearSieve()\
    \ : LinearSieve(0) {}\n    explicit LinearSieve(int n) : m_sz(n), m_lpf(n / 2,\
    \ -1) {\n        assert(n >= 0);\n        if(m_sz <= 2) return;\n        m_primes.push_back(2);\n\
    \        int p = 3;\n        for(int i = 1, end = m_lpf.size(); i < end; ++i)\
    \ {\n            if(m_lpf[i] == -1) {\n                m_lpf[i] = p;\n       \
    \         m_primes.push_back(p);\n            }\n            int limit = (m_sz\
    \ - 1) / p;\n            for(const auto &prime : m_primes | std::ranges::views::drop(1)\
    \ | std::ranges::views::take_while([&](int prime) -> bool { return prime <= m_lpf[i]\
    \ and prime <= limit; })) m_lpf[p * prime / 2] = prime;\n            p += 2;\n\
    \        }\n        m_primes.shrink_to_fit();\n    }\n\n    int size() const {\
    \ return m_sz; }\n    // \u7D20\u6570\u5224\u5B9A\uFF0EO(1).\n    bool is_prime(int\
    \ n) const {\n        assert(0 <= n and n < size());\n        if(n == 2) return\
    \ true;\n        if(n % 2 == 0) return false;\n        return m_lpf[n / 2] ==\
    \ n;\n    }\n    // \u81EA\u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    int lpf(int n) const {\n        assert(0\
    \ <= n and n < size());\n        if(n < 2) return -1;\n        if(n % 2 == 0)\
    \ return 2;\n        return m_lpf[n / 2];\n    }\n    // \u9AD8\u901F\u7D20\u56E0\
    \u6570\u5206\u89E3\uFF0EO(log N).\n    std::map<int, int> prime_factorize(int\
    \ n) const {\n        assert(1 <= n and n < size());\n        std::map<int, int>\
    \ res;\n        for(; n % 2 == 0; n /= 2) ++res[2];\n        for(; n > 1; n /=\
    \ m_lpf[n / 2]) ++res[m_lpf[n / 2]];\n        return res;\n    }\n    // \u7D20\
    \u6570\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\uFF0EO(1).\n    const std::vector<int>\
    \ &primes() const { return m_primes; }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/linear_sieve.hpp
  requiredBy: []
  timestamp: '2025-07-19 11:17:22+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_1_C-linear_sieve.test.cpp
  - verify/aoj-1276-linear_sieve.test.cpp
documentation_of: algorithm/Math/NumberTheory/linear_sieve.hpp
layout: document
title: "\u7DDA\u5F62\u7BE9"
---


## 概要

$N$ 未満の自然数の中からすべての素数を発見し，素数リストを作成する．

アルゴリズムの計算量は $\mathcal{O}(N)$ ．

時間計算量は，通常の「エラトステネスの篩」の $\mathcal{O}(N \log \log N)$ と比較すると小さい．
一方，素数をリストなどでもつ必要があり，その分の空間計算量が必要となる．


## 参考

1. "線形篩". 37zigenのHP. <https://37zigen.com/linear-sieve/>.
