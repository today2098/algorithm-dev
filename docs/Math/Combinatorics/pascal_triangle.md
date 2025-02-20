---
title: Pascal's Triangle（パスカルの三角形）
documentation_of: //lib/Math/Combinatorics/pascal_triangle.hpp
---


## 概要

パスカルの三角形とは，二項展開における係数を三角形状に並べたもの．

次の公式を利用し，二項係数のテーブルを構築する．

$$
{}_n C_k = {}_{n-1} C_{k-1} + {}_{n-1} C_{k}
$$

計算量は，時間と空間のともに $\mathcal{O}(N^2)$ を要する．


## 参考文献

1. "パスカルの三角形". Wikipedia. <https://ja.wikipedia.org/wiki/パスカルの三角形>.
