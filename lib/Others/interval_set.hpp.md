---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2880-interval_set.test.cpp
    title: test/aoj-2880-interval_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Others/interval_set.hpp\"\n\n\n\n#include <cassert>\n\
    #include <initializer_list>\n#include <iostream>\n#include <iterator>\n#include\
    \ <limits>\n#include <set>\n#include <type_traits>\n#include <utility>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename T, typename std::enable_if_t<std::is_arithmetic<T>::value,\
    \ bool> = false>\nclass Interval {\n    T l, u;\n\npublic:\n    using value_type\
    \ = T;\n\n    Interval() : Interval(0, 0) {}\n    explicit constexpr Interval(T\
    \ l, T u) : l(l), u(u) {\n        assert(l <= u);\n    }\n\n    constexpr Interval\
    \ operator+=(T rhs) {\n        l += rhs, u += rhs;\n        return *this;\n  \
    \  }\n    constexpr Interval operator-=(T rhs) {\n        l -= rhs, u -= rhs;\n\
    \        return *this;\n    }\n    constexpr Interval operator*=(T rhs) {\n  \
    \      l *= rhs, u *= rhs;\n        return *this;\n    }\n    constexpr Interval\
    \ operator+=(const Interval &rhs) {\n        l += rhs.lower(), u += rhs.upper();\n\
    \        return *this;\n    }\n    constexpr Interval operator-=(const Interval\
    \ &rhs) {\n        l -= rhs.lower(), u -= rhs.upper();\n        return *this;\n\
    \    }\n    constexpr Interval operator*=(const Interval &rhs) { return *this\
    \ = *this * rhs; }\n\n    friend constexpr auto operator<=>(const Interval &lhs,\
    \ const Interval &rhs) = default;\n    friend constexpr Interval operator+(const\
    \ Interval &lhs, T rhs) { return Interval(lhs) += rhs; }\n    friend constexpr\
    \ Interval operator-(const Interval &lhs, T rhs) { return Interval(lhs) -= rhs;\
    \ }\n    friend constexpr Interval operator*(const Interval &lhs, T rhs) { return\
    \ Interval(lhs) *= rhs; }\n    friend constexpr Interval operator+(const Interval\
    \ &lhs, const Interval &rhs) { return Interval(lhs) += rhs; }\n    friend constexpr\
    \ Interval operator-(const Interval &lhs, const Interval &rhs) { return Interval(lhs)\
    \ -= rhs; }\n    friend constexpr Interval operator*(const Interval &lhs, const\
    \ Interval &rhs) {\n        return Interval(std::min({lhs.lower() * rhs.lower(),\
    \ lhs.lower() * rhs.upper(), lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}),\n\
    \                        std::max({lhs.lower() * rhs.lower(), lhs.lower() * rhs.upper(),\
    \ lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}));\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Interval &a) { return os <<\
    \ \"[\" << a.lower() << \", \" << a.upper() << \")\"; }\n\n    constexpr T lower()\
    \ const { return l; }\n    constexpr T upper() const { return u; }\n    constexpr\
    \ T width() const { return upper() - lower(); }\n    constexpr bool contains(T\
    \ x) const { return lower() <= x and x < upper(); }\n    constexpr int contains(const\
    \ Interval &a) const { return contains(a.lower(), a.upper()); }\n    constexpr\
    \ int contains(T l, T u) const {\n        if(l <= lower() and upper() <= u) return\
    \ 2;  // \u533A\u9593\u5168\u4F53\u3092\u542B\u3080\u5834\u5408\uFF0E\n      \
    \  if(upper() < l or u < lower()) return 0;     // \u542B\u307E\u306A\u3044\u5834\
    \u5408\uFF0E\n        return 1;                                    // \u533A\u9593\
    \u306E\u4E00\u90E8\u306E\u307F\u542B\u3080\u5834\u5408\uFF0E\n    }\n\n    friend\
    \ constexpr Interval overlap(const Interval &a, const Interval &b) {\n       \
    \ T l = std::max(a.lower(), b.lower());\n        T u = std::min(a.upper(), b.upper());\n\
    \        return (l <= u ? Interval(l, u) : Interval(u, u));\n    }\n};\n\ntemplate\
    \ <typename Type>\nconstexpr Interval<Type> overlap(std::initializer_list<Interval<Type>\
    \ > list) {\n    Interval<Type> res(std::numeric_limits<Type>::min(), std::numeric_limits<Type>::max());\n\
    \    for(const auto &elem : list) res = overlap(res, elem);\n    return res;\n\
    }\n\n// Interval Set\uFF08\u9023\u7D9A\u3057\u3066\u3044\u306A\u3044\u533A\u9593\
    \u3092\u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9\uFF09\ntemplate <typename T,\
    \ typename std::enable_if_t<std::is_arithmetic<T>::value, bool> = false>\nclass\
    \ IntervalSet {\npublic:\n    using interval = Interval<T>;\n\nprivate:\n    std::set<interval>\
    \ m_st;  // m_st:=(\u533A\u9593\u306E\u96C6\u5408).\n\npublic:\n    using iterator\
    \ = std::set<interval>::iterator;\n    using const_iterator = std::set<interval>::const_iterator;\n\
    \    using reverse_iterator = std::set<interval>::reverse_iterator;\n    using\
    \ const_reverse_iterator = std::set<interval>::const_reverse_iterator;\n\n   \
    \ IntervalSet() {\n        static_assert(min_limit() < max_limit());\n       \
    \ // \u756A\u5175\u3092\u914D\u7F6E\uFF0E\n        m_st.emplace(std::numeric_limits<T>::lowest(),\
    \ std::numeric_limits<T>::lowest());\n        m_st.emplace(std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::max());\n    }\n\n    static constexpr T min_limit()\
    \ { return std::numeric_limits<T>::lowest() + 1; }\n    static constexpr T max_limit()\
    \ { return std::numeric_limits<T>::max() - 1; }\n    // \u533A\u9593\u8FFD\u52A0\
    \uFF0EO(logN).\n    iterator insert(const interval &interval) { return insert(interval.lower(),\
    \ interval.upper()); }\n    iterator insert(T l, T r) {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        auto left = lower_bound(l);\n\
    \        auto right = upper_bound(r);\n        if(std::prev(left)->upper() ==\
    \ l) {\n            left--;\n            l = left->lower();\n        } else if(left->lower()\
    \ <= l) {\n            if(r <= left->upper()) return left;\n            l = left->lower();\n\
    \        }\n        if(r <= std::prev(right)->upper()) r = std::prev(right)->upper();\n\
    \        return m_st.emplace_hint(m_st.erase(left, right), l, r);\n    }\n   \
    \ // \u533A\u9593\u524A\u9664\uFF0EO(logN).\n    iterator erase(const interval\
    \ &interval) { return erase(interval.lower(), interval.upper()); }\n    iterator\
    \ erase(T l, T r) {\n        assert(min_limit() <= l and l < r and r <= max_limit());\n\
    \        auto left = lower_bound(l);\n        auto right = upper_bound(r);\n \
    \       T ll = left->lower(), rr = std::prev(right)->upper();\n        auto iter\
    \ = m_st.erase(left, right);\n        if(r < rr) iter = m_st.emplace_hint(iter,\
    \ r, rr);\n        if(ll < l) m_st.emplace_hint(iter, ll, l);\n        return\
    \ iter;\n    }\n    // \u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\
    \u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    bool contains(T x) const {\n     \
    \   assert(min_limit() <= x and x < max_limit());\n        auto iter = std::prev(upper_bound(x));\n\
    \        return iter->lower() <= x and x < iter->upper();\n    }\n    // \u96C6\
    \u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(logN).\n    int contains(const interval &interval) const { return contains(interval.lower(),\
    \ interval.upper()); }\n    int contains(T l, T r) const {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        auto left = lower_bound(l);\n\
    \        auto right = upper_bound(r);\n        if(left == right) return 0;   \
    \                                                        // \u542B\u307E\u306A\
    \u3044\u5834\u5408\uFF0E\n        if(left == std::prev(right) and left->lower()\
    \ <= l and r <= left->upper()) return 2;  // \u533A\u9593\u5168\u4F53\u3092\u542B\
    \u3080\u5834\u5408\uFF0E\n        return 1;                                  \
    \                                           // \u533A\u9593\u306E\u4E00\u90E8\u306E\
    \u307F\u542B\u3080\u5834\u5408\uFF0E\n    }\n    // x\u4EE5\u4E0A\u3067\u96C6\u5408\
    \u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024 (mex: Minimum EXcluded\
    \ value) \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T x) const {\n    \
    \    auto iter = lower_bound(x);\n        return (x < iter->upper() ? iter->upper()\
    \ : x);\n    }\n    void clear() { m_st.erase(begin(), end()); }\n\n    const_iterator\
    \ begin() const { return std::next(m_st.begin()); }\n    const_iterator cbegin()\
    \ const { return std::next(m_st.cbegin()); }\n    const_iterator end() const {\
    \ return std::prev(m_st.end()); }\n    const_iterator cend() const { return std::prev(m_st.cend());\
    \ }\n    const_reverse_iterator rbegin() const { return std::next(m_st.rbegin());\
    \ }\n    const_reverse_iterator crbegin() const { return std::next(m_st.crbegin());\
    \ }\n    const_reverse_iterator rend() const { return std::prev(m_st.rend());\
    \ }\n    const_reverse_iterator crend() const { return std::prev(m_st.crend());\
    \ }\n    const_iterator lower_bound(T x) const {\n        assert(min_limit() <=\
    \ x and x < max_limit());\n        auto iter = m_st.lower_bound(interval(x + 1,\
    \ x + 1));\n        auto pre = std::prev(iter);\n        return (x < pre->upper()\
    \ ? pre : iter);\n    }\n    const_iterator upper_bound(T x) const {\n       \
    \ assert(min_limit() <= x and x < max_limit());\n        return m_st.lower_bound(interval(x\
    \ + 1, x + 1));\n    }\n    iterator erase(const_iterator iter) { return m_st.erase(iter);\
    \ }\n    iterator erase(const_iterator l, const_iterator r) { return m_st.erase(l,\
    \ r); }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_INTERVAL_SET_HPP\n#define ALGORITHM_INTERVAL_SET_HPP 1\n\
    \n#include <cassert>\n#include <initializer_list>\n#include <iostream>\n#include\
    \ <iterator>\n#include <limits>\n#include <set>\n#include <type_traits>\n#include\
    \ <utility>\n\nnamespace algorithm {\n\ntemplate <typename T, typename std::enable_if_t<std::is_arithmetic<T>::value,\
    \ bool> = false>\nclass Interval {\n    T l, u;\n\npublic:\n    using value_type\
    \ = T;\n\n    Interval() : Interval(0, 0) {}\n    explicit constexpr Interval(T\
    \ l, T u) : l(l), u(u) {\n        assert(l <= u);\n    }\n\n    constexpr Interval\
    \ operator+=(T rhs) {\n        l += rhs, u += rhs;\n        return *this;\n  \
    \  }\n    constexpr Interval operator-=(T rhs) {\n        l -= rhs, u -= rhs;\n\
    \        return *this;\n    }\n    constexpr Interval operator*=(T rhs) {\n  \
    \      l *= rhs, u *= rhs;\n        return *this;\n    }\n    constexpr Interval\
    \ operator+=(const Interval &rhs) {\n        l += rhs.lower(), u += rhs.upper();\n\
    \        return *this;\n    }\n    constexpr Interval operator-=(const Interval\
    \ &rhs) {\n        l -= rhs.lower(), u -= rhs.upper();\n        return *this;\n\
    \    }\n    constexpr Interval operator*=(const Interval &rhs) { return *this\
    \ = *this * rhs; }\n\n    friend constexpr auto operator<=>(const Interval &lhs,\
    \ const Interval &rhs) = default;\n    friend constexpr Interval operator+(const\
    \ Interval &lhs, T rhs) { return Interval(lhs) += rhs; }\n    friend constexpr\
    \ Interval operator-(const Interval &lhs, T rhs) { return Interval(lhs) -= rhs;\
    \ }\n    friend constexpr Interval operator*(const Interval &lhs, T rhs) { return\
    \ Interval(lhs) *= rhs; }\n    friend constexpr Interval operator+(const Interval\
    \ &lhs, const Interval &rhs) { return Interval(lhs) += rhs; }\n    friend constexpr\
    \ Interval operator-(const Interval &lhs, const Interval &rhs) { return Interval(lhs)\
    \ -= rhs; }\n    friend constexpr Interval operator*(const Interval &lhs, const\
    \ Interval &rhs) {\n        return Interval(std::min({lhs.lower() * rhs.lower(),\
    \ lhs.lower() * rhs.upper(), lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}),\n\
    \                        std::max({lhs.lower() * rhs.lower(), lhs.lower() * rhs.upper(),\
    \ lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}));\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Interval &a) { return os <<\
    \ \"[\" << a.lower() << \", \" << a.upper() << \")\"; }\n\n    constexpr T lower()\
    \ const { return l; }\n    constexpr T upper() const { return u; }\n    constexpr\
    \ T width() const { return upper() - lower(); }\n    constexpr bool contains(T\
    \ x) const { return lower() <= x and x < upper(); }\n    constexpr int contains(const\
    \ Interval &a) const { return contains(a.lower(), a.upper()); }\n    constexpr\
    \ int contains(T l, T u) const {\n        if(l <= lower() and upper() <= u) return\
    \ 2;  // \u533A\u9593\u5168\u4F53\u3092\u542B\u3080\u5834\u5408\uFF0E\n      \
    \  if(upper() < l or u < lower()) return 0;     // \u542B\u307E\u306A\u3044\u5834\
    \u5408\uFF0E\n        return 1;                                    // \u533A\u9593\
    \u306E\u4E00\u90E8\u306E\u307F\u542B\u3080\u5834\u5408\uFF0E\n    }\n\n    friend\
    \ constexpr Interval overlap(const Interval &a, const Interval &b) {\n       \
    \ T l = std::max(a.lower(), b.lower());\n        T u = std::min(a.upper(), b.upper());\n\
    \        return (l <= u ? Interval(l, u) : Interval(u, u));\n    }\n};\n\ntemplate\
    \ <typename Type>\nconstexpr Interval<Type> overlap(std::initializer_list<Interval<Type>\
    \ > list) {\n    Interval<Type> res(std::numeric_limits<Type>::min(), std::numeric_limits<Type>::max());\n\
    \    for(const auto &elem : list) res = overlap(res, elem);\n    return res;\n\
    }\n\n// Interval Set\uFF08\u9023\u7D9A\u3057\u3066\u3044\u306A\u3044\u533A\u9593\
    \u3092\u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9\uFF09\ntemplate <typename T,\
    \ typename std::enable_if_t<std::is_arithmetic<T>::value, bool> = false>\nclass\
    \ IntervalSet {\npublic:\n    using interval = Interval<T>;\n\nprivate:\n    std::set<interval>\
    \ m_st;  // m_st:=(\u533A\u9593\u306E\u96C6\u5408).\n\npublic:\n    using iterator\
    \ = std::set<interval>::iterator;\n    using const_iterator = std::set<interval>::const_iterator;\n\
    \    using reverse_iterator = std::set<interval>::reverse_iterator;\n    using\
    \ const_reverse_iterator = std::set<interval>::const_reverse_iterator;\n\n   \
    \ IntervalSet() {\n        static_assert(min_limit() < max_limit());\n       \
    \ // \u756A\u5175\u3092\u914D\u7F6E\uFF0E\n        m_st.emplace(std::numeric_limits<T>::lowest(),\
    \ std::numeric_limits<T>::lowest());\n        m_st.emplace(std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::max());\n    }\n\n    static constexpr T min_limit()\
    \ { return std::numeric_limits<T>::lowest() + 1; }\n    static constexpr T max_limit()\
    \ { return std::numeric_limits<T>::max() - 1; }\n    // \u533A\u9593\u8FFD\u52A0\
    \uFF0EO(logN).\n    iterator insert(const interval &interval) { return insert(interval.lower(),\
    \ interval.upper()); }\n    iterator insert(T l, T r) {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        auto left = lower_bound(l);\n\
    \        auto right = upper_bound(r);\n        if(std::prev(left)->upper() ==\
    \ l) {\n            left--;\n            l = left->lower();\n        } else if(left->lower()\
    \ <= l) {\n            if(r <= left->upper()) return left;\n            l = left->lower();\n\
    \        }\n        if(r <= std::prev(right)->upper()) r = std::prev(right)->upper();\n\
    \        return m_st.emplace_hint(m_st.erase(left, right), l, r);\n    }\n   \
    \ // \u533A\u9593\u524A\u9664\uFF0EO(logN).\n    iterator erase(const interval\
    \ &interval) { return erase(interval.lower(), interval.upper()); }\n    iterator\
    \ erase(T l, T r) {\n        assert(min_limit() <= l and l < r and r <= max_limit());\n\
    \        auto left = lower_bound(l);\n        auto right = upper_bound(r);\n \
    \       T ll = left->lower(), rr = std::prev(right)->upper();\n        auto iter\
    \ = m_st.erase(left, right);\n        if(r < rr) iter = m_st.emplace_hint(iter,\
    \ r, rr);\n        if(ll < l) m_st.emplace_hint(iter, ll, l);\n        return\
    \ iter;\n    }\n    // \u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\
    \u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    bool contains(T x) const {\n     \
    \   assert(min_limit() <= x and x < max_limit());\n        auto iter = std::prev(upper_bound(x));\n\
    \        return iter->lower() <= x and x < iter->upper();\n    }\n    // \u96C6\
    \u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(logN).\n    int contains(const interval &interval) const { return contains(interval.lower(),\
    \ interval.upper()); }\n    int contains(T l, T r) const {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        auto left = lower_bound(l);\n\
    \        auto right = upper_bound(r);\n        if(left == right) return 0;   \
    \                                                        // \u542B\u307E\u306A\
    \u3044\u5834\u5408\uFF0E\n        if(left == std::prev(right) and left->lower()\
    \ <= l and r <= left->upper()) return 2;  // \u533A\u9593\u5168\u4F53\u3092\u542B\
    \u3080\u5834\u5408\uFF0E\n        return 1;                                  \
    \                                           // \u533A\u9593\u306E\u4E00\u90E8\u306E\
    \u307F\u542B\u3080\u5834\u5408\uFF0E\n    }\n    // x\u4EE5\u4E0A\u3067\u96C6\u5408\
    \u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024 (mex: Minimum EXcluded\
    \ value) \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T x) const {\n    \
    \    auto iter = lower_bound(x);\n        return (x < iter->upper() ? iter->upper()\
    \ : x);\n    }\n    void clear() { m_st.erase(begin(), end()); }\n\n    const_iterator\
    \ begin() const { return std::next(m_st.begin()); }\n    const_iterator cbegin()\
    \ const { return std::next(m_st.cbegin()); }\n    const_iterator end() const {\
    \ return std::prev(m_st.end()); }\n    const_iterator cend() const { return std::prev(m_st.cend());\
    \ }\n    const_reverse_iterator rbegin() const { return std::next(m_st.rbegin());\
    \ }\n    const_reverse_iterator crbegin() const { return std::next(m_st.crbegin());\
    \ }\n    const_reverse_iterator rend() const { return std::prev(m_st.rend());\
    \ }\n    const_reverse_iterator crend() const { return std::prev(m_st.crend());\
    \ }\n    const_iterator lower_bound(T x) const {\n        assert(min_limit() <=\
    \ x and x < max_limit());\n        auto iter = m_st.lower_bound(interval(x + 1,\
    \ x + 1));\n        auto pre = std::prev(iter);\n        return (x < pre->upper()\
    \ ? pre : iter);\n    }\n    const_iterator upper_bound(T x) const {\n       \
    \ assert(min_limit() <= x and x < max_limit());\n        return m_st.lower_bound(interval(x\
    \ + 1, x + 1));\n    }\n    iterator erase(const_iterator iter) { return m_st.erase(iter);\
    \ }\n    iterator erase(const_iterator l, const_iterator r) { return m_st.erase(l,\
    \ r); }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/interval_set.hpp
  requiredBy: []
  timestamp: '2025-01-17 09:47:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-2880-interval_set.test.cpp
