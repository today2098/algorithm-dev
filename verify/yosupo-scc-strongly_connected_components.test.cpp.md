---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/Graph/Others/strongly_connected_components.hpp
    title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3\uFF09"
  - icon: ':x:'
    path: lib/Graph/Others/topological_sort.hpp
    title: "Topological Sort\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
      \u30C8\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/yosupo-scc-strongly_connected_components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    \n#line 1 \"lib/Graph/Others/strongly_connected_components.hpp\"\n\n\n\n/**\n\
    \ * @brief Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\uFF09\n * @docs docs/Graph/Others/strongly_connected_components.md\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <utility>\n\
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
    \n\n#line 1 \"lib/Graph/Others/topological_sort.hpp\"\n\n\n\n/**\n * @brief Topological\
    \ Sort\uFF08\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\uFF09\n * @docs\
    \ docs/Graph/Others/topological_sort.md\n */\n\n#line 10 \"lib/Graph/Others/topological_sort.hpp\"\
    \n#include <queue>\n#line 12 \"lib/Graph/Others/topological_sort.hpp\"\n\nnamespace\
    \ algorithm {\n\nclass TopologicalSort {\n    int m_vn;                      \
    \      // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>\
    \ > m_g;  // m_g[v]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n\npublic:\n    TopologicalSort() : TopologicalSort(0) {}\n    explicit TopologicalSort(size_t\
    \ vn) : m_vn(vn), m_g(vn) {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\
    \uFF0E\n    int order() const { return m_vn; }\n    // \u6709\u5411\u8FBA\u3092\
    \u5F35\u308B\uFF0E\n    void add_edge(int from, int to) {\n        assert(0 <=\
    \ from and from < order());\n        assert(0 <= to and to < order());\n     \
    \   m_g[from].push_back(to);\n    }\n    // \u6709\u5411\u975E\u5DE1\u56DE\u30B0\
    \u30E9\u30D5\u306B\u5BFE\u3059\u308B\u4EFB\u610F\u306E\u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u306E\u89E3\u3092\u6C42\u3081\u308B\uFF0EO(|V|+|E|).\n\
    \    std::vector<int> topological_sort() const {\n        std::vector<int> res;\n\
    \        res.reserve(order());\n        std::vector<int> deg(order(), 0);  //\
    \ deg[v]:=(\u30CE\u30FC\u30C9v\u306E\u5165\u6B21\u6570).\n        for(const std::vector<int>\
    \ &edges : m_g) {\n            for(int to : edges) deg[to]++;\n        }\n   \
    \     std::queue<int> que;\n        for(int i = 0; i < order(); ++i) {\n     \
    \       if(deg[i] == 0) que.push(i);\n        }\n        while(!que.empty()) {\n\
    \            int u = que.front();\n            que.pop();\n            res.push_back(u);\n\
    \            for(int v : m_g[u]) {\n                if(--deg[v] == 0) que.push(v);\n\
    \            }\n        }\n        if((int)res.size() != order()) return std::vector<int>();\
    \  // \u9589\u8DEF\u304C\u3042\u308B\u5834\u5408\uFF0E\n        return res;\n\
    \    }\n    // \u8003\u3048\u5F97\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\
    \u30FC\u30C8\u306E\u89E3\u3092\u6570\u3048\u4E0A\u3052\u308B\uFF0E\u30CE\u30FC\
    \u30C9\u6570\u306E\u5B9F\u7528\u4E0A\u9650\u76EE\u5B89\u306F20\u7A0B\u5EA6\uFF0E\
    O(N*(2^N)).\n    template <typename Type = long long>\n    Type count_up() const\
    \ {\n        assert(order() <= 30);\n        const int n = order();\n        std::vector<int>\
    \ b(n, 0);  // b[v]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u306B\
    \u3042\u308B\u884C\u304D\u5148\u30CE\u30FC\u30C9\u306E\u96C6\u5408).\n       \
    \ for(int v = 0; v < n; ++v) {\n            for(int to : m_g[v]) b[v] |= 1 <<\
    \ to;\n        }\n        std::vector<Type> dp(1 << n, 0);  // dp[S]:=(\u30CE\u30FC\
    \u30C9\u96C6\u5408S\u306B\u304A\u3051\u308B\u89E3\u306E\u901A\u308A\u6570).\n\
    \        dp[0] = 1;\n        for(int bit = 0; bit < 1 << n; ++bit) {\n       \
    \     for(int i = 0; i < n; ++i) {\n                if(!(bit >> i & 1) and !(bit\
    \ & b[i])) dp[bit | 1 << i] += dp[bit];\n            }\n        }\n        return\
    \ dp[(1 << n) - 1];\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 7 \"verify/yosupo-scc-strongly_connected_components.test.cpp\"\
    \n\nint main() {\n    int n;\n    int m;\n    std::cin >> n >> m;\n\n    algorithm::SCC\
    \ scc(n);\n    for(int i = 0; i < m; ++i) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n\n        scc.add_edge(a, b);\n    }\n\n    auto &&[num, ids] =\
    \ scc.decompose();\n    auto &&sccs = scc.scc(num, ids);\n    auto &&dag = scc.directed_acyclic_graph(num,\
    \ ids);\n\n    algorithm::TopologicalSort ts(num);\n    for(int u = 0; u < num;\
    \ ++u) {\n        for(auto v : dag[u]) ts.add_edge(u, v);\n    }\n    auto &&v\
    \ = ts.topological_sort();\n\n    std::cout << num << \"\\n\";\n    for(auto id\
    \ : v) {\n        std::cout << sccs[id].size() << \" \";\n        for(auto v :\
    \ sccs[id]) std::cout << v << \" \";\n        std::cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    \n#include \"../lib/Graph/Others/strongly_connected_components.hpp\"\n#include\
    \ \"../lib/Graph/Others/topological_sort.hpp\"\n\nint main() {\n    int n;\n \
    \   int m;\n    std::cin >> n >> m;\n\n    algorithm::SCC scc(n);\n    for(int\
    \ i = 0; i < m; ++i) {\n        int a, b;\n        std::cin >> a >> b;\n\n   \
    \     scc.add_edge(a, b);\n    }\n\n    auto &&[num, ids] = scc.decompose();\n\
    \    auto &&sccs = scc.scc(num, ids);\n    auto &&dag = scc.directed_acyclic_graph(num,\
    \ ids);\n\n    algorithm::TopologicalSort ts(num);\n    for(int u = 0; u < num;\
    \ ++u) {\n        for(auto v : dag[u]) ts.add_edge(u, v);\n    }\n    auto &&v\
    \ = ts.topological_sort();\n\n    std::cout << num << \"\\n\";\n    for(auto id\
    \ : v) {\n        std::cout << sccs[id].size() << \" \";\n        for(auto v :\
    \ sccs[id]) std::cout << v << \" \";\n        std::cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/Graph/Others/strongly_connected_components.hpp
  - lib/Graph/Others/topological_sort.hpp
  isVerificationFile: true
  path: verify/yosupo-scc-strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-scc-strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-scc-strongly_connected_components.test.cpp
- /verify/verify/yosupo-scc-strongly_connected_components.test.cpp.html
title: verify/yosupo-scc-strongly_connected_components.test.cpp
---
