## 概要

要素のグループ分けを効率的に管理するデータ構造．
1964年，Bernard A. Galler と Michael J. Fischer が考案した．

次のクエリ処理を高速に行う．

- $\operatorname{unite}(x, y)$ : 要素 $x$ が属するグループと要素 $y$ が属するグループとを併合する．
- $\operatorname{is\_same}(x, y)$ : 要素 $x, y$ が同じグループに属するか判定する．

実装では「union by size」と「経路圧縮」の工夫を行っている．

各クエリ処理に要する計算量は，アッカーマン関数の逆関数を $\operatorname{\alpha}(x)$ とすると，$\mathcal{O}(\operatorname{\alpha}(N))$ となる．
アッカーマン関数の逆関数は $x \leq 10^{80}$ に対し $\operatorname{\alpha}(x) \leq 4$ が成り立つため，実用上 $\mathcal{O}(1)$ とみなすことができる．


## 参考文献

1. Bernard A. Galler and Michael J. Fisher. 1964. An improved equivalence algorithm. Commun. ACM 7, 5 (May 1964), 301–303. <https://doi.org/10.1145/364099.364331>.
1. 大槻 兼資. "第11章 データ構造 (4)：Union-Find". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉 拓哉監修. 講談社, 2020, p.181-190.
1. "素集合データ構造". Wikipedia. <https://ja.wikipedia.org/wiki/素集合データ構造>.
1. "巨大数：アッカーマン関数とは". 高校数学の美しい物語. <https://manabitimes.jp/math/1010>.
