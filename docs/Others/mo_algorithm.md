## 概要

区間に対する複数のクエリをまとめて高速に処理するアルゴリズム．
特に，区間 $[l,m)$ と $[m,r)$ の結果をマージして区間 $[l,r)$ の結果を求めることが簡単にできない場合に適している．

Mo's algorithm を適用するためには，次の3つの条件を満たす必要がある．

- 配列の各要素が不変
- クエリを先読みできる（オフラインクエリ）
- 区間 $[l,r)$ の結果から区間 $[l \pm 1,r), [l,r \pm 1)$ の結果を簡単に計算できる（1回の区間伸縮が容易）


### アルゴリズムの説明

本アルゴリズムの基本的なアイデアは，クエリを適切な順番に並び替えて，全体での区間の伸縮回数を抑えることにより，計算量を小さくするということである．

アルゴリズムの流れは次の通り．
ただし，区間の長さを $N$ ，クエリ数を $Q$ ，$i$ 番目のクエリの区間を $[l_i, r_i)$ とおく．

1. 区間を幅 $n$ の $N/n$ 個のブロックに分割する．
1. 各クエリを $l_i$ についてブロックごとに分け，さらにブロック内で $r_i$ についてソートする．
1. 各クエリを並び替えた順に，区間を伸縮させながら処理する．

このとき，左端，右端の伸縮回数はそれぞれ $Q n$ 回，$N (N/n)$ 回となる．
これから，アルゴリズムの計算量は，区間伸縮1回あたりの計算量を $\mathcal{O}(\alpha)$ とすると，クエリの並び替えが $\mathcal{O}(Q \log{Q})$ ，すべてのクエリ処理が $\mathcal{O}(\alpha (Q n + N (N/n)))$ となる．

ここで最適な $n$ の値を決めることがミソである．
本実装では $n = N / \sqrt{Q}$ としており，全体の計算量は $\mathcal{O}(Q \log{Q} + \alpha N \sqrt{Q})$ になる．


## 参考文献

1. ageprocpp. "Mo's algorithm(クエリ平方分割)の話". Qiita. <https://qiita.com/ageprocpp/items/34121c58e571ea8c4023>.
1. ei1333. "Mo's algorithm". HatenaBlog. <https://ei1333.hateblo.jp/entry/2017/09/11/211011>.
1. strangerxxx. "Mo's Algorithmのイメージを視覚的に理解したい". HatenaBlog. <https://strangerxxx.hateblo.jp/entry/20230314/1678795200>.
1. ふくぶちょ〜. "Mo′s Algorithm(クエリ平方分割)について". note. <https://note.com/fukubutyo1729/n/n597953224d3a>.
1. "Mo's algorithm". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/range/mo/main.html>.


## 問題

- "Chemical Substance Alpha". All-Japan High School Programming Contest. AOJ. <https://onlinejudge.u-aizu.ac.jp/challenges/sources/PCK/Final/0425>.
- "G - Range Pairing Query". AtCoder Beginner Contest 242. AtCoder. <https://atcoder.jp/contests/abc242/tasks/abc242_g>.
- "G - Triple Index". AtCoder Beginner Contest 293. AtCoder. <https://atcoder.jp/contests/abc293/tasks/abc293_g>.
