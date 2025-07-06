---
title: 重み付きUnion-Find
documentation_of: //algorithm/DataStructure/UnionFind/potentialized_union_find.hpp
---


## 概要

「重み付き Union-Find」は，通常の Union-Find を発展させ，各要素にポテンシャルを付加し，要素間のポテンシャルの差分を管理する．

具体的には，次のクエリ操作を高速に行う．
ただし，各集合の代表元のポテンシャルを0とする．

- $\operatorname{potential}(x)$：要素 $x$ のポテンシャルを取得する
- $\operatorname{unite}(x, y, d)$：$\operatorname{potential}(y)-\operatorname{potential}(x)=d$ となるように，要素 $x, y$ が属するそれぞれの集合を合併する
- $\operatorname{issame}(x, y)$：要素 $x, y$ が同じ集合に属するか判定する

主な実装方針は Union-Find と同じで，各クエリ操作の計算量は $\mathcal{O}(\operatorname{\alpha}(N))$ となり，実用上  $\mathcal{O}(1)$ とみなせる（ただし，$\operatorname{\alpha}(x)$ はアッカーマン関数の逆関数）．


## 参考

1. drken. "重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて". Qiita. <https://qiita.com/drken/items/cce6fc5c579051e64fab>.


## 問題

- "D - People on a Line". AtCoder Beginner Contest 087. AtCoder. <https://atcoder.jp/contests/abc087/tasks/arc090_b>.
