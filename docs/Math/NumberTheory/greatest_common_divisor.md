---
title: Greatest Common Divisor（最大公約数）
documentation_of: //algorithm/Math/NumberTheory/greatest_common_divisor.hpp
---


## 概要

2つの整数 $a, b$ の最大公約数 (GCD: Greatest Common Divisor) を求める．

本実装では「ユークリッドの互除法」を用いており，計算量は $\mathcal{O}(\log(\min(a,b)))$ となる．

## 参考

1. H.H. シルヴァーマン. "第5章 割り切れる関係 —— 整除性と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.29-33.
1. "最大公約数". Wikipedia. <https://ja.wikipedia.org/wiki/最大公約数>.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "ユークリッドの互除法の証明と不定方程式". 高校数学の美しい物語. <https://manabitimes.jp/math/672>.
