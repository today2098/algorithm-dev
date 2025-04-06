---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
    title: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/Others/binary_heap.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ T, auto comp>\nclass BinaryHeap {\n    static_assert(std::is_convertible_v<decltype(comp),\
    \ std::function<bool(T, T)>>);\n\npublic:\n    using value_type = T;\n    using\
    \ size_type = std::size_t;\n\nprivate:\n    std::vector<value_type> m_tree;  //\
    \ m_tree[]:=(\u5B8C\u5168\u4E8C\u5206\u6728).\n\n    void shift_up(size_type k)\
    \ {\n        assert(k >= 1);\n        for(size_type p = k >> 1; p >= 1; p >>=\
    \ 1) {\n            if(comp(m_tree[k - 1], m_tree[p - 1])) break;\n          \
    \  std::swap(m_tree[k - 1], m_tree[p - 1]);\n            k = p;\n        }\n \
    \   }\n    void shift_down(size_type k) {\n        assert(k >= 1);\n        for(size_type\
    \ l = k << 1, r = k << 1 | 1, end = size(); l <= end; l = k << 1, r = k << 1 |\
    \ 1) {\n            if(r <= end and comp(m_tree[l - 1], m_tree[r - 1])) {\n  \
    \              if(comp(m_tree[r - 1], m_tree[k - 1])) break;\n               \
    \ std::swap(m_tree[r - 1], m_tree[k - 1]);\n                k = r;\n         \
    \   } else {\n                if(comp(m_tree[l - 1], m_tree[k - 1])) break;\n\
    \                std::swap(m_tree[l - 1], m_tree[k - 1]);\n                k =\
    \ l;\n            }\n        }\n    }\n    void heapify() {\n        for(size_type\
    \ i = size() >> 1; i >= 1; --i) shift_down(i);\n    }\n\npublic:\n    // constructor.\
    \ O(N).\n    BinaryHeap() : m_tree() {}\n    explicit BinaryHeap(const std::vector<value_type>\
    \ &v) : m_tree(v) {\n        heapify();\n    }\n    explicit BinaryHeap(std::vector<value_type>\
    \ &&v) : m_tree(std::move(v)) {\n        heapify();\n    }\n\n    // \u6BD4\u8F03\
    \u95A2\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto compare()\
    \ { return comp; }\n    // \u8981\u7D20\u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(1).\n    bool empty() const { return size() == 0; }\n    // \u8981\u7D20\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    size_type size() const {\
    \ return m_tree.size(); }\n    // \u5148\u982D\u8981\u7D20\u306E\u53C2\u7167\uFF0E\
    O(1).\n    value_type top() const {\n        assert(!empty());\n        return\
    \ m_tree[0];\n    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const\
    \ value_type &a) {\n        m_tree.push_back(a);\n        shift_up(size());\n\
    \    }\n    // \u5148\u982D\u8981\u7D20\u306E\u524A\u9664\uFF0EO(logN).\n    value_type\
    \ pop() {\n        assert(!empty());\n        value_type res = m_tree[0];\n  \
    \      m_tree[0] = m_tree[size() - 1];\n        m_tree.pop_back();\n        if(!empty())\
    \ shift_down(1);\n        return res;\n    }\n    void reset() { m_tree.clear();\
    \ }\n    void reserve(size_type cap) { m_tree.reserve(cap); }\n    void shrink_to_fit()\
    \ { m_tree.shrink_to_fit(); }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_HEAP_HPP\n#define ALGORITHM_BINARY_HEAP_HPP 1\n\n\
    #include <algorithm>\n#include <cassert>\n#include <functional>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ T, auto comp>\nclass BinaryHeap {\n    static_assert(std::is_convertible_v<decltype(comp),\
    \ std::function<bool(T, T)>>);\n\npublic:\n    using value_type = T;\n    using\
    \ size_type = std::size_t;\n\nprivate:\n    std::vector<value_type> m_tree;  //\
    \ m_tree[]:=(\u5B8C\u5168\u4E8C\u5206\u6728).\n\n    void shift_up(size_type k)\
    \ {\n        assert(k >= 1);\n        for(size_type p = k >> 1; p >= 1; p >>=\
    \ 1) {\n            if(comp(m_tree[k - 1], m_tree[p - 1])) break;\n          \
    \  std::swap(m_tree[k - 1], m_tree[p - 1]);\n            k = p;\n        }\n \
    \   }\n    void shift_down(size_type k) {\n        assert(k >= 1);\n        for(size_type\
    \ l = k << 1, r = k << 1 | 1, end = size(); l <= end; l = k << 1, r = k << 1 |\
    \ 1) {\n            if(r <= end and comp(m_tree[l - 1], m_tree[r - 1])) {\n  \
    \              if(comp(m_tree[r - 1], m_tree[k - 1])) break;\n               \
    \ std::swap(m_tree[r - 1], m_tree[k - 1]);\n                k = r;\n         \
    \   } else {\n                if(comp(m_tree[l - 1], m_tree[k - 1])) break;\n\
    \                std::swap(m_tree[l - 1], m_tree[k - 1]);\n                k =\
    \ l;\n            }\n        }\n    }\n    void heapify() {\n        for(size_type\
    \ i = size() >> 1; i >= 1; --i) shift_down(i);\n    }\n\npublic:\n    // constructor.\
    \ O(N).\n    BinaryHeap() : m_tree() {}\n    explicit BinaryHeap(const std::vector<value_type>\
    \ &v) : m_tree(v) {\n        heapify();\n    }\n    explicit BinaryHeap(std::vector<value_type>\
    \ &&v) : m_tree(std::move(v)) {\n        heapify();\n    }\n\n    // \u6BD4\u8F03\
    \u95A2\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto compare()\
    \ { return comp; }\n    // \u8981\u7D20\u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(1).\n    bool empty() const { return size() == 0; }\n    // \u8981\u7D20\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    size_type size() const {\
    \ return m_tree.size(); }\n    // \u5148\u982D\u8981\u7D20\u306E\u53C2\u7167\uFF0E\
    O(1).\n    value_type top() const {\n        assert(!empty());\n        return\
    \ m_tree[0];\n    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const\
    \ value_type &a) {\n        m_tree.push_back(a);\n        shift_up(size());\n\
    \    }\n    // \u5148\u982D\u8981\u7D20\u306E\u524A\u9664\uFF0EO(logN).\n    value_type\
    \ pop() {\n        assert(!empty());\n        value_type res = m_tree[0];\n  \
    \      m_tree[0] = m_tree[size() - 1];\n        m_tree.pop_back();\n        if(!empty())\
    \ shift_down(1);\n        return res;\n    }\n    void reset() { m_tree.clear();\
    \ }\n    void reserve(size_type cap) { m_tree.reserve(cap); }\n    void shrink_to_fit()\
    \ { m_tree.shrink_to_fit(); }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/Others/binary_heap.hpp
  requiredBy: []
  timestamp: '2025-03-30 12:53:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_9_C-binary_heap.test.cpp
