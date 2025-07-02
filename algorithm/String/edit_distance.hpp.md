---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DPL_1_E-edit_distance.test.cpp
    title: verify/aoj-DPL_1_E-edit_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/String/edit_distance.md
    document_title: "Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09"
    links: []
  bundledCode: "#line 1 \"algorithm/String/edit_distance.hpp\"\n\n\n\n/**\n * @brief\
    \ Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09\n * @docs docs/String/edit_distance.md\n\
    \ */\n\n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n//\
    \ 2\u3064\u306E\u914D\u5217\u306B\u5BFE\u3057\u3066\uFF0C\u7DE8\u96C6\u8DDD\u96E2\
    \ (Edit Distance) \u3092\u6C42\u3081\u308B\uFF0E\n// \u5F15\u6570\u306FSTL\u306E\
    \u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\u3067\u3042\u308B\u3053\
    \u3068\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\nint edit_distance(const Sequence\
    \ &s, const Sequence &t) {\n    const int n = s.size(), m = t.size();\n    //\
    \ dp[i][j]:=(s[:i]\u3068t[:j]\u306E\u7DE8\u96C6\u8DDD\u96E2).\n    std::vector<std::vector<int>\
    \ > dp(n + 1, std::vector<int>(m + 1, 0));\n    for(int i = 1; i <= n; ++i) dp[i][0]\
    \ = i;\n    for(int j = 1; j <= m; ++j) dp[0][j] = j;\n    for(int i = 0; i <\
    \ n; ++i) {\n        for(int j = 0; j < m; ++j) {\n            dp[i + 1][j + 1]\
    \ = std::min({dp[i][j + 1] + 1,\n                                         dp[i\
    \ + 1][j] + 1,\n                                         dp[i][j] + (s[i] == t[j]\
    \ ? 0 : 1)});\n        }\n    }\n    return dp[n][m];\n}\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_EDIT_DISTANCE_HPP\n#define ALGORITHM_EDIT_DISTANCE_HPP\
    \ 1\n\n/**\n * @brief Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09\n * @docs\
    \ docs/String/edit_distance.md\n */\n\n#include <algorithm>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// 2\u3064\u306E\u914D\u5217\u306B\u5BFE\u3057\u3066\
    \uFF0C\u7DE8\u96C6\u8DDD\u96E2 (Edit Distance) \u3092\u6C42\u3081\u308B\uFF0E\n\
    // \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\
    \u30CA\u3067\u3042\u308B\u3053\u3068\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\n\
    int edit_distance(const Sequence &s, const Sequence &t) {\n    const int n = s.size(),\
    \ m = t.size();\n    // dp[i][j]:=(s[:i]\u3068t[:j]\u306E\u7DE8\u96C6\u8DDD\u96E2\
    ).\n    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));\n\
    \    for(int i = 1; i <= n; ++i) dp[i][0] = i;\n    for(int j = 1; j <= m; ++j)\
    \ dp[0][j] = j;\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j <\
    \ m; ++j) {\n            dp[i + 1][j + 1] = std::min({dp[i][j + 1] + 1,\n    \
    \                                     dp[i + 1][j] + 1,\n                    \
    \                     dp[i][j] + (s[i] == t[j] ? 0 : 1)});\n        }\n    }\n\
    \    return dp[n][m];\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/String/edit_distance.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DPL_1_E-edit_distance.test.cpp
documentation_of: algorithm/String/edit_distance.hpp
layout: document
redirect_from:
- /library/algorithm/String/edit_distance.hpp
- /library/algorithm/String/edit_distance.hpp.html
title: "Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09"
---
## 概要

2つの配列 $S, T$ に対して，編集距離（レーベンシュタイン距離）を求める．
編集距離とは，1文字の挿入・削除・置換によって，一方の文字列をもう一方の文字列に変換するのに必要な操作の最小回数のことをいう．

アルゴリズムの計算量は $\mathcal{O}(\lvert S \rvert \lvert T \rvert)$ ．


## 参考文献

1. "レーベンシュタイン距離". Wikipedia. <https://ja.wikipedia.org/wiki/レーベンシュタイン距離>.
