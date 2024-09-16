---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
    title: test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/Tree/lowest_common_ancestor.md
    document_title: "Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Graph/Tree/lowest_common_ancestor.hpp\"\n\n\n\n/**\n\
    \ * @brief Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09\
    \n * @docs docs/Graph/Tree/lowest_common_ancestor.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <map>\n#include <stack>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// Lowest Common Ancestor\uFF08\
    \u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09.\ntemplate <typename T = int>  // T:Type\
    \ of cost.\nclass LCA {\n    int m_vn;                                       \
    \    // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int m_lb;                     \
    \                      // m_lb:=ceiling(log2(vn)).\n    std::vector<std::vector<std::pair<int,\
    \ T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\
    \u30C8). pair of (to, cost). \u30B0\u30E9\u30D5\u306F\u6728\u3067\u3042\u308B\u3053\
    \u3068\uFF0E\n    std::vector<std::vector<int> > m_par;               // m_par[k][v]:=(\u30CE\
    \u30FC\u30C9v\u304B\u30892^k\u56DE\u8FBF\u3063\u3066\u5230\u9054\u3059\u308B\u89AA\
    \u30CE\u30FC\u30C9\u756A\u53F7). \u89AA\u304C\u3044\u306A\u3044\u5834\u5408\u306F\
    -1\uFF0E\n    std::vector<int> m_depth;                           // m_depth[v]:=(\u30CE\
    \u30FC\u30C9v\u306E\u6DF1\u3055). \u6839\u306B\u9023\u7D50\u3057\u3066\u3044\u306A\
    \u3044\u5834\u5408\u306F-1\uFF0E\n    std::vector<T> m_dist;                 \
    \             // m_dist[v]:=(\u6839\u304B\u3089\u30CE\u30FC\u30C9v\u307E\u3067\
    \u306E\u8DDD\u96E2).\n    std::vector<int> m_ord;                            \
    \ // m_ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\u30CE\u30FC\u30C9v\u306E\u884C\
    \u304D\u304B\u3051\u9806\u5E8F).\n\n    bool is_unconnected(int v) const { return\
    \ m_ord[v] == -1; }\n    void dfs(int u, int p, int depth, T distance, int &now)\
    \ {\n        assert(m_ord[u] == -1);  // \u30B0\u30E9\u30D5\u4E0A\u306B\u9589\u8DEF\
    \u306F\u306A\u3044\u3053\u3068\uFF0E\n        m_ord[u] = now++;\n        m_par[0][u]\
    \ = p, m_depth[u] = depth, m_dist[u] = distance;\n        for(const auto &[v,\
    \ cost] : m_g[u]) {\n            if(v == p) continue;\n            dfs(v, u, depth\
    \ + 1, distance + cost, now);\n        }\n    }\n\npublic:\n    LCA() : LCA(0)\
    \ {}\n    explicit LCA(size_t vn) : m_vn(vn), m_lb(1), m_g(vn), m_depth(vn, -1),\
    \ m_dist(vn, infinity()), m_ord(vn, -1) {\n        while(1 << m_lb < order())\
    \ m_lb++;\n        m_par.assign(m_lb, std::vector<int>(order(), -1));\n    }\n\
    \n    static constexpr T infinity() { return std::numeric_limits<T>::max(); }\n\
    \    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const\
    \ { return m_vn; }\n    // \u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\u30CE\u30FC\
    \u30C9u\u3068v\u306F\u975E\u9023\u7D50\u3067\u3042\u308B\u3053\u3068\uFF0E\n \
    \   void add_edge(int u, int v, T cost = 0) {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        m_g[u].emplace_back(v, cost);\n\
    \        m_g[v].emplace_back(u, cost);\n    }\n    // \u7956\u5148\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\uFF0EO(|V|*log|V|).\n    void build(int rt = 0) {\n \
    \       assert(0 <= rt and rt < order());\n        for(std::vector<int> &v : m_par)\
    \ std::fill(v.begin(), v.end(), -1);\n        std::fill(m_depth.begin(), m_depth.end(),\
    \ -1);\n        std::fill(m_dist.begin(), m_dist.end(), infinity());\n       \
    \ std::fill(m_ord.begin(), m_ord.end(), -1);\n        int now = 0;\n        dfs(rt,\
    \ -1, 0, 0, now);\n        for(int k = 0; k < m_lb - 1; ++k) {\n            for(int\
    \ v = 0; v < order(); ++v) {\n                if(m_par[k][v] != -1) m_par[k +\
    \ 1][v] = m_par[k][m_par[k][v]];\n            }\n        }\n    }\n    // \u30CE\
    \u30FC\u30C9v\u306E\u7956\u5148\u3092k\u4EE3\u9061\u308B\uFF0EO(log|V|).\n   \
    \ int trace_back(int v, int k) const {\n        assert(0 <= v and v < order());\n\
    \        assert(0 <= k and k < order());\n        if(k > m_depth[v]) return -1;\n\
    \        for(int i = 0; i < m_lb; ++i) {\n            if(k >> i & 1) v = m_par[i][v];\n\
    \        }\n        return v;\n    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9\
    u\u3068v\u306E\u6700\u3082\u8FD1\u3044\u5171\u901A\u306E\u7956\u5148\u3092\u6C42\
    \u3081\u308B\uFF0EO(log|V|).\n    int lca(int u, int v) const {\n        assert(0\
    \ <= u and u < order());\n        assert(0 <= v and v < order());\n        if(is_unconnected(u)\
    \ or is_unconnected(v)) return -1;\n        if(m_depth[u] > m_depth[v]) std::swap(u,\
    \ v);\n        v = trace_back(v, m_depth[v] - m_depth[u]);  // \u540C\u3058\u6DF1\
    \u3055\u306B\u5408\u308F\u305B\u308B\uFF0E\n        if(u == v) return u;\n   \
    \     for(int k = m_lb - 1; k >= 0; --k) {\n            if(m_par[k][u] != m_par[k][v])\
    \ u = m_par[k][u], v = m_par[k][v];  // \u7570\u306A\u3063\u305F\u3089\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\uFF0E\n        }\n        return m_par[0][u];\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u6DF1\u3055\u3092\u8FD4\u3059\uFF0EO(1).\n \
    \   T depth(int v) const {\n        assert(0 <= v and v < order());\n        return\
    \ m_depth[v];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u9577\u3055\u3092\
    \u6C42\u3081\u308B\uFF0EO(log|V|).\n    int length(int u, int v) const {\n   \
    \     assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        if(is_unconnected(u) or is_unconnected(v)) return -1;\n        return\
    \ m_depth[u] + m_depth[v] - 2 * m_depth[lca(u, v)];\n    }\n    // \u6839\u3068\
    \u30CE\u30FC\u30C9v\u9593\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ T distance(int v) const {\n        assert(0 <= v and v < order());\n       \
    \ return m_dist[v];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n    T distance(int u, int v) const {\n\
    \        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        if(is_unconnected(u) or is_unconnected(v)) return infinity();\n     \
    \   return m_dist[u] + m_dist[v] - 2 * m_dist[lca(u, v)];\n    }\n    // \u6728\
    \u306E\u5727\u7E2E\uFF0E\n    // \u4EFB\u610F\u306E\u9802\u70B9\u96C6\u5408\u3068\
    \u305D\u306ELCA\u304B\u3089\u306A\u308B\uFF0C\u9802\u70B9\u540C\u58EB\u306E\u95A2\
    \u4FC2\u6027\u3092\u7DAD\u6301\u3057\u305F\u6728\u3092\u4F5C\u6210\u3059\u308B\
    \uFF0EO(K*log|V|).\n    std::pair<int, std::map<int, std::vector<int> > > auxiliary_tree(std::vector<int>\
    \ &vs) const {\n        assert(std::find_if(vs.begin(), vs.end(), [&](int v) ->\
    \ bool { return !(0 <= v and v < order()); }) == vs.end());\n        std::map<int,\
    \ std::vector<int> > res;  // res[v][]:=(\u5727\u7E2E\u3057\u305F\u6728\u306B\u304A\
    \u3051\u308B\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n      \
    \  vs.erase(std::remove_if(vs.begin(), vs.end(), [&](int v) -> bool { return is_unconnected(v);\
    \ }), vs.end());\n        auto comp = [&](int u, int v) -> bool { return m_ord[u]\
    \ < m_ord[v]; };\n        std::sort(vs.begin(), vs.end(), comp);\n        vs.erase(std::unique(vs.begin(),\
    \ vs.end()), vs.end());\n        const int n = vs.size();\n        if(n == 0)\
    \ return {-1, res};\n        if(n == 1) {\n            res[vs[0]];\n         \
    \   return {vs[0], res};\n        }\n        std::stack<int> st;\n        st.push(vs[0]);\n\
    \        for(int i = 1; i < n; ++i) {\n            int w = lca(vs[i - 1], vs[i]);\n\
    \            if(w != vs[i - 1]) {\n                int v = st.top();\n       \
    \         st.pop();\n                while(!st.empty() and m_depth[st.top()] >\
    \ m_depth[w]) {\n                    res[st.top()].push_back(v);\n           \
    \         res[v].push_back(st.top());\n                    v = st.top();\n   \
    \                 st.pop();\n                }\n                if(st.empty()\
    \ or st.top() != w) {\n                    st.push(w);\n                    vs.push_back(w);\n\
    \                }\n                res[w].push_back(v);\n                res[v].push_back(w);\n\
    \            }\n            st.push(vs[i]);\n        }\n        while(st.size()\
    \ > 1) {\n            int v = st.top();\n            st.pop();\n            res[st.top()].push_back(v);\n\
    \            res[v].push_back(st.top());\n        }\n        std::sort(vs.begin(),\
    \ vs.end(), comp);\n        return {st.top(), res};  // pair of (root, tree).\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LOWEST_COMMON_ANCESTOR_HPP\n#define ALGORITHM_LOWEST_COMMON_ANCESTOR_HPP\
    \ 1\n\n/**\n * @brief Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\
    \u5148\uFF09\n * @docs docs/Graph/Tree/lowest_common_ancestor.md\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <map>\n#include\
    \ <stack>\n#include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n\
    // Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09.\ntemplate\
    \ <typename T = int>  // T:Type of cost.\nclass LCA {\n    int m_vn;         \
    \                                  // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int\
    \ m_lb;                                           // m_lb:=ceiling(log2(vn)).\n\
    \    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\
    \u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8). pair of (to, cost). \u30B0\u30E9\
    \u30D5\u306F\u6728\u3067\u3042\u308B\u3053\u3068\uFF0E\n    std::vector<std::vector<int>\
    \ > m_par;               // m_par[k][v]:=(\u30CE\u30FC\u30C9v\u304B\u30892^k\u56DE\
    \u8FBF\u3063\u3066\u5230\u9054\u3059\u308B\u89AA\u30CE\u30FC\u30C9\u756A\u53F7\
    ). \u89AA\u304C\u3044\u306A\u3044\u5834\u5408\u306F-1\uFF0E\n    std::vector<int>\
    \ m_depth;                           // m_depth[v]:=(\u30CE\u30FC\u30C9v\u306E\
    \u6DF1\u3055). \u6839\u306B\u9023\u7D50\u3057\u3066\u3044\u306A\u3044\u5834\u5408\
    \u306F-1\uFF0E\n    std::vector<T> m_dist;                              // m_dist[v]:=(\u6839\
    \u304B\u3089\u30CE\u30FC\u30C9v\u307E\u3067\u306E\u8DDD\u96E2).\n    std::vector<int>\
    \ m_ord;                             // m_ord[v]:=(DFS\u6728\u306B\u304A\u3051\
    \u308B\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304B\u3051\u9806\u5E8F).\n\n    bool\
    \ is_unconnected(int v) const { return m_ord[v] == -1; }\n    void dfs(int u,\
    \ int p, int depth, T distance, int &now) {\n        assert(m_ord[u] == -1); \
    \ // \u30B0\u30E9\u30D5\u4E0A\u306B\u9589\u8DEF\u306F\u306A\u3044\u3053\u3068\uFF0E\
    \n        m_ord[u] = now++;\n        m_par[0][u] = p, m_depth[u] = depth, m_dist[u]\
    \ = distance;\n        for(const auto &[v, cost] : m_g[u]) {\n            if(v\
    \ == p) continue;\n            dfs(v, u, depth + 1, distance + cost, now);\n \
    \       }\n    }\n\npublic:\n    LCA() : LCA(0) {}\n    explicit LCA(size_t vn)\
    \ : m_vn(vn), m_lb(1), m_g(vn), m_depth(vn, -1), m_dist(vn, infinity()), m_ord(vn,\
    \ -1) {\n        while(1 << m_lb < order()) m_lb++;\n        m_par.assign(m_lb,\
    \ std::vector<int>(order(), -1));\n    }\n\n    static constexpr T infinity()\
    \ { return std::numeric_limits<T>::max(); }\n    // \u30CE\u30FC\u30C9\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int order() const { return m_vn; }\n    // \u7121\u5411\
    \u8FBA\u3092\u5F35\u308B\uFF0E\u30CE\u30FC\u30C9u\u3068v\u306F\u975E\u9023\u7D50\
    \u3067\u3042\u308B\u3053\u3068\uFF0E\n    void add_edge(int u, int v, T cost =\
    \ 0) {\n        assert(0 <= u and u < order());\n        assert(0 <= v and v <\
    \ order());\n        m_g[u].emplace_back(v, cost);\n        m_g[v].emplace_back(u,\
    \ cost);\n    }\n    // \u7956\u5148\u6728\u3092\u69CB\u7BC9\u3059\u308B\uFF0E\
    O(|V|*log|V|).\n    void build(int rt = 0) {\n        assert(0 <= rt and rt <\
    \ order());\n        for(std::vector<int> &v : m_par) std::fill(v.begin(), v.end(),\
    \ -1);\n        std::fill(m_depth.begin(), m_depth.end(), -1);\n        std::fill(m_dist.begin(),\
    \ m_dist.end(), infinity());\n        std::fill(m_ord.begin(), m_ord.end(), -1);\n\
    \        int now = 0;\n        dfs(rt, -1, 0, 0, now);\n        for(int k = 0;\
    \ k < m_lb - 1; ++k) {\n            for(int v = 0; v < order(); ++v) {\n     \
    \           if(m_par[k][v] != -1) m_par[k + 1][v] = m_par[k][m_par[k][v]];\n \
    \           }\n        }\n    }\n    // \u30CE\u30FC\u30C9v\u306E\u7956\u5148\u3092\
    k\u4EE3\u9061\u308B\uFF0EO(log|V|).\n    int trace_back(int v, int k) const {\n\
    \        assert(0 <= v and v < order());\n        assert(0 <= k and k < order());\n\
    \        if(k > m_depth[v]) return -1;\n        for(int i = 0; i < m_lb; ++i)\
    \ {\n            if(k >> i & 1) v = m_par[i][v];\n        }\n        return v;\n\
    \    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068v\u306E\u6700\u3082\u8FD1\
    \u3044\u5171\u901A\u306E\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    int lca(int u, int v) const {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        if(is_unconnected(u) or is_unconnected(v))\
    \ return -1;\n        if(m_depth[u] > m_depth[v]) std::swap(u, v);\n        v\
    \ = trace_back(v, m_depth[v] - m_depth[u]);  // \u540C\u3058\u6DF1\u3055\u306B\
    \u5408\u308F\u305B\u308B\uFF0E\n        if(u == v) return u;\n        for(int\
    \ k = m_lb - 1; k >= 0; --k) {\n            if(m_par[k][u] != m_par[k][v]) u =\
    \ m_par[k][u], v = m_par[k][v];  // \u7570\u306A\u3063\u305F\u3089\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\uFF0E\n        }\n        return m_par[0][u];\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u6DF1\u3055\u3092\u8FD4\u3059\uFF0EO(1).\n \
    \   T depth(int v) const {\n        assert(0 <= v and v < order());\n        return\
    \ m_depth[v];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u9577\u3055\u3092\
    \u6C42\u3081\u308B\uFF0EO(log|V|).\n    int length(int u, int v) const {\n   \
    \     assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        if(is_unconnected(u) or is_unconnected(v)) return -1;\n        return\
    \ m_depth[u] + m_depth[v] - 2 * m_depth[lca(u, v)];\n    }\n    // \u6839\u3068\
    \u30CE\u30FC\u30C9v\u9593\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ T distance(int v) const {\n        assert(0 <= v and v < order());\n       \
    \ return m_dist[v];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n    T distance(int u, int v) const {\n\
    \        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        if(is_unconnected(u) or is_unconnected(v)) return infinity();\n     \
    \   return m_dist[u] + m_dist[v] - 2 * m_dist[lca(u, v)];\n    }\n    // \u6728\
    \u306E\u5727\u7E2E\uFF0E\n    // \u4EFB\u610F\u306E\u9802\u70B9\u96C6\u5408\u3068\
    \u305D\u306ELCA\u304B\u3089\u306A\u308B\uFF0C\u9802\u70B9\u540C\u58EB\u306E\u95A2\
    \u4FC2\u6027\u3092\u7DAD\u6301\u3057\u305F\u6728\u3092\u4F5C\u6210\u3059\u308B\
    \uFF0EO(K*log|V|).\n    std::pair<int, std::map<int, std::vector<int> > > auxiliary_tree(std::vector<int>\
    \ &vs) const {\n        assert(std::find_if(vs.begin(), vs.end(), [&](int v) ->\
    \ bool { return !(0 <= v and v < order()); }) == vs.end());\n        std::map<int,\
    \ std::vector<int> > res;  // res[v][]:=(\u5727\u7E2E\u3057\u305F\u6728\u306B\u304A\
    \u3051\u308B\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n      \
    \  vs.erase(std::remove_if(vs.begin(), vs.end(), [&](int v) -> bool { return is_unconnected(v);\
    \ }), vs.end());\n        auto comp = [&](int u, int v) -> bool { return m_ord[u]\
    \ < m_ord[v]; };\n        std::sort(vs.begin(), vs.end(), comp);\n        vs.erase(std::unique(vs.begin(),\
    \ vs.end()), vs.end());\n        const int n = vs.size();\n        if(n == 0)\
    \ return {-1, res};\n        if(n == 1) {\n            res[vs[0]];\n         \
    \   return {vs[0], res};\n        }\n        std::stack<int> st;\n        st.push(vs[0]);\n\
    \        for(int i = 1; i < n; ++i) {\n            int w = lca(vs[i - 1], vs[i]);\n\
    \            if(w != vs[i - 1]) {\n                int v = st.top();\n       \
    \         st.pop();\n                while(!st.empty() and m_depth[st.top()] >\
    \ m_depth[w]) {\n                    res[st.top()].push_back(v);\n           \
    \         res[v].push_back(st.top());\n                    v = st.top();\n   \
    \                 st.pop();\n                }\n                if(st.empty()\
    \ or st.top() != w) {\n                    st.push(w);\n                    vs.push_back(w);\n\
    \                }\n                res[w].push_back(v);\n                res[v].push_back(w);\n\
    \            }\n            st.push(vs[i]);\n        }\n        while(st.size()\
    \ > 1) {\n            int v = st.top();\n            st.pop();\n            res[st.top()].push_back(v);\n\
    \            res[v].push_back(st.top());\n        }\n        std::sort(vs.begin(),\
    \ vs.end(), comp);\n        return {st.top(), res};  // pair of (root, tree).\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/Tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-09-16 19:17:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-GRL_5_C-lowest_common_ancestor.test.cpp
