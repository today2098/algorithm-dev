---
title: 繰り返し二乗法（mod付き）
documentation_of: //lib/Math/ModularArithmetic/mod_pow.hpp
---


## 概要

自然数 $n, k, m$ に対して，

$$
n^k \bmod m
$$

を求める．

本実装では「繰り返し二乗法」を用いており，計算量は $\mathcal{O}(\log k)$ である．


## 問題

- "B - n^p mod m". AtCoder Typical Contest 002. AtCoder. <https://atcoder.jp/contests/atc002/tasks/atc002_b>.
