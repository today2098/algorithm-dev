---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-GRL_3_C-strongly_connected_components.test.cpp
    title: verify/aoj-GRL_3_C-strongly_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-scc-strongly_connected_components.test.cpp
    title: verify/yosupo-scc-strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/Others/strongly_connected_components.md
    document_title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\
      \u5206\u89E3\uFF09"
    links: []
  bundledCode: "#line 1 \"algorithm/Graph/Others/strongly_connected_components.hpp\"\
    \n\n\n\n/**\n * @brief Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\uFF09\n * @docs docs/Graph/Others/strongly_connected_components.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// Strongly Connected Components\uFF08\
    \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\uFF09.\nclass SCC {\n    int m_vn;\
    \                            // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>\
    \ > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n\npublic:\n    SCC() : SCC(0) {}\n    explicit SCC(int vn) : m_vn(vn), m_g(vn)\
    \ {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n\
    \    void add_edge(int from, int to) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        m_g[from].push_back(to);\n\
    \    }\n    // \u6709\u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3059\u308B\uFF0Ereturn pair of (# of SCCs, SCC id of each nodes).\
    \ O(|V|+|E|).\n    std::pair<int, std::vector<int> > decompose() const {\n   \
    \     int num_sccs = 0;               // num_sccs:=(SCC\u306E\u6570).\n      \
    \  std::vector<int> ids(order());  // ids[v]:=(\u30CE\u30FC\u30C9v\u304C\u5C5E\
    \u3059\u308BSCC\u306EID).\n        // ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\
    \u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F).\n        // low[v]:=(DFS\u6728\
    \u306B\u304A\u3044\u3066\uFF0C\u30CE\u30FC\u30C9v\u304B\u3089\u8449\u65B9\u5411\
    \u3078\u306E\u8FBA\u30920\u56DE\u4EE5\u4E0A\uFF0C\u5F8C\u9000\u8FBA\u3092\u9AD8\
    \u30051\u56DE\u7528\u3044\u3066\u5230\u9054\u3067\u304D\u308B\u30CE\u30FC\u30C9\
    w\u306B\u5BFE\u3059\u308Bord[w]\u306E\u6700\u5C0F\u5024).\n        std::vector<int>\
    \ ord(order(), -1), low(order());\n        int now = 0;\n        std::stack<int>\
    \ visited;\n        auto dfs = [&](auto self, int u) -> void {\n            ord[u]\
    \ = low[u] = now++;\n            visited.push(u);\n            for(int to : m_g[u])\
    \ {\n                if(ord[to] == -1) {\n                    self(self, to);\n\
    \                    low[u] = std::min(low[u], low[to]);\n                } else\
    \ {\n                    low[u] = std::min(low[u], ord[to]);\n               \
    \ }\n            }\n            if(low[u] == ord[u]) {\n                while(true)\
    \ {\n                    int v = visited.top();\n                    visited.pop();\n\
    \                    ord[v] = order();  // inf.\n                    ids[v] =\
    \ num_sccs;\n                    if(v == u) break;\n                }\n      \
    \          num_sccs++;\n            }\n        };\n        for(int v = 0; v <\
    \ order(); ++v) {\n            if(ord[v] == -1) dfs(dfs, v);\n        }\n    \
    \    return {num_sccs, ids};\n    }\n    // \u5F37\u9023\u7D50\u6210\u5206\u3054\
    \u3068\u306B\u5404\u30CE\u30FC\u30C9\u3092\u30B0\u30EB\u30FC\u30D7\u5206\u3051\
    \u3059\u308B\uFF0E\n    std::vector<std::vector<int> > scc() const { return scc(decompose());\
    \ }\n    std::vector<std::vector<int> > scc(const std::pair<int, std::vector<int>\
    \ > &p) const { return scc(p.first, p.second); }\n    std::vector<std::vector<int>\
    \ > scc(int num, const std::vector<int> &ids) const {\n        assert((int)ids.size()\
    \ == order());\n        std::vector<std::vector<int> > sccs(num);\n        for(int\
    \ v = 0; v < order(); ++v) {\n            assert(0 <= ids[v] and ids[v] < num);\n\
    \            sccs[ids[v]].push_back(v);\n        }\n        return sccs;\n   \
    \ }\n    // \u5F37\u9023\u7D50\u6210\u5206\u304B\u3089\u69CB\u6210\u3055\u308C\
    \u308BDAG\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    std::vector<std::vector<int>\
    \ > directed_acyclic_graph(const std::pair<int, std::vector<int> > &p) const {\
    \ return directed_acyclic_graph(p.first, p.second); }\n    std::vector<std::vector<int>\
    \ > directed_acyclic_graph(int num, const std::vector<int> &ids) const {\n   \
    \     assert((int)ids.size() == order());\n        std::vector<std::vector<int>\
    \ > dag(num);\n        for(int u = 0; u < order(); ++u) {\n            assert(0\
    \ <= ids[u] and ids[u] < num);\n            for(int v : m_g[u]) {\n          \
    \      assert(0 <= ids[v] and ids[v] < num);\n                if(ids[v] == ids[u])\
    \ continue;\n                dag[ids[u]].push_back(ids[v]);\n            }\n \
    \       }\n        for(std::vector<int> &edge : dag) {\n            std::sort(edge.begin(),\
    \ edge.end());\n            edge.erase(std::unique(edge.begin(), edge.end()),\
    \ edge.end());\n        }\n        return dag;\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP\n#define ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP\
    \ 1\n\n/**\n * @brief Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\uFF09\n * @docs docs/Graph/Others/strongly_connected_components.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// Strongly Connected Components\uFF08\
    \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\uFF09.\nclass SCC {\n    int m_vn;\
    \                            // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>\
    \ > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n\npublic:\n    SCC() : SCC(0) {}\n    explicit SCC(int vn) : m_vn(vn), m_g(vn)\
    \ {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n\
    \    void add_edge(int from, int to) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        m_g[from].push_back(to);\n\
    \    }\n    // \u6709\u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3059\u308B\uFF0Ereturn pair of (# of SCCs, SCC id of each nodes).\
    \ O(|V|+|E|).\n    std::pair<int, std::vector<int> > decompose() const {\n   \
    \     int num_sccs = 0;               // num_sccs:=(SCC\u306E\u6570).\n      \
    \  std::vector<int> ids(order());  // ids[v]:=(\u30CE\u30FC\u30C9v\u304C\u5C5E\
    \u3059\u308BSCC\u306EID).\n        // ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\
    \u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F).\n        // low[v]:=(DFS\u6728\
    \u306B\u304A\u3044\u3066\uFF0C\u30CE\u30FC\u30C9v\u304B\u3089\u8449\u65B9\u5411\
    \u3078\u306E\u8FBA\u30920\u56DE\u4EE5\u4E0A\uFF0C\u5F8C\u9000\u8FBA\u3092\u9AD8\
    \u30051\u56DE\u7528\u3044\u3066\u5230\u9054\u3067\u304D\u308B\u30CE\u30FC\u30C9\
    w\u306B\u5BFE\u3059\u308Bord[w]\u306E\u6700\u5C0F\u5024).\n        std::vector<int>\
    \ ord(order(), -1), low(order());\n        int now = 0;\n        std::stack<int>\
    \ visited;\n        auto dfs = [&](auto self, int u) -> void {\n            ord[u]\
    \ = low[u] = now++;\n            visited.push(u);\n            for(int to : m_g[u])\
    \ {\n                if(ord[to] == -1) {\n                    self(self, to);\n\
    \                    low[u] = std::min(low[u], low[to]);\n                } else\
    \ {\n                    low[u] = std::min(low[u], ord[to]);\n               \
    \ }\n            }\n            if(low[u] == ord[u]) {\n                while(true)\
    \ {\n                    int v = visited.top();\n                    visited.pop();\n\
    \                    ord[v] = order();  // inf.\n                    ids[v] =\
    \ num_sccs;\n                    if(v == u) break;\n                }\n      \
    \          num_sccs++;\n            }\n        };\n        for(int v = 0; v <\
    \ order(); ++v) {\n            if(ord[v] == -1) dfs(dfs, v);\n        }\n    \
    \    return {num_sccs, ids};\n    }\n    // \u5F37\u9023\u7D50\u6210\u5206\u3054\
    \u3068\u306B\u5404\u30CE\u30FC\u30C9\u3092\u30B0\u30EB\u30FC\u30D7\u5206\u3051\
    \u3059\u308B\uFF0E\n    std::vector<std::vector<int> > scc() const { return scc(decompose());\
    \ }\n    std::vector<std::vector<int> > scc(const std::pair<int, std::vector<int>\
    \ > &p) const { return scc(p.first, p.second); }\n    std::vector<std::vector<int>\
    \ > scc(int num, const std::vector<int> &ids) const {\n        assert((int)ids.size()\
    \ == order());\n        std::vector<std::vector<int> > sccs(num);\n        for(int\
    \ v = 0; v < order(); ++v) {\n            assert(0 <= ids[v] and ids[v] < num);\n\
    \            sccs[ids[v]].push_back(v);\n        }\n        return sccs;\n   \
    \ }\n    // \u5F37\u9023\u7D50\u6210\u5206\u304B\u3089\u69CB\u6210\u3055\u308C\
    \u308BDAG\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    std::vector<std::vector<int>\
    \ > directed_acyclic_graph(const std::pair<int, std::vector<int> > &p) const {\
    \ return directed_acyclic_graph(p.first, p.second); }\n    std::vector<std::vector<int>\
    \ > directed_acyclic_graph(int num, const std::vector<int> &ids) const {\n   \
    \     assert((int)ids.size() == order());\n        std::vector<std::vector<int>\
    \ > dag(num);\n        for(int u = 0; u < order(); ++u) {\n            assert(0\
    \ <= ids[u] and ids[u] < num);\n            for(int v : m_g[u]) {\n          \
    \      assert(0 <= ids[v] and ids[v] < num);\n                if(ids[v] == ids[u])\
    \ continue;\n                dag[ids[u]].push_back(ids[v]);\n            }\n \
    \       }\n        for(std::vector<int> &edge : dag) {\n            std::sort(edge.begin(),\
    \ edge.end());\n            edge.erase(std::unique(edge.begin(), edge.end()),\
    \ edge.end());\n        }\n        return dag;\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Graph/Others/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-scc-strongly_connected_components.test.cpp
  - verify/aoj-GRL_3_C-strongly_connected_components.test.cpp
documentation_of: algorithm/Graph/Others/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/algorithm/Graph/Others/strongly_connected_components.hpp
- /library/algorithm/Graph/Others/strongly_connected_components.hpp.html
title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
  \uFF09"
---
## 概要

与えられる有向連結グラフを強連結成分 (SCC: Strongly Connected Components) に分解する．

ここで「強連結成分」とは，「ある有向グラフにおいて，互いに行き来できるノードの集合」を指す．

アルゴリズムの計算量は，グラフのノード数を $\lvert V \rvert$ ，辺の数を $\lvert E \rvert$ とおくと，$\mathcal{O}(\lvert V \rvert + \lvert E \rvert)$ となる．


## 参考文献

1. "Strongly connected component". Wikipedia. <https://en.wikipedia.org/wiki/Strongly_connected_component>.


## 問題

- "G - SCC". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_g>.
