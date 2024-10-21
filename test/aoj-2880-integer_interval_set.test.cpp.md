---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/Others/integer_interval_set.hpp
    title: "Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\u3092\u533A\u9593\
      \u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\uFF09"
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
  bundledCode: "#line 1 \"test/aoj-2880-integer_interval_set.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <tuple>\n#include <vector>\n\n#line 1 \"lib/DataStructure/Others/integer_interval_set.hpp\"\
    \n\n\n\n/**\n * @brief Integer Interval Set\uFF08\u6574\u6570\u306E\u96C6\u5408\
    \u3092\u533A\u9593\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020\
    \uFF09\n * @docs docs/DataStructure/Others/integer_interval_set.md\n */\n\n#include\
    \ <cassert>\n#line 11 \"lib/DataStructure/Others/integer_interval_set.hpp\"\n\
    #include <iterator>\n#include <limits>\n#include <set>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace algorithm {\n\n// Integer Interval Set\uFF08\u6574\
    \u6570\u306E\u96C6\u5408\u3092\u533A\u9593\u3067\u7BA1\u7406\u3059\u308B\u30C7\
    \u30FC\u30BF\u69CB\u9020\uFF09.\ntemplate <typename T, typename std::enable_if_t<std::is_integral<T>::value,\
    \ bool> = false>\nclass IntegerIntervalSet {\n    std::set<std::pair<T, T> > m_st;\
    \  // m_st:=(\u6574\u6570\u306E\u96C6\u5408). \u9023\u7D9A\u3057\u3066\u3044\u308B\
    \u533A\u9593[l,r)\u3092pair(l,r)\u3067\u8868\u73FE\u3059\u308B\uFF0E\n\npublic:\n\
    \    IntegerIntervalSet() {\n        static_assert(min_limit() < max_limit());\n\
    \        // \u756A\u5175\u3092\u914D\u7F6E\uFF0E\n        m_st.emplace(min_limit()\
    \ - 2, min_limit() - 1);\n        m_st.emplace(max_limit() + 1, max_limit() +\
    \ 2);\n    }\n\n    static constexpr T min_limit() { return std::numeric_limits<T>::min()\
    \ + 2; }\n    static constexpr T max_limit() { return std::numeric_limits<T>::max()\
    \ - 2; }\n    // \u6574\u6570x\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(logN).\n \
    \   bool insert(T x) { return insert(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\
    \u6574\u6570\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(logN).\n    bool insert(T l,\
    \ T r) {\n        assert(min_limit() <= l and l < r and r <= max_limit());\n \
    \       auto iter1 = std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));\n\
    \        auto [l1, r1] = *iter1;\n        if(r <= r1) return false;  // \u5168\
    \u3066\u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\uFF0E\
    \n        if(l <= r1) l = l1;\n        else iter1++;\n        auto iter3 = m_st.lower_bound(std::pair<T,\
    \ T>(r, r));\n        auto iter2 = std::prev(iter3);\n        auto [l2, r2] =\
    \ *iter2;\n        auto [l3, r3] = *iter3;\n        if(r == l3) {\n          \
    \  m_st.erase(iter1, ++iter3);\n            m_st.emplace(l, r3);\n        } else\
    \ {\n            m_st.erase(iter1, iter3);\n            if(r <= r2) m_st.emplace(l,\
    \ r2);\n            else m_st.emplace(l, r);\n        }\n        return true;\n\
    \    }\n    // \u6574\u6570x\u3092\u524A\u9664\u3059\u308B\uFF0EO(logN).\n   \
    \ bool erase(T x) { return erase(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\u6574\
    \u6570\u3092\u524A\u9664\u3059\u308B\uFF0EO(logN).\n    bool erase(T l, T r) {\n\
    \        assert(min_limit() <= l and l < r and r <= max_limit());\n        auto\
    \ iter1 = std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));\n      \
    \  auto iter3 = m_st.lower_bound(std::pair<T, T>(r, r));\n        auto iter2 =\
    \ std::prev(iter3);\n        auto [l1, r1] = *iter1;\n        auto [l2, r2] =\
    \ *iter2;\n        if(l < r1) {\n            m_st.erase(iter1, iter3);\n     \
    \       if(l1 < l) m_st.emplace(l1, l);\n        } else {\n            if(iter1\
    \ == iter2) return false;  // \u5168\u3066\u96C6\u5408\u306B\u542B\u307E\u308C\
    \u3066\u3044\u306A\u3044\u5834\u5408\uFF0E\n            m_st.erase(++iter1, iter3);\n\
    \        }\n        if(r < r2) m_st.emplace(r, r2);\n        return true;\n  \
    \  }\n    // \u6574\u6570x\u304C\u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\
    \u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(logN).\n    int contains(T x) const\
    \ { return contains(x, x + 1); }\n    // \u533A\u9593[l,r)\u306E\u6574\u6570\u304C\
    \u96C6\u5408\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0EO(logN).\n    int contains(T l, T r) const {\n        assert(min_limit()\
    \ <= l and l < r and r <= max_limit());\n        const auto &[_, pr] = *std::prev(m_st.lower_bound(std::pair<T,\
    \ T>(l + 1, l + 1)));\n        if(pr <= l) return 0;  // \u5168\u3066\u542B\u307E\
    \u308C\u3066\u3044\u306A\u3044\u5834\u5408\uFF0E\n        if(pr < r) return 1;\
    \   // \u4E00\u90E8\u306E\u307F\u542B\u307E\u308C\u3066\u3044\u308B\u5834\u5408\
    \uFF0E\n        return 2;              // \u5168\u3066\u542B\u307E\u308C\u3066\
    \u3044\u308B\u5834\u5408\uFF0E\n    }\n    // x\u4EE5\u4E0A\u306E\u6574\u6570\u3067\
    \u96C6\u5408\u306B\u542B\u307E\u308C\u306A\u3044\u6700\u5C0F\u306E\u5024 (mex:\
    \ Minimum EXcluded value) \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T mex(T\
    \ x) const {\n        assert(min_limit() <= x and x < max_limit());\n        const\
    \ auto &[_, r] = *std::prev(m_st.lower_bound(std::pair<T, T>(x + 1, x + 1)));\n\
    \        return (x < r ? r : x);\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const IntegerIntervalSet &ob) {\n        os << \"[\";\n        const int\
    \ n = ob.m_st.size();\n        int cnt = 0;\n        for(auto iter = ob.m_st.cbegin();\
    \ iter != ob.m_st.cend(); ++iter) {\n            if(0 < cnt and cnt < n - 1) {\n\
    \                const auto &[l, r] = *iter;\n                os << (cnt == 1\
    \ ? \"\" : \" \") << \"[\" << l << \", \" << r << \")\";\n            }\n    \
    \        cnt++;\n        }\n        os << \"]\";\n        return os;\n    }\n\
    };\n\n}  // namespace algorithm\n\n\n#line 1 \"lib/Utils/debug.hpp\"\n\n\n\n/**\n\
    \ * @brief \u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED\
    \n * @docs docs/Utils/debug.md\n */\n\n#line 11 \"lib/Utils/debug.hpp\"\n#include\
    \ <queue>\n#include <stack>\n#include <string>\n#include <string_view>\n#line\
    \ 18 \"lib/Utils/debug.hpp\"\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...)\
    \ algorithm::debug::debug_internal(__LINE__, #__VA_ARGS__, __VA_ARGS__)\n\nnamespace\
    \ algorithm {\n\nnamespace debug {\n\nconstexpr std::ostream &os = std::clog;\n\
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
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 10 \"test/aoj-2880-integer_interval_set.test.cpp\"\
    \n\nint main() {\n    int n;\n    int m;\n    int q;\n    std::cin >> n >> m >>\
    \ q;\n\n    std::vector<std::tuple<int, int, int> > vt(m);\n    for(auto &[d,\
    \ a, b] : vt) std::cin >> d >> a >> b;\n    std::sort(vt.begin(), vt.end());\n\
    \    debug(vt);\n\n    std::vector<std::tuple<int, int, int, int> > query(q);\n\
    \    for(int i = 0; i < q; ++i) {\n        auto &[e, s, t, idx] = query[i];\n\
    \        std::cin >> e >> s >> t;\n        idx = i;\n    }\n    std::sort(query.begin(),\
    \ query.end());\n    debug(query);\n\n    std::vector<bool> ans(q);\n    algorithm::IntegerIntervalSet<int>\
    \ st;\n    int i = 0;\n    for(const auto &[e, s, t, idx] : query) {\n       \
    \ while(i < m) {\n            const auto &[d, a, b] = vt[i];\n            if(e\
    \ <= d) break;\n            st.insert(a, b);\n            i++;\n        }\n  \
    \      debug(e, st);\n\n        ans[idx] = (s >= t or st.contains(s, t) == 2);\n\
    \    }\n\n    for(auto elem : ans) std::cout << (elem ? \"Yes\" : \"No\") << \"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2880\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <tuple>\n#include <vector>\n\n#include\
    \ \"../lib/DataStructure/Others/integer_interval_set.hpp\"\n#include \"../lib/Utils/debug.hpp\"\
    \n\nint main() {\n    int n;\n    int m;\n    int q;\n    std::cin >> n >> m >>\
    \ q;\n\n    std::vector<std::tuple<int, int, int> > vt(m);\n    for(auto &[d,\
    \ a, b] : vt) std::cin >> d >> a >> b;\n    std::sort(vt.begin(), vt.end());\n\
    \    debug(vt);\n\n    std::vector<std::tuple<int, int, int, int> > query(q);\n\
    \    for(int i = 0; i < q; ++i) {\n        auto &[e, s, t, idx] = query[i];\n\
    \        std::cin >> e >> s >> t;\n        idx = i;\n    }\n    std::sort(query.begin(),\
    \ query.end());\n    debug(query);\n\n    std::vector<bool> ans(q);\n    algorithm::IntegerIntervalSet<int>\
    \ st;\n    int i = 0;\n    for(const auto &[e, s, t, idx] : query) {\n       \
    \ while(i < m) {\n            const auto &[d, a, b] = vt[i];\n            if(e\
    \ <= d) break;\n            st.insert(a, b);\n            i++;\n        }\n  \
    \      debug(e, st);\n\n        ans[idx] = (s >= t or st.contains(s, t) == 2);\n\
    \    }\n\n    for(auto elem : ans) std::cout << (elem ? \"Yes\" : \"No\") << \"\
    \\n\";\n}\n"
  dependsOn:
  - lib/DataStructure/Others/integer_interval_set.hpp
  - lib/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-2880-integer_interval_set.test.cpp
  requiredBy: []
  timestamp: '2024-10-22 02:31:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-2880-integer_interval_set.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-2880-integer_interval_set.test.cpp
- /verify/test/aoj-2880-integer_interval_set.test.cpp.html
title: test/aoj-2880-integer_interval_set.test.cpp
---
