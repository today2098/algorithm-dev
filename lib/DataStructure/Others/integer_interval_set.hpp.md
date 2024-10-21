---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2880-integer_interval_set.test.cpp
    title: test/aoj-2880-integer_interval_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/Others/integer_interval_set.md
    document_title: "Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\u3092\
      \u533A\u9593\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/Others/integer_interval_set.hpp\"\n\n\n\
    \n/**\n * @brief Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\u3092\
    \u533A\u9593\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09\
    \n * @docs docs/DataStructure/Others/integer_interval_set.md\n */\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <iterator>\n#include <limits>\n#include\
    \ <set>\n#include <type_traits>\n#include <utility>\n\nnamespace algorithm {\n\
    \n// Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\u3092\u533A\u9593\
    \u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09.\ntemplate\
    \ <typename T, typename std::enable_if_t<std::is_integral<T>::value, bool> = false>\n\
    class IntegerIntervalSet {\n    std::set<std::pair<T, T> > m_st;  // m_st:=(\u6574\
    \u6570\u306E\u96C6\u5408). \u9023\u7D9A\u3057\u3066\u3044\u308B\u533A\u9593[l,r)\u3092\
    pair(l,r)\u3067\u8868\u73FE\u3059\u308B\uFF0E\n\npublic:\n    IntegerIntervalSet()\
    \ {\n        static_assert(min_limit() < max_limit());\n        // \u756A\u5175\
    \u3092\u914D\u7F6E\uFF0E\n        m_st.emplace(min_limit() - 2, min_limit() -\
    \ 1);\n        m_st.emplace(max_limit() + 1, max_limit() + 2);\n    }\n\n    static\
    \ constexpr T min_limit() { return std::numeric_limits<T>::min() + 2; }\n    static\
    \ constexpr T max_limit() { return std::numeric_limits<T>::max() - 2; }\n    //\
    \ \u6574\u6570x\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(logN).\n    bool insert(T\
    \ x) { return insert(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\u6574\u6570\u3092\
    \u8FFD\u52A0\u3059\u308B\uFF0EO(logN).\n    bool insert(T l, T r) {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        auto iter1 = std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 1)));\n        auto [l1, r1] = *iter1;\n        if(r <= r1) return\
    \ false;  // \u5168\u3066\u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\
    \u5834\u5408\uFF0E\n        if(l <= r1) l = l1;\n        else iter1++;\n     \
    \   auto iter3 = m_st.lower_bound(std::pair<T, T>(r, r));\n        auto iter2\
    \ = std::prev(iter3);\n        auto [l2, r2] = *iter2;\n        auto [l3, r3]\
    \ = *iter3;\n        if(r == l3) {\n            m_st.erase(iter1, ++iter3);\n\
    \            m_st.emplace(l, r3);\n        } else {\n            m_st.erase(iter1,\
    \ iter3);\n            if(r <= r2) m_st.emplace(l, r2);\n            else m_st.emplace(l,\
    \ r);\n        }\n        return true;\n    }\n    // \u6574\u6570x\u3092\u524A\
    \u9664\u3059\u308B\uFF0EO(logN).\n    bool erase(T x) { return erase(x, x + 1);\
    \ }\n    // \u533A\u9593[l,r)\u306E\u6574\u6570\u3092\u524A\u9664\u3059\u308B\uFF0E\
    O(logN).\n    bool erase(T l, T r) {\n        assert(min_limit() <= l and l <\
    \ r and r <= max_limit());\n        auto iter1 = std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 1)));\n        auto iter3 = m_st.lower_bound(std::pair<T, T>(r,\
    \ r));\n        auto iter2 = std::prev(iter3);\n        auto [l1, r1] = *iter1;\n\
    \        auto [l2, r2] = *iter2;\n        if(l < r1) {\n            m_st.erase(iter1,\
    \ iter3);\n            if(l1 < l) m_st.emplace(l1, l);\n        } else {\n   \
    \         if(iter1 == iter2) return false;  // \u5168\u3066\u96C6\u5408\u306B\u542B\
    \u307E\u308C\u3066\u3044\u306A\u3044\u5834\u5408\uFF0E\n            m_st.erase(++iter1,\
    \ iter3);\n        }\n        if(r < r2) m_st.emplace(r, r2);\n        return\
    \ true;\n    }\n    // \u6574\u6570x\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    int contains(T\
    \ x) const { return contains(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\u6574\
    \u6570\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(logN).\n    int contains(T l, T r) const {\n       \
    \ assert(min_limit() <= l and l < r and r <= max_limit());\n        const auto\
    \ &[_, pr] = *std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));\n  \
    \      if(pr <= l) return 0;  // \u5168\u3066\u542B\u307E\u308C\u3066\u3044\u306A\
    \u3044\u5834\u5408\uFF0E\n        if(pr < r) return 1;   // \u4E00\u90E8\u306E\
    \u307F\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\uFF0E\n        return 2;\
    \              // \u5168\u3066\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\
    \uFF0E\n    }\n    // x\u4EE5\u4E0A\u306E\u6574\u6570\u3067\u96C6\u5408\u306B\u542B\
    \u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024 (mex: Minimum EXcluded value)\
    \ \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T x) const {\n        assert(min_limit()\
    \ <= x and x < max_limit());\n        const auto &[_, r] = *std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(x + 1, x + 1)));\n        return (x < r ? r : x);\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const IntegerIntervalSet &ob) {\n        os <<\
    \ \"[\";\n        const int n = ob.m_st.size();\n        int cnt = 0;\n      \
    \  for(auto iter = ob.m_st.cbegin(); iter != ob.m_st.cend(); ++iter) {\n     \
    \       if(0 < cnt and cnt < n - 1) {\n                const auto &[l, r] = *iter;\n\
    \                os << (cnt == 1 ? \"\" : \" \") << \"[\" << l << \", \" << r\
    \ << \")\";\n            }\n            cnt++;\n        }\n        os << \"]\"\
    ;\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_INTEGER_INTERVAL_SET_HPP\n#define ALGORITHM_INTEGER_INTERVAL_SET_HPP\
    \ 1\n\n/**\n * @brief Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\
    \u3092\u533A\u9593\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\
    \uFF09\n * @docs docs/DataStructure/Others/integer_interval_set.md\n */\n\n#include\
    \ <cassert>\n#include <iostream>\n#include <iterator>\n#include <limits>\n#include\
    \ <set>\n#include <type_traits>\n#include <utility>\n\nnamespace algorithm {\n\
    \n// Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\u3092\u533A\u9593\
    \u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09.\ntemplate\
    \ <typename T, typename std::enable_if_t<std::is_integral<T>::value, bool> = false>\n\
    class IntegerIntervalSet {\n    std::set<std::pair<T, T> > m_st;  // m_st:=(\u6574\
    \u6570\u306E\u96C6\u5408). \u9023\u7D9A\u3057\u3066\u3044\u308B\u533A\u9593[l,r)\u3092\
    pair(l,r)\u3067\u8868\u73FE\u3059\u308B\uFF0E\n\npublic:\n    IntegerIntervalSet()\
    \ {\n        static_assert(min_limit() < max_limit());\n        // \u756A\u5175\
    \u3092\u914D\u7F6E\uFF0E\n        m_st.emplace(min_limit() - 2, min_limit() -\
    \ 1);\n        m_st.emplace(max_limit() + 1, max_limit() + 2);\n    }\n\n    static\
    \ constexpr T min_limit() { return std::numeric_limits<T>::min() + 2; }\n    static\
    \ constexpr T max_limit() { return std::numeric_limits<T>::max() - 2; }\n    //\
    \ \u6574\u6570x\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(logN).\n    bool insert(T\
    \ x) { return insert(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\u6574\u6570\u3092\
    \u8FFD\u52A0\u3059\u308B\uFF0EO(logN).\n    bool insert(T l, T r) {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        auto iter1 = std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 1)));\n        auto [l1, r1] = *iter1;\n        if(r <= r1) return\
    \ false;  // \u5168\u3066\u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\
    \u5834\u5408\uFF0E\n        if(l <= r1) l = l1;\n        else iter1++;\n     \
    \   auto iter3 = m_st.lower_bound(std::pair<T, T>(r, r));\n        auto iter2\
    \ = std::prev(iter3);\n        auto [l2, r2] = *iter2;\n        auto [l3, r3]\
    \ = *iter3;\n        if(r == l3) {\n            m_st.erase(iter1, ++iter3);\n\
    \            m_st.emplace(l, r3);\n        } else {\n            m_st.erase(iter1,\
    \ iter3);\n            if(r <= r2) m_st.emplace(l, r2);\n            else m_st.emplace(l,\
    \ r);\n        }\n        return true;\n    }\n    // \u6574\u6570x\u3092\u524A\
    \u9664\u3059\u308B\uFF0EO(logN).\n    bool erase(T x) { return erase(x, x + 1);\
    \ }\n    // \u533A\u9593[l,r)\u306E\u6574\u6570\u3092\u524A\u9664\u3059\u308B\uFF0E\
    O(logN).\n    bool erase(T l, T r) {\n        assert(min_limit() <= l and l <\
    \ r and r <= max_limit());\n        auto iter1 = std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 1)));\n        auto iter3 = m_st.lower_bound(std::pair<T, T>(r,\
    \ r));\n        auto iter2 = std::prev(iter3);\n        auto [l1, r1] = *iter1;\n\
    \        auto [l2, r2] = *iter2;\n        if(l < r1) {\n            m_st.erase(iter1,\
    \ iter3);\n            if(l1 < l) m_st.emplace(l1, l);\n        } else {\n   \
    \         if(iter1 == iter2) return false;  // \u5168\u3066\u96C6\u5408\u306B\u542B\
    \u307E\u308C\u3066\u3044\u306A\u3044\u5834\u5408\uFF0E\n            m_st.erase(++iter1,\
    \ iter3);\n        }\n        if(r < r2) m_st.emplace(r, r2);\n        return\
    \ true;\n    }\n    // \u6574\u6570x\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    int contains(T\
    \ x) const { return contains(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\u6574\
    \u6570\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(logN).\n    int contains(T l, T r) const {\n       \
    \ assert(min_limit() <= l and l < r and r <= max_limit());\n        const auto\
    \ &[_, pr] = *std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));\n  \
    \      if(pr <= l) return 0;  // \u5168\u3066\u542B\u307E\u308C\u3066\u3044\u306A\
    \u3044\u5834\u5408\uFF0E\n        if(pr < r) return 1;   // \u4E00\u90E8\u306E\
    \u307F\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\uFF0E\n        return 2;\
    \              // \u5168\u3066\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\
    \uFF0E\n    }\n    // x\u4EE5\u4E0A\u306E\u6574\u6570\u3067\u96C6\u5408\u306B\u542B\
    \u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024 (mex: Minimum EXcluded value)\
    \ \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T x) const {\n        assert(min_limit()\
    \ <= x and x < max_limit());\n        const auto &[_, r] = *std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(x + 1, x + 1)));\n        return (x < r ? r : x);\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const IntegerIntervalSet &ob) {\n        os <<\
    \ \"[\";\n        const int n = ob.m_st.size();\n        int cnt = 0;\n      \
    \  for(auto iter = ob.m_st.cbegin(); iter != ob.m_st.cend(); ++iter) {\n     \
    \       if(0 < cnt and cnt < n - 1) {\n                const auto &[l, r] = *iter;\n\
    \                os << (cnt == 1 ? \"\" : \" \") << \"[\" << l << \", \" << r\
    \ << \")\";\n            }\n            cnt++;\n        }\n        os << \"]\"\
    ;\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/Others/integer_interval_set.hpp
  requiredBy: []
  timestamp: '2024-10-13 14:47:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-2880-integer_interval_set.test.cpp
