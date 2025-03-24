---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Graph/Tree/heavy_light_decomposition.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Heavy-Light Decomposition\uFF08HL\u5206\u89E3\uFF0C\u91CD\u8EFD\
    \u5206\u89E3\uFF09.\nclass HLD {\n    int m_vn;                           // m_vn:=(\u30CE\
    \u30FC\u30C9\u6570).\n    std::vector<std::vector<int>> m_g;  // m_g[v][]:=(\u30CE\
    \u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8). \u30B0\u30E9\u30D5\u306F\u68EE\
    \u3067\u3042\u308B\u3053\u3068\uFF0E\n    std::vector<int> m_par, m_head;    \
    \ // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7), m_head[v]:=(\u30CE\
    \u30FC\u30C9v\u3092\u542B\u3080heavy path\u306E\u7AEF\u70B9).\n    std::vector<int>\
    \ m_sub;             // m_sub[v]:=(\u30CE\u30FC\u30C9v\u3092\u6839\u3068\u3059\
    \u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA).\n    std::vector<int> m_ord;\
    \             // m_ord[v]:=(\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304B\u3051\u9806\
    \u5E8F).\n    bool m_is_built;\n\n    bool is_built() const { return m_is_built;\
    \ }\n\npublic:\n    // constructor. O(|V|).\n    HLD() : HLD(0) {}\n    explicit\
    \ HLD(int vn) : m_vn(vn), m_g(vn), m_par(vn, -1), m_head(vn, -1), m_sub(vn, 1),\
    \ m_ord(vn, -1), m_is_built(false) {\n        assert(vn >= 0);\n    }\n\n    //\
    \ \u30CE\u30FC\u30C9\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        m_g[u].push_back(v);\n     \
    \   m_g[v].push_back(u);\n    }\n    // \u6728\u3092HL\u5206\u89E3\u3059\u308B\
    \uFF0EO(|V|).\n    void build() {\n        auto dfs = [&](auto self, int u, int\
    \ p) -> int {\n            assert(m_par[u] == -1);  // \u30B0\u30E9\u30D5\u306B\
    \u9589\u8DEF\u306F\u306A\u3044\u3053\u3068\uFF0E\n            m_par[u] = p, m_sub[u]\
    \ = 1;\n            if(m_g[u].size() > 1 and m_g[u][0] == p) std::swap(m_g[u][0],\
    \ m_g[u].back());\n            for(auto &v : m_g[u]) {\n                if(v ==\
    \ p) continue;\n                m_sub[u] += self(self, v, u);\n              \
    \  if(m_sub[v] > m_sub[m_g[u][0]]) std::swap(m_g[u][0], v);  // m_g[u][0]\u306B\
    heavy child\u3092\u683C\u7D0D\u3059\u308B\uFF0E\n            }\n            return\
    \ m_sub[u];\n        };\n        int next = 0;\n        auto dfs2 = [&](auto self,\
    \ int u, int p) -> void {\n            m_ord[u] = next++;\n            for(auto\
    \ v : m_g[u]) {\n                if(v == p) continue;\n                m_head[v]\
    \ = (v == m_g[u][0] ? m_head[u] : v);\n                self(self, v, u);\n   \
    \         }\n        };\n        std::fill(m_par.begin(), m_par.end(), -1);\n\
    \        for(int v = 0, end = order(); v < end; ++v) {\n            if(m_par[v]\
    \ != -1) continue;\n            dfs(dfs, v, -1);\n            m_head[v] = v;\n\
    \            dfs2(dfs2, v, -1);\n        }\n        m_is_built = true;\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F\u306B\u304A\
    \u3051\u308B\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vertex_index(int\
    \ v) const {\n        assert(0 <= v and v < order());\n        return m_ord[v];\n\
    \    }\n    const auto &vertex_index() const { return m_ord; }\n    // \u30D1\u30B9\
    u-v\u306B\u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\
    \u5BFE\u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    std::vector<std::pair<int, int>> vertex_query_ranges(int u, int v) const\
    \ {\n        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        assert(is_built());\n        std::vector<std::pair<int, int>> res;\n\
    \        do {\n            if(m_ord[u] > m_ord[v]) std::swap(u, v);\n        \
    \    if(m_head[u] == m_head[v]) {\n                res.emplace_back(m_ord[u],\
    \ m_ord[v] + 1);\n                return res;\n            }\n            res.emplace_back(m_ord[m_head[v]],\
    \ m_ord[v] + 1);\n            v = m_par[m_head[v]];\n        } while(v != -1);\n\
    \        return {};  // \u975E\u9023\u7D50\u306E\u5834\u5408\uFF0E\n    }\n  \
    \  // \u30CE\u30FC\u30C9v\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\
    \u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    std::pair<int,\
    \ int> vertex_query_range_of_subtree(int v) const {\n        assert(0 <= v and\
    \ v < order());\n        assert(is_built());\n        return {m_ord[v], m_ord[v]\
    \ + m_sub[v]};\n    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068v\u306E\
    \u6700\u8FD1\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    int lca(int u, int v) const {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        assert(is_built());\n      \
    \  do {\n            if(m_ord[u] > m_ord[v]) std::swap(u, v);\n            if(m_head[u]\
    \ == m_head[v]) return u;\n            v = m_par[m_head[v]];\n        } while(v\
    \ != -1);\n        return -1;  // \u975E\u9023\u7D50\u306E\u5834\u5408\uFF0E\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_HEAVY_LIGHT_DECOMPOSITION_HPP\n#define ALGORITHM_HEAVY_LIGHT_DECOMPOSITION_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// Heavy-Light Decomposition\uFF08HL\u5206\
    \u89E3\uFF0C\u91CD\u8EFD\u5206\u89E3\uFF09.\nclass HLD {\n    int m_vn;      \
    \                     // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>>\
    \ m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ). \u30B0\u30E9\u30D5\u306F\u68EE\u3067\u3042\u308B\u3053\u3068\uFF0E\n    std::vector<int>\
    \ m_par, m_head;     // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\
    ), m_head[v]:=(\u30CE\u30FC\u30C9v\u3092\u542B\u3080heavy path\u306E\u7AEF\u70B9\
    ).\n    std::vector<int> m_sub;             // m_sub[v]:=(\u30CE\u30FC\u30C9v\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA).\n    std::vector<int>\
    \ m_ord;             // m_ord[v]:=(\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304B\
    \u3051\u9806\u5E8F).\n    bool m_is_built;\n\n    bool is_built() const { return\
    \ m_is_built; }\n\npublic:\n    // constructor. O(|V|).\n    HLD() : HLD(0) {}\n\
    \    explicit HLD(int vn) : m_vn(vn), m_g(vn), m_par(vn, -1), m_head(vn, -1),\
    \ m_sub(vn, 1), m_ord(vn, -1), m_is_built(false) {\n        assert(vn >= 0);\n\
    \    }\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n\
    \    int order() const { return m_vn; }\n    // \u7121\u5411\u8FBA\u3092\u5F35\
    \u308B\uFF0E\n    void add_edge(int u, int v) {\n        assert(0 <= u and u <\
    \ order());\n        assert(0 <= v and v < order());\n        m_g[u].push_back(v);\n\
    \        m_g[v].push_back(u);\n    }\n    // \u6728\u3092HL\u5206\u89E3\u3059\u308B\
    \uFF0EO(|V|).\n    void build() {\n        auto dfs = [&](auto self, int u, int\
    \ p) -> int {\n            assert(m_par[u] == -1);  // \u30B0\u30E9\u30D5\u306B\
    \u9589\u8DEF\u306F\u306A\u3044\u3053\u3068\uFF0E\n            m_par[u] = p, m_sub[u]\
    \ = 1;\n            if(m_g[u].size() > 1 and m_g[u][0] == p) std::swap(m_g[u][0],\
    \ m_g[u].back());\n            for(auto &v : m_g[u]) {\n                if(v ==\
    \ p) continue;\n                m_sub[u] += self(self, v, u);\n              \
    \  if(m_sub[v] > m_sub[m_g[u][0]]) std::swap(m_g[u][0], v);  // m_g[u][0]\u306B\
    heavy child\u3092\u683C\u7D0D\u3059\u308B\uFF0E\n            }\n            return\
    \ m_sub[u];\n        };\n        int next = 0;\n        auto dfs2 = [&](auto self,\
    \ int u, int p) -> void {\n            m_ord[u] = next++;\n            for(auto\
    \ v : m_g[u]) {\n                if(v == p) continue;\n                m_head[v]\
    \ = (v == m_g[u][0] ? m_head[u] : v);\n                self(self, v, u);\n   \
    \         }\n        };\n        std::fill(m_par.begin(), m_par.end(), -1);\n\
    \        for(int v = 0, end = order(); v < end; ++v) {\n            if(m_par[v]\
    \ != -1) continue;\n            dfs(dfs, v, -1);\n            m_head[v] = v;\n\
    \            dfs2(dfs2, v, -1);\n        }\n        m_is_built = true;\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F\u306B\u304A\
    \u3051\u308B\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vertex_index(int\
    \ v) const {\n        assert(0 <= v and v < order());\n        return m_ord[v];\n\
    \    }\n    const auto &vertex_index() const { return m_ord; }\n    // \u30D1\u30B9\
    u-v\u306B\u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\
    \u5BFE\u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    std::vector<std::pair<int, int>> vertex_query_ranges(int u, int v) const\
    \ {\n        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        assert(is_built());\n        std::vector<std::pair<int, int>> res;\n\
    \        do {\n            if(m_ord[u] > m_ord[v]) std::swap(u, v);\n        \
    \    if(m_head[u] == m_head[v]) {\n                res.emplace_back(m_ord[u],\
    \ m_ord[v] + 1);\n                return res;\n            }\n            res.emplace_back(m_ord[m_head[v]],\
    \ m_ord[v] + 1);\n            v = m_par[m_head[v]];\n        } while(v != -1);\n\
    \        return {};  // \u975E\u9023\u7D50\u306E\u5834\u5408\uFF0E\n    }\n  \
    \  // \u30CE\u30FC\u30C9v\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\
    \u304A\u3051\u308B\u9802\u70B9\u5C5E\u6027\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\
    \u5FDC\u3059\u308B\u7BC4\u56F2\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    std::pair<int,\
    \ int> vertex_query_range_of_subtree(int v) const {\n        assert(0 <= v and\
    \ v < order());\n        assert(is_built());\n        return {m_ord[v], m_ord[v]\
    \ + m_sub[v]};\n    }\n    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068v\u306E\
    \u6700\u8FD1\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n\
    \    int lca(int u, int v) const {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        assert(is_built());\n      \
    \  do {\n            if(m_ord[u] > m_ord[v]) std::swap(u, v);\n            if(m_head[u]\
    \ == m_head[v]) return u;\n            v = m_par[m_head[v]];\n        } while(v\
    \ != -1);\n        return -1;  // \u975E\u9023\u7D50\u306E\u5834\u5408\uFF0E\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Graph/Tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2025-03-24 17:53:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
documentation_of: lib/Graph/Tree/heavy_light_decomposition.hpp
layout: document
title: "Heavy-Light Decomposition\uFF08HL\u5206\u89E3\uFF0C\u91CD\u8EFD\u5206\u89E3\
  \uFF09"
---


## 概要

根付き木をいくつかのパスに分割し，一次元配列に対して用いるアルゴリズムを木に対しても適用させるテクニック．


## 参考文献

1. "Ex - Antichain 解説". AtCoder Beginner Contest 269. AtCoder. <https://atcoder.jp/contests/abc269/editorial/4838>.
1. AI.Cash. "Heavy-light decomposition implementation". Codeforces. <https://codeforces.com/blog/entry/22072>.
1. "HL分解". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/graph/tree/hld/main.html>.


## 問題

- "K - 虫取り". いろはちゃんコンテスト Day2. AtCoder. <https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_k>.
