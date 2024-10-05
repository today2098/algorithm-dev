---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_1_B-potentialized_union_find.test.cpp
    title: test/aoj-DSL_1_B-potentialized_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/UnionFind/potentialized_union_find.md
    document_title: "\u91CD\u307F\u4ED8\u304DUnion-Find"
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/UnionFind/potentialized_union_find.hpp\"\
    \n\n\n\n/**\n * @brief \u91CD\u307F\u4ED8\u304DUnion-Find\n * @docs docs/DataStructure/UnionFind/potentialized_union_find.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u91CD\u307F\u4ED8\u304DUnion-Find\uFF0E\
    \ntemplate <typename T>\nclass PotentializedUnionFind {\n    int m_vn;  // m_vn:=(\u8981\
    \u7D20\u6570).\n    int m_gn;  // m_gn:=(\u30B0\u30EB\u30FC\u30D7\u6570).\n  \
    \  // m_par[x]:=(\u8981\u7D20x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0C\
    x\u306F\u6839\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\
    \u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\
    \uFF0E\n    std::vector<int> m_par;\n    std::vector<T> m_h;  // m_h[x]:=(\u8981\
    \u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB).\n\npublic:\n    PotentializedUnionFind()\
    \ : PotentializedUnionFind(0) {}\n    explicit PotentializedUnionFind(size_t vn)\
    \ : m_vn(vn), m_gn(vn), m_par(vn, -1), m_h(vn, 0) {}\n\n    // \u8981\u7D20\u306E\
    \u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const\
    \ { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u3092\u8FD4\u3059\uFF0E\
    O(\u03B1(N)).\n    int root(int x) {\n        assert(0 <= x and x < vn());\n \
    \       if(m_par[x] < 0) return x;\n        int rt = root(m_par[x]);  // \u7D4C\
    \u8DEF\u5727\u7E2E\uFF0E\n        m_h[x] += m_h[m_par[x]];\n        return m_par[x]\
    \ = rt;\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int x) {\n\
    \        assert(0 <= x and x < vn());\n        return -m_par[root(x)];\n    }\n\
    \    // \u8981\u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\
    \uFF0E\n    T potential(int x) {\n        assert(0 <= x and x < vn());\n     \
    \   root(x);\n        return m_h[x];\n    }\n    // \u8981\u7D20x, y\u304C\u540C\
    \u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0E\n    bool is_same(int x, int y) {\n        assert(0 <= x and x <\
    \ vn());\n        assert(0 <= y and y < vn());\n        return root(x) == root(y);\n\
    \    }\n    // \u8981\u7D20x\u306B\u5BFE\u3059\u308By\u306E\u76F8\u5BFE\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\uFF0E\n    T diff(int x, int y) {\n\
    \        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        return potential(y) - potential(x);\n    }\n    // diff(x,y)==d \u3068\
    \u306A\u308B\u3088\u3046\u306B\uFF0C\u8981\u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\
    \u308C\u305E\u308C\u306E\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\u5408\u3059\u308B\
    \uFF0E\n    bool unite(int x, int y, T d) {\n        assert(0 <= x and x < vn());\n\
    \        assert(0 <= y and y < vn());\n        d = potential(x) + d - potential(y);\n\
    \        x = root(x), y = root(y);\n        if(x == y) return false;     // Do\
    \ nothing.\n        if(-m_par[x] < -m_par[y]) {  // Merge technique (union by\
    \ size).\n            std::swap(x, y);\n            d = -d;\n        }\n     \
    \   m_par[x] += m_par[y];\n        m_par[y] = x;\n        m_h[y] = d;\n      \
    \  m_gn--;\n        return true;\n    }\n    void reset() {\n        m_gn = vn();\n\
    \        std::fill(m_par.begin(), m_par.end(), -1);\n        std::fill(m_h.begin(),\
    \ m_h.end(), 0);\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP\n#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP\
    \ 1\n\n/**\n * @brief \u91CD\u307F\u4ED8\u304DUnion-Find\n * @docs docs/DataStructure/UnionFind/potentialized_union_find.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u91CD\u307F\u4ED8\u304DUnion-Find\uFF0E\
    \ntemplate <typename T>\nclass PotentializedUnionFind {\n    int m_vn;  // m_vn:=(\u8981\
    \u7D20\u6570).\n    int m_gn;  // m_gn:=(\u30B0\u30EB\u30FC\u30D7\u6570).\n  \
    \  // m_par[x]:=(\u8981\u7D20x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0C\
    x\u306F\u6839\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\
    \u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\
    \uFF0E\n    std::vector<int> m_par;\n    std::vector<T> m_h;  // m_h[x]:=(\u8981\
    \u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB).\n\npublic:\n    PotentializedUnionFind()\
    \ : PotentializedUnionFind(0) {}\n    explicit PotentializedUnionFind(size_t vn)\
    \ : m_vn(vn), m_gn(vn), m_par(vn, -1), m_h(vn, 0) {}\n\n    // \u8981\u7D20\u306E\
    \u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const\
    \ { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u3092\u8FD4\u3059\uFF0E\
    O(\u03B1(N)).\n    int root(int x) {\n        assert(0 <= x and x < vn());\n \
    \       if(m_par[x] < 0) return x;\n        int rt = root(m_par[x]);  // \u7D4C\
    \u8DEF\u5727\u7E2E\uFF0E\n        m_h[x] += m_h[m_par[x]];\n        return m_par[x]\
    \ = rt;\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int x) {\n\
    \        assert(0 <= x and x < vn());\n        return -m_par[root(x)];\n    }\n\
    \    // \u8981\u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\
    \uFF0E\n    T potential(int x) {\n        assert(0 <= x and x < vn());\n     \
    \   root(x);\n        return m_h[x];\n    }\n    // \u8981\u7D20x, y\u304C\u540C\
    \u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0E\n    bool is_same(int x, int y) {\n        assert(0 <= x and x <\
    \ vn());\n        assert(0 <= y and y < vn());\n        return root(x) == root(y);\n\
    \    }\n    // \u8981\u7D20x\u306B\u5BFE\u3059\u308By\u306E\u76F8\u5BFE\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\uFF0E\n    T diff(int x, int y) {\n\
    \        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        return potential(y) - potential(x);\n    }\n    // diff(x,y)==d \u3068\
    \u306A\u308B\u3088\u3046\u306B\uFF0C\u8981\u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\
    \u308C\u305E\u308C\u306E\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\u5408\u3059\u308B\
    \uFF0E\n    bool unite(int x, int y, T d) {\n        assert(0 <= x and x < vn());\n\
    \        assert(0 <= y and y < vn());\n        d = potential(x) + d - potential(y);\n\
    \        x = root(x), y = root(y);\n        if(x == y) return false;     // Do\
    \ nothing.\n        if(-m_par[x] < -m_par[y]) {  // Merge technique (union by\
    \ size).\n            std::swap(x, y);\n            d = -d;\n        }\n     \
    \   m_par[x] += m_par[y];\n        m_par[y] = x;\n        m_h[y] = d;\n      \
    \  m_gn--;\n        return true;\n    }\n    void reset() {\n        m_gn = vn();\n\
    \        std::fill(m_par.begin(), m_par.end(), -1);\n        std::fill(m_h.begin(),\
    \ m_h.end(), 0);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/UnionFind/potentialized_union_find.hpp
  requiredBy: []
  timestamp: '2024-10-05 03:59:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_1_B-potentialized_union_find.test.cpp
