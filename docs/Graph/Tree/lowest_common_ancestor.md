## 概要

ある木において，任意の2頂点の最近共通祖先 (LCA: Lowest Common Ancestor) を効率的に求めるアルゴリズム．

本実装では「ダブリング」を用いている．

アルゴリズムの計算量は次の通り．
ただし，木のノード数を $\lvert V \rvert$ とする．

- 前処理：
    - 時間計算量：$\mathcal{O}(\lvert V \rvert \log \lvert V \rvert)$
    - 空間計算量：$\mathcal{O}(\lvert V \rvert \log \lvert V \rvert)$
- クエリ処理：$\mathcal{O}(\log \lvert V \rvert)$


## 参考文献

1. "G - Leaf Color 解説". AtCoder. <https://atcoder.jp/contests/abc340/editorial/9249>.
1. yaketake08. "LCAをベースに構築するAuxiliary Treeのメモ". HatenaBlog. <https://smijake3.hatenablog.com/entry/2019/09/15/200200>.
1. "ダブリングによる木の最近共通祖先（LCA：Lowest Common Ancestor）を求めるアルゴリズム". アルゴリズムロジック. <https://algo-logic.info/lca/>.
1. "最小共通祖先". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor>.


## 問題

- "D - Collision". AtCoder Beginner Contest 209. AtCoder. <https://atcoder.jp/contests/abc209/tasks/abc209_d>.
- "G - Leaf Color". AtCoder Beginner Contest 340. AtCoder. <https://atcoder.jp/contests/abc340/tasks/abc340_g>.
- "H - Union Sets". CODE THANKS FESTIVAL 2017(Parallel). AtCoder. <https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h>.
