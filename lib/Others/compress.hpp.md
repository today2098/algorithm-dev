---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Others/compress.md
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 1 \"lib/Others/compress.hpp\"\n\n\n\n/**\n * @brief \u5EA7\u6A19\
    \u5727\u7E2E\n * @docs docs/Others/compress.md\n */\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u5EA7\u6A19\u5727\u7E2E\uFF0E\
    O(N*logN).\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    std::vector<Type> key = v;\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    for(auto\
    \ &elem : v) elem = std::lower_bound(key.begin(), key.end(), elem) - key.begin();\n\
    \    return key;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_COMPRESS_HPP\n#define ALGORITHM_COMPRESS_HPP 1\n\n/**\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/Others/compress.md\n */\n\n\
    #include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n// \u5EA7\u6A19\
    \u5727\u7E2E\uFF0EO(N*logN).\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    std::vector<Type> key = v;\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    for(auto\
    \ &elem : v) elem = std::lower_bound(key.begin(), key.end(), elem) - key.begin();\n\
    \    return key;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/compress.hpp
  requiredBy: []
  timestamp: '2024-09-12 23:37:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Others/compress.hpp
layout: document
redirect_from:
- /library/lib/Others/compress.hpp
- /library/lib/Others/compress.hpp.html
title: "\u5EA7\u6A19\u5727\u7E2E"
---
## 概要

「座標圧縮（座圧）」とは，値の大小関係を保ったまま小さな自然数に変化することをいう．

具体的には，配列 $A = \lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ を次の条件を満たす自然数の列 $B = \lbrace b_0, b_1, \ldots, b_{N-1} \rbrace$ に変換する．

1. $b_0, b_1, \ldots, b_{N-1}$ は0以上の自然数
1. $a_i < a_j$ であるならば $b_i < b_j$
1. $a_i = a_j$ であるならば $b_i = b_j$
1. $a_i > a_j$ であるならば $b_i > b_j$
1. 条件1~4を満たす中で，配列 $B$ の最大値をできるだけ小さくする

計算量は，配列の長さを $N$ とすると，$\mathcal{O}(N \log N)$ となる．

扱う値の範囲を小さくすることで，余分なメモリを節約するなどの工夫ができる．


## 問題

- "A15 - Compression". 競技プログラミングの鉄則 演習問題集. AtCoder. <https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o>.
