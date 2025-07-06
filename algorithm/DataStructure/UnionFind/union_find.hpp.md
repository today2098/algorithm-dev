---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_1_A-union_find.test.cpp
    title: verify/aoj-DSL_1_A-union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/DataStructure/UnionFind/union_find.hpp\"\n\n\n\
    \n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\nclass UnionFind {\n    int m_vn;  // m_vn:=(\u8981\u7D20\
    \u6570).\n    int m_gn;  // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x]:=(\u8981\
    \u7D20x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\
    \u5143\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\
    \u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int>\
    \ m_par;\n\n    int root_internal(int x) {\n        if(m_par[x] < 0) return x;\n\
    \        return m_par[x] = root_internal(m_par[x]);  // \u7D4C\u8DEF\u5727\u7E2E\
    \uFF0E\n    }\n\npublic:\n    UnionFind() : UnionFind(0) {}\n    explicit UnionFind(int\
    \ n) : m_vn(n), m_gn(n), m_par(n, -1) {\n        assert(n >= 0);\n    }\n\n  \
    \  // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vn() const\
    \ { return m_vn; };\n    // \u96C6\u5408\u306E\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E\n    int gn() const { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E\n    int root(int x) {\n        assert(0 <= x and x < vn());\n        return\
    \ root_internal(x);\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\
    \u5408\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size(int\
    \ x) {\n        assert(0 <= x and x < vn());\n        return -m_par[root_internal(x)];\n\
    \    }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_same(int x, int y) {\n\
    \        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        return root_internal(x) == root_internal(y);\n    }\n    // \u8981\u7D20\
    x, y\u304C\u5C5E\u3059\u308B\u305D\u308C\u305E\u308C\u306E\u96C6\u5408\u3092\u5408\
    \u4F75\u3059\u308B\uFF0E\n    bool unite(int x, int y) {\n        assert(0 <=\
    \ x and x < vn());\n        assert(0 <= y and y < vn());\n        x = root_internal(x),\
    \ y = root_internal(y);\n        if(x == y) return false;                    //\
    \ Do nothing.\n        if(-m_par[x] < -m_par[y]) std::swap(x, y);  // Merge technique\
    \ (union by size).\n        m_par[x] += m_par[y];\n        m_par[y] = x;\n   \
    \     --m_gn;\n        return true;\n    }\n    void reset() {\n        m_gn =\
    \ m_vn;\n        std::fill(m_par.begin(), m_par.end(), -1);\n    }\n};\n\n}  //\
    \ namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_UNION_FIND_HPP\n#define ALGORITHM_UNION_FIND_HPP 1\n\n\
    #include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\nclass UnionFind {\n    int m_vn;  // m_vn:=(\u8981\u7D20\
    \u6570).\n    int m_gn;  // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x]:=(\u8981\
    \u7D20x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\
    \u5143\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\
    \u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int>\
    \ m_par;\n\n    int root_internal(int x) {\n        if(m_par[x] < 0) return x;\n\
    \        return m_par[x] = root_internal(m_par[x]);  // \u7D4C\u8DEF\u5727\u7E2E\
    \uFF0E\n    }\n\npublic:\n    UnionFind() : UnionFind(0) {}\n    explicit UnionFind(int\
    \ n) : m_vn(n), m_gn(n), m_par(n, -1) {\n        assert(n >= 0);\n    }\n\n  \
    \  // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vn() const\
    \ { return m_vn; };\n    // \u96C6\u5408\u306E\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E\n    int gn() const { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E\n    int root(int x) {\n        assert(0 <= x and x < vn());\n        return\
    \ root_internal(x);\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\
    \u5408\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size(int\
    \ x) {\n        assert(0 <= x and x < vn());\n        return -m_par[root_internal(x)];\n\
    \    }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_same(int x, int y) {\n\
    \        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        return root_internal(x) == root_internal(y);\n    }\n    // \u8981\u7D20\
    x, y\u304C\u5C5E\u3059\u308B\u305D\u308C\u305E\u308C\u306E\u96C6\u5408\u3092\u5408\
    \u4F75\u3059\u308B\uFF0E\n    bool unite(int x, int y) {\n        assert(0 <=\
    \ x and x < vn());\n        assert(0 <= y and y < vn());\n        x = root_internal(x),\
    \ y = root_internal(y);\n        if(x == y) return false;                    //\
    \ Do nothing.\n        if(-m_par[x] < -m_par[y]) std::swap(x, y);  // Merge technique\
    \ (union by size).\n        m_par[x] += m_par[y];\n        m_par[y] = x;\n   \
    \     --m_gn;\n        return true;\n    }\n    void reset() {\n        m_gn =\
    \ m_vn;\n        std::fill(m_par.begin(), m_par.end(), -1);\n    }\n};\n\n}  //\
    \ namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/DataStructure/UnionFind/union_find.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_1_A-union_find.test.cpp
documentation_of: algorithm/DataStructure/UnionFind/union_find.hpp
layout: document
title: "Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\uFF09"
---


## 概要

「素集合データ構造 (disjoint-set data structure)」とは，互いに素な動的集合の族を管理する．
簡単にいうと，要素のグループ分けを管理するデータ構造である．

素集合データ構造に対する次の操作のアルゴリズムを「Union-Find」という．
1964年，Bernard A. Galler と Michael J. Fischer が効率的な手法を考案した．

- $\operatorname{Union}(x,y)$：2つの要素 $x, y$ がそれぞれ属する集合を1つに合併する
- $\operatorname{Find}(x)$：要素 $x$ が属する集合の代表元を求める

本実装では「素集合森 (disjoint-set forest)」を作成しており，「union by size」と「経路圧縮」による工夫を行っている．

各クエリ処理に要する計算量は，アッカーマン関数の逆関数を $\operatorname{\alpha}(x)$ とすると，$\mathcal{O}(\operatorname{\alpha}(N))$ となる．
アッカーマン関数の逆関数は，増加が非常に遅く，$x \leq 10^{80}$ に対し $\operatorname{\alpha}(x) \leq 4$ が成り立つため，実用上 $\mathcal{O}(1)$ とみなすことができる．


## 参考

1. Bernard A. Galler and Michael J. Fisher. 1964. An improved equivalence algorithm. Commun. ACM 7, 5 (May 1964), 301–303. <https://doi.org/10.1145/364099.364331>.
1. 大槻兼資著. "第11章 データ構造 (4)：Union-Find". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, pp.181-190.
1. "19 互いに素な集合族のためのデータ構造". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.439-460.
1. "素集合データ構造". Wikipedia. <https://ja.wikipedia.org/wiki/素集合データ構造>.
1. rsk0315. "α(n) とお近づきになりたい人のための記事". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/11/14/170423>.
1. "巨大数：アッカーマン関数とは". 高校数学の美しい物語. <https://manabitimes.jp/math/1010>.


## 問題

- "B - Union Find". AtCoder Typical Contest 001. AtCoder. <https://atcoder.jp/contests/atc001/tasks/unionfind_a>.
