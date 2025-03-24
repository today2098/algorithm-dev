---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Graph/Flow/dinic.hpp
    title: "Dinic's Algorithm\uFF08\u6700\u5927\u6D41\u554F\u984C\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"verify/aoj-GRL_6_A-dinic.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n\n#include\
    \ <iostream>\n\n#line 1 \"lib/Graph/Flow/dinic.hpp\"\n\n\n\n/**\n * @brief Dinic's\
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
    \ algorithm\n\n\n#line 6 \"verify/aoj-GRL_6_A-dinic.test.cpp\"\n\nint main() {\n\
    \    int n, m;\n    std::cin >> n >> m;\n\n    algorithm::Dinic<int> dinic(n);\n\
    \    for(int i = 0; i < m; ++i) {\n        int u, v;\n        int c;\n       \
    \ std::cin >> u >> v >> c;\n\n        dinic.add_edge(u, v, c);\n    }\n\n    auto\
    \ &&ans = dinic.max_flow(0, n - 1);\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include <iostream>\n\n#include \"../lib/Graph/Flow/dinic.hpp\"\n\nint main()\
    \ {\n    int n, m;\n    std::cin >> n >> m;\n\n    algorithm::Dinic<int> dinic(n);\n\
    \    for(int i = 0; i < m; ++i) {\n        int u, v;\n        int c;\n       \
    \ std::cin >> u >> v >> c;\n\n        dinic.add_edge(u, v, c);\n    }\n\n    auto\
    \ &&ans = dinic.max_flow(0, n - 1);\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Graph/Flow/dinic.hpp
  isVerificationFile: true
  path: verify/aoj-GRL_6_A-dinic.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-GRL_6_A-dinic.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-GRL_6_A-dinic.test.cpp
- /verify/verify/aoj-GRL_6_A-dinic.test.cpp.html
title: verify/aoj-GRL_6_A-dinic.test.cpp
---
