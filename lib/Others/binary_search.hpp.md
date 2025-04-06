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
    links: []
  bundledCode: "#line 1 \"lib/Others/binary_search.hpp\"\n\n\n\n#include <concepts>\n\
    #include <functional>\n#include <type_traits>\n\nnamespace algorithm {\n\ntemplate\
    \ <std::integral Type, class Eval>\nconstexpr Type bisearch(Type ok, Type ng,\
    \ Eval eval) {\n    static_assert(std::is_convertible_v<Eval, std::function<bool(Type)>>);\n\
    \    while(ng - ok > 1) {\n        Type mid = ok + (ng - ok) / 2;\n        (eval(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ng;\n}\n\ntemplate <std::floating_point\
    \ Type, class Eval>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, Eval\
    \ eval) {\n    static_assert(std::is_convertible_v<Eval, std::function<bool(Type)>>);\n\
    \    while(ng - ok > eps) {\n        Type mid = ok + (ng - ok) / 2;\n        (eval(mid)\
    \ ? ok : ng) = mid;\n    }\n    return ng;\n}\n\n}  // namespace algorithm\n\n\
    \n"
  code: "#ifndef ALGORITHM_BINARY_SEARCH_HPP\n#define ALGORITHM_BINARY_SEARCH_HPP\
    \ 1\n\n#include <concepts>\n#include <functional>\n#include <type_traits>\n\n\
    namespace algorithm {\n\ntemplate <std::integral Type, class Eval>\nconstexpr\
    \ Type bisearch(Type ok, Type ng, Eval eval) {\n    static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(Type)>>);\n    while(ng - ok > 1) {\n        Type mid = ok\
    \ + (ng - ok) / 2;\n        (eval(mid) ? ok : ng) = mid;\n    }\n    return ng;\n\
    }\n\ntemplate <std::floating_point Type, class Eval>\nconstexpr Type bisearch(Type\
    \ ok, Type ng, Type eps, Eval eval) {\n    static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(Type)>>);\n    while(ng - ok > eps) {\n        Type mid =\
    \ ok + (ng - ok) / 2;\n        (eval(mid) ? ok : ng) = mid;\n    }\n    return\
    \ ng;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/binary_search.hpp
  requiredBy: []
  timestamp: '2025-03-29 18:57:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_4_B-binary_search.test.cpp
documentation_of: lib/Others/binary_search.hpp
layout: document
title: "Binary Search\uFF08\u4E8C\u5206\u63A2\u7D22\uFF09"
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
