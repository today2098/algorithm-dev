---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ALDS1_10_A-kitamasa.test.cpp
    title: test/aoj-ALDS1_10_A-kitamasa.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/Algebra/kitamasa.md
    document_title: "\u304D\u305F\u307E\u3055\u6CD5"
    links: []
  bundledCode: "#line 1 \"lib/Math/Algebra/kitamasa.hpp\"\n\n\n\n/**\n * @brief \u304D\
    \u305F\u307E\u3055\u6CD5\n * @docs docs/Math/Algebra/kitamasa.md\n */\n\n#include\
    \ <cassert>\n#include <cstdint>\n#include <vector>\n\nnamespace algorithm {\n\n\
    // \u304D\u305F\u307E\u3055\u6CD5\uFF0E\n// \u7DDA\u5F62\u6F38\u5316\u5F0F a[n]=d[0]*a[n-k]+d[1]*a[n-(k-1)]+....+d[k-1]*a[n-1]\
    \ \u3067\u8868\u3055\u308C\u308B\u6570\u5217\u306E\u4EFB\u610F\u306E\u9805\u3092\
    \u6C42\u3081\u308B\uFF0EO((K^2)*logN).\ntemplate <typename T = long long>\nclass\
    \ Kitamasa {\npublic:\n    using size_type = uint64_t;\n\nprivate:\n    size_type\
    \ m_k;       // m_k:=(\u968E\u6570).\n    std::vector<T> m_a;  // m_a[]:=(\u521D\
    \u9805\u6570\u5217).\n    std::vector<T> m_d;  // m_d[]:=(\u4FC2\u6570\u6570\u5217\
    ).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const std::vector<T>\
    \ &x) const {\n        std::vector<T> y(m_k);\n        y[0] = x[m_k - 1] * m_d[0];\n\
    \        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];\n\
    \        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n    std::vector<T> mul(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(m_k, 0);\n        std::vector<T>\
    \ t = x;\n        for(size_type i = 0; i < m_k; ++i) {\n            for(size_type\
    \ j = 0; j < m_k; ++j) y[j] += x[i] * t[j];\n            if(i == m_k - 1) break;\n\
    \            t = add(t);\n        }\n        return y;\n    }\n    // f(n)\u3092\
    \u8FD4\u3059\uFF0EO((K^2)*logN).\n    std::vector<T> f(size_type n) const {\n\
    \        if(n == 0) {\n            std::vector<T> x(m_k, 0);\n            x[0]\
    \ = 1;\n            return x;  // f(0).\n        }\n        std::vector<T> &&x\
    \ = mul(f(n / 2));\n        if(n & 1ULL) x = add(x);\n        return x;\n    }\n\
    \npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // \u30D5\u30A3\u30DC\
    \u30CA\u30C3\u30C1\u6570\u5217\uFF0E\n    explicit Kitamasa(const std::vector<T>\
    \ &a, const std::vector<T> &d) : m_k(a.size()), m_a(a), m_d(d) {\n        assert(a.size()\
    \ >= 1);\n        assert(a.size() == d.size());\n    }\n\n    T operator[](size_type\
    \ n) const { return calc(n); }\n\n    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\n\
    \    T calc(size_type n) const {\n        T res = 0;\n        const std::vector<T>\
    \ &&x = f(n);\n        for(size_type i = 0; i < m_k; ++i) res += x[i] * m_a[i];\n\
    \        return res;\n    }\n    // a[l:r]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN+K*(r-l)).\n\
    \    std::vector<T> calc(size_type l, size_type r) const {\n        assert(l <\
    \ r);\n        std::vector<T> res(r - l);\n        std::vector<T> &&x = f(l);\n\
    \        for(size_type i = l; i < r; ++i) {\n            for(size_type j = 0;\
    \ j < m_k; ++j) res[i - l] += x[j] * m_a[j];\n            if(i == r - 1) break;\n\
    \            x = add(x);\n        }\n        return res;\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_KITAMASA_HPP\n#define ALGORITHM_KITAMASA_HPP 1\n\n/**\n\
    \ * @brief \u304D\u305F\u307E\u3055\u6CD5\n * @docs docs/Math/Algebra/kitamasa.md\n\
    \ */\n\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u304D\u305F\u307E\u3055\u6CD5\uFF0E\n// \u7DDA\u5F62\u6F38\
    \u5316\u5F0F a[n]=d[0]*a[n-k]+d[1]*a[n-(k-1)]+....+d[k-1]*a[n-1] \u3067\u8868\u3055\
    \u308C\u308B\u6570\u5217\u306E\u4EFB\u610F\u306E\u9805\u3092\u6C42\u3081\u308B\
    \uFF0EO((K^2)*logN).\ntemplate <typename T = long long>\nclass Kitamasa {\npublic:\n\
    \    using size_type = uint64_t;\n\nprivate:\n    size_type m_k;       // m_k:=(\u968E\
    \u6570).\n    std::vector<T> m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n   \
    \ std::vector<T> m_d;  // m_d[]:=(\u4FC2\u6570\u6570\u5217).\n\n    // f(n)->f(n+1).\
    \ O(K).\n    std::vector<T> add(const std::vector<T> &x) const {\n        std::vector<T>\
    \ y(m_k);\n        y[0] = x[m_k - 1] * m_d[0];\n        for(size_type i = 1; i\
    \ < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];\n        return y;\n    }\n\
    \    // f(n)->f(2*n). O(K^2).\n    std::vector<T> mul(const std::vector<T> &x)\
    \ const {\n        std::vector<T> y(m_k, 0);\n        std::vector<T> t = x;\n\
    \        for(size_type i = 0; i < m_k; ++i) {\n            for(size_type j = 0;\
    \ j < m_k; ++j) y[j] += x[i] * t[j];\n            if(i == m_k - 1) break;\n  \
    \          t = add(t);\n        }\n        return y;\n    }\n    // f(n)\u3092\
    \u8FD4\u3059\uFF0EO((K^2)*logN).\n    std::vector<T> f(size_type n) const {\n\
    \        if(n == 0) {\n            std::vector<T> x(m_k, 0);\n            x[0]\
    \ = 1;\n            return x;  // f(0).\n        }\n        std::vector<T> &&x\
    \ = mul(f(n / 2));\n        if(n & 1ULL) x = add(x);\n        return x;\n    }\n\
    \npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // \u30D5\u30A3\u30DC\
    \u30CA\u30C3\u30C1\u6570\u5217\uFF0E\n    explicit Kitamasa(const std::vector<T>\
    \ &a, const std::vector<T> &d) : m_k(a.size()), m_a(a), m_d(d) {\n        assert(a.size()\
    \ >= 1);\n        assert(a.size() == d.size());\n    }\n\n    T operator[](size_type\
    \ n) const { return calc(n); }\n\n    // a[n]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN).\n\
    \    T calc(size_type n) const {\n        T res = 0;\n        const std::vector<T>\
    \ &&x = f(n);\n        for(size_type i = 0; i < m_k; ++i) res += x[i] * m_a[i];\n\
    \        return res;\n    }\n    // a[l:r]\u3092\u6C42\u3081\u308B\uFF0EO((K^2)*logN+K*(r-l)).\n\
    \    std::vector<T> calc(size_type l, size_type r) const {\n        assert(l <\
    \ r);\n        std::vector<T> res(r - l);\n        std::vector<T> &&x = f(l);\n\
    \        for(size_type i = l; i < r; ++i) {\n            for(size_type j = 0;\
    \ j < m_k; ++j) res[i - l] += x[j] * m_a[j];\n            if(i == r - 1) break;\n\
    \            x = add(x);\n        }\n        return res;\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Algebra/kitamasa.hpp
  requiredBy: []
  timestamp: '2024-09-29 14:41:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ALDS1_10_A-kitamasa.test.cpp
