---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-staticrmp-sparse_table.test.cpp
    title: verify/yosupo-staticrmp-sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/sparse_table.hpp\"\n\n\n\n\
    #include <cassert>\n#include <functional>\n#include <iterator>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u9759\u7684\
    \u306A\u6570\u5217\u306B\u5BFE\u3057\uFF0C\u7D50\u5408\u5247 (A\u2022B)\u2022\
    C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\u6027 A\u2022A=A \u304C\u6210\u308A\u7ACB\
    \u3064\u6F14\u7B97\uFF08min, max, gcd, lcm, bitwise-and, bitwise-or\u306A\u3069\
    \uFF09\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\u308B\uFF0E\ntemplate\
    \ <typename S, auto op>\nclass SparseTable {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>);\n\npublic:\n    using value_type = S;\n    using size_type\
    \ = std::size_t;\n    using iterator = std::vector<value_type>::const_iterator;\n\
    \    using const_iterator = std::vector<value_type>::const_iterator;\n    using\
    \ reverse_iterator = std::vector<value_type>::const_reverse_iterator;\n    using\
    \ const_reverse_iterator = std::vector<value_type>::const_reverse_iterator;\n\n\
    private:\n    size_type m_sz;                                // m_sz:=(\u8981\u7D20\
    \u6570).\n    std::vector<size_type> m_lg;                   // m_lg[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<value_type>> m_table;  // m_table[k][l]:=(\u533A\u9593\
    [l,l+2^k)\u306E\u7DCF\u7A4D).\n\n    void build() {\n        for(size_type i =\
    \ 2; i <= m_sz; ++i) m_lg[i] = m_lg[i >> 1] + 1;\n        m_table.resize(m_lg[m_sz]\
    \ + 1);\n        for(size_type k = 1; k <= m_lg[size()]; ++k) {\n            size_type\
    \ n = m_sz - (1U << k) + 1;\n            m_table[k].resize(n);\n            for(size_type\
    \ i = 0; i < n; ++i) m_table[k][i] = op(m_table[k - 1][i], m_table[k - 1][i +\
    \ (1U << (k - 1))]);\n        }\n    }\n\npublic:\n    // constructor. O(N*logN).\n\
    \    SparseTable() : m_sz(0) {}\n    explicit SparseTable(const std::vector<value_type>\
    \ &v) : m_sz(v.size()), m_lg(v.size() + 1, 0), m_table(1, v) {\n        build();\n\
    \    }\n    explicit SparseTable(std::vector<value_type> &&v) : m_sz(v.size()),\
    \ m_lg(v.size() + 1, 0), m_table(1) {\n        m_table[0] = std::move(v);\n  \
    \      build();\n    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    static constexpr auto operation() { return op; }\n\
    \    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(size_type k) const {\n    \
    \    assert(k < size());\n        return m_table[0][k];\n    }\n    // \u533A\u9593\
    [l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    value_type prod(size_type\
    \ l, size_type r) const {\n        assert(l < r and r <= size());\n        size_type\
    \ k = m_lg[r - l];\n        return op(m_table[k][l], m_table[k][r - (1U << k)]);\n\
    \    }\n\n    const_iterator begin() const { return m_table[0].begin(); }\n  \
    \  const_iterator end() const { return m_table[0].end(); }\n    const_iterator\
    \ cbegin() const { return m_table[0].cbegin(); }\n    const_iterator cend() const\
    \ { return m_table[0].cend(); }\n    const_reverse_iterator rbegin() const { return\
    \ m_table[0].rbegin(); }\n    const_reverse_iterator rend() const { return m_table[0].rend();\
    \ }\n    const_reverse_iterator crbegin() const { return m_table[0].crbegin();\
    \ }\n    const_reverse_iterator crend() const { return m_table[0].crend(); }\n\
    };\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SPARSE_TABLE_HPP\n#define ALGORITHM_SPARSE_TABLE_HPP 1\n\
    \n#include <cassert>\n#include <functional>\n#include <iterator>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u9759\u7684\
    \u306A\u6570\u5217\u306B\u5BFE\u3057\uFF0C\u7D50\u5408\u5247 (A\u2022B)\u2022\
    C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\u6027 A\u2022A=A \u304C\u6210\u308A\u7ACB\
    \u3064\u6F14\u7B97\uFF08min, max, gcd, lcm, bitwise-and, bitwise-or\u306A\u3069\
    \uFF09\u306E\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\u308B\uFF0E\ntemplate\
    \ <typename S, auto op>\nclass SparseTable {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>);\n\npublic:\n    using value_type = S;\n    using size_type\
    \ = std::size_t;\n    using iterator = std::vector<value_type>::const_iterator;\n\
    \    using const_iterator = std::vector<value_type>::const_iterator;\n    using\
    \ reverse_iterator = std::vector<value_type>::const_reverse_iterator;\n    using\
    \ const_reverse_iterator = std::vector<value_type>::const_reverse_iterator;\n\n\
    private:\n    size_type m_sz;                                // m_sz:=(\u8981\u7D20\
    \u6570).\n    std::vector<size_type> m_lg;                   // m_lg[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<value_type>> m_table;  // m_table[k][l]:=(\u533A\u9593\
    [l,l+2^k)\u306E\u7DCF\u7A4D).\n\n    void build() {\n        for(size_type i =\
    \ 2; i <= m_sz; ++i) m_lg[i] = m_lg[i >> 1] + 1;\n        m_table.resize(m_lg[m_sz]\
    \ + 1);\n        for(size_type k = 1; k <= m_lg[size()]; ++k) {\n            size_type\
    \ n = m_sz - (1U << k) + 1;\n            m_table[k].resize(n);\n            for(size_type\
    \ i = 0; i < n; ++i) m_table[k][i] = op(m_table[k - 1][i], m_table[k - 1][i +\
    \ (1U << (k - 1))]);\n        }\n    }\n\npublic:\n    // constructor. O(N*logN).\n\
    \    SparseTable() : m_sz(0) {}\n    explicit SparseTable(const std::vector<value_type>\
    \ &v) : m_sz(v.size()), m_lg(v.size() + 1, 0), m_table(1, v) {\n        build();\n\
    \    }\n    explicit SparseTable(std::vector<value_type> &&v) : m_sz(v.size()),\
    \ m_lg(v.size() + 1, 0), m_table(1) {\n        m_table[0] = std::move(v);\n  \
    \      build();\n    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    static constexpr auto operation() { return op; }\n\
    \    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(size_type k) const {\n    \
    \    assert(k < size());\n        return m_table[0][k];\n    }\n    // \u533A\u9593\
    [l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    value_type prod(size_type\
    \ l, size_type r) const {\n        assert(l < r and r <= size());\n        size_type\
    \ k = m_lg[r - l];\n        return op(m_table[k][l], m_table[k][r - (1U << k)]);\n\
    \    }\n\n    const_iterator begin() const { return m_table[0].begin(); }\n  \
    \  const_iterator end() const { return m_table[0].end(); }\n    const_iterator\
    \ cbegin() const { return m_table[0].cbegin(); }\n    const_iterator cend() const\
    \ { return m_table[0].cend(); }\n    const_reverse_iterator rbegin() const { return\
    \ m_table[0].rbegin(); }\n    const_reverse_iterator rend() const { return m_table[0].rend();\
    \ }\n    const_reverse_iterator crbegin() const { return m_table[0].crbegin();\
    \ }\n    const_reverse_iterator crend() const { return m_table[0].crend(); }\n\
    };\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/sparse_table.hpp
  requiredBy: []
  timestamp: '2025-03-29 17:30:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-staticrmp-sparse_table.test.cpp
documentation_of: lib/DataStructure/SegmentTree/sparse_table.hpp
layout: document
title: Sparse Table
---


## 概要

静的な要素列に対し，帯（冪等半群）を成す演算（$\min, \max, \gcd, \operatorname{lcm}, \operatorname{bitwise-and}, \operatorname{bitwise-or}$ など）による任意の区間クエリを求める．

ここで「帯」とは，以下の性質を満たす代数的構造を指す．

- 結合則：$(A \oplus B) \oplus C = A \oplus (B \oplus C)$
- 冪等性：$A \oplus A = A$

アルゴリズムの計算量は，クエリ処理が $\mathcal{O}(1)$ と速い．
一方で，要素列の長さを $N$ とすると，テーブル構築の時間計算量および空間計算量に $\mathcal{O}(N \log N)$ を要する．
状況に応じて「Segment Tree」と使い分けること．


## 参考文献

1. "半群". Wikipedia. <https://ja.wikipedia.org/wiki/半群>.
1. "冪等". Wikipedia. <https://ja.wikipedia.org/wiki/冪等>.
1. tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
1. "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