documentation_of: lib/Others/interval_set.hpp
layout: document
title: "Interval Set\uFF08\u9023\u7D9A\u3057\u3066\u3044\u306A\u3044\u533A\u9593\u3092\
  \u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9\uFF09"
---


## 概要

連続していない区間を管理するクラス．
重複する区間を追加するとマージされる．

特に mex (Minimum EXcluded value) を効率的に求めることができる．

`IntervalSet` に関する操作と計算量は次の通り（ただし，$N$ は区間の数）．

| 操作       | 説明                                              | 計算量                |
| ---------- | ------------------------------------------------- | --------------------- |
| `insert`   | 区間追加                                          | $\mathcal{O}(\log N)$ |
| `erase`    | 区間削除                                          | $\mathcal{O}(\log N)$ |
| `contains` | 区間に含まれているか判定する                      | $\mathcal{O}(\log N)$ |
| `mex(x)`   | $x$ 以上の集合に含まれない最小の値 (mex) を求める | $\mathcal{O}(\log N)$ |


## 参考文献

1. "区間 (数学)". Wikipedia. <https://ja.wikipedia.org/wiki/区間_(数学)>.
2. "区間演算". Wikipedia. <https://ja.wikipedia.org/wiki/区間演算>.
3. "Mex (mathematics)". Wikipedia. <https://en.wikipedia.org/wiki/Mex_(mathematics)>.
4. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/10/11/125049>.
5. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ (2) + 区間 mex クエリ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2022/02/05/043902>.


## 問題

- "E - Mex and Update". AtCoder Beginner Contest 330. AtCoder. <https://atcoder.jp/contests/abc330/tasks/abc330_e>.
