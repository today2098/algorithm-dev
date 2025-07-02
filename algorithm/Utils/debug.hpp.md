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
    \ <iomanip>\n#include <iostream>\n#include <queue>\n#include <ranges>\n#include\
    \ <stack>\n#include <string>\n#include <string_view>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__\
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
    \ static_cast<void>(0)\n\n#endif\n\n\n"
  code: "#ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#include <chrono>\n\
    #include <iomanip>\n#include <iostream>\n#include <queue>\n#include <ranges>\n\
    #include <stack>\n#include <string>\n#include <string_view>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n\n#ifdef DEBUG\n\n#define debug(...)\
    \ algorithm::debug::debug_internal(__LINE__ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))\n\
    \nnamespace algorithm {\n\nnamespace debug {\n\nconstexpr std::ostream &os = std::clog;\n\
    \n// Forward declaration.\n\ntemplate <typename Type>\nvoid print(const Type &);\n\
    \ntemplate <std::ranges::range R>\nvoid print(const R &);\n\ntemplate <typename...\
    \ Types>\nvoid print(const std::basic_string<Types...> &);\n\nvoid print(std::string_view);\n\
    \ntemplate <typename... Types>\nvoid print(const std::stack<Types...> &);\n\n\
    template <typename... Types>\nvoid print(const std::queue<Types...> &);\n\ntemplate\
    \ <typename... Types>\nvoid print(const std::priority_queue<Types...> &);\n\n\
    template <typename T, typename U>\nvoid print(const std::pair<T, U> &);\n\ntemplate\
    \ <typename... Types>\nvoid print(const std::tuple<Types...> &);\n\ntemplate <class\
    \ Tuple, std::size_t... Idxes>\nvoid print_tuple(const Tuple &, std::index_sequence<Idxes...>);\n\
    \nauto elapsed() {\n    static const auto start = std::chrono::system_clock::now();\n\
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
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Utils/debug.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_1_A-popcount.test.cpp
documentation_of: algorithm/Utils/debug.hpp
layout: document
redirect_from:
- /library/algorithm/Utils/debug.hpp
- /library/algorithm/Utils/debug.hpp.html
title: algorithm/Utils/debug.hpp
---
