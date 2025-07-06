---
title: 完全順列の総数，モンモール数
documentation_of: //algorithm/Math/Combinatorics/montmort.hpp
---


## 概要

完全順列 (complete permutations) とは，整数 $1,2,3, \ldots, n$ を要素とする順列において，$i$ 番目の要素が $i$ でないものを指す．
攪乱順列 (derangement)，乱列，混乱順列ともいう．

そして，完全順列の総数をモンモール数 (Montmort number) という．

「$n$ 個の整数 $1,2,3, \ldots, n$ を要素とする順列において，$i$ 番目の要素が $i$ でないものの総数」を $a_n$ とおくと，$a_n$ は次の漸化式で表される．

$$
a_0 = 1, \
a_1 = 0, \
a_n = (n-1)(a_{n-2} + a_{n-1})
$$

モンモール数の日常生活への応用例としては，「プレゼント交換方法の通り数の計算」などが考えられる．


## 参考文献

1. "完全順列". Wikipedia. <https://ja.wikipedia.org/wiki/完全順列>.
1. "攪乱順列（完全順列）の個数を求める公式". 高校数学の美しい物語. <https://manabitimes.jp/math/612>.


## 問題

- "C - 高橋君、24歳". AtCoder Regular Contest 009. AtCoder. <https://atcoder.jp/contests/arc009/tasks/arc009_3>.
