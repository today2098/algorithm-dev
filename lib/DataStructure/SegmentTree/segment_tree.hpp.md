---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_2_A-segment_tree.test.cpp
    title: test/aoj-DSL_2_A-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_2_B-segment_tree.test.cpp
    title: test/aoj-DSL_2_B-segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SegmentTree/segment_tree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/segment_tree.hpp\"\n\n\n\n\
    /**\n * @brief Segment Tree\n * @docs docs/DataStructure/SegmentTree/segment_tree.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ S>\nclass SegmentTree {\n    using Op = std::function<S(const S &, const S &)>;\n\
    \n    Op m_op;                // S m_op(S,S):=(\u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    ).\n    S m_e;                  // m_e:=(\u5358\u4F4D\u5143).\n    int m_sz; \
    \              // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;                //\
    \ m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    std::vector<S>\
    \ m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\
    \npublic:\n    // constructor. O(N).\n    SegmentTree() {};\n    explicit SegmentTree(const\
    \ Op &op, const S &e, size_t n) : m_op(op), m_e(e), m_sz(n), m_n(1) {\n      \
    \  while(m_n < size()) m_n <<= 1;\n        m_tree.assign(2 * m_n, identity());\n\
    \    }\n    explicit SegmentTree(const Op &op, const S &e, const std::vector<S>\
    \ &v) : SegmentTree(op, e, v.size()) {\n        std::copy(v.begin(), v.end(),\
    \ m_tree.begin() + m_n);\n        for(int i = m_n - 1; i >= 1; --i) m_tree[i]\
    \ = m_op(m_tree[i << 1], m_tree[i << 1 | 1]);\n    }\n\n    // \u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    // \u5358\
    \u4F4D\u5143\u3092\u8FD4\u3059\uFF0E\n    S identity() const { return m_e; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \uFF0EO(logN).\n    void set(int k, const S &a) {\n        assert(0 <= k and k\
    \ < size());\n        k += m_n;\n        m_tree[k] = a;\n        while(k >>= 1)\
    \ m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 | 1]);\n    }\n    // k\u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\uFF0EO(1).\n    S prod(int k) const\
    \ {\n        assert(0 <= k and k < size());\n        return m_tree[k + m_n];\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D v[l]\u2022\
    v[l+1]\u2022...\u2022v[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l and l <= r and r <= size());\n    \
    \    S val_l = identity(), val_r = identity();\n        l += m_n, r += m_n;\n\
    \        while(l < r) {\n            if(l & 1) val_l = m_op(val_l, m_tree[l++]);\n\
    \            if(r & 1) val_r = m_op(m_tree[--r], val_r);\n            l >>= 1,\
    \ r >>= 1;\n        }\n        return m_op(val_l, val_r);\n    }\n    // \u533A\
    \u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\uFF0E\
    O(1).\n    S prod_all() const { return m_tree[1]; }\n    // f(prod(l,-))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F f(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    int most_right(const Func &f, int l) const {\n        assert(f(identity())\
    \ == true);\n        assert(0 <= l and l <= size());\n        if(l == size())\
    \ return size();\n        S val = identity();\n        l += m_n;\n        do {\n\
    \            while(!(l & 1)) l >>= 1;\n            S &&tmp = m_op(val, m_tree[l]);\n\
    \            if(!f(tmp)) {\n                while(l < m_n) {\n               \
    \     l <<= 1;\n                    S &&tmp2 = m_op(val, m_tree[l]);\n       \
    \             if(f(tmp2)) val = tmp2, l++;\n                }\n              \
    \  return l - m_n;\n            }\n            val = tmp, l++;\n        } while((l\
    \ & -l) != l);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\
    \u6570\uFF0E\n        return size();\n    }\n    // f(prod(-,r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306B\u306F\
    \u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F f(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    int most_left(const Func &f, int r) const {\n        assert(f(identity())\
    \ == true);\n        assert(0 <= r and r <= size());\n        if(r == 0) return\
    \ 0;\n        S val = identity();\n        r += m_n;\n        do {\n         \
    \   r--;\n            while(r > 1 and r & 1) r >>= 1;\n            S &&tmp = m_op(m_tree[r],\
    \ val);\n            if(!f(tmp)) {\n                while(r < m_n) {\n       \
    \             r = (r << 1) | 1;\n                    S &&tmp2 = m_op(m_tree[r],\
    \ val);\n                    if(f(tmp2)) val = tmp2, r--;\n                }\n\
    \                return r - m_n + 1;\n            }\n            val = tmp;\n\
    \        } while((r & -r) != r);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F\
    2\u306E\u968E\u4E57\u6570\uFF0E\n        return 0;\n    }\n    void reset() {\
    \ std::fill(m_tree.begin(), m_tree.end(), identity()); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const SegmentTree &segtree) {\n        int l =\
    \ 1, r = 2;\n        os << \"[\\n\";\n        while(l < 2 * segtree.m_n) {\n \
    \           os << \"  [\";\n            for(int i = l; i < r; ++i) os << (i ==\
    \ l ? \"\" : \" \") << segtree.m_tree[i];\n            os << \"]\\n\";\n     \
    \       l <<= 1, r <<= 1;\n        }\n        os << \"]\";\n        return os;\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SEGMENT_TREE_HPP\n#define ALGORITHM_SEGMENT_TREE_HPP 1\n\
    \n/**\n * @brief Segment Tree\n * @docs docs/DataStructure/SegmentTree/segment_tree.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <iostream>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ S>\nclass SegmentTree {\n    using Op = std::function<S(const S &, const S &)>;\n\
    \n    Op m_op;                // S m_op(S,S):=(\u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    ).\n    S m_e;                  // m_e:=(\u5358\u4F4D\u5143).\n    int m_sz; \
    \              // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;                //\
    \ m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    std::vector<S>\
    \ m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\
    \npublic:\n    // constructor. O(N).\n    SegmentTree() {};\n    explicit SegmentTree(const\
    \ Op &op, const S &e, size_t n) : m_op(op), m_e(e), m_sz(n), m_n(1) {\n      \
    \  while(m_n < size()) m_n <<= 1;\n        m_tree.assign(2 * m_n, identity());\n\
    \    }\n    explicit SegmentTree(const Op &op, const S &e, const std::vector<S>\
    \ &v) : SegmentTree(op, e, v.size()) {\n        std::copy(v.begin(), v.end(),\
    \ m_tree.begin() + m_n);\n        for(int i = m_n - 1; i >= 1; --i) m_tree[i]\
    \ = m_op(m_tree[i << 1], m_tree[i << 1 | 1]);\n    }\n\n    // \u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    // \u5358\
    \u4F4D\u5143\u3092\u8FD4\u3059\uFF0E\n    S identity() const { return m_e; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \uFF0EO(logN).\n    void set(int k, const S &a) {\n        assert(0 <= k and k\
    \ < size());\n        k += m_n;\n        m_tree[k] = a;\n        while(k >>= 1)\
    \ m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 | 1]);\n    }\n    // k\u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\uFF0EO(1).\n    S prod(int k) const\
    \ {\n        assert(0 <= k and k < size());\n        return m_tree[k + m_n];\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D v[l]\u2022\
    v[l+1]\u2022...\u2022v[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l and l <= r and r <= size());\n    \
    \    S val_l = identity(), val_r = identity();\n        l += m_n, r += m_n;\n\
    \        while(l < r) {\n            if(l & 1) val_l = m_op(val_l, m_tree[l++]);\n\
    \            if(r & 1) val_r = m_op(m_tree[--r], val_r);\n            l >>= 1,\
    \ r >>= 1;\n        }\n        return m_op(val_l, val_r);\n    }\n    // \u533A\
    \u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u8FD4\u3059\uFF0E\
    O(1).\n    S prod_all() const { return m_tree[1]; }\n    // f(prod(l,-))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F f(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    int most_right(const Func &f, int l) const {\n        assert(f(identity())\
    \ == true);\n        assert(0 <= l and l <= size());\n        if(l == size())\
    \ return size();\n        S val = identity();\n        l += m_n;\n        do {\n\
    \            while(!(l & 1)) l >>= 1;\n            S &&tmp = m_op(val, m_tree[l]);\n\
    \            if(!f(tmp)) {\n                while(l < m_n) {\n               \
    \     l <<= 1;\n                    S &&tmp2 = m_op(val, m_tree[l]);\n       \
    \             if(f(tmp2)) val = tmp2, l++;\n                }\n              \
    \  return l - m_n;\n            }\n            val = tmp, l++;\n        } while((l\
    \ & -l) != l);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\
    \u6570\uFF0E\n        return size();\n    }\n    // f(prod(-,r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306B\u306F\
    \u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F f(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    int most_left(const Func &f, int r) const {\n        assert(f(identity())\
    \ == true);\n        assert(0 <= r and r <= size());\n        if(r == 0) return\
    \ 0;\n        S val = identity();\n        r += m_n;\n        do {\n         \
    \   r--;\n            while(r > 1 and r & 1) r >>= 1;\n            S &&tmp = m_op(m_tree[r],\
    \ val);\n            if(!f(tmp)) {\n                while(r < m_n) {\n       \
    \             r = (r << 1) | 1;\n                    S &&tmp2 = m_op(m_tree[r],\
    \ val);\n                    if(f(tmp2)) val = tmp2, r--;\n                }\n\
    \                return r - m_n + 1;\n            }\n            val = tmp;\n\
    \        } while((r & -r) != r);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F\
    2\u306E\u968E\u4E57\u6570\uFF0E\n        return 0;\n    }\n    void reset() {\
    \ std::fill(m_tree.begin(), m_tree.end(), identity()); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const SegmentTree &segtree) {\n        int l =\
    \ 1, r = 2;\n        os << \"[\\n\";\n        while(l < 2 * segtree.m_n) {\n \
    \           os << \"  [\";\n            for(int i = l; i < r; ++i) os << (i ==\
    \ l ? \"\" : \" \") << segtree.m_tree[i];\n            os << \"]\\n\";\n     \
    \       l <<= 1, r <<= 1;\n        }\n        os << \"]\";\n        return os;\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-09-01 16:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_2_A-segment_tree.test.cpp
  - test/aoj-DSL_2_B-segment_tree.test.cpp
