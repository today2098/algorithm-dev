---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/UnionFind/union_find.hpp
    title: "Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/aoj-DSL_1_A-union_find.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\n\n#include\
    \ <iostream>\n\n#line 1 \"lib/DataStructure/UnionFind/union_find.hpp\"\n\n\n\n\
    /**\n * @brief Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
    \uFF09\n * @docs docs/DataStructure/UnionFind/union_find.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nclass UnionFind {\n    int m_vn;  // m_vn:=(\u8981\u7D20\u6570).\n    int\
    \ m_gn;  // m_gn:=(\u30B0\u30EB\u30FC\u30D7\u6570).\n    // m_par[x]:=(\u8981\u7D20\
    x\u306E\u89AA). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u6839\u3067\u3042\
    \u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\u30B0\u30EB\
    \u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int>\
    \ m_par;\n\npublic:\n    UnionFind() : UnionFind(0) {}\n    explicit UnionFind(size_t\
    \ vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}\n\n    // \u8981\u7D20\u306E\u7DCF\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n    // \u30B0\
    \u30EB\u30FC\u30D7\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const { return\
    \ m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u3092\u8FD4\u3059\uFF0EO(\u03B1\
    (N)).\n    int root(int x) {\n        assert(0 <= x and x < vn());\n        if(m_par[x]\
    \ < 0) return x;\n        return m_par[x] = root(m_par[x]);  // \u7D4C\u8DEF\u5727\
    \u7E2E\uFF0E\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int x) {\n\
    \        assert(0 <= x and x < vn());\n        return -m_par[root(x)];\n    }\n\
    \    // \u8981\u7D20x, y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\
    \u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_same(int x, int\
    \ y) {\n        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        return root(x) == root(y);\n    }\n    // \u8981\u7D20x, y\u304C\u5C5E\
    \u3059\u308B\u305D\u308C\u305E\u308C\u306E\u30B0\u30EB\u30FC\u30D7\u3092\u4F75\
    \u5408\u3059\u308B\uFF0E\n    bool unite(int x, int y) {\n        assert(0 <=\
    \ x and x < vn());\n        assert(0 <= y and y < vn());\n        x = root(x),\
    \ y = root(y);\n        if(x == y) return false;                    // Do nothing.\n\
    \        if(-m_par[x] < -m_par[y]) std::swap(x, y);  // Merge technique (union\
    \ by size).\n        m_par[x] += m_par[y];\n        m_par[y] = x;\n        m_gn--;\n\
    \        return true;\n    }\n    void reset() {\n        m_gn = vn();\n     \
    \   std::fill(m_par.begin(), m_par.end(), -1);\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n#line 6 \"test/aoj-DSL_1_A-union_find.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::UnionFind uf(n);\n\
    \    while(q--) {\n        int com;\n        int x, y;\n        std::cin >> com\
    \ >> x >> y;\n\n        if(com == 0) uf.unite(x, y);\n        else std::cout <<\
    \ uf.is_same(x, y) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/UnionFind/union_find.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::UnionFind\
    \ uf(n);\n    while(q--) {\n        int com;\n        int x, y;\n        std::cin\
    \ >> com >> x >> y;\n\n        if(com == 0) uf.unite(x, y);\n        else std::cout\
    \ << uf.is_same(x, y) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/UnionFind/union_find.hpp
  isVerificationFile: true
  path: test/aoj-DSL_1_A-union_find.test.cpp
  requiredBy: []
  timestamp: '2024-10-05 03:59:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_1_A-union_find.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_1_A-union_find.test.cpp
- /verify/test/aoj-DSL_1_A-union_find.test.cpp.html
title: test/aoj-DSL_1_A-union_find.test.cpp
---
