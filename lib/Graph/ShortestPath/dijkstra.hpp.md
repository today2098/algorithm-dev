---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_1_A-dijkstra.test.cpp
    title: verify/aoj-GRL_1_A-dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Graph/ShortestPath/dijkstra.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\nnamespace dijkstra\
    \ {\n\ntemplate <typename T, auto inf>\nclass Dijkstra {\n    static_assert(std::is_invocable_r<T,\
    \ decltype(inf)>::value);\n\npublic:\n    using value_type = T;\n    using weighted_graph_type\
    \ = std::vector<std::vector<std::pair<int, value_type>>>;\n\nprivate:\n    int\
    \ m_vn;                     // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    weighted_graph_type\
    \ m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ). pair of (to, weight).\n    std::vector<value_type> m_d;  // m_d[t]:=(\u30CE\
    \u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2).\n    std::vector<int>\
    \ m_pre;       // m_pre[t]:=(\u30CE\u30FC\u30C9t\u3092\u8A2A\u554F\u3059\u308B\
    \u76F4\u524D\u306E\u30CE\u30FC\u30C9\u756A\u53F7). \u9006\u65B9\u5411\u7D4C\u8DEF\
    \uFF0E\n\npublic:\n    Dijkstra() : Dijkstra(0) {}\n    explicit Dijkstra(int\
    \ vn) : m_vn(vn), m_g(vn), m_d(vn, inf()), m_pre(vn, -1) {\n        assert(vn\
    \ >= 0);\n    }\n\n    static constexpr value_type infinity() { return inf();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\
    \u5F35\u308B\uFF0E\n    void add_edge(int from, int to, value_type weight) {\n\
    \        assert(0 <= from and from < order());\n        assert(0 <= to and to\
    \ < order());\n        m_g[from].emplace_back(to, weight);\n    }\n    // \u30CE\
    \u30FC\u30C9s\u304B\u3089\u5404\u30CE\u30FC\u30C9\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B\uFF0EO(|E| log |V|).\n    void dijkstra(int s)\
    \ {\n        assert(0 <= s and s < order());\n        std::fill(m_d.begin(), m_d.end(),\
    \ inf());\n        m_d[s] = 0;\n        std::fill(m_pre.begin(), m_pre.end(),\
    \ -1);\n        std::priority_queue<std::pair<value_type, int>, std::vector<std::pair<value_type,\
    \ int>>, std::greater<std::pair<value_type, int>>> pque;\n        pque.emplace(0,\
    \ s);\n        while(!pque.empty()) {\n            const auto [dist, v] = pque.top();\n\
    \            pque.pop();\n            if(m_d[v] < dist) continue;\n          \
    \  for(const auto &[to, weight] : m_g[v]) {\n                if(m_d[to] > m_d[v]\
    \ + weight) {\n                    m_d[to] = m_d[v] + weight;\n              \
    \      m_pre[to] = v;\n                    pque.emplace(m_d[to], to);\n      \
    \          }\n            }\n        }\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    value_type distance(int t) const {\n        assert(0 <= t and t < order());\n\
    \        return m_d[t];\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u3092\u5FA9\u5143\u3059\u308B\uFF0E\n    std::vector<int>\
    \ shortest_path(int t) const {\n        assert(0 <= t and t < order());\n    \
    \    std::vector<int> path;\n        if(distance(t) == inf()) return path;\n \
    \       for(; t != -1; t = m_pre[t]) path.push_back(t);\n        path.shrink_to_fit();\n\
    \        std::reverse(path.begin(), path.end());\n        return path;\n    }\n\
    };\n\ntemplate <typename T>\nusing default_dijkstra = Dijkstra<T, std::numeric_limits<T>::max>;\n\
    \n}  // namespace dijkstra\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DIJKSTRA_HPP\n#define ALGORITHM_DIJKSTRA_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace dijkstra {\n\ntemplate <typename T, auto inf>\nclass Dijkstra\
    \ {\n    static_assert(std::is_invocable_r<T, decltype(inf)>::value);\n\npublic:\n\
    \    using value_type = T;\n    using weighted_graph_type = std::vector<std::vector<std::pair<int,\
    \ value_type>>>;\n\nprivate:\n    int m_vn;                     // m_vn:=(\u30CE\
    \u30FC\u30C9\u6570).\n    weighted_graph_type m_g;      // m_g[v][]:=(\u30CE\u30FC\
    \u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8). pair of (to, weight).\n    std::vector<value_type>\
    \ m_d;  // m_d[t]:=(\u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2).\n    std::vector<int> m_pre;       // m_pre[t]:=(\u30CE\u30FC\u30C9t\u3092\
    \u8A2A\u554F\u3059\u308B\u76F4\u524D\u306E\u30CE\u30FC\u30C9\u756A\u53F7). \u9006\
    \u65B9\u5411\u7D4C\u8DEF\uFF0E\n\npublic:\n    Dijkstra() : Dijkstra(0) {}\n \
    \   explicit Dijkstra(int vn) : m_vn(vn), m_g(vn), m_d(vn, inf()), m_pre(vn, -1)\
    \ {\n        assert(vn >= 0);\n    }\n\n    static constexpr value_type infinity()\
    \ { return inf(); }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n\
    \    int order() const { return m_vn; }\n    // \u91CD\u307F\u4ED8\u304D\u6709\
    \u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int from, int to, value_type\
    \ weight) {\n        assert(0 <= from and from < order());\n        assert(0 <=\
    \ to and to < order());\n        m_g[from].emplace_back(to, weight);\n    }\n\
    \    // \u30CE\u30FC\u30C9s\u304B\u3089\u5404\u30CE\u30FC\u30C9\u3078\u306E\u6700\
    \u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\uFF0EO(|E| log |V|).\n    void dijkstra(int\
    \ s) {\n        assert(0 <= s and s < order());\n        std::fill(m_d.begin(),\
    \ m_d.end(), inf());\n        m_d[s] = 0;\n        std::fill(m_pre.begin(), m_pre.end(),\
    \ -1);\n        std::priority_queue<std::pair<value_type, int>, std::vector<std::pair<value_type,\
    \ int>>, std::greater<std::pair<value_type, int>>> pque;\n        pque.emplace(0,\
    \ s);\n        while(!pque.empty()) {\n            const auto [dist, v] = pque.top();\n\
    \            pque.pop();\n            if(m_d[v] < dist) continue;\n          \
    \  for(const auto &[to, weight] : m_g[v]) {\n                if(m_d[to] > m_d[v]\
    \ + weight) {\n                    m_d[to] = m_d[v] + weight;\n              \
    \      m_pre[to] = v;\n                    pque.emplace(m_d[to], to);\n      \
    \          }\n            }\n        }\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    value_type distance(int t) const {\n        assert(0 <= t and t < order());\n\
    \        return m_d[t];\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u3092\u5FA9\u5143\u3059\u308B\uFF0E\n    std::vector<int>\
    \ shortest_path(int t) const {\n        assert(0 <= t and t < order());\n    \
    \    std::vector<int> path;\n        if(distance(t) == inf()) return path;\n \
    \       for(; t != -1; t = m_pre[t]) path.push_back(t);\n        path.shrink_to_fit();\n\
    \        std::reverse(path.begin(), path.end());\n        return path;\n    }\n\
    };\n\ntemplate <typename T>\nusing default_dijkstra = Dijkstra<T, std::numeric_limits<T>::max>;\n\
    \n}  // namespace dijkstra\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/ShortestPath/dijkstra.hpp
  requiredBy: []
  timestamp: '2025-06-21 17:21:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_1_A-dijkstra.test.cpp
documentation_of: lib/Graph/ShortestPath/dijkstra.hpp
layout: document
title: "Dijkstra's Algorithm\uFF08\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
  \uFF09"
---


## 概要

重み付き有向グラフにおける単一始点最短経路問題を解くアルゴリズム．
前提条件はグラフに負閉路がないこと．
1959年に Edsger W. Dijkstra によって考案された．

本実装では優先度付きキューを用いて高速化を図っている．

計算量は，グラフの頂点集合を $V$，辺集合を $E$ とすると，$\mathcal{O}(\lvert E \rvert \log \lvert V \rvert)$ となる．


## 参考

1. 大槻兼資著. "14.6 単一始点最短路問題：ダイクストラ法". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, pp.254-264.
1. "22.3 Dijkstraのアルゴリズム". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.522-527.
1. "ダイクストラ法". Wikipedia. <https://ja.wikipedia.org/wiki/ダイクストラ法>.
