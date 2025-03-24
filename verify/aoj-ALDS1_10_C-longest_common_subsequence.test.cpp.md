---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/String/longest_common_subsequence.hpp
    title: "Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
  bundledCode: "#line 1 \"verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 1 \"lib/String/longest_common_subsequence.hpp\"\
    \n\n\n\n/**\n * @brief Longest Common Subsequence\uFF08\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u5217\uFF09\n * @docs docs/String/longest_common_subsequence.md\n\
    \ */\n\n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n//\
    \ 2\u3064\u306E\u914D\u5217\u306B\u5BFE\u3057\u3066\uFF0C\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u5217 (LCS: Longest Common Subsequence) \u3092\u6C42\u3081\u308B\uFF0E\
    \n// \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\
    \u30CA\u3067\u3042\u308B\u3053\u3068\uFF0EO(|S|*|T|).\ntemplate <class Sequence>\n\
    Sequence lcs(const Sequence &s, const Sequence &t) {\n    const int n = s.size(),\
    \ m = t.size();\n    // dp[i][j]:=(s[:i]\u3068t[:j]\u306ELCS\u306E\u9577\u3055\
    ).\n    std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));\n\
    \    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j) {\n    \
    \        dp[i + 1][j + 1] = (s[i] == t[j] ? dp[i][j] + 1 : std::max(dp[i][j +\
    \ 1], dp[i + 1][j]));\n        }\n    }\n    Sequence sub(dp[n][m], 0);  // sub[]:=(\u914D\
    \u5217s, t\u306ELCS).\n    int i = n - 1, j = m - 1, k = dp[n][m] - 1;\n    while(k\
    \ >= 0) {\n        if(s[i] == t[j]) {\n            sub[k] = s[i];\n          \
    \  i--, j--, k--;\n        } else if(dp[i + 1][j + 1] == dp[i][j + 1]) {\n   \
    \         i--;\n        } else {\n            j--;\n        }\n    }\n    return\
    \ sub;\n}\n\n}  // namespace algorithm\n\n\n#line 7 \"verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    while(q--) {\n       \
    \ std::string x, y;\n        std::cin >> x >> y;\n\n        auto ans = algorithm::lcs(x,\
    \ y).size();\n        std::cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../lib/String/longest_common_subsequence.hpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    while(q--) {\n       \
    \ std::string x, y;\n        std::cin >> x >> y;\n\n        auto ans = algorithm::lcs(x,\
    \ y).size();\n        std::cout << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/String/longest_common_subsequence.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp
- /verify/verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp.html
title: verify/aoj-ALDS1_10_C-longest_common_subsequence.test.cpp
---
