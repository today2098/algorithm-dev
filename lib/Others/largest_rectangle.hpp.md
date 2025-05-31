---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DPL_3_B-largest_rectangle.test.cpp
    title: verify/aoj-DPL_3_B-largest_rectangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DPL_3_C-largest_rectangle.test.cpp
    title: verify/aoj-DPL_3_C-largest_rectangle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/largest_rectangle.md
    document_title: "\u6700\u5927\u9577\u65B9\u5F62\u554F\u984C"
    links: []
  bundledCode: "#line 1 \"lib/Others/largest_rectangle.hpp\"\n\n\n\n/**\n * @brief\
    \ \u6700\u5927\u9577\u65B9\u5F62\u554F\u984C\n * @docs docs/Others/largest_rectangle.md\n\
    \ */\n\n#include <functional>\n#include <stack>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u6700\u5927\u9577\u65B9\u5F62\u554F\
    \u984C\uFF0E\n// \u5404i\u306B\u304A\u3044\u3066\uFF0Ccomp(H[i], H[] within [l,r))==true\
    \ \u3068\u306A\u308Bi\u3092\u542B\u3080\u6700\u5927\u533A\u9593[l,r)\u3092\u6C42\
    \u3081\u308B\uFF0EO(N).\ntemplate <typename Type, class Compare = std::function<bool(const\
    \ Type &, const Type &)> >\nstd::vector<std::pair<int, int> > largest_rectangle(\n\
    \    const std::vector<Type> &h,\n    const Compare &comp = [](const Type &a,\
    \ const Type &b) -> bool { return a <= b; }) {\n    const int n = h.size();\n\
    \    std::vector<std::pair<int, int> > res(n, {0, n});  // res[i]:=(pair of [l,r)).\n\
    \    std::stack<std::pair<Type, int> > st;\n    // left side.\n    for(int i =\
    \ 0; i < n; ++i) {\n        while(!st.empty() and comp(h[i], st.top().first))\
    \ st.pop();\n        if(!st.empty()) res[i].first = st.top().second + 1;\n   \
    \     st.push({h[i], i});\n    }\n    // right side.\n    st = std::stack<std::pair<Type,\
    \ int> >();\n    for(int i = n - 1; i >= 0; --i) {\n        while(!st.empty()\
    \ and comp(h[i], st.top().first)) st.pop();\n        if(!st.empty()) res[i].second\
    \ = st.top().second;\n        st.push({h[i], i});\n    }\n    return res;\n}\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LARGEST_RECTANGLE_HPP\n#define ALGORITHM_LARGEST_RECTANGLE_HPP\
    \ 1\n\n/**\n * @brief \u6700\u5927\u9577\u65B9\u5F62\u554F\u984C\n * @docs docs/Others/largest_rectangle.md\n\
    \ */\n\n#include <functional>\n#include <stack>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u6700\u5927\u9577\u65B9\u5F62\u554F\
    \u984C\uFF0E\n// \u5404i\u306B\u304A\u3044\u3066\uFF0Ccomp(H[i], H[] within [l,r))==true\
    \ \u3068\u306A\u308Bi\u3092\u542B\u3080\u6700\u5927\u533A\u9593[l,r)\u3092\u6C42\
    \u3081\u308B\uFF0EO(N).\ntemplate <typename Type, class Compare = std::function<bool(const\
    \ Type &, const Type &)> >\nstd::vector<std::pair<int, int> > largest_rectangle(\n\
    \    const std::vector<Type> &h,\n    const Compare &comp = [](const Type &a,\
    \ const Type &b) -> bool { return a <= b; }) {\n    const int n = h.size();\n\
    \    std::vector<std::pair<int, int> > res(n, {0, n});  // res[i]:=(pair of [l,r)).\n\
    \    std::stack<std::pair<Type, int> > st;\n    // left side.\n    for(int i =\
    \ 0; i < n; ++i) {\n        while(!st.empty() and comp(h[i], st.top().first))\
    \ st.pop();\n        if(!st.empty()) res[i].first = st.top().second + 1;\n   \
    \     st.push({h[i], i});\n    }\n    // right side.\n    st = std::stack<std::pair<Type,\
    \ int> >();\n    for(int i = n - 1; i >= 0; --i) {\n        while(!st.empty()\
    \ and comp(h[i], st.top().first)) st.pop();\n        if(!st.empty()) res[i].second\
    \ = st.top().second;\n        st.push({h[i], i});\n    }\n    return res;\n}\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/largest_rectangle.hpp
  requiredBy: []
  timestamp: '2024-09-16 00:47:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DPL_3_B-largest_rectangle.test.cpp
  - verify/aoj-DPL_3_C-largest_rectangle.test.cpp
documentation_of: lib/Others/largest_rectangle.hpp
layout: document
redirect_from:
- /library/lib/Others/largest_rectangle.hpp
- /library/lib/Others/largest_rectangle.hpp.html
title: "\u6700\u5927\u9577\u65B9\u5F62\u554F\u984C"
---
## 概要

「あるヒストグラム内において，面積が最大となる長方形を求める問題」を効率的に求めるテクニックアルゴリズム．

問題の概要は次の通り．

> 長さ $N$ の数列 $H = \lbrace h_0, h_1, \ldots, h_{N-1} \rbrace$ が与えられる．
>
> 各 $i \ (0 \leq i < N)$ において，$h_i \leq h_j$ となる $i$ を含む $j$ の最大区間を $[l,r)$ とする．
>
> このとき $\max(h_i * (r-l))$ を求めよ．

計算量は，愚直に求めると $\mathcal{O}(N^2)$ となるが，スタックを用いて工夫すると $\mathcal{O}(N)$ に落とすことができる．


## 参考文献

1. 秋葉 拓哉, 岩田 陽一, 北川 宜稔. "4-4 厳選！ 頻出テクニック (2)". プログラミングコンテストチャレンジブック. 第2版, マイナビ出版, 2012, p.298.
