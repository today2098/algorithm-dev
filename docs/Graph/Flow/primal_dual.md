## 概要

最小費用流問題を解くアルゴリズム．

アルゴリズムの流れは次の通り．

1. Dijkstra's algorithm により，現時点で単位コストが最も低い増加パスを探す．
1. 発見した増加パスにフローを流せるだけ流し，残余グラフと累積費用を更新する．
1. 増加パスが無くなるまで上記を繰り返す．

最大流値を $F$ とすると，計算量は $O(F \lvert E \rvert \log \lvert V \rvert)$ となる．


## 参考文献

1. "最小費用流". いかのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/minimum_cost_flow>.


## 問題

- "E - MinCostFlow". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_e>.
