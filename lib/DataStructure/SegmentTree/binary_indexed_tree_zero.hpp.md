---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SegmentTree/binary_indexed_tree_zero.md
    document_title: Binary Indexed Tree (0-based index)
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n\n\n\n/**\n * @brief Binary Indexed Tree (0-based index)\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree_zero.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Binary Indexed Tree (0-based index).\ntemplate <typename T>\n\
    class BIT0 {\n    int m_sz;               // m_sz:=(\u914D\u5217\u306E\u8981\u7D20\
    \u6570).\n    std::vector<T> m_tree;  // 0-based index.\n\n    void build() {\n\
    \        for(int i = 0; i < size() - 1; ++i) {\n            int j = i | (i + 1);\n\
    \            if(j < size()) m_tree[j] += m_tree[i];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT0() : BIT0(0) {};\n    explicit BIT0(size_t\
    \ n, T a = 0) : m_sz(n), m_tree(n, a) {\n        if(a != 0) build();\n    }\n\
    \    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()), m_tree(v) {\n  \
    \      build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n\
    \    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\
    \u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0EO(logN).\n    void add(int k, T a)\
    \ {\n        assert(0 <= k and k < size());\n        for(; k < size(); k |= k\
    \ + 1) m_tree[k] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n\
    \        assert(0 <= r and r <= size());\n        T res = 0;\n        for(r =\
    \ r - 1; r >= 0; r = (r & (r + 1)) - 1) res += m_tree[r];\n        return res;\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= size());\n        return sum(r) - sum(l);\n    }\n\
    \    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\uFF0EO(N).\n    void\
    \ fill(T a = 0) {\n        std::fill(m_tree.begin(), m_tree.end(), a);\n     \
    \   if(a != 0) build();\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP\
    \ 1\n\n/**\n * @brief Binary Indexed Tree (0-based index)\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree_zero.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Binary Indexed Tree (0-based index).\ntemplate <typename T>\n\
    class BIT0 {\n    int m_sz;               // m_sz:=(\u914D\u5217\u306E\u8981\u7D20\
    \u6570).\n    std::vector<T> m_tree;  // 0-based index.\n\n    void build() {\n\
    \        for(int i = 0; i < size() - 1; ++i) {\n            int j = i | (i + 1);\n\
    \            if(j < size()) m_tree[j] += m_tree[i];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT0() : BIT0(0) {};\n    explicit BIT0(size_t\
    \ n, T a = 0) : m_sz(n), m_tree(n, a) {\n        if(a != 0) build();\n    }\n\
    \    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()), m_tree(v) {\n  \
    \      build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n\
    \    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\
    \u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0EO(logN).\n    void add(int k, T a)\
    \ {\n        assert(0 <= k and k < size());\n        for(; k < size(); k |= k\
    \ + 1) m_tree[k] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n\
    \        assert(0 <= r and r <= size());\n        T res = 0;\n        for(r =\
    \ r - 1; r >= 0; r = (r & (r + 1)) - 1) res += m_tree[r];\n        return res;\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= size());\n        return sum(r) - sum(l);\n    }\n\
    \    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\uFF0EO(N).\n    void\
    \ fill(T a = 0) {\n        std::fill(m_tree.begin(), m_tree.end(), a);\n     \
    \   if(a != 0) build();\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
  requiredBy: []
  timestamp: '2024-09-07 15:00:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
layout: document
redirect_from:
- /library/lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
- /library/lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp.html
title: Binary Indexed Tree (0-based index)
---
## 概要

0-based index の「Binary Indexed Tree (BIT)」．

長さ $N$ の整数値の配列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総和を求める．

任意の区間 $[l,r)$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ と計算すればよい．


## 問題

- "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
