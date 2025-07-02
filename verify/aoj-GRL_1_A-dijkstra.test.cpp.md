---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Graph/ShortestPath/dijkstra.hpp
    title: algorithm/Graph/ShortestPath/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"verify/aoj-GRL_1_A-dijkstra.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\n\n#include\
    \ <iostream>\n\n#line 1 \"algorithm/Graph/ShortestPath/dijkstra.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
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
    \n}  // namespace dijkstra\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-GRL_1_A-dijkstra.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    int r;\n    std::cin >> n >> m >> r;\n\n\
    \    algorithm::dijkstra::default_dijkstra<int> dijkstra(n);\n    for(int i =\
    \ 0; i < m; ++i) {\n        int s, t;\n        int d;\n        std::cin >> s >>\
    \ t >> d;\n\n        dijkstra.add_edge(s, t, d);\n    }\n    dijkstra.dijkstra(r);\n\
    \n    for(int i = 0; i < n; ++i) {\n        auto ans = dijkstra.distance(i);\n\
    \        if(ans == dijkstra.infinity()) std::cout << \"INF\" << \"\\n\";\n   \
    \     else std::cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/Graph/ShortestPath/dijkstra.hpp\"\
    \n\nint main() {\n    int n, m;\n    int r;\n    std::cin >> n >> m >> r;\n\n\
    \    algorithm::dijkstra::default_dijkstra<int> dijkstra(n);\n    for(int i =\
    \ 0; i < m; ++i) {\n        int s, t;\n        int d;\n        std::cin >> s >>\
    \ t >> d;\n\n        dijkstra.add_edge(s, t, d);\n    }\n    dijkstra.dijkstra(r);\n\
    \n    for(int i = 0; i < n; ++i) {\n        auto ans = dijkstra.distance(i);\n\
    \        if(ans == dijkstra.infinity()) std::cout << \"INF\" << \"\\n\";\n   \
    \     else std::cout << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - algorithm/Graph/ShortestPath/dijkstra.hpp
  isVerificationFile: true
  path: verify/aoj-GRL_1_A-dijkstra.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_1_A-dijkstra.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_1_A-dijkstra.test.cpp
- /verify/verify/aoj-GRL_1_A-dijkstra.test.cpp.html
title: verify/aoj-GRL_1_A-dijkstra.test.cpp
---
