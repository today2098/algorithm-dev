---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/Combinatorics/naive_combination.md
    document_title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\
      \u305B"
    links: []
  bundledCode: "#line 1 \"lib/Math/Combinatorics/naive_combination.hpp\"\n\n\n\n/**\n\
    \ * @brief \u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B\
    \n * @docs docs/Math/Combinatorics/naive_combination.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n\nnamespace algorithm {\n\n// \u9806\u5217\uFF0EO(K).\nconstexpr\
    \ long long nPk(long long n, int k) {\n    assert(0 <= k and k <= n);\n    long\
    \ long res = 1;\n    for(int i = 0; i < k; ++i) res = res * (n - i);\n    return\
    \ res;\n}\n\n// \u7D44\u5408\u305B\uFF0EO(min(K,N-K)).\nconstexpr long long nCk(long\
    \ long n, int k) {\n    assert(n >= 0 and k >= 0);\n    if(k > n) return 0;\n\
    \    long long res = 1;\n    k = std::min<long long>(k, n - k);\n    for(int i\
    \ = 0; i < k; ++i) res = res * (n - i) / (i + 1);\n    return res;\n}\n\n// \u91CD\
    \u8907\u7D44\u5408\u305B\uFF0EO(min(N-1,K)).\nconstexpr long long nHk(long long\
    \ n, long long k) {\n    assert(n >= 1 and k >= 0);\n    return nCk(k + n - 1,\
    \ k);\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_NAIVE_COMBINATION_HPP\n#define ALGORITHM_NAIVE_COMBINATION_HPP\
    \ 1\n\n/**\n * @brief \u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\
    \u5408\u305B\n * @docs docs/Math/Combinatorics/naive_combination.md\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n\nnamespace algorithm {\n\n// \u9806\u5217\uFF0E\
    O(K).\nconstexpr long long nPk(long long n, int k) {\n    assert(0 <= k and k\
    \ <= n);\n    long long res = 1;\n    for(int i = 0; i < k; ++i) res = res * (n\
    \ - i);\n    return res;\n}\n\n// \u7D44\u5408\u305B\uFF0EO(min(K,N-K)).\nconstexpr\
    \ long long nCk(long long n, int k) {\n    assert(n >= 0 and k >= 0);\n    if(k\
    \ > n) return 0;\n    long long res = 1;\n    k = std::min<long long>(k, n - k);\n\
    \    for(int i = 0; i < k; ++i) res = res * (n - i) / (i + 1);\n    return res;\n\
    }\n\n// \u91CD\u8907\u7D44\u5408\u305B\uFF0EO(min(N-1,K)).\nconstexpr long long\
    \ nHk(long long n, long long k) {\n    assert(n >= 1 and k >= 0);\n    return\
    \ nCk(k + n - 1, k);\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/Combinatorics/naive_combination.hpp
  requiredBy: []
  timestamp: '2024-09-15 17:10:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/Combinatorics/naive_combination.hpp
layout: document
redirect_from:
- /library/lib/Math/Combinatorics/naive_combination.hpp
- /library/lib/Math/Combinatorics/naive_combination.hpp.html
title: "\u9806\u5217\uFF0C\u7D44\u5408\u305B\uFF0C\u91CD\u8907\u7D44\u5408\u305B"
---
## 概要

特定の性質を備えた対象を数え上げる．


## 参考文献

1. "組合せ数学". Wikipedia. <https://ja.wikipedia.org/wiki/組合せ数学>.
