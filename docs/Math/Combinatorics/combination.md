---
title: 数え上げ（mod付き）
documentation_of: //algorithm/Math/Combinatorics/combination.hpp
---


## 概要

ある場合の数を，素数 $p$ を法として $\bmod$ を取りながら数え上げる．

計算量は，前処理が $\mathcal{O}(N)$ ，各クエリ処理が $\mathcal{O}(1)$ となる．


## 説明

### algorithm::Combination

|メンバ関数|説明|計算量|
|---|---|---|
|`Combination<p>(n)`|コンストラクタ|$\mathcal{O}(N)$|
|`factorial(n)`|$n! \mod p$ を返す．|$\mathcal{O}(1)$|
|`inverse(n)`|$n^{-1} \mod p$ を返す．|$\mathcal{O}(1)$|
|`inverse_factorial(n)`|$(n!)^{-1} \mod p$ を返す．|$\mathcal{O}(1)$|
|`nPk(n,k)`|$_n \mathrm{P}_k \mod p$ を返す．|$\mathcal{O}(1)$|
|`nCk(n,k)`|$_n \mathrm{C}_k \mod p$ を返す．|$\mathcal{O}(1)$|
|`nHk(n,k)`|$_n \mathrm{H}_k \mod p$ を返す．|$\mathcal{O}(1)$|


## 参考

1. "数え上げ数学". Wikipedia. <https://ja.wikipedia.org/wiki/数え上げ数学>.
1. drken1215. "よくやる二項係数 (nCk mod. p)、逆元 (a^-1 mod. p) の求め方". HatenaBlog. <https://drken1215.hatenablog.com/entry/2018/06/08/210000>.
1. ngtkana. "1..=N の階乗逆数・ただの逆数を O(N) 時間で前計算する方法（mod p）" <https://ngtkana.hatenablog.com/entry/2025/05/11/105210>.
1. rsk0315. "mod についてふんわりとしか理解していない競プロ er のみなさん". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2023/05/05/221524>.
1. "競プロでよく使う二項係数(nCk)を素数(p)で割った余りの計算と逆元のまとめ". アルゴリズムロジック. <https://algo-logic.info/combination/>.


## 問題

- "D - Factorization". AtCoder Beginner Contest 110. <https://atcoder.jp/contests/abc110/tasks/abc110_d>.
- "E - Max-Min Sum". AtCoder Beginner Contest 151. <https://atcoder.jp/contests/abc151/tasks/abc151_e>.
