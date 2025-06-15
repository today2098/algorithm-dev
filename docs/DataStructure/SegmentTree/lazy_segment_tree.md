---
title: Lazy Segment Tree（遅延評価セグメント木）
documentation_of: //lib/DataStructure/LazySegmentTree/lazy_segment_tree.hpp
---


##  概要

単純な Segment tree が処理するクエリは一点更新・区間取得であるのに対し，「Lazy segment tree（遅延評価セグメント木）」は**区間更新**・区間取得のクエリを処理する．

具体的には，あるモノイド $(S, \bullet: S \times S \rightarrow S, e \in S)$ と作用素モノイド $(F, \circ : F \times F \rightarrow F, id \in F, S, . : F \times S \rightarrow S)$ において，長さ $N$ の要素列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対する次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **区間更新**：区間 $[l, r)$ の要素 $a_l, a_{l+1}, \ldots, a_{r-1}$ を作用素 $f$ を用いて更新する ( $x=f.x$ )
- **区間取得**：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する

ここで「作用素モノイド」とは，次の性質を満たす組 $(F, \circ : F \times F \rightarrow F, id \in F, S, . : F \times S \rightarrow S)$ による代数的構造のことをいう．

1. 組 $(F, \circ, id)$ がモノイドを成す
1. $id.x = x \quad (\forall x \in S)$
1. $f.(g.x) = (f \circ g).x \quad (\forall f, \forall g \in F, \forall x \in S)$

Lazy segment tree にのせるモノイドと作用素モノイドは次の条件を満たす必要がある（準同型）．

- 分配律：$f.(x \bullet y) = f.x \bullet f.y \quad (\forall f \in F, \forall x, \forall y \in S)$


## 説明

### `algorithm::lazy_segment_tree::LazySegmentTree<Monoid,OperatorMonoid>`

|テンプレート引数|説明|
|---|---|
|`Monoid`|モノイドの型．`algorithm::algebra::Monoid` を想定している．|
|`OperatorMonoid`|作用素モノイドの型．`algorithm::algebra::OperatorMonoid` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`LazySegmentTree()`|デフォルトコンストラクタ．サイズゼロの `LazySegmentTree` オブジェクトを構築する．|-|
|`LazySegmentTree(n)`|コンストラクタ．`n` 個の単位元 `Monoid::one()` で初期化された要素をもつ `LazySegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`LazySegmentTree(n,a)`|コンストラクタ．`n` 個の `a` で初期化された要素をもつ `LazySegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`LazySegmentTree(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素を用いて `LazySegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`LazySegmentTree(il)`|初期化子リスト `il` を受け取るコンストラクタ．`LazySegmentTree(il.begin(),il.end())` と等価．|$\Theta(N)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`set(k,a)`|`k` 番目の要素を `a` に置き換える．|$\Theta(\log N)$|
|`apply(k,f)`|`k` 番目の要素を作用素 `f` を用いて更新する．|$\Theta(\log N)$|
|`apply(l,r,f)`|区間 `[l,r)` の要素を作用素 `f` を用いて更新する．|$\Theta(\log N)$|
|`x=prod(k)`|`k` 番目の要素 `x` を取得する．|$\Theta(\log N)$|
|`x=prod(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\Theta(\log N)$|
|`x=prod_all()`|区間全体の要素の総積 `x` を求める．|$\mathcal{O}(1)$|
|`r=most_right(l,pred)`|`pred(prod(l,r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\Theta(\log N)$|
|`l=most_left(r,pred)`|`pred(prod(l,r))==true` となる区間の最左位置 `l` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\Theta(\log N)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(N)$|


## 参考

1. "Lazy Segtree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html>.
1. "作用素". Wikipedia. <https://ja.wikipedia.org/wiki/作用素>.
1. "モノイド作用と作用素モノイド". Wikipedia. <https://ja.wikipedia.org/wiki/モノイド#モノイド作用と作用素モノイド>.
1. "準同型". Wikipedia. <https://ja.wikipedia.org/wiki/準同型>.
1. betrue12. "Atcoder LibraryのLazy Segtreeの使い方". Hatena Blog. <https://betrue12.hateblo.jp/entry/2020/09/22/194541>.
1. "Segment木の種類とその要件". うさぎ小屋. <https://kmyk.github.io/blog/blog/2017/01/17/segment-tree-requirements/>.
1. "遅延評価セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree>.


## 問題

- "K - Range Affine Range Sum". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_k>.
- "L - Lazy Segment Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_l>.
