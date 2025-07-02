---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-2880-interval_set.test.cpp
    title: verify/aoj-2880-interval_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Others/interval_set.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <compare>\n#include <initializer_list>\n#include\
    \ <iostream>\n#include <iterator>\n#include <limits>\n#include <set>\n#include\
    \ <utility>\n\nnamespace algorithm {\n\nnamespace interval_set {\n\ntemplate <typename\
    \ T>\nclass Interval : public std::pair<T, T> {\npublic:\n    using value_type\
    \ = T;\n    using base_type = std::pair<value_type, value_type>;\n\n    constexpr\
    \ Interval() : Interval(0, 0) {}\n    constexpr Interval(const value_type &l,\
    \ const value_type &u) : base_type(l, u) {\n        assert(l <= u);\n    }\n \
    \   constexpr Interval(value_type &&l, value_type &&u) : base_type(std::move(l),\
    \ std::move(u)) {\n        assert(lower() <= upper());\n    }\n\n    friend constexpr\
    \ auto operator<=>(const Interval &lhs, const Interval &rhs) = default;\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Interval &interval) { return\
    \ os << \"[\" << interval.lower() << \", \" << interval.upper() << \")\"; }\n\n\
    \    static constexpr Interval all() { return {std::numeric_limits<value_type>::lowest(),\
    \ std::numeric_limits<value_type>::max()}; }\n    constexpr value_type lower()\
    \ const { return this->first; }\n    constexpr value_type upper() const { return\
    \ this->second; }\n    constexpr value_type width() const { return upper() - lower();\
    \ }\n    constexpr bool contains(const value_type &x) const { return lower() <=\
    \ x and x < upper(); }\n    constexpr int contains(const Interval &a) const {\
    \ return contains(a.lower(), a.upper()); }\n    constexpr int contains(const value_type\
    \ &l, const value_type &u) const {\n        if(lower() <= l and u <= upper())\
    \ return 2;  // \u533A\u9593[l,u)\u306E\u5168\u4F53\u3092\u542B\u3080\u5834\u5408\
    \uFF0E\n        if(u <= lower() or upper() <= l) return 0;   // \u533A\u9593[l,u)\u3092\
    \u542B\u307E\u306A\u3044\u5834\u5408\uFF0E\n        return 1;                \
    \                    // \u533A\u9593[l,u)\u306E\u4E00\u90E8\u306E\u307F\u542B\u3080\
    \u5834\u5408\uFF0E\n    }\n    constexpr Interval overlap(const Interval &a) const\
    \ { return overlap(a.lower(), a.upper()); }\n    constexpr Interval overlap(const\
    \ value_type &l, const value_type &u) const {\n        l = std::max(l, lower()),\
    \ u = std::min(u, upper());\n        return (l <= u ? Interval(l, u) : Interval(u,\
    \ u));\n    }\n};\n\ntemplate <typename Type>\nconstexpr Interval<Type> overlap(const\
    \ Interval<Type> &a, const Interval<Type> &b) { return a.overlap(b); }\n\ntemplate\
    \ <typename Type>\nconstexpr Interval<Type> overlap(std::initializer_list<Interval<Type>>\
    \ il) {\n    Interval<Type> res = Interval<Type>::all();\n    for(const auto &elem\
    \ : il) res = res.overlap(elem);\n    return res;\n}\n\n// Interval Set\uFF08\u533A\
    \u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09\
    .\ntemplate <typename T>\nclass IntervalSet {\npublic:\n    using value_type =\
    \ T;\n    using size_type = std::size_t;\n    using interval_type = Interval<value_type>;\n\
    \    using iterator = std::set<interval_type>::const_iterator;\n    using const_iterator\
    \ = std::set<interval_type>::const_iterator;\n    using reverse_iterator = std::set<interval_type>::const_reverse_iterator;\n\
    \    using const_reverse_iterator = std::set<interval_type>::const_reverse_iterator;\n\
    \nprivate:\n    std::set<interval_type> m_st;\n\n    iterator lower_bound_internal(const\
    \ value_type &l) const {\n        auto iter = upper_bound_internal(l);\n     \
    \   return (l < std::prev(iter)->upper() ? std::prev(iter) : iter);\n    }\n \
    \   iterator upper_bound_internal(const value_type &u) const { return m_st.lower_bound(interval_type(u,\
    \ u)); }\n\npublic:\n    IntervalSet() {\n        static_assert(lower_limit()\
    \ < upper_limit());\n        // \u756A\u5175\u3092\u914D\u7F6E\uFF0E\n       \
    \ m_st.emplace(lower_limit(), lower_limit());\n        m_st.emplace(upper_limit(),\
    \ upper_limit());\n    }\n\n    static constexpr value_type lower_limit() { return\
    \ std::numeric_limits<value_type>::lowest(); }\n    static constexpr value_type\
    \ upper_limit() { return std::numeric_limits<value_type>::max(); }\n\n    bool\
    \ empty() const { return size() == 0; }\n    size_type size() const { return m_st.size()\
    \ - 2; }\n\n    iterator insert(const interval_type &interval) { return insert(interval.lower(),\
    \ interval.upper()); }\n    iterator insert(value_type l, value_type u) {\n  \
    \      assert(lower_limit() < l and l <= u and u < upper_limit());\n        if(l\
    \ == u) return lower_bound_internal(l);\n        iterator left = lower_bound_internal(l);\n\
    \        if(std::prev(left)->upper() == l) --left;\n        if(left->lower() <\
    \ l) l = left->lower();\n        iterator right = upper_bound_internal(u);\n \
    \       if(right->lower() == u) ++right;\n        if(u < std::prev(right)->upper())\
    \ u = std::prev(right)->upper();\n        return m_st.emplace_hint(m_st.erase(left,\
    \ right), l, u);\n    }\n    iterator erase(const interval_type &interval) { return\
    \ erase(interval.lower(), interval.upper()); }\n    iterator erase(const value_type\
    \ &l, const value_type &u) {\n        assert(lower_limit() < l and l <= u and\
    \ u < upper_limit());\n        if(l == u) return lower_bound_internal(l);\n  \
    \      iterator left = lower_bound_internal(l);\n        iterator right = upper_bound_internal(u);\n\
    \        value_type ll = left->lower();\n        value_type uu = std::prev(right)->upper();\n\
    \        auto iter = m_st.erase(left, right);\n        if(u < uu) iter = m_st.emplace_hint(iter,\
    \ u, uu);\n        if(ll < l) m_st.emplace_hint(iter, ll, l);\n        return\
    \ iter;\n    }\n    iterator erase(iterator iter) { return m_st.erase(iter); }\n\
    \    iterator erase(iterator left, iterator right) { return m_st.erase(left, right);\
    \ }\n    void clear() { m_st.erase(begin(), end()); }\n\n    iterator lower_bound(const\
    \ value_type &l) const {\n        assert(lower_limit() < l and l < upper_limit());\n\
    \        return lower_bound_internal(l);\n    }\n    iterator upper_bound(const\
    \ value_type &u) const {\n        assert(lower_limit() < u and u < upper_limit());\n\
    \        return upper_bound_internal(u);\n    }\n    iterator find(const value_type\
    \ &x) const {\n        auto iter = lower_bound(x);\n        return (iter->contains(x)\
    \ ? iter : end());\n    }\n    std::pair<iterator, iterator> overlap_range(const\
    \ interval_type &interval) const { return overlap_range(interval.lower(), interval.upper());\
    \ }\n    std::pair<iterator, iterator> overlap_range(const value_type &l, const\
    \ value_type &u) const {\n        assert(lower_limit() < l and l <= u and u <\
    \ upper_limit());\n        return {lower_bound_internal(l), upper_bound_internal(u)};\n\
    \    }\n    bool contains(const value_type &x) const { return find(x) != end();\
    \ }\n    int contains(const interval_type &interval) const { return contains(interval.lower(),\
    \ interval.upper()); }\n    int contains(const value_type &l, const value_type\
    \ &u) const {\n        assert(lower_limit() < l and l <= u and u < upper_limit());\n\
    \        if(l == u) return 0;\n        return lower_bound_internal(l)->contains(l,\
    \ u);\n    }\n    // x\u4EE5\u4E0A\u3067\u96C6\u5408\u306B\u542B\u307E\u308C\u306A\
    \u3044\u6700\u5C0F\u306E\u5024 (mex: Minimum EXcluded value) \u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type mex(const value_type &x) const {\n     \
    \   auto iter = lower_bound(x);\n        return (iter->contains(x) ? iter->upper()\
    \ : x);\n    }\n\n    iterator begin() const { return std::next(m_st.begin());\
    \ }\n    iterator end() const { return std::prev(m_st.end()); }\n    iterator\
    \ cbegin() const { return std::next(m_st.cbegin()); }\n    iterator cend() const\
    \ { return std::prev(m_st.cend()); }\n    reverse_iterator rbegin() const { return\
    \ std::next(m_st.rbegin()); }\n    reverse_iterator rend() const { return std::prev(m_st.rend());\
    \ }\n    reverse_iterator crbegin() const { return std::next(m_st.crbegin());\
    \ }\n    reverse_iterator crend() const { return std::prev(m_st.crend()); }\n\
    };\n\n}  // namespace interval_set\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_INTERVAL_SET_HPP\n#define ALGORITHM_INTERVAL_SET_HPP 1\n\
    \n#include <algorithm>\n#include <cassert>\n#include <compare>\n#include <initializer_list>\n\
    #include <iostream>\n#include <iterator>\n#include <limits>\n#include <set>\n\
    #include <utility>\n\nnamespace algorithm {\n\nnamespace interval_set {\n\ntemplate\
    \ <typename T>\nclass Interval : public std::pair<T, T> {\npublic:\n    using\
    \ value_type = T;\n    using base_type = std::pair<value_type, value_type>;\n\n\
    \    constexpr Interval() : Interval(0, 0) {}\n    constexpr Interval(const value_type\
    \ &l, const value_type &u) : base_type(l, u) {\n        assert(l <= u);\n    }\n\
    \    constexpr Interval(value_type &&l, value_type &&u) : base_type(std::move(l),\
    \ std::move(u)) {\n        assert(lower() <= upper());\n    }\n\n    friend constexpr\
    \ auto operator<=>(const Interval &lhs, const Interval &rhs) = default;\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Interval &interval) { return\
    \ os << \"[\" << interval.lower() << \", \" << interval.upper() << \")\"; }\n\n\
    \    static constexpr Interval all() { return {std::numeric_limits<value_type>::lowest(),\
    \ std::numeric_limits<value_type>::max()}; }\n    constexpr value_type lower()\
    \ const { return this->first; }\n    constexpr value_type upper() const { return\
    \ this->second; }\n    constexpr value_type width() const { return upper() - lower();\
    \ }\n    constexpr bool contains(const value_type &x) const { return lower() <=\
    \ x and x < upper(); }\n    constexpr int contains(const Interval &a) const {\
    \ return contains(a.lower(), a.upper()); }\n    constexpr int contains(const value_type\
    \ &l, const value_type &u) const {\n        if(lower() <= l and u <= upper())\
    \ return 2;  // \u533A\u9593[l,u)\u306E\u5168\u4F53\u3092\u542B\u3080\u5834\u5408\
    \uFF0E\n        if(u <= lower() or upper() <= l) return 0;   // \u533A\u9593[l,u)\u3092\
    \u542B\u307E\u306A\u3044\u5834\u5408\uFF0E\n        return 1;                \
    \                    // \u533A\u9593[l,u)\u306E\u4E00\u90E8\u306E\u307F\u542B\u3080\
    \u5834\u5408\uFF0E\n    }\n    constexpr Interval overlap(const Interval &a) const\
    \ { return overlap(a.lower(), a.upper()); }\n    constexpr Interval overlap(const\
    \ value_type &l, const value_type &u) const {\n        l = std::max(l, lower()),\
    \ u = std::min(u, upper());\n        return (l <= u ? Interval(l, u) : Interval(u,\
    \ u));\n    }\n};\n\ntemplate <typename Type>\nconstexpr Interval<Type> overlap(const\
    \ Interval<Type> &a, const Interval<Type> &b) { return a.overlap(b); }\n\ntemplate\
    \ <typename Type>\nconstexpr Interval<Type> overlap(std::initializer_list<Interval<Type>>\
    \ il) {\n    Interval<Type> res = Interval<Type>::all();\n    for(const auto &elem\
    \ : il) res = res.overlap(elem);\n    return res;\n}\n\n// Interval Set\uFF08\u533A\
    \u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09\
    .\ntemplate <typename T>\nclass IntervalSet {\npublic:\n    using value_type =\
    \ T;\n    using size_type = std::size_t;\n    using interval_type = Interval<value_type>;\n\
    \    using iterator = std::set<interval_type>::const_iterator;\n    using const_iterator\
    \ = std::set<interval_type>::const_iterator;\n    using reverse_iterator = std::set<interval_type>::const_reverse_iterator;\n\
    \    using const_reverse_iterator = std::set<interval_type>::const_reverse_iterator;\n\
    \nprivate:\n    std::set<interval_type> m_st;\n\n    iterator lower_bound_internal(const\
    \ value_type &l) const {\n        auto iter = upper_bound_internal(l);\n     \
    \   return (l < std::prev(iter)->upper() ? std::prev(iter) : iter);\n    }\n \
    \   iterator upper_bound_internal(const value_type &u) const { return m_st.lower_bound(interval_type(u,\
    \ u)); }\n\npublic:\n    IntervalSet() {\n        static_assert(lower_limit()\
    \ < upper_limit());\n        // \u756A\u5175\u3092\u914D\u7F6E\uFF0E\n       \
    \ m_st.emplace(lower_limit(), lower_limit());\n        m_st.emplace(upper_limit(),\
    \ upper_limit());\n    }\n\n    static constexpr value_type lower_limit() { return\
    \ std::numeric_limits<value_type>::lowest(); }\n    static constexpr value_type\
    \ upper_limit() { return std::numeric_limits<value_type>::max(); }\n\n    bool\
    \ empty() const { return size() == 0; }\n    size_type size() const { return m_st.size()\
    \ - 2; }\n\n    iterator insert(const interval_type &interval) { return insert(interval.lower(),\
    \ interval.upper()); }\n    iterator insert(value_type l, value_type u) {\n  \
    \      assert(lower_limit() < l and l <= u and u < upper_limit());\n        if(l\
    \ == u) return lower_bound_internal(l);\n        iterator left = lower_bound_internal(l);\n\
    \        if(std::prev(left)->upper() == l) --left;\n        if(left->lower() <\
    \ l) l = left->lower();\n        iterator right = upper_bound_internal(u);\n \
    \       if(right->lower() == u) ++right;\n        if(u < std::prev(right)->upper())\
    \ u = std::prev(right)->upper();\n        return m_st.emplace_hint(m_st.erase(left,\
    \ right), l, u);\n    }\n    iterator erase(const interval_type &interval) { return\
    \ erase(interval.lower(), interval.upper()); }\n    iterator erase(const value_type\
    \ &l, const value_type &u) {\n        assert(lower_limit() < l and l <= u and\
    \ u < upper_limit());\n        if(l == u) return lower_bound_internal(l);\n  \
    \      iterator left = lower_bound_internal(l);\n        iterator right = upper_bound_internal(u);\n\
    \        value_type ll = left->lower();\n        value_type uu = std::prev(right)->upper();\n\
    \        auto iter = m_st.erase(left, right);\n        if(u < uu) iter = m_st.emplace_hint(iter,\
    \ u, uu);\n        if(ll < l) m_st.emplace_hint(iter, ll, l);\n        return\
    \ iter;\n    }\n    iterator erase(iterator iter) { return m_st.erase(iter); }\n\
    \    iterator erase(iterator left, iterator right) { return m_st.erase(left, right);\
    \ }\n    void clear() { m_st.erase(begin(), end()); }\n\n    iterator lower_bound(const\
    \ value_type &l) const {\n        assert(lower_limit() < l and l < upper_limit());\n\
    \        return lower_bound_internal(l);\n    }\n    iterator upper_bound(const\
    \ value_type &u) const {\n        assert(lower_limit() < u and u < upper_limit());\n\
    \        return upper_bound_internal(u);\n    }\n    iterator find(const value_type\
    \ &x) const {\n        auto iter = lower_bound(x);\n        return (iter->contains(x)\
    \ ? iter : end());\n    }\n    std::pair<iterator, iterator> overlap_range(const\
    \ interval_type &interval) const { return overlap_range(interval.lower(), interval.upper());\
    \ }\n    std::pair<iterator, iterator> overlap_range(const value_type &l, const\
    \ value_type &u) const {\n        assert(lower_limit() < l and l <= u and u <\
    \ upper_limit());\n        return {lower_bound_internal(l), upper_bound_internal(u)};\n\
    \    }\n    bool contains(const value_type &x) const { return find(x) != end();\
    \ }\n    int contains(const interval_type &interval) const { return contains(interval.lower(),\
    \ interval.upper()); }\n    int contains(const value_type &l, const value_type\
    \ &u) const {\n        assert(lower_limit() < l and l <= u and u < upper_limit());\n\
    \        if(l == u) return 0;\n        return lower_bound_internal(l)->contains(l,\
    \ u);\n    }\n    // x\u4EE5\u4E0A\u3067\u96C6\u5408\u306B\u542B\u307E\u308C\u306A\
    \u3044\u6700\u5C0F\u306E\u5024 (mex: Minimum EXcluded value) \u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type mex(const value_type &x) const {\n     \
    \   auto iter = lower_bound(x);\n        return (iter->contains(x) ? iter->upper()\
    \ : x);\n    }\n\n    iterator begin() const { return std::next(m_st.begin());\
    \ }\n    iterator end() const { return std::prev(m_st.end()); }\n    iterator\
    \ cbegin() const { return std::next(m_st.cbegin()); }\n    iterator cend() const\
    \ { return std::prev(m_st.cend()); }\n    reverse_iterator rbegin() const { return\
    \ std::next(m_st.rbegin()); }\n    reverse_iterator rend() const { return std::prev(m_st.rend());\
    \ }\n    reverse_iterator crbegin() const { return std::next(m_st.crbegin());\
    \ }\n    reverse_iterator crend() const { return std::prev(m_st.crend()); }\n\
    };\n\n}  // namespace interval_set\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Others/interval_set.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-2880-interval_set.test.cpp
documentation_of: algorithm/Others/interval_set.hpp
layout: document
redirect_from:
- /library/algorithm/Others/interval_set.hpp
- /library/algorithm/Others/interval_set.hpp.html
title: algorithm/Others/interval_set.hpp
---
