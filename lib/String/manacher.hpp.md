---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-enumerate_palindromes-manacher.test.cpp
    title: verify/yosupo-enumerate_palindromes-manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/String/manacher.md
    document_title: "Manacher's Algorithm\uFF08\u6700\u9577\u56DE\u6587\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/String/manacher.hpp\"\n\n\n\n/**\n * @brief Manacher's\
    \ Algorithm\uFF08\u6700\u9577\u56DE\u6587\uFF09\n * @docs docs/String/manacher.md\n\
    \ */\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// Manacher's\
    \ Algorithm\uFF08\u6700\u9577\u56DE\u6587\uFF09.\ntemplate <class Sequence>\n\
    class Manacher {\n    int m_sz;  // m_sz:=(\u914D\u5217\u30B5\u30A4\u30BA).\n\
    \    // m_radius[2*k]:=(k\u6587\u5B57\u76EE\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u5947\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84),\n    // m_radius[2*k+1]:=(k\u6587\
    \u5B57\u76EE\u3068k+1\u6587\u5B57\u76EE\u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\
    \u308B\u5076\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84).\n \
    \   std::vector<int> m_radius;\n\npublic:\n    // constructor. \u5F15\u6570\u306F\
    STL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\uFF0EO(|S|).\n\
    \    Manacher() : Manacher(Sequence()) {}\n    explicit Manacher(const Sequence\
    \ &s) : m_sz(s.size()), m_radius(2 * s.size(), 0) {\n        if(size() == 0) return;\n\
    \        const int n = 2 * size() - 1;\n        Sequence t(n, 0);\n        for(int\
    \ i = 0; i < size(); ++i) t[2 * i] = s[i];\n        int i = 0, j = 0;\n      \
    \  while(i < n) {\n            while(0 <= i - j and i + j < n and t[i - j] ==\
    \ t[i + j]) j++;\n            m_radius[i] = j;\n            int k = 1;\n     \
    \       while(0 <= i - k and i + k < n and k + m_radius[i - k] < j) {\n      \
    \          m_radius[i + k] = m_radius[i - k];\n                k++;\n        \
    \    }\n            i += k, j -= k;\n        }\n    }\n\n    // \u914D\u5217\u306E\
    \u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz;\
    \ }\n    // k\u6587\u5B57\u76EE\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\
    \u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u8FD4\u3059\uFF0E\
    \n    int odd_radius(int k) const {\n        assert(0 <= k and k < size());\n\
    \        return (m_radius[2 * k] + 1) / 2;\n    }\n    // k\u6587\u5B57\u76EE\u3068\
    k+1\u6587\u5B57\u76EE\u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\
    \u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u8FD4\u3059\uFF0E\
    \n    int even_radius(int k) const {\n        assert(0 <= k and k < size() - 1);\n\
    \        return m_radius[2 * k + 1] / 2;\n    }\n    // \u90E8\u5206\u5217s[l:r]\u304C\
    \u56DE\u6587\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_palindrome(int l,\
    \ int r) const {\n        assert(0 <= l and l < r and r <= size());\n        int\
    \ mid = (l + r) / 2;\n        if((r - l) & 1) return odd_radius(mid) >= (r - l\
    \ + 1) / 2;\n        return even_radius(mid) >= (r - l) / 2;\n    }\n};\n\n} \
    \ // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MANACHER_HPP\n#define ALGORITHM_MANACHER_HPP 1\n\n/**\n\
    \ * @brief Manacher's Algorithm\uFF08\u6700\u9577\u56DE\u6587\uFF09\n * @docs\
    \ docs/String/manacher.md\n */\n\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Manacher's Algorithm\uFF08\u6700\u9577\u56DE\u6587\uFF09.\n\
    template <class Sequence>\nclass Manacher {\n    int m_sz;  // m_sz:=(\u914D\u5217\
    \u30B5\u30A4\u30BA).\n    // m_radius[2*k]:=(k\u6587\u5B57\u76EE\u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u5947\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\
    \u5F84),\n    // m_radius[2*k+1]:=(k\u6587\u5B57\u76EE\u3068k+1\u6587\u5B57\u76EE\
    \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\u9577\u306E\u6700\
    \u9577\u56DE\u6587\u306E\u534A\u5F84).\n    std::vector<int> m_radius;\n\npublic:\n\
    \    // constructor. \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\
    \u30B3\u30F3\u30C6\u30CA\uFF0EO(|S|).\n    Manacher() : Manacher(Sequence()) {}\n\
    \    explicit Manacher(const Sequence &s) : m_sz(s.size()), m_radius(2 * s.size(),\
    \ 0) {\n        if(size() == 0) return;\n        const int n = 2 * size() - 1;\n\
    \        Sequence t(n, 0);\n        for(int i = 0; i < size(); ++i) t[2 * i] =\
    \ s[i];\n        int i = 0, j = 0;\n        while(i < n) {\n            while(0\
    \ <= i - j and i + j < n and t[i - j] == t[i + j]) j++;\n            m_radius[i]\
    \ = j;\n            int k = 1;\n            while(0 <= i - k and i + k < n and\
    \ k + m_radius[i - k] < j) {\n                m_radius[i + k] = m_radius[i - k];\n\
    \                k++;\n            }\n            i += k, j -= k;\n        }\n\
    \    }\n\n    // \u914D\u5217\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n\
    \    int size() const { return m_sz; }\n    // k\u6587\u5B57\u76EE\u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\
    \u534A\u5F84\u3092\u8FD4\u3059\uFF0E\n    int odd_radius(int k) const {\n    \
    \    assert(0 <= k and k < size());\n        return (m_radius[2 * k] + 1) / 2;\n\
    \    }\n    // k\u6587\u5B57\u76EE\u3068k+1\u6587\u5B57\u76EE\u306E\u9593\u3092\
    \u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\
    \u306E\u534A\u5F84\u3092\u8FD4\u3059\uFF0E\n    int even_radius(int k) const {\n\
    \        assert(0 <= k and k < size() - 1);\n        return m_radius[2 * k + 1]\
    \ / 2;\n    }\n    // \u90E8\u5206\u5217s[l:r]\u304C\u56DE\u6587\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0E\n    bool is_palindrome(int l, int r) const {\n        assert(0\
    \ <= l and l < r and r <= size());\n        int mid = (l + r) / 2;\n        if((r\
    \ - l) & 1) return odd_radius(mid) >= (r - l + 1) / 2;\n        return even_radius(mid)\
    \ >= (r - l) / 2;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/String/manacher.hpp
  requiredBy: []
  timestamp: '2024-10-12 03:17:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-enumerate_palindromes-manacher.test.cpp
documentation_of: lib/String/manacher.hpp
layout: document
redirect_from:
- /library/lib/String/manacher.hpp
- /library/lib/String/manacher.hpp.html
title: "Manacher's Algorithm\uFF08\u6700\u9577\u56DE\u6587\uFF09"
---
## 概要

長さ $N$ の文字列 $S$ について，任意の位置を中心とする最長回文 (longest palindromic substring) の半径の長さを求める．

アルゴリズムの計算量は $\mathcal{O}(N)$ ．


## 参考文献

1. "Longest palindromic substring". Wikipedia. <https://en.wikipedia.org/wiki/Longest_palindromic_substring>.
1. "Manacher's Algorithm". Algorithms for Competitive Programming. <https://cp-algorithms.com/string/manacher.html>.


## 問題

- "B56 - Palindrome Queries". 競技プログラミングの鉄則 演習問題集. AtCoder. <https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_ec>.
