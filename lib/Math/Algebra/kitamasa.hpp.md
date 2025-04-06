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
  bundledCode: "#line 1 \"lib/Math/Algebra/kitamasa.hpp\"\n\n\n\n#include <cassert>\n\
    #include <iterator>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u304D\u305F\u307E\u3055\u6CD5\uFF0E\ntemplate <typename T>\nclass Kitamasa\
    \ {\npublic:\n    using value_type = T;\n    using size_type = std::size_t;\n\n\
    private:\n    size_type m_k;       // m_k:=(\u968E\u6570).\n    std::vector<T>\
    \ m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n    std::vector<T> m_c;  // m_c[]:=(\u4FC2\
    \u6570\u6570\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(m_k);\n        y[0] = x[m_k\
    \ - 1] * m_c[0];\n        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] +\
    \ x[m_k - 1] * m_c[i];\n        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n\
    \    std::vector<T> mul(const std::vector<T> &x) const {\n        std::vector<T>\
    \ y(m_k, 0);\n        std::vector<T> t = x;\n        for(size_type i = 0; i <\
    \ m_k; ++i) {\n            for(size_type j = 0; j < m_k; ++j) y[j] += x[i] * t[j];\n\
    \            if(i == m_k - 1) break;\n            t = add(t);\n        }\n   \
    \     return y;\n    }\n    // f(n)\u3092\u8FD4\u3059\uFF0EO((K^2)*logN).\n  \
    \  std::vector<T> f(size_type n) const {\n        if(n == 0) {\n            std::vector<T>\
    \ x(m_k, 0);\n            x[0] = 1;\n            return x;  // f(0).\n       \
    \ }\n        std::vector<T> &&x = mul(f(n >> 1));\n        if(n & 1ULL) x = add(x);\n\
    \        return x;\n    }\n\npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1})\
    \ {}  // \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u6570\u5217\uFF0E\n    explicit\
    \ Kitamasa(std::vector<T> a, std::vector<T> c) : m_k(a.size()), m_a(std::move(a)),\
    \ m_c(std::move(c)) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_c.size());\n    }\n    template <std::input_iterator Iter>\n    explicit\
    \ Kitamasa(Iter a_first, Iter a_last, Iter d_first, Iter d_last) : m_a(a_first,\
    \ a_last), m_c(d_first, d_last) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_c.size());\n        m_k = m_a.size();\n    }\n\n    T operator[](size_type\
    \ n) const { return calc(n); }\n\n    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\n\
    \    T calc(size_type n) const {\n        const std::vector<T> &&x = f(n);\n \
    \       T res = 0;\n        for(size_type i = 0; i < m_k; ++i) res += m_a[i] *\
    \ x[i];\n        return res;\n    }\n    // a[l:r]\u3092\u6C42\u3081\u308B\uFF0E\
    O((K^2)*logN+K*(r-l)).\n    std::vector<T> calc(size_type l, size_type r) const\
    \ {\n        assert(l < r);\n        std::vector<T> res(r - l);\n        std::vector<T>\
    \ &&x = f(l);\n        for(size_type i = l; i < r; ++i) {\n            for(size_type\
    \ j = 0; j < m_k; ++j) res[i - l] += m_a[j] * x[j];\n            if(i == r - 1)\
    \ break;\n            x = add(x);\n        }\n        return res;\n    }\n};\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_KITAMASA_HPP\n#define ALGORITHM_KITAMASA_HPP 1\n\n#include\
    \ <cassert>\n#include <iterator>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u304D\u305F\u307E\u3055\u6CD5\uFF0E\ntemplate <typename T>\n\
    class Kitamasa {\npublic:\n    using value_type = T;\n    using size_type = std::size_t;\n\
    \nprivate:\n    size_type m_k;       // m_k:=(\u968E\u6570).\n    std::vector<T>\
    \ m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n    std::vector<T> m_c;  // m_c[]:=(\u4FC2\
    \u6570\u6570\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(m_k);\n        y[0] = x[m_k\
    \ - 1] * m_c[0];\n        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] +\
    \ x[m_k - 1] * m_c[i];\n        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n\
    \    std::vector<T> mul(const std::vector<T> &x) const {\n        std::vector<T>\
    \ y(m_k, 0);\n        std::vector<T> t = x;\n        for(size_type i = 0; i <\
    \ m_k; ++i) {\n            for(size_type j = 0; j < m_k; ++j) y[j] += x[i] * t[j];\n\
    \            if(i == m_k - 1) break;\n            t = add(t);\n        }\n   \
    \     return y;\n    }\n    // f(n)\u3092\u8FD4\u3059\uFF0EO((K^2)*logN).\n  \
    \  std::vector<T> f(size_type n) const {\n        if(n == 0) {\n            std::vector<T>\
    \ x(m_k, 0);\n            x[0] = 1;\n            return x;  // f(0).\n       \
    \ }\n        std::vector<T> &&x = mul(f(n >> 1));\n        if(n & 1ULL) x = add(x);\n\
    \        return x;\n    }\n\npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1})\
    \ {}  // \u30D5\u30A3\u30DC\u30CA\u30C3\u30C1\u6570\u5217\uFF0E\n    explicit\
    \ Kitamasa(std::vector<T> a, std::vector<T> c) : m_k(a.size()), m_a(std::move(a)),\
    \ m_c(std::move(c)) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_c.size());\n    }\n    template <std::input_iterator Iter>\n    explicit\
    \ Kitamasa(Iter a_first, Iter a_last, Iter d_first, Iter d_last) : m_a(a_first,\
    \ a_last), m_c(d_first, d_last) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_c.size());\n        m_k = m_a.size();\n    }\n\n    T operator[](size_type\
    \ n) const { return calc(n); }\n\n    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\n\
    \    T calc(size_type n) const {\n        const std::vector<T> &&x = f(n);\n \
    \       T res = 0;\n        for(size_type i = 0; i < m_k; ++i) res += m_a[i] *\
    \ x[i];\n        return res;\n    }\n    // a[l:r]\u3092\u6C42\u3081\u308B\uFF0E\
    O((K^2)*logN+K*(r-l)).\n    std::vector<T> calc(size_type l, size_type r) const\
    \ {\n        assert(l < r);\n        std::vector<T> res(r - l);\n        std::vector<T>\
    \ &&x = f(l);\n        for(size_type i = l; i < r; ++i) {\n            for(size_type\
    \ j = 0; j < m_k; ++j) res[i - l] += m_a[j] * x[j];\n            if(i == r - 1)\
    \ break;\n            x = add(x);\n        }\n        return res;\n    }\n};\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Algebra/kitamasa.hpp
  requiredBy: []
  timestamp: '2025-04-06 04:16:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_10_A-kitamasa.test.cpp
