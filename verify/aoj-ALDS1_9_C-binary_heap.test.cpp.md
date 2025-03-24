---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/Others/binary_heap.hpp
    title: "\u4E8C\u5206\u30D2\u30FC\u30D7"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C
  bundledCode: "#line 1 \"verify/aoj-ALDS1_9_C-binary_heap.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C\"\n\n\
    #include <iostream>\n#include <string>\n\n#line 1 \"lib/DataStructure/Others/binary_heap.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u5206\u30D2\
    \u30FC\u30D7\ntemplate <typename T>\nclass BinaryHeap {\n    using Comp = std::function<bool(const\
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
    \ = comp;\n        heapify();\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 7 \"verify/aoj-ALDS1_9_C-binary_heap.test.cpp\"\n\nint main() {\n    algorithm::BinaryHeap<int>\
    \ heap;\n\n    while(true) {\n        std::string op;\n        std::cin >> op;\n\
    \n        if(op == \"insert\") {\n            int k;\n            std::cin >>\
    \ k;\n\n            heap.push(k);\n        } else if(op == \"extract\") {\n  \
    \          std::cout << heap.pop() << \"\\n\";\n        } else {\n           \
    \ break;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../lib/DataStructure/Others/binary_heap.hpp\"\
    \n\nint main() {\n    algorithm::BinaryHeap<int> heap;\n\n    while(true) {\n\
    \        std::string op;\n        std::cin >> op;\n\n        if(op == \"insert\"\
    ) {\n            int k;\n            std::cin >> k;\n\n            heap.push(k);\n\
    \        } else if(op == \"extract\") {\n            std::cout << heap.pop() <<\
    \ \"\\n\";\n        } else {\n            break;\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/Others/binary_heap.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_9_C-binary_heap.test.cpp
- /verify/verify/aoj-ALDS1_9_C-binary_heap.test.cpp.html
title: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
---
