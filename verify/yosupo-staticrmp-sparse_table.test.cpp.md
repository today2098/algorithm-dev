---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/DataStructure/SegmentTree/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo-staticrmp-sparse_table.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"lib/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\n\n\n/**\n * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#line 12 \"lib/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\nnamespace algorithm {\n\n// \u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3057\
    \uFF0C\u7D50\u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\
    \u6027 A\u2022A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08min/max, gcd/lcm,\
    \ bitwise-and/or\u306A\u3069\uFF09\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\
    \u3081\u308B\uFF0E\ntemplate <typename S>  // S:\u51AA\u7B49\u534A\u7FA4\u306E\
    \u578B.\nclass SparseTable {\n    using Op = std::function<S(const S &, const\
    \ S &)>;\n\n    Op m_op;                               // S m_op(S,S):=(\u4E8C\
    \u9805\u6F14\u7B97\u95A2\u6570).\n    int m_sz;                              //\
    \ m_sz:=(\u8981\u7D20\u6570).\n    std::vector<int> m_lb;                 // m_lb[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<S> > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\
    \u7DCF\u7A4D).\n\npublic:\n    using value_type = S;\n\n    // constructor. O(N*logN).\n\
    \    SparseTable() {}\n    explicit SparseTable(const Op &op, const std::vector<S>\
    \ &v) : m_op(op), m_sz(v.size()), m_lb(v.size() + 1, 0) {\n        for(int i =\
    \ 2; i <= size(); ++i) m_lb[i] = m_lb[i >> 1] + 1;\n        m_table.resize(m_lb[size()]\
    \ + 1);\n        m_table[0].assign(v.begin(), v.end());\n        for(int k = 1;\
    \ k <= m_lb[size()]; ++k) {\n            int n = size() - (1 << k) + 1;\n    \
    \        m_table[k].resize(n);\n            for(int i = 0; i < n; ++i) m_table[k][i]\
    \ = m_op(m_table[k - 1][i], m_table[k - 1][i + (1 << (k - 1))]);\n        }\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(1).\n    S fold(int l, int r) const {\n        assert(0 <= l and\
    \ l < r and r <= size());\n        int k = m_lb[r - l];\n        return m_op(m_table[k][l],\
    \ m_table[k][r - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 8 \"verify/yosupo-staticrmp-sparse_table.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int> a(n);\n    for(auto\
    \ &in : a) std::cin >> in;\n\n    auto op = [](int a, int b) -> int { return std::min(a,\
    \ b); };\n    algorithm::SparseTable<int> sparse_table(op, a);\n\n    while(q--)\
    \ {\n        int l, r;\n        std::cin >> l >> r;\n\n        auto &&ans = sparse_table.fold(l,\
    \ r);\n        std::cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"../lib/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &in : a) std::cin >> in;\n\n    auto op = [](int a, int\
    \ b) -> int { return std::min(a, b); };\n    algorithm::SparseTable<int> sparse_table(op,\
    \ a);\n\n    while(q--) {\n        int l, r;\n        std::cin >> l >> r;\n\n\
    \        auto &&ans = sparse_table.fold(l, r);\n        std::cout << ans << \"\
    \\n\";\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/sparse_table.hpp
  isVerificationFile: true
  path: verify/yosupo-staticrmp-sparse_table.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-staticrmp-sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-staticrmp-sparse_table.test.cpp
- /verify/verify/yosupo-staticrmp-sparse_table.test.cpp.html
title: verify/yosupo-staticrmp-sparse_table.test.cpp
---
