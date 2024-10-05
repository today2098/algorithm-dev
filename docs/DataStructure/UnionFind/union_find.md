## 概要

「素集合データ構造 (disjoint-set data structure)」とは，要素の集合を素集合に分割して保持するデータ構造．
言い換えると，要素のグループ分けを管理するデータ構造である．

そして，素集合データ構造に対する次の操作のアルゴリズムを「Union-Find」という．

- **Union**：2つの集合を1つに併合する
- **Find**：特定の要素がどの集合に属しているか求める

1964年，Bernard A. Galler と Michael J. Fischer が効率的な手法を考案した．

本実装では「素集合森 (disjoint-set forest)」を作成しており，「union by size」と「経路圧縮」の工夫を行っている．

各クエリ処理に要する計算量は，アッカーマン関数の逆関数を $\operatorname{\alpha}(x)$ とすると，$\mathcal{O}(\operatorname{\alpha}(N))$ となる．
アッカーマン関数の逆関数は，増加が非常に遅く，$x \leq 10^{80}$ に対し $\operatorname{\alpha}(x) \leq 4$ が成り立つため，実用上 $\mathcal{O}(1)$ とみなすことができる．


## 参考文献

1. Bernard A. Galler and Michael J. Fisher. 1964. An improved equivalence algorithm. Commun. ACM 7, 5 (May 1964), 301–303. <https://doi.org/10.1145/364099.364331>.
1. 大槻 兼資. "第11章 データ構造 (4)：Union-Find". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉 拓哉監修. 講談社, 2020, p.181-190.
1. "素集合データ構造". Wikipedia. <https://ja.wikipedia.org/wiki/素集合データ構造>.
1. rsk0315. "α(n) とお近づきになりたい人のための記事". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/11/14/170423>.
1. "巨大数：アッカーマン関数とは". 高校数学の美しい物語. <https://manabitimes.jp/math/1010>.
