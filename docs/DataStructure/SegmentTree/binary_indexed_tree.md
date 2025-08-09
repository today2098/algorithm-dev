---
title: Binary Indexed Tree
documentation_of: //algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
---


## 概要

区間和などの計算や要素更新を効率的に行う木構造．
1994年に Peter Fenwick により提案された．
別名「Fenwick Tree（フェニック木）」．

あるアーベル群 $(G, +: G \times G \rightarrow G, 0 \in G)$ において，長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対する次の操作を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ を $a_i + x$ に更新する
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総積を求める

任意の区間 $[l,r)$ の要素の総積を知りたい場合は，$\operatorname{sum}(r) + (-\operatorname{sum}(l))$ から求められる．

ここで「アーベル群 (abelian group)」とは，次の性質を満たす組 $(G, +：G \times G \rightarrow G, 0 \in G)$ による代数的構造のことをいう（可換律を有する群といえる）．

1. 結合律：$\forall a, b, c \in G, \ a + (b + c) = (a + b) + c$
1. 零元（単位元）の存在：$\exists 0 \in G \ \mathrm{s.t.} \ \forall a \in G, \ a + 0 = 0 + a = a$
1. **逆元の存在**：$\forall a \in G, \ \exists -a, \ a + (-a) = (-a) + a = 0$
1. **可換律**：$\forall a, b \in G, \ a + b = b + a$

必要なメモリ領域は対象の配列サイズと同じであり，Segment tree より軽い（Segment tree は2倍程度）．

## 説明

### algorithm::BIT\<T, AbelianGroup\>

|テンプレート引数|説明|
|---|---|
|`T`|要素の型|
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
|`x=size()`|要素数 `x` を取得する．|$\Theta(1)$|
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
