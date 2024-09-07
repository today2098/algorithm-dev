## 概要

0-based index の「Binary Indexed Tree (BIT)」．

長さ $N$ の整数値の配列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新** $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- **区間取得** $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総和を求める．

任意の区間 $[l,r)$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ と計算すればよい．


## 問題

1. "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
