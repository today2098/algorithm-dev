---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_1_B-bellman_ford.test.cpp
    title: verify/aoj-GRL_1_B-bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Graph/ShortestPath/bellman_ford.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <vector>\n\nnamespace algorithm {\n\nnamespace bellman_ford\
    \ {\n\ntemplate <typename T, auto inf>\nclass BellmanFord {\n    static_assert(std::is_invocable_r<T,\
    \ decltype(inf)>::value);\n\npublic:\n    using value_type = T;\n    using weighted_edge_type\
    \ = std::tuple<int, int, value_type>;  // tuple of (from, to, weight).\n\nprivate:\n\
    \    int m_vn;                                 // m_vn:=(\u30CE\u30FC\u30C9\u6570\
    ).\n    std::vector<weighted_edge_type> m_edges;  // m_edges[]:=(\u8FBA\u30EA\u30B9\
    \u30C8).\n    std::vector<value_type> m_d;              // m_d[t]:=(\u30CE\u30FC\
    \u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2).\n    std::vector<int>\
    \ m_pre;                   // m_pre[t]:=(\u30CE\u30FC\u30C9t\u3092\u8A2A\u554F\
    \u3059\u308B\u76F4\u524D\u306E\u30CE\u30FC\u30C9\u756A\u53F7). \u9006\u65B9\u5411\
    \u7D4C\u8DEF\uFF0E\n\npublic:\n    BellmanFord() : BellmanFord(0) {}\n    explicit\
    \ BellmanFord(int vn) : m_vn(vn), m_d(vn, inf()), m_pre(vn, -1) {\n        assert(vn\
    \ >= 0);\n    }\n    explicit BellmanFord(int vn, int en) : BellmanFord(vn) {\n\
    \        assert(en >= 0);\n        m_edges.reserve(en);\n    }\n\n    static constexpr\
    \ value_type infinity() { return inf(); }\n    // \u30CE\u30FC\u30C9\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int order() const { return m_vn; }\n    // \u8FBA\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_edges.size(); }\n  \
    \  // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n   \
    \ void add_edge(int from, int to, value_type weight) {\n        assert(0 <= from\
    \ and from < order());\n        assert(0 <= to and to < order());\n        m_edges.emplace_back(from,\
    \ to, weight);\n    }\n    // \u30B0\u30E9\u30D5\u5168\u4F53\u304B\u3089\u8CA0\
    \u9589\u8DEF\u3092\u691C\u51FA\u3059\u308B\uFF0EO(|V||E|).\n    bool find_negative_cycle()\
    \ const {\n        std::vector<value_type> nd(m_vn, 0);\n        for(int i = 0;\
    \ i < m_vn; ++i) {\n            bool update = false;\n            for(const auto\
    \ &[from, to, weight] : m_edges) {\n                if(nd[to] > nd[from] + weight)\
    \ {\n                    nd[to] = nd[from] + weight;\n                    update\
    \ = true;\n                }\n            }\n            if(!update) return false;\
    \  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\n        }\n        return true;  //\
    \ \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089\u5404\u30CE\u30FC\u30C9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308B\uFF0EO(|V||E|).\n    bool bellman_ford(int s) {\n        assert(0\
    \ <= s and s < order());\n        std::fill(m_d.begin(), m_d.end(), inf());\n\
    \        m_d[s] = 0;\n        std::fill(m_pre.begin(), m_pre.end(), -1);\n   \
    \     for(int i = 0; i < m_vn; ++i) {\n            bool update = false;\n    \
    \        for(const auto &[from, to, weight] : m_edges) {\n                if(m_d[from]\
    \ == inf()) continue;\n                if(m_d[to] > m_d[from] + weight) {\n  \
    \                  m_d[to] = m_d[from] + weight;\n                    m_pre[to]\
    \ = from;\n                    update = true;\n                }\n           \
    \ }\n            if(!update) return false;  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\
    \n        }\n        for(int i = 0; i < m_vn; ++i) {\n            bool update\
    \ = false;\n            for(const auto &[from, to, weight] : m_edges) {\n    \
    \            if(m_d[from] == inf() or m_d[to] == -inf()) continue;\n         \
    \       if(m_d[from] == -inf() or m_d[to] > m_d[from] + weight) {\n          \
    \          m_d[to] = -inf();\n                    update = true;\n           \
    \     }\n            }\n            if(!update) break;\n        }\n        return\
    \ true;  // \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n    }\n    // \u30CE\u30FC\u30C9\
    s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E\n    value_type distance(int t) const {\n        assert(0 <= t and t <\
    \ order());\n        return m_d[t];\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089\
    t\u3078\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u5FA9\u5143\u3059\u308B\uFF0E\n  \
    \  std::vector<int> shortest_path(int t) const {\n        assert(0 <= t and t\
    \ < order());\n        std::vector<int> path;\n        if(distance(t) == -inf()\
    \ or distance(t) == inf()) return path;\n        for(; t != -1; t = m_pre[t])\
    \ path.push_back(t);\n        path.shrink_to_fit();\n        std::reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n};\n\ntemplate <typename T>\nusing\
    \ default_bellman_ford = BellmanFord<T, std::numeric_limits<T>::max>;\n\n}  //\
    \ namespace bellman_ford\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BELLMAN_FORD_HPP\n#define ALGORITHM_BELLMAN_FORD_HPP 1\n\
    \n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <tuple>\n\
    #include <type_traits>\n#include <vector>\n\nnamespace algorithm {\n\nnamespace\
    \ bellman_ford {\n\ntemplate <typename T, auto inf>\nclass BellmanFord {\n   \
    \ static_assert(std::is_invocable_r<T, decltype(inf)>::value);\n\npublic:\n  \
    \  using value_type = T;\n    using weighted_edge_type = std::tuple<int, int,\
    \ value_type>;  // tuple of (from, to, weight).\n\nprivate:\n    int m_vn;   \
    \                              // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<weighted_edge_type>\
    \ m_edges;  // m_edges[]:=(\u8FBA\u30EA\u30B9\u30C8).\n    std::vector<value_type>\
    \ m_d;              // m_d[t]:=(\u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\
    \u77ED\u8DDD\u96E2).\n    std::vector<int> m_pre;                   // m_pre[t]:=(\u30CE\
    \u30FC\u30C9t\u3092\u8A2A\u554F\u3059\u308B\u76F4\u524D\u306E\u30CE\u30FC\u30C9\
    \u756A\u53F7). \u9006\u65B9\u5411\u7D4C\u8DEF\uFF0E\n\npublic:\n    BellmanFord()\
    \ : BellmanFord(0) {}\n    explicit BellmanFord(int vn) : m_vn(vn), m_d(vn, inf()),\
    \ m_pre(vn, -1) {\n        assert(vn >= 0);\n    }\n    explicit BellmanFord(int\
    \ vn, int en) : BellmanFord(vn) {\n        assert(en >= 0);\n        m_edges.reserve(en);\n\
    \    }\n\n    static constexpr value_type infinity() { return inf(); }\n    //\
    \ \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return\
    \ m_vn; }\n    // \u8FBA\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const {\
    \ return m_edges.size(); }\n    // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\
    \u5F35\u308B\uFF0E\n    void add_edge(int from, int to, value_type weight) {\n\
    \        assert(0 <= from and from < order());\n        assert(0 <= to and to\
    \ < order());\n        m_edges.emplace_back(from, to, weight);\n    }\n    //\
    \ \u30B0\u30E9\u30D5\u5168\u4F53\u304B\u3089\u8CA0\u9589\u8DEF\u3092\u691C\u51FA\
    \u3059\u308B\uFF0EO(|V||E|).\n    bool find_negative_cycle() const {\n       \
    \ std::vector<value_type> nd(m_vn, 0);\n        for(int i = 0; i < m_vn; ++i)\
    \ {\n            bool update = false;\n            for(const auto &[from, to,\
    \ weight] : m_edges) {\n                if(nd[to] > nd[from] + weight) {\n   \
    \                 nd[to] = nd[from] + weight;\n                    update = true;\n\
    \                }\n            }\n            if(!update) return false;  // \u8CA0\
    \u9589\u8DEF\u306A\u3057\uFF0E\n        }\n        return true;  // \u8CA0\u9589\
    \u8DEF\u3042\u308A\uFF0E\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089\u5404\u30CE\
    \u30FC\u30C9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\uFF0E\
    O(|V||E|).\n    bool bellman_ford(int s) {\n        assert(0 <= s and s < order());\n\
    \        std::fill(m_d.begin(), m_d.end(), inf());\n        m_d[s] = 0;\n    \
    \    std::fill(m_pre.begin(), m_pre.end(), -1);\n        for(int i = 0; i < m_vn;\
    \ ++i) {\n            bool update = false;\n            for(const auto &[from,\
    \ to, weight] : m_edges) {\n                if(m_d[from] == inf()) continue;\n\
    \                if(m_d[to] > m_d[from] + weight) {\n                    m_d[to]\
    \ = m_d[from] + weight;\n                    m_pre[to] = from;\n             \
    \       update = true;\n                }\n            }\n            if(!update)\
    \ return false;  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\n        }\n        for(int\
    \ i = 0; i < m_vn; ++i) {\n            bool update = false;\n            for(const\
    \ auto &[from, to, weight] : m_edges) {\n                if(m_d[from] == inf()\
    \ or m_d[to] == -inf()) continue;\n                if(m_d[from] == -inf() or m_d[to]\
    \ > m_d[from] + weight) {\n                    m_d[to] = -inf();\n           \
    \         update = true;\n                }\n            }\n            if(!update)\
    \ break;\n        }\n        return true;  // \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\
    \n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    value_type distance(int t) const\
    \ {\n        assert(0 <= t and t < order());\n        return m_d[t];\n    }\n\
    \    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u5FA9\u5143\u3059\u308B\uFF0E\n    std::vector<int> shortest_path(int t) const\
    \ {\n        assert(0 <= t and t < order());\n        std::vector<int> path;\n\
    \        if(distance(t) == -inf() or distance(t) == inf()) return path;\n    \
    \    for(; t != -1; t = m_pre[t]) path.push_back(t);\n        path.shrink_to_fit();\n\
    \        std::reverse(path.begin(), path.end());\n        return path;\n    }\n\
    };\n\ntemplate <typename T>\nusing default_bellman_ford = BellmanFord<T, std::numeric_limits<T>::max>;\n\
    \n}  // namespace bellman_ford\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/ShortestPath/bellman_ford.hpp
  requiredBy: []
  timestamp: '2025-06-21 17:21:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_1_B-bellman_ford.test.cpp
documentation_of: lib/Graph/ShortestPath/bellman_ford.hpp
layout: document
title: "Bellman-Ford Algorithm\uFF08\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
  \uFF09"
---


## 概要

重み付き有向グラフにおける単一始点最短経路問題を解くアルゴリズム．
グラフの負閉路検出も行うことができる．
1956年と1958年に，L. R. Ford Jr. と Richard E. Bellman がそれぞれ独立に考案した．

計算量は，グラフの頂点集合を $V$，辺集合を $E$ とすると，$\mathcal{O}(\lvert V \rvert \lvert E \rvert)$ となる．


## 参考

1. 大槻兼資著. "14.5 単一始点最短路問題：ベルマン・フォード法". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, p.249-254.
1. "22.1 Bellman-Fordのアルゴリズム". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.515-519.
1. "ベルマン–フォード法". Wikipedia. <https://ja.wikipedia.org/wiki/ベルマン–フォード法>.
