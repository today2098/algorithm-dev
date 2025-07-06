---
title: Sparse Table
documentation_of: //algorithm/DataStructure/SegmentTree/sparse_table.hpp
---


## 概要

静的な要素列に対し，帯を成す演算（$\min, \max, \gcd, \operatorname{lcm}, \operatorname{bitwise-and}, \operatorname{bitwise-or}$ など）による任意の区間の要素の総積を求める．

ここで「帯 (band)」とは，次の性質を満たす組 $(S, \oplus: S \times S \rightarrow S)$ による代数的構造を指す（「冪等半群 (idempotent semigroup)」ともいう）．

1. 結合律：$(a \oplus b) \oplus c = a \oplus (b \oplus c) \quad (\forall a, \forall b, \forall c \in S)$
1. 冪等律：$a \oplus a = a \quad (\forall a \in S)$

アルゴリズムの計算量は，クエリ処理が $\mathcal{O}(1)$ と速い．
一方で，要素列の長さを $N$ とすると，テーブル構築の時間計算量および空間計算量に $\mathcal{O}(N \log N)$ を要する．
クエリ数 $Q$ が $N$ より大きい場合に適している．

- Segment tree を用いた場合の計算量：$\mathcal{O}(N + Q \log N)$
- Sparse table を用いた場合の計算量：$\mathcal{O}(N \log(N) + Q)$


## 説明

### algorithm::sparse_table::SparseTable<IdempotentSemigroup>

|テンプレート引数|説明|
|---|---|
|`IdempotentSemigroup`|モノイドの型．`algorithm::algebra::Semigroup` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`SparseTable()`|デフォルトコンストラクタ．サイズゼロの `SparseTable` オブジェクトを構築する．|-|
|`SparseTable(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素を用いて `SparseTable` オブジェクトを構築する．|$\Theta(N \log N)$|
|`SparseTable(il)`|初期化子リスト `il` を受け取るコンストラクタ．`SparseTable(il.begin(),il.end())` と等価．|$\Theta(N \log N)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`x=prod(k)`|`k` 番目の要素 `x` を取得する．|$\mathcal{O}(1)$|
|`x=prod(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(1)$|
|`x=prod_all()`|区間全体の要素の総積 `x` を求める．|$\mathcal{O}(1)$|


## 参考

1. "Band (algebra)". Wikipedia. <https://en.wikipedia.org/wiki/Band_(algebra)>.
1. "半群". Wikipedia. <https://ja.wikipedia.org/wiki/半群>.
1. "冪等". Wikipedia. <https://ja.wikipedia.org/wiki/冪等>.
1. tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
1. "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
1. "特殊な半群". 数学好きのすずめ. <https://suzume-world.com/2021/05/02/特殊な半群/>.
