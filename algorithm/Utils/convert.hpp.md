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
  bundledCode: "#line 1 \"algorithm/Utils/convert.hpp\"\n\n\n\nnamespace algorithm\
    \ {\n\ntemplate <typename Type>\nbool chmin(Type &a, const Type &b) {\n    if(a\
    \ <= b) return false;\n    a = b;\n    return true;\n}\n\ntemplate <typename Type>\n\
    bool chmax(Type &a, const Type &b) {\n    if(a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_CONVERT_HPP\n#define ALGORITHM_CONVERT_HPP 1\n\nnamespace\
    \ algorithm {\n\ntemplate <typename Type>\nbool chmin(Type &a, const Type &b)\
    \ {\n    if(a <= b) return false;\n    a = b;\n    return true;\n}\n\ntemplate\
    \ <typename Type>\nbool chmax(Type &a, const Type &b) {\n    if(a >= b) return\
    \ false;\n    a = b;\n    return true;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/convert.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/convert.hpp
layout: document
redirect_from:
- /library/algorithm/Utils/convert.hpp
- /library/algorithm/Utils/convert.hpp.html
title: algorithm/Utils/convert.hpp
---
