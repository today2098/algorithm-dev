---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
    title: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
    title: verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\n\
    \n\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename T>\nclass\
    \ BIT {\npublic:\n    using value_type = T;\n\nprivate:\n    int m_sz;  // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<value_type> m_tree;\n\n    static constexpr int\
    \ lsb(int bit) { return bit & -bit; }\n    void build() {\n        for(int i =\
    \ 1, end = size(); i < end; ++i) {\n            int j = i + lsb(i);\n        \
    \    if(j <= end) m_tree[j - 1] += m_tree[i - 1];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT() : BIT(0) {};\n    explicit BIT(int n) :\
    \ m_sz(n), m_tree(n, value_type()) {\n        assert(n >= 0);\n    }\n    explicit\
    \ BIT(int n, const value_type &a) : m_sz(n), m_tree(n, a) {\n        assert(n\
    \ >= 0);\n        if(a != value_type()) build();\n    }\n    explicit BIT(const\
    \ std::vector<value_type> &v) : m_sz(v.size()), m_tree(v) {\n        build();\n\
    \    }\n    explicit BIT(std::vector<value_type> &&v) : m_sz(v.size()), m_tree(std::move(v))\
    \ {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\
    \u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0EO(logN).\n    void add(int\
    \ k, const value_type &a) {\n        assert(0 <= k and k < size());\n        for(int\
    \ i = k + 1, end = size(); i <= end; i += lsb(i)) m_tree[i - 1] += a;\n    }\n\
    \    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\
    \u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0 <= r and r <=\
    \ size());\n        T res = value_type();\n        for(int i = r; i >= 1; i -=\
    \ lsb(i)) res += m_tree[i - 1];\n        return res;\n    }\n    // \u533A\u9593\
    [l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n\
    \    T sum(int l, int r) const {\n        assert(0 <= l and l < r and r <= size());\n\
    \        return sum(r) - sum(l);\n    }\n    void reset() { std::fill(m_tree.begin(),\
    \ m_tree.end(), value_type()); }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename\
    \ T>\nclass BIT {\npublic:\n    using value_type = T;\n\nprivate:\n    int m_sz;\
    \  // m_sz:=(\u8981\u7D20\u6570).\n    std::vector<value_type> m_tree;\n\n   \
    \ static constexpr int lsb(int bit) { return bit & -bit; }\n    void build() {\n\
    \        for(int i = 1, end = size(); i < end; ++i) {\n            int j = i +\
    \ lsb(i);\n            if(j <= end) m_tree[j - 1] += m_tree[i - 1];\n        }\n\
    \    }\n\npublic:\n    // constructor. O(N).\n    BIT() : BIT(0) {};\n    explicit\
    \ BIT(int n) : m_sz(n), m_tree(n, value_type()) {\n        assert(n >= 0);\n \
    \   }\n    explicit BIT(int n, const value_type &a) : m_sz(n), m_tree(n, a) {\n\
    \        assert(n >= 0);\n        if(a != value_type()) build();\n    }\n    explicit\
    \ BIT(const std::vector<value_type> &v) : m_sz(v.size()), m_tree(v) {\n      \
    \  build();\n    }\n    explicit BIT(std::vector<value_type> &&v) : m_sz(v.size()),\
    \ m_tree(std::move(v)) {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0E\
    O(logN).\n    void add(int k, const value_type &a) {\n        assert(0 <= k and\
    \ k < size());\n        for(int i = k + 1, end = size(); i <= end; i += lsb(i))\
    \ m_tree[i - 1] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n\
    \        assert(0 <= r and r <= size());\n        T res = value_type();\n    \
    \    for(int i = r; i >= 1; i -= lsb(i)) res += m_tree[i - 1];\n        return\
    \ res;\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const {\n        assert(0\
    \ <= l and l < r and r <= size());\n        return sum(r) - sum(l);\n    }\n \
    \   void reset() { std::fill(m_tree.begin(), m_tree.end(), value_type()); }\n\
    };\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2025-03-24 17:00:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  - verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  - verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
documentation_of: lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
layout: document
title: Binary Indexed Tree
---


## 概要

1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対して，次のクエリ処理 (RSM: Range Sum Query) を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総和を求める．

任意の区間 $[l,r)$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ と求めればよい．

必要なメモリサイズは，対象の配列サイズと同じ（Segment Tree では2倍程度必要となる）．

本実装の Binary Indexed Tree (BIT) は，数の加算のみをサポートしているが，拡張すればアーベル群（可換群）を成す他の演算もサポートすることができる．

ここで「アーベル群」とは，集合 $G$ と二項演算 $\ast : S \times S \rightarrow S$ の組 $(G, \ast)$ で，以下の条件を満たす代数構造のことを指す．

1. 結合法則：$a \ast (b \ast c) = (a \ast b) \ast c \quad (\forall a, \forall b, \forall c \in G)$
1. 単位元の存在：$e \ast a = a \ast e = a \quad (\exists e, \forall a \in G)$
1. **逆元の存在**：$a \ast a^{-1} = a^{-1} \ast a = e \quad (\exists e, \forall a, \exists a^{-1} \in G)$
1. **交換法則**：$a \ast b = b \ast a \quad (\forall a, \forall b \in G)$

Segment Tree が扱うのは「モノイド」であり，モノイドは上記条件の (1), (2) のみを満たせばよい．
それに対し，BIT は条件 (3), (4) が加わり制約が厳しい．


## 参考文献

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "アーベル群". Wikipedia. <https://ja.wikipedia.org/wiki/アーベル群>.
1. ngtkana. "データ構造 Fenwick tree (binary indexed tree, BIT) にどっぷりと入門し、その美しき構造に心を洗われたい方のための紹介記事です！". Qiita. <https://qiita.com/ngtkana/items/7d50ff180a4e5c294cb7>.
1. sysdev. "AtCoder Library を読んでアルゴリズムを勉強：フェニック木（BIT）". Qiita. <https://qiita.com/sysdev/items/30aa7d5e9ac4ea871bd3>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 問題

- "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
