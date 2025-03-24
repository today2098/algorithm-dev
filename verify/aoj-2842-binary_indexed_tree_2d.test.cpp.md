---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
    title: "\u4E8C\u6B21\u5143BIT"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2842
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2842
  bundledCode: "#line 1 \"verify/aoj-2842-binary_indexed_tree_2d.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2842\"\n\n#include <iostream>\n\
    #include <queue>\n#include <tuple>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp\"\
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
    \ value_type());\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 8 \"verify/aoj-2842-binary_indexed_tree_2d.test.cpp\"\
    \n\nint main() {\n    int y, x;\n    int t;\n    int q;\n    std::cin >> y >>\
    \ x >> t >> q;\n\n    algorithm::BIT2D<int> raw(y, x), baked(y, x);\n    std::queue<std::tuple<int,\
    \ int, int> > que;\n    while(q--) {\n        int time;\n        int c;\n    \
    \    std::cin >> time >> c;\n\n        while(!que.empty()) {\n            auto\
    \ [end, y, x] = que.front();\n            if(time < end) break;\n            que.pop();\n\
    \n            raw.add(y, x, -1);\n            baked.add(y, x, 1);\n        }\n\
    \n        if(c == 0) {\n            int y, x;\n            std::cin >> y >> x;\n\
    \            y--, x--;\n\n            raw.add(y, x, 1);\n            que.emplace(time\
    \ + t, y, x);\n        } else if(c == 1) {\n            int y, x;\n          \
    \  std::cin >> y >> x;\n            y--, x--;\n\n            if(baked.sum(y, x,\
    \ y + 1, x + 1) >= 1) baked.add(y, x, -1);\n        } else {\n            int\
    \ y, x, yy, xx;\n            std::cin >> y >> x >> yy >> xx;\n            y--,\
    \ x--;\n\n            auto &&a = baked.sum(y, x, yy, xx);\n            auto &&b\
    \ = raw.sum(y, x, yy, xx);\n            std::cout << a << \" \" << b << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2842\"\n\n#include\
    \ <iostream>\n#include <queue>\n#include <tuple>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp\"\
    \n\nint main() {\n    int y, x;\n    int t;\n    int q;\n    std::cin >> y >>\
    \ x >> t >> q;\n\n    algorithm::BIT2D<int> raw(y, x), baked(y, x);\n    std::queue<std::tuple<int,\
    \ int, int> > que;\n    while(q--) {\n        int time;\n        int c;\n    \
    \    std::cin >> time >> c;\n\n        while(!que.empty()) {\n            auto\
    \ [end, y, x] = que.front();\n            if(time < end) break;\n            que.pop();\n\
    \n            raw.add(y, x, -1);\n            baked.add(y, x, 1);\n        }\n\
    \n        if(c == 0) {\n            int y, x;\n            std::cin >> y >> x;\n\
    \            y--, x--;\n\n            raw.add(y, x, 1);\n            que.emplace(time\
    \ + t, y, x);\n        } else if(c == 1) {\n            int y, x;\n          \
    \  std::cin >> y >> x;\n            y--, x--;\n\n            if(baked.sum(y, x,\
    \ y + 1, x + 1) >= 1) baked.add(y, x, -1);\n        } else {\n            int\
    \ y, x, yy, xx;\n            std::cin >> y >> x >> yy >> xx;\n            y--,\
    \ x--;\n\n            auto &&a = baked.sum(y, x, yy, xx);\n            auto &&b\
    \ = raw.sum(y, x, yy, xx);\n            std::cout << a << \" \" << b << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
  isVerificationFile: true
  path: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 23:59:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-2842-binary_indexed_tree_2d.test.cpp
- /verify/verify/aoj-2842-binary_indexed_tree_2d.test.cpp.html
title: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
---
