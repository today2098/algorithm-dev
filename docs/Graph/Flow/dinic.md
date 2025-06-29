---
title: Dinic's Algorithm（最大流問題）
documentation_of: //lib/Graph/Flow/dinic.hpp
---


## 概要

最大流問題 (maximum-flow problem) を解くアルゴリズム．
1970年に Yefim Dinitz が考案した．

同じく最大流問題を解く Ford-Fulkerson algorithm は「DFS で残余グラフ内の増加パスを探し，そこにフローを流す」ということを繰り返すアルゴリズムである．
Dinic's algorithm では，この増加パスを探す部分に対して規則を作り，無闇に探索しない工夫を行っている．

アルゴリズムの流れは次の通り．

1. BFS により，残余グラフ上における source から各ノードへの増加パスの長さを求める
2. DFS により，増加パスであり，なおかつ先に求めた長さが狭義単調増加するような sink への経路を探す
3. 発見した増加パスにフローを流せるだけ流し，残余グラフを更新する
4. 候補の経路が無くなるまで手順2, 3を繰り返す
5. source から sink への増加パスが無くなるまで手順1~4を繰り返す

計算量は，グラフのノード数と辺数をそれぞれ $|V|, |E|$ とすると，$\mathcal{O}(|V|^2 |E|)$ となる．
しかし，大抵の場合は見積りより高速であるとされる．


## 参考

1. 秋葉拓哉ほか. "高速な最大流アルゴリズム". プログラミングコンテストチャレンジブック 第2版. マイナビ出版, 2012, p.194-195.
1. "Dinic's algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Dinic's_algorithm>.
1. "ディニッツ法". Wikipedia. <https://ja.wikipedia.org/wiki/ディニッツ法>.
1. tanaka-a. "燃やす埋める問題とProject Selection Problemの整理". Qiita. <https://qiita.com/tanaka-a/items/fb8d84c44190c7098047>.
1. "燃やす埋める問題". いかのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/maximum_flow/burn_bury_problem>.
1. "最大流問題について". <https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/>.
1. "Dinic 法とその時間計算量". <https://misawa.github.io/others/flow/dinic_time_complexity.html>.


## 問題

- "D - Maxflow". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_d>.
