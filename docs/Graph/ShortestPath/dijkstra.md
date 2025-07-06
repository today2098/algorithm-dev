---
title: Dijkstra's Algorithm（単一始点最短経路）
documentation_of: //algorithm/Graph/ShortestPath/dijkstra.hpp
---


## 概要

重み付き有向グラフにおける単一始点最短経路問題を解くアルゴリズム．
前提条件はグラフに負閉路がないこと．
1959年に Edsger W. Dijkstra によって考案された．

本実装では優先度付きキューを用いて高速化を図っている．

計算量は，グラフの頂点集合を $V$，辺集合を $E$ とすると，$\mathcal{O}(\lvert E \rvert \log \lvert V \rvert)$ となる．


## 参考

1. 大槻兼資著. "14.6 単一始点最短路問題：ダイクストラ法". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, pp.254-264.
1. "22.3 Dijkstraのアルゴリズム". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.522-527.
1. "ダイクストラ法". Wikipedia. <https://ja.wikipedia.org/wiki/ダイクストラ法>.
