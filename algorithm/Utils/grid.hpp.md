---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Utils/grid.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\nnamespace grid {\n\nconstexpr std::pair<int,\
    \ int> dydx4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};\nconstexpr std::pair<int,\
    \ int> dydx8[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0},\
    \ {1, 1}};\n\nauto is_inner = [](int h, int w, int y, int x) -> bool {\n    return\
    \ (0 <= y and y < h and 0 <= x and x < w);\n};\n\n// 2\u6B21\u5143\u914D\u5217\
    \u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\
    \uFF0E\ntemplate <class Sequence>\nstd::vector<Sequence> rotate90(const std::vector<Sequence>\
    \ &vv) {\n    if(vv.empty()) return std::vector<Sequence>();\n    const int h\
    \ = vv.size(), w = vv[0].size();\n    std::vector<Sequence> res(w, Sequence(h,\
    \ 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[w\
    \ - 1 - j][i] = vv[i][j];\n    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\
    \u5217\u3092180\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class Sequence>\n\
    std::vector<Sequence> rotate180(const std::vector<Sequence> &vv) {\n    if(vv.empty())\
    \ return std::vector<Sequence>();\n    const int h = vv.size(), w = vv[0].size();\n\
    \    std::vector<Sequence> res(h, Sequence(w, 0));\n    for(int i = 0; i < h;\
    \ ++i) {\n        for(int j = 0; j < w; ++j) res[h - 1 - i][w - 1 - j] = vv[i][j];\n\
    \    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\u5217\u3092\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B270\u5EA6\uFF08\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\uFF09\u56DE\
    \u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class Sequence>\nstd::vector<Sequence>\
    \ rotate270(const std::vector<Sequence> &vv) {\n    if(vv.empty()) return std::vector<Sequence>();\n\
    \    const int h = vv.size(), w = vv[0].size();\n    std::vector<Sequence> res(w,\
    \ Sequence(h, 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j\
    \ < w; ++j) res[j][h - 1 - i] = vv[i][j];\n    }\n    return res;\n}\n\n}  //\
    \ namespace grid\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GRID_HPP\n#define ALGORITHM_GRID_HPP 1\n\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\nnamespace grid {\n\nconstexpr std::pair<int,\
    \ int> dydx4[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};\nconstexpr std::pair<int,\
    \ int> dydx8[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0},\
    \ {1, 1}};\n\nauto is_inner = [](int h, int w, int y, int x) -> bool {\n    return\
    \ (0 <= y and y < h and 0 <= x and x < w);\n};\n\n// 2\u6B21\u5143\u914D\u5217\
    \u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\
    \uFF0E\ntemplate <class Sequence>\nstd::vector<Sequence> rotate90(const std::vector<Sequence>\
    \ &vv) {\n    if(vv.empty()) return std::vector<Sequence>();\n    const int h\
    \ = vv.size(), w = vv[0].size();\n    std::vector<Sequence> res(w, Sequence(h,\
    \ 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[w\
    \ - 1 - j][i] = vv[i][j];\n    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\
    \u5217\u3092180\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class Sequence>\n\
    std::vector<Sequence> rotate180(const std::vector<Sequence> &vv) {\n    if(vv.empty())\
    \ return std::vector<Sequence>();\n    const int h = vv.size(), w = vv[0].size();\n\
    \    std::vector<Sequence> res(h, Sequence(w, 0));\n    for(int i = 0; i < h;\
    \ ++i) {\n        for(int j = 0; j < w; ++j) res[h - 1 - i][w - 1 - j] = vv[i][j];\n\
    \    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\u5217\u3092\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B270\u5EA6\uFF08\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\uFF09\u56DE\
    \u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class Sequence>\nstd::vector<Sequence>\
    \ rotate270(const std::vector<Sequence> &vv) {\n    if(vv.empty()) return std::vector<Sequence>();\n\
    \    const int h = vv.size(), w = vv[0].size();\n    std::vector<Sequence> res(w,\
    \ Sequence(h, 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j\
    \ < w; ++j) res[j][h - 1 - i] = vv[i][j];\n    }\n    return res;\n}\n\n}  //\
    \ namespace grid\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/grid.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/grid.hpp
layout: document
redirect_from:
- /library/algorithm/Utils/grid.hpp
- /library/algorithm/Utils/grid.hpp.html
title: algorithm/Utils/grid.hpp
---
