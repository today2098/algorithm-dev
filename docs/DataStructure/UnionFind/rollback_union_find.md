## 概要

「Rollback 付き Union-Find」は，通常の Union-Find の機能に加え，グループの併合時に親についての情報を保存することにより前の状態に戻せるようにしたもの．
このロールバック処理は不可逆である．

本実装では「union by size」の工夫のみ行い，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考文献

1. "Union-Find木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/union_find_tree>.
