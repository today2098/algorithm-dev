---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Others/largest_rectangle.hpp
    title: "\u6700\u5927\u9577\u65B9\u5F62\u554F\u984C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B
  bundledCode: "#line 1 \"test/aoj-DPL_3_B-largest_rectangle.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 1 \"lib/Others/largest_rectangle.hpp\"\
    \n\n\n\n/**\n * @brief \u6700\u5927\u9577\u65B9\u5F62\u554F\u984C\n * @docs docs/Others/largest_rectangle.md\n\
    \ */\n\n#include <functional>\n#include <stack>\n#include <utility>\n#line 13\
    \ \"lib/Others/largest_rectangle.hpp\"\n\nnamespace algorithm {\n\n// \u6700\u5927\
    \u9577\u65B9\u5F62\u554F\u984C\uFF0E\n// \u5404i\u306B\u304A\u3044\u3066\uFF0C\
    comp(H[i], H[] within [l,r))==true \u3068\u306A\u308Bi\u3092\u542B\u3080\u6700\
    \u5927\u533A\u9593[l,r)\u3092\u6C42\u3081\u308B\uFF0EO(N).\ntemplate <typename\
    \ Type, class Compare = std::function<bool(const Type &, const Type &)> >\nstd::vector<std::pair<int,\
    \ int> > largest_rectangle(\n    const std::vector<Type> &h,\n    const Compare\
    \ &comp = [](const Type &a, const Type &b) -> bool { return a <= b; }) {\n   \
    \ const int n = h.size();\n    std::vector<std::pair<int, int> > res(n, {0, n});\
    \  // res[i]:=(pair of [l,r)).\n    std::stack<std::pair<Type, int> > st;\n  \
    \  // left side.\n    for(int i = 0; i < n; ++i) {\n        while(!st.empty()\
    \ and comp(h[i], st.top().first)) st.pop();\n        if(!st.empty()) res[i].first\
    \ = st.top().second + 1;\n        st.push({h[i], i});\n    }\n    // right side.\n\
    \    st = std::stack<std::pair<Type, int> >();\n    for(int i = n - 1; i >= 0;\
    \ --i) {\n        while(!st.empty() and comp(h[i], st.top().first)) st.pop();\n\
    \        if(!st.empty()) res[i].second = st.top().second;\n        st.push({h[i],\
    \ i});\n    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\n#line 8 \"\
    test/aoj-DPL_3_B-largest_rectangle.test.cpp\"\n\nint main() {\n    int h, w;\n\
    \    std::cin >> h >> w;\n\n    std::vector c(h, std::vector<char>(w));\n    for(int\
    \ i = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) std::cin >> c[i][j];\n\
    \    }\n\n    int ans = 0;\n    std::vector<int> height(w, 0);\n    for(int i\
    \ = 0; i < h; ++i) {\n        for(int j = 0; j < w; ++j) {\n            if(c[i][j]\
    \ == '0') height[j]++;\n            else height[j] = 0;\n        }\n\n       \
    \ auto &&ranges = algorithm::largest_rectangle(height);\n        for(int j = 0;\
    \ j < w; ++j) {\n            const auto &[l, r] = ranges[j];\n            auto\
    \ tmp = height[j] * (r - l);\n            ans = std::max(ans, tmp);\n        }\n\
    \    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../lib/Others/largest_rectangle.hpp\"\n\nint main() {\n    int h, w;\n    std::cin\
    \ >> h >> w;\n\n    std::vector c(h, std::vector<char>(w));\n    for(int i = 0;\
    \ i < h; ++i) {\n        for(int j = 0; j < w; ++j) std::cin >> c[i][j];\n   \
    \ }\n\n    int ans = 0;\n    std::vector<int> height(w, 0);\n    for(int i = 0;\
    \ i < h; ++i) {\n        for(int j = 0; j < w; ++j) {\n            if(c[i][j]\
    \ == '0') height[j]++;\n            else height[j] = 0;\n        }\n\n       \
    \ auto &&ranges = algorithm::largest_rectangle(height);\n        for(int j = 0;\
    \ j < w; ++j) {\n            const auto &[l, r] = ranges[j];\n            auto\
    \ tmp = height[j] * (r - l);\n            ans = std::max(ans, tmp);\n        }\n\
    \    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Others/largest_rectangle.hpp
  isVerificationFile: true
  path: test/aoj-DPL_3_B-largest_rectangle.test.cpp
  requiredBy: []
  timestamp: '2024-09-16 00:47:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DPL_3_B-largest_rectangle.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DPL_3_B-largest_rectangle.test.cpp
- /verify/test/aoj-DPL_3_B-largest_rectangle.test.cpp.html
title: test/aoj-DPL_3_B-largest_rectangle.test.cpp
---
