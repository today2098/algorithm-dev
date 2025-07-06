---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_10_A-kitamasa.test.cpp
    title: verify/aoj-ALDS1_10_A-kitamasa.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Algebra/kitamasa.hpp\"\n\n\n\n#include <cassert>\n\
    #include <iterator>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u304D\u305F\u307E\u3055\u6CD5\uFF0E\ntemplate <typename T>\nclass Kitamasa\
    \ {\npublic:\n    using value_type = T;\n    using size_type = std::size_t;\n\n\
    private:\n    size_type m_k;                // m_k:=(\u968E\u6570).\n    std::vector<value_type>\
    \ m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n    std::vector<value_type> m_d;\
    \  // m_d[]:=(\u4FC2\u6570\u6570\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<value_type>\
    \ add(const std::vector<value_type> &x) const {\n        std::vector<value_type>\
    \ y(m_k);\n        y[0] = x[m_k - 1] * m_d[0];\n        for(size_type i = 1; i\
    \ < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];\n        return y;\n    }\n\
    \    // f(n)->f(2*n). O(K^2).\n    std::vector<value_type> mul(const std::vector<value_type>\
    \ &x) const {\n        std::vector<value_type> y(m_k, 0);\n        std::vector<value_type>\
    \ t = x;\n        for(size_type i = 0; i < m_k; ++i) {\n            for(size_type\
    \ j = 0; j < m_k; ++j) y[j] += x[i] * t[j];\n            if(i == m_k - 1) break;\n\
    \            t = add(t);\n        }\n        return y;\n    }\n    // f(n)\u3092\
    \u8FD4\u3059\uFF0EO((K^2)*logN).\n    std::vector<value_type> f(size_type n) const\
    \ {\n        if(n == 0) {\n            std::vector<value_type> x(m_k, 0);\n  \
    \          x[0] = 1;\n            return x;  // f(0).\n        }\n        std::vector<value_type>\
    \ &&x = mul(f(n >> 1));\n        if(n & 1ULL) x = add(x);\n        return x;\n\
    \    }\n\npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // \u30D5\u30A3\
    \u30DC\u30CA\u30C3\u30C1\u6570\u5217\uFF0E\n    template <std::input_iterator\
    \ InputIter>\n    explicit Kitamasa(InputIter a_first, InputIter a_last, InputIter\
    \ d_first, InputIter d_last) : m_a(a_first, a_last), m_d(d_first, d_last) {\n\
    \        assert(m_a.size() >= 1);\n        assert(m_a.size() == m_d.size());\n\
    \        m_k = m_a.size();\n    }\n    explicit Kitamasa(std::vector<value_type>\
    \ a, std::vector<value_type> d) : m_k(a.size()), m_a(std::move(a)), m_d(std::move(d))\
    \ {\n        assert(m_a.size() >= 1);\n        assert(m_a.size() == m_d.size());\n\
    \    }\n\n    value_type operator[](size_type n) const { return calc(n); }\n\n\
    \    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*log N).\n    value_type calc(size_type\
    \ n) const {\n        std::vector<value_type> &&x = f(n);\n        value_type\
    \ res = 0;\n        for(size_type i = 0; i < m_k; ++i) res += m_a[i] * x[i];\n\
    \        return res;\n    }\n    // a[l:r]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*log(N)\
    \ + K*(r-l)).\n    std::vector<value_type> calc(size_type l, size_type r) const\
    \ {\n        assert(l < r);\n        std::vector<value_type> res(r - l);\n   \
    \     std::vector<value_type> &&x = f(l);\n        for(size_type i = l; i < r;\
    \ ++i) {\n            for(size_type j = 0; j < m_k; ++j) res[i - l] += m_a[j]\
    \ * x[j];\n            if(i == r - 1) break;\n            x = add(x);\n      \
    \  }\n        return res;\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_KITAMASA_HPP\n#define ALGORITHM_KITAMASA_HPP 1\n\n#include\
    \ <cassert>\n#include <iterator>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u304D\u305F\u307E\u3055\u6CD5\uFF0E\ntemplate <typename T>\n\
    class Kitamasa {\npublic:\n    using value_type = T;\n    using size_type = std::size_t;\n\
    \nprivate:\n    size_type m_k;                // m_k:=(\u968E\u6570).\n    std::vector<value_type>\
    \ m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n    std::vector<value_type> m_d;\
    \  // m_d[]:=(\u4FC2\u6570\u6570\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<value_type>\
    \ add(const std::vector<value_type> &x) const {\n        std::vector<value_type>\
    \ y(m_k);\n        y[0] = x[m_k - 1] * m_d[0];\n        for(size_type i = 1; i\
    \ < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];\n        return y;\n    }\n\
    \    // f(n)->f(2*n). O(K^2).\n    std::vector<value_type> mul(const std::vector<value_type>\
    \ &x) const {\n        std::vector<value_type> y(m_k, 0);\n        std::vector<value_type>\
    \ t = x;\n        for(size_type i = 0; i < m_k; ++i) {\n            for(size_type\
    \ j = 0; j < m_k; ++j) y[j] += x[i] * t[j];\n            if(i == m_k - 1) break;\n\
    \            t = add(t);\n        }\n        return y;\n    }\n    // f(n)\u3092\
    \u8FD4\u3059\uFF0EO((K^2)*logN).\n    std::vector<value_type> f(size_type n) const\
    \ {\n        if(n == 0) {\n            std::vector<value_type> x(m_k, 0);\n  \
    \          x[0] = 1;\n            return x;  // f(0).\n        }\n        std::vector<value_type>\
    \ &&x = mul(f(n >> 1));\n        if(n & 1ULL) x = add(x);\n        return x;\n\
    \    }\n\npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // \u30D5\u30A3\
    \u30DC\u30CA\u30C3\u30C1\u6570\u5217\uFF0E\n    template <std::input_iterator\
    \ InputIter>\n    explicit Kitamasa(InputIter a_first, InputIter a_last, InputIter\
    \ d_first, InputIter d_last) : m_a(a_first, a_last), m_d(d_first, d_last) {\n\
    \        assert(m_a.size() >= 1);\n        assert(m_a.size() == m_d.size());\n\
    \        m_k = m_a.size();\n    }\n    explicit Kitamasa(std::vector<value_type>\
    \ a, std::vector<value_type> d) : m_k(a.size()), m_a(std::move(a)), m_d(std::move(d))\
    \ {\n        assert(m_a.size() >= 1);\n        assert(m_a.size() == m_d.size());\n\
    \    }\n\n    value_type operator[](size_type n) const { return calc(n); }\n\n\
    \    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*log N).\n    value_type calc(size_type\
    \ n) const {\n        std::vector<value_type> &&x = f(n);\n        value_type\
    \ res = 0;\n        for(size_type i = 0; i < m_k; ++i) res += m_a[i] * x[i];\n\
    \        return res;\n    }\n    // a[l:r]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*log(N)\
    \ + K*(r-l)).\n    std::vector<value_type> calc(size_type l, size_type r) const\
    \ {\n        assert(l < r);\n        std::vector<value_type> res(r - l);\n   \
    \     std::vector<value_type> &&x = f(l);\n        for(size_type i = l; i < r;\
    \ ++i) {\n            for(size_type j = 0; j < m_k; ++j) res[i - l] += m_a[j]\
    \ * x[j];\n            if(i == r - 1) break;\n            x = add(x);\n      \
    \  }\n        return res;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Algebra/kitamasa.hpp
  requiredBy: []
  timestamp: '2025-07-06 15:35:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_10_A-kitamasa.test.cpp
