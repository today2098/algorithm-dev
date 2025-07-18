---
title: 区間篩
documentation_of: //algorithm/Math/NumberTheory/segment_sieve.hpp
---


## 概要

区間 $[L,R)$ の自然数の中からすべての素数を発見する．
特に区間篩は大きな値に対して効果を発揮する．

実用上の制約は，おおよそ $R \leq 10^{12}, R - L \leq 10^6$ ．

アルゴリズムの計算量は $\mathcal{O}((\sqrt R + (R - L)) \log \log R)$ となる．


## 参考文献

1. rsk0315_h4x. "エラトステネスの篩に基づく高速な素因数分解". Qiita. <https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409>.
