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
  bundledCode: "#line 1 \"lib/Math/Combinatorics/pascal_triangle.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ T = long long>\nclass PascalTriangle {\n    static std::vector<std::vector<T>\
    \ > s_c;  // s_c[n][k]:=(C(n,n-k) and C(n,k)).\n\n    PascalTriangle() = default;\n\
    \    ~PascalTriangle() = default;\n\npublic:\n    // \u7D44\u5408\u305B\uFF0E\n\
    \    static T nCk(int n, int k) {\n        assert(n >= 0);\n        assert(k >=\
    \ 0);\n        if(k > n) return 0;\n        resize(n + 1);\n        return (n\
    \ - k < k ? s_c[n][n - k] : s_c[n][k]);\n    }\n    // \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0E\n    static T nHk(int n, int k) {\n        assert(n >= 1);\n    \
    \    assert(k >= 0);\n        return nCk(k + n - 1, k);\n    }\n    static void\
    \ resize(int sz) {\n        const int now = s_c.size();\n        s_c.resize(sz);\n\
    \        for(int n = now; n < sz; ++n) {\n            const int len = (n + 2)\
    \ / 2;\n            s_c[n].resize(len);\n            s_c[n][0] = 1;\n        \
    \    for(int k = 1; k < len; ++k) s_c[n][k] = s_c[n - 1][k - 1] + (n - 1 - k <\
    \ k ? s_c[n - 1][n - 1 - k] : s_c[n - 1][k]);\n        }\n    }\n    static void\
    \ clear() { s_c.clear(); }\n};\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > PascalTriangle<T>::s_c;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP\n#define ALGORITHM_PASCAL_TRIANGLE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate\
    \ <typename T = long long>\nclass PascalTriangle {\n    static std::vector<std::vector<T>\
    \ > s_c;  // s_c[n][k]:=(C(n,n-k) and C(n,k)).\n\n    PascalTriangle() = default;\n\
    \    ~PascalTriangle() = default;\n\npublic:\n    // \u7D44\u5408\u305B\uFF0E\n\
    \    static T nCk(int n, int k) {\n        assert(n >= 0);\n        assert(k >=\
    \ 0);\n        if(k > n) return 0;\n        resize(n + 1);\n        return (n\
    \ - k < k ? s_c[n][n - k] : s_c[n][k]);\n    }\n    // \u91CD\u8907\u7D44\u5408\
    \u305B\uFF0E\n    static T nHk(int n, int k) {\n        assert(n >= 1);\n    \
    \    assert(k >= 0);\n        return nCk(k + n - 1, k);\n    }\n    static void\
    \ resize(int sz) {\n        const int now = s_c.size();\n        s_c.resize(sz);\n\
    \        for(int n = now; n < sz; ++n) {\n            const int len = (n + 2)\
    \ / 2;\n            s_c[n].resize(len);\n            s_c[n][0] = 1;\n        \
    \    for(int k = 1; k < len; ++k) s_c[n][k] = s_c[n - 1][k - 1] + (n - 1 - k <\
    \ k ? s_c[n - 1][n - 1 - k] : s_c[n - 1][k]);\n        }\n    }\n    static void\
    \ clear() { s_c.clear(); }\n};\n\ntemplate <typename T>\nstd::vector<std::vector<T>\
    \ > PascalTriangle<T>::s_c;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/pascal_triangle.hpp
  requiredBy: []
  timestamp: '2025-02-20 21:37:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/Combinatorics/pascal_triangle.hpp
layout: document
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
