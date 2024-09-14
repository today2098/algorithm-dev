## 概要

「座標圧縮（座圧）」とは，値の大小関係を保ったまま小さな自然数に変化することをいう．

具体的には，配列 $A = \lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ を次の条件を満たす自然数の列 $B = \lbrace b_0, b_1, \ldots, b_{N-1} \rbrace$ に変換する．

1. $b_0, b_1, \ldots, b_{N-1}$ は0以上の自然数
1. $a_i < a_j$ であるならば $b_i < b_j$
1. $a_i = a_j$ であるならば $b_i = b_j$
1. $a_i > a_j$ であるならば $b_i > b_j$
1. 条件1~4を満たす中で，配列 $B$ の最大値をできるだけ小さくする

計算量は，配列の長さを $N$ とすると，$\mathcal{O}(N \log N)$ となる．

扱う値の範囲を小さくすることで，余分なメモリを節約するなどの工夫ができる．


## 問題

- "A15 - Compression". 競技プログラミングの鉄則 演習問題集. AtCoder. <https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_o>.
