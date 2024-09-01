## 概要

ローカル環境でのみ実行されるデバッグ用の関数形式マクロ．
引数にあるものを，名前と行番号とを合わせて，標準エラー出力 (`std::clog`) に出力する．
可変長引数に対応しており，複数の値を同時に出力することもできる．

引数として使用できるものは次の通り．

- リテラル値
- スカラー型の変数
- `std::string`, `std::string_view`, `std::pair`, `std::tuple`, `std::stack`, `std::queue`, `std::priority_queue` のオブジェクト
- iterator が実装されているクラス（STL のコンテナクラスなど）のオブジェクト
- 出力演算子が定義されているクラスのオブジェクト

使用する際は，コンパイル時に「`-D=DEBUG`」とオプション指定する．

使用例は次の通り．
引数は1個以上指定すること．

```main.cpp
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
// debug();  // error!
```

```bash
$ g++ -std=gnu++20 -D=DEBUG -o debug.out main.cpp
$ ./debug
[L50] ('i', -1LL): (i, -1)
[L51] (a, b): (0, 3.14)
[L52] s: Hello, world!
[L53] p: {1, 1.41}
[L54] v: [1 1 2 3 5]
```


## 参考文献

1. "SFINAE". Wikipedia. <https://ja.wikipedia.org/wiki/SFINAE>.
1. _EnumHack. "C++メタ関数のまとめ". Qiita. <https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb>.
1. terukazu. "特定のメンバ関数有無で、呼び出す関数を変えたい". Qiita. <https://qiita.com/terukazu/items/e257c05a7b191d32c577>.
1. "競技プログラミングで print デバッグ". <https://naskya.net/post/0002/>.
1. rsk0315_h4x. X (Twitter). <https://twitter.com/rsk0315_h4x/status/1522810205029167105>.
1. raclamusi. X (Twitter). <https://twitter.com/raclamusi/status/1522862497463631872>.
