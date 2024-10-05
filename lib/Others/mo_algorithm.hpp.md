---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-0425-mo_algorithm.test.cpp
    title: test/aoj-0425-mo_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/mo_algorithm.md
    document_title: "Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"lib/Others/mo_algorithm.hpp\"\n\n\n\n/**\n * @brief Mo's\
    \ Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09\n * @docs docs/Others/mo_algorithm.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <tuple>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// Mo's Algorithm\uFF08\u30AF\u30A8\
    \u30EA\u5E73\u65B9\u5206\u5272\uFF09.\nclass Mo {\n    int m_len;            \
    \                              // m_len:=(\u533A\u9593\u306E\u9577\u3055).\n \
    \   int m_q;                                            // m_q:=(\u30AF\u30A8\u30EA\
    \u6570).\n    std::vector<std::tuple<int, int, int> > m_queries;  // m_queries[i]:=(i\u756A\
    \u76EE\u306E\u533A\u9593\u30AF\u30A8\u30EA). tuple of (left, right, index).\n\n\
    \    void sort_queries() {\n        if(m_q == 0) return;\n        const int width\
    \ = std::max(m_len / (int)std::sqrt(m_q), 1);  // width:=N/\u221AQ.\n        std::sort(m_queries.begin(),\
    \ m_queries.end(), [&width](const std::tuple<int, int, int> &a, const std::tuple<int,\
    \ int, int> &b) -> bool {\n            const auto &[al, ar, _] = a;\n        \
    \    const auto &[bl, br, __] = b;\n            int a_block = al / width, b_block\
    \ = bl / width;\n            if(a_block == b_block) return (a_block & 1 ? ar >\
    \ br : ar < br);\n            return a_block < b_block;\n        });\n    }\n\n\
    public:\n    Mo() : Mo(0) {}\n    explicit Mo(size_t n) : m_len(n), m_q(0) {}\n\
    \    explicit Mo(size_t n, size_t q) : Mo(n) {\n        m_queries.reserve(q);\n\
    \    }\n\n    // \u533A\u9593[l,r)\u306B\u3064\u3044\u3066\u306E\u30AF\u30A8\u30EA\
    \u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    void insert(int l, int r) {\n      \
    \  assert(0 <= l and l < r and r <= m_len);\n        m_queries.emplace_back(l,\
    \ r, m_q++);\n    }\n    // \u5404\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\
    \uFF0EO(Q*logQ+\u03B1*N*\u221AQ).\n    template <class F1, class F2, class F3>\n\
    \    void execute(const F1 &add, const F2 &del, const F3 &solve) { execute(add,\
    \ del, add, del, solve); }\n    template <class F1, class F2, class F3, class\
    \ F4, class F5>\n    void execute(const F1 &add_l, const F2 &del_l, const F3 &add_r,\
    \ const F4 &del_r, const F5 &solve) {\n        sort_queries();\n        int l\
    \ = 0, r = 0;\n        for(const auto &[nl, nr, idx] : m_queries) {\n        \
    \    while(nl < l) add_l(--l);\n            while(r < nr) add_r(r++);\n      \
    \      while(l < nl) del_l(l++);\n            while(nr < r) del_r(--r);\n    \
    \        solve(idx);\n        }\n    }\n    void reset() {\n        m_queries.clear();\n\
    \        m_q = 0;\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MO_ALGORITHM_HPP\n#define ALGORITHM_MO_ALGORITHM_HPP 1\n\
    \n/**\n * @brief Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\
    \uFF09\n * @docs docs/Others/mo_algorithm.md\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <tuple>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\
    \uFF09.\nclass Mo {\n    int m_len;                                          //\
    \ m_len:=(\u533A\u9593\u306E\u9577\u3055).\n    int m_q;                     \
    \                       // m_q:=(\u30AF\u30A8\u30EA\u6570).\n    std::vector<std::tuple<int,\
    \ int, int> > m_queries;  // m_queries[i]:=(i\u756A\u76EE\u306E\u533A\u9593\u30AF\
    \u30A8\u30EA). tuple of (left, right, index).\n\n    void sort_queries() {\n \
    \       if(m_q == 0) return;\n        const int width = std::max(m_len / (int)std::sqrt(m_q),\
    \ 1);  // width:=N/\u221AQ.\n        std::sort(m_queries.begin(), m_queries.end(),\
    \ [&width](const std::tuple<int, int, int> &a, const std::tuple<int, int, int>\
    \ &b) -> bool {\n            const auto &[al, ar, _] = a;\n            const auto\
    \ &[bl, br, __] = b;\n            int a_block = al / width, b_block = bl / width;\n\
    \            if(a_block == b_block) return (a_block & 1 ? ar > br : ar < br);\n\
    \            return a_block < b_block;\n        });\n    }\n\npublic:\n    Mo()\
    \ : Mo(0) {}\n    explicit Mo(size_t n) : m_len(n), m_q(0) {}\n    explicit Mo(size_t\
    \ n, size_t q) : Mo(n) {\n        m_queries.reserve(q);\n    }\n\n    // \u533A\
    \u9593[l,r)\u306B\u3064\u3044\u3066\u306E\u30AF\u30A8\u30EA\u3092\u8FFD\u52A0\u3059\
    \u308B\uFF0E\n    void insert(int l, int r) {\n        assert(0 <= l and l < r\
    \ and r <= m_len);\n        m_queries.emplace_back(l, r, m_q++);\n    }\n    //\
    \ \u5404\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\uFF0EO(Q*logQ+\u03B1\
    *N*\u221AQ).\n    template <class F1, class F2, class F3>\n    void execute(const\
    \ F1 &add, const F2 &del, const F3 &solve) { execute(add, del, add, del, solve);\
    \ }\n    template <class F1, class F2, class F3, class F4, class F5>\n    void\
    \ execute(const F1 &add_l, const F2 &del_l, const F3 &add_r, const F4 &del_r,\
    \ const F5 &solve) {\n        sort_queries();\n        int l = 0, r = 0;\n   \
    \     for(const auto &[nl, nr, idx] : m_queries) {\n            while(nl < l)\
    \ add_l(--l);\n            while(r < nr) add_r(r++);\n            while(l < nl)\
    \ del_l(l++);\n            while(nr < r) del_r(--r);\n            solve(idx);\n\
    \        }\n    }\n    void reset() {\n        m_queries.clear();\n        m_q\
    \ = 0;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Others/mo_algorithm.hpp
  requiredBy: []
  timestamp: '2024-10-05 02:32:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-0425-mo_algorithm.test.cpp
documentation_of: lib/Others/mo_algorithm.hpp
layout: document
redirect_from:
- /library/lib/Others/mo_algorithm.hpp
- /library/lib/Others/mo_algorithm.hpp.html
title: "Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09"
---
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
