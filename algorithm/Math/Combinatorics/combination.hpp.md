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
  bundledCode: "#line 1 \"algorithm/Math/Combinatorics/combination.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int mod>\n\
    class Combination {\n    static_assert(mod >= 2);\n\n    int m_sz;\n    std::vector<long\
    \ long> m_fact;      // m_fact[n]:=(n\u306E\u968E\u4E57).\n    std::vector<long\
    \ long> m_inv;       // m_inv[n]:=(n\u306E\u9006\u5143).\n    std::vector<long\
    \ long> m_inv_fact;  // m_inv_fact[n]:=(n\u306E\u968E\u4E57\u306E\u9006\u5143\
    ).\n\n    void build(int n) {\n        if(n <= m_sz) return;\n        m_fact.resize(n);\n\
    \        m_inv.resize(n);\n        m_inv_fact.resize(n);\n        for(int i =\
    \ m_sz; i < n; ++i) {\n            m_fact[i] = m_fact[i - 1] * i % mod;\n    \
    \        m_inv[i] = mod - m_inv[mod % i] * (mod / i) % mod;\n            m_inv_fact[i]\
    \ = m_inv_fact[i - 1] * m_inv[i] % mod;\n        }\n        m_sz = n;\n    }\n\
    \npublic:\n    Combination() : Combination(2) {}\n    explicit Combination(int\
    \ n) : m_sz(2), m_fact(n), m_inv(n), m_inv_fact(n) {\n        assert(n >= 2);\n\
    \        m_fact[0] = m_fact[1] = 1;\n        m_inv[1] = 1;\n        m_inv_fact[0]\
    \ = m_inv_fact[1] = 1;\n        build(n);\n    }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    long long factorial(int\
    \ n) {\n        assert(n >= 0);\n        build(n + 1);\n        return m_fact[n];\n\
    \    }\n    // \u9006\u5143\uFF0EO(1).\n    long long inverse(int n) {\n     \
    \   assert(n >= 1);\n        build(n + 1);\n        return m_inv[n];\n    }\n\
    \    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    long long inverse_factorial(int\
    \ n) {\n        assert(n >= 0);\n        build(n + 1);\n        return m_inv_fact[n];\n\
    \    }\n    // \u9806\u5217\uFF0EO(1).\n    long long nPk(int n, int k) {\n  \
    \      assert(n >= 0);\n        assert(k >= 0);\n        if(n < k) return 0;\n\
    \        build(n + 1);\n        return m_fact[n] * m_inv_fact[n - k] % mod;\n\
    \    }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long long nCk(int n, int k)\
    \ {\n        assert(n >= 0);\n        assert(k >= 0);\n        if(n < k) return\
    \ 0;\n        build(n + 1);\n        return m_fact[n] * m_inv_fact[n - k] % mod\
    \ * m_inv_fact[k] % mod;\n    }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(1).\n\
    \    long long nHk(int n, int k) {\n        assert(n >= 0);\n        assert(k\
    \ >= 0);\n        if(k == 0) return 1;\n        if(n == 0) return 0;\n       \
    \ return nCk(k + n - 1, k);\n    }\n};\n\nusing Combination998244353 = Combination<998'244'353>;\n\
    using Combination1000000007 = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_COMBINATION_HPP\n#define ALGORITHM_COMBINATION_HPP 1\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int\
    \ mod>\nclass Combination {\n    static_assert(mod >= 2);\n\n    int m_sz;\n \
    \   std::vector<long long> m_fact;      // m_fact[n]:=(n\u306E\u968E\u4E57).\n\
    \    std::vector<long long> m_inv;       // m_inv[n]:=(n\u306E\u9006\u5143).\n\
    \    std::vector<long long> m_inv_fact;  // m_inv_fact[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\n    void build(int n) {\n        if(n <= m_sz) return;\n\
    \        m_fact.resize(n);\n        m_inv.resize(n);\n        m_inv_fact.resize(n);\n\
    \        for(int i = m_sz; i < n; ++i) {\n            m_fact[i] = m_fact[i - 1]\
    \ * i % mod;\n            m_inv[i] = mod - m_inv[mod % i] * (mod / i) % mod;\n\
    \            m_inv_fact[i] = m_inv_fact[i - 1] * m_inv[i] % mod;\n        }\n\
    \        m_sz = n;\n    }\n\npublic:\n    Combination() : Combination(2) {}\n\
    \    explicit Combination(int n) : m_sz(2), m_fact(n), m_inv(n), m_inv_fact(n)\
    \ {\n        assert(n >= 2);\n        m_fact[0] = m_fact[1] = 1;\n        m_inv[1]\
    \ = 1;\n        m_inv_fact[0] = m_inv_fact[1] = 1;\n        build(n);\n    }\n\
    \n    static constexpr int modulus() { return mod; }\n    // \u968E\u4E57\uFF0E\
    O(1).\n    long long factorial(int n) {\n        assert(n >= 0);\n        build(n\
    \ + 1);\n        return m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n  \
    \  long long inverse(int n) {\n        assert(n >= 1);\n        build(n + 1);\n\
    \        return m_inv[n];\n    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0E\
    O(1).\n    long long inverse_factorial(int n) {\n        assert(n >= 0);\n   \
    \     build(n + 1);\n        return m_inv_fact[n];\n    }\n    // \u9806\u5217\
    \uFF0EO(1).\n    long long nPk(int n, int k) {\n        assert(n >= 0);\n    \
    \    assert(k >= 0);\n        if(n < k) return 0;\n        build(n + 1);\n   \
    \     return m_fact[n] * m_inv_fact[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\
    \uFF0EO(1).\n    long long nCk(int n, int k) {\n        assert(n >= 0);\n    \
    \    assert(k >= 0);\n        if(n < k) return 0;\n        build(n + 1);\n   \
    \     return m_fact[n] * m_inv_fact[n - k] % mod * m_inv_fact[k] % mod;\n    }\n\
    \    // \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(1).\n    long long nHk(int n, int\
    \ k) {\n        assert(n >= 0);\n        assert(k >= 0);\n        if(k == 0) return\
    \ 1;\n        if(n == 0) return 0;\n        return nCk(k + n - 1, k);\n    }\n\
    };\n\nusing Combination998244353 = Combination<998'244'353>;\nusing Combination1000000007\
    \ = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yuki-117-combination.test.cpp
