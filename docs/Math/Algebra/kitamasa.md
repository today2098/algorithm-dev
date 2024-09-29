## 概要

初めの $k$ 項 $\lbrace a_0, a_1, \ldots, a_{k-1} \rbrace$ と $k$ 階線形漸化式

$$
a_n = d_0 \cdot a_{n-k} + d_1 \cdot a_{n-(k-1)} + \cdots + d_{k-1} \cdot a_{n-1}
$$

によって定まる数列の任意の項 $a_n$ を $\mathcal{O}(k^2 \log n)$ で求める．


### アルゴリズムの説明

このアルゴリズムの主な方針は，

$$
a_n = x_{(n)0} \cdot a_0 + x_{(n)1} \cdot a_1 + \cdots + x_{(n)k-1} \cdot a_{k-1}
$$

となる $f(n) = \lbrace x_{(n)0}, x_{(n)1}, \ldots, x_{(n)k-1} \rbrace$ を求めることである．

まず，前提として $f(i)$ が分かっていると仮定する．
このとき，

$$
a_i = x_{(i)0} \cdot a_0 + x_{(i)1} \cdot a_1 + \cdots + x_{(i)k-2} \cdot a_{k-2} + x_{(i)k-1} \cdot a_{k-1} \notag
$$

とすると，

$$
\begin{align}
a_{i+1} &= x_{(i)0} \cdot a_1 + x_{(i)1} \cdot a_2 + \cdots + x_{(i)k-2} \cdot a_{k-1} + x_{(i)k-1} \cdot a_k \notag\\
a_{i+1} &= x_{(i)0} \cdot a_1 + x_{(i)1} \cdot a_2 + \cdots + x_{(i)k-2} \cdot a_{k-1} + x_{(i)k-1} \cdot (d_0 \cdot a_0 + d_1 \cdot a_1 + \cdots + d_{k-1} \cdot a_{k-1}) \notag\\

a_{i+1} &= x_{(i)k-1} \cdot d_0 \cdot a_0 + (x_{(i)0} + x_{(i)k-1} \cdot d_1) \cdot a_1 + (x_{(i)1} + x_{(i)k-1} \cdot d_2) \cdot a_2 + \cdots + (x_{(i)k-2} + x_{(i)k-1} \cdot d_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

より，$f(i+1)$ が $\mathcal{O}(k)$ で求められる．

また，先の方法で $f(i), f(i+1), \ldots, f(i+k-1)$ が $\mathcal{O}(k^2)$ で列挙できるとする．
このとき，

$$
\begin{align}
a_{2i} &= x_{(i)0} \cdot a_i + x_{(i)1} \cdot a_{i+1} + \cdots + x_{(i)k-1} \cdot a_{i+k-1} \notag\\
a_{2i} &= x_{(i)0} \cdot (x_{(i)0} \cdot a_0 + x_{(i)1} \cdot a_1 + \cdots + x_{(i)k-1} \cdot a_{k-1}) \notag\\
    &\quad + x_{(i)1} \cdot (x_{(i+1)0} \cdot a_0 + x_{(i+1)1} \cdot a_1 + \cdots + x_{(i+1)k-1} \cdot a_{k-1}) \notag\\
    &\quad + \cdots \notag\\
    &\quad + x_{(i)k-1} \cdot (x_{(i+k-1)0} \cdot a_0 + x_{(i+k-1)1} \cdot a_1 + \cdots + x_{(i+k-1)k-1} \cdot a_{k-1}) \notag\\
a_{2i} &= (x_{(i)0} \cdot x_{(i)0} + x_{(i)1} \cdot x_{(i+1)0} + \cdots + x_{(i)k-1} \cdot x_{(i+k-1)0}) \cdot a_0 \notag\\
    &\quad + (x_{(i)0} \cdot x_{(i)1} + x_{(i)1} \cdot x_{(i+1)1} + \cdots + x_{(i)k-1} \cdot x_{(i+k-1)1}) \cdot a_1 \notag\\
    &\quad + \cdots \notag\\
    &\quad + (x_{(i)0} \cdot x_{(i)k-1} + x_{(i)1} \cdot x_{(i+1)k-1} + \cdots + x_{(i)k-1} \cdot x_{(i+k-1)k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

となり，$f(2i)$ が $\mathcal{O}(k^2)$ で求められる．

よって，「繰り返し二乗法」と同じ要領で $f(k) = \lbrace d_0, d_1, \ldots, d_{k-1} \rbrace$ から $f(n)$ を求めることができ，全体の計算量は $\mathcal{O}(k^2 \log n)$ となる．


## 参考文献

1. yosupo. "きたまさ法メモ". HatenaBlog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.


## 問題

- "T - フィボナッチ". Typical DP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
