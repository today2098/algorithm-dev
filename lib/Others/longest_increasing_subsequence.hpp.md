---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
    title: test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-longest_increasing_subsequence-longest_increasing_subsequence.test.cpp
    title: test/yosupo-longest_increasing_subsequence-longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/longest_increasing_subsequence.md
    document_title: "Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Others/longest_increasing_subsequence.hpp\"\n\n\n\n\
    /**\n * @brief Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\uFF09\n * @docs docs/Others/longest_increasing_subsequence.md\n */\n\
    \n#include <algorithm>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing\
    \ Subsequence) \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate\
    \ <typename Type, class Compare = std::function<bool(const Type &, const Type\
    \ &)> >\nstd::vector<int> lis(const std::vector<Type> &v, Compare comp = [](const\
    \ Type &a, const Type &b) -> bool { return a < b; }) {\n    const int n = v.size();\n\
    \    std::vector<int> res(n, 0);  // res[i]:=(v[i]\u3092\u6700\u5F8C\u306E\u8981\
    \u7D20\u3068\u3059\u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\
    \u3055).\n    std::vector<Type> dp;        // dp[k]:=(\u9577\u3055k\u306E\u5897\
    \u52A0\u90E8\u5206\u5217\u306E\u3046\u3061\uFF0C\u305D\u306E\u6700\u5F8C\u306E\
    \u8981\u7D20\u306E\u6700\u5C0F\u5024).\n    for(int i = 0; i < n; ++i) {\n   \
    \     auto itr = std::lower_bound(dp.begin(), dp.end(), v[i], comp);\n       \
    \ res[i] = itr - dp.begin() + 1;\n        if(itr == dp.end()) dp.push_back(v[i]);\n\
    \        else *itr = v[i];\n    }\n    return res;\n}\n\n// \u6700\u9577\u5897\
    \u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing Subsequence) \u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate <typename Type, class Compare\
    \ = std::function<bool(const Type &, const Type &)> >\nstd::vector<int> lis2(const\
    \ std::vector<Type> &v, Compare comp = [](const Type &a, const Type &b) -> bool\
    \ { return a < b; }) {\n    const int n = v.size();\n    std::vector<int> res(n\
    \ + 1, 0);  // res[i]:=(v[:i]\u306B\u304A\u3051\u308B\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\u306E\u9577\u3055).\n    std::vector<Type> dp;            // dp[k]:=(\u9577\
    \u3055k\u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u3046\u3061\uFF0C\u305D\u306E\
    \u6700\u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024).\n    for(int i = 0; i\
    \ < n; ++i) {\n        auto itr = std::lower_bound(dp.begin(), dp.end(), v[i],\
    \ comp);\n        if(itr == dp.end()) dp.push_back(v[i]);\n        else *itr =\
    \ v[i];\n        res[i + 1] = dp.size();\n    }\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP\n#define ALGORITHM_LONGEST_INCREASING_SUBSEQUENCE_HPP\
    \ 1\n\n/**\n * @brief Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\uFF09\n * @docs docs/Others/longest_increasing_subsequence.md\n\
    \ */\n\n#include <algorithm>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing\
    \ Subsequence) \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate\
    \ <typename Type, class Compare = std::function<bool(const Type &, const Type\
    \ &)> >\nstd::vector<int> lis(const std::vector<Type> &v, Compare comp = [](const\
    \ Type &a, const Type &b) -> bool { return a < b; }) {\n    const int n = v.size();\n\
    \    std::vector<int> res(n, 0);  // res[i]:=(v[i]\u3092\u6700\u5F8C\u306E\u8981\
    \u7D20\u3068\u3059\u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\
    \u3055).\n    std::vector<Type> dp;        // dp[k]:=(\u9577\u3055k\u306E\u5897\
    \u52A0\u90E8\u5206\u5217\u306E\u3046\u3061\uFF0C\u305D\u306E\u6700\u5F8C\u306E\
    \u8981\u7D20\u306E\u6700\u5C0F\u5024).\n    for(int i = 0; i < n; ++i) {\n   \
    \     auto itr = std::lower_bound(dp.begin(), dp.end(), v[i], comp);\n       \
    \ res[i] = itr - dp.begin() + 1;\n        if(itr == dp.end()) dp.push_back(v[i]);\n\
    \        else *itr = v[i];\n    }\n    return res;\n}\n\n// \u6700\u9577\u5897\
    \u52A0\u90E8\u5206\u5217 (LIS: Longest Increasing Subsequence) \u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\ntemplate <typename Type, class Compare\
    \ = std::function<bool(const Type &, const Type &)> >\nstd::vector<int> lis2(const\
    \ std::vector<Type> &v, Compare comp = [](const Type &a, const Type &b) -> bool\
    \ { return a < b; }) {\n    const int n = v.size();\n    std::vector<int> res(n\
    \ + 1, 0);  // res[i]:=(v[:i]\u306B\u304A\u3051\u308B\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\u306E\u9577\u3055).\n    std::vector<Type> dp;            // dp[k]:=(\u9577\
    \u3055k\u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u3046\u3061\uFF0C\u305D\u306E\
    \u6700\u5F8C\u306E\u8981\u7D20\u306E\u6700\u5C0F\u5024).\n    for(int i = 0; i\
    \ < n; ++i) {\n        auto itr = std::lower_bound(dp.begin(), dp.end(), v[i],\
    \ comp);\n        if(itr == dp.end()) dp.push_back(v[i]);\n        else *itr =\
    \ v[i];\n        res[i + 1] = dp.size();\n    }\n    return res;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2024-09-16 00:47:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DPL_1_D-longest_increasing_subsequence.test.cpp
  - test/yosupo-longest_increasing_subsequence-longest_increasing_subsequence.test.cpp
documentation_of: lib/Others/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/lib/Others/longest_increasing_subsequence.hpp
- /library/lib/Others/longest_increasing_subsequence.hpp.html
title: "Longest Increasing Subsequence\uFF08\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
  \uFF09"
---
## 概要

長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対して，最長増加部分列 (LIS: Longest Increasing Subsequence) の長さを求める．

アルゴリズムの計算量は $\mathcal{O}(N \log N)$ となる．


## 参考文献

1. 秋葉 拓哉, 岩田 陽一, 北川 宜稔. "2-3 値を覚えて再利用 '動的計画法'". プログラミングコンテストチャレンジブック. 第2版, マイナビ出版, 2012, p.63-65.


## 問題

1. "F - Useless for LIS". AtCoder Beginner Contest 354. AtCoder. <https://atcoder.jp/contests/abc354/tasks/abc354_f>.
