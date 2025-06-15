---
title: Binary Trie（二分トライ木）
documentation_of: //lib/DataStructure/Others/binary_trie.hpp
---


## 概要

$w$ ビット非負整数を要素とする多重集合を表すデータ構造．

データ構造は $0$ と $1$ をキーとする Trie 木であり，次のクエリ処理を $\mathcal{O}(w)$ で行う．

- $\operatorname{insert}(x,c)$：多重集合 $S$ に非負整数 $x$ を $c$ 個挿入する．
- $\operatorname{erase}(x,c)$：多重集合 $S$ から非負整数 $x$ を $c$ 個削除する．
- $\operatorname{count}(x)$：多重集合 $S$ に含まれる非負整数 $x$ の個数を求める．
- $\operatorname{kth\_element}(k)$：多重集合 $S$ 内で $k$ 番目に小さい要素を取得する．

また，多重集合内の全ての非負整数に対し，任意の値で排他的論理和の操作を行うこともできる．


## 参考

1. Pat Morin. "13.1 BinaryTrie：二分トライ木". みんなのデータ構造. 堀江 慧訳. ラムダノート, 2018, pp.226-238.
1. "トライ (データ構造)". Wikipedia. <https://ja.wikipedia.org/wiki/トライ_(データ構造)>.
1. kazuma8128. "非負整数値を扱う Trie について". HatenaBlog. <https://kazuma8128.hatenablog.com/entry/2018/05/06/022654>.
1. "Trie木 (Binary Trie)". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/trie>.


## 問題

- "C - データ構造". AtCoder Regular Contest 033. AtCoder. <https://atcoder.jp/contests/arc033/tasks/arc033_3>.
