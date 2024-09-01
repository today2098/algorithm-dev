---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Utils/my_template.md
    document_title: My Template
    links: []
  bundledCode: "#line 1 \"lib/Utils/my_template.hpp\"\n\n\n\n/**\n * @brief My Template\n\
    \ * @docs docs/Utils/my_template.md\n */\n\n#include <bits/stdc++.h>\n#define\
    \ REP(i, n) for(int i = 0; i < (int)(n); ++i)\n#define FOR(i, l, r) for(int i\
    \ = (int)(l); i < (int)(r); ++i)\n#define ALL(v) (v).begin(), (v).end()\nusing\
    \ llong = long long;\nusing vi = std::vector<int>;\nusing vvi = std::vector<vi>;\n\
    using pii = std::pair<int, int>;\nusing namespace std;\nconstexpr int INF = 1e9;\n\
    constexpr long long LINF = 1e18;\nconstexpr double EPS = 1e-10;\nconstexpr int\
    \ MOD = 998'244'353;\nconstexpr int MOD2 = 1e9 + 7;\n\ntemplate <typename Type>\n\
    inline std::istream &operator>>(std::istream &is, std::vector<Type> &v) {\n  \
    \  for(Type &in : v) is >> in;\n    return is;\n}\n\ntemplate <typename Type>\n\
    inline std::ostream &operator<<(std::ostream &os, const std::vector<Type> &v)\
    \ {\n    for(auto itr = v.cbegin(); itr != v.cend(); ++itr) os << (itr == v.cbegin()\
    \ ? \"\" : \" \") << *itr;\n    return os;\n}\n\n\n"
  code: "#ifndef ALGORITHM_MY_TEMPLATE_HPP\n#define ALGORITHM_MY_TEMPLATE_HPP 1\n\n\
    /**\n * @brief My Template\n * @docs docs/Utils/my_template.md\n */\n\n#include\
    \ <bits/stdc++.h>\n#define REP(i, n) for(int i = 0; i < (int)(n); ++i)\n#define\
    \ FOR(i, l, r) for(int i = (int)(l); i < (int)(r); ++i)\n#define ALL(v) (v).begin(),\
    \ (v).end()\nusing llong = long long;\nusing vi = std::vector<int>;\nusing vvi\
    \ = std::vector<vi>;\nusing pii = std::pair<int, int>;\nusing namespace std;\n\
    constexpr int INF = 1e9;\nconstexpr long long LINF = 1e18;\nconstexpr double EPS\
    \ = 1e-10;\nconstexpr int MOD = 998'244'353;\nconstexpr int MOD2 = 1e9 + 7;\n\n\
    template <typename Type>\ninline std::istream &operator>>(std::istream &is, std::vector<Type>\
    \ &v) {\n    for(Type &in : v) is >> in;\n    return is;\n}\n\ntemplate <typename\
    \ Type>\ninline std::ostream &operator<<(std::ostream &os, const std::vector<Type>\
    \ &v) {\n    for(auto itr = v.cbegin(); itr != v.cend(); ++itr) os << (itr ==\
    \ v.cbegin() ? \"\" : \" \") << *itr;\n    return os;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/my_template.hpp
  requiredBy: []
  timestamp: '2024-09-01 18:20:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Utils/my_template.hpp
layout: document
redirect_from:
- /library/lib/Utils/my_template.hpp
- /library/lib/Utils/my_template.hpp.html
title: My Template
---
