---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utils/table.md
    document_title: "\u591A\u6B21\u5143\u914D\u5217\u751F\u6210"
    links: []
  bundledCode: "#line 1 \"lib/Utils/table.hpp\"\n\n\n\n/**\n * @brief \u591A\u6B21\
    \u5143\u914D\u5217\u751F\u6210\n * @docs docs/Utils/table.md\n */\n\n#include\
    \ <vector>\n\nnamespace algorithm {\n\ntemplate <typename Type>\nstd::vector<Type>\
    \ table(size_t n, const Type &val) { return std::vector<Type>(n, val); }\n\ntemplate\
    \ <typename... Args>\nauto table(size_t n, const Args &...args) { return std::vector(n,\
    \ table(args...)); }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TABLE_HPP\n#define ALGORITHM_TABLE_HPP 1\n\n/**\n * @brief\
    \ \u591A\u6B21\u5143\u914D\u5217\u751F\u6210\n * @docs docs/Utils/table.md\n */\n\
    \n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename Type>\nstd::vector<Type>\
    \ table(size_t n, const Type &val) { return std::vector<Type>(n, val); }\n\ntemplate\
    \ <typename... Args>\nauto table(size_t n, const Args &...args) { return std::vector(n,\
    \ table(args...)); }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/table.hpp
  requiredBy: []
  timestamp: '2024-09-06 23:55:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/table.hpp
layout: document
redirect_from:
- /library/lib/Utils/table.hpp
- /library/lib/Utils/table.hpp.html
title: "\u591A\u6B21\u5143\u914D\u5217\u751F\u6210"
---
## 概要

`std::vector` による多次元配列を再帰的に生成する．