documentation_of: lib/DataStructure/Others/integer_interval_set.hpp
layout: document
redirect_from:
- /library/lib/DataStructure/Others/integer_interval_set.hpp
- /library/lib/DataStructure/Others/integer_interval_set.hpp.html
title: "Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\u3092\u533A\u9593\
  \u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09"
---
## 概要

整数の集合を区間で管理するデータ構造．
特に mex (Minimum EXcluded value) を効率的に求めることができる．

このデータ構造は次のクエリ処理を $\mathcal{O}(\log{N})$ で行う．

- $\operatorname{insert}(l,r)$：区間 $[l,r)$ の整数を集合に追加する．
- $\operatorname{erase}(l,r)$：区間 $[l,r)$ の整数を集合から削除する．
- $\operatorname{contain}(l,r)$：区間 $[l,r)$ の整数が集合に含まれているか判定する．
- $\operatorname{mex}(x)$：$x$ 以上の整数で集合に含まれない最小の値 (mex) を求める．


## 参考文献

1. "Mex (mathematics)". Wikipedia. <https://en.wikipedia.org/wiki/Mex_(mathematics)>.
1. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/10/11/125049>.
1. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ (2) + 区間 mex クエリ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2022/02/05/043902>.


## 問題

- "E - Mex and Update". AtCoder Beginner Contest 330. AtCoder. <https://atcoder.jp/contests/abc330/tasks/abc330_e>.
