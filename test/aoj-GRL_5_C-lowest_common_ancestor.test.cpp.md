---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Graph/Tree/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/Graph/Tree/lowest_common_ancestor.hpp\"\
    \n\n\n\n/**\n * @brief Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\
    \u5148\uFF09\n * @docs docs/Graph/Tree/lowest_common_ancestor.md\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <map>\n#include\
    \ <numeric>\n#include <stack>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\
    \u5148\uFF09.\ntemplate <typename T = int>  // T:Type of cost.\nclass LCA {\n\
    \    int m_vn;                                           // m_vn:=(\u30CE\u30FC\
    \u30C9\u6570).\n    int m_lb;                                           // m_lb:=ceiling(log2(vn)).\n\
    \    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\
    \u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8). pair of (to, cost). \u30B0\u30E9\
    \u30D5\u306F\u6728\u3067\u3042\u308B\u3053\u3068\uFF0E\n    std::vector<std::vector<int>\
    \ > m_par;               // m_par[k][v]:=(\u30CE\u30FC\u30C9v\u304B\u30892^k\u56DE\
    \u9061\u3063\u3066\u5230\u9054\u3059\u308B\u89AA\u30CE\u30FC\u30C9). \u89AA\u30CE\
    \u30FC\u30C9\u304C\u3044\u306A\u3044\u5834\u5408\u306F-1\uFF0E\n    std::vector<int>\
    \ m_depth;                           // m_depth[v]:=(\u30CE\u30FC\u30C9v\u306E\
    \u6DF1\u3055).\n    std::vector<T> m_dist;                              // m_dist[v]:=(\u6839\
    \u304B\u3089\u30CE\u30FC\u30C9v\u307E\u3067\u306E\u8DDD\u96E2).\n    std::vector<std::vector<T>\
    \ > m_mx_cost;             // m_mx_cost[k][v]:=(\u30CE\u30FC\u30C9v\u304B\u3089\
    2^k\u56DE\u9061\u4E0A\u3059\u308B\u30D1\u30B9\u306E\u4E2D\u3067\u306E\u6700\u5927\
    \u30B3\u30B9\u30C8).\n    std::vector<int> m_ord;                            \
    \ // m_ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\u30CE\u30FC\u30C9v\u306E\u884C\
    \u304D\u304B\u3051\u9806\u5E8F).\n\n    void dfs(int u, int p, int depth, T distance,\
    \ int &now) {\n        assert(m_ord[u] == -1);  // \u30B0\u30E9\u30D5\u4E0A\u306B\
    \u9589\u8DEF\u306F\u306A\u3044\u3053\u3068\uFF0E\n        m_ord[u] = now++;\n\
    \        m_depth[u] = depth, m_dist[u] = distance;\n        for(const auto &[v,\
    \ cost] : m_g[u]) {\n            if(v == p) continue;\n            m_par[0][v]\
    \ = u, m_mx_cost[0][v] = cost;\n            dfs(v, u, depth + 1, distance + cost,\
    \ now);\n        }\n    }\n    // \u30CE\u30FC\u30C9v\u304B\u3089k\u56DE\u9061\
    \u4E0A\u3059\u308B\u30D1\u30B9\u306E\u4E2D\u3067\u306E\u6700\u5927\u30B3\u30B9\
    \u30C8\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n    T max_cost_internal(int v,\
    \ int k) const {\n        T res = -infinity();\n        for(int i = 0; i < m_lb;\
    \ ++i) {\n            if(k >> i & 1) {\n                res = std::max(res, m_mx_cost[i][v]);\n\
    \                v = m_par[i][v];\n            }\n        }\n        return res;\n\
    \    }\n\npublic:\n    // constructor. O(|V|*log|V|).\n    LCA() : LCA(0) {}\n\
    \    explicit LCA(size_t vn) : m_vn(vn), m_lb(1), m_g(vn), m_depth(vn, 0), m_dist(vn,\
    \ 0), m_ord(vn) {\n        while(1 << m_lb < order()) m_lb++;\n        m_par.assign(m_lb,\
    \ std::vector<int>(order(), -1));\n        m_mx_cost.assign(m_lb, std::vector<T>(order(),\
    \ -infinity()));\n        std::iota(m_ord.begin(), m_ord.end(), 0);\n    }\n\n\
    \    static constexpr T infinity() { return std::numeric_limits<T>::max(); }\n\
    \    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const\
    \ { return m_vn; }\n    // \u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\u30CE\u30FC\
    \u30C9u\u3068v\u306F\u975E\u9023\u7D50\u3067\u3042\u308B\u3053\u3068\uFF0E\n \
    \   void add_edge(int u, int v, T cost = 0) {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        m_g[u].emplace_back(v, cost);\n\
    \        m_g[v].emplace_back(u, cost);\n    }\n    // \u7956\u5148\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\uFF0EO(|V|*log|V|).\n    void build(const std::vector<int>\
    \ &rts = {}) {\n        assert(std::find_if(rts.cbegin(), rts.cend(), [&](int\
    \ v) -> bool { return !(0 <= v and v < order()); }) == rts.cend());\n        std::fill(m_par[0].begin(),\
    \ m_par[0].end(), -1);\n        std::fill(m_mx_cost[0].begin(), m_mx_cost[0].end(),\
    \ -infinity());\n        std::fill(m_ord.begin(), m_ord.end(), -1);\n        int\
    \ now = 0;\n        for(int rt : rts) {\n            if(m_ord[rt] == -1) dfs(rt,\
    \ -1, 0, 0, now);\n        }\n        for(int v = 0; v < order(); ++v) {\n   \
    \         if(m_ord[v] == -1) dfs(v, -1, 0, 0, now);\n        }\n        for(int\
    \ k = 0; k < m_lb - 1; ++k) {\n            for(int v = 0; v < order(); ++v) {\n\
    \                if(m_par[k][v] == -1) {\n                    m_par[k + 1][v]\
    \ = -1;\n                    m_mx_cost[k + 1][v] = -infinity();\n            \
    \    } else {\n                    m_par[k + 1][v] = m_par[k][m_par[k][v]];\n\
    \                    m_mx_cost[k + 1][v] = std::max(m_mx_cost[k][v], m_mx_cost[k][m_par[k][v]]);\n\
    \                }\n            }\n        }\n    }\n    // \u30CE\u30FC\u30C9\
    v\u306E\u7956\u5148\u3092k\u4EE3\u9061\u308B\uFF0EO(log|V|).\n    int trace_back(int\
    \ v, int k) const {\n        assert(0 <= v and v < order());\n        assert(0\
    \ <= k and k < order());\n        if(k > m_depth[v]) return -1;\n        for(int\
    \ i = 0; i < m_lb; ++i) {\n            if(k >> i & 1) v = m_par[i][v];\n     \
    \   }\n        return v;\n    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068\
    v\u306E\u6700\u8FD1\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0E2\u3064\
    \u306E\u30CE\u30FC\u30C9\u304C\u975E\u9023\u7D50\u306E\u5834\u5408\uFF0C-1\u3092\
    \u8FD4\u3059\uFF0EO(log|V|).\n    int lca(int u, int v) const {\n        assert(0\
    \ <= u and u < order());\n        assert(0 <= v and v < order());\n        if(m_depth[u]\
    \ > m_depth[v]) std::swap(u, v);\n        v = trace_back(v, m_depth[v] - m_depth[u]);\
    \  // \u540C\u3058\u6DF1\u3055\u306B\u5408\u308F\u305B\u308B\uFF0E\n        if(u\
    \ == v) return u;\n        for(int k = m_lb - 1; k >= 0; --k) {\n            if(m_par[k][u]\
    \ != m_par[k][v]) u = m_par[k][u], v = m_par[k][v];  // \u7570\u306A\u3063\u305F\
    \u3089\u6839\u306B\u8FD1\u3065\u3051\u308B\uFF0E\n        }\n        return m_par[0][u];\n\
    \    }\n    // \u30CE\u30FC\u30C9v\u306E\u6DF1\u3055\u3092\u8FD4\u3059\uFF0EO(1).\n\
    \    T depth(int v) const {\n        assert(0 <= v and v < order());\n       \
    \ return m_depth[v];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n    int length(int u, int v) const {\n\
    \        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        int w = lca(u, v);\n        if(w == -1) return -1;\n        return m_depth[u]\
    \ + m_depth[v] - 2 * m_depth[w];\n    }\n    // \u6839\u3068\u30CE\u30FC\u30C9\
    v\u9593\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\uFF0EO(1).\n    T distance(int v)\
    \ const {\n        assert(0 <= v and v < order());\n        return m_dist[v];\n\
    \    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\uFF0EO(log|V|).\n    T distance(int u, int v) const {\n        assert(0\
    \ <= u and u < order());\n        assert(0 <= v and v < order());\n        int\
    \ w = lca(u, v);\n        if(w == -1) return infinity();\n        return m_dist[u]\
    \ + m_dist[v] - 2 * m_dist[w];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\
    \u30D1\u30B9\u306B\u304A\u3051\u308B\u6700\u5927\u30B3\u30B9\u30C8\u3092\u6C42\
    \u3081\u308B\uFF0EO(log|V|).\n    T max_cost(int u, int v) const {\n        assert(0\
    \ <= u and u < order());\n        assert(0 <= v and v < order());\n        int\
    \ w = lca(u, v);\n        if(w == -1) return -infinity();\n        T res = -infinity();\n\
    \        res = std::max(res, max_cost_internal(u, depth(u) - depth(w)));\n   \
    \     res = std::max(res, max_cost_internal(v, depth(v) - depth(w)));\n      \
    \  return res;\n    }\n    // \u6728\u306E\u5727\u7E2E\uFF0E\n    // \u4EFB\u610F\
    \u306E\u9802\u70B9\u96C6\u5408\u3068\u305D\u306ELCA\u304B\u3089\u306A\u308B\uFF0C\
    \u9802\u70B9\u540C\u58EB\u306E\u95A2\u4FC2\u6027\u3092\u7DAD\u6301\u3057\u305F\
    \u6728\u3092\u4F5C\u6210\u3059\u308B\uFF0EO(K*log|V|).\n    std::map<int, std::vector<int>\
    \ > auxiliary_tree(std::vector<int> &vs) const {\n        assert(std::find_if(vs.cbegin(),\
    \ vs.cend(), [&](int v) -> bool { return !(0 <= v and v < order()); }) == vs.cend());\n\
    \        const int n = vs.size();\n        if(n == 0) return std::map<int, std::vector<int>\
    \ >();\n        std::map<int, std::vector<int> > res;  // res[v][]:=(\u5727\u7E2E\
    \u3057\u305F\u6728\u306B\u304A\u3051\u308B\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\
    \u30EA\u30B9\u30C8).\n        auto comp = [&](int u, int v) -> bool { return m_ord[u]\
    \ < m_ord[v]; };\n        std::sort(vs.begin(), vs.end(), comp);\n        vs.erase(std::unique(vs.begin(),\
    \ vs.end()), vs.end());\n        std::stack<int> st;\n        st.push(vs[0]);\n\
    \        for(int i = 1; i < n; ++i) {\n            int w = lca(vs[i - 1], vs[i]);\n\
    \            if(w == -1) {\n                while(st.size() > 1) {\n         \
    \           int v = st.top();\n                    st.pop();\n               \
    \     res[st.top()].push_back(v);\n                    res[v].push_back(st.top());\n\
    \                }\n                res[st.top()];  // for unconnected node.\n\
    \                st.pop();\n            } else if(w != vs[i - 1]) {\n        \
    \        int v = st.top();\n                st.pop();\n                while(!st.empty()\
    \ and m_depth[st.top()] > m_depth[w]) {\n                    res[st.top()].push_back(v);\n\
    \                    res[v].push_back(st.top());\n                    v = st.top();\n\
    \                    st.pop();\n                }\n                if(st.empty()\
    \ or st.top() != w) {\n                    st.push(w);\n                    vs.push_back(w);\n\
    \                }\n                res[w].push_back(v);\n                res[v].push_back(w);\n\
    \            }\n            st.push(vs[i]);\n        }\n        while(st.size()\
    \ > 1) {\n            int v = st.top();\n            st.pop();\n            res[st.top()].push_back(v);\n\
    \            res[v].push_back(st.top());\n        }\n        res[st.top()];  //\
    \ for unconnected node.\n        std::sort(vs.begin(), vs.end(), comp);\n    \
    \    return res;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::LCA lca(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        int k;\n        std::cin >> k;\n\n\
    \        for(int j = 0; j < k; ++j) {\n            int c;\n            std::cin\
    \ >> c;\n\n            lca.add_edge(i, c);\n        }\n    }\n    lca.build();\n\
    \n    int q;\n    std::cin >> q;\n\n    while(q--) {\n        int u, v;\n    \
    \    std::cin >> u >> v;\n\n        auto ans = lca.lca(u, v);\n        std::cout\
    \ << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include <iostream>\n\n#include \"../lib/Graph/Tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::LCA lca(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        int k;\n        std::cin >> k;\n\n\
    \        for(int j = 0; j < k; ++j) {\n            int c;\n            std::cin\
    \ >> c;\n\n            lca.add_edge(i, c);\n        }\n    }\n    lca.build();\n\
    \n    int q;\n    std::cin >> q;\n\n    while(q--) {\n        int u, v;\n    \
    \    std::cin >> u >> v;\n\n        auto ans = lca.lca(u, v);\n        std::cout\
    \ << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/Graph/Tree/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-10-06 03:45:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
- /verify/test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp.html
title: test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
---
