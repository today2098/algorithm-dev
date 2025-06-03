---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
    title: Binary Indexed Tree
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
  bundledCode: "#line 1 \"verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #include <iterator>\n#line 10 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\nnamespace algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename T>\n\
    class BIT {\npublic:\n    using value_type = T;\n\nprivate:\n    std::vector<value_type>\
    \ m_tree;\n\n    static constexpr int lsb(int bit) { return bit & -bit; }\n  \
    \  void build() {\n        for(int i = 1, end = size(); i < end; ++i) {\n    \
    \        int j = i + lsb(i);\n            if(j <= end) m_tree[j - 1] += m_tree[i\
    \ - 1];\n        }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT() : BIT(0)\
    \ {};\n    explicit BIT(int n) : BIT(n, value_type()) {}\n    explicit BIT(int\
    \ n, const value_type &a) : m_tree(n, a) {\n        assert(n >= 0);\n        if(a\
    \ != value_type()) build();\n    }\n    template <std::input_iterator InputIter>\n\
    \    explicit BIT(InputIter first, InputIter last) : m_tree(first, last) {\n \
    \       build();\n    }\n    explicit BIT(std::initializer_list<value_type> il)\
    \ : m_tree(il) {\n        build();\n    }\n    explicit BIT(std::vector<value_type>\
    \ &&v) : m_tree(std::move(v)) {\n        build();\n    }\n\n    // \u8981\u7D20\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_tree.size();\
    \ }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\u308B\
    \uFF0EO(log N).\n    void add(int k, const value_type &a) {\n        assert(0\
    \ <= k and k < size());\n        for(int i = k + 1, end = size(); i <= end; i\
    \ += lsb(i)) m_tree[i - 1] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type sum(int\
    \ r) const {\n        assert(0 <= r and r <= size());\n        value_type res\
    \ = value_type();\n        for(int i = r; i >= 1; i -= lsb(i)) res += m_tree[i\
    \ - 1];\n        return res;\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type sum(int\
    \ l, int r) const {\n        assert(0 <= l and l < r and r <= size());\n     \
    \   return sum(r) - sum(l);\n    }\n    void reset() {\n        std::fill(m_tree.begin(),\
    \ m_tree.end(), value_type());\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 1 \"lib/Graph/Tree/heavy_light_decomposition.hpp\"\n\n\n\n#line 8 \"lib/Graph/Tree/heavy_light_decomposition.hpp\"\
    \n\nnamespace algorithm {\n\n// Heavy-Light Decomposition\uFF08HL\u5206\u89E3\uFF0C\
    \u91CD\u8EFD\u5206\u89E3\uFF09.\nclass HLD {\n    int m_vn;                  \
    \         // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>>\
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
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 9 \"verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::HLD hld(n);\n\
    \    for(int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n\n        hld.add_edge(u, v);\n    }\n    hld.build();\n\n    std::vector<long\
    \ long> b(n);\n    for(int i = 0; i < n; ++i) b[hld.vertex_index()[i]] = a[i];\n\
    \    algorithm::BIT bit(std::move(b));\n\n    while(q--) {\n        int t;\n \
    \       std::cin >> t;\n\n        if(t == 0) {\n            int p;\n         \
    \   int x;\n            std::cin >> p >> x;\n\n            bit.add(hld.vertex_index(p),\
    \ x);\n        } else {\n            int u, v;\n            std::cin >> u >> v;\n\
    \n            long long ans = 0;\n            auto &&ranges = hld.vertex_query_ranges(u,\
    \ v);\n            for(const auto &[l, r] : ranges) ans += bit.sum(l, r);\n\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n#include \"../lib/Graph/Tree/heavy_light_decomposition.hpp\"\n\nint main() {\n\
    \    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int> a(n);\n\
    \    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::HLD hld(n);\n   \
    \ for(int i = 0; i < n - 1; ++i) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n\n        hld.add_edge(u, v);\n    }\n    hld.build();\n\n    std::vector<long\
    \ long> b(n);\n    for(int i = 0; i < n; ++i) b[hld.vertex_index()[i]] = a[i];\n\
    \    algorithm::BIT bit(std::move(b));\n\n    while(q--) {\n        int t;\n \
    \       std::cin >> t;\n\n        if(t == 0) {\n            int p;\n         \
    \   int x;\n            std::cin >> p >> x;\n\n            bit.add(hld.vertex_index(p),\
    \ x);\n        } else {\n            int u, v;\n            std::cin >> u >> v;\n\
    \n            long long ans = 0;\n            auto &&ranges = hld.vertex_query_ranges(u,\
    \ v);\n            for(const auto &[l, r] : ranges) ans += bit.sum(l, r);\n\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
  - lib/Graph/Tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2025-06-01 10:46:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
- /verify/verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp.html
title: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
---
