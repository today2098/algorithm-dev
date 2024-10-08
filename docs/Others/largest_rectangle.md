## 概要

「あるヒストグラム内において，面積が最大となる長方形を求める問題」を効率的に求めるテクニックアルゴリズム．

問題の概要は次の通り．

> 長さ $N$ の数列 $H = \lbrace h_0, h_1, \ldots, h_{N-1} \rbrace$ が与えられる．
>
> 各 $i \ (0 \leq i < N)$ において，$h_i \leq h_j$ となる $i$ を含む $j$ の最大区間を $[l,r)$ とする．
>
> このとき $\max(h_i * (r-l))$ を求めよ．

計算量は，愚直に求めると $\mathcal{O}(N^2)$ となるが，スタックを用いて工夫すると $\mathcal{O}(N)$ に落とすことができる．


## 参考文献

1. 秋葉 拓哉, 岩田 陽一, 北川 宜稔. "4-4 厳選！ 頻出テクニック (2)". プログラミングコンテストチャレンジブック. 第2版, マイナビ出版, 2012, p.298.
