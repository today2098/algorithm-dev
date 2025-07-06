---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-persistent_unionfind-rollback_union_find.test.cpp
    title: verify/yosupo-persistent_unionfind-rollback_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/DataStructure/UnionFind/rollback_union_find.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// Rollback\u4ED8\
    \u304DUnion-Find\uFF0E\nclass RollbackUnionFind {\n    int m_vn;  // m_vn:=(\u8981\
    \u7D20\u6570).\n    int m_gn;  // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x]:=(\u8981\
    \u7D20x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\
    \u5143\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\
    \u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int>\
    \ m_par;\n    std::stack<std::tuple<int, int, int, int>> m_history;  // tuple\
    \ of (x, m_par[x], y, m_par[y]).\n\n    int root_internal(int x) const {\n   \
    \     if(m_par[x] < 0) return x;\n        return root_internal(m_par[x]);\n  \
    \  }\n\npublic:\n    RollbackUnionFind() : RollbackUnionFind(0) {}\n    explicit\
    \ RollbackUnionFind(int n) : m_vn(n), m_gn(n), m_par(n, -1) {\n        assert(n\
    \ >= 0);\n    }\n\n    // \u73FE\u5728\u306E\u30D2\u30B9\u30C8\u30EA\u30FC\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n\
    \    int index() const { return m_history.size(); }\n    // \u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n    // \u96C6\u5408\
    \u306E\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n \
    \   // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(log N).\n    int root(int x) const {\n \
    \       assert(0 <= x and x < vn());\n        return root_internal(x);\n    }\n\
    \    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(log N).\n    int size(int x) const { return\
    \ -m_par[root(x)]; }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\u30B0\u30EB\u30FC\
    \u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(log N).\n\
    \    bool is_same(int x, int y) const { return root(x) == root(y); }\n    // \u8981\
    \u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\u308C\u305E\u308C\u306E\u96C6\u5408\u3092\
    \u5408\u4F75\u3059\u308B\uFF0EO(log N).\n    bool unite(int x, int y) {\n    \
    \    assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n    \
    \    x = root_internal(x), y = root_internal(y);\n        m_history.emplace(x,\
    \ m_par[x], y, m_par[y]);\n        if(x == y) return false;\n        if(-m_par[x]\
    \ < -m_par[y]) std::swap(x, y);  // Merge technique (union by size).\n       \
    \ m_par[x] += m_par[y];\n        m_par[y] = x;\n        --m_gn;\n        return\
    \ true;\n    }\n    // \u76F4\u524D\u306E\u72B6\u614B\u306B\u623B\u3059\uFF0E\
    O(1).\n    void rollback() {\n        assert(!m_history.empty());\n        auto\
    \ [x, xp, y, yp] = m_history.top();\n        m_history.pop();\n        m_par[x]\
    \ = xp, m_par[y] = yp;\n    }\n    void reset() {\n        m_gn = m_vn;\n    \
    \    std::fill(m_par.begin(), m_par.end(), -1);\n        std::stack<std::tuple<int,\
    \ int, int, int>>().swap(m_history);\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_ROLLBACK_UNION_FIND_HPP\n#define ALGORITHM_ROLLBACK_UNION_FIND_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// Rollback\u4ED8\
    \u304DUnion-Find\uFF0E\nclass RollbackUnionFind {\n    int m_vn;  // m_vn:=(\u8981\
    \u7D20\u6570).\n    int m_gn;  // m_gn:=(\u96C6\u5408\u306E\u6570).\n    // m_par[x]:=(\u8981\
    \u7D20x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u4EE3\u8868\
    \u5143\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\
    \u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int>\
    \ m_par;\n    std::stack<std::tuple<int, int, int, int>> m_history;  // tuple\
    \ of (x, m_par[x], y, m_par[y]).\n\n    int root_internal(int x) const {\n   \
    \     if(m_par[x] < 0) return x;\n        return root_internal(m_par[x]);\n  \
    \  }\n\npublic:\n    RollbackUnionFind() : RollbackUnionFind(0) {}\n    explicit\
    \ RollbackUnionFind(int n) : m_vn(n), m_gn(n), m_par(n, -1) {\n        assert(n\
    \ >= 0);\n    }\n\n    // \u73FE\u5728\u306E\u30D2\u30B9\u30C8\u30EA\u30FC\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n\
    \    int index() const { return m_history.size(); }\n    // \u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n    // \u96C6\u5408\
    \u306E\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n \
    \   // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(log N).\n    int root(int x) const {\n \
    \       assert(0 <= x and x < vn());\n        return root_internal(x);\n    }\n\
    \    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(log N).\n    int size(int x) const { return\
    \ -m_par[root(x)]; }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\u30B0\u30EB\u30FC\
    \u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(log N).\n\
    \    bool is_same(int x, int y) const { return root(x) == root(y); }\n    // \u8981\
    \u7D20x, y\u304C\u5C5E\u3059\u308B\u305D\u308C\u305E\u308C\u306E\u96C6\u5408\u3092\
    \u5408\u4F75\u3059\u308B\uFF0EO(log N).\n    bool unite(int x, int y) {\n    \
    \    assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n    \
    \    x = root_internal(x), y = root_internal(y);\n        m_history.emplace(x,\
    \ m_par[x], y, m_par[y]);\n        if(x == y) return false;\n        if(-m_par[x]\
    \ < -m_par[y]) std::swap(x, y);  // Merge technique (union by size).\n       \
    \ m_par[x] += m_par[y];\n        m_par[y] = x;\n        --m_gn;\n        return\
    \ true;\n    }\n    // \u76F4\u524D\u306E\u72B6\u614B\u306B\u623B\u3059\uFF0E\
    O(1).\n    void rollback() {\n        assert(!m_history.empty());\n        auto\
    \ [x, xp, y, yp] = m_history.top();\n        m_history.pop();\n        m_par[x]\
    \ = xp, m_par[y] = yp;\n    }\n    void reset() {\n        m_gn = m_vn;\n    \
    \    std::fill(m_par.begin(), m_par.end(), -1);\n        std::stack<std::tuple<int,\
    \ int, int, int>>().swap(m_history);\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/DataStructure/UnionFind/rollback_union_find.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-persistent_unionfind-rollback_union_find.test.cpp
documentation_of: algorithm/DataStructure/UnionFind/rollback_union_find.hpp
layout: document
title: "Rollback\u4ED8\u304DUnion-Find"
---


## 概要

「Rollback 付き Union-Find」は，通常の Union-Find の機能に加え，グループ合併時に親についての情報を保存することにより直前の状態に戻せるようにしたもの．
このロールバック操作は不可逆である．

本実装では「union by size」のみによる工夫を行っており，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考

1. "Union-Find木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/union_find_tree>.
