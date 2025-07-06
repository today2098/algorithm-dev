---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_4_A-imos_2d.test.cpp
    title: verify/aoj-DSL_4_A-imos_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Others/compress.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u5EA7\u6A19\u5727\u7E2E\uFF0E\
    O(N log N).\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    std::vector<Type> key(v);\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    key.shrink_to_fit();\n\
    \    for(auto &elem : v) elem = std::lower_bound(key.cbegin(), key.cend(), elem)\
    \ - key.cbegin();\n    return key;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_COMPRESS_HPP\n#define ALGORITHM_COMPRESS_HPP 1\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n// \u5EA7\u6A19\u5727\
    \u7E2E\uFF0EO(N log N).\ntemplate <typename Type>\nstd::vector<Type> compress(std::vector<Type>\
    \ &v) {\n    std::vector<Type> key(v);\n    std::sort(key.begin(), key.end());\n\
    \    key.erase(std::unique(key.begin(), key.end()), key.end());\n    key.shrink_to_fit();\n\
    \    for(auto &elem : v) elem = std::lower_bound(key.cbegin(), key.cend(), elem)\
    \ - key.cbegin();\n    return key;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Others/compress.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_4_A-imos_2d.test.cpp
documentation_of: algorithm/Others/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---


## 概要

「座標圧縮（座圧）」とは，座標情報を位置関係のみの情報に圧縮することをいう．
扱う値の範囲を小さくすることで，余分なメモリを節約するなどの工夫ができる．

具体的には，数列 $A = \lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ を次の条件を満たす自然数列 $B = \lbrace b_0, b_1, \ldots, b_{N-1} \rbrace$ に変換する．

1. $b_0, b_1, \ldots, b_{N-1}$ は0以上の自然数
2. $a_i < a_j$ であるならば $b_i < b_j$
3. $a_i = a_j$ であるならば $b_i = b_j$
4. $a_i > a_j$ であるならば $b_i > b_j$
5. 条件1~4を満たす中で，自然数列 $B$ の最大値をできるだけ小さくする

計算量は，配列の長さを $N$ とすると，$\mathcal{O}(N \log N)$ となる．


## 説明

|関数|説明|計算量|
|---|---|---|
|`key=compress(v)`|`v` をソートして重複を削除したもの `key` を返す．副作用として，`v` を座圧した結果に変換する．|$\mathcal{O}(N \log N)$|


## 参考

1. "座標圧縮の解説（1次元から2次元の圧縮まで）". アルゴリズムロジック. <https://algo-logic.info/coordinate-compress/>.


## 問題

- "A15 - Compression". 競技プログラミングの鉄則 演習問題集. AtCoder. <https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o>.
