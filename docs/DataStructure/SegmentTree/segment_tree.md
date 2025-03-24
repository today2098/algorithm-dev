---
title: Segment Tree
documentation_of: //lib/DataStructure/SegmentTree/segment_tree.hpp
---


## 概要

長さ $N$ の配列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新**：要素 $a_i$ を $x$ で更新する
- **区間取得**：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する

本ライブラリで実装している Segment Tree は，いわゆる「抽象セグメント木」であり，オブジェクトを定義する際に扱うモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ を定義する．

ここで「モノイド」とは，集合 $S$ とその上の二項演算 $\bullet : S \times S \rightarrow S$ をもち，以下の条件を満たす代数構造のことをいう．

- 結合律：$(a \bullet b) \bullet c = a \bullet (b \bullet c) \quad (\forall a, \forall b, \forall c \in S)$
- 単位元の存在：$e \bullet a = a \bullet e = a \quad (e \in S, \forall a \in S)$

例えば，整数全体は加法あるいは乗法に関してモノイドを成す．


## 参考文献

1. "SegTree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/segtree.html>.
1. "モノイド". Wikipedia. <https://ja.wikipedia.org/wiki/モノイド>.
1. rsk0315. "セグ木のお勉強を敬遠している人へ". えびちゃんの日記. HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/07/05/184929>.
1. "セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree>.
