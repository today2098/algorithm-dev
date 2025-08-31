---
title: Modint構造体
documentation_of: //algorithm/Math/ModularArithmetic/modint.hpp
---


## 概要

法 $m \in \mathbb{N}$ における剰余類環 $\mathbb{Z}/m\mathbb{Z}$ の要素を表す構造体．

$0$ 以上 $m$ 未満の整数を値として保存し，剰余類環 $\mathbb{Z}/m\mathbb{Z}$ における加法と乗法の演算をサポートする．

$$
\begin{align}
&a + m \mathbb{Z}, \ b + m \mathbb{Z} \in \mathbb{Z} / m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z}) + (b + m \mathbb{Z}) = (a + b) + m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z})(b + m \mathbb{Z}) = a b + m \mathbb{Z}. \notag\\
\end{align}
$$

また，法 $m$ が素数 $p$ であるとき，剰余類環 $\mathbb{Z}/p\mathbb{Z}$ の零元 $0+p\mathbb{Z}$ を除くすべての元 $a+p\mathbb{Z}$ は乗法逆元 $a^{-1}$ をもち，除法の演算も定義できる．

$$
\frac{b + m \mathbb{Z}}{a + m \mathbb{Z}} = b \cdot a^{-1} + m \mathbb{Z}.
$$

## 参考

1. "整数の合同". Wikipedia. <https://ja.wikipedia.org/wiki/整数の合同>.
1. "剰余類環". Wikipedia. <https://ja.wikipedia.org/wiki/剰余類環>.
1. "モジュラ逆数". Wikipedia. <https://ja.wikipedia.org/wiki/モジュラ逆数>.
1. drken. "「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜". Qiita. <https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a>.
1. "群・環・体". HatenaBlog. <https://zellij.hatenablog.com/entry/20121211/p1>.

## 問題

- "D - Writing a Numeral". AtCoder Beginner Contest 298. AtCoder. <https://atcoder.jp/contests/abc298/tasks/abc298_d>.
