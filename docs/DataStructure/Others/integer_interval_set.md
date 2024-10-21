## 概要

整数の集合を区間で管理するデータ構造．
特に mex (Minimum EXcluded value) を効率的に求めることができる．

このデータ構造は次のクエリ処理を $\mathcal{O}(\log{N})$ で行う．

- $\operatorname{insert}(l,r)$：区間 $[l,r)$ の整数を集合に追加する．
- $\operatorname{erase}(l,r)$：区間 $[l,r)$ の整数を集合から削除する．
- $\operatorname{contain}(l,r)$：区間 $[l,r)$ の整数が集合に含まれているか判定する．
- $\operatorname{mex}(x)$：$x$ 以上の整数で集合に含まれない最小の値 (mex) を求める．


## 参考文献

1. "Mex (mathematics)". Wikipedia. <https://en.wikipedia.org/wiki/Mex_(mathematics)>.
1. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/10/11/125049>.
1. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ (2) + 区間 mex クエリ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2022/02/05/043902>.


## 問題

- "E - Mex and Update". AtCoder Beginner Contest 330. AtCoder. <https://atcoder.jp/contests/abc330/tasks/abc330_e>.
