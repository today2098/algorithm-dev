---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/Combinatorics/pascal_triangle.md
    document_title: "Pascal's Triangle\uFF08\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\
      \u5F62\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/Combinatorics/pascal_triangle.hpp\"\n\n\n\n/**\n\
    \ * @brief Pascal's Triangle\uFF08\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\
    \uFF09\n * @docs docs/Math/Combinatorics/pascal_triangle.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ Type = long long>\nclass PascalTriangle {\npublic:\n    int m_mx;          \
    \                   // m_mx:=(\u5F15\u6570n\u306E\u6700\u5927\u5024).\n    std::vector<std::vector<Type>\
    \ > m_c;  // m_c[n][k]:=(C(n,k) and C(n,n-k)).\n\npublic:\n    // constructor.\
    \ O(N^2).\n    PascalTriangle() : PascalTriangle(51e2) {}\n    explicit PascalTriangle(int\
    \ mx) : m_mx(mx), m_c(mx + 1) {\n        assert(mx >= 0);\n        for(int n =\
    \ 0; n <= m_mx; ++n) {\n            const int len = (n + 2) / 2;\n           \
    \ m_c[n].resize(len);\n            m_c[n][0] = 1;\n            for(int k = 1;\
    \ k < len; ++k) m_c[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);\n        }\n  \
    \  }\n\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    Type nCk(int n, int k) const\
    \ {\n        assert(0 <= n and n <= m_mx);\n        assert(k >= 0);\n        if(k\
    \ > n) return 0;\n        return (k <= n - k ? m_c[n][k] : m_c[n][n - k]);\n \
    \   }\n    // \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(1).\n    Type nHk(int n, int\
    \ k) const {\n        assert(n >= 1 and k >= 0);\n        return nCk(k + n - 1,\
    \ k);\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP\n#define ALGORITHM_PASCAL_TRIANGLE_HPP\
    \ 1\n\n/**\n * @brief Pascal's Triangle\uFF08\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\
    \u89D2\u5F62\uFF09\n * @docs docs/Math/Combinatorics/pascal_triangle.md\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\ntemplate <typename Type = long long>\nclass PascalTriangle {\npublic:\n\
    \    int m_mx;                             // m_mx:=(\u5F15\u6570n\u306E\u6700\
    \u5927\u5024).\n    std::vector<std::vector<Type> > m_c;  // m_c[n][k]:=(C(n,k)\
    \ and C(n,n-k)).\n\npublic:\n    // constructor. O(N^2).\n    PascalTriangle()\
    \ : PascalTriangle(51e2) {}\n    explicit PascalTriangle(int mx) : m_mx(mx), m_c(mx\
    \ + 1) {\n        assert(mx >= 0);\n        for(int n = 0; n <= m_mx; ++n) {\n\
    \            const int len = (n + 2) / 2;\n            m_c[n].resize(len);\n \
    \           m_c[n][0] = 1;\n            for(int k = 1; k < len; ++k) m_c[n][k]\
    \ = nCk(n - 1, k - 1) + nCk(n - 1, k);\n        }\n    }\n\n    // \u7D44\u5408\
    \u305B\uFF0EO(1).\n    Type nCk(int n, int k) const {\n        assert(0 <= n and\
    \ n <= m_mx);\n        assert(k >= 0);\n        if(k > n) return 0;\n        return\
    \ (k <= n - k ? m_c[n][k] : m_c[n][n - k]);\n    }\n    // \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0EO(1).\n    Type nHk(int n, int k) const {\n        assert(n >= 1 and\
    \ k >= 0);\n        return nCk(k + n - 1, k);\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/pascal_triangle.hpp
  requiredBy: []
  timestamp: '2024-09-15 17:10:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/Combinatorics/pascal_triangle.hpp
layout: document
redirect_from:
- /library/lib/Math/Combinatorics/pascal_triangle.hpp
- /library/lib/Math/Combinatorics/pascal_triangle.hpp.html
title: "Pascal's Triangle\uFF08\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\uFF09"
---
## 概要

パスカルの三角形とは，二項展開における係数を三角形状に並べたもの．

次の公式を利用し，二項係数のテーブルを構築する．

$$
{}_n C_k = {}_{n-1} C_{k-1} + {}_{n-1} C_{k}
$$

計算量は，時間と空間のともに $\mathcal{O}(N^2)$ を要する．


## 参考文献

1. "パスカルの三角形". Wikipedia. <https://ja.wikipedia.org/wiki/パスカルの三角形>.
