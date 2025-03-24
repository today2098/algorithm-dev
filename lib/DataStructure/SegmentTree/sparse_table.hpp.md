---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-staticrmp-sparse_table.test.cpp
    title: verify/yosupo-staticrmp-sparse_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SegmentTree/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/sparse_table.hpp\"\n\n\n\n\
    /**\n * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3057\uFF0C\u7D50\
    \u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\u6027 A\u2022\
    A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08min/max, gcd/lcm, bitwise-and/or\u306A\
    \u3069\uFF09\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\u308B\uFF0E\
    \ntemplate <typename S>  // S:\u51AA\u7B49\u534A\u7FA4\u306E\u578B.\nclass SparseTable\
    \ {\n    using Op = std::function<S(const S &, const S &)>;\n\n    Op m_op;  \
    \                             // S m_op(S,S):=(\u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    ).\n    int m_sz;                              // m_sz:=(\u8981\u7D20\u6570).\n\
    \    std::vector<int> m_lb;                 // m_lb[x]:=floor(log2(x)).\n    std::vector<std::vector<S>\
    \ > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\u7DCF\u7A4D).\n\n\
    public:\n    using value_type = S;\n\n    // constructor. O(N*logN).\n    SparseTable()\
    \ {}\n    explicit SparseTable(const Op &op, const std::vector<S> &v) : m_op(op),\
    \ m_sz(v.size()), m_lb(v.size() + 1, 0) {\n        for(int i = 2; i <= size();\
    \ ++i) m_lb[i] = m_lb[i >> 1] + 1;\n        m_table.resize(m_lb[size()] + 1);\n\
    \        m_table[0].assign(v.begin(), v.end());\n        for(int k = 1; k <= m_lb[size()];\
    \ ++k) {\n            int n = size() - (1 << k) + 1;\n            m_table[k].resize(n);\n\
    \            for(int i = 0; i < n; ++i) m_table[k][i] = m_op(m_table[k - 1][i],\
    \ m_table[k - 1][i + (1 << (k - 1))]);\n        }\n    }\n\n    // \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    //\
    \ \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n   \
    \ S fold(int l, int r) const {\n        assert(0 <= l and l < r and r <= size());\n\
    \        int k = m_lb[r - l];\n        return m_op(m_table[k][l], m_table[k][r\
    \ - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SPARSE_TABLE_HPP\n#define ALGORITHM_SPARSE_TABLE_HPP 1\n\
    \n/**\n * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3057\uFF0C\u7D50\
    \u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\u6027 A\u2022\
    A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08min/max, gcd/lcm, bitwise-and/or\u306A\
    \u3069\uFF09\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\u308B\uFF0E\
    \ntemplate <typename S>  // S:\u51AA\u7B49\u534A\u7FA4\u306E\u578B.\nclass SparseTable\
    \ {\n    using Op = std::function<S(const S &, const S &)>;\n\n    Op m_op;  \
    \                             // S m_op(S,S):=(\u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    ).\n    int m_sz;                              // m_sz:=(\u8981\u7D20\u6570).\n\
    \    std::vector<int> m_lb;                 // m_lb[x]:=floor(log2(x)).\n    std::vector<std::vector<S>\
    \ > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\u7DCF\u7A4D).\n\n\
    public:\n    using value_type = S;\n\n    // constructor. O(N*logN).\n    SparseTable()\
    \ {}\n    explicit SparseTable(const Op &op, const std::vector<S> &v) : m_op(op),\
    \ m_sz(v.size()), m_lb(v.size() + 1, 0) {\n        for(int i = 2; i <= size();\
    \ ++i) m_lb[i] = m_lb[i >> 1] + 1;\n        m_table.resize(m_lb[size()] + 1);\n\
    \        m_table[0].assign(v.begin(), v.end());\n        for(int k = 1; k <= m_lb[size()];\
    \ ++k) {\n            int n = size() - (1 << k) + 1;\n            m_table[k].resize(n);\n\
    \            for(int i = 0; i < n; ++i) m_table[k][i] = m_op(m_table[k - 1][i],\
    \ m_table[k - 1][i + (1 << (k - 1))]);\n        }\n    }\n\n    // \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    //\
    \ \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n   \
    \ S fold(int l, int r) const {\n        assert(0 <= l and l < r and r <= size());\n\
    \        int k = m_lb[r - l];\n        return m_op(m_table[k][l], m_table[k][r\
    \ - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-09-12 09:05:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-staticrmp-sparse_table.test.cpp
documentation_of: lib/DataStructure/SegmentTree/sparse_table.hpp
layout: document
redirect_from:
- /library/lib/DataStructure/SegmentTree/sparse_table.hpp
- /library/lib/DataStructure/SegmentTree/sparse_table.hpp.html
title: Sparse Table
---
## 概要

静的な数列に対し，帯（冪等半群）を成す演算（$\min$/$\max, \gcd$/$\operatorname{lcm}, \operatorname{bitwise-and}$/$\operatorname{or}$ など）による任意の区間クエリを求める．

ここで「帯」とは，以下の性質を満たす代数的構造を指す．

- 結合則：$(A \oplus B) \oplus C = A \oplus (B \oplus C)$
- 冪等性：$A \oplus A = A$

アルゴリズムの計算量は，クエリ処理が $\mathcal{O}(1)$ と速い．
一方で，数列の長さを $N$ とすると，テーブル構築の時間計算量及び空間計算量に $\mathcal{O}(N \log N)$ かかる．
状況に応じて「Segment Tree」と使い分けること．


## 参考文献

1. "半群". Wikipedia. <https://ja.wikipedia.org/wiki/半群>.
1. "冪等". Wikipedia. <https://ja.wikipedia.org/wiki/冪等>.
1. tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
1. "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
