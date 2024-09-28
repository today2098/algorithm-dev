---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utils/convert.md
    document_title: "\u5024\u306E\u5909\u63DB"
    links: []
  bundledCode: "#line 1 \"lib/Utils/convert.hpp\"\n\n\n\n/**\n * @brief \u5024\u306E\
    \u5909\u63DB\n * @docs docs/Utils/convert.md\n */\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\ntemplate <typename Type>\nbool chmin(Type\
    \ &a, const Type &b) {\n    if(a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\n\ntemplate <typename Type>\nbool chmax(Type &a,\
    \ const Type &b) {\n    if(a < b) {\n        a = b;\n        return true;\n  \
    \  }\n    return false;\n}\n\n// 2\u6B21\u5143\u914D\u5217\u3092\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class\
    \ Sequence>\nstd::vector<Sequence> rotate90(const std::vector<Sequence> &vv) {\n\
    \    const int h = vv.size();\n    if(h == 0) return std::vector<Sequence>();\n\
    \    const int w = vv[0].size();\n    std::vector<Sequence> res(w, Sequence(h,\
    \ 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[w\
    \ - 1 - j][i] = vv[i][j];\n    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\
    \u5217\u3092180\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class Sequence>\n\
    std::vector<Sequence> rotate180(const std::vector<Sequence> &vv) {\n    const\
    \ int h = vv.size();\n    if(h == 0) return std::vector<Sequence>();\n    const\
    \ int w = vv[0].size();\n    std::vector<Sequence> res(h, Sequence(w, 0));\n \
    \   for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[h - 1\
    \ - i][w - 1 - j] = vv[i][j];\n    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\
    \u5217\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B270\u5EA6\uFF08\u6642\u8A08\u56DE\
    \u308A\u306B90\u5EA6\uFF09\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class\
    \ Sequence>\nstd::vector<Sequence> rotate270(const std::vector<Sequence> &vv)\
    \ {\n    const int h = vv.size();\n    if(h == 0) return std::vector<Sequence>();\n\
    \    const int w = vv[0].size();\n    std::vector<Sequence> res(w, Sequence(h,\
    \ 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[j][h\
    \ - 1 - i] = vv[i][j];\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_CONVERT_HPP\n#define ALGORITHM_CONVERT_HPP 1\n\n/**\n *\
    \ @brief \u5024\u306E\u5909\u63DB\n * @docs docs/Utils/convert.md\n */\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ Type>\nbool chmin(Type &a, const Type &b) {\n    if(a > b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\n\ntemplate <typename Type>\n\
    bool chmax(Type &a, const Type &b) {\n    if(a < b) {\n        a = b;\n      \
    \  return true;\n    }\n    return false;\n}\n\n// 2\u6B21\u5143\u914D\u5217\u3092\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\
    \ntemplate <class Sequence>\nstd::vector<Sequence> rotate90(const std::vector<Sequence>\
    \ &vv) {\n    const int h = vv.size();\n    if(h == 0) return std::vector<Sequence>();\n\
    \    const int w = vv[0].size();\n    std::vector<Sequence> res(w, Sequence(h,\
    \ 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[w\
    \ - 1 - j][i] = vv[i][j];\n    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\
    \u5217\u3092180\u5EA6\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class Sequence>\n\
    std::vector<Sequence> rotate180(const std::vector<Sequence> &vv) {\n    const\
    \ int h = vv.size();\n    if(h == 0) return std::vector<Sequence>();\n    const\
    \ int w = vv[0].size();\n    std::vector<Sequence> res(h, Sequence(w, 0));\n \
    \   for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[h - 1\
    \ - i][w - 1 - j] = vv[i][j];\n    }\n    return res;\n}\n\n// 2\u6B21\u5143\u914D\
    \u5217\u3092\u53CD\u6642\u8A08\u56DE\u308A\u306B270\u5EA6\uFF08\u6642\u8A08\u56DE\
    \u308A\u306B90\u5EA6\uFF09\u56DE\u8EE2\u3055\u305B\u308B\uFF0E\ntemplate <class\
    \ Sequence>\nstd::vector<Sequence> rotate270(const std::vector<Sequence> &vv)\
    \ {\n    const int h = vv.size();\n    if(h == 0) return std::vector<Sequence>();\n\
    \    const int w = vv[0].size();\n    std::vector<Sequence> res(w, Sequence(h,\
    \ 0));\n    for(int i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) res[j][h\
    \ - 1 - i] = vv[i][j];\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/convert.hpp
  requiredBy: []
  timestamp: '2024-09-20 23:05:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/convert.hpp
layout: document
redirect_from:
- /library/lib/Utils/convert.hpp
- /library/lib/Utils/convert.hpp.html
title: "\u5024\u306E\u5909\u63DB"
---
