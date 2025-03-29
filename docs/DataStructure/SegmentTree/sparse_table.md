---
title: Sparse Table
documentation_of: //lib/DataStructure/SegmentTree/sparse_table.hpp
---


## 概要

静的な要素列に対し，帯（冪等半群）を成す演算（$\min, \max, \gcd, \operatorname{lcm}, \operatorname{bitwise-and}, \operatorname{bitwise-or}$ など）による任意の区間クエリを求める．

ここで「帯」とは，以下の性質を満たす代数的構造を指す．

- 結合則：$(A \oplus B) \oplus C = A \oplus (B \oplus C)$
- 冪等性：$A \oplus A = A$

アルゴリズムの計算量は，クエリ処理が $\mathcal{O}(1)$ と速い．
一方で，要素列の長さを $N$ とすると，テーブル構築の時間計算量および空間計算量に $\mathcal{O}(N \log N)$ を要する．
状況に応じて「Segment Tree」と使い分けること．


## 参考文献

1. "半群". Wikipedia. <https://ja.wikipedia.org/wiki/半群>.
1. "冪等". Wikipedia. <https://ja.wikipedia.org/wiki/冪等>.
1. tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
1. "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
