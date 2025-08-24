---
title: Greatest Common Divisor（最大公約数）
documentation_of: //algorithm/Math/NumberTheory/greatest_common_divisor.hpp
---


## 概要

2つの整数 $a, b$ の最大公約数 (GCD: Greatest Common Divisor) を求める．

本実装では「ユークリッドの互除法 (Euclidean algorithm)」を用いており，計算量は $\mathcal{O}(\log(\min(a,b)))$ となる．

### アルゴリズムの説明

ユークリッドの互除法が最大公約数を求める原理とその計算量を説明する．

#### 剰余と公約数の関係

$a, b \in \mathbb{Z}, \ a \geq b > 0$ に対して，$a$ を $b$ で割ったときの商を $q$，余りを $r$ とすると，$a = qb + r$ となる．

ここで $d \in \mathbb{N}$ を $d \mid a, \ d \mid b$ を満たす数とする．
このとき，$d \mid a-qb$ となるから，$d \mid r$ が成り立つ．

逆に，$d' \in \mathbb{N}$ を $d' \mid b, \ d' \mid r$ を満たす数とすると，$d' \mid qb+r$ だから，$d' \mid a$ が成り立つ．

よって，$a$ と $b$ の公約数全体の集合は $b$ と $r$ の公約数全体の集合に等しく，特に $\gcd(a,b)$ は $\gcd(b,r)$ に等しい．

#### ユークリッドの互除法の説明

ユークリッドの互除法は上記の性質を利用する．

$r_0, r_1 \in \mathbb{Z}, \ r_0 \geq r_1 > 0$ に対して，次のように剰余算を繰り返す．

$$
\begin{align}
&r_0 - \lfloor r_0 / r_1 \rfloor \cdot r_1 = r_2, \notag \\
&r_1 - \lfloor r_1 / r_2 \rfloor \cdot r_2 = r_3, \notag \\
&\ldots \notag \\
&r_i - \lfloor r_i / r_{i+1} \rfloor \cdot r_{i+1} = r_{i+2}, \notag \\
&\ldots \notag \\
&r_{n-1} - \lfloor r_{n-1} / r_n \rfloor \cdot r_n = 0. \notag \\
\end{align}
$$

$r_{i+2} < r_{i+1} \leq r_i$ であるから，必ず $r_{n+1} = 0$ となる $n$ が存在し，$r_n$ が求める最大公約数となる．

#### 計算量の導出

先の式 $r_i - \lfloor r_i / r_{i+1} \rfloor \cdot r_{i+1} = r_{i+2}$ において，$r_{i+2} < r_i / 2$ である．

したがって，繰り返しは高々 $2 \log b$ 回であり，計算量は $\mathcal{O}(\log b)$ となる．

## 参考

1. H.H. シルヴァーマン. "第5章 割り切れる関係 —— 整除性と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.29-33.
1. "最大公約数". Wikipedia. <https://ja.wikipedia.org/wiki/最大公約数>.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "ユークリッドの互除法の証明と不定方程式". 高校数学の美しい物語. <https://manabitimes.jp/math/672>.
