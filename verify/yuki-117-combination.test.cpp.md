---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Math/Combinatorics/combination.hpp
    title: algorithm/Math/Combinatorics/combination.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"verify/yuki-117-combination.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/117\"\n\n#include <iostream>\n\n#line 1 \"\
    algorithm/Math/Combinatorics/combination.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\ntemplate <int mod>\nclass Combination {\n\
    \    static_assert(mod >= 2);\n\n    int m_sz;\n    std::vector<long long> m_fact;\
    \      // m_fact[n]:=(n\u306E\u968E\u4E57).\n    std::vector<long long> m_inv;\
    \       // m_inv[n]:=(n\u306E\u9006\u5143).\n    std::vector<long long> m_inv_fact;\
    \  // m_inv_fact[n]:=(n\u306E\u968E\u4E57\u306E\u9006\u5143).\n\n    void build(int\
    \ n) {\n        if(n <= m_sz) return;\n        m_fact.resize(n);\n        m_inv.resize(n);\n\
    \        m_inv_fact.resize(n);\n        for(int i = m_sz; i < n; ++i) {\n    \
    \        m_fact[i] = m_fact[i - 1] * i % mod;\n            m_inv[i] = mod - m_inv[mod\
    \ % i] * (mod / i) % mod;\n            m_inv_fact[i] = m_inv_fact[i - 1] * m_inv[i]\
    \ % mod;\n        }\n        m_sz = n;\n    }\n\npublic:\n    Combination() :\
    \ Combination(2) {}\n    explicit Combination(int n) : m_sz(2), m_fact(n), m_inv(n),\
    \ m_inv_fact(n) {\n        assert(n >= 2);\n        m_fact[0] = m_fact[1] = 1;\n\
    \        m_inv[1] = 1;\n        m_inv_fact[0] = m_inv_fact[1] = 1;\n        build(n);\n\
    \    }\n\n    static constexpr int modulus() { return mod; }\n    // \u968E\u4E57\
    \uFF0EO(1).\n    long long factorial(int n) {\n        assert(n >= 0);\n     \
    \   build(n + 1);\n        return m_fact[n];\n    }\n    // \u9006\u5143\uFF0E\
    O(1).\n    long long inverse(int n) {\n        assert(n >= 1);\n        build(n\
    \ + 1);\n        return m_inv[n];\n    }\n    // \u968E\u4E57\u306E\u9006\u5143\
    \uFF0EO(1).\n    long long inverse_factorial(int n) {\n        assert(n >= 0);\n\
    \        build(n + 1);\n        return m_inv_fact[n];\n    }\n    // \u9806\u5217\
    \uFF0EO(1).\n    long long nPk(int n, int k) {\n        assert(n >= 0);\n    \
    \    assert(k >= 0);\n        if(n < k) return 0;\n        build(n + 1);\n   \
    \     return m_fact[n] * m_inv_fact[n - k] % mod;\n    }\n    // \u7D44\u5408\u305B\
    \uFF0EO(1).\n    long long nCk(int n, int k) {\n        assert(n >= 0);\n    \
    \    assert(k >= 0);\n        if(n < k) return 0;\n        build(n + 1);\n   \
    \     return m_fact[n] * m_inv_fact[n - k] % mod * m_inv_fact[k] % mod;\n    }\n\
    \    // \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(1).\n    long long nHk(int n, int\
    \ k) {\n        assert(n >= 0);\n        assert(k >= 0);\n        if(k == 0) return\
    \ 1;\n        if(n == 0) return 0;\n        return nCk(k + n - 1, k);\n    }\n\
    };\n\nusing Combination998244353 = Combination<998'244'353>;\nusing Combination1000000007\
    \ = Combination<1'000'000'007>;\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/yuki-117-combination.test.cpp\"\
    \n\nint main() {\n    int t;\n    scanf(\"%d\\n\", &t);\n\n    algorithm::Combination1000000007\
    \ comb(2e6);\n    while(t--) {\n        char c;\n        int n, k;\n        scanf(\"\
    %c(%d,%d)\\n\", &c, &n, &k);\n\n        long long ans;\n        if(c == 'C') ans\
    \ = comb.nCk(n, k);\n        else if(c == 'P') ans = comb.nPk(n, k);\n       \
    \ else ans = comb.nHk(n, k);\n        std::cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n\n#include <iostream>\n\
    \n#include \"../algorithm/Math/Combinatorics/combination.hpp\"\n\nint main() {\n\
    \    int t;\n    scanf(\"%d\\n\", &t);\n\n    algorithm::Combination1000000007\
    \ comb(2e6);\n    while(t--) {\n        char c;\n        int n, k;\n        scanf(\"\
    %c(%d,%d)\\n\", &c, &n, &k);\n\n        long long ans;\n        if(c == 'C') ans\
    \ = comb.nCk(n, k);\n        else if(c == 'P') ans = comb.nPk(n, k);\n       \
    \ else ans = comb.nHk(n, k);\n        std::cout << ans << \"\\n\";\n    }\n}\n"
  dependsOn:
  - algorithm/Math/Combinatorics/combination.hpp
  isVerificationFile: true
  path: verify/yuki-117-combination.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yuki-117-combination.test.cpp
layout: document
redirect_from:
- /verify/verify/yuki-117-combination.test.cpp
- /verify/verify/yuki-117-combination.test.cpp.html
title: verify/yuki-117-combination.test.cpp
---
