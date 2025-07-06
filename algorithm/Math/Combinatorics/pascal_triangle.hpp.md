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
  bundledCode: "#line 1 \"algorithm/Math/Combinatorics/pascal_triangle.hpp\"\n\n\n\
    \n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <int\
    \ mod>\nclass PascalTriangle {\n    static_assert(mod >= 1);\n\n    int m_sz;\n\
    \    std::vector<std::vector<long long>> m_c;  // m_c[n][k]:=(C(n,n-k) and C(n,k)).\n\
    \npublic:\n    // constructor. O(N^2).\n    PascalTriangle() : PascalTriangle(0)\
    \ {}\n    PascalTriangle(int n) : m_sz(n), m_c(n) {\n        for(int i = 0; i\
    \ < n; ++i) {\n            const int m = (i + 2) / 2;\n            m_c[i].resize(m);\n\
    \            m_c[i][0] = 1 % mod;\n            for(int j = 1; j < m; ++j) m_c[i][j]\
    \ = (m_c[i - 1][j - 1] + (i - 1 - j < j ? m_c[i - 1][i - 1 - j] : m_c[i - 1][j]))\
    \ % mod;\n        }\n    }\n\n    static constexpr int modulus() { return mod;\
    \ }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long long nCk(int n, int k) const\
    \ {\n        assert(n >= 0);\n        assert(k >= 0);\n        if(k > n) return\
    \ 0;\n        return (n - k < k ? m_c[n][n - k] : m_c[n][k]);\n    }\n};\n\n}\
    \  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP\n#define ALGORITHM_PASCAL_TRIANGLE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate\
    \ <int mod>\nclass PascalTriangle {\n    static_assert(mod >= 1);\n\n    int m_sz;\n\
    \    std::vector<std::vector<long long>> m_c;  // m_c[n][k]:=(C(n,n-k) and C(n,k)).\n\
    \npublic:\n    // constructor. O(N^2).\n    PascalTriangle() : PascalTriangle(0)\
    \ {}\n    PascalTriangle(int n) : m_sz(n), m_c(n) {\n        for(int i = 0; i\
    \ < n; ++i) {\n            const int m = (i + 2) / 2;\n            m_c[i].resize(m);\n\
    \            m_c[i][0] = 1 % mod;\n            for(int j = 1; j < m; ++j) m_c[i][j]\
    \ = (m_c[i - 1][j - 1] + (i - 1 - j < j ? m_c[i - 1][i - 1 - j] : m_c[i - 1][j]))\
    \ % mod;\n        }\n    }\n\n    static constexpr int modulus() { return mod;\
    \ }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    long long nCk(int n, int k) const\
    \ {\n        assert(n >= 0);\n        assert(k >= 0);\n        if(k > n) return\
    \ 0;\n        return (n - k < k ? m_c[n][n - k] : m_c[n][k]);\n    }\n};\n\n}\
    \  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Combinatorics/pascal_triangle.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/Combinatorics/pascal_triangle.hpp
layout: document
title: "Pascal's Triangle\uFF08\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\uFF09"
---


## 概要

パスカルの三角形とは，二項展開における係数を三角形状に並べたもの．

次の公式を利用し，二項係数のテーブルを構築する．

$$
{}_n \mathrm{C}_k = {}_{n-1} \mathrm{C}_{k-1} + {}_{n-1} \mathrm{C}_{k}
$$

計算量は，時間と空間のともに $\mathcal{O}(N^2)$ を要する．


## 参考文献

1. "パスカルの三角形". Wikipedia. <https://ja.wikipedia.org/wiki/パスカルの三角形>.
