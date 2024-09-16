## 概要

木の直径を求めるアルゴリズム．
ここで木の直径とは，「与えられた木における単純パスの長さの最大値」をいう．
また，重みなし無向グラフに対しては，グラフの直径の下界となる．

アルゴリズムの流れは次の通り．
ただし，$\operatorname{d}(u,v)$ はノード $u, v$ 間の距離，$\operatorname{ecc}(v)$ は $\max_u \operatorname{d}(v,u)$ を表す（"ecc" は "eccentricity" の略）．

1. 与えられた木上の任意のノード $s$ を選択する．
1. BFS により，$\operatorname{d}(s,u) = \operatorname{ecc}(s)$ となるノード $u$ を探索する．
1. BFS により，$\operatorname{d}(u,v) = \operatorname{ecc}(u)$ となるノード $v$ を探索する．
1. ノード $u$ と $v$ を結ぶ単純パスが，求める木の直径となる．

計算量は，木のノード数を $\lvert V \rvert$ とすると，$\mathcal{O}(\lvert V \rvert)$ となる.


### アルゴリズムの説明

アルゴリズムのポイントは，「木上の任意のノードから最も遠くにあるノードは直径の端点になる」ということ．
アルゴリズムの正当性を背理法を用いて証明する．

ある木において，「根 $r$ から最も遠いノード $x$ は木の直径の端点にならない」と仮定する．
また，木の直径の端点を $u, v$ とおく．

(1) まず，パス $r$-$x$ が直径 $u$-$v$ と交わる場合を考える．
この交点となるノードを $h$ とおく．
ノード $h$ は直径上にあるため，$h$ から最も離れているノードは $u$ または $v$ となる．
しかし，根 $r$ から最も遠いノードは $x$ であり，$x$ は $u$ または $v$ のどちらかになるため，矛盾が生じる．

(2) 次に，パス $r$-$x$ が直径 $u$-$v$ と交わらない場合を考える．
直径上にある点を $h'$ とおく．
$\operatorname{d}(r,h') + \operatorname{d}(h',x) \geq \operatorname{d}(r,x)$ であることに注意すると，

$$
\begin{align}
&\operatorname{d}(r,x) \geq \operatorname{d}(r,h') + \max(\operatorname{d}(h',u), \operatorname{d}(h',v)) \notag\\
\Rightarrow &\operatorname{d}(h',x) \geq \max(\operatorname{d}(h',u), \operatorname{d}(h',v)) \notag
\end{align}
$$

となる．(1) と同様にノード $x$ は $u$ または $v$ のどちらかになるため，矛盾が生じる．

よって，木上の任意のノードから最も遠くにあるノードは直径の端点になることが示された．


## 参考文献

1. Clémence Magnien, Matthieu Latapy, and Michel Habib. 2009. Fast computation of empirically tight bounds for the diameter of massive graphs. ACM J. Exp. Algorithmics 13, Article 10 (2009), 9 pages. <https://doi.org/10.1145/1412228.1455266>.
1. "直径". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/graph/tree/diameter/main.html>.


## 問題

- "D - 高橋くんと木の直径". AtCoder Beginner Contest 019. AtCoder. <https://atcoder.jp/contests/abc019/tasks/abc019_4>.
- "C - ロミオとジュリエット". AtCoder Regular Contest 022. AtCoder. <https://atcoder.jp/contests/arc022/tasks/arc022_3>.
- "C - Removing Coins". AtCoder Grand Contest 033. AtCoder. <https://atcoder.jp/contests/agc033/tasks/agc033_c>.
- "003 - Longest Circular Road（★4）". 競プロ典型 90 問. AtCoder. <https://atcoder.jp/contests/typical90/tasks/typical90_c>.
