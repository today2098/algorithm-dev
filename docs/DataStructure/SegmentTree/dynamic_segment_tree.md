---
title: Dynamic Segment Tree（動的セグメント木）
documentation_of: //algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp
---


## 概要

通常の Segment tree は，全要素分の値を保持するための領域を用意する必要がある．
それに対し，「Dynamic segment tree（動的セグメント木）」は，必要な要素のみに対して更新時に動的に領域確保する．
つまり，扱う要素列の長さを $N$ ，更新のある要素数を $Q \leq N$ とすると，空間計算量は $\mathcal{O}(Q)$ となる．
特に $N$ の制約が大きく，また「クエリを先読みし，座標圧縮する」というテクニックが使えないオンラインクエリの場合に適する．

ただし，Segment tree と異なり次の制約をもつ．

- 初期化時，すべての要素は単位元である必要がある
- 一点取得の時間計算量が $\mathcal{O}(\log Q)$


## 説明

### algorithm::dynamic_segment_tree::DynamicSegmentTree<Monoid>

|テンプレート引数|説明|
|---|---|
|`Monoid`|モノイドの型．`algorithm::algebra::Monoid` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`DynamicSegmentTree()`|デフォルトコンストラクタ．`DynamicSegmentTree(n)` と等価．|$\mathcal{O}(1)$|
|`DynamicSegmentTree(n)`|コンストラクタ．要素数を `n` とした `DynamicSegmentTree` オブジェクトを構築する．全要素は単位元 `Monoid::one()` で初期化されるとみなす．|$\mathcal{O}(1)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`set(k,a)`|`k` 番目の要素を `a` に置き換える．|$\mathcal{O}(\log Q)$|
|`x=prod(k)`|`k` 番目の要素 `x` を取得する．|$\mathcal{O}(Q)$|
|`x=prod(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log Q)$|
|`x=prod_all()`|区間全体の要素の総積 `x` を求める．|$\mathcal{O}(1)$|
|`r=most_right(l,pred)`|`pred(prod(l,r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log Q)$|
|`l=most_left(r,pred)`|`pred(prod(l,r))==true` となる区間の最左位置 `l` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log Q)$|
|`reset(k)`|`k` 番目の要素を単位元 `Monoid::one()` で初期化する．|$\mathcal{O}(Q)$|
|`reset(l,r)`|区間 `[l,r)` の要素を単位元 `Monoid::one()` で初期化する．|$\mathcal{O}(Q)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(Q)$|


## 参考

1. "Dynamic Segment Tree の ACL 風実装". HatenaBlog. <https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644>.


## 問題

- "D - タコヤキオイシクナール". AtCoder Regular Contest 008. AtCoder. <https://atcoder.jp/contests/arc008/tasks/arc008_4>.
