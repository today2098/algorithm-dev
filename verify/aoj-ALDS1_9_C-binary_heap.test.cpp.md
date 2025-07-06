---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/Others/binary_heap.hpp
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
    #include <iostream>\n#include <string>\n\n#line 1 \"algorithm/DataStructure/Others/binary_heap.hpp\"\
    \n\n\n\n#include <cassert>\n#include <initializer_list>\n#line 7 \"algorithm/DataStructure/Others/binary_heap.hpp\"\
    \n#include <iterator>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\nnamespace binary_heap {\n\ntemplate <typename T, auto\
    \ comp>\nclass BinaryHeap {\n    static_assert(std::is_invocable_r<bool, decltype(comp),\
    \ T, T>::value);\n\npublic:\n    using value_type = T;\n    using size_type =\
    \ std::size_t;\n\nprivate:\n    std::vector<value_type> m_tree;  // m_tree[]:=(\u5B8C\
    \u5168\u4E8C\u5206\u6728).\n\n    static constexpr size_type left(size_type k)\
    \ { return k << 1; }\n    static constexpr size_type right(size_type k) { return\
    \ k << 1 | 1; }\n    void shift_up(size_type k) {\n        for(size_type p = k\
    \ >> 1; p >= 1 and comp(m_tree[k - 1], m_tree[p - 1]); p >>= 1) {\n          \
    \  std::swap(m_tree[k - 1], m_tree[p - 1]);\n            k = p;\n        }\n \
    \   }\n    void shift_down(size_type k) {\n        for(size_type l = left(k),\
    \ r = right(k), end = size(); l <= end; l = left(k), r = right(k)) {\n       \
    \     if(r <= end and comp(m_tree[r - 1], m_tree[l - 1])) {\n                if(comp(m_tree[k\
    \ - 1], m_tree[r - 1])) break;\n                std::swap(m_tree[k - 1], m_tree[r\
    \ - 1]);\n                k = r;\n                continue;\n            }\n \
    \           if(comp(m_tree[k - 1], m_tree[l - 1])) break;\n            std::swap(m_tree[k\
    \ - 1], m_tree[l - 1]);\n            k = l;\n        }\n    }\n    void heapify()\
    \ {\n        for(size_type i = size() >> 1; i >= 1; --i) shift_down(i);\n    }\n\
    \npublic:\n    // constructor. O(N).\n    BinaryHeap() : m_tree(0) {}\n    template\
    \ <std::input_iterator InputIter>\n    explicit BinaryHeap(InputIter first, InputIter\
    \ last) : m_tree(first, last) {\n        heapify();\n    }\n    template <typename\
    \ U>\n    explicit BinaryHeap(std::initializer_list<U> il) : BinaryHeap(il.begin(),\
    \ il.end()) {}\n    explicit BinaryHeap(const std::vector<value_type> &v) : m_tree(v)\
    \ {\n        heapify();\n    }\n    explicit BinaryHeap(std::vector<value_type>\
    \ &&v) : m_tree(std::move(v)) {\n        heapify();\n    }\n\n    // \u6BD4\u8F03\
    \u95A2\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto compare()\
    \ { return comp; }\n    // \u8981\u7D20\u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(1).\n    bool empty() const { return m_tree.empty(); }\n    // \u8981\u7D20\
    \u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    size_type size() const {\
    \ return m_tree.size(); }\n    // \u5148\u982D\u8981\u7D20\u306E\u53C2\u7167\uFF0E\
    O(1).\n    value_type top() const {\n        assert(!empty());\n        return\
    \ m_tree.front();\n    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(log N).\n   \
    \ void push(const value_type &a) {\n        m_tree.push_back(a);\n        shift_up(size());\n\
    \    }\n    void push(value_type &&a) {\n        m_tree.push_back(std::move(a));\n\
    \        shift_up(size());\n    }\n    template <typename... Args>\n    void emplace(Args\
    \ &&...args) {\n        m_tree.emplace_back(std::forward<Args>(args)...);\n  \
    \      shift_up(size());\n    }\n    // \u5148\u982D\u8981\u7D20\u306E\u524A\u9664\
    \uFF0EO(log N).\n    value_type pop() {\n        assert(!empty());\n        value_type\
    \ res = m_tree.front();\n        m_tree.front() = m_tree.back();\n        m_tree.pop_back();\n\
    \        if(!empty()) shift_down(1);\n        return res;\n    }\n    void reset()\
    \ { m_tree.clear(); }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const BinaryHeap &rhs) {\n        os << \"[\\n\";\n        for(int l = 1, r\
    \ = 2, end = rhs.size(); l <= end; l <<= 1, r <<= 1) {\n            for(int i\
    \ = l; i < r and i <= end; ++i) os << (i == l ? \"  [\" : \" \") << rhs.m_tree[i\
    \ - 1];\n            os << \"]\\n\";\n        }\n        return os << \"]\";\n\
    \    }\n};\n\nnamespace internal {\n\ntemplate <typename T>\nconstexpr auto less\
    \ = [](const T &lhs, const T &rhs) -> bool { return lhs < rhs; };\n\ntemplate\
    \ <typename T>\nconstexpr auto greater = [](const T &lhs, const T &rhs) -> bool\
    \ { return lhs > rhs; };\n\n}  // namespace internal\n\ntemplate <typename T>\n\
    using min_heap = BinaryHeap<T, internal::greater<T>>;\n\ntemplate <typename T>\n\
    using max_heap = BinaryHeap<T, internal::greater<T>>;\n\n}  // namespace binary_heap\n\
    \n}  // namespace algorithm\n\n\n#line 7 \"verify/aoj-ALDS1_9_C-binary_heap.test.cpp\"\
    \n\nint main() {\n    algorithm::binary_heap::max_heap<int> heap;\n\n    while(true)\
    \ {\n        std::string op;\n        std::cin >> op;\n\n        if(op == \"insert\"\
    ) {\n            int k;\n            std::cin >> k;\n\n            heap.push(k);\n\
    \        } else if(op == \"extract\") {\n            auto &&ans = heap.pop();\n\
    \            std::cout << ans << \"\\n\";\n        } else {\n            break;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/9/ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../algorithm/DataStructure/Others/binary_heap.hpp\"\
    \n\nint main() {\n    algorithm::binary_heap::max_heap<int> heap;\n\n    while(true)\
    \ {\n        std::string op;\n        std::cin >> op;\n\n        if(op == \"insert\"\
    ) {\n            int k;\n            std::cin >> k;\n\n            heap.push(k);\n\
    \        } else if(op == \"extract\") {\n            auto &&ans = heap.pop();\n\
    \            std::cout << ans << \"\\n\";\n        } else {\n            break;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/Others/binary_heap.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_9_C-binary_heap.test.cpp
- /verify/verify/aoj-ALDS1_9_C-binary_heap.test.cpp.html
title: verify/aoj-ALDS1_9_C-binary_heap.test.cpp
---
