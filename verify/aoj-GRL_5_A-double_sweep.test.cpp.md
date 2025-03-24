---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/Graph/Tree/double_sweep.hpp
    title: "Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
  bundledCode: "#line 1 \"verify/aoj-GRL_5_A-double_sweep.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\n\n#include\
    \ <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"lib/Graph/Tree/double_sweep.hpp\"\
    \n\n\n\n/**\n * @brief Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09\n * @docs\
    \ docs/Graph/Tree/double_sweep.md\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <queue>\n#line 14 \"lib/Graph/Tree/double_sweep.hpp\"\n\nnamespace algorithm\
    \ {\n\n// \u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\uFF0E\u8FD4\u308A\u5024\
    \u306F\u76F4\u5F84\u3068\u305D\u306E\u7D4C\u8DEF\uFF0EO(|V|).\nstd::pair<int,\
    \ std::vector<int> > double_sweep(const std::vector<std::vector<int> > &g, int\
    \ s = 0) {\n    const int vn = g.size();\n    assert(0 <= s and s < vn);\n   \
    \ int furthest_node;\n    std::vector<int> d(vn);\n    std::vector<int> pre(vn);\n\
    \    std::queue<int> que;\n    auto bfs = [&](int s) -> void {\n        std::fill(pre.begin(),\
    \ pre.end(), -1);\n        d[s] = 0, pre[s] = -2;\n        que.push(s);\n    \
    \    while(!que.empty()) {\n            int u = que.front();\n            que.pop();\n\
    \            furthest_node = u;\n            for(int v : g[u]) {\n           \
    \     assert(0 <= v and v < vn);\n                if(pre[v] != -1) continue;\n\
    \                d[v] = d[u] + 1, pre[v] = u;\n                que.push(v);\n\
    \            }\n        }\n    };\n    bfs(s);\n    bfs(furthest_node);\n    std::vector<int>\
    \ path({furthest_node});\n    path.reserve(d[furthest_node] + 1);\n    for(int\
    \ v = furthest_node; pre[v] != -2; v = pre[v]) path.push_back(pre[v]);\n    return\
    \ {d[furthest_node], path};  // pair of (diameter, path).\n}\n\n// \u91CD\u307F\
    \u4ED8\u304D\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\uFF0E\u8FD4\u308A\
    \u5024\u306F\u76F4\u5F84\u3068\u305D\u306E\u7D4C\u8DEF\uFF0EO(|V|).\ntemplate\
    \ <typename Type>\nstd::pair<Type, std::vector<int> > double_sweep(const std::vector<std::vector<std::pair<int,\
    \ Type> > > &g, int s = 0) {\n    const int vn = g.size();\n    assert(0 <= s\
    \ and s < vn);\n    int furthest_node;\n    std::vector<Type> d(vn);\n    std::vector<int>\
    \ pre(vn);\n    std::queue<int> que;\n    auto bfs = [&](int s) -> void {\n  \
    \      furthest_node = s;\n        std::fill(pre.begin(), pre.end(), -1);\n  \
    \      d[s] = 0, pre[s] = -2;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            if(d[u]\
    \ > d[furthest_node]) furthest_node = u;\n            for(const auto &[v, cost]\
    \ : g[u]) {\n                assert(0 <= v and v < vn);\n                if(pre[v]\
    \ != -1) continue;\n                d[v] = d[u] + cost, pre[v] = u;\n        \
    \        que.push(v);\n            }\n        }\n    };\n    bfs(s);\n    bfs(furthest_node);\n\
    \    std::vector<int> path({furthest_node});\n    for(int v = furthest_node; pre[v]\
    \ != -2; v = pre[v]) path.push_back(pre[v]);\n    return {d[furthest_node], path};\
    \  // pair of (diameter, path).\n}\n\n}  // namespace algorithm\n\n\n#line 8 \"\
    verify/aoj-GRL_5_A-double_sweep.test.cpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    std::vector<std::vector<std::pair<int, int> > > g(n);\n    for(int\
    \ i = 0; i < n - 1; ++i) {\n        int s, t;\n        int w;\n        std::cin\
    \ >> s >> t >> w;\n\n        g[s].emplace_back(t, w);\n        g[t].emplace_back(s,\
    \ w);\n    }\n\n    auto &&[ans, path] = algorithm::double_sweep(g);\n    std::cout\
    \ << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../lib/Graph/Tree/double_sweep.hpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    std::vector<std::vector<std::pair<int, int> > > g(n);\n    for(int\
    \ i = 0; i < n - 1; ++i) {\n        int s, t;\n        int w;\n        std::cin\
    \ >> s >> t >> w;\n\n        g[s].emplace_back(t, w);\n        g[t].emplace_back(s,\
    \ w);\n    }\n\n    auto &&[ans, path] = algorithm::double_sweep(g);\n    std::cout\
    \ << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Graph/Tree/double_sweep.hpp
  isVerificationFile: true
  path: verify/aoj-GRL_5_A-double_sweep.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_5_A-double_sweep.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_5_A-double_sweep.test.cpp
- /verify/verify/aoj-GRL_5_A-double_sweep.test.cpp.html
title: verify/aoj-GRL_5_A-double_sweep.test.cpp
---
