## 概要

高速フーリエ変換 (FFT: Fast Fourier Transform) を用いた畳み込みを行う．

具体的には，長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ と長さ $M$ の数列 $\lbrace b_0, b_1, \ldots, b_{M-1} \rbrace$ に対して

$$
c_i = \sum_{k=0}^{i} a_k b_{i-k}
$$

となる長さ $N + M - 1$ の数列 $\lbrace c_0, c_1, \ldots, c_{N+M-1} \rbrace$ を $\mathcal{O}((N + M) \log (N + M))$ で求める．

数列の長さや要素の値が大きくなると，誤差も大きくなることに注意．


## 参考文献

1. "高速フーリエ変換". Wikipedia. <https://ja.wikipedia.org/wiki/高速フーリエ変換>.
1. AngrySadEight. "高速フーリエ変換・数論変換を改めて理解しようという話". Qiita. <https://qiita.com/AngrySadEight/items/0dfde26060daaf6a2fda>.
1. tatyam. "【競プロer向け】FFT を習得しよう！". 東京工業大学で活動するデジタル創作. <https://trap.jp/post/1386/>.
1. "競プロのための高速フーリエ変換". <https://www.creativ.xyz/fast-fourier-transform/>.


## 問題

- "C - 高速フーリエ変換". AtCoder Typical Contest 001. AtCoder. <https://atcoder.jp/contests/atc001/tasks/fft_c>.
