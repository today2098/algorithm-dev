---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp
    title: "\u4E8C\u6B21\u5143BIT (0-based index)"
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
  bundledCode: "#line 1 \"verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2842\"\n\n#include\
    \ <iostream>\n#include <queue>\n#include <tuple>\n\n#line 1 \"lib/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp\"\
    \n\n\n\n/**\n * @brief \u4E8C\u6B21\u5143BIT (0-based index)\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u4E8C\u6B21\u5143BIT (0-based index)\uFF0E\ntemplate <typename\
    \ T>\nclass BIT2D0 {\n    int m_h, m_w;\n    std::vector<std::vector<T> > m_tree;\
    \  // 0-based index.\n\n    void build() {\n        for(int i = 0; i < height();\
    \ ++i) {\n            int ni = i | (i + 1);\n            bool flag = (ni < height());\n\
    \            for(int j = 0; j < width(); ++j) {\n                int nj = j |\
    \ (j + 1);\n                if(nj < width()) {\n                    m_tree[i][nj]\
    \ += m_tree[i][j];\n                    if(flag) m_tree[ni][nj] -= m_tree[i][j];\n\
    \                }\n                if(flag) m_tree[ni][j] += m_tree[i][j];\n\
    \            }\n        }\n    }\n\npublic:\n    // constructor. O(H*W).\n   \
    \ BIT2D0() : BIT2D0(0, 0) {}\n    explicit BIT2D0(size_t h, size_t w, T a = 0)\
    \ : m_h(h), m_w(w), m_tree(h, std::vector<T>(w, a)) {\n        if(a != 0) build();\n\
    \    }\n    explicit BIT2D0(const std::vector<std::vector<T> > &dat) : m_h(dat.size()),\
    \ m_w((dat.empty() ? 0 : dat[0].size())), m_tree(dat) {\n        build();\n  \
    \  }\n\n    int height() const { return m_h; }\n    int width() const { return\
    \ m_w; }\n    // (y,x)\u306B\u3042\u308B\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\u3059\
    \u308B\uFF0EO((logH)*logW).\n    void add(int y, int x, T a) {\n        assert(0\
    \ <= y and y < height());\n        assert(0 <= x and x < width());\n        for(int\
    \ i = y; i < height(); i |= i + 1) {\n            for(int j = x; j < width();\
    \ j |= j + 1) m_tree[i][j] += a;\n        }\n    }\n    // \u533A\u9593[0,y)\u304B\
    \u3064[0,x)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n \
    \   T sum(int y, int x) const {\n        assert(0 <= y and y <= height());\n \
    \       assert(0 <= x and x <= width());\n        T res = 0;\n        for(int\
    \ i = y - 1; i >= 0; i = (i & (i + 1)) - 1) {\n            for(int j = x - 1;\
    \ j >= 0; j = (j & (j + 1)) - 1) res += m_tree[i][j];\n        }\n        return\
    \ res;\n    }\n    // \u533A\u9593[y,yy)\u304B\u3064[x,xx)\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B\uFF0EO((logH)*logW).\n    T sum(int y, int x, int yy, int xx)\
    \ const {\n        assert(0 <= y and y <= yy and yy <= height());\n        assert(0\
    \ <= x and x <= xx and xx <= width());\n        return sum(yy, xx) - sum(yy, x)\
    \ - sum(y, xx) + sum(y, x);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\
    \u3081\u308B\uFF0EO(H*W).\n    void fill(T a = 0) {\n        for(auto &elem :\
    \ m_tree) std::fill(elem.begin(), elem.end(), a);\n        if(a != 0) build();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 8 \"verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp\"\
    \n\nint main() {\n    int y, x;\n    int t;\n    int q;\n    std::cin >> y >>\
    \ x >> t >> q;\n\n    algorithm::BIT2D0<int> raw(y, x), baked(y, x);\n    std::queue<std::tuple<int,\
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
    \ x--;\n\n            auto a = baked.sum(y, x, yy, xx);\n            auto b =\
    \ raw.sum(y, x, yy, xx);\n            std::cout << a << \" \" << b << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2842\"\n\n#include\
    \ <iostream>\n#include <queue>\n#include <tuple>\n\n#include \"../lib/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp\"\
    \n\nint main() {\n    int y, x;\n    int t;\n    int q;\n    std::cin >> y >>\
    \ x >> t >> q;\n\n    algorithm::BIT2D0<int> raw(y, x), baked(y, x);\n    std::queue<std::tuple<int,\
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
    \ x--;\n\n            auto a = baked.sum(y, x, yy, xx);\n            auto b =\
    \ raw.sum(y, x, yy, xx);\n            std::cout << a << \" \" << b << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp
  isVerificationFile: true
  path: verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp
- /verify/verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp.html
title: verify/aoj-2842-binary_indexed_tree_2d_zero.test.cpp
---
