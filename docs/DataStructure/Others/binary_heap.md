---
title: 二分ヒープ
documentation_of: //lib/DataStructure/Others/binary_heap.hpp
---


## 概要

（広義の）完全二分木を用いたヒープ．
基本的な機能は `std::priority_queue` と同じ．

二分ヒープは，ある全順序集合 $S = \lbrace a_1, a_2, \ldots, a_n \rbrace$ の要素を，次のヒープ条件を満たすように完全二分木の各点に割り当て管理する．

> 親の要素は子の要素より常に大きいか等しい

ヒープの根（先頭）は集合 $S$ の中の最大要素になる．

`BinaryHeap` に関する各操作の計算量は次の通り（ただし，$N$ はヒープに含まれる要素の数）． 

| 操作      | 説明           | 計算量                |
| --------- | -------------- | --------------------- |
| `size`    | 要素数の取得   | $\mathcal{O}(1)$      |
| `top`     | 先頭要素の参照 | $\mathcal{O}(1)$      |
| `push`    | 要素追加       | $\mathcal{O}(\log N)$ |
| `pop`     | 先頭要素の削除 | $\mathcal{O}(\log N)$ |
| `heapify` | ヒープ化       | $\mathcal{O}(N)$      |


## 参考文献

1. 渡邉 敏正. "第4章 ヒープ". データ構造と基本アルゴリズム. 共立出版, 2000, pp.109-126.
2. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
3. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
4. "優先度付きキュー". Wikipedia. <https://ja.wikipedia.org/wiki/優先度付きキュー>.
5. "全順序". Wikipedia. <https://ja.wikipedia.org/wiki/全順序>.
