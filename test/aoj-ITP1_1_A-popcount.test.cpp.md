---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Others/popcount.hpp
    title: Population Count (popcount)
  - icon: ':heavy_check_mark:'
    path: lib/Utils/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/aoj-ITP1_1_A-popcount.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#include\
    \ <bitset>\n#include <cassert>\n#include <iostream>\n#include <limits>\n#include\
    \ <random>\n\n#line 1 \"lib/Others/popcount.hpp\"\n\n\n\n/**\n * @brief Population\
    \ Count (popcount)\n * @docs docs/Others/popcount.md\n */\n\n#include <cstdint>\n\
    \nnamespace algorithm {\n\nconstexpr int popcount32(uint32_t bit) {\n    bit -=\
    \ (bit >> 1) & 0x55555555U;\n    bit = (bit & 0x33333333U) + ((bit >> 2) & 0x33333333U);\n\
    \    bit = (bit + (bit >> 4)) & 0x0f0f0f0fU;\n    bit += bit >> 8;\n    bit +=\
    \ bit >> 16;\n    return bit & 0x3fU;\n}\n\nconstexpr int popcount64(uint64_t\
    \ bit) {\n    bit -= (bit >> 1) & 0x5555555555555555ULL;\n    bit = (bit & 0x3333333333333333ULL)\
    \ + ((bit >> 2) & 0x3333333333333333ULL);\n    bit = (bit + (bit >> 4)) & 0x0f0f0f0f0f0f0f0fULL;\n\
    \    bit += bit >> 8;\n    bit += bit >> 16;\n    bit += bit >> 32;\n    return\
    \ bit & 0x7fULL;\n}\n\n}  // namespace algorithm\n\n\n#line 1 \"lib/Utils/debug.hpp\"\
    \n\n\n\n/**\n * @brief \u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\
    \u30AF\u30ED\n * @docs docs/Utils/debug.md\n */\n\n#line 10 \"lib/Utils/debug.hpp\"\
    \n#include <iterator>\n#include <queue>\n#include <stack>\n#include <string>\n\
    #include <string_view>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    \n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
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
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 11 \"test/aoj-ITP1_1_A-popcount.test.cpp\"\
    \n\nconstexpr int naive_popcount(uint64_t bit) {\n    int res = 0;\n    while(bit)\
    \ {\n        res++;\n        bit &= bit - 1;\n    }\n    return res;\n}\n\nint\
    \ main() {\n    constexpr int t = 10000;\n    std::random_device seed;\n    std::mt19937_64\
    \ rng(seed());\n\n    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::min())\
    \ == 0);\n    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::max())\
    \ == 32);\n    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::min())\
    \ == 0);\n    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::max())\
    \ == 64);\n\n    std::uniform_int_distribution<uint32_t> uniform(std::numeric_limits<uint32_t>::min(),\n\
    \                                                    std::numeric_limits<uint32_t>::max());\n\
    \    for(int i = 0; i < t; ++i) {\n        uint32_t arg = uniform(rng);\n    \
    \    auto target = algorithm::popcount32(arg);\n        auto want = naive_popcount(arg);\n\
    \        debug(i, std::bitset<32>(arg), target, want);\n\n        assert(target\
    \ == want);\n    }\n\n    std::uniform_int_distribution<uint64_t> uniform2(std::numeric_limits<uint64_t>::min(),\n\
    \                                                     std::numeric_limits<uint64_t>::max());\n\
    \    for(int i = 0; i < t; ++i) {\n        uint64_t arg = uniform2(rng);\n   \
    \     auto target = algorithm::popcount64(arg);\n        auto want = naive_popcount(arg);\n\
    \        debug(i, std::bitset<64>(arg), arg, target, want);\n\n        assert(target\
    \ == want);\n    }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <bitset>\n#include <cassert>\n#include <iostream>\n#include <limits>\n\
    #include <random>\n\n#include \"../lib/Others/popcount.hpp\"\n#include \"../lib/Utils/debug.hpp\"\
    \n\nconstexpr int naive_popcount(uint64_t bit) {\n    int res = 0;\n    while(bit)\
    \ {\n        res++;\n        bit &= bit - 1;\n    }\n    return res;\n}\n\nint\
    \ main() {\n    constexpr int t = 10000;\n    std::random_device seed;\n    std::mt19937_64\
    \ rng(seed());\n\n    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::min())\
    \ == 0);\n    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::max())\
    \ == 32);\n    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::min())\
    \ == 0);\n    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::max())\
    \ == 64);\n\n    std::uniform_int_distribution<uint32_t> uniform(std::numeric_limits<uint32_t>::min(),\n\
    \                                                    std::numeric_limits<uint32_t>::max());\n\
    \    for(int i = 0; i < t; ++i) {\n        uint32_t arg = uniform(rng);\n    \
    \    auto target = algorithm::popcount32(arg);\n        auto want = naive_popcount(arg);\n\
    \        debug(i, std::bitset<32>(arg), target, want);\n\n        assert(target\
    \ == want);\n    }\n\n    std::uniform_int_distribution<uint64_t> uniform2(std::numeric_limits<uint64_t>::min(),\n\
    \                                                     std::numeric_limits<uint64_t>::max());\n\
    \    for(int i = 0; i < t; ++i) {\n        uint64_t arg = uniform2(rng);\n   \
    \     auto target = algorithm::popcount64(arg);\n        auto want = naive_popcount(arg);\n\
    \        debug(i, std::bitset<64>(arg), arg, target, want);\n\n        assert(target\
    \ == want);\n    }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - lib/Others/popcount.hpp
  - lib/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_1_A-popcount.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 13:46:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_1_A-popcount.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_1_A-popcount.test.cpp
- /verify/test/aoj-ITP1_1_A-popcount.test.cpp.html
title: test/aoj-ITP1_1_A-popcount.test.cpp
---
