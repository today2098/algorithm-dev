---
title: Binary Heap（二分ヒープ）
documentation_of: //algorithm/DataStructure/Others/binary_heap.hpp
---


## 概要

（広義の）完全二分木を用いたヒープ．
基本的な機能は `std::priority_queue` と同じ．

ある全順序集合 $S = \lbrace a_1, a_2, \ldots, a_n \rbrace$ の要素を，次のヒープ条件を満たすように完全二分木の各点に割り当て管理する．

> 親の要素は子の要素より常に大きいか等しい

ヒープの根（先頭）は集合 $S$ の中の最大要素となる．

主な操作の計算量は次の通り（ただし，$N$ はヒープに含まれる要素の数）．

|操作|説明|計算量|
|---|---|---|
|`heapify`|ヒープ化|$\mathcal{O}(N)$|
|`size`|要素数の取得|$\mathcal{O}(1)$|
|`top`|先頭要素の参照|$\mathcal{O}(1)$|
|`push`|要素追加|$\mathcal{O}(\log N)$|
|`pop`|先頭要素の削除|$\mathcal{O}(\log N)$|


## 参考

1. 渡邉 敏正. "第4章 ヒープ". データ構造と基本アルゴリズム. 共立出版, 2000, pp.109-126.
1. "6 ヒープソート". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.136-152.
1. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
1. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
1. "優先度付きキュー". Wikipedia. <https://ja.wikipedia.org/wiki/優先度付きキュー>.
1. "全順序". Wikipedia. <https://ja.wikipedia.org/wiki/全順序>.
1. gteu. "なぜヒープ化 (heapify) は O(N) で可能なのか". Qiita. <https://qiita.com/gteu/items/f40bdee41dd6a272a47e>.
