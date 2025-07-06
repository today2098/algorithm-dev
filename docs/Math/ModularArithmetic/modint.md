---
title: Modint構造体
documentation_of: //algorithm/Math/ModularArithmetic/modint.hpp
---


## 概要

任意の自然数 $m \geq 1$ を法として，四則演算時に剰余をとる構造体．

自然数 $m$ を法とする剰余類の代表元（$0$ 以上 $m$ 未満）を値として保存し，剰余類環 $\mathbb{Z}/m\mathbb{Z}$ における加法と乗法の演算をサポートする．

$$
\begin{align}
&a + m \mathbb{Z}, \ b + m \mathbb{Z} \in \mathbb{Z} / m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z}) + (b + m \mathbb{Z}) = (a + b) + m \mathbb{Z}, \notag\\
&(a + m \mathbb{Z})(b + m \mathbb{Z}) = a b + m \mathbb{Z} \notag\\
\end{align}
$$

また，任意の素数 $p$ を法としたときは，剰余体 $\mathbb{Z}/p\mathbb{Z}$ において $0+p\mathbb{Z}$ 以外の剰余類  $a+p\mathbb{Z} \in \mathbb{Z}/p\mathbb{Z}$ は乗法逆元 $a^{-1}$ をもち，除法の演算もサポートする．

$$
\frac{b + m \mathbb{Z}}{a + m \mathbb{Z}} = b \cdot a^{-1} + m \mathbb{Z}
$$


## 参考文献

1. "剰余類環". Wikipedia. <https://ja.wikipedia.org/wiki/剰余類環>.
1. "モジュラ逆数". Wikipedia. <https://ja.wikipedia.org/wiki/モジュラ逆数>.
1. drken. "「1000000007 で割ったあまり」の求め方を総特集！ 〜 逆元から離散対数まで 〜". Qiita. <https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a>.
1. "群・環・体". HatenaBlog. <https://zellij.hatenablog.com/entry/20121211/p1>.
