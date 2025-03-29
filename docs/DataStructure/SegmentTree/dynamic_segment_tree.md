---
title: Dynamic Segment Tree（動的セグメント木）
documentation_of: //lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp
---


## 概要

通常の Segment Tree は，全要素分の値を保持するための領域を用意する必要がある．
それに対し，Dynamic Segment Tree（動的セグメント木）は，必要な要素についてのみ更新時に動的に領域確保する．
つまり，扱う要素配列の長さを $N$ ，更新のある要素数を $Q \leq N$ とすると，空間計算量は $\mathcal{O}(Q) \leq \mathcal{O}(N)$ となる．
特に，$N$ の制約が大きく，また「クエリを先読みし，座標圧縮する」というテクニックが使えないオンラインクエリの場合に適する．

ただし，一点取得が $\mathcal{O}(\log N)$ となる．
また，初期化時はすべての要素値が単位元 $e$ であるという制約がある．

本実装では抽象化を行っており，オブジェクト定義時にモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ を定義する．


## 参考文献

1. "Dynamic Segment Tree の ACL 風実装". HatenaBlog. <https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644>.


## 問題

- "D - タコヤキオイシクナール". AtCoder Regular Contest 008. AtCoder. <https://atcoder.jp/contests/arc008/tasks/arc008_4>.
