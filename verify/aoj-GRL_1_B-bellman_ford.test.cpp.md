---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Graph/ShortestPath/bellman_ford.hpp
    title: "Bellman-Ford Algorithm\uFF08\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\
      \u8DEF\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"verify/aoj-GRL_1_B-bellman_ford.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\n\n#include\
    \ <iostream>\n\n#line 1 \"lib/Graph/ShortestPath/bellman_ford.hpp\"\n\n\n\n/**\n\
    \ * @brief Bellman-Ford Algorithm\uFF08\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\
    \u8DEF\uFF09\n * @docs docs/Graph/ShortestPath/bellman_ford.md\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename T>\nclass BellmanFord {\n    struct Edge {\n\
    \        int from, to;\n        T cost;\n        explicit Edge(int from_, int\
    \ to_, T cost_) : from(from_), to(to_), cost(cost_) {}\n    };\n\n    int m_vn;\
    \                   // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<Edge>\
    \ m_edges;  // m_edges[]:=(\u8FBA\u30EA\u30B9\u30C8).\n    std::vector<T> m_d;\
    \         // m_d[t]:=(\u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\
    \u8DDD\u96E2).\n    std::vector<int> m_pre;     // m_pre[t]:=(\u30CE\u30FC\u30C9\
    t\u3092\u8A2A\u554F\u3059\u308B\u76F4\u524D\u306E\u30CE\u30FC\u30C9\u756A\u53F7\
    ). \u9006\u65B9\u5411\u7D4C\u8DEF\uFF0E\n\npublic:\n    BellmanFord() : BellmanFord(0)\
    \ {}\n    explicit BellmanFord(size_t vn) : m_vn(vn), m_d(vn, infinity()), m_pre(vn,\
    \ -1) {}\n    explicit BellmanFord(size_t vn, size_t en) : BellmanFord(vn) {\n\
    \        m_edges.reserve(en);\n    }\n\n    static constexpr T infinity() { return\
    \ std::numeric_limits<T>::max(); }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\
    \u3059\uFF0E\n    int order() const { return m_vn; }\n    // \u8FBA\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int size() const { return m_edges.size(); }\n    // \u91CD\
    \u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int\
    \ from, int to, T cost) {\n        assert(0 <= from and from < order());\n   \
    \     assert(0 <= to and to < order());\n        m_edges.emplace_back(from, to,\
    \ cost);\n    }\n    // \u30B0\u30E9\u30D5\u5168\u4F53\u304B\u3089\u8CA0\u9589\
    \u8DEF\u3092\u691C\u51FA\u3059\u308B\uFF0EO(|V|*|E|).\n    bool find_negative_cycle()\
    \ const {\n        std::vector<T> nd(order(), 0);\n        for(int i = 0; i <\
    \ order(); ++i) {\n            bool update = false;\n            for(const auto\
    \ &[from, to, cost] : m_edges) {\n                if(nd[to] > nd[from] + cost)\
    \ {\n                    nd[to] = nd[from] + cost;\n                    update\
    \ = true;\n                }\n            }\n            if(!update) return false;\
    \  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\n        }\n        return true;  //\
    \ \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089\u5404\u30CE\u30FC\u30C9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308B\uFF0EO(|V|*|E|).\n    bool bellman_ford(int s) {\n        assert(0\
    \ <= s and s < order());\n        std::fill(m_d.begin(), m_d.end(), infinity());\n\
    \        std::fill(m_pre.begin(), m_pre.end(), -1);\n        m_d[s] = 0;\n   \
    \     for(int i = 0; i < order(); ++i) {\n            bool update = false;\n \
    \           for(const auto &[from, to, cost] : m_edges) {\n                if(m_d[from]\
    \ == infinity()) continue;\n                if(m_d[to] > m_d[from] + cost) {\n\
    \                    m_d[to] = m_d[from] + cost;\n                    m_pre[to]\
    \ = from;\n                    update = true;\n                }\n           \
    \ }\n            if(!update) return false;  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\
    \n        }\n        for(int i = 0; i < order(); ++i) {\n            bool update\
    \ = false;\n            for(const auto &[from, to, cost] : m_edges) {\n      \
    \          if(m_d[from] == infinity() or m_d[to] == -infinity()) continue;\n \
    \               if(m_d[from] == -infinity() or m_d[to] > m_d[from] + cost) {\n\
    \                    m_d[to] = -infinity();\n                    update = true;\n\
    \                }\n            }\n            if(!update) break;\n        }\n\
    \        return true;  // \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n    }\n    //\
    \ \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8FD4\
    \u3059\uFF0E\n    T distance(int t) const {\n        assert(0 <= t and t < order());\n\
    \        return m_d[t];\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u3092\u5FA9\u5143\u3059\u308B\uFF0E\n    std::vector<int>\
    \ shortest_path(int t) const {\n        assert(0 <= t and t < order());\n    \
    \    std::vector<int> path;\n        if(distance(t) == infinity() or distance(t)\
    \ == -infinity()) return path;\n        for(; t != -1; t = m_pre[t]) path.push_back(t);\n\
    \        std::reverse(path.begin(), path.end());\n        return path;\n    }\n\
    };\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-GRL_1_B-bellman_ford.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    int r;\n    std::cin >> n >> m >> r;\n\n\
    \    algorithm::BellmanFord<int> bellman_ford(n, m);\n    for(int i = 0; i < m;\
    \ ++i) {\n        int s, t;\n        int d;\n        std::cin >> s >> t >> d;\n\
    \n        bellman_ford.add_edge(s, t, d);\n    }\n\n    auto res = bellman_ford.bellman_ford(r);\n\
    \    if(res) {\n        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n      \
    \  return 0;\n    }\n\n    for(int i = 0; i < n; ++i) {\n        auto ans = bellman_ford.distance(i);\n\
    \n        if(ans == bellman_ford.infinity()) std::cout << \"INF\" << \"\\n\";\n\
    \        else std::cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include <iostream>\n\n#include \"../lib/Graph/ShortestPath/bellman_ford.hpp\"\
    \n\nint main() {\n    int n, m;\n    int r;\n    std::cin >> n >> m >> r;\n\n\
    \    algorithm::BellmanFord<int> bellman_ford(n, m);\n    for(int i = 0; i < m;\
    \ ++i) {\n        int s, t;\n        int d;\n        std::cin >> s >> t >> d;\n\
    \n        bellman_ford.add_edge(s, t, d);\n    }\n\n    auto res = bellman_ford.bellman_ford(r);\n\
    \    if(res) {\n        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n      \
    \  return 0;\n    }\n\n    for(int i = 0; i < n; ++i) {\n        auto ans = bellman_ford.distance(i);\n\
    \n        if(ans == bellman_ford.infinity()) std::cout << \"INF\" << \"\\n\";\n\
    \        else std::cout << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/Graph/ShortestPath/bellman_ford.hpp
  isVerificationFile: true
  path: verify/aoj-GRL_1_B-bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_1_B-bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_1_B-bellman_ford.test.cpp
- /verify/verify/aoj-GRL_1_B-bellman_ford.test.cpp.html
title: verify/aoj-GRL_1_B-bellman_ford.test.cpp
---
