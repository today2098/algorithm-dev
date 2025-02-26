---
title: Sieve of Eratosthenes（エラトステネスの篩）
documentation_of: //lib/Math/NumberTheory/sieve.hpp
---


## 概要

$N$ 未満の自然数の中からすべての素数を発見する．

アルゴリズムの計算量は $\mathcal{O}(N \log \log N)$ となる．

本実装では，各自然数に対して最小の素因数 (LPF: Least Prime Factor) を求めており，「素数判定」に加え「高速素因数分解」などができる．


## 参考文献

1. "エラトステネスの篩". Wikipedia. <https://ja.wikipedia.org/wiki/エラトステネスの篩>.
1. rsk0315_h4x. "エラトステネスの篩に基づく高速な素因数分解". Qiita. <https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409>.
1. drken. "エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜". Qiita. <https://qiita.com/drken/items/3beb679e54266f20ab63>.
1. rsk0315. "素因数分解を <O(n), O(log(n)/log(log(n)))> で行う". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2023/05/03/133029>.
