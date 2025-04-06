---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Others/binary_search.hpp
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
    #include <iostream>\n#include <vector>\n\n#line 1 \"lib/Others/binary_search.hpp\"\
    \n\n\n\n#include <concepts>\n#include <functional>\n#include <type_traits>\n\n\
    namespace algorithm {\n\ntemplate <std::integral Type, class Eval>\nconstexpr\
    \ Type bisearch(Type ok, Type ng, Eval eval) {\n    static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(Type)>>);\n    while(ng - ok > 1) {\n        Type mid = ok\
    \ + (ng - ok) / 2;\n        (eval(mid) ? ok : ng) = mid;\n    }\n    return ng;\n\
    }\n\ntemplate <std::floating_point Type, class Eval>\nconstexpr Type bisearch(Type\
    \ ok, Type ng, Type eps, Eval eval) {\n    static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(Type)>>);\n    while(ng - ok > eps) {\n        Type mid =\
    \ ok + (ng - ok) / 2;\n        (eval(mid) ? ok : ng) = mid;\n    }\n    return\
    \ ng;\n}\n\n}  // namespace algorithm\n\n\n#line 7 \"verify/aoj-ALDS1_4_B-binary_search.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> s(n);\n\
    \    for(auto &elem : s) std::cin >> elem;\n\n    int q;\n    std::cin >> q;\n\
    \n    int ans = 0;\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \n        int l = algorithm::bisearch(-1, n, [&](int idx) -> bool {\n        \
    \    return s[idx] < t;\n        });\n        int r = algorithm::bisearch(-1,\
    \ n, [&](int idx) -> bool {\n            return s[idx] <= t;\n        });\n\n\
    \        if(r - l > 0) ++ans;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../lib/Others/binary_search.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> s(n);\n\
    \    for(auto &elem : s) std::cin >> elem;\n\n    int q;\n    std::cin >> q;\n\
    \n    int ans = 0;\n    while(q--) {\n        int t;\n        std::cin >> t;\n\
    \n        int l = algorithm::bisearch(-1, n, [&](int idx) -> bool {\n        \
    \    return s[idx] < t;\n        });\n        int r = algorithm::bisearch(-1,\
    \ n, [&](int idx) -> bool {\n            return s[idx] <= t;\n        });\n\n\
    \        if(r - l > 0) ++ans;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Others/binary_search.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_4_B-binary_search.test.cpp
  requiredBy: []
  timestamp: '2025-03-29 18:57:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_4_B-binary_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_4_B-binary_search.test.cpp
- /verify/verify/aoj-ALDS1_4_B-binary_search.test.cpp.html
title: verify/aoj-ALDS1_4_B-binary_search.test.cpp
---
