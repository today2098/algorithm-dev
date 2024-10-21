## 概要

通常の Segment Tree に対し，扱う配列の長さ $N$ の制約が大きい場合にも対応できる．
特に「クエリを先読みし，座標圧縮する」ということができないオンラインクエリの場合に適する．

本実装では抽象化を行っており，オブジェクト定義時にモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ を定義する．

制約は，配列のすべての要素が単位元 $e$ で初期化されていること．


## 参考文献

1. "Dynamic Segment Tree の ACL 風実装". HatenaBlog. <https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644>.
