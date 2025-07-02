---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Combinatorics/montmort.hpp\"\n\n#define ALGORTIHM_MONTMORT_HPP\
    \ 1\n\n#include <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace montmort {\n\n// COMPLETE_PERMUTATIONS_PROBABILITY:=(\u7121\u9650\
    \u500B\u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\u305F\u3068\u304D\u306B\
    \u5B8C\u5168\u9806\u5217\u3068\u306A\u308B\u78BA\u7387).\nconst double COMPLETE_PERMUTATIONS_PROBABILITY\
    \ = std::exp(-1.0);\n\n// \u5B8C\u5168\u9806\u5217\u306E\u7DCF\u6570\uFF0C\u30E2\
    \u30F3\u30E2\u30FC\u30EB\u6570\uFF0E\ntemplate <int mod>\nclass Montmort {\n \
    \   static_assert(mod >= 2);\n\nprivate:\n    int m_sz;\n    std::vector<long\
    \ long> m_montmort;  // m_montmort[k]:=(k\u9805\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\
    \u30EB\u6570).\n\npublic:\n    Montmort() : Montmort(2) {}\n    explicit Montmort(int\
    \ n) : m_sz(n), m_montmort(n) {\n        assert(n >= 2);\n        m_montmort[0]\
    \ = 1;\n        m_montmort[1] = 0;\n        for(int i = 2; i < m_sz; ++i) m_montmort[i]\
    \ = (i - 1) * (m_montmort[i - 2] + m_montmort[i - 1]) % mod;\n    }\n\n    static\
    \ constexpr int modulus() { return mod; }\n    int size() const { return m_sz;\
    \ }\n    // k\u9805\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\u30EB\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    long long montmort(int k) const {\n       \
    \ assert(0 <= k and k < size());\n        return m_montmort[k];\n    }\n};\n\n\
    // \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\uFF0EO(K).\nconstexpr long long montmort(int\
    \ k) {\n    assert(k >= 0);\n    long long a[2] = {1, 0};\n    if(k < 2) return\
    \ a[k];\n    for(int i = 2; i <= k; ++i) {\n        long long tmp = (i - 1) *\
    \ (a[0] + a[1]);\n        a[0] = a[1];\n        a[1] = tmp;\n    }\n    return\
    \ a[1];\n}\n\n// \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\uFF08mod\u4ED8\u304D\uFF09\
    \uFF0EO(K).\nconstexpr long long montmort(int k, int mod) {\n    assert(k >= 0);\n\
    \    assert(mod >= 1);\n    long long a[2] = {1, 0};\n    if(k < 2) return a[k]\
    \ % mod;\n    for(int i = 2; i <= k; ++i) {\n        long long tmp = (i - 1) *\
    \ (a[0] + a[1]) % mod;\n        a[0] = a[1];\n        a[1] = tmp;\n    }\n   \
    \ return a[1];\n}\n\n}  // namespace montmort\n\n}  // namespace algorithm\n\n\
    #endif\n"
  code: "#ifndef ALGORITHM_MONTMORT_HPP\n#define ALGORTIHM_MONTMORT_HPP 1\n\n#include\
    \ <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm {\n\n\
    namespace montmort {\n\n// COMPLETE_PERMUTATIONS_PROBABILITY:=(\u7121\u9650\u500B\
    \u306E\u8981\u7D20\u3092\u4E26\u3073\u66FF\u3048\u305F\u3068\u304D\u306B\u5B8C\
    \u5168\u9806\u5217\u3068\u306A\u308B\u78BA\u7387).\nconst double COMPLETE_PERMUTATIONS_PROBABILITY\
    \ = std::exp(-1.0);\n\n// \u5B8C\u5168\u9806\u5217\u306E\u7DCF\u6570\uFF0C\u30E2\
    \u30F3\u30E2\u30FC\u30EB\u6570\uFF0E\ntemplate <int mod>\nclass Montmort {\n \
    \   static_assert(mod >= 2);\n\nprivate:\n    int m_sz;\n    std::vector<long\
    \ long> m_montmort;  // m_montmort[k]:=(k\u9805\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\
    \u30EB\u6570).\n\npublic:\n    Montmort() : Montmort(2) {}\n    explicit Montmort(int\
    \ n) : m_sz(n), m_montmort(n) {\n        assert(n >= 2);\n        m_montmort[0]\
    \ = 1;\n        m_montmort[1] = 0;\n        for(int i = 2; i < m_sz; ++i) m_montmort[i]\
    \ = (i - 1) * (m_montmort[i - 2] + m_montmort[i - 1]) % mod;\n    }\n\n    static\
    \ constexpr int modulus() { return mod; }\n    int size() const { return m_sz;\
    \ }\n    // k\u9805\u76EE\u306E\u30E2\u30F3\u30E2\u30FC\u30EB\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    long long montmort(int k) const {\n       \
    \ assert(0 <= k and k < size());\n        return m_montmort[k];\n    }\n};\n\n\
    // \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\uFF0EO(K).\nconstexpr long long montmort(int\
    \ k) {\n    assert(k >= 0);\n    long long a[2] = {1, 0};\n    if(k < 2) return\
    \ a[k];\n    for(int i = 2; i <= k; ++i) {\n        long long tmp = (i - 1) *\
    \ (a[0] + a[1]);\n        a[0] = a[1];\n        a[1] = tmp;\n    }\n    return\
    \ a[1];\n}\n\n// \u30E2\u30F3\u30E2\u30FC\u30EB\u6570\uFF08mod\u4ED8\u304D\uFF09\
    \uFF0EO(K).\nconstexpr long long montmort(int k, int mod) {\n    assert(k >= 0);\n\
    \    assert(mod >= 1);\n    long long a[2] = {1, 0};\n    if(k < 2) return a[k]\
    \ % mod;\n    for(int i = 2; i <= k; ++i) {\n        long long tmp = (i - 1) *\
    \ (a[0] + a[1]) % mod;\n        a[0] = a[1];\n        a[1] = tmp;\n    }\n   \
    \ return a[1];\n}\n\n}  // namespace montmort\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Combinatorics/montmort.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/Combinatorics/montmort.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Combinatorics/montmort.hpp
- /library/algorithm/Math/Combinatorics/montmort.hpp.html
title: algorithm/Math/Combinatorics/montmort.hpp
---
