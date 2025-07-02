---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Others/popcount.hpp
    title: algorithm/Others/popcount.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/Utils/debug.hpp
    title: algorithm/Utils/debug.hpp
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
  bundledCode: "#line 1 \"verify/aoj-ITP1_1_A-popcount.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#include\
    \ <bitset>\n#include <cassert>\n#include <iostream>\n#include <limits>\n#include\
    \ <random>\n\n#line 1 \"algorithm/Others/popcount.hpp\"\n\n\n\n#include <cstdint>\n\
    \nnamespace algorithm {\n\nconstexpr int popcount32(uint32_t bit) {\n    bit -=\
    \ (bit >> 1) & 0x5555'5555U;\n    bit = (bit & 0x3333'3333U) + ((bit >> 2) & 0x3333'3333U);\n\
    \    bit = (bit + (bit >> 4)) & 0x0f0f'0f0fU;\n    bit += bit >> 8;\n    bit +=\
    \ bit >> 16;\n    return bit & 0x0000'003fU;\n}\n\nconstexpr int popcount64(uint64_t\
    \ bit) {\n    bit -= (bit >> 1) & 0x5555'5555'5555'5555ULL;\n    bit = (bit &\
    \ 0x3333'3333'3333'3333ULL) + ((bit >> 2) & 0x3333'3333'3333'3333ULL);\n    bit\
    \ = (bit + (bit >> 4)) & 0x0f0f'0f0f'0f0f'0f0fULL;\n    bit += bit >> 8;\n   \
    \ bit += bit >> 16;\n    bit += bit >> 32;\n    return bit & 0x0000'0000'0000'007fULL;\n\
    }\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Utils/debug.hpp\"\n\n\n\
    \n#include <chrono>\n#include <iomanip>\n#line 7 \"algorithm/Utils/debug.hpp\"\
    \n#include <queue>\n#include <ranges>\n#include <stack>\n#include <string>\n#include\
    \ <string_view>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    \n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__\
    \ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))\n\nnamespace algorithm {\n\nnamespace\
    \ debug {\n\nconstexpr std::ostream &os = std::clog;\n\n// Forward declaration.\n\
    \ntemplate <typename Type>\nvoid print(const Type &);\n\ntemplate <std::ranges::range\
    \ R>\nvoid print(const R &);\n\ntemplate <typename... Types>\nvoid print(const\
    \ std::basic_string<Types...> &);\n\nvoid print(std::string_view);\n\ntemplate\
    \ <typename... Types>\nvoid print(const std::stack<Types...> &);\n\ntemplate <typename...\
    \ Types>\nvoid print(const std::queue<Types...> &);\n\ntemplate <typename... Types>\n\
    void print(const std::priority_queue<Types...> &);\n\ntemplate <typename T, typename\
    \ U>\nvoid print(const std::pair<T, U> &);\n\ntemplate <typename... Types>\nvoid\
    \ print(const std::tuple<Types...> &);\n\ntemplate <class Tuple, std::size_t...\
    \ Idxes>\nvoid print_tuple(const Tuple &, std::index_sequence<Idxes...>);\n\n\
    auto elapsed() {\n    static const auto start = std::chrono::system_clock::now();\n\
    \    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()\
    \ - start).count();\n}\n\ntemplate <typename Type, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, const Type &first, const Args &...args) {\n\
    \    constexpr const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\"\
    );\n    constexpr const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \"\
    )\");\n    os << \"(\" << std::setw(8) << elapsed() << \") [L\" << line << \"\
    ] \" << open_bracket << context << close_bracket << \": \" << open_bracket;\n\
    \    print(first);\n    ((os << \", \", print(args)), ...);\n    os << close_bracket\
    \ << std::endl;\n}\n\nvoid debug_internal(int line) {\n    os << \"(\" << std::setw(8)\
    \ << elapsed() << \") [L\" << line << \"] (empty)\" << std::endl;\n}\n\n// Implementation.\n\
    \ntemplate <typename Type>\nvoid print(const Type &a) {\n    os << a;\n}\n\ntemplate\
    \ <std::ranges::range R>\nvoid print(const R &r) {\n    os << \"[\";\n    for(auto\
    \ iter = std::ranges::cbegin(r); iter != std::ranges::cend(r); ++iter) {\n   \
    \     if(iter != std::ranges::cbegin(r)) os << \" \";\n        print(*iter);\n\
    \    }\n    os << \"]\";\n}\n\ntemplate <typename... Types>\nvoid print(const\
    \ std::basic_string<Types...> &s) {\n    os << s;\n}\n\nvoid print(std::string_view\
    \ sv) {\n    os << sv;\n}\n\ntemplate <typename... Types>\nvoid print(const std::stack<Types...>\
    \ &st) {\n    std::stack<Types...> tmp(st);\n    os << \"[\";\n    for(bool first\
    \ = true; !tmp.empty(); tmp.pop(), first = false) {\n        if(!first) os <<\
    \ \" \";\n        print(tmp.top());\n    }\n    os << \"]\";\n}\n\ntemplate <typename...\
    \ Types>\nvoid print(const std::queue<Types...> &que) {\n    std::queue<Types...>\
    \ tmp(que);\n    os << \"[\";\n    for(bool first = true; !tmp.empty(); tmp.pop(),\
    \ first = false) {\n        if(!first) os << \" \";\n        print(tmp.front());\n\
    \    }\n    os << \"]\";\n}\n\ntemplate <typename... Types>\nvoid print(const\
    \ std::priority_queue<Types...> &pque) {\n    std::priority_queue<Types...> tmp(pque);\n\
    \    os << \"[\";\n    for(bool first = true; !tmp.empty(); tmp.pop(), first =\
    \ false) {\n        if(!first) os << \" \";\n        print(tmp.top());\n    }\n\
    \    os << \"]\";\n}\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <typename... Types>\nvoid print(const std::tuple<Types...>\
    \ &t) {\n    print_tuple(t, std::make_index_sequence<sizeof...(Types)>());\n}\n\
    \ntemplate <class Tuple, std::size_t... Idxes>\nvoid print_tuple(const Tuple &t,\
    \ std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes == 0\
    \ ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n}\n\n\
    }  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 11 \"verify/aoj-ITP1_1_A-popcount.test.cpp\"\
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
    #include <random>\n\n#include \"../algorithm/Others/popcount.hpp\"\n#include \"\
    ../algorithm/Utils/debug.hpp\"\n\nconstexpr int naive_popcount(uint64_t bit) {\n\
    \    int res = 0;\n    while(bit) {\n        res++;\n        bit &= bit - 1;\n\
    \    }\n    return res;\n}\n\nint main() {\n    constexpr int t = 10000;\n   \
    \ std::random_device seed;\n    std::mt19937_64 rng(seed());\n\n    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::min())\
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
  - algorithm/Others/popcount.hpp
  - algorithm/Utils/debug.hpp
  isVerificationFile: true
  path: verify/aoj-ITP1_1_A-popcount.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ITP1_1_A-popcount.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ITP1_1_A-popcount.test.cpp
- /verify/verify/aoj-ITP1_1_A-popcount.test.cpp.html
title: verify/aoj-ITP1_1_A-popcount.test.cpp
---
