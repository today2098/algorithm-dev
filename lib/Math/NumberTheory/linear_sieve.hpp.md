---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-1276-linear_sieve.test.cpp
    title: test/aoj-1276-linear_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ALDS1_1_C-linear_sieve.test.cpp
    title: test/aoj-ALDS1_1_C-linear_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/linear_sieve.md
    document_title: "\u7DDA\u5F62\u7BE9"
    links: []
  bundledCode: "#line 1 \"lib/Math/NumberTheory/linear_sieve.hpp\"\n\n\n\n/**\n *\
    \ @brief \u7DDA\u5F62\u7BE9\n * @docs docs/Math/NumberTheory/linear_sieve.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <map>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// \u7DDA\u5F62\u7BE9\uFF0E\nclass LinearSieve {\n\
    \    int m_mx;  // m_mx:=(\u7BE9\u306B\u304B\u3051\u308B\u6700\u5927\u306E\u81EA\
    \u7136\u6570).\n    // m_lpf[n]:=(\u81EA\u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\
    \u6570). Least prime factor. m_lpf[n]==n \u306E\u3068\u304D\uFF0Cn\u306F\u7D20\
    \u6570\uFF0E\n    std::vector<int> m_lpf;\n    std::vector<int> m_primes;  //\
    \ m_primes[]:=(\u81EA\u7136\u6570n\u4EE5\u4E0B\u306E\u7D20\u6570\u30EA\u30B9\u30C8\
    ).\n\npublic:\n    // constructor. n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u3092\
    \u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N).\n    LinearSieve() : LinearSieve(51e4)\
    \ {}\n    explicit LinearSieve(int n) : m_mx(n), m_lpf(n + 1, -1) {\n        assert(n\
    \ >= 0);\n        for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] ==\
    \ -1) {\n                m_lpf[p] = p;\n                m_primes.push_back(p);\n\
    \            }\n            for(int prime : m_primes) {\n                if(prime\
    \ > m_lpf[p] or (long long) prime * p > m_mx) break;\n                m_lpf[prime\
    \ * p] = prime;\n            }\n        }\n    }\n\n    // \u7D20\u6570\u5224\u5B9A\
    \uFF0EO(1).\n    bool is_prime(int n) const {\n        assert(0 <= n and n <=\
    \ m_mx);\n        return m_lpf[n] == n;\n    }\n    // \u81EA\u7136\u6570n\u306E\
    \u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    int lpf(int n)\
    \ const {\n        assert(0 <= n and n <= m_mx);\n        return m_lpf[n];\n \
    \   }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(logN).\n    std::map<int,\
    \ int> prime_factorize(int n) const {\n        assert(1 <= n and n <= m_mx);\n\
    \        std::map<int, int> res;\n        while(n > 1) {\n            res[m_lpf[n]]++;\n\
    \            n /= m_lpf[n];\n        }\n        return res;\n    }\n    // \u9AD8\
    \u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<int> divisors(int n) const\
    \ {\n        assert(1 <= n and n <= m_mx);\n        std::vector<int> res({1});\n\
    \        const std::map<int, int> &&pf = prime_factorize(n);\n        for(const\
    \ auto &[p, cnt] : pf) {\n            const int sz = res.size();\n           \
    \ int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n                b *=\
    \ p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);\n\
    \            }\n        }\n        std::sort(res.begin(), res.end());\n      \
    \  return res;\n    }\n    // \u7D20\u6570\u30EA\u30B9\u30C8\u3092\u53C2\u7167\
    \u3059\u308B\uFF0EO(1).\n    const std::vector<int> &primes() const { return m_primes;\
    \ }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LINEAR_SIEVE_HPP\n#define ALGORITHM_LINEAR_SIEVE_HPP 1\n\
    \n/**\n * @brief \u7DDA\u5F62\u7BE9\n * @docs docs/Math/NumberTheory/linear_sieve.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <map>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// \u7DDA\u5F62\u7BE9\uFF0E\nclass LinearSieve {\n\
    \    int m_mx;  // m_mx:=(\u7BE9\u306B\u304B\u3051\u308B\u6700\u5927\u306E\u81EA\
    \u7136\u6570).\n    // m_lpf[n]:=(\u81EA\u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\
    \u6570). Least prime factor. m_lpf[n]==n \u306E\u3068\u304D\uFF0Cn\u306F\u7D20\
    \u6570\uFF0E\n    std::vector<int> m_lpf;\n    std::vector<int> m_primes;  //\
    \ m_primes[]:=(\u81EA\u7136\u6570n\u4EE5\u4E0B\u306E\u7D20\u6570\u30EA\u30B9\u30C8\
    ).\n\npublic:\n    // constructor. n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u3092\
    \u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N).\n    LinearSieve() : LinearSieve(51e4)\
    \ {}\n    explicit LinearSieve(int n) : m_mx(n), m_lpf(n + 1, -1) {\n        assert(n\
    \ >= 0);\n        for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] ==\
    \ -1) {\n                m_lpf[p] = p;\n                m_primes.push_back(p);\n\
    \            }\n            for(int prime : m_primes) {\n                if(prime\
    \ > m_lpf[p] or (long long) prime * p > m_mx) break;\n                m_lpf[prime\
    \ * p] = prime;\n            }\n        }\n    }\n\n    // \u7D20\u6570\u5224\u5B9A\
    \uFF0EO(1).\n    bool is_prime(int n) const {\n        assert(0 <= n and n <=\
    \ m_mx);\n        return m_lpf[n] == n;\n    }\n    // \u81EA\u7136\u6570n\u306E\
    \u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    int lpf(int n)\
    \ const {\n        assert(0 <= n and n <= m_mx);\n        return m_lpf[n];\n \
    \   }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(logN).\n    std::map<int,\
    \ int> prime_factorize(int n) const {\n        assert(1 <= n and n <= m_mx);\n\
    \        std::map<int, int> res;\n        while(n > 1) {\n            res[m_lpf[n]]++;\n\
    \            n /= m_lpf[n];\n        }\n        return res;\n    }\n    // \u9AD8\
    \u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<int> divisors(int n) const\
    \ {\n        assert(1 <= n and n <= m_mx);\n        std::vector<int> res({1});\n\
    \        const std::map<int, int> &&pf = prime_factorize(n);\n        for(const\
    \ auto &[p, cnt] : pf) {\n            const int sz = res.size();\n           \
    \ int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n                b *=\
    \ p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j] * b);\n\
    \            }\n        }\n        std::sort(res.begin(), res.end());\n      \
    \  return res;\n    }\n    // \u7D20\u6570\u30EA\u30B9\u30C8\u3092\u53C2\u7167\
    \u3059\u308B\uFF0EO(1).\n    const std::vector<int> &primes() const { return m_primes;\
    \ }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/NumberTheory/linear_sieve.hpp
  requiredBy: []
  timestamp: '2024-09-07 11:53:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-1276-linear_sieve.test.cpp
  - test/aoj-ALDS1_1_C-linear_sieve.test.cpp
documentation_of: lib/Math/NumberTheory/linear_sieve.hpp
layout: document
redirect_from:
- /library/lib/Math/NumberTheory/linear_sieve.hpp
- /library/lib/Math/NumberTheory/linear_sieve.hpp.html
title: "\u7DDA\u5F62\u7BE9"
---
## 概要

$1$ 以上 $N$ 以下の自然数の中からすべての素数を発見する．

アルゴリズムの計算量は $\mathcal{O}(N)$ となる．

通常の「エラトステネスの篩」より高速だが，素数リストを作成する必要があり，その分空間計算量がかかる．


## 参考文献

1. "線形篩". 37zigenのHP. <https://37zigen.com/linear-sieve/>.
