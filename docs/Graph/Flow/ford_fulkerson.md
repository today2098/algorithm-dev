---
title: Ford-Fulkerson Algorithm（最大流問題）
documentation_of: //algorithm/Graph/Flow/ford_fulkerson.hpp
---


## 概要

最大流問題 (maximum-flow problem) を解くアルゴリズム．
1956年に L. R. Ford Jr. と D. R. Fulkerson によって考案された．


### フローネットワークと最大流問題の定義

「フローネットワーク (flow network)」とは，各辺 $(u,v) \in E$ が容量 (capacity) $c(u,v) \geq 0 \ (c: V \times V \rightarrow \mathbb{R})$ をもち，また始点 (source) $s \in V$ と終点 (sink) $t \in V$ の2頂点をもつ有向グラフ $G = (V,E)$ のことをいう．
便宜上，$(u,v) \notin E$ のとき $c(u,v) = 0$ とみなし，自己ループはないものとする．

$G$ における「フロー (flow)」は，次の2条件を満たす関数 $f: V \times V \rightarrow \mathbb{R}$ である．

1. 容量制限：$0 \leq f(u,v) \leq c(u,v) \ (\forall u, \forall v \in V)$
1. フロー保存則：$\sum_{v \in V} f(u,v) = \sum_{v \in V} f(v,u) \ (\forall u \in V-\{s,t\})$

そして，フロー $f$ の値 $\lvert f \rvert$ は次のように定義される（ここでの $\lvert \cdot \rvert$ の表記は絶対値や要素数を表していない）．

$$
|f| = \sum_{v \in V} f(s,v) - \sum_{v \in V} f(v,s)
$$

「最大流問題」とは，与えられたフローネットワーク $G$ に対し，$s$ から $t$ への最大値をもつフローを求める問題である．


### アルゴリズムの説明

Ford-Fulkerson algorithm では，次の手続きを反復し，徐々にフローを増やして解に近づけていく．

1. DFS により，残余ネットワーク上の増加可能パスを探す
1. 発見した増加可能パス上の辺に対してフローを増減させ，残余ネットワークを更新する
1. 残余ネットワーク上から増加可能パスがなくなるまで繰り返す

求める最大のフローを $f^*$ とすると，上記手続きの反復回数は高々 $\lvert f^* \rvert$ 回である．
各反復時の DFS に $\mathcal{O}(\lvert E \rvert)$ の計算量を要し，全体の計算量は $\mathcal{O}(\lvert f^* \rvert \lvert E \rvert)$ となる．


## 参考

1. 大槻兼資著. "第16章 グラフ (4)：ネットワークフロー". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, pp.283-309. 
1. "24 最大フロー". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.563-591.
1. "フローネットワーク". Wikipedia. <https://ja.wikipedia.org/wiki/フローネットワーク>.
1. "最大フロー問題". Wikipedia. <https://ja.wikipedia.org/wiki/最大フロー問題>.
1. "Ford–Fulkerson algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm>.
1. "フォード・ファルカーソンのアルゴリズム". Wikipedia. <https://ja.wikipedia.org/wiki/フォード・ファルカーソンのアルゴリズム>.


## 問題

- "D - Maxflow". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_d>.
