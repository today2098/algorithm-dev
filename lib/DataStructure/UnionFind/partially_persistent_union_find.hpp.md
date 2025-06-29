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
  bundledCode: "#line 1 \"lib/DataStructure/UnionFind/partially_persistent_union_find.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u90E8\u5206\u6C38\u7D9AUnion-Find\uFF0E\
    \nclass PartiallyPersistentUnionFind {\n    int m_now;  // m_now:=(\u73FE\u5728\
    \u6642\u523B).\n    int m_vn;   // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;\
    \   // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x][]:=(\u8981\u7D20x\u306B\
    \u3064\u3044\u3066\u6642\u523Bt\u3068\u305D\u306E\u6642\u523B\u306B\u304A\u3051\
    \u308B\u89AApar\u306E\u60C5\u5831\u30EA\u30B9\u30C8). pair of (t, par).\n    //\
    \ \u5024par\u304C0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\u5143\
    \u3067\u3042\u308A\uFF0C\u5024par\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\
    \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<std::vector<std::pair<int,\
    \ int>>> m_par;\n\n    std::tuple<int, int, int> root_internal(int x) const {\n\
    \        if(m_par[x].back().second < 0) return {m_par[x].back().first, x, -m_par[x].back().second};\
    \  // return tuple of (t, root, size).\n        return root_internal(m_par[x].back().second);\n\
    \    }\n    std::tuple<int, int, int> root_internal(int x, int t) const {\n  \
    \      auto iter = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(), std::pair<int,\
    \ int>(t, -m_vn));\n        if(iter == m_par[x].cend() or iter->first > t) --iter;\n\
    \        if(iter->second < 0) return {iter->first, x, -iter->second};  // return\
    \ tuple of (t, root, size).\n        return root_internal(iter->second, t);\n\
    \    }\n\npublic:\n    PartiallyPersistentUnionFind() : PartiallyPersistentUnionFind(0)\
    \ {}\n    explicit PartiallyPersistentUnionFind(int n)\n        : m_now(0), m_vn(n),\
    \ m_gn(n), m_par(n, std::vector<std::pair<int, int>>({{0, -1}})) {\n        assert(n\
    \ >= 0);\n    }\n\n    // \u73FE\u5728\u306E\u6642\u523B\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    int now() const { return m_now; }\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int gn() const\
    \ { return m_gn; };\n    // \u73FE\u6642\u523B\u306B\u304A\u3044\u3066\u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(log N).\n    int root(int x) const {\n        assert(0 <=\
    \ x and x < vn());\n        return std::get<1>(root_internal(x));\n    }\n   \
    \ // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\
    \u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\uFF0EO(log N).\n    int\
    \ root(int x, int t) const {\n        assert(0 <= x and x < vn());\n        assert(0\
    \ <= t and t <= now());\n        return std::get<1>(root_internal(x, t));\n  \
    \  }\n    // \u73FE\u6642\u523B\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(log N).\n    int size(int x) const {\n        assert(0 <= x and x < vn());\n\
    \        return std::get<2>(root_internal(x));\n    }\n    // \u6642\u523Bt\u306B\
    \u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(log N).\n    int size(int x,\
    \ int t) const {\n        assert(0 <= x and x < vn());\n        assert(0 <= t\
    \ and t <= now());\n        return std::get<2>(root_internal(x, t));\n    }\n\
    \    // \u73FE\u5728\u306B\u304A\u3044\u3066\u8981\u7D20x, y\u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(log\
    \ N).\n    bool is_same(int x, int y) const { return root(x) == root(y); }\n \
    \   // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20x, y\u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(log\
    \ N).\n    bool is_same(int x, int y, int t) const { return root(x, t) == root(y,\
    \ t); }\n    // \u8981\u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\u308C\u305E\u308C\
    \u306E\u96C6\u5408\u3092\u5408\u4F75\u3057\uFF0C\u6642\u9593\u3092+1\u9032\u3081\
    \u308B\uFF0EO(log N).\n    bool unite(int x, int y) {\n        assert(0 <= x and\
    \ x < vn());\n        assert(0 <= y and y < vn());\n        ++m_now;\n       \
    \ auto [_, xr, sz_x] = root_internal(x);\n        auto [__, yr, sz_y] = root_internal(y);\n\
    \        if(xr == yr) return false;\n        if(sz_x < sz_y) std::swap(xr, yr);\
    \  // Merge technique (union by size).\n        m_par[xr].emplace_back(m_now,\
    \ -sz_x - sz_y);\n        m_par[yr].emplace_back(m_now, xr);\n        --m_gn;\n\
    \        return true;\n    }\n    void reset() {\n        m_now = 0, m_gn = m_vn;\n\
    \        for(auto &history : m_par) history.resize(1);\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP\n#define ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u90E8\u5206\u6C38\u7D9AUnion-Find\uFF0E\
    \nclass PartiallyPersistentUnionFind {\n    int m_now;  // m_now:=(\u73FE\u5728\
    \u6642\u523B).\n    int m_vn;   // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;\
    \   // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x][]:=(\u8981\u7D20x\u306B\
    \u3064\u3044\u3066\u6642\u523Bt\u3068\u305D\u306E\u6642\u523B\u306B\u304A\u3051\
    \u308B\u89AApar\u306E\u60C5\u5831\u30EA\u30B9\u30C8). pair of (t, par).\n    //\
    \ \u5024par\u304C0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\u5143\
    \u3067\u3042\u308A\uFF0C\u5024par\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\
    \u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<std::vector<std::pair<int,\
    \ int>>> m_par;\n\n    std::tuple<int, int, int> root_internal(int x) const {\n\
    \        if(m_par[x].back().second < 0) return {m_par[x].back().first, x, -m_par[x].back().second};\
    \  // return tuple of (t, root, size).\n        return root_internal(m_par[x].back().second);\n\
    \    }\n    std::tuple<int, int, int> root_internal(int x, int t) const {\n  \
    \      auto iter = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(), std::pair<int,\
    \ int>(t, -m_vn));\n        if(iter == m_par[x].cend() or iter->first > t) --iter;\n\
    \        if(iter->second < 0) return {iter->first, x, -iter->second};  // return\
    \ tuple of (t, root, size).\n        return root_internal(iter->second, t);\n\
    \    }\n\npublic:\n    PartiallyPersistentUnionFind() : PartiallyPersistentUnionFind(0)\
    \ {}\n    explicit PartiallyPersistentUnionFind(int n)\n        : m_now(0), m_vn(n),\
    \ m_gn(n), m_par(n, std::vector<std::pair<int, int>>({{0, -1}})) {\n        assert(n\
    \ >= 0);\n    }\n\n    // \u73FE\u5728\u306E\u6642\u523B\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    int now() const { return m_now; }\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int gn() const\
    \ { return m_gn; };\n    // \u73FE\u6642\u523B\u306B\u304A\u3044\u3066\u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(log N).\n    int root(int x) const {\n        assert(0 <=\
    \ x and x < vn());\n        return std::get<1>(root_internal(x));\n    }\n   \
    \ // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\
    \u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\uFF0EO(log N).\n    int\
    \ root(int x, int t) const {\n        assert(0 <= x and x < vn());\n        assert(0\
    \ <= t and t <= now());\n        return std::get<1>(root_internal(x, t));\n  \
    \  }\n    // \u73FE\u6642\u523B\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(log N).\n    int size(int x) const {\n        assert(0 <= x and x < vn());\n\
    \        return std::get<2>(root_internal(x));\n    }\n    // \u6642\u523Bt\u306B\
    \u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\
    \u30A4\u30BA\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(log N).\n    int size(int x,\
    \ int t) const {\n        assert(0 <= x and x < vn());\n        assert(0 <= t\
    \ and t <= now());\n        return std::get<2>(root_internal(x, t));\n    }\n\
    \    // \u73FE\u5728\u306B\u304A\u3044\u3066\u8981\u7D20x, y\u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(log\
    \ N).\n    bool is_same(int x, int y) const { return root(x) == root(y); }\n \
    \   // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20x, y\u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(log\
    \ N).\n    bool is_same(int x, int y, int t) const { return root(x, t) == root(y,\
    \ t); }\n    // \u8981\u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\u308C\u305E\u308C\
    \u306E\u96C6\u5408\u3092\u5408\u4F75\u3057\uFF0C\u6642\u9593\u3092+1\u9032\u3081\
    \u308B\uFF0EO(log N).\n    bool unite(int x, int y) {\n        assert(0 <= x and\
    \ x < vn());\n        assert(0 <= y and y < vn());\n        ++m_now;\n       \
    \ auto [_, xr, sz_x] = root_internal(x);\n        auto [__, yr, sz_y] = root_internal(y);\n\
    \        if(xr == yr) return false;\n        if(sz_x < sz_y) std::swap(xr, yr);\
    \  // Merge technique (union by size).\n        m_par[xr].emplace_back(m_now,\
    \ -sz_x - sz_y);\n        m_par[yr].emplace_back(m_now, xr);\n        --m_gn;\n\
    \        return true;\n    }\n    void reset() {\n        m_now = 0, m_gn = m_vn;\n\
    \        for(auto &history : m_par) history.resize(1);\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/UnionFind/partially_persistent_union_find.hpp
  requiredBy: []
  timestamp: '2025-06-22 02:23:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/DataStructure/UnionFind/partially_persistent_union_find.hpp
layout: document
title: "Partially Persistent Union-Find\uFF08\u90E8\u5206\u6C38\u7D9AUnionf-Find\uFF09"
---


## 概要

「部分永続 Union-Find」では，通常の Union-Find の機能に加え，過去の状態に対してクエリを求めることができる．
ただし，更新が行えるのは最新の状態に対してのみ．

本実装では「union by size」の工夫のみ行い，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考

1. "Union-Find木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/union_find_tree>.
1. "やぶについて書きます". <https://camypaper.bitbucket.io/2016/12/18/adc2016/>.


## 問題

- "H - Union Sets". CODE THANKS FESTIVAL 2017(Parallel). AtCoder. <https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h>.
