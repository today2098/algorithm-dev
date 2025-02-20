---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2880-interval_set.test.cpp
    title: test/aoj-2880-interval_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-ITP1_1_A-popcount.test.cpp
    title: test/aoj-ITP1_1_A-popcount.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Utils/debug.md
    document_title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\
      \u30ED"
    links: []
  bundledCode: "#line 1 \"lib/Utils/debug.hpp\"\n\n\n\n/**\n * @brief \u30C7\u30D0\
    \u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED\n * @docs docs/Utils/debug.md\n\
    \ */\n\n#include <iostream>\n#include <iterator>\n#include <queue>\n#include <stack>\n\
    #include <string>\n#include <string_view>\n#include <tuple>\n#include <type_traits>\n\
    #include <utility>\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::clog;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(std::string_view\
    \ s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T, U> &p);\n\
    template <class T, std::size_t... Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\n\
    template <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st);\ntemplate <typename... Ts>\nvoid\
    \ print(const std::queue<Ts...> &que);\ntemplate <typename... Ts>\nvoid print(const\
    \ std::priority_queue<Ts...> &pque);\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(std::string_view\
    \ s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes\
    \ == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n\
    }\n\ntemplate <typename... Ts>\nvoid print(const std::tuple<Ts...> &t) {\n   \
    \ print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());\n}\n\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st) {\n    std::stack<Ts...> tmp =\
    \ st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Ts>\nvoid print(const std::queue<Ts...> &que)\
    \ {\n    std::queue<Ts...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Ts>\nvoid\
    \ print(const std::priority_queue<Ts...> &pque) {\n    std::priority_queue<Ts...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> >\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr = std::begin(v);\
    \ itr != std::end(v); ++itr) {\n        if(itr != std::begin(v)) os << \" \";\n\
    \        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename T, typename\
    \ std::enable_if_t<!has_iterator<T>::value, bool> >\nvoid print(const T &elem)\
    \ { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n"
  code: "#ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n/**\n * @brief\
    \ \u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED\n *\
    \ @docs docs/Utils/debug.md\n */\n\n#include <iostream>\n#include <iterator>\n\
    #include <queue>\n#include <stack>\n#include <string>\n#include <string_view>\n\
    #include <tuple>\n#include <type_traits>\n#include <utility>\n\n// #define DEBUG\n\
    \n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::clog;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(std::string_view\
    \ s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T, U> &p);\n\
    template <class T, std::size_t... Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\n\
    template <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st);\ntemplate <typename... Ts>\nvoid\
    \ print(const std::queue<Ts...> &que);\ntemplate <typename... Ts>\nvoid print(const\
    \ std::priority_queue<Ts...> &pque);\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(std::string_view\
    \ s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes\
    \ == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n\
    }\n\ntemplate <typename... Ts>\nvoid print(const std::tuple<Ts...> &t) {\n   \
    \ print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());\n}\n\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st) {\n    std::stack<Ts...> tmp =\
    \ st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Ts>\nvoid print(const std::queue<Ts...> &que)\
    \ {\n    std::queue<Ts...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Ts>\nvoid\
    \ print(const std::priority_queue<Ts...> &pque) {\n    std::priority_queue<Ts...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> >\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr = std::begin(v);\
    \ itr != std::end(v); ++itr) {\n        if(itr != std::begin(v)) os << \" \";\n\
    \        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename T, typename\
    \ std::enable_if_t<!has_iterator<T>::value, bool> >\nvoid print(const T &elem)\
    \ { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Utils/debug.hpp
  requiredBy: []
  timestamp: '2024-09-01 18:40:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-2880-interval_set.test.cpp
  - test/aoj-ITP1_1_A-popcount.test.cpp
documentation_of: lib/Utils/debug.hpp
layout: document
redirect_from:
- /library/lib/Utils/debug.hpp
- /library/lib/Utils/debug.hpp.html
title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
---
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
