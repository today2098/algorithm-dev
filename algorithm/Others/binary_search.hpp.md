---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ALDS1_4_B-binary_search.test.cpp
    title: verify/aoj-ALDS1_4_B-binary_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Others/binary_search.hpp\"\n\n\n\n#include <cassert>\n\
    #include <concepts>\n#include <numeric>\n#include <type_traits>\n\nnamespace algorithm\
    \ {\n\ntemplate <std::integral Type, class Pred>\nconstexpr Type bisearch(Type\
    \ ok, Type ng, Pred pred) {\n    static_assert(std::is_invocable_r<bool, Pred,\
    \ Type>::value);\n    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n    while(ng\
    \ - ok > 1) {\n        Type mid = std::midpoint(ok, ng);\n        (pred(mid) ?\
    \ ok : ng) = mid;\n    }\n    return ng;\n}\n\ntemplate <std::floating_point Type,\
    \ class Pred>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, Pred pred)\
    \ {\n    static_assert(std::is_invocable_r<bool, Pred, Type>::value);\n    assert(ok\
    \ <= ng);\n    if(!pred(ok)) return ok;\n    while(ng - ok > eps) {\n        Type\
    \ mid = std::midpoint(ok, ng);\n        (pred(mid) ? ok : ng) = mid;\n    }\n\
    \    return ng;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_SEARCH_HPP\n#define ALGORITHM_BINARY_SEARCH_HPP\
    \ 1\n\n#include <cassert>\n#include <concepts>\n#include <numeric>\n#include <type_traits>\n\
    \nnamespace algorithm {\n\ntemplate <std::integral Type, class Pred>\nconstexpr\
    \ Type bisearch(Type ok, Type ng, Pred pred) {\n    static_assert(std::is_invocable_r<bool,\
    \ Pred, Type>::value);\n    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n\
    \    while(ng - ok > 1) {\n        Type mid = std::midpoint(ok, ng);\n       \
    \ (pred(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\ntemplate <std::floating_point\
    \ Type, class Pred>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, Pred\
    \ pred) {\n    static_assert(std::is_invocable_r<bool, Pred, Type>::value);\n\
    \    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n    while(ng - ok > eps)\
    \ {\n        Type mid = std::midpoint(ok, ng);\n        (pred(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ng;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Others/binary_search.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ALDS1_4_B-binary_search.test.cpp
documentation_of: algorithm/Others/binary_search.hpp
layout: document
redirect_from:
- /library/algorithm/Others/binary_search.hpp
- /library/algorithm/Others/binary_search.hpp.html
title: algorithm/Others/binary_search.hpp
---
