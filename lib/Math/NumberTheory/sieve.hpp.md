---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-1276-sieve.test.cpp
    title: test/aoj-1276-sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ALDS1_1_C-sieve.test.cpp
    title: test/aoj-ALDS1_1_C-sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/sieve.md
    document_title: "Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
      \u30B9\u306E\u7BE9\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/NumberTheory/sieve.hpp\"\n\n\n\n/**\n * @brief\
    \ Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \uFF09\n * @docs docs/Math/NumberTheory/sieve.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <numeric>\n#include <vector>\n\n\
    namespace algorithm {\n\n// Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\uFF09.\nclass Sieve {\n    int m_mx;  // m_mx:=(\u7BE9\
    \u306B\u304B\u3051\u308B\u6700\u5927\u306E\u81EA\u7136\u6570).\n    // m_lpf[n]:=(\u81EA\
    \u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570). Least prime factor. m_lpf[n]==n\
    \ \u306E\u3068\u304D\uFF0Cn\u306F\u7D20\u6570\uFF0E\n    std::vector<int> m_lpf;\n\
    \npublic:\n    // constructor. n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u3092\u7BE9\
    \u306B\u304B\u3051\u308B\uFF0EO(N*loglogN).\n    Sieve() : Sieve(51e4) {}\n  \
    \  explicit Sieve(int n) : m_mx(n), m_lpf(n + 1, -1) {\n        assert(n >= 0);\n\
    \        std::iota(m_lpf.begin() + 2, m_lpf.end(), 2);\n        for(int p = 2;\
    \ p * p <= m_mx; ++p) {\n            if(m_lpf[p] == p) {\n                for(int\
    \ q = p * p; q <= m_mx; q += p) {\n                    if(m_lpf[q] == q) m_lpf[q]\
    \ = p;\n                }\n            }\n        }\n    }\n\n    // \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(1).\n    bool is_prime(int n) const {\n        assert(0 <=\
    \ n and n <= m_mx);\n        return m_lpf[n] == n;\n    }\n    // \u81EA\u7136\
    \u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ int lpf(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_lpf[n];\n    }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(logN).\n\
    \    std::map<int, int> prime_factorize(int n) const {\n        assert(1 <= n\
    \ and n <= m_mx);\n        std::map<int, int> res;\n        while(n > 1) {\n \
    \           res[m_lpf[n]]++;\n            n /= m_lpf[n];\n        }\n        return\
    \ res;\n    }\n    // \u9AD8\u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<int>\
    \ divisors(int n) const {\n        assert(1 <= n and n <= m_mx);\n        std::vector<int>\
    \ res({1});\n        const std::map<int, int> &&pf = prime_factorize(n);\n   \
    \     for(const auto &[p, cnt] : pf) {\n            const int sz = res.size();\n\
    \            int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n        \
    \        b *= p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j]\
    \ * b);\n            }\n        }\n        std::sort(res.begin(), res.end());\n\
    \        return res;\n    }\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\
    \u30A4\u95A2\u6570\uFF0En\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\
    \u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0E\n    int totient(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        const std::map<int,\
    \ int> &&pf = prime_factorize(n);\n        int res = n;\n        for(const auto\
    \ &[p, _] : pf) res -= res / p;\n        return res;\n    }\n    // \u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570\uFF0EO(N*loglogN).\n    std::vector<int> mobius() const\
    \ {\n        std::vector<int> res(m_mx + 1, 1);  // res[n]:=\u03BC(n).\n     \
    \   for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] == p) {\n      \
    \          res[p] = -1;\n                for(int q = 2 * p; q <= m_mx; q += p)\
    \ {\n                    if((q / p) % p == 0) res[q] = 0;  // n\u304C\u3042\u308B\
    \u7D20\u6570p\u30672\u56DE\u4EE5\u4E0A\u5272\u308A\u5207\u308C\u308B\u3068\u304D\
    \uFF0C\u03BC(n)=0.\n                    else res[q] = -res[q];            // n\u304C\
    k\u500B\u306E\u76F8\u7570\u306A\u308B\u7D20\u56E0\u6570\u3067\u5206\u89E3\u3067\
    \u304D\u308B\u3068\u304D\uFF0C\u03BC(n)=(-1)^k.\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_SIEVE_HPP\n#define ALGORITHM_SIEVE_HPP 1\n\n/**\n * @brief\
    \ Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
    \uFF09\n * @docs docs/Math/NumberTheory/sieve.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <numeric>\n#include <vector>\n\n\
    namespace algorithm {\n\n// Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\uFF09.\nclass Sieve {\n    int m_mx;  // m_mx:=(\u7BE9\
    \u306B\u304B\u3051\u308B\u6700\u5927\u306E\u81EA\u7136\u6570).\n    // m_lpf[n]:=(\u81EA\
    \u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570). Least prime factor. m_lpf[n]==n\
    \ \u306E\u3068\u304D\uFF0Cn\u306F\u7D20\u6570\uFF0E\n    std::vector<int> m_lpf;\n\
    \npublic:\n    // constructor. n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u3092\u7BE9\
    \u306B\u304B\u3051\u308B\uFF0EO(N*loglogN).\n    Sieve() : Sieve(51e4) {}\n  \
    \  explicit Sieve(int n) : m_mx(n), m_lpf(n + 1, -1) {\n        assert(n >= 0);\n\
    \        std::iota(m_lpf.begin() + 2, m_lpf.end(), 2);\n        for(int p = 2;\
    \ p * p <= m_mx; ++p) {\n            if(m_lpf[p] == p) {\n                for(int\
    \ q = p * p; q <= m_mx; q += p) {\n                    if(m_lpf[q] == q) m_lpf[q]\
    \ = p;\n                }\n            }\n        }\n    }\n\n    // \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(1).\n    bool is_prime(int n) const {\n        assert(0 <=\
    \ n and n <= m_mx);\n        return m_lpf[n] == n;\n    }\n    // \u81EA\u7136\
    \u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ int lpf(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_lpf[n];\n    }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(logN).\n\
    \    std::map<int, int> prime_factorize(int n) const {\n        assert(1 <= n\
    \ and n <= m_mx);\n        std::map<int, int> res;\n        while(n > 1) {\n \
    \           res[m_lpf[n]]++;\n            n /= m_lpf[n];\n        }\n        return\
    \ res;\n    }\n    // \u9AD8\u901F\u7D04\u6570\u5217\u6319\uFF0E\n    std::vector<int>\
    \ divisors(int n) const {\n        assert(1 <= n and n <= m_mx);\n        std::vector<int>\
    \ res({1});\n        const std::map<int, int> &&pf = prime_factorize(n);\n   \
    \     for(const auto &[p, cnt] : pf) {\n            const int sz = res.size();\n\
    \            int b = 1;\n            for(int i = 0; i < cnt; ++i) {\n        \
    \        b *= p;\n                for(int j = 0; j < sz; ++j) res.push_back(res[j]\
    \ * b);\n            }\n        }\n        std::sort(res.begin(), res.end());\n\
    \        return res;\n    }\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\
    \u30A4\u95A2\u6570\uFF0En\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\
    \u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0E\n    int totient(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        const std::map<int,\
    \ int> &&pf = prime_factorize(n);\n        int res = n;\n        for(const auto\
    \ &[p, _] : pf) res -= res / p;\n        return res;\n    }\n    // \u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570\uFF0EO(N*loglogN).\n    std::vector<int> mobius() const\
    \ {\n        std::vector<int> res(m_mx + 1, 1);  // res[n]:=\u03BC(n).\n     \
    \   for(int p = 2; p <= m_mx; ++p) {\n            if(m_lpf[p] == p) {\n      \
    \          res[p] = -1;\n                for(int q = 2 * p; q <= m_mx; q += p)\
    \ {\n                    if((q / p) % p == 0) res[q] = 0;  // n\u304C\u3042\u308B\
    \u7D20\u6570p\u30672\u56DE\u4EE5\u4E0A\u5272\u308A\u5207\u308C\u308B\u3068\u304D\
    \uFF0C\u03BC(n)=0.\n                    else res[q] = -res[q];            // n\u304C\
    k\u500B\u306E\u76F8\u7570\u306A\u308B\u7D20\u56E0\u6570\u3067\u5206\u89E3\u3067\
    \u304D\u308B\u3068\u304D\uFF0C\u03BC(n)=(-1)^k.\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/NumberTheory/sieve.hpp
  requiredBy: []
  timestamp: '2024-09-07 11:53:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-1276-sieve.test.cpp
  - test/aoj-ALDS1_1_C-sieve.test.cpp
documentation_of: lib/Math/NumberTheory/sieve.hpp
layout: document
redirect_from:
- /library/lib/Math/NumberTheory/sieve.hpp
- /library/lib/Math/NumberTheory/sieve.hpp.html
title: "Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
  \u7BE9\uFF09"
---
## 概要

$1$ 以上 $N$ 以下の自然数の中からすべての素数を発見する．

アルゴリズムの計算量は $\mathcal{O}(N \log \log N)$ となる．

本実装では，各自然数に対して最小の素因数 (LPF: Least Prime Factor) を求めており，「素数判定」に加え「高速素因数分解」などができる．


## 参考文献

1. rsk0315_h4x. "エラトステネスの篩に基づく高速な素因数分解". Qiita. <https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409>.
1. drken. "エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜". Qiita. <https://qiita.com/drken/items/3beb679e54266f20ab63>.
1. rsk0315. "素因数分解を <O(n), O(log(n)/log(log(n)))> で行う". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2023/05/03/133029>.
