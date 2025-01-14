---
title: Interval Set（連続していない区間を管理するクラス）
documentation_of: //lib/DataStructure/Others/integer_interval_set.hpp
---


## 概要

連続していない区間を管理するクラス．
重複する区間はマージされる．

特に mex (Minimum EXcluded value) を効率的に求めることができる．

`IntervalSet` に関する操作と計算量は次の通り（ただし，$N$ は区間の数）．

| 操作       | 説明                                              | 計算量                |
| ---------- | ------------------------------------------------- | --------------------- |
| `insert`   | 区間追加                                          | $\mathcal{O}(\log N)$ |
| `erase`    | 区間削除                                          | $\mathcal{O}(\log N)$ |
| `contains` | 区間に含まれているか判定する                      | $\mathcal{O}(\log N)$ |
| `mex(x)`   | $x$ 以上の集合に含まれない最小の値 (mex) を求める | $\mathcal{O}(\log N)$ |


## 参考文献

1. "区間 (数学)". Wikipedia. <https://ja.wikipedia.org/wiki/区間_(数学)>.
2. "区間演算". Wikipedia. <https://ja.wikipedia.org/wiki/区間演算>.
3. "Mex (mathematics)". Wikipedia. <https://en.wikipedia.org/wiki/Mex_(mathematics)>.
4. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/10/11/125049>.
5. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ (2) + 区間 mex クエリ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2022/02/05/043902>.


## 問題

- "E - Mex and Update". AtCoder Beginner Contest 330. AtCoder. <https://atcoder.jp/contests/abc330/tasks/abc330_e>.
