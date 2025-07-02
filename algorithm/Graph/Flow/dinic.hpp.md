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
    links: []
  bundledCode: "#line 1 \"algorithm/Graph/Flow/dinic.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ Flow>\nclass Dinic {\npublic:\n    using flow_type = Flow;\n\nprivate:\n   \
    \ struct Edge {\n        int to;         // to:=(\u884C\u304D\u5148\u30CE\u30FC\
    \u30C9).\n        flow_type cap;  // cap:=(\u5BB9\u91CF).\n        int rev;  \
    \      // rev:=(\u9006\u8FBA\u306E\u4F4D\u7F6E). m_g[to][rev]\u304C\u9006\u8FBA\
    \u3068\u306A\u308B\uFF0E\n\n        explicit Edge(int to, flow_type cap, int rev)\
    \ : to(to), cap(cap), rev(rev) {}\n    };\n\n    int m_vn;                   \
    \             // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<Edge>>\
    \ m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int>> m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\
    \u8FBA\u306E\u60C5\u5831). pair of (from, index).\n\npublic:\n    Dinic() : Dinic(0)\
    \ {}\n    explicit Dinic(int n) : m_vn(n), m_g(n) {\n        assert(n >= 0);\n\
    \    }\n    explicit Dinic(int vn, int en) : Dinic(vn) {\n        assert(en >=\
    \ 0);\n        m_pos.reserve(en);\n    }\n\n    static constexpr flow_type infinity()\
    \ { return std::numeric_limits<flow_type>::max(); }\n    // \u30CE\u30FC\u30C9\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int order() const { return m_vn;\
    \ }\n    // \u8FBA\u6570\u3092\u53D6\u5F97\u3059\u308B.\n    int size() const\
    \ { return m_pos.size(); }\n    // \u5BB9\u91CFcap\u306E\u6709\u5411\u8FBA\u3092\
    \u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int from, int to, flow_type cap)\
    \ {\n        assert(0 <= from and from < order());\n        assert(0 <= to and\
    \ to < order());\n        assert(cap >= 0);\n        int i = m_g[from].size(),\
    \ j = m_g[to].size();\n        if(from == to) ++j;\n        m_g[from].emplace_back(to,\
    \ cap, j);\n        m_g[to].emplace_back(from, 0, i);\n        m_pos.emplace_back(from,\
    \ i);\n        return size() - 1;\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089\
    t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\uFF0EO((|V|^2)*|E|).\n\
    \    flow_type max_flow(int s, int t) { return max_flow(s, t, infinity()); }\n\
    \    flow_type max_flow(int s, int t, flow_type flow) {\n        assert(0 <= s\
    \ and s < order());\n        assert(0 <= t and t < order());\n        flow_type\
    \ res = 0;\n        while(res < flow) {\n            // (1) BFS: \u30CE\u30FC\u30C9\
    s\u3068\u5404\u30CE\u30FC\u30C9\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\u9577\
    \u3055\u3092\u6C42\u3081\u308B\uFF0E\n            std::vector<int> d(m_vn, -1);\
    \  // d[v]:=(\u30CE\u30FC\u30C9s-v\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\u9577\
    \u3055).\n            d[s] = 0;\n            std::queue<int> que({s});\n     \
    \       while(!que.empty()) {\n                int v = que.front();\n        \
    \        que.pop();\n                for(const Edge &e : m_g[v]) {\n         \
    \           if(d[e.to] != -1 or e.cap == 0) continue;\n                    d[e.to]\
    \ = d[v] + 1;\n                    que.push(e.to);\n                }\n      \
    \      }\n            if(d[t] == -1) break;\n            // (2) DFS: \u30CE\u30FC\
    \u30C9s-t\u9593\u306E\u5897\u52A0\u30D1\u30B9\u3092\u63A2\u3059\uFF0E\n      \
    \      std::vector<int> next(m_vn, 0);  // next[v]:=(m_g[v][]\u306B\u304A\u3051\
    \u308B\u6B21\u306B\u8ABF\u3079\u308B\u3079\u304D\u4F4D\u7F6E).\n            auto\
    \ dfs = [&](auto self, int v, flow_type flow) -> flow_type {\n               \
    \ if(v == t) return flow;\n                for(int &i = next[v], end = m_g[v].size();\
    \ i < end; ++i) {\n                    Edge &e = m_g[v][i];\n                \
    \    if(d[e.to] <= d[v] or e.cap == 0) continue;\n                    flow_type\
    \ res = self(self, e.to, std::min(flow, e.cap));\n                    if(res ==\
    \ 0) continue;\n                    e.cap -= res;\n                    m_g[e.to][e.rev].cap\
    \ += res;\n                    return res;\n                }\n              \
    \  return 0;\n            };\n            while(res < flow) {\n              \
    \  flow_type tmp = dfs(dfs, s, flow - res);\n                if(tmp == 0) break;\n\
    \                res += tmp;\n            }\n        }\n        return res;\n\
    \    }\n    // i\u756A\u76EE\u306E\u8FBA\u306E\u60C5\u5831\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    std::tuple<int, int, flow_type, flow_type> get_edge(int i) const\
    \ {\n        assert(0 <= i and i < size());\n        const auto &[from, idx] =\
    \ m_pos[i];\n        const Edge &e = m_g[from][idx];\n        return {from, e.to,\
    \ e.cap + m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};  // tuple of (from, to,\
    \ capacity, flow).\n    }\n    // \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u3088\u308A\
    \uFF0C\u30B0\u30E9\u30D5\u4E0A\u306E\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3059\
    \u308B\uFF0E\n    std::vector<bool> min_cut(int s) const {\n        assert(0 <=\
    \ s and s < order());\n        std::vector<bool> res(m_vn, false);\n        std::queue<int>\
    \ que({s});\n        while(!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            if(res[v]) continue;\n            res[v]\
    \ = true;\n            for(const Edge &e : m_g[v]) {\n                if(!res[e.to]\
    \ and e.cap > 0) que.push(e.to);\n            }\n        }\n        return res;\n\
    \    }\n    void reset() {\n        for(const auto &[from, idx] : m_pos) {\n \
    \           Edge &e = m_g[from][idx];\n            e.cap += m_g[e.to][e.rev].cap;\n\
    \            m_g[e.to][e.rev].cap = 0;\n        }\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DINIC_HPP\n#define ALGORITHM_DINIC_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ Flow>\nclass Dinic {\npublic:\n    using flow_type = Flow;\n\nprivate:\n   \
    \ struct Edge {\n        int to;         // to:=(\u884C\u304D\u5148\u30CE\u30FC\
    \u30C9).\n        flow_type cap;  // cap:=(\u5BB9\u91CF).\n        int rev;  \
    \      // rev:=(\u9006\u8FBA\u306E\u4F4D\u7F6E). m_g[to][rev]\u304C\u9006\u8FBA\
    \u3068\u306A\u308B\uFF0E\n\n        explicit Edge(int to, flow_type cap, int rev)\
    \ : to(to), cap(cap), rev(rev) {}\n    };\n\n    int m_vn;                   \
    \             // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<Edge>>\
    \ m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n    std::vector<std::pair<int, int>> m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\
    \u8FBA\u306E\u60C5\u5831). pair of (from, index).\n\npublic:\n    Dinic() : Dinic(0)\
    \ {}\n    explicit Dinic(int n) : m_vn(n), m_g(n) {\n        assert(n >= 0);\n\
    \    }\n    explicit Dinic(int vn, int en) : Dinic(vn) {\n        assert(en >=\
    \ 0);\n        m_pos.reserve(en);\n    }\n\n    static constexpr flow_type infinity()\
    \ { return std::numeric_limits<flow_type>::max(); }\n    // \u30CE\u30FC\u30C9\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int order() const { return m_vn;\
    \ }\n    // \u8FBA\u6570\u3092\u53D6\u5F97\u3059\u308B.\n    int size() const\
    \ { return m_pos.size(); }\n    // \u5BB9\u91CFcap\u306E\u6709\u5411\u8FBA\u3092\
    \u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int from, int to, flow_type cap)\
    \ {\n        assert(0 <= from and from < order());\n        assert(0 <= to and\
    \ to < order());\n        assert(cap >= 0);\n        int i = m_g[from].size(),\
    \ j = m_g[to].size();\n        if(from == to) ++j;\n        m_g[from].emplace_back(to,\
    \ cap, j);\n        m_g[to].emplace_back(from, 0, i);\n        m_pos.emplace_back(from,\
    \ i);\n        return size() - 1;\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089\
    t\u3078\u306E\u6700\u5927\u6D41\u3092\u6C42\u3081\u308B\uFF0EO((|V|^2)*|E|).\n\
    \    flow_type max_flow(int s, int t) { return max_flow(s, t, infinity()); }\n\
    \    flow_type max_flow(int s, int t, flow_type flow) {\n        assert(0 <= s\
    \ and s < order());\n        assert(0 <= t and t < order());\n        flow_type\
    \ res = 0;\n        while(res < flow) {\n            // (1) BFS: \u30CE\u30FC\u30C9\
    s\u3068\u5404\u30CE\u30FC\u30C9\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\u9577\
    \u3055\u3092\u6C42\u3081\u308B\uFF0E\n            std::vector<int> d(m_vn, -1);\
    \  // d[v]:=(\u30CE\u30FC\u30C9s-v\u9593\u306E\u5897\u52A0\u30D1\u30B9\u306E\u9577\
    \u3055).\n            d[s] = 0;\n            std::queue<int> que({s});\n     \
    \       while(!que.empty()) {\n                int v = que.front();\n        \
    \        que.pop();\n                for(const Edge &e : m_g[v]) {\n         \
    \           if(d[e.to] != -1 or e.cap == 0) continue;\n                    d[e.to]\
    \ = d[v] + 1;\n                    que.push(e.to);\n                }\n      \
    \      }\n            if(d[t] == -1) break;\n            // (2) DFS: \u30CE\u30FC\
    \u30C9s-t\u9593\u306E\u5897\u52A0\u30D1\u30B9\u3092\u63A2\u3059\uFF0E\n      \
    \      std::vector<int> next(m_vn, 0);  // next[v]:=(m_g[v][]\u306B\u304A\u3051\
    \u308B\u6B21\u306B\u8ABF\u3079\u308B\u3079\u304D\u4F4D\u7F6E).\n            auto\
    \ dfs = [&](auto self, int v, flow_type flow) -> flow_type {\n               \
    \ if(v == t) return flow;\n                for(int &i = next[v], end = m_g[v].size();\
    \ i < end; ++i) {\n                    Edge &e = m_g[v][i];\n                \
    \    if(d[e.to] <= d[v] or e.cap == 0) continue;\n                    flow_type\
    \ res = self(self, e.to, std::min(flow, e.cap));\n                    if(res ==\
    \ 0) continue;\n                    e.cap -= res;\n                    m_g[e.to][e.rev].cap\
    \ += res;\n                    return res;\n                }\n              \
    \  return 0;\n            };\n            while(res < flow) {\n              \
    \  flow_type tmp = dfs(dfs, s, flow - res);\n                if(tmp == 0) break;\n\
    \                res += tmp;\n            }\n        }\n        return res;\n\
    \    }\n    // i\u756A\u76EE\u306E\u8FBA\u306E\u60C5\u5831\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E\n    std::tuple<int, int, flow_type, flow_type> get_edge(int i) const\
    \ {\n        assert(0 <= i and i < size());\n        const auto &[from, idx] =\
    \ m_pos[i];\n        const Edge &e = m_g[from][idx];\n        return {from, e.to,\
    \ e.cap + m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};  // tuple of (from, to,\
    \ capacity, flow).\n    }\n    // \u6700\u5C0F\u30AB\u30C3\u30C8\u306B\u3088\u308A\
    \uFF0C\u30B0\u30E9\u30D5\u4E0A\u306E\u30CE\u30FC\u30C9\u3092\u5206\u5272\u3059\
    \u308B\uFF0E\n    std::vector<bool> min_cut(int s) const {\n        assert(0 <=\
    \ s and s < order());\n        std::vector<bool> res(m_vn, false);\n        std::queue<int>\
    \ que({s});\n        while(!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            if(res[v]) continue;\n            res[v]\
    \ = true;\n            for(const Edge &e : m_g[v]) {\n                if(!res[e.to]\
    \ and e.cap > 0) que.push(e.to);\n            }\n        }\n        return res;\n\
    \    }\n    void reset() {\n        for(const auto &[from, idx] : m_pos) {\n \
    \           Edge &e = m_g[from][idx];\n            e.cap += m_g[e.to][e.rev].cap;\n\
    \            m_g[e.to][e.rev].cap = 0;\n        }\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Graph/Flow/dinic.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-GRL_6_A-dinic.test.cpp
documentation_of: algorithm/Graph/Flow/dinic.hpp
layout: document
redirect_from:
- /library/algorithm/Graph/Flow/dinic.hpp
- /library/algorithm/Graph/Flow/dinic.hpp.html
title: algorithm/Graph/Flow/dinic.hpp
---
