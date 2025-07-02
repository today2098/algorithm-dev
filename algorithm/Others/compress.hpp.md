---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_4_A-imos_2d.test.cpp
    title: verify/aoj-DSL_4_A-imos_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Others/compress.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u5EA7\u6A19\u5727\u7E2E\uFF0E\
    O(N log N).\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    std::vector<Type> key(v);\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    key.shrink_to_fit();\n\
    \    for(auto &elem : v) elem = std::lower_bound(key.cbegin(), key.cend(), elem)\
    \ - key.cbegin();\n    return key;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_COMPRESS_HPP\n#define ALGORITHM_COMPRESS_HPP 1\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n// \u5EA7\u6A19\u5727\
    \u7E2E\uFF0EO(N log N).\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    std::vector<Type> key(v);\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    key.shrink_to_fit();\n\
    \    for(auto &elem : v) elem = std::lower_bound(key.cbegin(), key.cend(), elem)\
    \ - key.cbegin();\n    return key;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Others/compress.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_4_A-imos_2d.test.cpp
documentation_of: algorithm/Others/compress.hpp
layout: document
redirect_from:
- /library/algorithm/Others/compress.hpp
- /library/algorithm/Others/compress.hpp.html
title: algorithm/Others/compress.hpp
---
