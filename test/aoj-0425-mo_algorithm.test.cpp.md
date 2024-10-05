---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Others/mo_algorithm.hpp
    title: "Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425
  bundledCode: "#line 1 \"test/aoj-0425-mo_algorithm.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425\"\n\n#include\
    \ <iostream>\n#include <numeric>\n#include <utility>\n#include <vector>\n\n#line\
    \ 1 \"lib/Others/mo_algorithm.hpp\"\n\n\n\n/**\n * @brief Mo's Algorithm\uFF08\
    \u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09\n * @docs docs/Others/mo_algorithm.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <tuple>\n\
    #line 14 \"lib/Others/mo_algorithm.hpp\"\n\nnamespace algorithm {\n\n// Mo's Algorithm\uFF08\
    \u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09.\nclass Mo {\n    int m_len;\
    \                                          // m_len:=(\u533A\u9593\u306E\u9577\
    \u3055).\n    int m_q;                                            // m_q:=(\u30AF\
    \u30A8\u30EA\u6570).\n    std::vector<std::tuple<int, int, int> > m_queries; \
    \ // m_queries[i]:=(i\u756A\u76EE\u306E\u533A\u9593\u30AF\u30A8\u30EA). tuple\
    \ of (left, right, index).\n\n    void sort_queries() {\n        if(m_q == 0)\
    \ return;\n        const int width = std::max(m_len / (int)std::sqrt(m_q), 1);\
    \  // width:=N/\u221AQ.\n        std::sort(m_queries.begin(), m_queries.end(),\
    \ [&width](const std::tuple<int, int, int> &a, const std::tuple<int, int, int>\
    \ &b) -> bool {\n            const auto &[al, ar, _] = a;\n            const auto\
    \ &[bl, br, __] = b;\n            int a_block = al / width, b_block = bl / width;\n\
    \            if(a_block == b_block) return (a_block & 1 ? ar > br : ar < br);\n\
    \            return a_block < b_block;\n        });\n    }\n\npublic:\n    Mo()\
    \ : Mo(0) {}\n    explicit Mo(size_t n) : m_len(n), m_q(0) {}\n    explicit Mo(size_t\
    \ n, size_t q) : Mo(n) {\n        m_queries.reserve(q);\n    }\n\n    // \u533A\
    \u9593[l,r)\u306B\u3064\u3044\u3066\u306E\u30AF\u30A8\u30EA\u3092\u8FFD\u52A0\u3059\
    \u308B\uFF0E\n    void insert(int l, int r) {\n        assert(0 <= l and l < r\
    \ and r <= m_len);\n        m_queries.emplace_back(l, r, m_q++);\n    }\n    //\
    \ \u5404\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\uFF0EO(Q*logQ+\u03B1\
    *N*\u221AQ).\n    template <class F1, class F2, class F3>\n    void execute(const\
    \ F1 &add, const F2 &del, const F3 &solve) { execute(add, del, add, del, solve);\
    \ }\n    template <class F1, class F2, class F3, class F4, class F5>\n    void\
    \ execute(const F1 &add_l, const F2 &del_l, const F3 &add_r, const F4 &del_r,\
    \ const F5 &solve) {\n        sort_queries();\n        int l = 0, r = 0;\n   \
    \     for(const auto &[nl, nr, idx] : m_queries) {\n            while(nl < l)\
    \ add_l(--l);\n            while(r < nr) add_r(r++);\n            while(l < nl)\
    \ del_l(l++);\n            while(nr < r) del_r(--r);\n            solve(idx);\n\
    \        }\n    }\n    void reset() {\n        m_queries.clear();\n        m_q\
    \ = 0;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 9 \"test/aoj-0425-mo_algorithm.test.cpp\"\
    \n\nint main() {\n    int n;\n    int k;\n    int q;\n    std::cin >> n >> k >>\
    \ q;\n\n    std::vector<std::pair<int, int> > vp(k);\n    for(auto &[a, b] : vp)\
    \ {\n        std::cin >> a >> b;\n        a--, b--;\n    }\n\n    std::vector<std::pair<int,\
    \ int> > queries(q);\n    algorithm::Mo mo(k, q);\n    for(int i = 0; i < q; ++i)\
    \ {\n        int type;\n        int s, t;\n        int x;\n        std::cin >>\
    \ type >> s >> t >> x;\n        s--, x--;\n\n        queries[i] = std::pair<int,\
    \ int>(type, x);\n        mo.insert(s, t);\n    }\n\n    std::vector<int> ans(q);\n\
    \    std::vector<int> alpha(n), inv(n);\n    std::iota(alpha.begin(), alpha.end(),\
    \ 0);\n    std::iota(inv.begin(), inv.end(), 0);\n    auto swap_l = [&](int itr)\
    \ -> void {\n        const auto &[a, b] = vp[itr];\n        std::swap(alpha[inv[a]],\
    \ alpha[inv[b]]);\n        std::swap(inv[a], inv[b]);\n    };\n    auto swap_r\
    \ = [&](int itr) -> void {\n        const auto &[a, b] = vp[itr];\n        std::swap(inv[alpha[a]],\
    \ inv[alpha[b]]);\n        std::swap(alpha[a], alpha[b]);\n    };\n    auto solve\
    \ = [&](int idx) -> void {\n        const auto &[type, x] = queries[idx];\n  \
    \      ans[idx] = (type == 1 ? alpha[x] + 1 : inv[x] + 1);\n    };\n    mo.execute(swap_l,\
    \ swap_l, swap_r, swap_r, solve);\n\n    for(auto elem : ans) std::cout << elem\
    \ << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <utility>\n#include <vector>\n\
    \n#include \"../lib/Others/mo_algorithm.hpp\"\n\nint main() {\n    int n;\n  \
    \  int k;\n    int q;\n    std::cin >> n >> k >> q;\n\n    std::vector<std::pair<int,\
    \ int> > vp(k);\n    for(auto &[a, b] : vp) {\n        std::cin >> a >> b;\n \
    \       a--, b--;\n    }\n\n    std::vector<std::pair<int, int> > queries(q);\n\
    \    algorithm::Mo mo(k, q);\n    for(int i = 0; i < q; ++i) {\n        int type;\n\
    \        int s, t;\n        int x;\n        std::cin >> type >> s >> t >> x;\n\
    \        s--, x--;\n\n        queries[i] = std::pair<int, int>(type, x);\n   \
    \     mo.insert(s, t);\n    }\n\n    std::vector<int> ans(q);\n    std::vector<int>\
    \ alpha(n), inv(n);\n    std::iota(alpha.begin(), alpha.end(), 0);\n    std::iota(inv.begin(),\
    \ inv.end(), 0);\n    auto swap_l = [&](int itr) -> void {\n        const auto\
    \ &[a, b] = vp[itr];\n        std::swap(alpha[inv[a]], alpha[inv[b]]);\n     \
    \   std::swap(inv[a], inv[b]);\n    };\n    auto swap_r = [&](int itr) -> void\
    \ {\n        const auto &[a, b] = vp[itr];\n        std::swap(inv[alpha[a]], inv[alpha[b]]);\n\
    \        std::swap(alpha[a], alpha[b]);\n    };\n    auto solve = [&](int idx)\
    \ -> void {\n        const auto &[type, x] = queries[idx];\n        ans[idx] =\
    \ (type == 1 ? alpha[x] + 1 : inv[x] + 1);\n    };\n    mo.execute(swap_l, swap_l,\
    \ swap_r, swap_r, solve);\n\n    for(auto elem : ans) std::cout << elem << \"\\\
    n\";\n}\n"
  dependsOn:
  - lib/Others/mo_algorithm.hpp
  isVerificationFile: true
  path: test/aoj-0425-mo_algorithm.test.cpp
  requiredBy: []
  timestamp: '2024-10-05 02:32:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-0425-mo_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-0425-mo_algorithm.test.cpp
- /verify/test/aoj-0425-mo_algorithm.test.cpp.html
title: test/aoj-0425-mo_algorithm.test.cpp
---
