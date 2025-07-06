---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_6_A-ford_fulkerson.test.cpp
    title: verify/aoj-GRL_6_A-ford_fulkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Graph/Flow/ford_fulkerson.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n\
    template <typename Flow>\nclass FordFulkerson {\npublic:\n    using flow_type\
    \ = Flow;\n\nprivate:\n    struct Edge {\n        int to;         // to:=(\u884C\
    \u304D\u5148\u30CE\u30FC\u30C9).\n        flow_type cap;  // cap:=(\u5BB9\u91CF\
    ).\n        int rev;        // rev:=(\u9006\u8FBA\u306E\u4F4D\u7F6E). m_g[to][rev]\u304C\
    \u9006\u8FBA\u3068\u306A\u308B\uFF0E\n\n        explicit Edge(int to, flow_type\
    \ cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    int m_vn;     \
    \                           // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<Edge>>\
    \ m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int>> m_pos;  // m_pos[]:=(i\u756A\u76EE\u306E\
    \u8FBA\u306E\u60C5\u5831). pair of (from, index).\n\npublic:\n    FordFulkerson()\
    \ : FordFulkerson(0) {}\n    explicit FordFulkerson(int n) : m_vn(n), m_g(n) {\n\
    \        assert(n >= 0);\n    }\n    explicit FordFulkerson(int vn, int en) :\
    \ FordFulkerson(vn) {\n        assert(en >= 0);\n        m_pos.reserve(en);\n\
    \    }\n\n    static constexpr flow_type infinity() { return std::numeric_limits<flow_type>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n   \
    \ int order() const { return m_vn; }\n    // \u8FBA\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    int size() const { return m_pos.size(); }\n    // \u5BB9\u91CF\
    cap\u306E\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int\
    \ from, int to, flow_type cap) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        assert(cap >= 0);\n      \
    \  int i = m_g[from].size(), j = m_g[to].size();\n        if(from == to) ++j;\n\
    \        m_g[from].emplace_back(to, cap, j);\n        m_g[to].emplace_back(from,\
    \ 0, i);\n        m_pos.emplace_back(from, i);\n        return size() - 1;\n \
    \   }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\
    \u6C42\u3081\u308B\uFF0EO(f*|E|).\n    flow_type max_flow(int s, int t) { return\
    \ max_flow(s, t, infinity()); }\n    flow_type max_flow(int s, int t, flow_type\
    \ flow) {\n        assert(0 <= s and s < order());\n        assert(0 <= t and\
    \ t < order());\n        flow_type res = 0;\n        while(res < flow) {\n   \
    \         std::vector<bool> seen(m_vn, false);\n            auto dfs = [&](auto\
    \ self, int v, flow_type flow) -> flow_type {\n                if(v == t) return\
    \ flow;\n                seen[v] = true;\n                for(Edge &e : m_g[v])\
    \ {\n                    if(seen[e.to] or e.cap == 0) continue;\n            \
    \        flow_type res = self(self, e.to, std::min(flow, e.cap));\n          \
    \          if(res == 0) continue;\n                    e.cap -= res;\n       \
    \             m_g[e.to][e.rev].cap += res;\n                    return res;\n\
    \                }\n                return 0;\n            };\n            flow_type\
    \ tmp = dfs(dfs, s, flow - res);\n            if(tmp == 0) break;\n          \
    \  res += tmp;\n        }\n        return res;\n    }\n    // i\u756A\u76EE\u306E\
    \u8FBA\u306E\u60C5\u5831\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    std::tuple<int,\
    \ int, flow_type, flow_type> get_edge(int i) const {\n        assert(0 <= i and\
    \ i < size());\n        const auto &[from, idx] = m_pos[i];\n        const Edge\
    \ &e = m_g[from][idx];\n        return {from, e.to, e.cap + m_g[e.to][e.rev].cap,\
    \ m_g[e.to][e.rev].cap};  // tuple of (from, to, capacity, flow).\n    }\n   \
    \ // \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u3088\u308A\uFF0C\u30B0\u30E9\u30D5\u4E0A\
    \u306E\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3059\u308B\uFF0E\n    std::vector<bool>\
    \ min_cut(int s) const {\n        assert(0 <= s and s < order());\n        std::vector<bool>\
    \ res(m_vn, false);\n        std::queue<int> que({s});\n        while(!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            if(res[v])\
    \ continue;\n            res[v] = true;\n            for(const Edge &e : m_g[v])\
    \ {\n                if(!res[e.to] and e.cap > 0) que.push(e.to);\n          \
    \  }\n        }\n        return res;\n    }\n    void reset() {\n        for(const\
    \ auto &[from, idx] : m_pos) {\n            Edge &e = m_g[from][idx];\n      \
    \      e.cap += m_g[e.to][e.rev].cap;\n            m_g[e.to][e.rev].cap = 0;\n\
    \        }\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_FORD_FULKERSON_HPP\n#define ALGORITHM_FORD_FULKERSON_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\ntemplate <typename Flow>\nclass FordFulkerson {\npublic:\n    using flow_type\
    \ = Flow;\n\nprivate:\n    struct Edge {\n        int to;         // to:=(\u884C\
    \u304D\u5148\u30CE\u30FC\u30C9).\n        flow_type cap;  // cap:=(\u5BB9\u91CF\
    ).\n        int rev;        // rev:=(\u9006\u8FBA\u306E\u4F4D\u7F6E). m_g[to][rev]\u304C\
    \u9006\u8FBA\u3068\u306A\u308B\uFF0E\n\n        explicit Edge(int to, flow_type\
    \ cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    int m_vn;     \
    \                           // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<Edge>>\
    \ m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int>> m_pos;  // m_pos[]:=(i\u756A\u76EE\u306E\
    \u8FBA\u306E\u60C5\u5831). pair of (from, index).\n\npublic:\n    FordFulkerson()\
    \ : FordFulkerson(0) {}\n    explicit FordFulkerson(int n) : m_vn(n), m_g(n) {\n\
    \        assert(n >= 0);\n    }\n    explicit FordFulkerson(int vn, int en) :\
    \ FordFulkerson(vn) {\n        assert(en >= 0);\n        m_pos.reserve(en);\n\
    \    }\n\n    static constexpr flow_type infinity() { return std::numeric_limits<flow_type>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n   \
    \ int order() const { return m_vn; }\n    // \u8FBA\u6570\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    int size() const { return m_pos.size(); }\n    // \u5BB9\u91CF\
    cap\u306E\u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int\
    \ from, int to, flow_type cap) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        assert(cap >= 0);\n      \
    \  int i = m_g[from].size(), j = m_g[to].size();\n        if(from == to) ++j;\n\
    \        m_g[from].emplace_back(to, cap, j);\n        m_g[to].emplace_back(from,\
    \ 0, i);\n        m_pos.emplace_back(from, i);\n        return size() - 1;\n \
    \   }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\
    \u6C42\u3081\u308B\uFF0EO(f*|E|).\n    flow_type max_flow(int s, int t) { return\
    \ max_flow(s, t, infinity()); }\n    flow_type max_flow(int s, int t, flow_type\
    \ flow) {\n        assert(0 <= s and s < order());\n        assert(0 <= t and\
    \ t < order());\n        flow_type res = 0;\n        while(res < flow) {\n   \
    \         std::vector<bool> seen(m_vn, false);\n            auto dfs = [&](auto\
    \ self, int v, flow_type flow) -> flow_type {\n                if(v == t) return\
    \ flow;\n                seen[v] = true;\n                for(Edge &e : m_g[v])\
    \ {\n                    if(seen[e.to] or e.cap == 0) continue;\n            \
    \        flow_type res = self(self, e.to, std::min(flow, e.cap));\n          \
    \          if(res == 0) continue;\n                    e.cap -= res;\n       \
    \             m_g[e.to][e.rev].cap += res;\n                    return res;\n\
    \                }\n                return 0;\n            };\n            flow_type\
    \ tmp = dfs(dfs, s, flow - res);\n            if(tmp == 0) break;\n          \
    \  res += tmp;\n        }\n        return res;\n    }\n    // i\u756A\u76EE\u306E\
    \u8FBA\u306E\u60C5\u5831\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    std::tuple<int,\
    \ int, flow_type, flow_type> get_edge(int i) const {\n        assert(0 <= i and\
    \ i < size());\n        const auto &[from, idx] = m_pos[i];\n        const Edge\
    \ &e = m_g[from][idx];\n        return {from, e.to, e.cap + m_g[e.to][e.rev].cap,\
    \ m_g[e.to][e.rev].cap};  // tuple of (from, to, capacity, flow).\n    }\n   \
    \ // \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u3088\u308A\uFF0C\u30B0\u30E9\u30D5\u4E0A\
    \u306E\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3059\u308B\uFF0E\n    std::vector<bool>\
    \ min_cut(int s) const {\n        assert(0 <= s and s < order());\n        std::vector<bool>\
    \ res(m_vn, false);\n        std::queue<int> que({s});\n        while(!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            if(res[v])\
    \ continue;\n            res[v] = true;\n            for(const Edge &e : m_g[v])\
    \ {\n                if(!res[e.to] and e.cap > 0) que.push(e.to);\n          \
    \  }\n        }\n        return res;\n    }\n    void reset() {\n        for(const\
    \ auto &[from, idx] : m_pos) {\n            Edge &e = m_g[from][idx];\n      \
    \      e.cap += m_g[e.to][e.rev].cap;\n            m_g[e.to][e.rev].cap = 0;\n\
    \        }\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Graph/Flow/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_6_A-ford_fulkerson.test.cpp
documentation_of: algorithm/Graph/Flow/ford_fulkerson.hpp
layout: document
title: "Ford-Fulkerson Algorithm\uFF08\u6700\u5927\u6D41\u554F\u984C\uFF09"
---


## 概要

最大流問題 (maximum-flow problem) を解くアルゴリズム．
1956年に L. R. Ford Jr. と D. R. Fulkerson によって考案された．


### フローネットワークと最大流問題の定義

「フローネットワーク (flow network)」とは，各辺 $(u,v) \in E$ が容量 (capacity) $c(u,v) \geq 0 \ (c: V \times V \rightarrow \mathbb{R})$ をもち，また始点 (source) $s \in V$ と終点 (sink) $t \in V$ の2頂点をもつ有向グラフ $G = (V,E)$ のことをいう．
便宜上，$(u,v) \notin E$ のとき $c(u,v) = 0$ とみなし，自己ループはないものとする．

$G$ における「フロー (flow)」は，次の2条件を満たす関数 $f: V \times V \rightarrow \mathbb{R}$ である．

1. 容量制限：$0 \leq f(u,v) \leq c(u,v) \ (\forall u, \forall v \in V)$
1. フロー保存則：$\sum_{v \in V} f(u,v) = \sum_{v \in V} f(v,u) \ (\forall u \in V-\{s,t\})$

そして，フロー $f$ の値 $\lvert f \rvert$ は次のように定義される（ここでの $\lvert \cdot \rvert$ の表記は絶対値や要素数を表していない）．

$$
|f| = \sum_{v \in V} f(s,v) - \sum_{v \in V} f(v,s)
$$

「最大流問題」とは，与えられたフローネットワーク $G$ に対し，$s$ から $t$ への最大値をもつフローを求める問題である．


### アルゴリズムの説明

Ford-Fulkerson algorithm では，次の手続きを反復し，徐々にフローを増やして解に近づけていく．

1. DFS により，残余ネットワーク上の増加可能パスを探す
1. 発見した増加可能パス上の辺に対してフローを増減させ，残余ネットワークを更新する
1. 残余ネットワーク上から増加可能パスがなくなるまで繰り返す

求める最大のフローを $f^*$ とすると，上記手続きの反復回数は高々 $\lvert f^* \rvert$ 回である．
各反復時の DFS に $\mathcal{O}(\lvert E \rvert)$ の計算量を要し，全体の計算量は $\mathcal{O}(\lvert f^* \rvert \lvert E \rvert)$ となる．


## 参考

1. 大槻兼資著. "第16章 グラフ (4)：ネットワークフロー". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, pp.283-309. 
1. "24 最大フロー". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.563-591.
1. "フローネットワーク". Wikipedia. <https://ja.wikipedia.org/wiki/フローネットワーク>.
1. "最大フロー問題". Wikipedia. <https://ja.wikipedia.org/wiki/最大フロー問題>.
1. "Ford–Fulkerson algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm>.
1. "フォード・ファルカーソンのアルゴリズム". Wikipedia. <https://ja.wikipedia.org/wiki/フォード・ファルカーソンのアルゴリズム>.


## 問題

- "D - Maxflow". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_d>.
