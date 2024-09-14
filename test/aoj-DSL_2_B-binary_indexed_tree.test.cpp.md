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
  bundledCode: "#line 1 \"test/aoj-DSL_2_B-binary_indexed_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\n\n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename T>\nclass BIT {\n\
    \    int m_sz;               // m_sz:=(\u914D\u5217\u306E\u8981\u7D20\u6570).\n\
    \    std::vector<T> m_tree;  // 1-based index.\n\n    void build() {\n       \
    \ for(int i = 1; i < size(); ++i) {\n            int j = i + (i & -i);\n     \
    \       if(j <= size()) m_tree[j] += m_tree[i];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT() : BIT(0) {};\n    explicit BIT(size_t n,\
    \ T a = 0) : m_sz(n), m_tree(n + 1, a) {\n        if(a != 0) build();\n    }\n\
    \    explicit BIT(const std::vector<T> &v) : m_sz(v.size()), m_tree(v.size() +\
    \ 1) {\n        std::copy(v.begin(), v.end(), m_tree.begin() + 1);\n        build();\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\
    \u3059\u308B\uFF0EO(logN).\n    void add(int k, T a) {\n        assert(1 <= k\
    \ and k <= size());\n        for(; k <= size(); k += k & -k) m_tree[k] += a;\n\
    \    }\n    // \u533A\u9593[1,r]\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0 <= r and\
    \ r <= size());\n        T res = 0;\n        for(; r > 0; r -= r & -r) res +=\
    \ m_tree[r];\n        return res;\n    }\n    // \u533A\u9593[l,r]\u306E\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int\
    \ l, int r) const {\n        assert(1 <= l and l <= r and r <= size());\n    \
    \    return sum(r) - sum(l - 1);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\
    \u57CB\u3081\u308B\uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin()\
    \ + 1, m_tree.end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"test/aoj-DSL_2_B-binary_indexed_tree.test.cpp\"\n\n\
    int main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::BIT<int>\
    \ bit(n);\n    while(q--) {\n        int com;\n        std::cin >> com;\n\n  \
    \      if(com == 0) {\n            int x;\n            int y;\n            std::cin\
    \ >> x >> y;\n\n            bit.add(x, y);\n        } else {\n            int\
    \ x, y;\n            std::cin >> x >> y;\n\n            auto &&ans = bit.sum(x,\
    \ y);\n            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::BIT<int>\
    \ bit(n);\n    while(q--) {\n        int com;\n        std::cin >> com;\n\n  \
    \      if(com == 0) {\n            int x;\n            int y;\n            std::cin\
    \ >> x >> y;\n\n            bit.add(x, y);\n        } else {\n            int\
    \ x, y;\n            std::cin >> x >> y;\n\n            auto &&ans = bit.sum(x,\
    \ y);\n            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
  isVerificationFile: true
  path: test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '2024-09-12 00:41:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
- /verify/test/aoj-DSL_2_B-binary_indexed_tree.test.cpp.html
title: test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
---
