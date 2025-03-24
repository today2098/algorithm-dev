---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_4_B-binary_search.test.cpp
    title: verify/aoj-ALDS1_4_B-binary_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/binary_search.md
    document_title: "\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"lib/Others/binary_search.hpp\"\n\n\n\n/**\n * @brief \u4E8C\
    \u5206\u63A2\u7D22\n * @docs docs/Others/binary_search.md\n */\n\n#include <type_traits>\n\
    \nnamespace algorithm {\n\n// \u4E8C\u5206\u63A2\u7D22\uFF0EO(logN).\ntemplate\
    \ <typename Type, class Func, typename std::enable_if_t<std::is_integral_v<Type>,\
    \ bool> = false>\nconstexpr Type bisearch(Type ok, Type ng, const Func &eval)\
    \ {\n    while(ng - ok > 1) {\n        Type mid = ok + (ng - ok) / 2;\n      \
    \  (eval(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\n// \u4E8C\u5206\u63A2\
    \u7D22\uFF0EO(logN).\ntemplate <typename Type, class Func, typename std::enable_if_t<std::is_floating_point_v<Type>,\
    \ bool> = false>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, const Func\
    \ &eval) {\n    while(ng - ok > eps) {\n        Type mid = ok + (ng - ok) / 2;\n\
    \        (eval(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_SEARCH_HPP\n#define ALGORITHM_BINARY_SEARCH_HPP\
    \ 1\n\n/**\n * @brief \u4E8C\u5206\u63A2\u7D22\n * @docs docs/Others/binary_search.md\n\
    \ */\n\n#include <type_traits>\n\nnamespace algorithm {\n\n// \u4E8C\u5206\u63A2\
    \u7D22\uFF0EO(logN).\ntemplate <typename Type, class Func, typename std::enable_if_t<std::is_integral_v<Type>,\
    \ bool> = false>\nconstexpr Type bisearch(Type ok, Type ng, const Func &eval)\
    \ {\n    while(ng - ok > 1) {\n        Type mid = ok + (ng - ok) / 2;\n      \
    \  (eval(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\n// \u4E8C\u5206\u63A2\
    \u7D22\uFF0EO(logN).\ntemplate <typename Type, class Func, typename std::enable_if_t<std::is_floating_point_v<Type>,\
    \ bool> = false>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, const Func\
    \ &eval) {\n    while(ng - ok > eps) {\n        Type mid = ok + (ng - ok) / 2;\n\
    \        (eval(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/binary_search.hpp
  requiredBy: []
  timestamp: '2024-09-29 17:03:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_4_B-binary_search.test.cpp
documentation_of: lib/Others/binary_search.hpp
layout: document
redirect_from:
- /library/lib/Others/binary_search.hpp
- /library/lib/Others/binary_search.hpp.html
title: "\u4E8C\u5206\u63A2\u7D22"
---
## 概要

$\forall x \in \mathbb{Z}, f(x) \rightarrow f(x+1)$ 及び $\exists x \in \mathbb{Z}, f(x)$ を満たす1変数述語 $f(x)$ に対し，$\min{\lbrace x \in \mathbb{Z} \mid f(x) \rbrace}$ を求めるアルゴリズム．


## 参考文献

1. "二分探索". Wikipedia. <https://ja.wikipedia.org/wiki/二分探索>.
1. "二分法". Wikipedia. <https://ja.wikipedia.org/wiki/二分法>.
1. rsk0315. "抽象化ライブラリの第一歩としての二分探索". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2024/08/04/185219>.
1. "二分探索 二分法 違い". うさぎ小屋. <https://kmyk.github.io/blog/blog/2020/11/07/binary-search-and-bisection-method/>.


## 問題

- "C - Transportation Expenses". AtCoder Beginner Contest 365. AtCoder. <https://atcoder.jp/contests/abc365/tasks/abc365_c>.
