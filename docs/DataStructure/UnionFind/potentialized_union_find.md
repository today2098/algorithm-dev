## 概要

「重み付き Union-Find」は，通常の Union-Find を発展させ，各要素にポテンシャルを付加し，要素間のポテンシャルの差分を管理する．

次のクエリ処理を高速に行う．
ただし，各グループの根（代表要素）のポテンシャルを0とする．

- $\operatorname{potential}(x)$ : 要素 $x$ のポテンシャルを返す．
- $\operatorname{unite}(x, y, d)$ : $\operatorname{potential}(y)-\operatorname{potential}(x)=d$ となるように，要素x, yが属するそれぞれのグループを併合する．
- $\operatorname{is\_same}(x, y)$ : 要素 $x, y$ が同じグループに属するか判定する．

主な実装方針は Union-Find と同じで，各クエリの計算量は $\mathcal{O}(\operatorname{\alpha}(N))$ となり，実用上  $\mathcal{O}(1)$ とみなせる（ただし，$\operatorname{\alpha}(x)$ はアッカーマン関数の逆関数）．


## 参考文献

1. drken. "重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて". Qiita. <https://qiita.com/drken/items/cce6fc5c579051e64fab>.


## 問題

- "D - People on a Line". AtCoder Beginner Contest 087. AtCoder. <https://atcoder.jp/contests/abc087/tasks/arc090_b>.
