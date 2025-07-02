---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/String/z_algorithm.hpp
    title: "Z algorithm\uFF08\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/yosupo-zalgorithm-z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <iostream>\n\
    #include <string>\n\n#line 1 \"algorithm/String/z_algorithm.hpp\"\n\n\n\n/**\n\
    \ * @brief Z algorithm\uFF08\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\uFF09\n\
    \ * @docs docs/String/z_algorithm.md\n */\n\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E (LCP: Longest Common Prefix)\
    \ \u306E\u9577\u3055\u3092\u6C42\u3081\u308B\uFF0E\n// \u5F15\u6570\u306FSTL\u306E\
    \u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\u3067\u3042\u308B\u3053\
    \u3068\uFF0EO(|S|).\ntemplate <class Sequence>\nstd::vector<int> z_algorithm(const\
    \ Sequence &s) {\n    const int n = s.size();\n    std::vector<int> z(n);  //\
    \ z[i]:=(s\u3068s[i:]\u306ELCP\u306E\u9577\u3055).\n    z[0] = n;\n    int i =\
    \ 1, j = 0;\n    while(i < n) {\n        while(i + j < n and s[j] == s[i + j])\
    \ j++;\n        z[i] = j;\n        if(j == 0) {\n            i++;\n          \
    \  continue;\n        }\n        int k = 1;\n        while(i + k < n and k + z[k]\
    \ < j) {\n            z[i + k] = z[k];\n            k++;\n        }\n        i\
    \ += k, j -= k;\n    }\n    return z;\n}\n\n}  // namespace algorithm\n\n\n#line\
    \ 7 \"verify/yosupo-zalgorithm-z_algorithm.test.cpp\"\n\nint main() {\n    std::string\
    \ s;\n    std::cin >> s;\n\n    auto &&z = algorithm::z_algorithm(s);\n\n    for(auto\
    \ elem : z) std::cout << elem << \" \";\n    std::cout << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <iostream>\n#include <string>\n\n#include \"../algorithm/String/z_algorithm.hpp\"\
    \n\nint main() {\n    std::string s;\n    std::cin >> s;\n\n    auto &&z = algorithm::z_algorithm(s);\n\
    \n    for(auto elem : z) std::cout << elem << \" \";\n    std::cout << std::endl;\n\
    }\n"
  dependsOn:
  - algorithm/String/z_algorithm.hpp
  isVerificationFile: true
  path: verify/yosupo-zalgorithm-z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-zalgorithm-z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-zalgorithm-z_algorithm.test.cpp
- /verify/verify/yosupo-zalgorithm-z_algorithm.test.cpp.html
title: verify/yosupo-zalgorithm-z_algorithm.test.cpp
---
