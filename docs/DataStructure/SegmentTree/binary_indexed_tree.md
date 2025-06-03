---
title: Binary Indexed Tree
documentation_of: //lib/DataStructure/SegmentTree/binary_indexed_tree.hpp
---


## 概要

「Binary Indexed Tree (BIT)」とは，1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対して，次のクエリ処理 (RSM: Range Sum Query) を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総和を求める．

任意の区間 $[l,r)$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ と求めればよい．

必要なメモリサイズは，対象の配列サイズと同じ（Segment Tree では2倍程度必要となる）．

本実装では，数の加算のみをサポートしているが，拡張すればアーベル群（可換群）を成す他の演算もサポートすることができる．

ここで「アーベル群」とは，集合 $G$ と二項演算 $\ast : S \times S \rightarrow S$ の組 $(G, \ast)$ で，以下の条件を満たす代数構造のことを指す．

1. 結合法則：$a \ast (b \ast c) = (a \ast b) \ast c \quad (\forall a, \forall b, \forall c \in G)$
1. 単位元の存在：$e \ast a = a \ast e = a \quad (\exists e, \forall a \in G)$
1. **逆元の存在**：$a \ast a^{-1} = a^{-1} \ast a = e \quad (\exists e, \forall a, \exists a^{-1} \in G)$
1. **交換法則**：$a \ast b = b \ast a \quad (\forall a, \forall b \in G)$

Segment Tree が扱うのは「モノイド」であり，モノイドは上記条件の (1), (2) のみを満たせばよい．
それに対し，BIT は条件 (3), (4) が加わり制約が厳しい．


## 説明

### algorithm::BIT

|メンバ関数|説明|計算量|
|---|---|---|
|`BIT<T>()`|デフォルトコンストラクタ．サイズゼロの `BIT` オブジェクトを構築する．|$\mathcal{O}(N)$|
|`BIT<T>(n)`|コンストラクタ．`n` 個の `T()` で初期化された要素をもつ `BIT` オブジェクトを構築する．|$\mathcal{O}(N)$|
|`BIT<T>(n,a)`|コンストラクタ．`n` 個の `a` で初期化された要素をもつ `BIT` オブジェクトを構築する．|$\mathcal{O}(N)$|
|`BIT<T>(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素で `BIT` オブジェクトを構築する．|$\mathcal{O}(N)$|
|`BIT<T>(il)`|コンストラクタ．初期化子リストの要素で `BIT` オブジェクトを構築する．|$\mathcal{O}(N)$|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`add(k,a)`|`k` 番目の要素に `a` を加算する．|$\mathcal{O}(\log N)$|
|`x=sum(r)`|区間 `[0,r)` の要素の総和 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=sum(l,r)`|区間 `[l,r)` の要素の総和 `x` を求める．|$\mathcal{O}(\log N)$|
|`reset()`|全要素を `T()` で初期化する．|$\mathcal{O}(N)$|


## 参考

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "アーベル群". Wikipedia. <https://ja.wikipedia.org/wiki/アーベル群>.
1. ngtkana. "データ構造 Fenwick tree (binary indexed tree, BIT) にどっぷりと入門し、その美しき構造に心を洗われたい方のための紹介記事です！". Qiita. <https://qiita.com/ngtkana/items/7d50ff180a4e5c294cb7>.
1. sysdev. "AtCoder Library を読んでアルゴリズムを勉強：フェニック木（BIT）". Qiita. <https://qiita.com/sysdev/items/30aa7d5e9ac4ea871bd3>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 問題

- "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
