---
title: きたまさ法
documentation_of: //lib/Math/Algebra/kitamasa.hpp
---


## 概要

初めの $k$ 項 $\lbrace a_0, a_1, \ldots, a_{k-1} \rbrace$ と $k$ 階線形漸化式

$$
a_n = c_0 \cdot a_{n-k} + c_1 \cdot a_{n-(k-1)} + \cdots + c_{k-1} \cdot a_{n-1}
$$

によって定まる数列の任意の項 $a_N$ を $\mathcal{O}(k^2 \log N)$ で求める．


### アルゴリズムの説明

#### 方針

説明のため，

$$
a_n = C(n,0) \cdot a_0 + C(n,1) \cdot a_1 + \cdots + C(n,k-1) \cdot a_{k-1} = \sum_{i=0}^{k-1} C(n,i) \cdot a_{i}
$$

となる $C(n,*)$ を定義する（ただし，$n \geq 0$ ）．

このとき，

$$
\begin{equation}
C(0,i) = 
    \begin{cases}
    1 &\text{if \ $i=0$,} \\
    0 &\text{if \ $0<i<k$}
    \end{cases} \notag
\end{equation}
$$

である．


きたまさ法の方針は，$C(n,*) \rightarrow C(n+1,*), C(n,*) \rightarrow C(2n,*)$ を計算することにより，繰り返し二乗法と同じ要領で $C(0,*)$ から $C(N,*)$ を求めることである．


#### $C(n,*) \rightarrow C(n+1,*)$ の計算

まず，前提として $C(n,*)$ が分かっていると仮定する．
このとき，

$$
\begin{align}
a_{n+1} &= C(n,0) \cdot a_1 + C(n,1) \cdot a_2 + \cdots + C(n,k-2) \cdot a_{k-1} + C(n,k-1) \cdot a_k \notag\\
    &= C(n,0) \cdot a_1 + C(n,1) \cdot a_2 + \cdots + C(n,k-2) \cdot a_{k-1} + C(n,k-1) \cdot (c_0 \cdot a_0 + c_1 \cdot a_1 + \cdots + c_{k-1} \cdot a_{k-1}) \notag\\
    &= C(n,k-1) \cdot c_0 \cdot a_0 + (C(n,0) + C(n,k-1) \cdot c_1) \cdot a_1 + (C(n,1) + C(n,k-1) \cdot c_2) \cdot a_2 + \cdots + (C(n,k-2) + C(n,k-1)  \cdot c_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
\begin{equation}
C(n+1,i) = 
    \begin{cases}
    C(n,k-1) \cdot c_0 &\text{if \ $i=0$,} \\
    C(n,i-1) + C(n,k-1)  \cdot c_i &\text{if \ $0<i<k$}
    \end{cases} \notag
\end{equation}
$$

と求まる．
これは $\mathcal{O}(k)$ で計算できる．


#### $C(n,*) \rightarrow C(2n,*)$ の計算

先の方法で $C(n,*), C(n+1,*), \ldots, C(n+k-1,*)$ が $\mathcal{O}(k^2)$ で列挙できるとする．
このとき，

$$
\begin{align}
a_{2n} &= C(n,0) \cdot a_n + C(n,1) \cdot a_{n+1} + \cdots + C(n,k-1) \cdot a_{n+k-1} \notag\\
    &= C(n,0) \cdot (C(n,0) \cdot a_0 + C(n,1) \cdot a_1 + \cdots + C(n,k-1) \cdot a_{k-1}) \notag\\
    &\quad + C(n,1) \cdot (C(n+1,0) \cdot a_0 + C(n+1,1) \cdot a_1 + \cdots + C(n+1,k-1) \cdot a_{k-1}) \notag\\
    &\quad + \cdots \notag\\
    &\quad + C(n,k-1) \cdot (C(n+k-1,0) \cdot a_0 + C(n+k-1,1) \cdot a_1 + \cdots + C(n+k-1,k-1) \cdot a_{k-1}) \notag\\
    &= (C(n,0) \cdot C(n,0) + C(n,1) \cdot C(n+1,0) + \cdots + C(n,k-1) \cdot C(n+k-1,0)) \cdot a_0 \notag\\
    &\quad + (C(n,0) \cdot C(n,1) + C(n,1) \cdot C(n+1,1) + \cdots + C(n,k-1) \cdot C(n+k-1,1)) \cdot a_1 \notag\\
    &\quad + \cdots \notag\\
    &\quad + (C(n,0) \cdot C(n,k-1) + C(n,1) \cdot C(n+1,k-1) + \cdots + C(n,k-1) \cdot C(n+k-1,k-1)) \cdot a_{k-1} \notag\\
\end{align}
$$

となるから，

$$
C(2n,i) = \sum_{j=0}^{k-1} C(n,j) \cdot C(n+j,i)
$$

と求まる．
これは $\mathcal{O}(k^2)$ で計算できる．

よって，繰り返し二乗法と同じ要領で $C(0,*)$ から $C(N,*)$ を $\mathcal{O}(k^2 \log N)$ で求めることができる．


## 参考文献

1. "漸化式". Wikipedia. <https://ja.wikipedia.org/wiki/漸化式>.
1. yosupo. "きたまさ法メモ". HatenaBlog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.
1. smijake3. "Kitamasa法". HatenaBlog. <https://smijake3.hatenablog.com/entry/2017/01/02/024712>.


## 問題

- "T - フィボナッチ". Typical CP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
