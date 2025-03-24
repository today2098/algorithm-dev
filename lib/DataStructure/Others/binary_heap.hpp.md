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
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u5206\u30D2\u30FC\u30D7\
    \ntemplate <typename T>\nclass BinaryHeap {\n    using Comp = std::function<bool(const\
    \ T &, const T &)>;\n\n    Comp m_comp;            // bool m_comp(T,T):=(\u6BD4\
    \u8F03\u6F14\u7B97\u5B50).\n    std::vector<T> m_tree;  // m_tree[]:=(\u5B8C\u5168\
    \u4E8C\u5206\u6728). 1-based index.\n\n    void shift_up(int k) {\n        int\
    \ par = k >> 1;\n        while(1 <= par) {\n            if(m_comp(m_tree[par],\
    \ m_tree[k])) break;\n            std::swap(m_tree[par], m_tree[k]);\n       \
    \     k = par;\n            par >>= 1;\n        }\n    }\n    void shift_down(int\
    \ k) {\n        int l = k << 1, r = k << 1 | 1;\n        while(l <= size()) {\n\
    \            if(size() < r or m_comp(m_tree[l], m_tree[r])) {\n              \
    \  if(m_comp(m_tree[k], m_tree[l])) break;\n                std::swap(m_tree[k],\
    \ m_tree[l]);\n                k = l;\n            } else {\n                if(m_comp(m_tree[k],\
    \ m_tree[r])) break;\n                std::swap(m_tree[k], m_tree[r]);\n     \
    \           k = r;\n            }\n            l = k << 1, r = k << 1 | 1;\n \
    \       }\n    }\n    void heapify() {\n        for(int i = size() >> 1; i >=\
    \ 1; --i) shift_down(i);\n    }\n\npublic:\n    // constructor. O(N).\n    BinaryHeap()\
    \ : BinaryHeap([](const T &a, const T &b) -> bool { return a > b; }) {}\n    explicit\
    \ BinaryHeap(size_t n) : BinaryHeap([](const T &a, const T &b) -> bool { return\
    \ a > b; }, n) {}\n    explicit BinaryHeap(const std::vector<T> &v) : BinaryHeap(v,\
    \ [](const T &a, const T &b) -> bool { return a > b; }) {}\n    explicit BinaryHeap(const\
    \ std::vector<T> &v, size_t n) : BinaryHeap(v, [](const T &a, const T &b) -> bool\
    \ { return a > b; }, n) {}\n    explicit BinaryHeap(const Comp &comp) : m_comp(comp),\
    \ m_tree(1) {}\n    explicit BinaryHeap(const Comp &comp, size_t n) : BinaryHeap(comp)\
    \ {\n        m_tree.reserve(n + 1);\n    }\n    explicit BinaryHeap(const std::vector<T>\
    \ &v, const Comp &comp) : m_comp(comp), m_tree(v.size() + 1) {\n        std::copy(v.begin(),\
    \ v.end(), m_tree.begin() + 1);\n        heapify();\n    }\n    explicit BinaryHeap(const\
    \ std::vector<T> &v, const Comp &comp, size_t n) : BinaryHeap(v, comp) {\n   \
    \     m_tree.reserve(n + 1);\n    }\n\n    // \u8981\u7D20\u304C\u7A7A\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const { return size() == 0; }\n\
    \    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    int size() const\
    \ { return m_tree.size() - 1; }\n    // \u5148\u982D\u8981\u7D20\u306E\u53C2\u7167\
    \uFF0EO(1).\n    T top() const {\n        assert(!empty());\n        return m_tree[1];\n\
    \    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const T &x)\
    \ {\n        m_tree.push_back(x);\n        shift_up(size());\n    }\n    // \u5148\
    \u982D\u8981\u7D20\u306E\u524A\u9664\uFF0EO(logN).\n    T pop() {\n        assert(!empty());\n\
    \        T res = m_tree[1];\n        m_tree[1] = m_tree[size()];\n        m_tree.pop_back();\n\
    \        if(!empty()) shift_down(1);\n        return res;\n    }\n    // \u30D2\
    \u30FC\u30D7\u5316\uFF0EO(N).\n    void heapify(const Comp &comp) {\n        m_comp\
    \ = comp;\n        heapify();\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_HEAP_HPP\n#define ALGORITHM_BINARY_HEAP_HPP 1\n\n\
    #include <algorithm>\n#include <cassert>\n#include <functional>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u5206\u30D2\u30FC\u30D7\
    \ntemplate <typename T>\nclass BinaryHeap {\n    using Comp = std::function<bool(const\
    \ T &, const T &)>;\n\n    Comp m_comp;            // bool m_comp(T,T):=(\u6BD4\
    \u8F03\u6F14\u7B97\u5B50).\n    std::vector<T> m_tree;  // m_tree[]:=(\u5B8C\u5168\
    \u4E8C\u5206\u6728). 1-based index.\n\n    void shift_up(int k) {\n        int\
    \ par = k >> 1;\n        while(1 <= par) {\n            if(m_comp(m_tree[par],\
    \ m_tree[k])) break;\n            std::swap(m_tree[par], m_tree[k]);\n       \
    \     k = par;\n            par >>= 1;\n        }\n    }\n    void shift_down(int\
    \ k) {\n        int l = k << 1, r = k << 1 | 1;\n        while(l <= size()) {\n\
    \            if(size() < r or m_comp(m_tree[l], m_tree[r])) {\n              \
    \  if(m_comp(m_tree[k], m_tree[l])) break;\n                std::swap(m_tree[k],\
    \ m_tree[l]);\n                k = l;\n            } else {\n                if(m_comp(m_tree[k],\
    \ m_tree[r])) break;\n                std::swap(m_tree[k], m_tree[r]);\n     \
    \           k = r;\n            }\n            l = k << 1, r = k << 1 | 1;\n \
    \       }\n    }\n    void heapify() {\n        for(int i = size() >> 1; i >=\
    \ 1; --i) shift_down(i);\n    }\n\npublic:\n    // constructor. O(N).\n    BinaryHeap()\
    \ : BinaryHeap([](const T &a, const T &b) -> bool { return a > b; }) {}\n    explicit\
    \ BinaryHeap(size_t n) : BinaryHeap([](const T &a, const T &b) -> bool { return\
    \ a > b; }, n) {}\n    explicit BinaryHeap(const std::vector<T> &v) : BinaryHeap(v,\
    \ [](const T &a, const T &b) -> bool { return a > b; }) {}\n    explicit BinaryHeap(const\
    \ std::vector<T> &v, size_t n) : BinaryHeap(v, [](const T &a, const T &b) -> bool\
    \ { return a > b; }, n) {}\n    explicit BinaryHeap(const Comp &comp) : m_comp(comp),\
    \ m_tree(1) {}\n    explicit BinaryHeap(const Comp &comp, size_t n) : BinaryHeap(comp)\
    \ {\n        m_tree.reserve(n + 1);\n    }\n    explicit BinaryHeap(const std::vector<T>\
    \ &v, const Comp &comp) : m_comp(comp), m_tree(v.size() + 1) {\n        std::copy(v.begin(),\
    \ v.end(), m_tree.begin() + 1);\n        heapify();\n    }\n    explicit BinaryHeap(const\
    \ std::vector<T> &v, const Comp &comp, size_t n) : BinaryHeap(v, comp) {\n   \
    \     m_tree.reserve(n + 1);\n    }\n\n    // \u8981\u7D20\u304C\u7A7A\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const { return size() == 0; }\n\
    \    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    int size() const\
    \ { return m_tree.size() - 1; }\n    // \u5148\u982D\u8981\u7D20\u306E\u53C2\u7167\
    \uFF0EO(1).\n    T top() const {\n        assert(!empty());\n        return m_tree[1];\n\
    \    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const T &x)\
    \ {\n        m_tree.push_back(x);\n        shift_up(size());\n    }\n    // \u5148\
    \u982D\u8981\u7D20\u306E\u524A\u9664\uFF0EO(logN).\n    T pop() {\n        assert(!empty());\n\
    \        T res = m_tree[1];\n        m_tree[1] = m_tree[size()];\n        m_tree.pop_back();\n\
    \        if(!empty()) shift_down(1);\n        return res;\n    }\n    // \u30D2\
    \u30FC\u30D7\u5316\uFF0EO(N).\n    void heapify(const Comp &comp) {\n        m_comp\
    \ = comp;\n        heapify();\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/Others/binary_heap.hpp
  requiredBy: []
  timestamp: '2025-01-12 02:15:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_9_C-binary_heap.test.cpp
documentation_of: lib/DataStructure/Others/binary_heap.hpp
layout: document
title: "\u4E8C\u5206\u30D2\u30FC\u30D7"
---


## 概要

（広義の）完全二分木を用いたヒープ．
基本的な機能は `std::priority_queue` と同じ．

二分ヒープは，ある全順序集合 $S = \lbrace a_1, a_2, \ldots, a_n \rbrace$ の要素を，次のヒープ条件を満たすように完全二分木の各点に割り当て管理する．

> 親の要素は子の要素より常に大きいか等しい

ヒープの根（先頭）は集合 $S$ の中の最大要素になる．

`BinaryHeap` に関する各操作の計算量は次の通り（ただし，$N$ はヒープに含まれる要素の数）． 

| 操作      | 説明           | 計算量                |
| --------- | -------------- | --------------------- |
| `size`    | 要素数の取得   | $\mathcal{O}(1)$      |
| `top`     | 先頭要素の参照 | $\mathcal{O}(1)$      |
| `push`    | 要素追加       | $\mathcal{O}(\log N)$ |
| `pop`     | 先頭要素の削除 | $\mathcal{O}(\log N)$ |
| `heapify` | ヒープ化       | $\mathcal{O}(N)$      |


## 参考文献

1. 渡邉 敏正. "第4章 ヒープ". データ構造と基本アルゴリズム. 共立出版, 2000, pp.109-126.
2. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
3. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
4. "優先度付きキュー". Wikipedia. <https://ja.wikipedia.org/wiki/優先度付きキュー>.
5. "全順序". Wikipedia. <https://ja.wikipedia.org/wiki/全順序>.
