---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Others/interval_set.hpp
    title: "Interval Set\uFF08\u9023\u7D9A\u3057\u3066\u3044\u306A\u3044\u533A\u9593\
      \u3092\u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9\uFF09"
  - icon: ':heavy_check_mark:'
    path: lib/Utils/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2880
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2880
  bundledCode: "#line 1 \"test/aoj-2880-interval_set.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <tuple>\n#include <vector>\n\n#line 1 \"lib/Others/interval_set.hpp\"\
    \n\n\n\n#include <cassert>\n#include <initializer_list>\n#line 7 \"lib/Others/interval_set.hpp\"\
    \n#include <iterator>\n#include <limits>\n#include <set>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace algorithm {\n\ntemplate <typename T, typename\
    \ std::enable_if_t<std::is_arithmetic<T>::value, bool> = false>\nclass Interval\
    \ {\n    T l, u;\n\npublic:\n    using value_type = T;\n\n    Interval() : Interval(0,\
    \ 0) {}\n    explicit constexpr Interval(T l, T u) : l(l), u(u) {\n        assert(l\
    \ <= u);\n    }\n\n    constexpr Interval operator+=(T rhs) {\n        l += rhs,\
    \ u += rhs;\n        return *this;\n    }\n    constexpr Interval operator-=(T\
    \ rhs) {\n        l -= rhs, u -= rhs;\n        return *this;\n    }\n    constexpr\
    \ Interval operator*=(T rhs) {\n        l *= rhs, u *= rhs;\n        return *this;\n\
    \    }\n    constexpr Interval operator+=(const Interval &rhs) {\n        l +=\
    \ rhs.lower(), u += rhs.upper();\n        return *this;\n    }\n    constexpr\
    \ Interval operator-=(const Interval &rhs) {\n        l -= rhs.lower(), u -= rhs.upper();\n\
    \        return *this;\n    }\n    constexpr Interval operator*=(const Interval\
    \ &rhs) { return *this = *this * rhs; }\n\n    friend constexpr auto operator<=>(const\
    \ Interval &lhs, const Interval &rhs) = default;\n    friend constexpr Interval\
    \ operator+(const Interval &lhs, T rhs) { return Interval(lhs) += rhs; }\n   \
    \ friend constexpr Interval operator-(const Interval &lhs, T rhs) { return Interval(lhs)\
    \ -= rhs; }\n    friend constexpr Interval operator*(const Interval &lhs, T rhs)\
    \ { return Interval(lhs) *= rhs; }\n    friend constexpr Interval operator+(const\
    \ Interval &lhs, const Interval &rhs) { return Interval(lhs) += rhs; }\n    friend\
    \ constexpr Interval operator-(const Interval &lhs, const Interval &rhs) { return\
    \ Interval(lhs) -= rhs; }\n    friend constexpr Interval operator*(const Interval\
    \ &lhs, const Interval &rhs) {\n        return Interval(std::min({lhs.lower()\
    \ * rhs.lower(), lhs.lower() * rhs.upper(), lhs.upper() * rhs.lower(), lhs.upper()\
    \ * rhs.upper()}),\n                        std::max({lhs.lower() * rhs.lower(),\
    \ lhs.lower() * rhs.upper(), lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}));\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const Interval &a)\
    \ { return os << \"[\" << a.lower() << \", \" << a.upper() << \")\"; }\n\n   \
    \ constexpr T lower() const { return l; }\n    constexpr T upper() const { return\
    \ u; }\n    constexpr T width() const { return upper() - lower(); }\n    constexpr\
    \ bool contains(T x) const { return lower() <= x and x < upper(); }\n    constexpr\
    \ int contains(const Interval &a) const { return contains(a.lower(), a.upper());\
    \ }\n    constexpr int contains(T l, T u) const {\n        if(l <= lower() and\
    \ upper() <= u) return 2;  // \u533A\u9593\u5168\u4F53\u3092\u542B\u3080\u5834\
    \u5408\uFF0E\n        if(upper() < l or u < lower()) return 0;     // \u542B\u307E\
    \u306A\u3044\u5834\u5408\uFF0E\n        return 1;                            \
    \        // \u533A\u9593\u306E\u4E00\u90E8\u306E\u307F\u542B\u3080\u5834\u5408\
    \uFF0E\n    }\n\n    friend constexpr Interval overlap(const Interval &a, const\
    \ Interval &b) {\n        T l = std::max(a.lower(), b.lower());\n        T u =\
    \ std::min(a.upper(), b.upper());\n        return (l <= u ? Interval(l, u) : Interval(u,\
    \ u));\n    }\n};\n\ntemplate <typename Type>\nconstexpr Interval<Type> overlap(std::initializer_list<Interval<Type>\
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
    \ r); }\n};\n\n}  // namespace algorithm\n\n\n#line 1 \"lib/Utils/debug.hpp\"\n\
    \n\n\n/**\n * @brief \u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\
    \u30AF\u30ED\n * @docs docs/Utils/debug.md\n */\n\n#line 11 \"lib/Utils/debug.hpp\"\
    \n#include <queue>\n#include <stack>\n#include <string>\n#include <string_view>\n\
    #line 18 \"lib/Utils/debug.hpp\"\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define\
    \ debug(...) algorithm::debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)\n\
    \nnamespace algorithm {\n\nnamespace debug {\n\nconstexpr std::ostream &os = std::clog;\n\
    \nstruct has_iterator_impl {\n    template <class T>\n    static constexpr std::true_type\
    \ check(typename T::iterator *);\n\n    template <class T>\n    static constexpr\
    \ std::false_type check(...);\n};\n\ntemplate <class T>\nclass has_iterator :\
    \ public decltype(has_iterator_impl::check<T>(nullptr)) {};\n\n// Prototype declaration.\n\
    void print(const std::string &s);\nvoid print(std::string_view s);\ntemplate <typename\
    \ T, typename U>\nvoid print(const std::pair<T, U> &p);\ntemplate <class T, std::size_t...\
    \ Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\ntemplate\
    \ <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st);\ntemplate <typename... Ts>\nvoid\
    \ print(const std::queue<Ts...> &que);\ntemplate <typename... Ts>\nvoid print(const\
    \ std::priority_queue<Ts...> &pque);\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(std::string_view\
    \ s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes\
    \ == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n\
    }\n\ntemplate <typename... Ts>\nvoid print(const std::tuple<Ts...> &t) {\n   \
    \ print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());\n}\n\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st) {\n    std::stack<Ts...> tmp =\
    \ st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Ts>\nvoid print(const std::queue<Ts...> &que)\
    \ {\n    std::queue<Ts...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Ts>\nvoid\
    \ print(const std::priority_queue<Ts...> &pque) {\n    std::priority_queue<Ts...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> >\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr = std::begin(v);\
    \ itr != std::end(v); ++itr) {\n        if(itr != std::begin(v)) os << \" \";\n\
    \        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename T, typename\
    \ std::enable_if_t<!has_iterator<T>::value, bool> >\nvoid print(const T &elem)\
    \ { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 10 \"test/aoj-2880-interval_set.test.cpp\"\
    \n\nint main() {\n    int n;\n    int m;\n    int q;\n    std::cin >> n >> m >>\
    \ q;\n\n    std::vector<std::tuple<int, int, int> > vt(m);\n    for(auto &[d,\
    \ a, b] : vt) std::cin >> d >> a >> b;\n    std::sort(vt.begin(), vt.end());\n\
    \    debug(vt);\n\n    std::vector<std::tuple<int, int, int, int> > query(q);\n\
    \    for(int i = 0; i < q; ++i) {\n        auto &[e, s, t, idx] = query[i];\n\
    \        std::cin >> e >> s >> t;\n        idx = i;\n    }\n    std::sort(query.begin(),\
    \ query.end());\n    debug(query);\n\n    std::vector<bool> ans(q);\n    algorithm::IntervalSet<int>\
    \ st;\n    int i = 0;\n    for(const auto &[e, s, t, idx] : query) {\n       \
    \ while(i < m) {\n            const auto &[d, a, b] = vt[i];\n            if(e\
    \ <= d) break;\n            st.insert(a, b);\n            debug(d, a, b, st);\n\
    \            i++;\n        }\n\n        ans[idx] = (s >= t or st.contains(s, t)\
    \ == 2);\n        debug(e, s, t, st, idx, ans[idx]);\n    }\n\n    for(auto elem\
    \ : ans) std::cout << (elem ? \"Yes\" : \"No\") << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <tuple>\n#include <vector>\n\n#include\
    \ \"../lib/Others/interval_set.hpp\"\n#include \"../lib/Utils/debug.hpp\"\n\n\
    int main() {\n    int n;\n    int m;\n    int q;\n    std::cin >> n >> m >> q;\n\
    \n    std::vector<std::tuple<int, int, int> > vt(m);\n    for(auto &[d, a, b]\
    \ : vt) std::cin >> d >> a >> b;\n    std::sort(vt.begin(), vt.end());\n    debug(vt);\n\
    \n    std::vector<std::tuple<int, int, int, int> > query(q);\n    for(int i =\
    \ 0; i < q; ++i) {\n        auto &[e, s, t, idx] = query[i];\n        std::cin\
    \ >> e >> s >> t;\n        idx = i;\n    }\n    std::sort(query.begin(), query.end());\n\
    \    debug(query);\n\n    std::vector<bool> ans(q);\n    algorithm::IntervalSet<int>\
    \ st;\n    int i = 0;\n    for(const auto &[e, s, t, idx] : query) {\n       \
    \ while(i < m) {\n            const auto &[d, a, b] = vt[i];\n            if(e\
    \ <= d) break;\n            st.insert(a, b);\n            debug(d, a, b, st);\n\
    \            i++;\n        }\n\n        ans[idx] = (s >= t or st.contains(s, t)\
    \ == 2);\n        debug(e, s, t, st, idx, ans[idx]);\n    }\n\n    for(auto elem\
    \ : ans) std::cout << (elem ? \"Yes\" : \"No\") << \"\\n\";\n}\n"
  dependsOn:
  - lib/Others/interval_set.hpp
  - lib/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-2880-interval_set.test.cpp
  requiredBy: []
  timestamp: '2025-01-17 09:47:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-2880-interval_set.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-2880-interval_set.test.cpp
- /verify/test/aoj-2880-interval_set.test.cpp.html
title: test/aoj-2880-interval_set.test.cpp
---