documentation_of: algorithm/Math/Combinatorics/combination.hpp
layout: document
title: "\u6570\u3048\u4E0A\u3052\uFF08mod\u4ED8\u304D\uFF09"
---


## 概要

ある場合の数を，素数 $p$ を法として $\bmod$ を取りながら数え上げる．

計算量は，前処理が $\mathcal{O}(N)$ ，各クエリ処理が $\mathcal{O}(1)$ となる．


## 説明

### algorithm::Combination

|メンバ関数|説明|計算量|
|---|---|---|
|`Combination<p>(n)`|コンストラクタ|$\mathcal{O}(N)$|
|`factorial(n)`|$n! \mod p$ を返す．|$\mathcal{O}(1)$|
|`inverse(n)`|$n^{-1} \mod p$ を返す．|$\mathcal{O}(1)$|
|`inverse_factorial(n)`|$(n!)^{-1} \mod p$ を返す．|$\mathcal{O}(1)$|
|`nPk(n,k)`|$_n \mathrm{P}_k \mod p$ を返す．|$\mathcal{O}(1)$|
|`nCk(n,k)`|$_n \mathrm{C}_k \mod p$ を返す．|$\mathcal{O}(1)$|
|`nHk(n,k)`|$_n \mathrm{H}_k \mod p$ を返す．|$\mathcal{O}(1)$|


## 参考

1. "数え上げ数学". Wikipedia. <https://ja.wikipedia.org/wiki/数え上げ数学>.
1. drken1215. "よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方". HatenaBlog. <https://drken1215.hatenablog.com/entry/2018/06/08/210000>.
1. ngtkana. "1..=N の階乗逆数・ただの逆数を O(N) 時間で前計算する方法（mod p）" <https://ngtkana.hatenablog.com/entry/2025/05/11/105210>.
1. rsk0315. "mod についてふんわりとしか理解していない競プロ er のみなさん". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2023/05/05/221524>.
1. "競プロでよく使う二項係数(nCk)を素数(p)で割った余りの計算と逆元のまとめ". アルゴリズムロジック. <https://algo-logic.info/combination/>.


## 問題

- "D - Factorization". AtCoder Beginner Contest 110. <https://atcoder.jp/contests/abc110/tasks/abc110_d>.
- "E - Max-Min Sum". AtCoder Beginner Contest 151. <https://atcoder.jp/contests/abc151/tasks/abc151_e>.
