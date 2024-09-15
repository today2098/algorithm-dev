---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/String/edit_distance.hpp
    title: "Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E
  bundledCode: "#line 1 \"test/aoj-DPL_1_E-edit_distance.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E\"\n\n#include\
    \ <iostream>\n#include <string>\n\n#line 1 \"lib/String/edit_distance.hpp\"\n\n\
    \n\n/**\n * @brief Edit Distance\uFF08\u7DE8\u96C6\u8DDD\u96E2\uFF09\n * @docs\
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
    \    return dp[n][m];\n}\n\n}  // namespace algorithm\n\n\n#line 7 \"test/aoj-DPL_1_E-edit_distance.test.cpp\"\
    \n\nint main() {\n    std::string s, t;\n    std::cin >> s >> t;\n\n    auto ans\
    \ = algorithm::edit_distance(s, t);\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../lib/String/edit_distance.hpp\"\
    \n\nint main() {\n    std::string s, t;\n    std::cin >> s >> t;\n\n    auto ans\
    \ = algorithm::edit_distance(s, t);\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/String/edit_distance.hpp
  isVerificationFile: true
  path: test/aoj-DPL_1_E-edit_distance.test.cpp
  requiredBy: []
  timestamp: '2024-09-16 02:05:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DPL_1_E-edit_distance.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DPL_1_E-edit_distance.test.cpp
- /verify/test/aoj-DPL_1_E-edit_distance.test.cpp.html
title: test/aoj-DPL_1_E-edit_distance.test.cpp
---
