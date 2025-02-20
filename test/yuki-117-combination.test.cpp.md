---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Combinatorics/combination.hpp
    title: "\u6570\u3048\u4E0A\u3052\uFF08mod\u4ED8\u304D\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/yuki-117-combination.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/117\"\n\n#include <iostream>\n\n#line 1 \"lib/Math/Combinatorics/combination.hpp\"\
    \n\n\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate\
    \ <int mod>\nclass Combination {\n    static_assert(mod >= 2);\n\n    static Combination\
    \ *s_instance;\n    int m_sz;\n    std::vector<long long> m_fact;  // m_fact[n]:=(n\u306E\
    \u968E\u4E57).\n    std::vector<long long> m_inv;   // m_inv[n]:=(n\u306E\u9006\
    \u5143).\n    std::vector<long long> m_finv;  // m_finv[n]:=(n\u306E\u968E\u4E57\
    \u306E\u9006\u5143).\n\n    Combination() : m_sz(2), m_fact({1, 1}), m_inv({-1,\
    \ 1}), m_finv({1, 1}) {}\n\n    static Combination *instance() {\n        if(!s_instance)\
    \ s_instance = new Combination;\n        return s_instance;\n    }\n    void calc(int\
    \ sz) {\n        assert(sz <= mod);\n        if(sz <= m_sz) return;\n        reserve_internal(sz);\n\
    \        for(int n = m_sz; n < sz; ++n) {\n            m_fact.push_back(m_fact[n\
    \ - 1] * n % mod);\n            m_inv.push_back(mod - m_inv[mod % n] * (mod /\
    \ n) % mod);\n            m_finv.push_back(m_finv[n - 1] * m_inv[n] % mod);\n\
    \        }\n        m_sz = sz;\n    }\n    long long fact(int n) {\n        assert(n\
    \ >= 0);\n        calc(n + 1);\n        return m_fact[n];\n    }\n    long long\
    \ inv(int n) {\n        assert(n >= 1);\n        calc(n + 1);\n        return\
    \ m_inv[n];\n    }\n    long long finv(int n) {\n        assert(n >= 0);\n   \
    \     calc(n + 1);\n        return m_finv[n];\n    }\n    long long nPk_internal(int\
    \ n, int k) {\n        assert(n >= 0);\n        assert(k >= 0);\n        if(n\
    \ < k) return 0;\n        calc(n + 1);\n        return m_fact[n] * m_finv[n -\
    \ k] % mod;\n    }\n    long long nCk_internal(int n, int k) {\n        assert(n\
    \ >= 0);\n        assert(k >= 0);\n        if(n < k) return 0;\n        calc(n\
    \ + 1);\n        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;\n \
    \   }\n    void resize_internal(int sz) {\n        assert(0 <= sz);\n        if(sz\
    \ < 2) return;\n        if(m_sz < sz) {\n            reserve_internal(sz);\n \
    \           return;\n        }\n        m_fact.resize(sz);\n        m_inv.resize(sz);\n\
    \        m_finv.resize(sz);\n        m_sz = sz;\n    }\n    void reserve_internal(int\
    \ cap) {\n        assert(0 <= cap);\n        m_fact.reserve(cap);\n        m_inv.reserve(cap);\n\
    \        m_finv.reserve(cap);\n    }\n    void shrink_to_fit_internal() {\n  \
    \      m_fact.shrink_to_fit();\n        m_inv.shrink_to_fit();\n        m_finv.shrink_to_fit();\n\
    \    }\n\npublic:\n    static constexpr int modulus() { return mod; }\n    //\
    \ \u968E\u4E57\uFF0EO(1).\n    static long long factorial(int n) { return instance()->fact(n);\
    \ }\n    // \u9006\u5143\uFF0EO(1).\n    static long long inverse(int n) { return\
    \ instance()->inv(n); }\n    // \u968E\u4E57\u306E\u9006\u5143\uFF0EO(1).\n  \
    \  static long long inverse_fact(int n) { return instance()->finv(n); }\n    //\
    \ \u9806\u5217\uFF0EO(1).\n    static long long nPk(int n, int k) { return instance()->nPk_internal(n,\
    \ k); }\n    // \u7D44\u5408\u305B\uFF0EO(1).\n    static long long nCk(int n,\
    \ int k) { return instance()->nCk_internal(n, k); }\n    // \u91CD\u8907\u7D44\
    \u5408\u305B\uFF0EO(1).\n    static long long nHk(int n, int k) {\n        assert(n\
    \ >= 0);\n        assert(k >= 0);\n        if(k == 0) return 1;\n        if(n\
    \ == 0) return 0;\n        return instance()->nCk_internal(k + n - 1, k);\n  \
    \  }\n    static void resize(int sz) { instance()->resize_internal(sz); }\n  \
    \  static void reserve(int cap) { instance()->reserve_internal(cap); }\n    static\
    \ void shrink_to_fit() { instance()->shrink_to_fit_internal(); }\n    static void\
    \ destroy() {\n        delete s_instance;\n        s_instance = nullptr;\n   \
    \ }\n};\n\ntemplate <int mod>\nCombination<mod> *Combination<mod>::s_instance\
    \ = nullptr;\n\nusing Combination998244353 = Combination<998'244'353>;\nusing\
    \ Combination1000000007 = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\
    \n\n#line 6 \"test/yuki-117-combination.test.cpp\"\n\nint main() {\n    int t;\n\
    \    scanf(\"%d\\n\", &t);\n\n    algorithm::Combination1000000007::reserve(1e6\
    \ + 1);\n    while(t--) {\n        char c;\n        int n, k;\n        scanf(\"\
    %c(%d,%d)\\n\", &c, &n, &k);\n\n        if(c == 'C') std::cout << algorithm::Combination1000000007::nCk(n,\
    \ k);\n        else if(c == 'P') std::cout << algorithm::Combination1000000007::nPk(n,\
    \ k);\n        else std::cout << algorithm::Combination1000000007::nHk(n, k);\n\
    \        std::cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n\n#include <iostream>\n\
    \n#include \"../lib/Math/Combinatorics/combination.hpp\"\n\nint main() {\n   \
    \ int t;\n    scanf(\"%d\\n\", &t);\n\n    algorithm::Combination1000000007::reserve(1e6\
    \ + 1);\n    while(t--) {\n        char c;\n        int n, k;\n        scanf(\"\
    %c(%d,%d)\\n\", &c, &n, &k);\n\n        if(c == 'C') std::cout << algorithm::Combination1000000007::nCk(n,\
    \ k);\n        else if(c == 'P') std::cout << algorithm::Combination1000000007::nPk(n,\
    \ k);\n        else std::cout << algorithm::Combination1000000007::nHk(n, k);\n\
    \        std::cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - lib/Math/Combinatorics/combination.hpp
  isVerificationFile: true
  path: test/yuki-117-combination.test.cpp
  requiredBy: []
  timestamp: '2025-02-20 22:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yuki-117-combination.test.cpp
layout: document
redirect_from:
- /verify/test/yuki-117-combination.test.cpp
- /verify/test/yuki-117-combination.test.cpp.html
title: test/yuki-117-combination.test.cpp
---
