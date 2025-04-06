---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/Others/binary_heap.hpp
    title: "Binary Heap\uFF08\u4E8C\u5206\u30D2\u30FC\u30D7\uFF09"
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
    \ <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\ntemplate <typename T, auto comp>\nclass BinaryHeap {\n    static_assert(std::is_convertible_v<decltype(comp),\
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
    \ { m_tree.shrink_to_fit(); }\n};\n\n}  // namespace algorithm\n\n\n#line 7 \"\
    verify/aoj-ALDS1_9_C-binary_heap.test.cpp\"\n\nint main() {\n    using Type =\
    \ int;\n    auto comp = [](Type a, Type b) -> bool { return a < b; };\n    algorithm::BinaryHeap<Type,\
    \ comp> heap;\n\n    while(true) {\n        std::string op;\n        std::cin\
    \ >> op;\n\n        if(op == \"insert\") {\n            Type k;\n            std::cin\
    \ >> k;\n\n            heap.push(k);\n        } else if(op == \"extract\") {\n\
    \            auto &&ans = heap.pop();\n            std::cout << ans << \"\\n\"\
    ;\n        } else {\n            break;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../lib/DataStructure/Others/binary_heap.hpp\"\
    \n\nint main() {\n    using Type = int;\n    auto comp = [](Type a, Type b) ->\
    \ bool { return a < b; };\n    algorithm::BinaryHeap<Type, comp> heap;\n\n   \
    \ while(true) {\n        std::string op;\n        std::cin >> op;\n\n        if(op\
    \ == \"insert\") {\n            Type k;\n            std::cin >> k;\n\n      \
    \      heap.push(k);\n        } else if(op == \"extract\") {\n            auto\
    \ &&ans = heap.pop();\n            std::cout << ans << \"\\n\";\n        } else\
    \ {\n            break;\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/Others/binary_heap.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
  requiredBy: []
  timestamp: '2025-03-30 12:53:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_9_C-binary_heap.test.cpp
- /verify/verify/aoj-ALDS1_9_C-binary_heap.test.cpp.html
title: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
---
