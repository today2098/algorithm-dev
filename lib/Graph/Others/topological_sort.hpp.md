---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-scc-strongly_connected_components.test.cpp
    title: verify/yosupo-scc-strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/Others/topological_sort.md
    document_title: "Topological Sort\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
      \u30FC\u30C8\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Graph/Others/topological_sort.hpp\"\n\n\n\n/**\n * @brief\
    \ Topological Sort\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \uFF09\n * @docs docs/Graph/Others/topological_sort.md\n */\n\n#include <cassert>\n\
    #include <queue>\n#include <vector>\n\nnamespace algorithm {\n\nclass TopologicalSort\
    \ {\n    int m_vn;                            // m_vn:=(\u30CE\u30FC\u30C9\u6570\
    ).\n    std::vector<std::vector<int> > m_g;  // m_g[v]:=(\u30CE\u30FC\u30C9v\u306E\
    \u96A3\u63A5\u30EA\u30B9\u30C8).\n\npublic:\n    TopologicalSort() : TopologicalSort(0)\
    \ {}\n    explicit TopologicalSort(size_t vn) : m_vn(vn), m_g(vn) {}\n\n    //\
    \ \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return\
    \ m_vn; }\n    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int\
    \ from, int to) {\n        assert(0 <= from and from < order());\n        assert(0\
    \ <= to and to < order());\n        m_g[from].push_back(to);\n    }\n    // \u6709\
    \u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u306B\u5BFE\u3059\u308B\u4EFB\u610F\
    \u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\u89E3\u3092\
    \u6C42\u3081\u308B\uFF0EO(|V|+|E|).\n    std::vector<int> topological_sort() const\
    \ {\n        std::vector<int> res;\n        res.reserve(order());\n        std::vector<int>\
    \ deg(order(), 0);  // deg[v]:=(\u30CE\u30FC\u30C9v\u306E\u5165\u6B21\u6570).\n\
    \        for(const std::vector<int> &edges : m_g) {\n            for(int to :\
    \ edges) deg[to]++;\n        }\n        std::queue<int> que;\n        for(int\
    \ i = 0; i < order(); ++i) {\n            if(deg[i] == 0) que.push(i);\n     \
    \   }\n        while(!que.empty()) {\n            int u = que.front();\n     \
    \       que.pop();\n            res.push_back(u);\n            for(int v : m_g[u])\
    \ {\n                if(--deg[v] == 0) que.push(v);\n            }\n        }\n\
    \        if((int)res.size() != order()) return std::vector<int>();  // \u9589\u8DEF\
    \u304C\u3042\u308B\u5834\u5408\uFF0E\n        return res;\n    }\n    // \u8003\
    \u3048\u5F97\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\
    \u89E3\u3092\u6570\u3048\u4E0A\u3052\u308B\uFF0E\u30CE\u30FC\u30C9\u6570\u306E\
    \u5B9F\u7528\u4E0A\u9650\u76EE\u5B89\u306F20\u7A0B\u5EA6\uFF0EO(N*(2^N)).\n  \
    \  template <typename Type = long long>\n    Type count_up() const {\n       \
    \ assert(order() <= 30);\n        const int n = order();\n        std::vector<int>\
    \ b(n, 0);  // b[v]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306B\
    \u3042\u308B\u884C\u304D\u5148\u30CE\u30FC\u30C9\u306E\u96C6\u5408).\n       \
    \ for(int v = 0; v < n; ++v) {\n            for(int to : m_g[v]) b[v] |= 1 <<\
    \ to;\n        }\n        std::vector<Type> dp(1 << n, 0);  // dp[S]:=(\u30CE\u30FC\
    \u30C9\u96C6\u5408S\u306B\u304A\u3051\u308B\u89E3\u306E\u901A\u308A\u6570).\n\
    \        dp[0] = 1;\n        for(int bit = 0; bit < 1 << n; ++bit) {\n       \
    \     for(int i = 0; i < n; ++i) {\n                if(!(bit >> i & 1) and !(bit\
    \ & b[i])) dp[bit | 1 << i] += dp[bit];\n            }\n        }\n        return\
    \ dp[(1 << n) - 1];\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TOPOLOGICAL_SORT_HPP\n#define ALGORITHM_TOPOLOGICAL_SORT_HPP\
    \ 1\n\n/**\n * @brief Topological Sort\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\uFF09\n * @docs docs/Graph/Others/topological_sort.md\n */\n\
    \n#include <cassert>\n#include <queue>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nclass TopologicalSort {\n    int m_vn;                            // m_vn:=(\u30CE\
    \u30FC\u30C9\u6570).\n    std::vector<std::vector<int> > m_g;  // m_g[v]:=(\u30CE\
    \u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n\npublic:\n    TopologicalSort()\
    \ : TopologicalSort(0) {}\n    explicit TopologicalSort(size_t vn) : m_vn(vn),\
    \ m_g(vn) {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int\
    \ order() const { return m_vn; }\n    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\
    \n    void add_edge(int from, int to) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        m_g[from].push_back(to);\n\
    \    }\n    // \u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u306B\u5BFE\u3059\
    \u308B\u4EFB\u610F\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
    \u306E\u89E3\u3092\u6C42\u3081\u308B\uFF0EO(|V|+|E|).\n    std::vector<int> topological_sort()\
    \ const {\n        std::vector<int> res;\n        res.reserve(order());\n    \
    \    std::vector<int> deg(order(), 0);  // deg[v]:=(\u30CE\u30FC\u30C9v\u306E\u5165\
    \u6B21\u6570).\n        for(const std::vector<int> &edges : m_g) {\n         \
    \   for(int to : edges) deg[to]++;\n        }\n        std::queue<int> que;\n\
    \        for(int i = 0; i < order(); ++i) {\n            if(deg[i] == 0) que.push(i);\n\
    \        }\n        while(!que.empty()) {\n            int u = que.front();\n\
    \            que.pop();\n            res.push_back(u);\n            for(int v\
    \ : m_g[u]) {\n                if(--deg[v] == 0) que.push(v);\n            }\n\
    \        }\n        if((int)res.size() != order()) return std::vector<int>();\
    \  // \u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\uFF0E\n        return res;\n\
    \    }\n    // \u8003\u3048\u5F97\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\u306E\u89E3\u3092\u6570\u3048\u4E0A\u3052\u308B\uFF0E\u30CE\u30FC\
    \u30C9\u6570\u306E\u5B9F\u7528\u4E0A\u9650\u76EE\u5B89\u306F20\u7A0B\u5EA6\uFF0E\
    O(N*(2^N)).\n    template <typename Type = long long>\n    Type count_up() const\
    \ {\n        assert(order() <= 30);\n        const int n = order();\n        std::vector<int>\
    \ b(n, 0);  // b[v]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306B\
    \u3042\u308B\u884C\u304D\u5148\u30CE\u30FC\u30C9\u306E\u96C6\u5408).\n       \
    \ for(int v = 0; v < n; ++v) {\n            for(int to : m_g[v]) b[v] |= 1 <<\
    \ to;\n        }\n        std::vector<Type> dp(1 << n, 0);  // dp[S]:=(\u30CE\u30FC\
    \u30C9\u96C6\u5408S\u306B\u304A\u3051\u308B\u89E3\u306E\u901A\u308A\u6570).\n\
    \        dp[0] = 1;\n        for(int bit = 0; bit < 1 << n; ++bit) {\n       \
    \     for(int i = 0; i < n; ++i) {\n                if(!(bit >> i & 1) and !(bit\
    \ & b[i])) dp[bit | 1 << i] += dp[bit];\n            }\n        }\n        return\
    \ dp[(1 << n) - 1];\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/Others/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-10-12 06:18:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-scc-strongly_connected_components.test.cpp
documentation_of: lib/Graph/Others/topological_sort.hpp
layout: document
redirect_from:
- /library/lib/Graph/Others/topological_sort.hpp
- /library/lib/Graph/Others/topological_sort.hpp.html
title: "Topological Sort\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
  \uFF09"
---
## 概要

トポロジカルソートとは，有向グラフの各ノードを，全ての辺の向きが揃うように一列に並べること．
グラフが有向非巡回グラフ (DAG: Directed Acyclic Graph) である（つまり閉路がない）場合のみ，解が存在する．

アルゴリズムの計算量は $O(\lvert V \rvert + \lvert E \rvert)$ ．


## 参考文献

1. "トポロジカルソート". Wikipedia. <https://ja.wikipedia.org/wiki/トポロジカルソート>.
1. "トポロジカルソート". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/topological_sort>.
