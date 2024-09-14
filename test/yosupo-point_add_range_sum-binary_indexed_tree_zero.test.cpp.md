---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
    title: Binary Indexed Tree (0-based index)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n\n\n\n/**\n * @brief Binary Indexed Tree (0-based index)\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree_zero.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#line 12 \"lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n\nnamespace algorithm {\n\n// Binary Indexed Tree (0-based index).\ntemplate\
    \ <typename T>\nclass BIT0 {\n    int m_sz;               // m_sz:=(\u914D\u5217\
    \u306E\u8981\u7D20\u6570).\n    std::vector<T> m_tree;  // 0-based index.\n\n\
    \    void build() {\n        for(int i = 0; i < size() - 1; ++i) {\n         \
    \   int j = i | (i + 1);\n            if(j < size()) m_tree[j] += m_tree[i];\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT0() : BIT0(0)\
    \ {};\n    explicit BIT0(size_t n, T a = 0) : m_sz(n), m_tree(n, a) {\n      \
    \  if(a != 0) build();\n    }\n    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()),\
    \ m_tree(v) {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0E\n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\
    \u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0EO(logN).\n    void add(int\
    \ k, T a) {\n        assert(0 <= k and k < size());\n        for(; k < size();\
    \ k |= k + 1) m_tree[k] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const\
    \ {\n        assert(0 <= r and r <= size());\n        T res = 0;\n        for(r\
    \ = r - 1; r >= 0; r = (r & (r + 1)) - 1) res += m_tree[r];\n        return res;\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const {\n        assert(0\
    \ <= l and l <= r and r <= size());\n        return sum(r) - sum(l);\n    }\n\
    \    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\uFF0EO(N).\n    void\
    \ fill(T a = 0) {\n        std::fill(m_tree.begin(), m_tree.end(), a);\n     \
    \   if(a != 0) build();\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 7 \"\
    test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<long long>\
    \ a(n);\n    for(auto &in : a) std::cin >> in;\n\n    algorithm::BIT0 bit(a);\n\
    \    while(q--) {\n        int t;\n        std::cin >> t;\n\n        if(t == 0)\
    \ {\n            int p;\n            long long x;\n            std::cin >> p >>\
    \ x;\n\n            bit.add(p, x);\n        } else {\n            int l, r;\n\
    \            std::cin >> l >> r;\n\n            auto &&ans = bit.sum(l, r);\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<long\
    \ long> a(n);\n    for(auto &in : a) std::cin >> in;\n\n    algorithm::BIT0 bit(a);\n\
    \    while(q--) {\n        int t;\n        std::cin >> t;\n\n        if(t == 0)\
    \ {\n            int p;\n            long long x;\n            std::cin >> p >>\
    \ x;\n\n            bit.add(p, x);\n        } else {\n            int l, r;\n\
    \            std::cin >> l >> r;\n\n            auto &&ans = bit.sum(l, r);\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
  isVerificationFile: true
  path: test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
  requiredBy: []
  timestamp: '2024-09-12 00:41:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
- /verify/test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp.html
title: test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
---
