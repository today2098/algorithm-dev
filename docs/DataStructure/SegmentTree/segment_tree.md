---
title: Segment Tree
documentation_of: //algorithm/DataStructure/SegmentTree/segment_tree.hpp
---


## 概要

任意のモノイドを扱う「抽象セグメント木」．

あるモノイド $(S, \bullet: S \times S \rightarrow S, e \in S)$ において，長さ $N$ の要素列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対する次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新**：要素 $a_i$ を $x$ で更新する
- **区間取得**：区間 $[l,r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する

ここで「モノイド (monoid)」とは，次の性質を満たす組 $(S, \bullet : S \times S \rightarrow S, e \in S)$ による代数的構造のことをいう．

1. 結合律：$\forall a, b, c \in S, \ a \bullet (b \bullet c) = (a \bullet b) \bullet c$
1. 単位元の存在：$\exists e \in S \ \mathrm{s.t.} \ \forall a \in S, \ a \bullet e = e \bullet a = a$

例えば，自然数全体 $\mathbb{N}$ は加法に関して $0$ を単位元にもつモノイドを成す．

## 説明

### algorithm::SegmentTree\<S,Monoid\>

|テンプレート引数|説明|
|---|---|
|`S`|要素の型|
|`Monoid`|モノイドの型．`algorithm::algebra::Monoid` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`SegmentTree()`|デフォルトコンストラクタ．サイズゼロの `SegmentTree` オブジェクトを構築する．|-|
|`SegmentTree(n)`|コンストラクタ．`n` 個の単位元 `Monoid::one()` で初期化された要素をもつ `SegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`SegmentTree(n,a)`|コンストラクタ．`n` 個の `a` で初期化された要素をもつ `SegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`SegmentTree(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素を用いて `SegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`SegmentTree(il)`|初期化子リスト `il` を受け取るコンストラクタ．`SegmentTree(il.begin(),il.end())` と等価．|$\Theta(N)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\Theta(1)$|
|`set(k,a)`|`k` 番目の要素を `a` に置き換える．|$\Theta(\log N)$|
|`x=prod(k)`|`k` 番目の要素 `x` を取得する．|$\Theta(1)$|
|`x=prod(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=prod_all()`|区間全体の要素の総積 `x` を求める．|$\Theta(1)$|
|`r=most_right(l,pred)`|`pred(prod(l,r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log N)$|
|`l=most_left(r,pred)`|`pred(prod(l,r))==true` となる区間の最左位置 `l` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log N)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(N)$|

## 参考

1. "SegTree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/segtree.html>.
1. "モノイド". Wikipedia. <https://ja.wikipedia.org/wiki/モノイド>.
1. rsk0315. "セグ木のお勉強を敬遠している人へ". えびちゃんの日記. HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/07/05/184929>.
1. "セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree>.

## 問題

- "J - Segment Tree". AtCoder Library Practice Contest. <https://atcoder.jp/contests/practice2/tasks/practice2_j>.
