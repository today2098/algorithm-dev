---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/linear_sieve.hpp
    title: "\u7DDA\u5F62\u7BE9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj-ALDS1_1_C-linear_sieve.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\n\n\
    #include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/linear_sieve.hpp\"\n\n\n\
    \n#include <algorithm>\n#include <cassert>\n#include <map>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// \u7DDA\u5F62\u7BE9\uFF0E\nclass LinearSieve {\n\
    \    int m_sz;\n    // m_lpf[i]:=(\u6B63\u306E\u5947\u65702*i+1\u306E\u6700\u5C0F\
    \u7D20\u56E0\u6570). Least prime factor. m_lpf[i]==2*i+1 \u306E\u3068\u304D\uFF0C\
    2*i+1\u306F\u7D20\u6570\uFF0E\n    std::vector<int> m_lpf;\n    std::vector<int>\
    \ m_primes;  // m_primes[]:=(\u81EA\u7136\u6570n\u672A\u6E80\u306E\u7D20\u6570\
    \u30EA\u30B9\u30C8).\n\npublic:\n    // constructor. n\u672A\u6E80\u306E\u81EA\
    \u7136\u6570\u3092\u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N).\n    LinearSieve()\
    \ : LinearSieve(0) {}\n    explicit LinearSieve(int n) : m_sz(n), m_lpf(n / 2,\
    \ -1) {\n        assert(n >= 0);\n        if(m_sz <= 2) return;\n        m_primes.push_back(2);\n\
    \        int p = 3;\n        for(int i = 1, end = m_lpf.size(); i < end; ++i)\
    \ {\n            if(m_lpf[i] == -1) {\n                m_lpf[i] = p;\n       \
    \         m_primes.push_back(p);\n            }\n            for(auto iter = m_primes.cbegin()\
    \ + 1; iter < m_primes.cend(); ++iter) {\n                const int prime = *iter;\n\
    \                if(prime > m_lpf[i] or (long long) p * prime >= m_sz) break;\n\
    \                m_lpf[p * prime / 2] = prime;\n            }\n            p +=\
    \ 2;\n        }\n        m_primes.shrink_to_fit();\n    }\n\n    // \u7D20\u6570\
    \u5224\u5B9A\uFF0EO(1).\n    bool is_prime(int n) const {\n        assert(0 <=\
    \ n and n < m_sz);\n        if(n == 2) return true;\n        if(n % 2 == 0) return\
    \ false;\n        return m_lpf[n / 2] == n;\n    }\n    // \u81EA\u7136\u6570\
    n\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    int lpf(int\
    \ n) const {\n        assert(0 <= n and n < m_sz);\n        if(n < 2) return -1;\n\
    \        if(n % 2 == 0) return 2;\n        return m_lpf[n / 2];\n    }\n    //\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0EO(logN).\n    std::map<int,\
    \ int> prime_factorize(int n) const {\n        assert(1 <= n and n < m_sz);\n\
    \        std::map<int, int> res;\n        for(; n % 2 == 0; n /= 2) res[2]++;\n\
    \        for(; n > 1; n /= m_lpf[n / 2]) res[m_lpf[n / 2]]++;\n        return\
    \ res;\n    }\n    // \u7D20\u6570\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\
    \uFF0EO(1).\n    const std::vector<int> &primes() const { return m_primes; }\n\
    };\n\n}  // namespace algorithm\n\n\n#line 6 \"test/aoj-ALDS1_1_C-linear_sieve.test.cpp\"\
    \n\nint main() {\n    constexpr int mx = 1e8;\n\n    int n;\n    std::cin >> n;\n\
    \n    int ans = 0;\n    algorithm::LinearSieve sieve(mx + 1);\n    for(int i =\
    \ 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(sieve.is_prime(a))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/linear_sieve.hpp\"\
    \n\nint main() {\n    constexpr int mx = 1e8;\n\n    int n;\n    std::cin >> n;\n\
    \n    int ans = 0;\n    algorithm::LinearSieve sieve(mx + 1);\n    for(int i =\
    \ 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(sieve.is_prime(a))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/linear_sieve.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_1_C-linear_sieve.test.cpp
  requiredBy: []
  timestamp: '2025-03-02 15:28:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ALDS1_1_C-linear_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_1_C-linear_sieve.test.cpp
- /verify/test/aoj-ALDS1_1_C-linear_sieve.test.cpp.html
title: test/aoj-ALDS1_1_C-linear_sieve.test.cpp
---
