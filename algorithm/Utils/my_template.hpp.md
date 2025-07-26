---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Utils/my_template.hpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    #define REP(i, n) for(int i = 0; i < (int)(n); ++i)\n#define RREP(i, n) for(int\
    \ i = (int)(n); i-- > 0;)\n#define FOR(i, l, r) for(int i = (int)(l); i < (int)(r);\
    \ ++i)\n#define RFOR(i, l, r) for(int i = (int)(r); i-- > (int)(l);)\n#define\
    \ ALL(v) std::begin(v), std::end(v)\nusing llong = long long;\nusing vi = std::vector<int>;\n\
    using vvi = std::vector<vi>;\nusing pii = std::pair<int, int>;\nusing namespace\
    \ std;\nconstexpr int INF = 1e9;\nconstexpr long long LINF = 1e18;\nconstexpr\
    \ double EPS = 1e-10;\nconstexpr int MOD = 998'244'353;\nconstexpr int MOD2 =\
    \ 1e9 + 7;\n\ntemplate <typename C, typename Tr, typename R, typename T = std::ranges::range_value_t<R>>\n\
    \    requires std::ranges::output_range<R, T>\ninline auto &operator>>(std::basic_istream<C,\
    \ Tr> &is, R &r) {\n    for(auto &elem : r) is >> elem;\n    return is;\n}\n\n\
    template <typename C, typename Tr, std::ranges::input_range R>\n    requires(!std::convertible_to<R,\
    \ const char *>)\ninline auto &operator<<(std::basic_ostream<C, Tr> &os, const\
    \ R &r) {\n    if(std::ranges::empty(r)) return os;\n    auto iter = std::ranges::cbegin(r);\n\
    \    const auto end = std::ranges::cend(r);\n    os << *iter++;\n    while(iter\
    \ != end) os << \" \" << *iter++;\n    return os;\n}\n\n\n"
  code: "#ifndef ALGORITHM_MY_TEMPLATE_HPP\n#define ALGORITHM_MY_TEMPLATE_HPP 1\n\n\
    #include <bits/stdc++.h>\n#define REP(i, n) for(int i = 0; i < (int)(n); ++i)\n\
    #define RREP(i, n) for(int i = (int)(n); i-- > 0;)\n#define FOR(i, l, r) for(int\
    \ i = (int)(l); i < (int)(r); ++i)\n#define RFOR(i, l, r) for(int i = (int)(r);\
    \ i-- > (int)(l);)\n#define ALL(v) std::begin(v), std::end(v)\nusing llong = long\
    \ long;\nusing vi = std::vector<int>;\nusing vvi = std::vector<vi>;\nusing pii\
    \ = std::pair<int, int>;\nusing namespace std;\nconstexpr int INF = 1e9;\nconstexpr\
    \ long long LINF = 1e18;\nconstexpr double EPS = 1e-10;\nconstexpr int MOD = 998'244'353;\n\
    constexpr int MOD2 = 1e9 + 7;\n\ntemplate <typename C, typename Tr, typename R,\
    \ typename T = std::ranges::range_value_t<R>>\n    requires std::ranges::output_range<R,\
    \ T>\ninline auto &operator>>(std::basic_istream<C, Tr> &is, R &r) {\n    for(auto\
    \ &elem : r) is >> elem;\n    return is;\n}\n\ntemplate <typename C, typename\
    \ Tr, std::ranges::input_range R>\n    requires(!std::convertible_to<R, const\
    \ char *>)\ninline auto &operator<<(std::basic_ostream<C, Tr> &os, const R &r)\
    \ {\n    if(std::ranges::empty(r)) return os;\n    auto iter = std::ranges::cbegin(r);\n\
    \    const auto end = std::ranges::cend(r);\n    os << *iter++;\n    while(iter\
    \ != end) os << \" \" << *iter++;\n    return os;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/my_template.hpp
  requiredBy: []
  timestamp: '2025-07-26 08:01:34+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Utils/my_template.hpp
layout: document
title: My Template
---
