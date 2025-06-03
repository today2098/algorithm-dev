---
title: 座標圧縮
documentation_of: //lib/Others/compress.hpp
---


## 概要

「座標圧縮（座圧）」とは，座標情報を位置関係のみの情報に圧縮することをいう．
扱う値の範囲を小さくすることで，余分なメモリを節約するなどの工夫ができる．

具体的には，数列 $A = \lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ を次の条件を満たす自然数列 $B = \lbrace b_0, b_1, \ldots, b_{N-1} \rbrace$ に変換する．

1. $b_0, b_1, \ldots, b_{N-1}$ は0以上の自然数
2. $a_i < a_j$ であるならば $b_i < b_j$
3. $a_i = a_j$ であるならば $b_i = b_j$
4. $a_i > a_j$ であるならば $b_i > b_j$
5. 条件1~4を満たす中で，自然数列 $B$ の最大値をできるだけ小さくする

計算量は，配列の長さを $N$ とすると，$\mathcal{O}(N \log N)$ となる．


## 説明

|関数|説明|計算量|
|---|---|---|
|`key=compress(v)`|`v` をソートして重複を削除したもの `key` を返す．副作用として，`v` を座圧した結果に変換する．|$\mathcal{O}(N \log N)$|


## 参考

1. "座標圧縮の解説（1次元から2次元の圧縮まで）". アルゴリズムロジック. <https://algo-logic.info/coordinate-compress/>.


## 問題

- "A15 - Compression". 競技プログラミングの鉄則 演習問題集. AtCoder. <https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o>.