documentation_of: lib/DataStructure/SegmentTree/segment_tree.hpp
layout: document
redirect_from:
- /library/lib/DataStructure/SegmentTree/segment_tree.hpp
- /library/lib/DataStructure/SegmentTree/segment_tree.hpp.html
title: Segment Tree
---
## 概要

長さ $N$ の配列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新**：要素 $a_i$ を $x$ で更新する
- **区間取得**：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する

本ライブラリで実装している Segment Tree は，いわゆる「抽象セグメント木」であり，オブジェクトを定義する際に扱うモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ を定義する．

ここで「モノイド」とは，集合 $S$ とその上の二項演算 $\bullet : S \times S \rightarrow S$ をもち，以下の条件を満たす代数構造のことをいう．

- 結合律：$(a \bullet b) \bullet c = a \bullet (b \bullet c) \quad (\forall a, \forall b, \forall c \in S)$
- 単位元の存在：$e \bullet a = a \bullet e = a \quad (e \in S, \forall a \in S)$

例えば，整数全体は加法あるいは乗法に関してモノイドを成す．


## 参考文献

1. "SegTree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/segtree.html>.
1. "モノイド". Wikipedia. <https://ja.wikipedia.org/wiki/モノイド>.
1. rsk0315. "セグ木のお勉強を敬遠している人へ". えびちゃんの日記. HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/07/05/184929>.
1. "セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree>.