documentation_of: lib/Math/Algebra/kitamasa.hpp
layout: document
redirect_from:
- /library/lib/Math/Algebra/kitamasa.hpp
- /library/lib/Math/Algebra/kitamasa.hpp.html
title: "\u304D\u305F\u307E\u3055\u6CD5"
---
## 概要

初めの $k$ 項 $\lbrace a_0, a_1, \ldots, a_{k-1} \rbrace$ と $k$ 階線形漸化式

$$
a_n = d_0 \cdot a_{n-k} + d_1 \cdot a_{n-(k-1)} + \cdots + d_{k-1} \cdot a_{n-1}
$$

によって定まる数列の任意の項 $a_n$ を $\mathcal{O}(k^2 \log n)$ で求める．


### アルゴリズムの説明

このアルゴリズムの主な方針は，

$$
a_n = x_{(n)0} \cdot a_0 + x_{(n)1} \cdot a_1 + \cdots + x_{(n)k-1} \cdot a_{k-1}
$$

となる $f(n) = \lbrace x_{(n)0}, x_{(n)1}, \ldots, x_{(n)k-1} \rbrace$ を求めることである．

まず，前提として $f(i)$ が分かっていると仮定する．
このとき，

$$
a_i = x_{(i)0} \cdot a_0 + x_{(i)1} \cdot a_1 + \cdots + x_{(i)k-2} \cdot a_{k-2} + x_{(i)k-1} \cdot a_{k-1} \notag
$$

