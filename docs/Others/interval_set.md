---
title: Interval Set（区間をsetで管理するデータ構造）
documentation_of: //algorithm/Others/interval_set.hpp
---


## 概要

区間を set で管理するデータ構造．
重複する区間を追加するとマージされる．

数の集合を扱うデータ構造ともみなせ，特に集合内の mex (Minimum EXcluded value) を効率的に求めることができる．


## 参考

1. "区間 (数学)". Wikipedia. <https://ja.wikipedia.org/wiki/区間_(数学)>.
1. "区間演算". Wikipedia. <https://ja.wikipedia.org/wiki/区間演算>.
1. "Mex (mathematics)". Wikipedia. <https://en.wikipedia.org/wiki/Mex_(mathematics)>.
1. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/10/11/125049>.
1. rsk0315. "要素の追加・削除と mex を対数時間で処理するよ (2) + 区間 mex クエリ". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2022/02/05/043902>.


## 問題

- "E - Mex and Update". AtCoder Beginner Contest 330. AtCoder. <https://atcoder.jp/contests/abc330/tasks/abc330_e>.
- "C - Black Intervals". AtCoder Beginner Contest 411. AtCoder. <https://atcoder.jp/contests/abc411/tasks/abc411_c>.
