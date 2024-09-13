## 概要

最大流問題を効率的に解くアルゴリズム．
1970年に Yefim Dinitz が考案した．

同じく最大流問題を解く Ford-Fulkerson Algorithm は「DFS で残余グラフ内の増加パスを探し，そこにフローを流す」ということを繰り返す貪欲なアルゴリズムである．
一方，Dinic's algorithm では，この増加パスを探す部分に対して規則を作り，無闇に探索しない工夫をしている．

アルゴリズムの流れは次の通り．

1. BFS により，残余グラフ上における source から各ノードへの増加パスの長さを求める
1. DFS により，増加パスであり，なおかつ先に求めた長さが狭義単調増加するような sink への経路を探す
1. 発見した増加パスにフローを流せるだけ流し，残余グラフを更新する
1. 候補の経路が無くなるまで DFS を繰り返す
1. source から sink への増加パスが無くなるまで BFS からやり直す

計算量は，グラフのノード数を $\lvert V \rvert$ ，辺数を $\lvert E \rvert$ とすると，BFS 部分は $\mathcal{O}(\lvert V \rvert + \lvert E \rvert)$ ，DFS 部分は同じ辺を何度も調べないことで $\mathcal{O}(\lvert V \rvert \lvert E \rvert)$ となる．
これらは高々 $\lvert V \rvert - 1$ 回しか行われないため，全体の最悪計算量は $\mathcal{O}(\lvert V \rvert ^2 \lvert E \rvert)$ となる．
しかし，たいていの場合は見積りより高速である．


## 参考文献

1. 秋葉拓哉ほか. "高速な最大流アルゴリズム". プログラミングコンテストチャレンジブック. 第2版, マイナビ出版, 2012, p.194-195.
1. "Dinic's algorithm". Wikipedia. <https://en.wikipedia.org/wiki/Dinic's_algorithm>.
1. tanaka-a. "燃やす埋める問題とProject Selection Problemの整理". <https://qiita.com/tanaka-a/items/fb8d84c44190c7098047>.
1. "最大流問題について". <https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140311/>.
1. "Dinic 法とその時間計算量". <https://misawa.github.io/others/flow/dinic_time_complexity.html>.
