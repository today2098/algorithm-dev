---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_6_A-dinic.test.cpp
    title: verify/aoj-GRL_6_A-dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/Flow/dinic.md
    document_title: "Dinic's Algorithm\uFF08\u6700\u5927\u6D41\u554F\u984C\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Graph/Flow/dinic.hpp\"\n\n\n\n/**\n * @brief Dinic's\
    \ Algorithm\uFF08\u6700\u5927\u6D41\u554F\u984C\uFF09\n * @docs docs/Graph/Flow/dinic.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <queue>\n#include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename T>  // T:\u5BB9\u91CF\u306E\u578B.\nclass\
    \ Dinic {\n    struct Edge {\n        int to;   // to:=(\u884C\u304D\u5148\u30CE\
    \u30FC\u30C9).\n        T cap;    // cap:=(\u5BB9\u91CF).\n        int rev;  //\
    \ rev:=(\u9006\u8FBA\u30A4\u30C6\u30EC\u30FC\u30BF).\n        explicit Edge(int\
    \ to_, T cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {}\n    };\n\n    std::vector<std::vector<Edge>\
    \ > m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int> > m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\
    \u8FBA\u60C5\u5831). pair of (from, index).\n\n    T dfs(int v, int t, T flow,\
    \ const std::vector<int> &d, std::vector<int> &iter) {\n        if(v == t) return\
    \ flow;\n        for(int &i = iter[v], n = m_g[v].size(); i < n; ++i) {\n    \
    \        Edge &e = m_g[v][i];\n            if(e.cap > 0 and d[e.to] > d[v]) {\n\
    \                T &&res = dfs(e.to, t, std::min(flow, e.cap), d, iter);\n   \
    \             if(res > 0) {\n                    e.cap -= res;\n             \
    \       m_g[e.to][e.rev].cap += res;\n                    return res;\n      \
    \          }\n            }\n        }\n        return 0;\n    }\n\npublic:\n\
    \    Dinic() : Dinic(0) {}\n    explicit Dinic(size_t vn) : m_g(vn) {}\n    explicit\
    \ Dinic(size_t vn, size_t en) : Dinic(vn) {\n        m_pos.reserve(en);\n    }\n\
    \n    static constexpr T infinity() { return std::numeric_limits<T>::max(); }\n\
    \    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const\
    \ { return m_g.size(); }\n    // \u8FBA\u6570\u3092\u8FD4\u3059.\n    int size()\
    \ const { return m_pos.size(); }\n    // \u5BB9\u91CFcap\u306E\u6709\u5411\u8FBA\
    \u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int from, int to, T cap)\
    \ {\n        assert(0 <= from and from < order());\n        assert(0 <= to and\
    \ to < order());\n        assert(cap >= 0);\n        int idx_from = m_g[from].size(),\
    \ idx_to = m_g[to].size();\n        if(from == to) idx_to++;\n        m_g[from].emplace_back(to,\
    \ cap, idx_to);\n        m_g[to].emplace_back(from, 0, idx_from);\n        m_pos.emplace_back(from,\
    \ idx_from);\n        return size() - 1;\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\uFF0EO((|V|^2)*|E|).\n\
    \    T max_flow(int s, int t) { return max_flow(s, t, infinity()); }\n    T max_flow(int\
    \ s, int t, T flow) {\n        assert(0 <= s and s < order());\n        assert(0\
    \ <= t and t < order());\n        T res = 0;\n        std::vector<int> d(order());\
    \     // d[v]:=(\u30CE\u30FC\u30C9s-v\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\
    \u9577\u3055).\n        std::vector<int> iter(order());  // iter[v]:=(m_g[v][]\u306E\
    \u6B21\u306B\u8ABF\u3079\u308B\u3079\u304D\u30A4\u30C6\u30EC\u30FC\u30BF).\n \
    \       while(res < flow) {\n            // (1) BFS: \u30CE\u30FC\u30C9s\u3068\
    \u5404\u30CE\u30FC\u30C9\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\uFF0E\n            std::fill(d.begin(), d.end(), -1);\n\
    \            d[s] = 0;\n            std::queue<int> que;\n            que.push(s);\n\
    \            while(!que.empty()) {\n                int v = que.front();\n   \
    \             que.pop();\n                for(const Edge &e : m_g[v]) {\n    \
    \                if(e.cap > 0 and d[e.to] == -1) {\n                        d[e.to]\
    \ = d[v] + 1;\n                        que.push(e.to);\n                    }\n\
    \                }\n            }\n            if(d[t] == -1) break;\n       \
    \     // (2) DFS: \u5897\u52A0\u30D1\u30B9\u3092\u63A2\u3059\uFF0E\n         \
    \   std::fill(iter.begin(), iter.end(), 0);\n            while(res < flow) {\n\
    \                T &&tmp = dfs(s, t, flow - res, d, iter);\n                if(tmp\
    \ == 0) break;\n                res += tmp;\n            }\n        }\n      \
    \  return res;\n    }\n    // i\u756A\u76EE\u306E\u8FBA\u60C5\u5831\u3092\u8FD4\
    \u3059\uFF0E\n    std::tuple<int, int, T, T> get_edge(int i) const {\n       \
    \ assert(0 <= i and i < size());\n        const auto &[from, idx] = m_pos[i];\n\
    \        const Edge &e = m_g[from][idx];\n        return {from, e.to, e.cap +\
    \ m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};  // tuple of (from, to, cap, flow).\n\
    \    }\n    // \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u3088\u308A\uFF0C\u30B0\u30E9\
    \u30D5\u4E0A\u306E\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3059\u308B\uFF0E\n   \
    \ std::vector<bool> min_cut(int s) const {\n        assert(0 <= s and s < order());\n\
    \        std::vector<bool> res(order(), false);\n        std::queue<int> que;\n\
    \        que.push(s);\n        while(!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            if(res[v]) continue;\n            res[v]\
    \ = true;\n            for(const Edge &e : m_g[v]) {\n                if(e.cap\
    \ > 0 and !res[e.to]) que.push(e.to);\n            }\n        }\n        return\
    \ res;\n    }\n    void reset() {\n        for(const auto &[from, idx] : m_pos)\
    \ {\n            Edge &e = m_g[from][idx];\n            e.cap = e.cap + m_g[e.to][e.rev].cap;\n\
    \            m_g[e.to][e.rev].cap = 0;\n        }\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DINIC_HPP\n#define ALGORITHM_DINIC_HPP 1\n\n/**\n * @brief\
    \ Dinic's Algorithm\uFF08\u6700\u5927\u6D41\u554F\u984C\uFF09\n * @docs docs/Graph/Flow/dinic.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <queue>\n#include <tuple>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename T>  // T:\u5BB9\u91CF\u306E\u578B.\nclass\
    \ Dinic {\n    struct Edge {\n        int to;   // to:=(\u884C\u304D\u5148\u30CE\
    \u30FC\u30C9).\n        T cap;    // cap:=(\u5BB9\u91CF).\n        int rev;  //\
    \ rev:=(\u9006\u8FBA\u30A4\u30C6\u30EC\u30FC\u30BF).\n        explicit Edge(int\
    \ to_, T cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {}\n    };\n\n    std::vector<std::vector<Edge>\
    \ > m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int> > m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\
    \u8FBA\u60C5\u5831). pair of (from, index).\n\n    T dfs(int v, int t, T flow,\
    \ const std::vector<int> &d, std::vector<int> &iter) {\n        if(v == t) return\
    \ flow;\n        for(int &i = iter[v], n = m_g[v].size(); i < n; ++i) {\n    \
    \        Edge &e = m_g[v][i];\n            if(e.cap > 0 and d[e.to] > d[v]) {\n\
    \                T &&res = dfs(e.to, t, std::min(flow, e.cap), d, iter);\n   \
    \             if(res > 0) {\n                    e.cap -= res;\n             \
    \       m_g[e.to][e.rev].cap += res;\n                    return res;\n      \
    \          }\n            }\n        }\n        return 0;\n    }\n\npublic:\n\
    \    Dinic() : Dinic(0) {}\n    explicit Dinic(size_t vn) : m_g(vn) {}\n    explicit\
    \ Dinic(size_t vn, size_t en) : Dinic(vn) {\n        m_pos.reserve(en);\n    }\n\
    \n    static constexpr T infinity() { return std::numeric_limits<T>::max(); }\n\
    \    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const\
    \ { return m_g.size(); }\n    // \u8FBA\u6570\u3092\u8FD4\u3059.\n    int size()\
    \ const { return m_pos.size(); }\n    // \u5BB9\u91CFcap\u306E\u6709\u5411\u8FBA\
    \u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int from, int to, T cap)\
    \ {\n        assert(0 <= from and from < order());\n        assert(0 <= to and\
    \ to < order());\n        assert(cap >= 0);\n        int idx_from = m_g[from].size(),\
    \ idx_to = m_g[to].size();\n        if(from == to) idx_to++;\n        m_g[from].emplace_back(to,\
    \ cap, idx_to);\n        m_g[to].emplace_back(from, 0, idx_from);\n        m_pos.emplace_back(from,\
    \ idx_from);\n        return size() - 1;\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\uFF0EO((|V|^2)*|E|).\n\
    \    T max_flow(int s, int t) { return max_flow(s, t, infinity()); }\n    T max_flow(int\
    \ s, int t, T flow) {\n        assert(0 <= s and s < order());\n        assert(0\
    \ <= t and t < order());\n        T res = 0;\n        std::vector<int> d(order());\
    \     // d[v]:=(\u30CE\u30FC\u30C9s-v\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\
    \u9577\u3055).\n        std::vector<int> iter(order());  // iter[v]:=(m_g[v][]\u306E\
    \u6B21\u306B\u8ABF\u3079\u308B\u3079\u304D\u30A4\u30C6\u30EC\u30FC\u30BF).\n \
    \       while(res < flow) {\n            // (1) BFS: \u30CE\u30FC\u30C9s\u3068\
    \u5404\u30CE\u30FC\u30C9\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\uFF0E\n            std::fill(d.begin(), d.end(), -1);\n\
    \            d[s] = 0;\n            std::queue<int> que;\n            que.push(s);\n\
    \            while(!que.empty()) {\n                int v = que.front();\n   \
    \             que.pop();\n                for(const Edge &e : m_g[v]) {\n    \
    \                if(e.cap > 0 and d[e.to] == -1) {\n                        d[e.to]\
    \ = d[v] + 1;\n                        que.push(e.to);\n                    }\n\
    \                }\n            }\n            if(d[t] == -1) break;\n       \
    \     // (2) DFS: \u5897\u52A0\u30D1\u30B9\u3092\u63A2\u3059\uFF0E\n         \
    \   std::fill(iter.begin(), iter.end(), 0);\n            while(res < flow) {\n\
    \                T &&tmp = dfs(s, t, flow - res, d, iter);\n                if(tmp\
    \ == 0) break;\n                res += tmp;\n            }\n        }\n      \
    \  return res;\n    }\n    // i\u756A\u76EE\u306E\u8FBA\u60C5\u5831\u3092\u8FD4\
    \u3059\uFF0E\n    std::tuple<int, int, T, T> get_edge(int i) const {\n       \
    \ assert(0 <= i and i < size());\n        const auto &[from, idx] = m_pos[i];\n\
    \        const Edge &e = m_g[from][idx];\n        return {from, e.to, e.cap +\
    \ m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};  // tuple of (from, to, cap, flow).\n\
    \    }\n    // \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u3088\u308A\uFF0C\u30B0\u30E9\
    \u30D5\u4E0A\u306E\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3059\u308B\uFF0E\n   \
    \ std::vector<bool> min_cut(int s) const {\n        assert(0 <= s and s < order());\n\
    \        std::vector<bool> res(order(), false);\n        std::queue<int> que;\n\
    \        que.push(s);\n        while(!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            if(res[v]) continue;\n            res[v]\
    \ = true;\n            for(const Edge &e : m_g[v]) {\n                if(e.cap\
    \ > 0 and !res[e.to]) que.push(e.to);\n            }\n        }\n        return\
    \ res;\n    }\n    void reset() {\n        for(const auto &[from, idx] : m_pos)\
    \ {\n            Edge &e = m_g[from][idx];\n            e.cap = e.cap + m_g[e.to][e.rev].cap;\n\
    \            m_g[e.to][e.rev].cap = 0;\n        }\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/Flow/dinic.hpp
  requiredBy: []
  timestamp: '2024-09-14 17:47:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_6_A-dinic.test.cpp
