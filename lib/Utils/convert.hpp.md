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
  bundledCode: "#line 1 \"lib/Utils/convert.hpp\"\n\n\n\nnamespace algorithm {\n\n\
    template <typename Type>\nbool chmin(Type &a, const Type &b) {\n    if(a <= b)\
    \ return false;\n    a = b;\n    return true;\n}\n\ntemplate <typename Type>\n\
    bool chmax(Type &a, const Type &b) {\n    if(a >= b) return false;\n    a = b;\n\
    \    return true;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_CONVERT_HPP\n#define ALGORITHM_CONVERT_HPP 1\n\nnamespace\
    \ algorithm {\n\ntemplate <typename Type>\nbool chmin(Type &a, const Type &b)\
    \ {\n    if(a <= b) return false;\n    a = b;\n    return true;\n}\n\ntemplate\
    \ <typename Type>\nbool chmax(Type &a, const Type &b) {\n    if(a >= b) return\
    \ false;\n    a = b;\n    return true;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/convert.hpp
  requiredBy: []
  timestamp: '2025-03-23 15:30:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/convert.hpp
layout: document
title: "\u5024\u306E\u5909\u63DB\u3092\u884C\u3046\u30E6\u30FC\u30C6\u30A3\u30EA\u30C6\
  \u30A3\u30E9\u30A4\u30D6\u30E9\u30EA"
---
