---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Others/longest_increasing_subsequence.hpp
    title: "Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\u5206\
      \u5217\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
  bundledCode: "#line 1 \"test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"lib/Others/longest_increasing_subsequence.hpp\"\
    \n\n\n\n/**\n * @brief Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\uFF09\n * @docs docs/Others/longest_increasing_subsequence.md\n\
    \ */\n\n#include <algorithm>\n#include <functional>\n#line 12 \"lib/Others/longest_increasing_subsequence.hpp\"\
    \n\nnamespace algorithm {\n\n// \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS:\
    \ Longest Increasing Subsequence) \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0E\
    O(N*logN).\ntemplate <typename Type, class Compare = std::function<bool(const\
    \ Type &, const Type &)> >\nstd::vector<int> lis(const std::vector<Type> &v, Compare\
    \ comp = [](const Type &a, const Type &b) -> bool { return a < b; }) {\n    const\
    \ int n = v.size();\n    std::vector<int> res(n, 0);  // res[i]:=(v[i]\u3092\u6700\
    \u5F8C\u306E\u8981\u7D20\u3068\u3059\u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\u306E\u9577\u3055).\n    std::vector<Type> dp;        // dp[k]:=(\u9577\
    \u3055k\u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u3046\u3061\uFF0C\u305D\u306E\
    \u6700\u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024).\n    for(int i = 0; i\
    \ < n; ++i) {\n        auto itr = std::lower_bound(dp.begin(), dp.end(), v[i],\
    \ comp);\n        res[i] = itr - dp.begin() + 1;\n        if(itr == dp.end())\
    \ dp.push_back(v[i]);\n        else *itr = v[i];\n    }\n    return res;\n}\n\n\
    // \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing Subsequence)\
    \ \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate <typename\
    \ Type, class Compare = std::function<bool(const Type &, const Type &)> >\nstd::vector<int>\
    \ lis2(const std::vector<Type> &v, Compare comp = [](const Type &a, const Type\
    \ &b) -> bool { return a < b; }) {\n    const int n = v.size();\n    std::vector<int>\
    \ res(n + 1, 0);  // res[i]:=(v[:i]\u306B\u304A\u3051\u308B\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\u306E\u9577\u3055).\n    std::vector<Type> dp;            //\
    \ dp[k]:=(\u9577\u3055k\u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u3046\u3061\uFF0C\
    \u305D\u306E\u6700\u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024).\n    for(int\
    \ i = 0; i < n; ++i) {\n        auto itr = std::lower_bound(dp.begin(), dp.end(),\
    \ v[i], comp);\n        if(itr == dp.end()) dp.push_back(v[i]);\n        else\
    \ *itr = v[i];\n        res[i + 1] = dp.size();\n    }\n    return res;\n}\n\n\
    }  // namespace algorithm\n\n\n#line 7 \"test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> a(n);\n\
    \    for(auto &in : a) std::cin >> in;\n\n    auto ans = algorithm::lis2(a).back();\n\
    \    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../lib/Others/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> a(n);\n\
    \    for(auto &in : a) std::cin >> in;\n\n    auto ans = algorithm::lis2(a).back();\n\
    \    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Others/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2024-09-16 01:47:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
- /verify/test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp.html
title: test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
---