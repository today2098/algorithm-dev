---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/Combinatorics/combination.md
    document_title: "\u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/Combinatorics/combination.hpp\"\n\n\n\n/**\n *\
    \ @brief \u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\n * @docs docs/Math/Combinatorics/combination.md\n\
    \ */\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D44\
    \u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate <int mod>\nclass Combination\
    \ {\n    int m_mx;                       // m_mx:=(\u5F15\u6570n\u306E\u6700\u5927\
    \u5024).\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\u968E\u4E57\
    ).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\u5143).\n\
    \    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\u306E\u9006\
    \u5143).\n\npublic:\n    // constructor. \u5236\u7D04\u306F\uFF0Cmod\u304C\u7D20\
    \u6570\u304B\u3064 mx<mod \u3067\u3042\u308B\u3053\u3068\uFF0EO(N).\n    Combination()\
    \ : Combination(51e4) {}\n    explicit Combination(int mx) : m_mx(mx), m_fact(mx\
    \ + 1), m_inv(mx + 1), m_finv(mx + 1) {\n        static_assert(mod >= 1);\n  \
    \      assert(1 <= m_mx and m_mx < mod);\n        m_fact[0] = m_fact[1] = 1;\n\
    \        m_inv[1] = 1;\n        m_finv[0] = m_finv[1] = 1;\n        for(int n\
    \ = 2; n <= m_mx; ++n) {\n            m_fact[n] = m_fact[n - 1] * n % mod;\n \
    \           m_inv[n] = mod - m_inv[mod % n] * (mod / n) % mod;\n            m_finv[n]\
    \ = m_finv[n - 1] * m_inv[n] % mod;\n        }\n    }\n\n    static constexpr\
    \ int modulus() { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    long long\
    \ factorial(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n    long long inverse(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        return m_inv[n];\n\
    \    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    long long inverse_fact(int\
    \ n) const {\n        assert(0 <= n and n <= m_mx);\n        return m_finv[n];\n\
    \    }\n    // \u9806\u5217\uFF0EO(1).\n    long long nPk(int n, int k) const\
    \ {\n        assert(0 <= k and k <= n and n <= m_mx);\n        return m_fact[n]\
    \ * m_finv[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long\
    \ long nCk(int n, int k) const {\n        assert(0 <= n and n <= m_mx);\n    \
    \    assert(k >= 0);\n        if(k > n) return 0;\n        return m_fact[n] *\
    \ m_finv[n - k] % mod * m_finv[k] % mod;\n    }\n    // \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0EO(1).\n    long long nHk(int n, int k) const {\n        assert(n >=\
    \ 1 and k >= 0);\n        return nCk(k + n - 1, k);\n    }\n};\n\nusing Combination998244353\
    \ = Combination<998'244'353>;\nusing Combination1000000007 = Combination<1'000'000'007>;\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_COMBINATION_HPP\n#define ALGORITHM_COMBINATION_HPP 1\n\n\
    /**\n * @brief \u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\n * @docs docs/Math/Combinatorics/combination.md\n\
    \ */\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D44\
    \u5408\u305B\uFF08mod\u4ED8\u304D\uFF09\uFF0E\ntemplate <int mod>\nclass Combination\
    \ {\n    int m_mx;                       // m_mx:=(\u5F15\u6570n\u306E\u6700\u5927\
    \u5024).\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\u968E\u4E57\
    ).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\u5143).\n\
    \    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\u306E\u9006\
    \u5143).\n\npublic:\n    // constructor. \u5236\u7D04\u306F\uFF0Cmod\u304C\u7D20\
    \u6570\u304B\u3064 mx<mod \u3067\u3042\u308B\u3053\u3068\uFF0EO(N).\n    Combination()\
    \ : Combination(51e4) {}\n    explicit Combination(int mx) : m_mx(mx), m_fact(mx\
    \ + 1), m_inv(mx + 1), m_finv(mx + 1) {\n        static_assert(mod >= 1);\n  \
    \      assert(1 <= m_mx and m_mx < mod);\n        m_fact[0] = m_fact[1] = 1;\n\
    \        m_inv[1] = 1;\n        m_finv[0] = m_finv[1] = 1;\n        for(int n\
    \ = 2; n <= m_mx; ++n) {\n            m_fact[n] = m_fact[n - 1] * n % mod;\n \
    \           m_inv[n] = mod - m_inv[mod % n] * (mod / n) % mod;\n            m_finv[n]\
    \ = m_finv[n - 1] * m_inv[n] % mod;\n        }\n    }\n\n    static constexpr\
    \ int modulus() { return mod; }\n    // \u968E\u4E57\uFF0EO(1).\n    long long\
    \ factorial(int n) const {\n        assert(0 <= n and n <= m_mx);\n        return\
    \ m_fact[n];\n    }\n    // \u9006\u5143\uFF0EO(1).\n    long long inverse(int\
    \ n) const {\n        assert(1 <= n and n <= m_mx);\n        return m_inv[n];\n\
    \    }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n    long long inverse_fact(int\
    \ n) const {\n        assert(0 <= n and n <= m_mx);\n        return m_finv[n];\n\
    \    }\n    // \u9806\u5217\uFF0EO(1).\n    long long nPk(int n, int k) const\
    \ {\n        assert(0 <= k and k <= n and n <= m_mx);\n        return m_fact[n]\
    \ * m_finv[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long\
    \ long nCk(int n, int k) const {\n        assert(0 <= n and n <= m_mx);\n    \
    \    assert(k >= 0);\n        if(k > n) return 0;\n        return m_fact[n] *\
    \ m_finv[n - k] % mod * m_finv[k] % mod;\n    }\n    // \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0EO(1).\n    long long nHk(int n, int k) const {\n        assert(n >=\
    \ 1 and k >= 0);\n        return nCk(k + n - 1, k);\n    }\n};\n\nusing Combination998244353\
    \ = Combination<998'244'353>;\nusing Combination1000000007 = Combination<1'000'000'007>;\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2024-09-15 17:10:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/Combinatorics/combination.hpp
layout: document
redirect_from:
- /library/lib/Math/Combinatorics/combination.hpp
- /library/lib/Math/Combinatorics/combination.hpp.html
title: "\u7D44\u5408\u305B\uFF08mod\u4ED8\u304D\uFF09"
---
## 概要

特定の性質を備えた対象を，素数 $p$ を法として mod を取りながら数え上げる．

計算量は，前処理に $\mathcal{O}(N)$ ，クエリ処理に $\mathcal{O}(1)$ を要する．


## 参考文献

1. drken1215. "よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方". HatenaBlog. <https://drken1215.hatenablog.com/entry/2018/06/08/210000>.
1. "競プロでよく使う二項係数(nCk)を素数(p)で割った余りの計算と逆元のまとめ". アルゴリズムロジック. <https://algo-logic.info/combination/>.
