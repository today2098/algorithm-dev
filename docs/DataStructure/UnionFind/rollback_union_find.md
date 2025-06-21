---
title: Rollback付きUnion-Find
documentation_of: //lib/DataStructure/UnionFind/rollback_union_find.hpp
---


## 概要

「Rollback 付き Union-Find」は，通常の Union-Find の機能に加え，グループ合併時に親についての情報を保存することにより直前の状態に戻せるようにしたもの．
このロールバック操作は不可逆である．

本実装では「union by size」のみによる工夫を行っており，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考

1. "Union-Find木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/union_find_tree>.
