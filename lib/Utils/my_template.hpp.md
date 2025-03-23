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
  bundledCode: "#line 1 \"lib/Utils/my_template.hpp\"\n\n\n\n#include <bits/stdc++.h>\n\
    #define REP(i, n) for(int i = 0; i < (int)(n); ++i)\n#define RREP(i, n) for(int\
    \ i = (int)(n); i-- > 0;)\n#define FOR(i, l, r) for(int i = (int)(l); i < (int)(r);\
    \ ++i)\n#define RFOR(i, r, l) for(int i = (int)(r); i-- > (int)(l);)\n#define\
    \ ALL(v) std::begin(v), std::end(v)\nusing llong = long long;\nusing vi = std::vector<int>;\n\
    using vvi = std::vector<vi>;\nusing pii = std::pair<int, int>;\nusing namespace\
    \ std;\nconstexpr int INF = 1e9;\nconstexpr long long LINF = 1e18;\nconstexpr\
    \ double EPS = 1e-10;\nconstexpr int MOD = 998'244'353;\nconstexpr int MOD2 =\
    \ 1e9 + 7;\n\ntemplate <typename Type>\ninline std::istream &operator>>(std::istream\
    \ &is, std::vector<Type> &v) {\n    for(auto &elem : v) is >> elem;\n    return\
    \ is;\n}\n\ntemplate <typename Type>\ninline std::ostream &operator<<(std::ostream\
    \ &os, const std::vector<Type> &v) {\n    for(auto iter = v.cbegin(); iter !=\
    \ v.cend(); ++iter) os << (iter == v.cbegin() ? \"\" : \" \") << *iter;\n    return\
    \ os;\n}\n\n\n"
  code: "#ifndef ALGORITHM_MY_TEMPLATE_HPP\n#define ALGORITHM_MY_TEMPLATE_HPP 1\n\n\
    #include <bits/stdc++.h>\n#define REP(i, n) for(int i = 0; i < (int)(n); ++i)\n\
    #define RREP(i, n) for(int i = (int)(n); i-- > 0;)\n#define FOR(i, l, r) for(int\
    \ i = (int)(l); i < (int)(r); ++i)\n#define RFOR(i, r, l) for(int i = (int)(r);\
    \ i-- > (int)(l);)\n#define ALL(v) std::begin(v), std::end(v)\nusing llong = long\
    \ long;\nusing vi = std::vector<int>;\nusing vvi = std::vector<vi>;\nusing pii\
    \ = std::pair<int, int>;\nusing namespace std;\nconstexpr int INF = 1e9;\nconstexpr\
    \ long long LINF = 1e18;\nconstexpr double EPS = 1e-10;\nconstexpr int MOD = 998'244'353;\n\
    constexpr int MOD2 = 1e9 + 7;\n\ntemplate <typename Type>\ninline std::istream\
    \ &operator>>(std::istream &is, std::vector<Type> &v) {\n    for(auto &elem :\
    \ v) is >> elem;\n    return is;\n}\n\ntemplate <typename Type>\ninline std::ostream\
    \ &operator<<(std::ostream &os, const std::vector<Type> &v) {\n    for(auto iter\
    \ = v.cbegin(); iter != v.cend(); ++iter) os << (iter == v.cbegin() ? \"\" : \"\
    \ \") << *iter;\n    return os;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/my_template.hpp
  requiredBy: []
  timestamp: '2025-03-23 14:11:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/my_template.hpp
layout: document
title: My Template
---