documentation_of: lib/Math/Algebra/kitamasa.hpp
layout: document
title: "\u304D\u305F\u307E\u3055\u6CD5"
---


## 概要

初めの $k$ 項 $\lbrace a_0, a_1, \ldots, a_{k-1} \rbrace$ と $k$ 階線形漸化式

$$
a_n = c_0 \cdot a_{n-k} + c_1 \cdot a_{n-(k-1)} + \cdots + c_{k-1} \cdot a_{n-1}
$$

によって定まる数列の任意の項 $a_N$ を $\mathcal{O}(k^2 \log N)$ で求める．


### アルゴリズムの説明

#### 方針

説明のため，

$$
a_n = C(n,0) \cdot a_0 + C(n,1) \cdot a_1 + \cdots + C(n,k-1) \cdot a_{k-1} = \sum_{i=0}^{k-1} C(n,i) \cdot a_{i}
$$

となる $C(n,*)$ を定義する（ただし，$n \geq 0$ ）．

このとき，

$$
\begin{equation}
C(0,i) = 
    \begin{cases}
    1 &\text{if \ $i=0$,} \\
    0 &\text{if \ $0<i<k$}
    \end{cases} \notag
\end{equation}
$$

である．


きたまさ法の方針は，$C(n,*) \rightarrow C(n+1,*), C(n,*) \rightarrow C(2n,*)$ を計算することにより，繰り返し二乗法と同じ要領で $C(0,*)$ から $C(N,*)$ を求めることである．


