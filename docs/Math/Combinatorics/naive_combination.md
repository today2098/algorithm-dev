---
title: 順列，組合せ，重複組合せ
documentation_of: //lib/Math/Combinatorics/naive_combination.hpp
---


## 概要

順列，組合せ，重複組合せの総数を $\mathcal{O}(K)$ で数え上げる．


#### 順列

$$
{}_n \mathrm{P}_k = n \times (n-1) \times (n-2) \times \cdots \times (n-k+1)
$$


#### 組合せ

$$
\begin{equation}
    {}_n \mathrm{C}_k = 
    \begin{cases}
        0 & \text{if $n<k$,} \\
        {}_n \mathrm{P}_k / k! & \text{otherwise}
    \end{cases}
    \notag
\end{equation}
$$


#### 重複組合せ

$$
\begin{equation}
    {}_n \mathrm{H}_k = 
    \begin{cases}
        1 & \text{if $k=0$,} \\
        0 & \text{if $n=0$ and $k>0$,} \\
        {}_{k+n-1} \mathrm{C}_k & \text{otherwise}
    \end{cases}
    \notag
\end{equation}
$$


## 参考文献

1. "数え上げ数学". Wikipedia. <https://ja.wikipedia.org/wiki/数え上げ数学>.
1. "組合せ数学". Wikipedia. <https://ja.wikipedia.org/wiki/組合せ数学>.
1. "順列". Wikipedia. <https://ja.wikipedia.org/wiki/順列>.
1. "組合せ (数学)". Wikipedia. <https://ja.wikipedia.org/wiki/組合せ_(数学)>.
1. "重複組合せ". Wikipedia. <https://ja.wikipedia.org/wiki/重複組合せ>.


## 問題

- "D - 表現の自由 ( Freedom of expression )". AtCoder Regular Contest 004. <https://atcoder.jp/contests/arc004/tasks/arc004_4>.
- "D - 多重ループ". AtCoder Beginner Contest 021. <https://atcoder.jp/contests/abc021/tasks/abc021_d>.
