---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yuki-117-combination.test.cpp
    title: verify/yuki-117-combination.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Math/Combinatorics/combination.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int mod>\n\
    class Combination {\n    static_assert(mod >= 2);\n\n    static Combination *s_instance;\n\
    \    int m_sz;\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\u968E\
    \u4E57).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\u5143\
    ).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\u306E\
    \u9006\u5143).\n\n    Combination() : m_sz(2), m_fact({1, 1}), m_inv({-1, 1}),\
    \ m_finv({1, 1}) {}\n    ~Combination() = default;\n\n    static Combination *instance()\
    \ {\n        if(!s_instance) s_instance = new Combination;\n        return s_instance;\n\
    \    }\n    long long fact(int n) {\n        assert(n >= 0);\n        if(m_sz\
    \ <= n) resize_internal(n + 1);\n        return m_fact[n];\n    }\n    long long\
    \ inv(int n) {\n        assert(n >= 1);\n        if(m_sz <= n) resize_internal(n\
    \ + 1);\n        return m_inv[n];\n    }\n    long long finv(int n) {\n      \
    \  assert(n >= 0);\n        if(m_sz <= n) resize_internal(n + 1);\n        return\
    \ m_finv[n];\n    }\n    long long nPk_internal(int n, int k) {\n        assert(n\
    \ >= 0);\n        assert(k >= 0);\n        if(n < k) return 0;\n        if(m_sz\
    \ <= n) resize_internal(n + 1);\n        return m_fact[n] * m_finv[n - k] % mod;\n\
    \    }\n    long long nCk_internal(int n, int k) {\n        assert(n >= 0);\n\
    \        assert(k >= 0);\n        if(n < k) return 0;\n        if(m_sz <= n) resize_internal(n\
    \ + 1);\n        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;\n \
    \   }\n    void resize_internal(int sz) {\n        assert(0 <= sz);\n        if(sz\
    \ < 2) return;\n        m_fact.resize(sz);\n        m_inv.resize(sz);\n      \
    \  m_finv.resize(sz);\n        for(int n = m_sz; n < sz; ++n) {\n            m_fact[n]\
    \ = m_fact[n - 1] * n % mod;\n            m_inv[n] = mod - m_inv[mod % n] * (mod\
    \ / n) % mod;\n            m_finv[n] = m_finv[n - 1] * m_inv[n] % mod;\n     \
    \   }\n        m_sz = sz;\n    }\n\npublic:\n    static constexpr int modulus()\
    \ { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    static long long factorial(int\
    \ n) { return instance()->fact(n); }\n    // \u9006\u5143\uFF0EO(1).\n    static\
    \ long long inverse(int n) { return instance()->inv(n); }\n    // \u968E\u4E57\
    \u306E\u9006\u5143\uFF0EO(1).\n    static long long inverse_fact(int n) { return\
    \ instance()->finv(n); }\n    // \u9806\u5217\uFF0EO(1).\n    static long long\
    \ nPk(int n, int k) { return instance()->nPk_internal(n, k); }\n    // \u7D44\u5408\
    \u305B\uFF0EO(1).\n    static long long nCk(int n, int k) { return instance()->nCk_internal(n,\
    \ k); }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(1).\n    static long long\
    \ nHk(int n, int k) {\n        assert(n >= 0);\n        assert(k >= 0);\n    \
    \    if(k == 0) return 1;\n        if(n == 0) return 0;\n        return instance()->nCk_internal(k\
    \ + n - 1, k);\n    }\n    static void resize(int sz) { instance()->resize_internal(sz);\
    \ }\n    static void destroy() {\n        delete s_instance;\n        s_instance\
    \ = nullptr;\n    }\n};\n\ntemplate <int mod>\nCombination<mod> *Combination<mod>::s_instance\
    \ = nullptr;\n\nusing Combination998244353 = Combination<998'244'353>;\nusing\
    \ Combination1000000007 = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_COMBINATION_HPP\n#define ALGORITHM_COMBINATION_HPP 1\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int\
    \ mod>\nclass Combination {\n    static_assert(mod >= 2);\n\n    static Combination\
    \ *s_instance;\n    int m_sz;\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\
    \u968E\u4E57).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\
    \u5143).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\n    Combination() : m_sz(2), m_fact({1, 1}), m_inv({-1,\
    \ 1}), m_finv({1, 1}) {}\n    ~Combination() = default;\n\n    static Combination\
    \ *instance() {\n        if(!s_instance) s_instance = new Combination;\n     \
    \   return s_instance;\n    }\n    long long fact(int n) {\n        assert(n >=\
    \ 0);\n        if(m_sz <= n) resize_internal(n + 1);\n        return m_fact[n];\n\
    \    }\n    long long inv(int n) {\n        assert(n >= 1);\n        if(m_sz <=\
    \ n) resize_internal(n + 1);\n        return m_inv[n];\n    }\n    long long finv(int\
    \ n) {\n        assert(n >= 0);\n        if(m_sz <= n) resize_internal(n + 1);\n\
    \        return m_finv[n];\n    }\n    long long nPk_internal(int n, int k) {\n\
    \        assert(n >= 0);\n        assert(k >= 0);\n        if(n < k) return 0;\n\
    \        if(m_sz <= n) resize_internal(n + 1);\n        return m_fact[n] * m_finv[n\
    \ - k] % mod;\n    }\n    long long nCk_internal(int n, int k) {\n        assert(n\
    \ >= 0);\n        assert(k >= 0);\n        if(n < k) return 0;\n        if(m_sz\
    \ <= n) resize_internal(n + 1);\n        return m_fact[n] * m_finv[n - k] % mod\
    \ * m_finv[k] % mod;\n    }\n    void resize_internal(int sz) {\n        assert(0\
    \ <= sz);\n        if(sz < 2) return;\n        m_fact.resize(sz);\n        m_inv.resize(sz);\n\
    \        m_finv.resize(sz);\n        for(int n = m_sz; n < sz; ++n) {\n      \
    \      m_fact[n] = m_fact[n - 1] * n % mod;\n            m_inv[n] = mod - m_inv[mod\
    \ % n] * (mod / n) % mod;\n            m_finv[n] = m_finv[n - 1] * m_inv[n] %\
    \ mod;\n        }\n        m_sz = sz;\n    }\n\npublic:\n    static constexpr\
    \ int modulus() { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    static long\
    \ long factorial(int n) { return instance()->fact(n); }\n    // \u9006\u5143\uFF0E\
    O(1).\n    static long long inverse(int n) { return instance()->inv(n); }\n  \
    \  // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    static long long inverse_fact(int\
    \ n) { return instance()->finv(n); }\n    // \u9806\u5217\uFF0EO(1).\n    static\
    \ long long nPk(int n, int k) { return instance()->nPk_internal(n, k); }\n   \
    \ // \u7D44\u5408\u305B\uFF0EO(1).\n    static long long nCk(int n, int k) { return\
    \ instance()->nCk_internal(n, k); }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0E\
    O(1).\n    static long long nHk(int n, int k) {\n        assert(n >= 0);\n   \
    \     assert(k >= 0);\n        if(k == 0) return 1;\n        if(n == 0) return\
    \ 0;\n        return instance()->nCk_internal(k + n - 1, k);\n    }\n    static\
    \ void resize(int sz) { instance()->resize_internal(sz); }\n    static void destroy()\
    \ {\n        delete s_instance;\n        s_instance = nullptr;\n    }\n};\n\n\
    template <int mod>\nCombination<mod> *Combination<mod>::s_instance = nullptr;\n\
    \nusing Combination998244353 = Combination<998'244'353>;\nusing Combination1000000007\
    \ = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2025-02-21 01:13:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
