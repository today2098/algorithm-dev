---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_1_B-potentialized_union_find.test.cpp
    title: verify/aoj-DSL_1_B-potentialized_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/DataStructure/UnionFind/potentialized_union_find.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u91CD\u307F\u4ED8\u304DUnion-Find\uFF0E\
    \ntemplate <typename T>\nclass PotentializedUnionFind {\npublic:\n    using value_type\
    \ = T;\n\nprivate:\n    int m_vn;  // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;\
    \  // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x]:=(\u8981\u7D20x\u306E\
    \u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\u5143\u3067\u3042\
    \u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\u96C6\u5408\
    \u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int> m_par;\n\
    \    std::vector<value_type> m_h;  // m_h[x]:=(\u8981\u7D20x\u306E\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB).\n\n    int root_internal(int x) {\n        if(m_par[x]\
    \ < 0) return x;\n        int rt = root_internal(m_par[x]);  // \u7D4C\u8DEF\u5727\
    \u7E2E\uFF0E\n        m_h[x] += m_h[m_par[x]];\n        return m_par[x] = rt;\n\
    \    }\n    value_type potential_internal(int x) {\n        root_internal(x);\n\
    \        return m_h[x];\n    }\n\npublic:\n    PotentializedUnionFind() : PotentializedUnionFind(0)\
    \ {}\n    explicit PotentializedUnionFind(int n) : m_vn(n), m_gn(n), m_par(n,\
    \ -1), m_h(n, 0) {\n        assert(n >= 0);\n    }\n\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u96C6\u5408\u306E\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int gn()\
    \ const { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\
    \u306E\u4EE3\u8868\u5143\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int root(int\
    \ x) {\n        assert(0 <= x and x < vn());\n        return root_internal(x);\n\
    \    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size(int x) { return -m_par[root(x)];\
    \ }\n    // \u8981\u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    value_type potential(int x) {\n        assert(0\
    \ <= x and x < vn());\n        return potential_internal(x);\n    }\n    // \u8981\
    \u7D20x, y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0E\n    bool is_same(int x, int y) { return root(x) == root(y);\
    \ }\n    // \u8981\u7D20x\u306B\u5BFE\u3059\u308By\u306E\u76F8\u5BFE\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\u308B\uFF0E\n    value_type diff(int\
    \ x, int y) { return potential(y) - potential(x); }\n    // diff(x,y)==d \u3068\
    \u306A\u308B\u3088\u3046\u306B\uFF0C\u8981\u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\
    \u308C\u305E\u308C\u306E\u96C6\u5408\u3092\u5408\u4F75\u3059\u308B\uFF0E\n   \
    \ bool unite(int x, int y, value_type d) {\n        assert(0 <= x and x < vn());\n\
    \        assert(0 <= y and y < vn());\n        d = potential_internal(x) + d -\
    \ potential_internal(y);\n        x = root_internal(x), y = root_internal(y);\n\
    \        if(x == y) return false;     // Do nothing.\n        if(-m_par[x] < -m_par[y])\
    \ {  // Merge technique (union by size).\n            std::swap(x, y);\n     \
    \       d = -d;\n        }\n        m_par[x] += m_par[y];\n        m_par[y] =\
    \ x;\n        m_h[y] = d;\n        --m_gn;\n        return true;\n    }\n    void\
    \ reset() {\n        m_gn = m_vn;\n        std::fill(m_par.begin(), m_par.end(),\
    \ -1);\n        std::fill(m_h.begin(), m_h.end(), value_type());\n    }\n};\n\n\
    }  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP\n#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u91CD\u307F\u4ED8\u304DUnion-Find\uFF0E\
    \ntemplate <typename T>\nclass PotentializedUnionFind {\npublic:\n    using value_type\
    \ = T;\n\nprivate:\n    int m_vn;  // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;\
    \  // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x]:=(\u8981\u7D20x\u306E\
    \u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\u5143\u3067\u3042\
    \u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\u96C6\u5408\
    \u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int> m_par;\n\
    \    std::vector<value_type> m_h;  // m_h[x]:=(\u8981\u7D20x\u306E\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB).\n\n    int root_internal(int x) {\n        if(m_par[x]\
    \ < 0) return x;\n        int rt = root_internal(m_par[x]);  // \u7D4C\u8DEF\u5727\
    \u7E2E\uFF0E\n        m_h[x] += m_h[m_par[x]];\n        return m_par[x] = rt;\n\
    \    }\n    value_type potential_internal(int x) {\n        root_internal(x);\n\
    \        return m_h[x];\n    }\n\npublic:\n    PotentializedUnionFind() : PotentializedUnionFind(0)\
    \ {}\n    explicit PotentializedUnionFind(int n) : m_vn(n), m_gn(n), m_par(n,\
    \ -1), m_h(n, 0) {\n        assert(n >= 0);\n    }\n\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u96C6\u5408\u306E\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int gn()\
    \ const { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\
    \u306E\u4EE3\u8868\u5143\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int root(int\
    \ x) {\n        assert(0 <= x and x < vn());\n        return root_internal(x);\n\
    \    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\
    \u30BA\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size(int x) { return -m_par[root(x)];\
    \ }\n    // \u8981\u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    value_type potential(int x) {\n        assert(0\
    \ <= x and x < vn());\n        return potential_internal(x);\n    }\n    // \u8981\
    \u7D20x, y\u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0E\n    bool is_same(int x, int y) { return root(x) == root(y);\
    \ }\n    // \u8981\u7D20x\u306B\u5BFE\u3059\u308By\u306E\u76F8\u5BFE\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u6C42\u3081\u308B\uFF0E\n    value_type diff(int\
    \ x, int y) { return potential(y) - potential(x); }\n    // diff(x,y)==d \u3068\
    \u306A\u308B\u3088\u3046\u306B\uFF0C\u8981\u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\
    \u308C\u305E\u308C\u306E\u96C6\u5408\u3092\u5408\u4F75\u3059\u308B\uFF0E\n   \
    \ bool unite(int x, int y, value_type d) {\n        assert(0 <= x and x < vn());\n\
    \        assert(0 <= y and y < vn());\n        d = potential_internal(x) + d -\
    \ potential_internal(y);\n        x = root_internal(x), y = root_internal(y);\n\
    \        if(x == y) return false;     // Do nothing.\n        if(-m_par[x] < -m_par[y])\
    \ {  // Merge technique (union by size).\n            std::swap(x, y);\n     \
    \       d = -d;\n        }\n        m_par[x] += m_par[y];\n        m_par[y] =\
    \ x;\n        m_h[y] = d;\n        --m_gn;\n        return true;\n    }\n    void\
    \ reset() {\n        m_gn = m_vn;\n        std::fill(m_par.begin(), m_par.end(),\
    \ -1);\n        std::fill(m_h.begin(), m_h.end(), value_type());\n    }\n};\n\n\
    }  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/DataStructure/UnionFind/potentialized_union_find.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_1_B-potentialized_union_find.test.cpp
documentation_of: algorithm/DataStructure/UnionFind/potentialized_union_find.hpp
layout: document
redirect_from:
- /library/algorithm/DataStructure/UnionFind/potentialized_union_find.hpp
- /library/algorithm/DataStructure/UnionFind/potentialized_union_find.hpp.html
title: algorithm/DataStructure/UnionFind/potentialized_union_find.hpp
---
