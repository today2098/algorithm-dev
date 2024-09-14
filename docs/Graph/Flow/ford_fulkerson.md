## 概要

最大流問題を解く貪欲なアルゴリズム．
1956年に L. R. Ford Jr. と D. R. Fulkerson により考案された．

アルゴリズムの流れは次の通り．

1. DFS により，残余グラフ上の増加パスを探す
1. 発見した増加パスにフローを流せるだけ流し，残余グラフを更新する
1. 残余グラフ上から増加パスが無くなるまで上記を繰り返す

最大流値を $F$ とすると，上記処理の反復回数は $F$ 回に抑えられる．
また，グラフの辺数を $\lvert E \rvert$ とすると，各反復時において DFS に $\mathcal{O}(\lvert E \rvert)$ の計算量を要する．
よって，全体の計算量は $\mathcal{O}(F \lvert E \rvert)$ となる．


## 参考文献

1. 大槻兼資. "第16章 グラフ (4)：ネットワークフロー". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, p.283-309. 
1. "最大フロー問題". Wikipedia. <https://ja.wikipedia.org/wiki/最大フロー問題>.
1. "Ford–Fulkerson algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Ford%E2%80%93Fulkerson_algorithm>.
1. "フォード・ファルカーソンのアルゴリズム". Wikipedia. <https://ja.wikipedia.org/wiki/フォード・ファルカーソンのアルゴリズム>.


## 問題

- "D - Maxflow". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_d>.
