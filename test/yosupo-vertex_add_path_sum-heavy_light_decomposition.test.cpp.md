---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
    title: Binary Indexed Tree (0-based index)
  - icon: ':heavy_check_mark:'
    path: lib/Graph/Tree/heavy_light_decomposition.hpp
    title: "Heavy-Light Decomposition\uFF08HL\u5206\u89E3\uFF0C\u91CD\u8EFD\u5206\u89E3\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n\n\n\n/**\n * @brief Binary Indexed Tree (0-based index)\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree_zero.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#line 12 \"lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n\nnamespace algorithm {\n\n// Binary Indexed Tree (0-based index).\ntemplate\
    \ <typename T>\nclass BIT0 {\n    int m_sz;               // m_sz:=(\u914D\u5217\
    \u306E\u8981\u7D20\u6570).\n    std::vector<T> m_tree;  // 0-based index.\n\n\
    \    void build() {\n        for(int i = 0; i < size() - 1; ++i) {\n         \
    \   int j = i | (i + 1);\n            if(j < size()) m_tree[j] += m_tree[i];\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT0() : BIT0(0)\
    \ {};\n    explicit BIT0(size_t n, T a = 0) : m_sz(n), m_tree(n, a) {\n      \
    \  if(a != 0) build();\n    }\n    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()),\
    \ m_tree(v) {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0E\n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\
    \u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0EO(logN).\n    void add(int\
    \ k, T a) {\n        assert(0 <= k and k < size());\n        for(; k < size();\
    \ k |= k + 1) m_tree[k] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const\
    \ {\n        assert(0 <= r and r <= size());\n        T res = 0;\n        for(r\
    \ = r - 1; r >= 0; r = (r & (r + 1)) - 1) res += m_tree[r];\n        return res;\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= size());\n        return sum(r) - sum(l);\n    }\n\
    \    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\uFF0EO(N).\n    void\
    \ fill(T a = 0) {\n        std::fill(m_tree.begin(), m_tree.end(), a);\n     \
    \   if(a != 0) build();\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 1 \"\
    lib/Graph/Tree/heavy_light_decomposition.hpp\"\n\n\n\n/**\n * @brief Heavy-Light\
    \ Decomposition\uFF08HL\u5206\u89E3\uFF0C\u91CD\u8EFD\u5206\u89E3\uFF09\n * @docs\
    \ docs/Graph/Tree/heavy_light_decomposition.md\n */\n\n#line 11 \"lib/Graph/Tree/heavy_light_decomposition.hpp\"\
    \n#include <functional>\n#include <utility>\n#line 14 \"lib/Graph/Tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace algorithm {\n\n// Heavy-Light Decomposition\uFF08HL\u5206\u89E3\uFF0C\
    \u91CD\u8EFD\u5206\u89E3\uFF09.\nclass HLD {\n    int m_vn;                  \
    \          // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>\
    \ > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ). \u30B0\u30E9\u30D5\u306F\u6728\u3067\u3042\u308B\u3053\u3068\uFF0E\n    std::vector<int>\
    \ m_par;              // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\
    ).\n    std::vector<int> m_sub;              // m_sub[v]:=(\u30CE\u30FC\u30C9\
    v\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA).\n\
    \    std::vector<int> m_head;             // m_head[v]:=(\u30CE\u30FC\u30C9v\u3092\
    \u542B\u3080heavy path\u306E\u7AEF\u70B9).\n    std::vector<int> m_ord;      \
    \        // m_ord[v]:=(\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304B\u3051\u9806\
    \u5E8F).\n\n    int dfs1(int u, int p) {\n        assert(m_par[u] == -1);  //\
    \ \u30B0\u30E9\u30D5\u4E0A\u306B\u9589\u8DEF\u306F\u306A\u3044\u3053\u3068\uFF0E\
    \n        m_par[u] = p;\n        m_sub[u] = 1;\n        if(m_g[u].size() > 1 and\
    \ m_g[u][0] == p) std::swap(m_g[u][0], m_g[u].back());\n        for(int &v : m_g[u])\
    \ {\n            if(v == p) continue;\n            m_sub[u] += dfs1(v, u);\n \
    \           if(m_sub[v] > m_sub[m_g[u][0]]) std::swap(m_g[u][0], v);  // m_g[u][0]\u306B\
    heavy child\u3092\u683C\u7D0D\u3059\u308B\uFF0E\n        }\n        return m_sub[u];\n\
    \    }\n    void dfs2(int u, int p, int &now) {\n        m_ord[u] = now++;\n \
    \       for(int v : m_g[u]) {\n            if(v == p) continue;\n            m_head[v]\
    \ = (v == m_g[u][0] ? m_head[u] : v);\n            dfs2(v, u, now);\n        }\n\
    \    }\n\npublic:\n    // constructor. O(|V|).\n    HLD() : HLD(0) {}\n    explicit\
    \ HLD(size_t vn) : m_vn(vn), m_g(vn), m_par(vn), m_sub(vn), m_head(vn), m_ord(vn,\
    \ -1) {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        m_g[u].push_back(v);\n     \
    \   m_g[v].push_back(u);\n    }\n    // \u6728\u3092HL\u5206\u89E3\u3059\u308B\
    \uFF0EO(|V|).\n    void build(int rt = 0) {\n        assert(0 <= rt and rt < order());\n\
    \        std::fill(m_par.begin(), m_par.end(), -1);\n        dfs1(rt, -1);\n \
    \       m_head[rt] = rt;\n        std::fill(m_ord.begin(), m_ord.end(), -1);\n\
    \        int now = 0;\n        dfs2(rt, -1, now);\n    }\n    // \u30CE\u30FC\u30C9\
    v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F\u306B\u304A\u3051\u308B\u756A\u53F7\
    \u3092\u8FD4\u3059\uFF0E\n    int vid(int v) const {\n        assert(0 <= v and\
    \ v < order());\n        return m_ord[v];\n    }\n    // \u30D1\u30B9u-v\u306B\
    \u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u8FD4\u3059\uFF0EO(log|V|).\n    std::vector<std::pair<int,\
    \ int> > vertex_query_ranges(int u, int v) const {\n        assert(0 <= u and\
    \ u < order());\n        assert(0 <= v and v < order());\n        if(m_ord[u]\
    \ == -1 or m_ord[v] == -1) return {};\n        std::vector<std::pair<int, int>\
    \ > res;\n        while(true) {\n            if(m_ord[u] > m_ord[v]) std::swap(u,\
    \ v);\n            if(m_head[u] == m_head[v]) {\n                res.emplace_back(m_ord[u],\
    \ m_ord[v] + 1);\n                break;\n            }\n            res.emplace_back(m_ord[m_head[v]],\
    \ m_ord[v] + 1);\n            v = m_par[m_head[v]];\n        }\n        return\
    \ res;\n    }\n    // \u30CE\u30FC\u30C9v\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\
    \u6728\u306B\u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\
    \u306B\u5BFE\u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u8FD4\u3059\uFF0EO(1).\n    std::pair<int,\
    \ int> subtree_vertex_query_range(int v) const {\n        assert(0 <= v and v\
    \ < order());\n        if(m_ord[v] == -1) return {-1, -1};\n        return {m_ord[v],\
    \ m_ord[v] + m_sub[v]};\n    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068\
    v\u306E\u6700\u8FD1\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    int lca(int u, int v) const {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        if(m_ord[u] == -1 or m_ord[v]\
    \ == -1) return -1;\n        while(true) {\n            if(m_ord[u] > m_ord[v])\
    \ std::swap(u, v);\n            if(m_head[u] == m_head[v]) return u;\n       \
    \     v = m_par[m_head[v]];\n        }\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n#line 8 \"test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::HLD hld(n);\n\
    \    for(int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n\n        hld.add_edge(u, v);\n    }\n    hld.build();\n\n    algorithm::BIT0<long\
    \ long> bitree(n);\n    for(int i = 0; i < n; ++i) bitree.add(hld.vid(i), a[i]);\n\
    \n    while(q--) {\n        int t;\n        std::cin >> t;\n\n        if(t ==\
    \ 0) {\n            int p;\n            int x;\n            std::cin >> p >> x;\n\
    \n            auto k = hld.vid(p);\n            bitree.add(k, x);\n        } else\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n\n            long\
    \ long ans = 0;\n            auto &&ranges = hld.vertex_query_ranges(u, v);\n\
    \            for(const auto &[l, r] : ranges) ans += bitree.sum(l, r);\n\n   \
    \         std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n#include \"../lib/Graph/Tree/heavy_light_decomposition.hpp\"\n\nint main() {\n\
    \    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int> a(n);\n\
    \    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::HLD hld(n);\n   \
    \ for(int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n\n        hld.add_edge(u, v);\n    }\n    hld.build();\n\n    algorithm::BIT0<long\
    \ long> bitree(n);\n    for(int i = 0; i < n; ++i) bitree.add(hld.vid(i), a[i]);\n\
    \n    while(q--) {\n        int t;\n        std::cin >> t;\n\n        if(t ==\
    \ 0) {\n            int p;\n            int x;\n            std::cin >> p >> x;\n\
    \n            auto k = hld.vid(p);\n            bitree.add(k, x);\n        } else\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n\n            long\
    \ long ans = 0;\n            auto &&ranges = hld.vertex_query_ranges(u, v);\n\
    \            for(const auto &[l, r] : ranges) ans += bitree.sum(l, r);\n\n   \
    \         std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
  - lib/Graph/Tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2024-10-27 01:14:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
- /verify/test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp.html
title: test/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
---