documentation_of: algorithm/Math/Algebra/kitamasa.hpp
layout: document
title: "\u304D\u305F\u307E\u3055\u6CD5"
---


## 概要

初めの $k$ 項 $\lbrace a_0, a_1, \ldots, a_{k-1} \rbrace$ と $k$ 階線形漸化式

$$
a_n = d_0 \cdot a_{n-k} + d_1 \cdot a_{n-(k-1)} + \cdots + d_{k-1} \cdot a_{n-1}
$$

によって定まる数列の任意の項 $a_N$ を $\mathcal{O}(k^2 \log N)$ で求める．


### アルゴリズムの説明

#### 方針

説明のため，

$$
a_n = D(n,0) \cdot a_0 + D(n,1) \cdot a_1 + \cdots + D(n,k-1) \cdot a_{k-1} = \sum_{i=0}^{k-1} D(n,i) \cdot a_{i}
$$

となる $D(n,\ast)$ を定義する（ただし，$n \geq 0$ ）．

このとき，

$$
\begin{equation}
D(0,i) = 
    \begin{cases}
    1 &\text{if \ $i=0$ ,} \\
    0 &\text{otherwise}
    \end{cases} \notag
\end{equation}
$$

である．

きたまさ法の方針は，$D(n,\ast) \rightarrow D(n+1,\ast)$ と $D(n,\ast) \rightarrow D(2n,\ast)$ を計算することにより，繰り返し二乗法と同じ要領で $D(0,\ast)$ から $D(N,\ast)$ を求めることである．