#### $C(n,*) \rightarrow C(n+1,*)$ の計算

まず，前提として $C(n,*)$ が分かっていると仮定する．
このとき，

$$
\begin{align}
a_{n+1} &= C(n,0) \cdot a_1 + C(n,1) \cdot a_2 + \cdots + C(n,k-2) \cdot a_{k-1} + C(n,k-1) \cdot a_k \notag\\
    &= C(n,0) \cdot a_1 + C(n,1) \cdot a_2 + \cdots + C(n,k-2) \cdot a_{k-1} + C(n,k-1) \cdot (c_0 \cdot a_0 + c_1 \cdot a_1 + \cdots + c_{k-1} \cdot a_{k-1}) \notag\\
    &= C(n,k-1) \cdot c_0 \cdot a_0 + (C(n,0) + C(n,k-1) \cdot c_1) \cdot a_1 + (C(n,1) + C(n,k-1) \cdot c_2) \cdot a_2 + \cdots + (C(n,k-2) + C(n,k-1)  \cdot c_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
\begin{equation}
C(n+1,i) = 
    \begin{cases}
    C(n,k-1) \cdot c_0 &\text{if \ $i=0$,} \\
    C(n,i-1) + C(n,k-1)  \cdot c_i &\text{if \ $0<i<k$}
    \end{cases} \notag
\end{equation}
$$

と求まる．
これは $\mathcal{O}(k)$ で計算できる．


#### $C(n,*) \rightarrow C(2n,*)$ の計算

先の方法で $C(n,*), C(n+1,*), \ldots, C(n+k-1,*)$ が $\mathcal{O}(k^2)$ で列挙できるとする．
このとき，

$$
\begin{align}
a_{2n} &= C(n,0) \cdot a_n + C(n,1) \cdot a_{n+1} + \cdots + C(n,k-1) \cdot a_{n+k-1} \notag\\
    &= C(n,0) \cdot (C(n,0) \cdot a_0 + C(n,1) \cdot a_1 + \cdots + C(n,k-1) \cdot a_{k-1}) \notag\\
    &\quad + C(n,1) \cdot (C(n+1,0) \cdot a_0 + C(n+1,1) \cdot a_1 + \cdots + C(n+1,k-1) \cdot a_{k-1}) \notag\\
    &\quad + \cdots \notag\\
    &\quad + C(n,k-1) \cdot (C(n+k-1,0) \cdot a_0 + C(n+k-1,1) \cdot a_1 + \cdots + C(n+k-1,k-1) \cdot a_{k-1}) \notag\\
    &= (C(n,0) \cdot C(n,0) + C(n,1) \cdot C(n+1,0) + \cdots + C(n,k-1) \cdot C(n+k-1,0)) \cdot a_0 \notag\\
    &\quad + (C(n,0) \cdot C(n,1) + C(n,1) \cdot C(n+1,1) + \cdots + C(n,k-1) \cdot C(n+k-1,1)) \cdot a_1 \notag\\
    &\quad + \cdots \notag\\
    &\quad + (C(n,0) \cdot C(n,k-1) + C(n,1) \cdot C(n+1,k-1) + \cdots + C(n,k-1) \cdot C(n+k-1,k-1)) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
C(2n,i) = \sum_{j=0}^{k-1} C(n,j) \cdot C(n+j,i)
$$

と求まる．
これは $\mathcal{O}(k^2)$ で計算できる．

よって，繰り返し二乗法と同じ要領で $C(0,*)$ から $C(N,*)$ を $\mathcal{O}(k^2 \log N)$ で求めることができる．


## 参考文献

1. "漸化式". Wikipedia. <https://ja.wikipedia.org/wiki/漸化式>.
1. yosupo. "きたまさ法メモ". HatenaBlog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.
1. smijake3. "Kitamasa法". HatenaBlog. <https://smijake3.hatenablog.com/entry/2017/01/02/024712>.


## 問題

- "T - フィボナッチ". Typical CP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
