---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/sieve.hpp
    title: "Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9\uFF09"
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
  bundledCode: "#line 1 \"verify/aoj-ALDS1_1_C-sieve.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\n\n#include\
    \ <iostream>\n\n#line 1 \"lib/Math/NumberTheory/sieve.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <numeric>\n#include <vector>\n\n\
    namespace algorithm {\n\n// Sieve of Eratosthenes\uFF08\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\uFF09.\nclass Sieve {\n    int m_sz;\n    // m_lpf[i]:=(\u6B63\
    \u306E\u5947\u65702*i+1\u306E\u6700\u5C0F\u7D20\u56E0\u6570). Least prime factor.\
    \ m_lpf[i]==2*i+1 \u306E\u3068\u304D\uFF0C2*i+1\u306F\u7D20\u6570\uFF0E\n    std::vector<int>\
    \ m_lpf;\n\npublic:\n    // constructor. n\u672A\u6E80\u306E\u81EA\u7136\u6570\
    \u3092\u7BE9\u306B\u304B\u3051\u308B\uFF0EO(N*loglogN).\n    Sieve() : Sieve(0)\
    \ {}\n    explicit Sieve(int n) : m_sz(n), m_lpf(n / 2, -1) {\n        assert(n\
    \ >= 0);\n        for(long long p = 3; p < m_sz; p += 2) {\n            if(m_lpf[p\
    \ / 2] == -1) {\n                m_lpf[p / 2] = p;\n                for(long long\
    \ q = p * p; q < m_sz; q += 2 * p) {\n                    if(m_lpf[q / 2] == -1)\
    \ m_lpf[q / 2] = p;\n                }\n            }\n        }\n    }\n\n  \
    \  // \u7D20\u6570\u5224\u5B9A\uFF0EO(1).\n    bool is_prime(int n) const {\n\
    \        assert(0 <= n and n < m_sz);\n        if(n == 2) return true;\n     \
    \   if(n % 2 == 0) return false;\n        return m_lpf[n / 2] == n;\n    }\n \
    \   // \u81EA\u7136\u6570n\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u8FD4\u3059\
    \uFF0EO(1).\n    int lpf(int n) const {\n        assert(0 <= n and n < m_sz);\n\
    \        if(n < 2) return -1;\n        if(n % 2 == 0) return 2;\n        return\
    \ m_lpf[n / 2];\n    }\n    // \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\uFF0E\
    O(logN).\n    std::map<int, int> prime_factorize(int n) const {\n        assert(1\
    \ <= n and n < m_sz);\n        std::map<int, int> res;\n        for(; n % 2 ==\
    \ 0; n /= 2) res[2]++;\n        for(; n > 1; n /= m_lpf[n / 2]) res[m_lpf[n /\
    \ 2]]++;\n        return res;\n    }\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\
    \u30A1\u30A4\u95A2\u6570\uFF0En\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\
    \u306A\u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n\
    \    int totient(int n) const {\n        assert(1 <= n and n < m_sz);\n      \
    \  int res = n;\n        for(const auto &[p, _] : prime_factorize(n)) res -= res\
    \ / p;\n        return res;\n    }\n    // \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\
    \uFF0EO(N*loglogN).\n    std::vector<int> mobius() const {\n        std::vector<int>\
    \ res(m_sz, 1);  // res[n]:=\u03BC(n).\n        for(int p = 2; p < m_sz; ++p)\
    \ {\n            if(lpf(p) == p) {\n                res[p] = -1;\n           \
    \     for(int q = 2 * p; q < m_sz; q += p) {\n                    if((q / p) %\
    \ p == 0) res[q] = 0;  // n\u304C\u3042\u308B\u7D20\u6570p\u30672\u56DE\u4EE5\u4E0A\
    \u5272\u308A\u5207\u308C\u308B\u3068\u304D\uFF0C\u03BC(n)=0.\n               \
    \     else res[q] = -res[q];            // n\u304Ck\u500B\u306E\u76F8\u7570\u306A\
    \u308B\u7D20\u56E0\u6570\u3067\u5206\u89E3\u3067\u304D\u308B\u3068\u304D\uFF0C\
    \u03BC(n)=(-1)^k.\n                }\n            }\n        }\n        return\
    \ res;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-ALDS1_1_C-sieve.test.cpp\"\
    \n\nint main() {\n    constexpr int mx = 1e8;\n\n    int n;\n    std::cin >> n;\n\
    \n    int ans = 0;\n    algorithm::Sieve sieve(mx + 1);\n    for(int i = 0; i\
    \ < n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(sieve.is_prime(a))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/sieve.hpp\"\n\n\
    int main() {\n    constexpr int mx = 1e8;\n\n    int n;\n    std::cin >> n;\n\n\
    \    int ans = 0;\n    algorithm::Sieve sieve(mx + 1);\n    for(int i = 0; i <\
    \ n; ++i) {\n        int a;\n        std::cin >> a;\n\n        if(sieve.is_prime(a))\
    \ ans++;\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/sieve.hpp
  isVerificationFile: true
  path: verify/aoj-ALDS1_1_C-sieve.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ALDS1_1_C-sieve.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ALDS1_1_C-sieve.test.cpp
- /verify/verify/aoj-ALDS1_1_C-sieve.test.cpp.html
title: verify/aoj-ALDS1_1_C-sieve.test.cpp
---
