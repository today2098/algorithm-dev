---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yuki-117-combination.test.cpp
    title: verify/yuki-117-combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Math/Combinatorics/combination.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int mod>\n\
    class Combination {\n    static_assert(mod >= 2);\n\n    int m_sz;\n    std::vector<long\
    \ long> m_fact;      // m_fact[n]:=(n\u306E\u968E\u4E57).\n    std::vector<long\
    \ long> m_inv;       // m_inv[n]:=(n\u306E\u9006\u5143).\n    std::vector<long\
    \ long> m_inv_fact;  // m_inv_fact[n]:=(n\u306E\u968E\u4E57\u306E\u9006\u5143\
    ).\n\npublic:\n    Combination() : Combination(2) {}\n    explicit Combination(int\
    \ n) : m_sz(n), m_fact(n), m_inv(n), m_inv_fact(n) {\n        assert(n >= 2);\n\
    \        m_fact[0] = m_fact[1] = 1;\n        m_inv[1] = 1;\n        m_inv_fact[0]\
    \ = m_inv_fact[1] = 1;\n        for(int i = 2; i < m_sz; ++i) {\n            m_fact[i]\
    \ = m_fact[i - 1] * i % mod;\n            m_inv[i] = mod - m_inv[mod % i] * (mod\
    \ / i) % mod;\n            m_inv_fact[i] = m_inv_fact[i - 1] * m_inv[i] % mod;\n\
    \        }\n    }\n\n    static constexpr int modulus() { return mod; }\n    //\
    \ \u968E\u4E57\uFF0EO(1).\n    int size() const { return m_sz; }\n    long long\
    \ factorial(int n) const {\n        assert(0 <= n and n < size());\n        return\
    \ m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n    long long inverse(int\
    \ n) const {\n        assert(1 <= n and n < size());\n        return m_inv[n];\n\
    \    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    long long inverse_factorial(int\
    \ n) const {\n        assert(0 <= n and n < size());\n        return m_inv_fact[n];\n\
    \    }\n    // \u9806\u5217\uFF0EO(1).\n    long long nPk(int n, int k) const\
    \ {\n        assert(0 <= n and n < size());\n        assert(k >= 0);\n       \
    \ if(n < k) return 0;\n        return m_fact[n] * m_inv_fact[n - k] % mod;\n \
    \   }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long long nCk(int n, int k) const\
    \ {\n        assert(0 <= n and n < size());\n        assert(k >= 0);\n       \
    \ if(n < k) return 0;\n        return m_fact[n] * m_inv_fact[n - k] % mod * m_inv_fact[k]\
    \ % mod;\n    }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(1).\n    long long\
    \ nHk(int n, int k) const {\n        assert(n >= 0);\n        assert(k >= 0);\n\
    \        if(k == 0) return 1;\n        if(n == 0) return 0;\n        return nCk(k\
    \ + n - 1, k);\n    }\n};\n\nusing Combination998244353 = Combination<998'244'353>;\n\
    using Combination1000000007 = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_COMBINATION_HPP\n#define ALGORITHM_COMBINATION_HPP 1\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int\
    \ mod>\nclass Combination {\n    static_assert(mod >= 2);\n\n    int m_sz;\n \
    \   std::vector<long long> m_fact;      // m_fact[n]:=(n\u306E\u968E\u4E57).\n\
    \    std::vector<long long> m_inv;       // m_inv[n]:=(n\u306E\u9006\u5143).\n\
    \    std::vector<long long> m_inv_fact;  // m_inv_fact[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\npublic:\n    Combination() : Combination(2) {}\n    explicit\
    \ Combination(int n) : m_sz(n), m_fact(n), m_inv(n), m_inv_fact(n) {\n       \
    \ assert(n >= 2);\n        m_fact[0] = m_fact[1] = 1;\n        m_inv[1] = 1;\n\
    \        m_inv_fact[0] = m_inv_fact[1] = 1;\n        for(int i = 2; i < m_sz;\
    \ ++i) {\n            m_fact[i] = m_fact[i - 1] * i % mod;\n            m_inv[i]\
    \ = mod - m_inv[mod % i] * (mod / i) % mod;\n            m_inv_fact[i] = m_inv_fact[i\
    \ - 1] * m_inv[i] % mod;\n        }\n    }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    int size() const { return\
    \ m_sz; }\n    long long factorial(int n) const {\n        assert(0 <= n and n\
    \ < size());\n        return m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n\
    \    long long inverse(int n) const {\n        assert(1 <= n and n < size());\n\
    \        return m_inv[n];\n    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0E\
    O(1).\n    long long inverse_factorial(int n) const {\n        assert(0 <= n and\
    \ n < size());\n        return m_inv_fact[n];\n    }\n    // \u9806\u5217\uFF0E\
    O(1).\n    long long nPk(int n, int k) const {\n        assert(0 <= n and n <\
    \ size());\n        assert(k >= 0);\n        if(n < k) return 0;\n        return\
    \ m_fact[n] * m_inv_fact[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\uFF0E\
    O(1).\n    long long nCk(int n, int k) const {\n        assert(0 <= n and n <\
    \ size());\n        assert(k >= 0);\n        if(n < k) return 0;\n        return\
    \ m_fact[n] * m_inv_fact[n - k] % mod * m_inv_fact[k] % mod;\n    }\n    // \u91CD\
    \u8907\u7D44\u5408\u305B\uFF0EO(1).\n    long long nHk(int n, int k) const {\n\
    \        assert(n >= 0);\n        assert(k >= 0);\n        if(k == 0) return 1;\n\
    \        if(n == 0) return 0;\n        return nCk(k + n - 1, k);\n    }\n};\n\n\
    using Combination998244353 = Combination<998'244'353>;\nusing Combination1000000007\
    \ = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2025-04-13 12:48:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki-117-combination.test.cpp
documentation_of: lib/Math/Combinatorics/combination.hpp
layout: document
title: "\u6570\u3048\u4E0A\u3052\uFF08mod\u4ED8\u304D\uFF09"
---


## 概要

ある場合の数を，素数 $p$ を法として $\bmod$ を取りながら数え上げる．

計算量は，前処理が $\mathcal{O}(N)$ ，各クエリ処理が $\mathcal{O}(1)$ となる．


## 参考文献

1. "数え上げ数学". Wikipedia. <https://ja.wikipedia.org/wiki/数え上げ数学>.
1. drken1215. "よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方". HatenaBlog. <https://drken1215.hatenablog.com/entry/2018/06/08/210000>.
1. "競プロでよく使う二項係数(nCk)を素数(p)で割った余りの計算と逆元のまとめ". アルゴリズムロジック. <https://algo-logic.info/combination/>.


## 問題

- "D - Factorization". AtCoder Beginner Contest 110. <https://atcoder.jp/contests/abc110/tasks/abc110_d>.
- "E - Max-Min Sum". AtCoder Beginner Contest 151. <https://atcoder.jp/contests/abc151/tasks/abc151_e>.