documentation_of: lib/DataStructure/Others/binary_heap.hpp
layout: document
title: "Binary Heap\uFF08\u4E8C\u5206\u30D2\u30FC\u30D7\uFF09"
---


## 概要

（広義の）完全二分木を用いたヒープ．
基本的な機能は `std::priority_queue` と同じ．

二分ヒープは，ある全順序集合 $S = \lbrace a_1, a_2, \ldots, a_n \rbrace$ の要素を，次のヒープ条件を満たすように完全二分木の各点に割り当て管理する．

> 親の要素は子の要素より常に大きいか等しい

ヒープの根（先頭）は集合 $S$ の中の最大要素になる．

`BinaryHeap` に関する各操作の計算量は次の通り（ただし，$N$ はヒープに含まれる要素の数）． 

| 操作                | 説明           | 計算量                |
| ------------------- | -------------- | --------------------- |
| `size`              | 要素数の取得   | $\mathcal{O}(1)$      |
| `top`               | 先頭要素の参照 | $\mathcal{O}(1)$      |
| `push`              | 要素追加       | $\mathcal{O}(\log N)$ |
| `pop`               | 先頭要素の削除 | $\mathcal{O}(\log N)$ |
| `heapify` (private) | ヒープ化       | $\mathcal{O}(N)$      |


## 参考文献

1. 渡邉 敏正. "第4章 ヒープ". データ構造と基本アルゴリズム. 共立出版, 2000, pp.109-126.
1. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
1. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
1. "優先度付きキュー". Wikipedia. <https://ja.wikipedia.org/wiki/優先度付きキュー>.
1. "全順序". Wikipedia. <https://ja.wikipedia.org/wiki/全順序>.
