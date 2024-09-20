---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_1_A-popcount.test.cpp
    title: test/aoj-ITP1_1_A-popcount.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/popcount.md
    document_title: Population Count (popcount)
    links: []
  bundledCode: "#line 1 \"lib/Others/popcount.hpp\"\n\n\n\n/**\n * @brief Population\
    \ Count (popcount)\n * @docs docs/Others/popcount.md\n */\n\n#include <cstdint>\n\
    \nnamespace algorithm {\n\nconstexpr int popcount32(uint32_t bit) {\n    bit -=\
    \ (bit >> 1) & 0x55555555U;\n    bit = (bit & 0x33333333U) + ((bit >> 2) & 0x33333333U);\n\
    \    bit = (bit + (bit >> 4)) & 0x0f0f0f0fU;\n    bit += bit >> 8;\n    bit +=\
    \ bit >> 16;\n    return bit & 0x3fU;\n}\n\nconstexpr int popcount64(uint64_t\
    \ bit) {\n    bit -= (bit >> 1) & 0x5555555555555555ULL;\n    bit = (bit & 0x3333333333333333ULL)\
    \ + ((bit >> 2) & 0x3333333333333333ULL);\n    bit = (bit + (bit >> 4)) & 0x0f0f0f0f0f0f0f0fULL;\n\
    \    bit += bit >> 8;\n    bit += bit >> 16;\n    bit += bit >> 32;\n    return\
    \ bit & 0x7fULL;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_POPCOUNT_HPP\n#define ALGORITHM_POPCOUNT_HPP 1\n\n/**\n\
    \ * @brief Population Count (popcount)\n * @docs docs/Others/popcount.md\n */\n\
    \n#include <cstdint>\n\nnamespace algorithm {\n\nconstexpr int popcount32(uint32_t\
    \ bit) {\n    bit -= (bit >> 1) & 0x55555555U;\n    bit = (bit & 0x33333333U)\
    \ + ((bit >> 2) & 0x33333333U);\n    bit = (bit + (bit >> 4)) & 0x0f0f0f0fU;\n\
    \    bit += bit >> 8;\n    bit += bit >> 16;\n    return bit & 0x3fU;\n}\n\nconstexpr\
    \ int popcount64(uint64_t bit) {\n    bit -= (bit >> 1) & 0x5555555555555555ULL;\n\
    \    bit = (bit & 0x3333333333333333ULL) + ((bit >> 2) & 0x3333333333333333ULL);\n\
    \    bit = (bit + (bit >> 4)) & 0x0f0f0f0f0f0f0f0fULL;\n    bit += bit >> 8;\n\
    \    bit += bit >> 16;\n    bit += bit >> 32;\n    return bit & 0x7fULL;\n}\n\n\
    }  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/popcount.hpp
  requiredBy: []
  timestamp: '2024-09-20 06:57:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ITP1_1_A-popcount.test.cpp
documentation_of: lib/Others/popcount.hpp
layout: document
redirect_from:
- /library/lib/Others/popcount.hpp
- /library/lib/Others/popcount.hpp.html
title: Population Count (popcount)
---
## 概要

与えられた非負整数値を2進数表記した際に1となっているビットの数を高速に求める．
"popcount" は "population count" の略．


## 参考文献

1. "Hamming weight". Wikipedia. <https://en.wikipedia.org/wiki/Hamming_weight>.
1. zawawahoge. "ビットカウントする高速アルゴリズムをPythonで実装しながら詳しく解説してみる". Qiita. <https://qiita.com/zawawahoge/items/8bbd4c2319e7f7746266>.


## 問題

- "D - Popcount and XOR". AtCoder Beginner Contest 347. AtCoder. <https://atcoder.jp/contests/abc347/tasks/abc347_d>.
