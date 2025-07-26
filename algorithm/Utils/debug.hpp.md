---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_1_A-popcount.test.cpp
    title: verify/aoj-ITP1_1_A-popcount.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Utils/debug.hpp\"\n\n\n\n#include <chrono>\n#include\
    \ <concepts>\n#include <iomanip>\n#include <iostream>\n#include <queue>\n#include\
    \ <ranges>\n#include <stack>\n#include <string>\n#include <string_view>\n#include\
    \ <tuple>\n#include <utility>\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__\
    \ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))\n\nnamespace algorithm {\n\nnamespace\
    \ debug {\n\nconstexpr std::ostream &os = std::clog;\n\n// Forward declaration.\n\
    \ntemplate <typename Type>\nvoid print(const Type &);\n\ntemplate <std::ranges::input_range\
    \ R>\n    requires(!std::convertible_to<R, const char *>)\nvoid print(const R\
    \ &);\n\nvoid print(const char *);\n\ntemplate <typename... Types>\nvoid print(const\
    \ std::basic_string<Types...> &);\n\ntemplate <typename... Types>\nvoid print(std::basic_string_view<Types...>);\n\
    \ntemplate <typename... Types>\nvoid print(std::stack<Types...>);\n\ntemplate\
    \ <typename... Types>\nvoid print(std::queue<Types...>);\n\ntemplate <typename...\
    \ Types>\nvoid print(std::priority_queue<Types...>);\n\ntemplate <typename T,\
    \ typename U>\nvoid print(const std::pair<T, U> &);\n\ntemplate <typename... Types>\n\
    void print(const std::tuple<Types...> &);\n\ntemplate <typename... Types, std::size_t...\
    \ Idxes>\nvoid print_tuple(const std::tuple<Types...> &t, std::index_sequence<Idxes...>);\n\
    \n// Implementation.\n\nauto elapsed() {\n    static const auto start = std::chrono::system_clock::now();\n\
    \    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()\
    \ - start).count();\n}\n\ntemplate <typename Type, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, Type &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"(\" << std::setw(8) << elapsed() << \") [L\" << line << \"] \" << open_bracket\
    \ << context << close_bracket << \": \" << open_bracket;\n    print(std::forward<Type>(first));\n\
    \    ((os << \", \", print(std::forward<Args>(args))), ...);\n    os << close_bracket\
    \ << std::endl;\n}\n\nvoid debug_internal(int line) {\n    os << \"(\" << std::setw(8)\
    \ << elapsed() << \") [L\" << line << \"] (empty)\" << std::endl;\n}\n\ntemplate\
    \ <typename Type>\nvoid print(const Type &a) {\n    os << a;\n}\n\ntemplate <std::ranges::input_range\
    \ R>\n    requires(!std::convertible_to<R, const char *>)\nvoid print(const R\
    \ &r) {\n    os << \"[\";\n    auto iter = std::ranges::cbegin(r);\n    const\
    \ auto end = std::ranges::cend(r);\n    if(iter != end) {\n        print(*iter++);\n\
    \        while(iter != end) {\n            os << \" \";\n            print(*iter++);\n\
    \        }\n    }\n    os << \"]\";\n}\n\nvoid print(const char *s) {\n    os\
    \ << s;\n}\n\ntemplate <typename... Types>\nvoid print(const std::basic_string<Types...>\
    \ &s) {\n    os << s;\n}\n\ntemplate <typename... Types>\nvoid print(std::basic_string_view<Types...>\
    \ sv) {\n    os << sv;\n}\n\ntemplate <typename... Types>\nvoid print(std::stack<Types...>\
    \ st) {\n    os << \"[\";\n    if(!st.empty()) {\n        print(st.top());\n \
    \       st.pop();\n        for(; !st.empty(); st.pop()) {\n            os << \"\
    \ \";\n            print(st.top());\n        }\n    }\n    os << \"]\";\n}\n\n\
    template <typename... Types>\nvoid print(std::queue<Types...> que) {\n    os <<\
    \ \"[\";\n    if(!que.empty()) {\n        print(que.front());\n        que.pop();\n\
    \        for(; !que.empty(); que.pop()) {\n            os << \" \";\n        \
    \    print(que.front());\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename...\
    \ Types>\nvoid print(std::priority_queue<Types...> pque) {\n    os << \"[\";\n\
    \    if(!pque.empty()) {\n        print(pque.top());\n        pque.pop();\n  \
    \      for(; !pque.empty(); pque.pop()) {\n            os << \" \";\n        \
    \    print(pque.top());\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ T, typename U>\nvoid print(const std::pair<T, U> &p) {\n    os << \"{\";\n \
    \   print(p.first);\n    os << \", \";\n    print(p.second);\n    os << \"}\"\
    ;\n}\n\ntemplate <typename... Types>\nvoid print(const std::tuple<Types...> &t)\
    \ {\n    print_tuple(t, std::make_index_sequence<sizeof...(Types)>());\n}\n\n\
    template <typename... Types, std::size_t... Idxes>\nvoid print_tuple(const std::tuple<Types...>\
    \ &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes ==\
    \ 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n}\n\
    \n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n"
  code: "#ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#include <chrono>\n\
    #include <concepts>\n#include <iomanip>\n#include <iostream>\n#include <queue>\n\
    #include <ranges>\n#include <stack>\n#include <string>\n#include <string_view>\n\
    #include <tuple>\n#include <utility>\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__\
    \ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))\n\nnamespace algorithm {\n\nnamespace\
    \ debug {\n\nconstexpr std::ostream &os = std::clog;\n\n// Forward declaration.\n\
    \ntemplate <typename Type>\nvoid print(const Type &);\n\ntemplate <std::ranges::input_range\
    \ R>\n    requires(!std::convertible_to<R, const char *>)\nvoid print(const R\
    \ &);\n\nvoid print(const char *);\n\ntemplate <typename... Types>\nvoid print(const\
    \ std::basic_string<Types...> &);\n\ntemplate <typename... Types>\nvoid print(std::basic_string_view<Types...>);\n\
    \ntemplate <typename... Types>\nvoid print(std::stack<Types...>);\n\ntemplate\
    \ <typename... Types>\nvoid print(std::queue<Types...>);\n\ntemplate <typename...\
    \ Types>\nvoid print(std::priority_queue<Types...>);\n\ntemplate <typename T,\
    \ typename U>\nvoid print(const std::pair<T, U> &);\n\ntemplate <typename... Types>\n\
    void print(const std::tuple<Types...> &);\n\ntemplate <typename... Types, std::size_t...\
    \ Idxes>\nvoid print_tuple(const std::tuple<Types...> &t, std::index_sequence<Idxes...>);\n\
    \n// Implementation.\n\nauto elapsed() {\n    static const auto start = std::chrono::system_clock::now();\n\
    \    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()\
    \ - start).count();\n}\n\ntemplate <typename Type, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, Type &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"(\" << std::setw(8) << elapsed() << \") [L\" << line << \"] \" << open_bracket\
    \ << context << close_bracket << \": \" << open_bracket;\n    print(std::forward<Type>(first));\n\
    \    ((os << \", \", print(std::forward<Args>(args))), ...);\n    os << close_bracket\
    \ << std::endl;\n}\n\nvoid debug_internal(int line) {\n    os << \"(\" << std::setw(8)\
    \ << elapsed() << \") [L\" << line << \"] (empty)\" << std::endl;\n}\n\ntemplate\
    \ <typename Type>\nvoid print(const Type &a) {\n    os << a;\n}\n\ntemplate <std::ranges::input_range\
    \ R>\n    requires(!std::convertible_to<R, const char *>)\nvoid print(const R\
    \ &r) {\n    os << \"[\";\n    auto iter = std::ranges::cbegin(r);\n    const\
    \ auto end = std::ranges::cend(r);\n    if(iter != end) {\n        print(*iter++);\n\
    \        while(iter != end) {\n            os << \" \";\n            print(*iter++);\n\
    \        }\n    }\n    os << \"]\";\n}\n\nvoid print(const char *s) {\n    os\
    \ << s;\n}\n\ntemplate <typename... Types>\nvoid print(const std::basic_string<Types...>\
    \ &s) {\n    os << s;\n}\n\ntemplate <typename... Types>\nvoid print(std::basic_string_view<Types...>\
    \ sv) {\n    os << sv;\n}\n\ntemplate <typename... Types>\nvoid print(std::stack<Types...>\
    \ st) {\n    os << \"[\";\n    if(!st.empty()) {\n        print(st.top());\n \
    \       st.pop();\n        for(; !st.empty(); st.pop()) {\n            os << \"\
    \ \";\n            print(st.top());\n        }\n    }\n    os << \"]\";\n}\n\n\
    template <typename... Types>\nvoid print(std::queue<Types...> que) {\n    os <<\
    \ \"[\";\n    if(!que.empty()) {\n        print(que.front());\n        que.pop();\n\
    \        for(; !que.empty(); que.pop()) {\n            os << \" \";\n        \
    \    print(que.front());\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename...\
    \ Types>\nvoid print(std::priority_queue<Types...> pque) {\n    os << \"[\";\n\
    \    if(!pque.empty()) {\n        print(pque.top());\n        pque.pop();\n  \
    \      for(; !pque.empty(); pque.pop()) {\n            os << \" \";\n        \
    \    print(pque.top());\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ T, typename U>\nvoid print(const std::pair<T, U> &p) {\n    os << \"{\";\n \
    \   print(p.first);\n    os << \", \";\n    print(p.second);\n    os << \"}\"\
    ;\n}\n\ntemplate <typename... Types>\nvoid print(const std::tuple<Types...> &t)\
    \ {\n    print_tuple(t, std::make_index_sequence<sizeof...(Types)>());\n}\n\n\
    template <typename... Types, std::size_t... Idxes>\nvoid print_tuple(const std::tuple<Types...>\
    \ &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes ==\
    \ 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n}\n\
    \n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/debug.hpp
  requiredBy: []
  timestamp: '2025-07-26 07:59:29+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_1_A-popcount.test.cpp
documentation_of: algorithm/Utils/debug.hpp
layout: document
title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
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
