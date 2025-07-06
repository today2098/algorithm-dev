---
title: きたまさ法
documentation_of: //algorithm/Math/Algebra/kitamasa.hpp
---


## 概要

初めの $k$ 項 $\lbrace a_0, a_1, \ldots, a_{k-1} \rbrace$ と $k$ 階線形漸化式

$$
a_n = d_0 \cdot a_{n-k} + d_1 \cdot a_{n-(k-1)} + \cdots + d_{k-1} \cdot a_{n-1}
$$

によって定まる数列の任意の項 $a_N$ を $\mathcal{O}(k^2 \log N)$ で求める．


### アルゴリズムの説明

#### 方針

説明のため，

$$
a_n = D(n,0) \cdot a_0 + D(n,1) \cdot a_1 + \cdots + D(n,k-1) \cdot a_{k-1} = \sum_{i=0}^{k-1} D(n,i) \cdot a_{i}
$$

となる $D(n,*)$ を定義する（ただし，$n \geq 0$ ）．

このとき，

$$
\begin{equation}
D(0,i) = 
    \begin{cases}
    1 &\text{if \ $i=0$,} \\
    0 &\text{otherwise}
    \end{cases} \notag
\end{equation}
$$

である．

きたまさ法の方針は，$D(n,*) \rightarrow D(n+1,*), D(n,*) \rightarrow D(2n,*)$ を計算することにより，繰り返し二乗法と同じ要領で $D(0,*)$ から $D(N,*)$ を求めることである．


#### $D(n,*) \rightarrow D(n+1,*)$ の計算

まず，前提として $D(n,*)$ が分かっていると仮定する．
このとき，

$$
\begin{align}
a_{n+1} &= D(n,0) \cdot a_1 + D(n,1) \cdot a_2 + \cdots + D(n,k-2) \cdot a_{k-1} + D(n,k-1) \cdot a_k \notag\\
    &= D(n,0) \cdot a_1 + D(n,1) \cdot a_2 + \cdots + D(n,k-2) \cdot a_{k-1} + D(n,k-1) \cdot (d_0 \cdot a_0 + d_1 \cdot a_1 + \cdots + d_{k-1} \cdot a_{k-1}) \notag\\
    &= D(n,k-1) \cdot d_0 \cdot a_0 + (D(n,0) + D(n,k-1) \cdot d_1) \cdot a_1 + (D(n,1) + D(n,k-1) \cdot d_2) \cdot a_2 + \cdots + (D(n,k-2) + D(n,k-1)  \cdot d_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
\begin{equation}
D(n+1,i) = 
    \begin{cases}
    D(n,k-1) \cdot d_0 &\text{if \ $i=0$,} \\
    D(n,i-1) + D(n,k-1)  \cdot d_i &\text{otherwise}
    \end{cases} \notag
\end{equation}
$$

と求まる．
これは $\mathcal{O}(k)$ で計算できる．


#### $D(n,*) \rightarrow D(2n,*)$ の計算

先の方法で $D(n,*), D(n+1,*), \ldots, D(n+k-1,*)$ が $\mathcal{O}(k^2)$ で列挙できるとする．
このとき，

$$
\begin{align}
a_{2n} &= D(n,0) \cdot a_n + D(n,1) \cdot a_{n+1} + \cdots + D(n,k-1) \cdot a_{n+k-1} \notag\\
    &= D(n,0) \cdot (D(n,0) \cdot a_0 + D(n,1) \cdot a_1 + \cdots + D(n,k-1) \cdot a_{k-1}) \notag\\
    &\quad + D(n,1) \cdot (D(n+1,0) \cdot a_0 + D(n+1,1) \cdot a_1 + \cdots + D(n+1,k-1) \cdot a_{k-1}) \notag\\
    &\quad + \cdots \notag\\
    &\quad + D(n,k-1) \cdot (D(n+k-1,0) \cdot a_0 + D(n+k-1,1) \cdot a_1 + \cdots + D(n+k-1,k-1) \cdot a_{k-1}) \notag\\
    &= (D(n,0) \cdot D(n,0) + D(n,1) \cdot D(n+1,0) + \cdots + D(n,k-1) \cdot D(n+k-1,0)) \cdot a_0 \notag\\
    &\quad + (D(n,0) \cdot D(n,1) + D(n,1) \cdot D(n+1,1) + \cdots + D(n,k-1) \cdot D(n+k-1,1)) \cdot a_1 \notag\\
    &\quad + \cdots \notag\\
    &\quad + (D(n,0) \cdot D(n,k-1) + D(n,1) \cdot D(n+1,k-1) + \cdots + D(n,k-1) \cdot D(n+k-1,k-1)) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
D(2n,i) = \sum_{j=0}^{k-1} D(n,j) \cdot D(n+j,i)
$$

と求まる．
これは $\mathcal{O}(k^2)$ で計算できる．

よって，繰り返し二乗法と同じ要領で $D(0,*)$ から $D(N,*)$ を $\mathcal{O}(k^2 \log N)$ で求めることができる．


## 参考文献

1. "漸化式". Wikipedia. <https://ja.wikipedia.org/wiki/漸化式>.
1. yosupo. "きたまさ法メモ". HatenaBlog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.
1. smijake3. "Kitamasa法". HatenaBlog. <https://smijake3.hatenablog.com/entry/2017/01/02/024712>.


## 問題

- "T - フィボナッチ". Typical CP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
