---
title: Binary Indexed Tree
documentation_of: //lib/DataStructure/BIT/binary_indexed_tree.hpp
---


## 概要

「Binary Indexed Tree (BIT)」とは，1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

あるアーベル群 $(S, *: S \times S \rightarrow S, e \in S)$ において，長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対する次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ を $a_i * x$ に更新する
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総積を求める

任意の区間 $[l,r)$ の要素の総積を知りたい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ から求められる．

ここで「アーベル群 (abelian group)」とは，次の性質を満たす組 $(S, *：S \times S \rightarrow S, e \in S)$ による代数的構造のことをいう（交換法則を有する群である）．

1. 結合法則：$a \ast (b \ast c) = (a \ast b) \ast c \quad (\forall a, \forall b, \forall c \in S)$
1. 単位元の存在：$e \ast a = a \ast e = a \quad (\exists e, \forall a \in S)$
1. **逆元の存在**：$a \ast a^{-1} = a^{-1} \ast a = e \quad (\exists e, \forall a, \exists a^{-1} \in S)$
1. **交換法則**：$a \ast b = b \ast a \quad (\forall a, \forall b \in S)$

必要なメモリサイズは対象の配列サイズと同じであり，Segment tree より軽い（Segment tree は2倍程度）．


## 説明

### `algorithm::binary_indexed_tree::BIT<AbelianGroup>`

|テンプレート引数|説明|
|---|---|
|`AbelianGroup`|アーベル群の型．`algorithm::algebra::Group` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`BIT()`|デフォルトコンストラクタ．サイズゼロの `BIT` オブジェクトを構築する．|-|
|`BIT(n)`|コンストラクタ．`n` 個の単位元 `Group::one()` で初期化された要素をもつ `BIT` オブジェクトを構築する．|$\Theta(N)$|
|`BIT(n,a)`|コンストラクタ．`n` 個の `a` で初期化された要素をもつ `BIT` オブジェクトを構築する．|$\Theta(N)$|
|`BIT(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素を用いて `BIT` オブジェクトを構築する．|$\Theta(N)$|
|`BIT(il)`|初期化子リスト `il` を受け取るコンストラクタ．`BIT(il.begin(),il.end())` と等価．|$\Theta(N)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`add(k,a)`|`k` 番目の要素を `a` との積の結果に置き換える．|$\mathcal{O}(\log N)$|
|`x=sum(r)`|区間 `[0,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=sum(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=sum_all()`|全要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`r=most_right(pred)`|`pred(sum(r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[0,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log N)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(N)$|


## 参考

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "アーベル群". Wikipedia. <https://ja.wikipedia.org/wiki/アーベル群>.
1. ngtkana. "データ構造 Fenwick tree (binary indexed tree, BIT) にどっぷりと入門し、その美しき構造に心を洗われたい方のための紹介記事です！". Qiita. <https://qiita.com/ngtkana/items/7d50ff180a4e5c294cb7>.
1. sysdev. "AtCoder Library を読んでアルゴリズムを勉強：フェニック木（BIT）". Qiita. <https://qiita.com/sysdev/items/30aa7d5e9ac4ea871bd3>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 問題

- "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