documentation_of: lib/DataStructure/UnionFind/potentialized_union_find.hpp
layout: document
redirect_from:
- /library/lib/DataStructure/UnionFind/potentialized_union_find.hpp
- /library/lib/DataStructure/UnionFind/potentialized_union_find.hpp.html
title: "\u91CD\u307F\u4ED8\u304DUnion-Find"
---
## 概要

「重み付き Union-Find」は，通常の Union-Find を発展させ，各要素にポテンシャルを付加し，要素間のポテンシャルの差分を管理する．

次のクエリ処理を高速に行う．
ただし，各グループの根（代表要素）のポテンシャルを0とする．

- $\operatorname{potential}(x)$ : 要素 $x$ のポテンシャルを返す．
- $\operatorname{unite}(x, y, d)$ : $\operatorname{potential}(y)-\operatorname{potential}(x)=d$ となるように，要素x, yが属するそれぞれのグループを併合する．
- $\operatorname{is\_same}(x, y)$ : 要素 $x, y$ が同じグループに属するか判定する．

主な実装方針は Union-Find と同じで，各クエリの計算量は $\mathcal{O}(\operatorname{\alpha}(N))$ となり，実用上  $\mathcal{O}(1)$ とみなせる（ただし，$\operatorname{\alpha}(x)$ はアッカーマン関数の逆関数）．


## 参考文献

1. drken. "重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて". Qiita. <https://qiita.com/drken/items/cce6fc5c579051e64fab>.


## 問題

- "D - People on a Line". AtCoder Beginner Contest 087. AtCoder. <https://atcoder.jp/contests/abc087/tasks/arc090_b>.
