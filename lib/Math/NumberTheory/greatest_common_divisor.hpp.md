---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_C-least_common_multiple.test.cpp
    title: test/aoj-NTL_1_C-least_common_multiple.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/greatest_common_divisor.md
    document_title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n\n\
    \n/**\n * @brief Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09\
    \n * @docs docs/Math/NumberTheory/greatest_common_divisor.md\n */\n\nnamespace\
    \ algorithm {\n\ntemplate <typename Type>\nconstexpr Type igcd(Type a, Type b)\
    \ { return (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GREATEST_COMMON_DIVISOR_HPP\n#define ALGORITHM_GREATEST_COMMON_DIVISOR_HPP\
    \ 1\n\n/**\n * @brief Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\
    \uFF09\n * @docs docs/Math/NumberTheory/greatest_common_divisor.md\n */\n\nnamespace\
    \ algorithm {\n\ntemplate <typename Type>\nconstexpr Type igcd(Type a, Type b)\
    \ { return (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/NumberTheory/greatest_common_divisor.hpp
  requiredBy:
  - lib/Math/NumberTheory/least_common_multiple.hpp
  timestamp: '2024-09-01 22:54:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_C-least_common_multiple.test.cpp
documentation_of: lib/Math/NumberTheory/greatest_common_divisor.hpp
layout: document
redirect_from:
- /library/lib/Math/NumberTheory/greatest_common_divisor.hpp
- /library/lib/Math/NumberTheory/greatest_common_divisor.hpp.html
title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
---
## 概要

2つの整数 $a, b$ の最大公約数 (GCD: Greatest Common Divisor) を求める．

本実装では「ユークリッドの互除法」を用いており，計算量は $\mathcal{O}(\log(\min(a,b)))$ となる． 


## 参考文献

1. H.H. シルヴァーマン. "第5章 割り切れる関係 —— 整除性と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.29-33.
1. "最大公約数". Wikipedia. <https://ja.wikipedia.org/wiki/最大公約数>.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "ユークリッドの互除法の証明と不定方程式". 高校数学の美しい物語. <https://manabitimes.jp/math/672>.
