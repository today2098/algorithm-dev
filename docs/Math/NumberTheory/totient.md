---
title: Euler's Totient Function（オイラーのトーシェント関数）
documentation_of: //algorithm/Math/NumberTheory/totient.hpp
---

## 概要

自然数 $n$ に対して，$n$ と互いに素である $1$ 以上 $n$ 未満の自然数の個数を求める．

$$
\varphi(n) = \sum_{\substack{1 \leq m < n \\ \gcd(m,n) = 1}} 1.
$$

「オイラーの $\varphi$ 関数」とも呼ぶばれる．

## 参考

1. "オイラーのφ関数". Wikipedia. <https://ja.wikipedia.org/wiki/オイラーのφ関数>.
1. "オイラー関数の定義・性質4つとその証明". 数学の景色. <https://mathlandscape.com/euler-function/>.
