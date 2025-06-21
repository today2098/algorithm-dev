---
title: Bellman-Ford Algorithm（単一始点最短経路）
documentation_of: //lib/Graph/ShortestPath/bellman_ford.hpp
---


## 概要

重み付き有向グラフにおける単一始点最短経路問題を解くアルゴリズム．
グラフの負閉路検出も行うことができる．
1956年と1958年に，L. R. Ford Jr. と Richard E. Bellman がそれぞれ独立に考案した．

計算量は，グラフの頂点集合を $V$ ，辺集合を $E$ とすると，$\mathcal{O}(\lvert V \rvert \lvert E \rvert)$ となる．


## 参考

1. 大槻 兼資. "14.5 単一始点最短路問題：ベルマン・フォード法". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉 拓哉監修. 講談社, 2020, p.249-254.
1. "22.1 Bellman-Fordのアルゴリズム". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.515-519.
1. "ベルマン–フォード法". Wikipedia. <https://ja.wikipedia.org/wiki/ベルマン–フォード法>.