とすると，

$$
\begin{align}
a_{i+1} &= x_{(i)0} \cdot a_1 + x_{(i)1} \cdot a_2 + \cdots + x_{(i)k-2} \cdot a_{k-1} + x_{(i)k-1} \cdot a_k \notag\\
a_{i+1} &= x_{(i)0} \cdot a_1 + x_{(i)1} \cdot a_2 + \cdots + x_{(i)k-2} \cdot a_{k-1} + x_{(i)k-1} \cdot (d_0 \cdot a_0 + d_1 \cdot a_1 + \cdots + d_{k-1} \cdot a_{k-1}) \notag\\

a_{i+1} &= x_{(i)k-1} \cdot d_0 \cdot a_0 + (x_{(i)0} + x_{(i)k-1} \cdot d_1) \cdot a_1 + (x_{(i)1} + x_{(i)k-1} \cdot d_2) \cdot a_2 + \cdots + (x_{(i)k-2} + x_{(i)k-1} \cdot d_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

より，$f(i+1)$ が $\mathcal{O}(k)$ で求められる．

また，先の方法で $f(i), f(i+1), \ldots, f(i+k-1)$ が $\mathcal{O}(k^2)$ で列挙できるとする．
このとき，

$$
\begin{align}
a_{2i} &= x_{(i)0} \cdot a_i + x_{(i)1} \cdot a_{i+1} + \cdots + x_{(i)k-1} \cdot a_{i+k-1} \notag\\
a_{2i} &= x_{(i)0} \cdot (x_{(i)0} \cdot a_0 + x_{(i)1} \cdot a_1 + \cdots + x_{(i)k-1} \cdot a_{k-1}) \notag\\
    &\quad + x_{(i)1} \cdot (x_{(i+1)0} \cdot a_0 + x_{(i+1)1} \cdot a_1 + \cdots + x_{(i+1)k-1} \cdot a_{k-1}) \notag\\
    &\quad + \cdots \notag\\
    &\quad + x_{(i)k-1} \cdot (x_{(i+k-1)0} \cdot a_0 + x_{(i+k-1)1} \cdot a_1 + \cdots + x_{(i+k-1)k-1} \cdot a_{k-1}) \notag\\
a_{2i} &= (x_{(i)0} \cdot x_{(i)0} + x_{(i)1} \cdot x_{(i+1)0} + \cdots + x_{(i)k-1} \cdot x_{(i+k-1)0}) \cdot a_0 \notag\\
    &\quad + (x_{(i)0} \cdot x_{(i)1} + x_{(i)1} \cdot x_{(i+1)1} + \cdots + x_{(i)k-1} \cdot x_{(i+k-1)1}) \cdot a_1 \notag\\
    &\quad + \cdots \notag\\
    &\quad + (x_{(i)0} \cdot x_{(i)k-1} + x_{(i)1} \cdot x_{(i+1)k-1} + \cdots + x_{(i)k-1} \cdot x_{(i+k-1)k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

となり，$f(2i)$ が $\mathcal{O}(k^2)$ で求められる．

よって，「繰り返し二乗法」と同じ要領で $f(k) = \lbrace d_0, d_1, \ldots, d_{k-1} \rbrace$ から $f(n)$ を求めることができ，全体の計算量は $\mathcal{O}(k^2 \log n)$ となる．


## 参考文献

1. yosupo. "きたまさ法メモ". HatenaBlog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.


## 問題

- "T - フィボナッチ". Typical DP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
