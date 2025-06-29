---
title: Partially Persistent Union-Find（部分永続Unionf-Find）
documentation_of: //lib/DataStructure/UnionFind/partially_persistent_union_find.hpp
---


## 概要

「部分永続 Union-Find」では，通常の Union-Find の機能に加え，過去の状態に対してクエリを求めることができる．
ただし，更新が行えるのは最新の状態に対してのみ．

本実装では「union by size」の工夫のみ行い，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考

1. "Union-Find木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/union_find_tree>.
1. "やぶについて書きます". <https://camypaper.bitbucket.io/2016/12/18/adc2016/>.


## 問題

- "H - Union Sets". CODE THANKS FESTIVAL 2017(Parallel). AtCoder. <https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h>.
