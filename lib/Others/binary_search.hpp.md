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
  bundledCode: "#line 1 \"lib/Others/binary_search.hpp\"\n\n\n\n#include <cassert>\n\
    #include <concepts>\n#include <numeric>\n#include <type_traits>\n\nnamespace algorithm\
    \ {\n\ntemplate <std::integral Type, class Pred>\nconstexpr Type bisearch(Type\
    \ ok, Type ng, Pred pred) {\n    static_assert(std::is_invocable_r<bool, Pred,\
    \ Type>::value);\n    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n    while(ng\
    \ - ok > 1) {\n        Type mid = std::midpoint(ok, ng);\n        (pred(mid) ?\
    \ ok : ng) = mid;\n    }\n    return ng;\n}\n\ntemplate <std::floating_point Type,\
    \ class Pred>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, Pred pred)\
    \ {\n    static_assert(std::is_invocable_r<bool, Pred, Type>::value);\n    assert(ok\
    \ <= ng);\n    if(!pred(ok)) return ok;\n    while(ng - ok > eps) {\n        Type\
    \ mid = std::midpoint(ok, ng);\n        (pred(mid) ? ok : ng) = mid;\n    }\n\
    \    return ng;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_SEARCH_HPP\n#define ALGORITHM_BINARY_SEARCH_HPP\
    \ 1\n\n#include <cassert>\n#include <concepts>\n#include <numeric>\n#include <type_traits>\n\
    \nnamespace algorithm {\n\ntemplate <std::integral Type, class Pred>\nconstexpr\
    \ Type bisearch(Type ok, Type ng, Pred pred) {\n    static_assert(std::is_invocable_r<bool,\
    \ Pred, Type>::value);\n    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n\
    \    while(ng - ok > 1) {\n        Type mid = std::midpoint(ok, ng);\n       \
    \ (pred(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\ntemplate <std::floating_point\
    \ Type, class Pred>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, Pred\
    \ pred) {\n    static_assert(std::is_invocable_r<bool, Pred, Type>::value);\n\
    \    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n    while(ng - ok > eps)\
    \ {\n        Type mid = std::midpoint(ok, ng);\n        (pred(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ng;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/binary_search.hpp
  requiredBy: []
  timestamp: '2025-06-24 00:52:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_4_B-binary_search.test.cpp
documentation_of: lib/Others/binary_search.hpp
layout: document
title: "Binary Search\uFF08\u4E8C\u5206\u63A2\u7D22\uFF09"
---


## 概要

$\forall x \in \mathbb{Z}, \neg P(x) \rightarrow \neg P(x+1)$ および $\exists x \in \mathbb{Z}, \neg P(x)$ を満たす1項述語 $P(x)$ に対し，$\min{\lbrace x \in \mathbb{Z} \mid \neg P(x) \rbrace}$ を求めるアルゴリズム．

「探索範囲の中央値 $x$ に対して $P(x)$ を評価して，探索範囲を半減させる」といった手続きを繰り返し，解を求める．

計算量は，探索範囲の初期幅を $N$ とすると，$\mathcal{O}(\log N)$ となる．

```cpp
std::vector<int> v({3, 1, 4, 6, 5});

auto itr = algorithm::bisearch<int>(0, v.size(), [&](int i) -> bool {
    return v[i] < 4;
});

std::cout << itr << std::endl;  // 2
```


## 参考

1. "二分探索". Wikipedia. <https://ja.wikipedia.org/wiki/二分探索>.
1. "二分法". Wikipedia. <https://ja.wikipedia.org/wiki/二分法>.
1. rsk0315. "抽象化ライブラリの第一歩としての二分探索". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2024/08/04/185219>.
1. "二分探索 二分法 違い". うさぎ小屋. <https://kmyk.github.io/blog/blog/2020/11/07/binary-search-and-bisection-method/>.
1. meguru_comp. X (Twitter). <https://x.com/meguru_comp/status/697008509376835584>.


## 問題

- "C - Transportation Expenses". AtCoder Beginner Contest 365. AtCoder. <https://atcoder.jp/contests/abc365/tasks/abc365_c>.