#### $D(n,\ast) \rightarrow D(n+1,\ast)$ の計算

まず，前提として $D(n,\ast)$ が分かっていると仮定する．
このとき，

$$
\begin{align}
a_{n+1} &= D(n,0) \cdot a_1 + D(n,1) \cdot a_2 + \cdots + D(n,k-2) \cdot a_{k-1} + D(n,k-1) \cdot a_k \notag\\
    &= D(n,0) \cdot a_1 + D(n,1) \cdot a_2 + \cdots + D(n,k-2) \cdot a_{k-1} + D(n,k-1) \cdot (d_0 \cdot a_0 + d_1 \cdot a_1 + \cdots + d_{k-1} \cdot a_{k-1}) \notag\\
    &= D(n,k-1) \cdot d_0 \cdot a_0 + (D(n,0) + D(n,k-1) \cdot d_1) \cdot a_1 + (D(n,1) + D(n,k-1) \cdot d_2) \cdot a_2 + \cdots + (D(n,k-2) + D(n,k-1)  \cdot d_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
\begin{equation}
D(n+1,i) = 
    \begin{cases}
    D(n,k-1) \cdot d_0 &\text{if \ $i=0$ ,} \\
    D(n,i-1) + D(n,k-1) \cdot d_i &\text{otherwise}
    \end{cases} \notag
\end{equation}
$$

と求まる．
これは $\mathcal{O}(k)$ で計算できる．


#### $D(n,\ast) \rightarrow D(2n,\ast)$ の計算

先の方法で $D(n,\ast), D(n+1,\ast), \ldots, D(n+k-1,\ast)$ が $\mathcal{O}(k^2)$ で列挙できるとする．
このとき，

$$
\begin{align}
a_{2n} &= D(n,0) \cdot a_n + D(n,1) \cdot a_{n+1} + \cdots + D(n,k-1) \cdot a_{n+k-1} \notag\\
    &= D(n,0) \cdot (D(n,0) \cdot a_0 + D(n,1) \cdot a_1 + \cdots + D(n,k-1) \cdot a_{k-1}) \notag\\
    &\quad + D(n,1) \cdot (D(n+1,0) \cdot a_0 + D(n+1,1) \cdot a_1 + \cdots + D(n+1,k-1) \cdot a_{k-1}) \notag\\
    &\quad + \cdots \notag\\
    &\quad + D(n,k-1) \cdot (D(n+k-1,0) \cdot a_0 + D(n+k-1,1) \cdot a_1 + \cdots + D(n+k-1,k-1) \cdot a_{k-1}) \notag\\
    &= (D(n,0) \cdot D(n,0) + D(n,1) \cdot D(n+1,0) + \cdots + D(n,k-1) \cdot D(n+k-1,0)) \cdot a_0 \notag\\
    &\quad + (D(n,0) \cdot D(n,1) + D(n,1) \cdot D(n+1,1) + \cdots + D(n,k-1) \cdot D(n+k-1,1)) \cdot a_1 \notag\\
    &\quad + \cdots \notag\\
    &\quad + (D(n,0) \cdot D(n,k-1) + D(n,1) \cdot D(n+1,k-1) + \cdots + D(n,k-1) \cdot D(n+k-1,k-1)) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
D(2n,i) = \sum_{j=0}^{k-1} D(n,j) \cdot D(n+j,i)
$$

と求まる．
これは $\mathcal{O}(k^2)$ で計算できる．

よって，繰り返し二乗法と同じ要領で $D(0,\ast)$ から $D(N,\ast)$ を $\mathcal{O}(k^2 \log N)$ で求めることができる．


## 参考

1. "漸化式". Wikipedia. <https://ja.wikipedia.org/wiki/漸化式>.
1. yosupo. "きたまさ法メモ". HatenaBlog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.
1. smijake3. "Kitamasa法". HatenaBlog. <https://smijake3.hatenablog.com/entry/2017/01/02/024712>.


## 問題

- "T - フィボナッチ". Typical CP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
