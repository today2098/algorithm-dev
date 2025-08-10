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
  bundledCode: "#line 1 \"algorithm/Utils/split.hpp\"\n\n\n\n#include <ranges>\n#include\
    \ <sstream>\n#include <string>\n#include <string_view>\n#include <vector>\n\n\
    namespace algorithm {\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\u5217\
    s\u3092\u6587\u5B57delim\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split(std::string_view sv, char delim, bool disable_empty = false) {\n    std::vector<std::string>\
    \ res;\n    std::stringstream ss;\n    ss << sv << delim;\n    std::string item;\n\
    \    while(std::getline(ss, item, delim)) {\n        if(!(disable_empty and item.empty()))\
    \ res.push_back(item);\n    }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\
    \u5272\uFF0E\u6587\u5B57\u5217s\u3092\u6587\u5B57\u5217delim\u3067\u5206\u5272\
    \u3059\u308B\uFF0E\nstd::vector<std::string> split(std::string_view sv, std::string_view\
    \ delim, bool disable_empty = false) {\n    std::vector<std::string> res;\n  \
    \  for(auto item : sv | std::ranges::views::split(delim)) {\n        if(!(disable_empty\
    \ and item.empty())) res.emplace_back(item.begin(), item.end());\n    }\n    return\
    \ res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SPLIT_HPP\n#define ALGORITHM_SPLIT_HPP 1\n\n#include <ranges>\n\
    #include <sstream>\n#include <string>\n#include <string_view>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\
    \u5217s\u3092\u6587\u5B57delim\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split(std::string_view sv, char delim, bool disable_empty = false) {\n    std::vector<std::string>\
    \ res;\n    std::stringstream ss;\n    ss << sv << delim;\n    std::string item;\n\
    \    while(std::getline(ss, item, delim)) {\n        if(!(disable_empty and item.empty()))\
    \ res.push_back(item);\n    }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\
    \u5272\uFF0E\u6587\u5B57\u5217s\u3092\u6587\u5B57\u5217delim\u3067\u5206\u5272\
    \u3059\u308B\uFF0E\nstd::vector<std::string> split(std::string_view sv, std::string_view\
    \ delim, bool disable_empty = false) {\n    std::vector<std::string> res;\n  \
    \  for(auto item : sv | std::ranges::views::split(delim)) {\n        if(!(disable_empty\
    \ and item.empty())) res.emplace_back(item.begin(), item.end());\n    }\n    return\
    \ res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/split.hpp
  requiredBy: []
  timestamp: '2025-07-26 16:38:59+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/split.hpp
layout: document
title: "\u6587\u5B57\u5217\u5206\u5272"
---


## 概要

与えられた文字列を任意の文字または文字列で分割する．


## 参考

1. "std::ranges::split_view". cpprefjp - C++日本語リファレンス. <https://cpprefjp.github.io/reference/ranges/split_view.html>.
1. MaryCore. "C++ std::string 文字列の分割（split）｜区切り文字／文字列に対応". <https://marycore.jp/prog/cpp/std-string-split/>.
1. MaryCore. "C++ 正規表現で文字列の分割（split）【std::regex_token_iterator】". <https://marycore.jp/prog/cpp/std-regex-split-regex-token-iterator/>.
