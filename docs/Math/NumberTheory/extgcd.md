---
title: Extended Euclidean Algorithm（拡張ユークリッドの互除法）
documentation_of: //algorithm/Math/NumberTheory/extgcd.hpp
---


## 概要

2つの整数 $a, b$ に対して，

$$
ax + by = \gcd(a, b), \ |x| \leq \frac{|b|}{\gcd(a, b)}, \ |y| \leq \frac{|a|}{\gcd(a, b)}
$$

を満たす整数の組 $(x, y)$ を「ユークリッドの互除法」を応用して求める．

アルゴリズムの計算量は $\mathcal{O}(\log(\min(a,b)))$ である．

### アルゴリズムの説明

#### 解の存在性の証明と導出

$r_0, r_1 \in \mathbb{Z}, \ r_0 \geq r_1 > 0$ について，$r_0 x_0 + r_1 y_0 = \gcd(r_0,r_1)$ を満たす整数の組 $(x_0,y_0)$ が存在すると仮定する．

$r_0$ を $r_1$ で割ったときの商を $q$，余りを $r_2$ とすると，

$$
\begin{align}
r_0 x_0 + r_1 y_0 &= \gcd(r_0, r_1) \notag \\
(q r_1 + r_2) x_0 + r_1 y_0 &= \gcd(r_0, r_1) \quad (\because \ r_0=q r_1 + r_2) \notag \\
r_1 (q x_0 + y_0) + r_2 x_0 &= \gcd(r_0, r_1) \notag \\
r_1 x_1 + r_2 y_1 &= \gcd(r_0, r_1) \quad (x_1 = q x_0 + y_0, \ y_1 = x_0) \notag \\
r_1 x_1 + r_2 y_1 &= \gcd(r_1, r_2) \quad (\because \ \gcd(r_0, r_1) = \gcd(r_1, r_2)) \notag \\
\end{align}
$$

と表せ，元の問題に帰着できる．

この式変形を再帰的に繰り返す（ただし，$g = \gcd(r_0,r_1)$）．

$$
\begin{align}
r_0 x_0 + r_1 y_0 &= g \notag \\
r_1 x_1 + r_2 y_1 &= g \quad \left( r_2 = r_0 - \left\lfloor \frac{r_0}{r_1} \right\rfloor \cdot r_1, \ x_1 = \left\lfloor \frac{r_0}{r_1} \right\rfloor \cdot x_0 + y_0, \ y_1 = x_0 \right) \notag \\
&\ldots \notag \\
r_i x_i + r_{i+1} y_i &= g \quad \left( r_{i+1} = r_{i-1} - \left\lfloor \frac{r_{i-1}}{r_i} \right\rfloor \cdot r_i, \ x_i = \left\lfloor \frac{r_{i-1}}{r_i} \right\rfloor \cdot x_{i-1} + y_{i-1}, \ y_i = x_{i-1} \right) \notag \\
&\ldots \notag \\
r_n x_n + 0 \cdot y_n &= g. \notag \\
\end{align}
$$

$r_{i+2} < r_{i+1} \leq r_i$ であるから，必ず $r_{n+1} = 0$ となる $n$ が存在し，このとき $r_n = g$ となる．

したがって，$x_n = 1, \ y_n = 0$ のとき，等式 $r_n x_n + 0 \cdot y_n = g$ が成り立つ．

また，$x_{i-1} = y_i, \ y_{i-1} = x_i - \lfloor r_{i-1} / r_i \rfloor \cdot y_i$ であるから，求めたい組 $(x_0,y_0)$ も導ける．

#### 解の範囲について

上記より，$x_n = 1, \ y_n = 0$ のとき，$x_{n-1} = y_n = 0 = r_{n+1}/g, \ y_{n-1} = x_n - \lfloor r_{n-1} / r_n \rfloor \cdot y_n = 1 = r_n / g$ が成り立つ．

$r_i \geq r_{i+1} \geq 1$ において，$r_i x_i + r_{i+1} y_i = g, \ |x_i| \leq r_{i+1} / g, \ |y_i| \leq r_i / g$ を満たす組 $(x_i, y_i)$ が存在すると仮定する．
このとき $|x_{i-1}| \leq r_i / g, \ |y_{i-1}| \leq r_{i-1} / g$ であることを示す．

はじめに $x_{i-1}$ について，$x_{i-1} = y_i$ であるから，$|x_{i-1}| \leq r_i / g$ が成り立つ．

次に $y_{i-1}$ について，$y_{i-1} = x_i - \lfloor r_{i-1} / r_i \rfloor \cdot y_i$ であるから，

$$
\begin{align}
|y_{i-1}| &\leq |x_i| + \left\lfloor \frac{r_{i-1}}{r_i} \right\rfloor \cdot |y_i| \notag \\
&\leq \frac{r_{i+1}}{g} + \left\lfloor \frac{r_{i-1}}{r_i} \right\rfloor \cdot \frac{r_i}{g} \notag \\
&= \frac{r_{i-1}}{g} \quad \left( \because \ r_{i-1} = \left\lfloor \frac{r_{i-1}}{r_i} \right\rfloor \cdot r_i + r_{i+1} \right) \notag \\
\end{align}
$$

が成り立つ．

よって，帰納法より，$x_n = 1, \ y_n = 0$ のとき，$|x_0| \leq r_1 / g$ かつ $|y_0| \leq r_0 / g$ となることが示された．

#### 計算量の導出

$r_i = \lfloor r_i / r_{i+1} \rfloor \cdot r_{i+1} + r_{i+2}$ なので，$r_{i+2} < r_i / 2$ である．

したがって，行う式変形は高々 $2 \log r_1$ 回であり，計算量は $\mathcal{O}(\log r_1)$ となる．

## 参考

1. H.H. シルヴァーマン. "第6章 一次方程式と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.36-43.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "Extended Euclidean algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm>.
1. drken. "拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜". Qiita. <https://qiita.com/drken/items/b97ff231e43bce50199a>.
1. "拡張ユークリッドの互除法の解の範囲". HatenaBlog. <https://satashun.hatenablog.com/entry/2019/12/30/231319>.
