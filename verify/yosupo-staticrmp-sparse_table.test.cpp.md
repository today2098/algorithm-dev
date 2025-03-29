---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/sparse_table.hpp
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo-staticrmp-sparse_table.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"lib/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\n\n\n#include <cassert>\n#include <functional>\n#include <iterator>\n#include\
    \ <type_traits>\n#line 10 \"lib/DataStructure/SegmentTree/sparse_table.hpp\"\n\
    \nnamespace algorithm {\n\n// \u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3057\
    \uFF0C\u7D50\u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\
    \u6027 A\u2022A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08min, max, gcd,\
    \ lcm, bitwise-and, bitwise-or\u306A\u3069\uFF09\u306E\u533A\u9593\u30AF\u30A8\
    \u30EA\u3092\u6C42\u3081\u308B\uFF0E\ntemplate <typename S, auto op>\nclass SparseTable\
    \ {\n    static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>);\n\npublic:\n    using value_type = S;\n    using size_type = std::size_t;\n\
    \    using iterator = std::vector<value_type>::const_iterator;\n    using const_iterator\
    \ = std::vector<value_type>::const_iterator;\n    using reverse_iterator = std::vector<value_type>::const_reverse_iterator;\n\
    \    using const_reverse_iterator = std::vector<value_type>::const_reverse_iterator;\n\
    \nprivate:\n    size_type m_sz;                                // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<size_type> m_lg;                   // m_lg[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<value_type>> m_table;  // m_table[k][l]:=(\u533A\u9593\
    [l,l+2^k)\u306E\u7DCF\u7A4D).\n\n    void build() {\n        for(size_type i =\
    \ 2; i <= m_sz; ++i) m_lg[i] = m_lg[i >> 1] + 1;\n        m_table.resize(m_lg[m_sz]\
    \ + 1);\n        for(size_type k = 1; k <= m_lg[size()]; ++k) {\n            size_type\
    \ n = m_sz - (1U << k) + 1;\n            m_table[k].resize(n);\n            for(size_type\
    \ i = 0; i < n; ++i) m_table[k][i] = op(m_table[k - 1][i], m_table[k - 1][i +\
    \ (1U << (k - 1))]);\n        }\n    }\n\npublic:\n    // constructor. O(N*logN).\n\
    \    SparseTable() : m_sz(0) {}\n    explicit SparseTable(const std::vector<value_type>\
    \ &v) : m_sz(v.size()), m_lg(v.size() + 1, 0), m_table(1, v) {\n        build();\n\
    \    }\n    explicit SparseTable(std::vector<value_type> &&v) : m_sz(v.size()),\
    \ m_lg(v.size() + 1, 0), m_table(1) {\n        m_table[0] = std::move(v);\n  \
    \      build();\n    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    static constexpr auto operation() { return op; }\n\
    \    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(size_type k) const {\n    \
    \    assert(k < size());\n        return m_table[0][k];\n    }\n    // \u533A\u9593\
    [l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    value_type prod(size_type\
    \ l, size_type r) const {\n        assert(l < r and r <= size());\n        size_type\
    \ k = m_lg[r - l];\n        return op(m_table[k][l], m_table[k][r - (1U << k)]);\n\
    \    }\n\n    const_iterator begin() const { return m_table[0].begin(); }\n  \
    \  const_iterator end() const { return m_table[0].end(); }\n    const_iterator\
    \ cbegin() const { return m_table[0].cbegin(); }\n    const_iterator cend() const\
    \ { return m_table[0].cend(); }\n    const_reverse_iterator rbegin() const { return\
    \ m_table[0].rbegin(); }\n    const_reverse_iterator rend() const { return m_table[0].rend();\
    \ }\n    const_reverse_iterator crbegin() const { return m_table[0].crbegin();\
    \ }\n    const_reverse_iterator crend() const { return m_table[0].crend(); }\n\
    };\n\n}  // namespace algorithm\n\n\n#line 1 \"lib/Utils/debug.hpp\"\n\n\n\n#include\
    \ <chrono>\n#include <iomanip>\n#line 8 \"lib/Utils/debug.hpp\"\n#include <queue>\n\
    #include <stack>\n#include <string>\n#include <string_view>\n#include <tuple>\n\
    #line 15 \"lib/Utils/debug.hpp\"\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__\
    \ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))\n\nnamespace algorithm {\n\nnamespace\
    \ debug {\n\nconstexpr std::ostream &os = std::clog;\n\nstruct has_const_iterator_impl\
    \ {\n    template <class T>\n    static constexpr std::true_type check(typename\
    \ T::const_iterator *);\n\n    template <class T>\n    static constexpr std::false_type\
    \ check(...);\n};\n\ntemplate <class T>\nclass has_const_iterator : public decltype(has_const_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\ntemplate <typename Type>\nauto print(const\
    \ Type &) -> typename std::enable_if<!has_const_iterator<Type>::value>::type;\n\
    \ntemplate <class Container>\nauto print(const Container &) -> typename std::enable_if<has_const_iterator<Container>::value>::type;\n\
    \nvoid print(const std::string &);\n\nvoid print(std::string_view);\n\ntemplate\
    \ <typename... Types>\nvoid print(const std::stack<Types...> &);\n\ntemplate <typename...\
    \ Types>\nvoid print(const std::queue<Types...> &);\n\ntemplate <typename... Types>\n\
    void print(const std::priority_queue<Types...> &);\n\ntemplate <typename T, typename\
    \ U>\nvoid print(const std::pair<T, U> &);\n\ntemplate <typename... Types>\nvoid\
    \ print(const std::tuple<Types...> &);\n\ntemplate <class Tuple, std::size_t...\
    \ Idxes>\nvoid print_tuple(const Tuple &, std::index_sequence<Idxes...>);\n\n\
    // Implementation.\nvoid elapsed() {\n    static const auto start = std::chrono::system_clock::now();\n\
    \    auto t = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()\
    \ - start).count();\n    os << \"(\" << std::setw(8) << t << \")\";\n}\n\ntemplate\
    \ <typename Type, typename... Args>\nvoid debug_internal(int line, std::string_view\
    \ context, const Type &first, const Args &...args) {\n    constexpr const char\
    \ *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr const\
    \ char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    elapsed();\n\
    \    os << \" [L\" << line << \"] \" << open_bracket << context << close_bracket\
    \ << \": \" << open_bracket;\n    print(first);\n    ((os << \", \", print(args)),\
    \ ...);\n    os << close_bracket << std::endl;\n}\n\nvoid debug_internal(int line)\
    \ {\n    elapsed();\n    os << \" [L\" << line << \"] (empty)\" << std::endl;\n\
    }\n\ntemplate <typename Type>\nauto print(const Type &a) -> typename std::enable_if<!has_const_iterator<Type>::value>::type\
    \ {\n    os << a;\n}\n\ntemplate <class Container>\nauto print(const Container\
    \ &c) -> typename std::enable_if<has_const_iterator<Container>::value>::type {\n\
    \    os << \"[\";\n    for(auto iter = std::cbegin(c); iter != std::cend(c); ++iter)\
    \ {\n        if(iter != std::cbegin(c)) os << \" \";\n        print(*iter);\n\
    \    }\n    os << \"]\";\n}\n\nvoid print(const std::string &s) {\n    os << s;\n\
    }\n\nvoid print(std::string_view sv) {\n    os << sv;\n}\n\ntemplate <typename...\
    \ Types>\nvoid print(const std::stack<Types...> &st) {\n    std::stack<Types...>\
    \ tmp = st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Types>\nvoid print(const std::queue<Types...>\
    \ &que) {\n    std::queue<Types...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Types>\nvoid\
    \ print(const std::priority_queue<Types...> &pque) {\n    std::priority_queue<Types...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T, U>\
    \ &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <typename... Types>\nvoid print(const std::tuple<Types...>\
    \ &t) {\n    print_tuple(t, std::make_index_sequence<sizeof...(Types)>());\n}\n\
    \ntemplate <class Tuple, std::size_t... Idxes>\nvoid print_tuple(const Tuple &t,\
    \ std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes == 0\
    \ ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n}\n\n\
    }  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 10 \"verify/yosupo-staticrmp-sparse_table.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = int;\n    std::vector<S> a(n);\n    for(auto &elem : a) std::cin >> elem;\n\
    \n    auto op = [](S a, S b) -> S { return std::min(a, b); };\n    algorithm::SparseTable<S,\
    \ op> sparse_table(std::move(a));\n    debug(sparse_table);\n    debug(a);\n\n\
    \    while(q--) {\n        int l, r;\n        std::cin >> l >> r;\n\n        auto\
    \ &&ans = sparse_table.prod(l, r);\n        std::cout << ans << \"\\n\";\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n\n\
    #include \"../lib/DataStructure/SegmentTree/sparse_table.hpp\"\n#include \"../lib/Utils/debug.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = int;\n    std::vector<S> a(n);\n    for(auto &elem : a) std::cin >> elem;\n\
    \n    auto op = [](S a, S b) -> S { return std::min(a, b); };\n    algorithm::SparseTable<S,\
    \ op> sparse_table(std::move(a));\n    debug(sparse_table);\n    debug(a);\n\n\
    \    while(q--) {\n        int l, r;\n        std::cin >> l >> r;\n\n        auto\
    \ &&ans = sparse_table.prod(l, r);\n        std::cout << ans << \"\\n\";\n   \
    \ }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/sparse_table.hpp
  - lib/Utils/debug.hpp
  isVerificationFile: true
  path: verify/yosupo-staticrmp-sparse_table.test.cpp
  requiredBy: []
  timestamp: '2025-03-29 17:30:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-staticrmp-sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-staticrmp-sparse_table.test.cpp
- /verify/verify/yosupo-staticrmp-sparse_table.test.cpp.html
title: verify/yosupo-staticrmp-sparse_table.test.cpp
---