documentation_of: lib/Graph/Flow/dinic.hpp
layout: document
redirect_from:
- /library/lib/Graph/Flow/dinic.hpp
- /library/lib/Graph/Flow/dinic.hpp.html
title: "Dinic's Algorithm\uFF08\u6700\u5927\u6D41\u554F\u984C\uFF09"
---
## 概要

最大流問題を効率的に解くアルゴリズム．
1970年に Yefim Dinitz が考案した．

同じく最大流問題を解く Ford-Fulkerson Algorithm は「DFS で残余グラフ内の増加パスを探し，そこにフローを流す」ということを繰り返す貪欲なアルゴリズムである．
一方，Dinic's algorithm では，この増加パスを探す部分に対して規則を作り，無闇に探索しない工夫をしている．

アルゴリズムの流れは次の通り．

1. BFS により，残余グラフ上における source から各ノードへの増加パスの長さを求める
1. DFS により，増加パスであり，なおかつ先に求めた長さが狭義単調増加するような sink への経路を探す
1. 発見した増加パスにフローを流せるだけ流し，残余グラフを更新する
1. 候補の経路が無くなるまで DFS を繰り返す
1. source から sink への増加パスが無くなるまで BFS からやり直す

計算量は，グラフのノード数を $\lvert V \rvert$ ，辺数を $\lvert E \rvert$ とすると，BFS 部分は $\mathcal{O}(\lvert V \rvert + \lvert E \rvert)$ ，DFS 部分は同じ辺を何度も調べないことで $\mathcal{O}(\lvert V \rvert \lvert E \rvert)$ となる．
これらは高々 $\lvert V \rvert - 1$ 回しか行われないため，全体の最悪計算量は $\mathcal{O}(\lvert V \rvert ^2 \lvert E \rvert)$ となる．
しかし，たいていの場合は見積りより高速である．


## 参考文献

1. 秋葉拓哉ほか. "高速な最大流アルゴリズム". プログラミングコンテストチャレンジブック. 第2版, マイナビ出版, 2012, p.194-195.
1. "Dinic's algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Dinic's_algorithm>.
1. tanaka-a. "燃やす埋める問題とProject Selection Problemの整理". <https://qiita.com/tanaka-a/items/fb8d84c44190c7098047>.
1. "最大流問題について". <https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/>.
1. "Dinic 法とその時間計算量". <https://misawa.github.io/others/flow/dinic_time_complexity.html>.


## 問題

- "D - Maxflow". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_d>.
