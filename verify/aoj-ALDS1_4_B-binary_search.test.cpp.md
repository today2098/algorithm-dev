---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Others/binary_search.hpp
    title: "Binary Search\uFF08\u4E8C\u5206\u63A2\u7D22\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"verify/aoj-ALDS1_4_B-binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"algorithm/Others/binary_search.hpp\"\
    \n\n\n\n#include <cassert>\n#include <concepts>\n#include <numeric>\n#include\
    \ <type_traits>\n\nnamespace algorithm {\n\ntemplate <std::integral Type, class\
    \ Pred>\nconstexpr Type bisearch(Type ok, Type ng, Pred pred) {\n    static_assert(std::is_invocable_r<bool,\
    \ Pred, Type>::value);\n    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n\
    \    while(ng - ok > 1) {\n        Type mid = std::midpoint(ok, ng);\n       \
    \ (pred(mid) ? ok : ng) = mid;\n    }\n    return ng;\n}\n\ntemplate <std::floating_point\
    \ Type, class Pred>\nconstexpr Type bisearch(Type ok, Type ng, Type eps, Pred\
    \ pred) {\n    static_assert(std::is_invocable_r<bool, Pred, Type>::value);\n\
    \    assert(ok <= ng);\n    if(!pred(ok)) return ok;\n    while(ng - ok > eps)\
    \ {\n        Type mid = std::midpoint(ok, ng);\n        (pred(mid) ? ok : ng)\
    \ = mid;\n    }\n    return ng;\n}\n\n}  // namespace algorithm\n\n\n#line 7 \"\
    verify/aoj-ALDS1_4_B-binary_search.test.cpp\"\n\nint main() {\n    int n;\n  \
    \  std::cin >> n;\n\n    std::vector<int> s(n);\n    for(auto &elem : s) std::cin\
    \ >> elem;\n\n    int q;\n    std::cin >> q;\n\n    int ans = 0;\n    while(q--)\
    \ {\n        int t;\n        std::cin >> t;\n\n        auto itr = algorithm::bisearch(0,\
    \ n, [&](int i) -> bool {\n            return s[i] < t;\n        });\n\n     \
    \   if(itr < n and s[itr] == t) ++ans;\n    }\n\n    std::cout << ans << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../algorithm/Others/binary_search.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> s(n);\n\
    \    for(auto &elem : s) std::cin >> elem;\n\n    int q;\n    std::cin >> q;\n\
    \n    int ans = 0;\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \n        auto itr = algorithm::bisearch(0, n, [&](int i) -> bool {\n        \
    \    return s[i] < t;\n        });\n\n        if(itr < n and s[itr] == t) ++ans;\n\
    \    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - algorithm/Others/binary_search.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_4_B-binary_search.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_4_B-binary_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_4_B-binary_search.test.cpp
- /verify/verify/aoj-ALDS1_4_B-binary_search.test.cpp.html
title: verify/aoj-ALDS1_4_B-binary_search.test.cpp
---
