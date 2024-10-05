---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/kitamasa.hpp
    title: "\u304D\u305F\u307E\u3055\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_A
  bundledCode: "#line 1 \"test/aoj-ALDS1_10_A-kitamasa.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_A\"\n\n\
    #include <iostream>\n\n#line 1 \"lib/Math/Algebra/kitamasa.hpp\"\n\n\n\n/**\n\
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
    \ = mul(f(n >> 1));\n        if(n & 1ULL) x = add(x);\n        return x;\n   \
    \ }\n\npublic:\n    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // \u30D5\u30A3\u30DC\
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
    \ algorithm\n\n\n#line 6 \"test/aoj-ALDS1_10_A-kitamasa.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n\n    algorithm::Kitamasa kitamasa({1, 1},\
    \ {1, 1});\n    std::cout << kitamasa[n] << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_A\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/Algebra/kitamasa.hpp\"\n\nint\
    \ main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::Kitamasa kitamasa({1,\
    \ 1}, {1, 1});\n    std::cout << kitamasa[n] << std::endl;\n}\n"
  dependsOn:
  - lib/Math/Algebra/kitamasa.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_10_A-kitamasa.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 19:29:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ALDS1_10_A-kitamasa.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_10_A-kitamasa.test.cpp
- /verify/test/aoj-ALDS1_10_A-kitamasa.test.cpp.html
title: test/aoj-ALDS1_10_A-kitamasa.test.cpp
---
