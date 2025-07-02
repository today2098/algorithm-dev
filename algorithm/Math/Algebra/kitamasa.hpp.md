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
    private:\n    size_type m_k;       // m_k:=(\u968E\u6570).\n    std::vector<T>\
    \ m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n    std::vector<T> m_d;  // m_d[]:=(\u4FC2\
    \u6570\u6570\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(m_k);\n        y[0] = x[m_k\
    \ - 1] * m_d[0];\n        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] +\
    \ x[m_k - 1] * m_d[i];\n        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n\
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
    \ Kitamasa(std::vector<T> a, std::vector<T> d) : m_k(a.size()), m_a(std::move(a)),\
    \ m_d(std::move(d)) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_d.size());\n    }\n    template <std::input_iterator Iter>\n    explicit\
    \ Kitamasa(Iter a_first, Iter a_last, Iter d_first, Iter d_last) : m_a(a_first,\
    \ a_last), m_d(d_first, d_last) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_d.size());\n        m_k = m_a.size();\n    }\n\n    T operator[](size_type\
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
    \ m_a;  // m_a[]:=(\u521D\u9805\u6570\u5217).\n    std::vector<T> m_d;  // m_d[]:=(\u4FC2\
    \u6570\u6570\u5217).\n\n    // f(n)->f(n+1). O(K).\n    std::vector<T> add(const\
    \ std::vector<T> &x) const {\n        std::vector<T> y(m_k);\n        y[0] = x[m_k\
    \ - 1] * m_d[0];\n        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] +\
    \ x[m_k - 1] * m_d[i];\n        return y;\n    }\n    // f(n)->f(2*n). O(K^2).\n\
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
    \ Kitamasa(std::vector<T> a, std::vector<T> d) : m_k(a.size()), m_a(std::move(a)),\
    \ m_d(std::move(d)) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_d.size());\n    }\n    template <std::input_iterator Iter>\n    explicit\
    \ Kitamasa(Iter a_first, Iter a_last, Iter d_first, Iter d_last) : m_a(a_first,\
    \ a_last), m_d(d_first, d_last) {\n        assert(m_a.size() >= 1);\n        assert(m_a.size()\
    \ == m_d.size());\n        m_k = m_a.size();\n    }\n\n    T operator[](size_type\
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
  path: algorithm/Math/Algebra/kitamasa.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_10_A-kitamasa.test.cpp
documentation_of: algorithm/Math/Algebra/kitamasa.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Algebra/kitamasa.hpp
- /library/algorithm/Math/Algebra/kitamasa.hpp.html
title: algorithm/Math/Algebra/kitamasa.hpp
---
