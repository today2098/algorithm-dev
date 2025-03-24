---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
    title: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u4E8C\u6B21\u5143BIT\uFF0E\ntemplate <typename T>\nclass\
    \ BIT2D {\npublic:\n    using value_type = T;\n\nprivate:\n    int m_h, m_w;\n\
    \    std::vector<std::vector<value_type>> m_tree;\n\n    static constexpr int\
    \ lsb(int bit) { return bit & -bit; }\n    void build() {\n        for(int i =\
    \ 1, h = height(); i <= h; ++i) {\n            int ni = i + lsb(i);\n        \
    \    for(int j = 1, w = width(); j <= w; ++j) {\n                int nj = j +\
    \ lsb(j);\n                if(ni <= h) m_tree[ni - 1][j - 1] += m_tree[i - 1][j\
    \ - 1];\n                if(nj <= w) {\n                    m_tree[i - 1][nj -\
    \ 1] += m_tree[i - 1][j - 1];\n                    if(ni <= h) m_tree[ni - 1][nj\
    \ - 1] -= m_tree[i - 1][j - 1];\n                }\n            }\n        }\n\
    \    }\n\npublic:\n    // constructor. O(H*W).\n    BIT2D() : BIT2D(0, 0) {}\n\
    \    explicit BIT2D(int h, int w) : BIT2D(h, w, value_type()) {}\n    explicit\
    \ BIT2D(int h, int w, const value_type &a) : m_h(h), m_w(w), m_tree(h, std::vector<value_type>(w,\
    \ a)) {\n        assert(h >= 0 and w >= 0);\n        if(a != value_type()) build();\n\
    \    }\n\n    int height() const { return m_h; }\n    int width() const { return\
    \ m_w; }\n    // (y,x)\u306B\u3042\u308B\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\
    \u308B\uFF0EO((logH)*logW).\n    void add(int y, int x, const value_type &a) {\n\
    \        assert(0 <= y and y < height());\n        assert(0 <= x and x < width());\n\
    \        for(int i = y + 1, h = height(); i <= h; i += lsb(i)) {\n           \
    \ for(int j = x + 1, w = width(); j <= w; j += lsb(j)) m_tree[i - 1][j - 1] +=\
    \ a;\n        }\n    }\n    // [0,y)\u304B\u3064[0,x)\u306E\u7BC4\u56F2\u306B\u3042\
    \u308B\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n\
    \    value_type sum(int y, int x) const {\n        assert(0 <= y and y <= height());\n\
    \        assert(0 <= x and x <= width());\n        value_type res = 0;\n     \
    \   for(int i = y; i >= 1; i -= lsb(i)) {\n            for(int j = x; j >= 1;\
    \ j -= lsb(j)) res += m_tree[i - 1][j - 1];\n        }\n        return res;\n\
    \    }\n    // [y,yy)\u304B\u3064[x,xx)\u306E\u7BC4\u56F2\u306B\u3042\u308B\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n    value_type\
    \ sum(int y, int x, int yy, int xx) const {\n        assert(0 <= y and y <= yy\
    \ and yy <= height());\n        assert(0 <= x and x <= xx and xx <= width());\n\
    \        return sum(yy, xx) - sum(yy, x) - sum(y, xx) + sum(y, x);\n    }\n  \
    \  void reset() {\n        for(auto &v : m_tree) std::fill(v.begin(), v.end(),\
    \ value_type());\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_2D_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u4E8C\u6B21\u5143BIT\uFF0E\ntemplate <typename T>\nclass\
    \ BIT2D {\npublic:\n    using value_type = T;\n\nprivate:\n    int m_h, m_w;\n\
    \    std::vector<std::vector<value_type>> m_tree;\n\n    static constexpr int\
    \ lsb(int bit) { return bit & -bit; }\n    void build() {\n        for(int i =\
    \ 1, h = height(); i <= h; ++i) {\n            int ni = i + lsb(i);\n        \
    \    for(int j = 1, w = width(); j <= w; ++j) {\n                int nj = j +\
    \ lsb(j);\n                if(ni <= h) m_tree[ni - 1][j - 1] += m_tree[i - 1][j\
    \ - 1];\n                if(nj <= w) {\n                    m_tree[i - 1][nj -\
    \ 1] += m_tree[i - 1][j - 1];\n                    if(ni <= h) m_tree[ni - 1][nj\
    \ - 1] -= m_tree[i - 1][j - 1];\n                }\n            }\n        }\n\
    \    }\n\npublic:\n    // constructor. O(H*W).\n    BIT2D() : BIT2D(0, 0) {}\n\
    \    explicit BIT2D(int h, int w) : BIT2D(h, w, value_type()) {}\n    explicit\
    \ BIT2D(int h, int w, const value_type &a) : m_h(h), m_w(w), m_tree(h, std::vector<value_type>(w,\
    \ a)) {\n        assert(h >= 0 and w >= 0);\n        if(a != value_type()) build();\n\
    \    }\n\n    int height() const { return m_h; }\n    int width() const { return\
    \ m_w; }\n    // (y,x)\u306B\u3042\u308B\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\
    \u308B\uFF0EO((logH)*logW).\n    void add(int y, int x, const value_type &a) {\n\
    \        assert(0 <= y and y < height());\n        assert(0 <= x and x < width());\n\
    \        for(int i = y + 1, h = height(); i <= h; i += lsb(i)) {\n           \
    \ for(int j = x + 1, w = width(); j <= w; j += lsb(j)) m_tree[i - 1][j - 1] +=\
    \ a;\n        }\n    }\n    // [0,y)\u304B\u3064[0,x)\u306E\u7BC4\u56F2\u306B\u3042\
    \u308B\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n\
    \    value_type sum(int y, int x) const {\n        assert(0 <= y and y <= height());\n\
    \        assert(0 <= x and x <= width());\n        value_type res = 0;\n     \
    \   for(int i = y; i >= 1; i -= lsb(i)) {\n            for(int j = x; j >= 1;\
    \ j -= lsb(j)) res += m_tree[i - 1][j - 1];\n        }\n        return res;\n\
    \    }\n    // [y,yy)\u304B\u3064[x,xx)\u306E\u7BC4\u56F2\u306B\u3042\u308B\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n    value_type\
    \ sum(int y, int x, int yy, int xx) const {\n        assert(0 <= y and y <= yy\
    \ and yy <= height());\n        assert(0 <= x and x <= xx and xx <= width());\n\
    \        return sum(yy, xx) - sum(yy, x) - sum(y, xx) + sum(y, x);\n    }\n  \
    \  void reset() {\n        for(auto &v : m_tree) std::fill(v.begin(), v.end(),\
    \ value_type());\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
  requiredBy: []
  timestamp: '2025-03-24 23:59:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-2842-binary_indexed_tree_2d.test.cpp
documentation_of: lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
layout: document
title: "\u4E8C\u6B21\u5143BIT"
---


## 概要

Binary Indexed Tree (BIT) を二次元に拡張したもの．
