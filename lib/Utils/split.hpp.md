---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utils/split.md
    document_title: "\u6587\u5B57\u5217\u5206\u5272"
    links: []
  bundledCode: "#line 1 \"lib/Utils/split.hpp\"\n\n\n\n/**\n * @brief \u6587\u5B57\
    \u5217\u5206\u5272\n * @docs docs/Utils/split.md\n */\n\n#include <regex>\n#include\
    \ <sstream>\n#include <string>\n#include <vector>\n\nnamespace algorithm {\n\n\
    // \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\u5217s\u3092\u6307\u5B9A\u306E\
    \u6587\u5B57delim\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split(const std::string &s, char delim, bool disable_empty = false) {\n    std::vector<std::string>\
    \ res;\n    std::istringstream ss(s + delim);\n    std::string item;\n    while(std::getline(ss,\
    \ item, delim)) {\n        if(!(item.empty() and disable_empty)) res.push_back(item);\n\
    \    }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\
    \u5217s\u3092\u6307\u5B9A\u306E\u6587\u5B57\u5217delim\u3067\u5206\u5272\u3059\
    \u308B\uFF0E\nstd::vector<std::string> split(const std::string &s, const std::string\
    \ &delim, bool disable_empty = false) {\n    std::vector<std::string> res;\n \
    \   const size_t length = delim.size();\n    size_t offset = 0;\n    while(true)\
    \ {\n        size_t pos = s.find(delim, offset);\n        if(pos == std::string::npos)\
    \ {\n            std::string &&item = s.substr(offset);\n            if(!(item.empty()\
    \ and disable_empty)) res.push_back(item);\n            break;\n        }\n  \
    \      std::string &&item = s.substr(offset, pos - offset);\n        if(!(item.empty()\
    \ and disable_empty)) res.push_back(item);\n        offset = pos + length;\n \
    \   }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\
    \u5217s\u3092\u6B63\u898F\u8868\u73FEpattern\u306B\u30DE\u30C3\u30C1\u3059\u308B\
    \u6587\u5B57\u5217\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split_regex(const std::string &s, const std::regex &pattern, bool disable_empty\
    \ = false) {\n    std::vector<std::string> res;\n    std::sregex_token_iterator\
    \ itr(s.begin(), s.end(), pattern, -1);\n    std::sregex_token_iterator end;\n\
    \    for(; itr != end; ++itr) {\n        if(!((*itr).str().empty() and disable_empty))\
    \ res.push_back(*itr);\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_SPLIT_HPP\n#define ALGORITHM_SPLIT_HPP 1\n\n/**\n * @brief\
    \ \u6587\u5B57\u5217\u5206\u5272\n * @docs docs/Utils/split.md\n */\n\n#include\
    \ <regex>\n#include <sstream>\n#include <string>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\u5217s\u3092\
    \u6307\u5B9A\u306E\u6587\u5B57delim\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split(const std::string &s, char delim, bool disable_empty = false) {\n    std::vector<std::string>\
    \ res;\n    std::istringstream ss(s + delim);\n    std::string item;\n    while(std::getline(ss,\
    \ item, delim)) {\n        if(!(item.empty() and disable_empty)) res.push_back(item);\n\
    \    }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\
    \u5217s\u3092\u6307\u5B9A\u306E\u6587\u5B57\u5217delim\u3067\u5206\u5272\u3059\
    \u308B\uFF0E\nstd::vector<std::string> split(const std::string &s, const std::string\
    \ &delim, bool disable_empty = false) {\n    std::vector<std::string> res;\n \
    \   const size_t length = delim.size();\n    size_t offset = 0;\n    while(true)\
    \ {\n        size_t pos = s.find(delim, offset);\n        if(pos == std::string::npos)\
    \ {\n            std::string &&item = s.substr(offset);\n            if(!(item.empty()\
    \ and disable_empty)) res.push_back(item);\n            break;\n        }\n  \
    \      std::string &&item = s.substr(offset, pos - offset);\n        if(!(item.empty()\
    \ and disable_empty)) res.push_back(item);\n        offset = pos + length;\n \
    \   }\n    return res;\n}\n\n// \u6587\u5B57\u5217\u5206\u5272\uFF0E\u6587\u5B57\
    \u5217s\u3092\u6B63\u898F\u8868\u73FEpattern\u306B\u30DE\u30C3\u30C1\u3059\u308B\
    \u6587\u5B57\u5217\u3067\u5206\u5272\u3059\u308B\uFF0E\nstd::vector<std::string>\
    \ split_regex(const std::string &s, const std::regex &pattern, bool disable_empty\
    \ = false) {\n    std::vector<std::string> res;\n    std::sregex_token_iterator\
    \ itr(s.begin(), s.end(), pattern, -1);\n    std::sregex_token_iterator end;\n\
    \    for(; itr != end; ++itr) {\n        if(!((*itr).str().empty() and disable_empty))\
    \ res.push_back(*itr);\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/split.hpp
  requiredBy: []
  timestamp: '2024-10-27 23:42:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/split.hpp
layout: document
redirect_from:
- /library/lib/Utils/split.hpp
- /library/lib/Utils/split.hpp.html
title: "\u6587\u5B57\u5217\u5206\u5272"
---
## 概要

Python などにある split 関数とほぼ同じ機能をもつもの．
引数にある文字列を任意の文字または文字列，正規表現にマッチする文字列で分割する．


## 参考文献

1. MaryCore. "C++ std::string 文字列の分割（split）｜区切り文字／文字列に対応". <https://marycore.jp/prog/cpp/std-string-split/>.
1. MaryCore. "C++ 正規表現で文字列の分割（split）【std::regex_token_iterator】". <https://marycore.jp/prog/cpp/std-regex-split-regex-token-iterator/>.
