---
title: 拡張ユークリッドの互除法
documentation_of: //algorithm/Math/NumberTheory/extgcd.hpp
---


## 概要

2つの整数 $a, b$ に対して，

$$
ax + by = \gcd(a, b)
$$

を満たす整数の組 $(x, y)$ を「ユークリッドの互除法」を応用して求める．
ただし，解が複数存在する場合は $\lvert x \rvert + \lvert y \rvert$ が最小となるものとする．
また，さらに最小のものが複数存在する場合は $x \leq y$ であるものとする．

この解を $(x_0, y_0)$ とすると，他の解は

$$
\left\lparen x_0 + k \cdot \frac{b}{\gcd(a,b)}, \ y_0 - k \cdot \frac{a}{\gcd(a,b)} \right\rparen
$$

と求められる（ただし，$k$ は整数）．

アルゴリズムの計算量は $\mathcal{O}(\log(\min(a,b)))$ となる．

## 参考

1. H.H. シルヴァーマン. "第6章 一次方程式と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.36-43.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. drken. "拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜". Qiita. <https://qiita.com/drken/items/b97ff231e43bce50199a>.
1. "拡張ユークリッドの互除法の解の範囲". HatenaBlog. <https://satashun.hatenablog.com/entry/2019/12/30/231319>.
