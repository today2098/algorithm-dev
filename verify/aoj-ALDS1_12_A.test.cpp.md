---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Graph/Others/prim.hpp
    title: "Prim's Algorithm\uFF08\u6700\u5C0F\u5168\u57DF\u6728\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_A
  bundledCode: "#line 1 \"verify/aoj-ALDS1_12_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_A\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/Graph/Others/prim.hpp\"\n\n\n\n/**\n\
    \ * @brief Prim's Algorithm\uFF08\u6700\u5C0F\u5168\u57DF\u6728\uFF09\n * @docs\
    \ docs/Graph/Others/prim.md\n */\n\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\ntemplate <typename T>\nclass Prim {\n    std::vector<std::vector<std::pair<int,\
    \ T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\
    \u30C8). pair of (to, cost).\n\npublic:\n    Prim() : Prim(0) {}\n    explicit\
    \ Prim(size_t vn) : m_g(vn) {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\
    \uFF0E\n    int order() const { return m_g.size(); }\n    // \u91CD\u307F\u4ED8\
    \u304D\u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int u, int\
    \ v, T cost) {\n        assert(0 <= u and u < order());\n        assert(0 <= v\
    \ and v < order());\n        m_g[u].emplace_back(v, cost);\n        m_g[v].emplace_back(u,\
    \ cost);\n    }\n    // \u91CD\u307F\u4ED8\u304D\u7121\u5411\u9023\u7D50\u30B0\
    \u30E9\u30D5\u306B\u304A\u3051\u308B\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8\u3092\u6C42\u3081\u308B\uFF0EO(|E|*log|V|).\n    T prim(int rt =\
    \ 0) {\n        assert(0 <= rt and rt < order());\n        T res = 0;\n      \
    \  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int> >, std::greater<std::pair<T,\
    \ int> > > pque;\n        pque.emplace(0, rt);\n        std::vector<bool> seen(order(),\
    \ false);\n        while(!pque.empty()) {\n            auto [cost, u] = pque.top();\n\
    \            pque.pop();\n            if(seen[u]) continue;\n            seen[u]\
    \ = true;\n            res += cost;\n            for(const auto &[v, cost] : m_g[u])\
    \ {\n                if(!seen[v]) pque.emplace(cost, v);\n            }\n    \
    \    }\n        return res;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 6 \"verify/aoj-ALDS1_12_A.test.cpp\"\n\nint main() {\n    int n;\n    std::cin\
    \ >> n;\n\n    algorithm::Prim<int> prim(n);\n    for(int i = 0; i < n; ++i) {\n\
    \        for(int j = 0; j < n; ++j) {\n            int a;\n            std::cin\
    \ >> a;\n\n            if(i < j and a != -1) prim.add_edge(i, j, a);\n       \
    \ }\n    }\n\n    auto ans = prim.prim();\n    std::cout << ans << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_A\"\
    \n\n#include <iostream>\n\n#include \"../lib/Graph/Others/prim.hpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n\n    algorithm::Prim<int> prim(n);\n   \
    \ for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < n; ++j) {\n       \
    \     int a;\n            std::cin >> a;\n\n            if(i < j and a != -1)\
    \ prim.add_edge(i, j, a);\n        }\n    }\n\n    auto ans = prim.prim();\n \
    \   std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Graph/Others/prim.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_12_A.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_12_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_12_A.test.cpp
- /verify/verify/aoj-ALDS1_12_A.test.cpp.html
title: verify/aoj-ALDS1_12_A.test.cpp
---
