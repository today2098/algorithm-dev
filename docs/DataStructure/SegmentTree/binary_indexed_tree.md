## 概要

1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

長さ $N$ の整数値の配列 $\lbrace a_1, a_1, \ldots, a_N \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- **区間取得** $\operatorname{sum}(r)$：区間 $[1,r]$ の要素の総和を求める．

任意の区間 $[l,r]$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l-1)$ と計算すればよい．

本実装の BIT (Binary Indexed Tree) は，整数値の加算のみをサポートしているが，拡張すればアーベル群（可換群）を成す他の演算もサポートすることができる．

ここで「アーベル群」とは，集合 $G$ と二項演算 $\ast : S \times S \rightarrow S$ の組 $(G, \ast)$ で，以下の条件を満たす代数構造のことを指す．

1. 結合法則：$a \ast (b \ast c) = (a \ast b) \ast c \quad (\forall a, \forall b, \forall c \in G)$
1. 単位元の存在：$e \ast a = a \ast e = a \quad (\exists e, \forall a \in G)$
1. **逆元の存在**：$a \ast a^{-1} = a^{-1} \ast a = e \quad (\exists e, \forall a, \exists a^{-1} \in G)$
1. **交換法則**：$a \ast b = b \ast a \quad (\forall a, \forall b \in G)$

セグメント木が扱うのは「モノイド」であり，モノイドは上記条件の (1), (2) のみを満たせばよい．
それに対し，BIT は条件 (3), (4) が加わり制約が厳しい．
その理由は，BIT は元データの一部しか情報を持たないためである（セグメント木がもつデータの半分程度）．


## 参考文献

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "アーベル群". Wikipedia. <https://ja.wikipedia.org/wiki/アーベル群>.
1. sysdev. "AtCoder Library を読んでアルゴリズムを勉強：フェニック木（BIT）". Qiita. <https://qiita.com/sysdev/items/30aa7d5e9ac4ea871bd3>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 問題

- "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
