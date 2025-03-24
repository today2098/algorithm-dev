---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename\
    \ T>\nclass BIT {\npublic:\n    using value_type = T;\n\nprivate:\n    int m_sz;\
    \  // m_sz:=(\u8981\u7D20\u6570).\n    std::vector<value_type> m_tree;\n\n   \
    \ static constexpr int lsb(int bit) { return bit & -bit; }\n    void build() {\n\
    \        for(int i = 1, end = size(); i < end; ++i) {\n            int j = i +\
    \ lsb(i);\n            if(j <= end) m_tree[j - 1] += m_tree[i - 1];\n        }\n\
    \    }\n\npublic:\n    // constructor. O(N).\n    BIT() : BIT(0) {};\n    explicit\
    \ BIT(int n) : m_sz(n), m_tree(n, value_type()) {\n        assert(n >= 0);\n \
    \   }\n    explicit BIT(int n, const value_type &a) : m_sz(n), m_tree(n, a) {\n\
    \        assert(n >= 0);\n        if(a != value_type()) build();\n    }\n    explicit\
    \ BIT(const std::vector<value_type> &v) : m_sz(v.size()), m_tree(v) {\n      \
    \  build();\n    }\n    explicit BIT(std::vector<value_type> &&v) : m_sz(v.size()),\
    \ m_tree(std::move(v)) {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0E\
    O(logN).\n    void add(int k, const value_type &a) {\n        assert(0 <= k and\
    \ k < size());\n        for(int i = k + 1, end = size(); i <= end; i += lsb(i))\
    \ m_tree[i - 1] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n\
    \        assert(0 <= r and r <= size());\n        T res = value_type();\n    \
    \    for(int i = r; i >= 1; i -= lsb(i)) res += m_tree[i - 1];\n        return\
    \ res;\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const {\n        assert(0\
    \ <= l and l < r and r <= size());\n        return sum(r) - sum(l);\n    }\n \
    \   void reset() { std::fill(m_tree.begin(), m_tree.end(), value_type()); }\n\
    };\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::BIT<int>\
    \ bit(n);\n    while(q--) {\n        int com;\n        std::cin >> com;\n\n  \
    \      if(com == 0) {\n            int x;\n            int y;\n            std::cin\
    \ >> x >> y;\n            --x;\n\n            bit.add(x, y);\n        } else {\n\
    \            int x, y;\n            std::cin >> x >> y;\n            --x;\n\n\
    \            auto &&ans = bit.sum(x, y);\n            std::cout << ans << \"\\\
    n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::BIT<int>\
    \ bit(n);\n    while(q--) {\n        int com;\n        std::cin >> com;\n\n  \
    \      if(com == 0) {\n            int x;\n            int y;\n            std::cin\
    \ >> x >> y;\n            --x;\n\n            bit.add(x, y);\n        } else {\n\
    \            int x, y;\n            std::cin >> x >> y;\n            --x;\n\n\
    \            auto &&ans = bit.sum(x, y);\n            std::cout << ans << \"\\\
    n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
  isVerificationFile: true
  path: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
- /verify/verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp.html
title: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
---
