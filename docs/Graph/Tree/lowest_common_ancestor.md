## 概要

ある木において，任意の2頂点の最近共通祖先 (LCA: Lowest Common Ancestor) を効率的に求めるアルゴリズム．

本ライブラリでは「ダブリング」を用いて実装している．

計算量は，木のノード数を $\lvert V \rvert$ とすると，前処理に $\mathcal{O}(\lvert V \rvert \log \lvert V \rvert)$ ，クエリ処理に $\mathcal{O}(\log \lvert V \rvert)$ を要する．


## 参考文献

1. "G - Leaf Color 解説". AtCoder. <https://atcoder.jp/contests/abc340/editorial/9249>.
1. yaketake08. "LCAをベースに構築するAuxiliary Treeのメモ". HatenaBlog. <https://smijake3.hatenablog.com/entry/2019/09/15/200200>.
1. "ダブリングによる木の最近共通祖先（LCA：Lowest Common Ancestor）を求めるアルゴリズム". アルゴリズムロジック. <https://algo-logic.info/lca/>.
1. "最小共通祖先". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor>.


## 問題

- "G - Leaf Color". AtCoder Beginner Contest 340. AtCoder. <https://atcoder.jp/contests/abc340/tasks/abc340_g>.