documentation_of: lib/Graph/Tree/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/lib/Graph/Tree/lowest_common_ancestor.hpp
- /library/lib/Graph/Tree/lowest_common_ancestor.hpp.html
title: "Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09"
---
## 概要

ある木において，任意の2頂点の最近共通祖先 (LCA: Lowest Common Ancestor) を効率的に求めるアルゴリズム．

本ライブラリでは「ダブリング」を用いて実装している．

計算量は，木のノード数を $\lvert V \rvert$ とすると，前処理に $\mathcal{O}(\lvert V \rvert \log \lvert V \rvert)$ ，クエリ処理に $\mathcal{O}(\log \lvert V \rvert)$ を要する．


## 参考文献

1. "G - Leaf Color 解説". AtCoder. <https://atcoder.jp/contests/abc340/editorial/9249>.
1. yaketake08. "LCAをベースに構築するAuxiliary Treeのメモ". HatenaBlog. <https://smijake3.hatenablog.com/entry/2019/09/15/200200>.
1. "ダブリングによる木の最近共通祖先（LCA：Lowest Common Ancestor）を求めるアルゴリズム". アルゴリズムロジック. <https://algo-logic.info/lca/>.
1. "最小共通祖先". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor>.


## 問題

- "G - Leaf Color". AtCoder Beginner Contest 340. AtCoder. <https://atcoder.jp/contests/abc340/tasks/abc340_g>.
