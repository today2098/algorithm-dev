---
title: デバッグ用関数形式マクロ
documentation_of: //algorithm/Utils/debug.hpp
---


## 概要

ローカル環境でのみ実行されるデバッグ用の関数形式マクロ．

引数にあるものを，経過時間（マイクロ秒）と行番号，引数名を合わせて，標準エラー出力 (`std::clog`) に出力する．
可変長引数に対応しており，複数の値を同時に出力することもできる．

引数として使用できるものは次の通り．

- リテラル値
- スカラー型の変数
- `std::string`, `std::string_view`, `std::stack`, `std::queue`, `std::priority_queue`, `std::pair`, `std::tuple` のオブジェクト
- `const_iterator` が実装されているクラス（STL のコンテナクラスなど）のオブジェクト
- 出力演算子が定義されているクラスのオブジェクト

使用する際は，コンパイル時に「`-D=DEBUG`」とオプション指定する．

使用例は次の通り．

```cpp
int a = 0;
double b = 3.14;
std::string s = "Hello, world!";
std::pair<int, double> p({1, 1.41});
std::vector<int> v({1, 1, 2, 3, 5});

debug('i', -1LL);
debug(a, b);
debug(s);
debug(p);
debug(v);
debug();
```

```bash
$ g++ -std=gnu++23 -D=DEBUG -o debug.out main.cpp
$ ./debug.out
(       0) [L61] ('i', -1LL): (i, -1)
(     119) [L62] (a, b): (0, 3.14)
(     164) [L63] s: Hello, world!
(     198) [L64] p: {1, 1.41}
(     226) [L65] v: [1 1 2 3 5]
(     270) [L66] (empty)
```


## 参考文献

1. "SFINAE". Wikipedia. <https://ja.wikipedia.org/wiki/SFINAE>.
1. "任意の式によるSFINAE [N2634]". cpprefjp. <https://cpprefjp.github.io/index.html>.
1. _EnumHack. "C++メタ関数のまとめ". Qiita. <https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb>.
1. terukazu. "特定のメンバ関数有無で、呼び出す関数を変えたい". Qiita. <https://qiita.com/terukazu/items/e257c05a7b191d32c577>.
1. "競技プログラミングで print デバッグ". <https://naskya.net/post/0002/>.
1. rsk0315_h4x. X (Twitter). <https://twitter.com/rsk0315_h4x/status/1522810205029167105>.
1. raclamusi. X (Twitter). <https://twitter.com/raclamusi/status/1522862497463631872>.
