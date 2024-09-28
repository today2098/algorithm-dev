## 概要

数論変換 (NTT: Number Theoretic Transform) を用いた畳み込みを行う．

具体的には，長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ と長さ $M$ の数列 $\lbrace b_0, b_1, \ldots, b_{M-1} \rbrace$ に対して，

$$
c_i = \sum_{k=0}^{i} a_k b_{i-k}
$$

となる長さ $N + M - 1$ の数列 $\lbrace c_0, c_1, \ldots, c_{N+M-1} \rbrace$ を $\mathcal{O}((N + M) \log (N + M))$ で求める．


## 参考文献

1. tsujimotter. "原始根の数のかぞえかた". Hatena Blog. <https://tsujimotter.hatenablog.com/entry/primitive-root>.
1. Sen_comp. "NTT(数論変換)のやさしい解説". Hatena Blog. <https://sen-comp.hatenablog.com/entry/2021/02/06/180310>.
1. "原始根の定義と具体例（高校生向け）". 高校数学の美しい物語. <https://manabitimes.jp/math/842>.


## 問題

- "C - 高速フーリエ変換". AtCoder Typical Contest 001. AtCoder. <https://atcoder.jp/contests/atc001/tasks/fft_c>.
