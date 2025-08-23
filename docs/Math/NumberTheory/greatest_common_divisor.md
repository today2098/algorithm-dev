---
title: Greatest Common Divisor（最大公約数）
documentation_of: //algorithm/Math/NumberTheory/greatest_common_divisor.hpp
---


## 概要

2つの自然数 $a, b$ の最大公約数 (GCD: Greatest Common Divisor) を求める．

本実装では「ユークリッドの互除法 (Euclidean algorithm)」を用いており，計算量は $\mathcal{O}(\log(\min(a,b)))$ となる．

### アルゴリズムの説明

ユークリッドの互除法が最大公約数を求める原理とその計算量を説明する．

#### 剰余と公約数の関係

$a, b \in \mathbb{N}, \ a \geq b$ に対して，$a$ を $b$ で割ったときの商を $q \in \mathbb{N}$，余りを $r \in \mathbb{N_0}$ とすると，

$$
a = qb + r, \ 0 \leq r < b
$$

となる．

ここで $d \in \mathbb{N}$ を $d \mid a, \ d \mid b$ を満たす数とする．
このとき，$d \mid a-qb$ となるから，$d \mid r$ が成り立つ．

逆に，$d' \in \mathbb{N}$ を $d' \mid b, \ d' \mid r$ を満たす数とすると，$d' \mid qb+r$ だから，$d' \mid a$ が成り立つ．

よって，$a$ と $b$ の公約数全体の集合は $b$ と $r$ の公約数全体の集合に等しく，特に $\gcd(a,b)$ は $\gcd(b,r)$ に等しい．

#### ユークリッドの互除法の説明

ユークリッドの互除法は上記の性質を利用する．

$r_0 = a, \ r_1 = b$ とおき，次のように剰余算を繰り返す．

$$
\begin{align}
&r_0 = d_0 r_1 + r_2 \quad (d_0 > 0, \ 0 < r_2 < r_1), \notag \\
&r_1 = d_1 r_2 + r_3 \quad (d_1 > 0, \ 0 < r_3 < r_2), \notag \\
&\ldots \notag \\
&r_i = d_i r_{i+1} + r_{i+2} \quad (d_i > 0, \ 0 \leq r_{i+2} < r_{i+1}), \notag \\
&\ldots \notag \\
&r_{n-2} = d_{n-2} r_{n-1} + 0 \quad (d_{n-2} > 0). \notag
\end{align}
$$

$r_{i+2} < r_{i+1} \leq r_i$ であるから，必ず $r_n = 0$ となる $n$ が存在し，$r_{n-1}$ が求める最大公約数となる．

#### 計算量の導出

先の途中式 $r_i = d_i r_{i+1} + r_{i+2}$ において，$r_{i+2} < r_i / 2$ である．

したがって，繰り返しは高々 $2 \log b$ 回であり，計算量は $\mathcal{O}(\log b)$ となる．

## 参考

1. H.H. シルヴァーマン. "第5章 割り切れる関係 —— 整除性と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.29-33.
1. "最大公約数". Wikipedia. <https://ja.wikipedia.org/wiki/最大公約数>.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "ユークリッドの互除法の証明と不定方程式". 高校数学の美しい物語. <https://manabitimes.jp/math/672>.
