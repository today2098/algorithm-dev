---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/big_integer.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B
  bundledCode: "#line 1 \"test/aoj-NTL_2_B-big_integer.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B\"\n\n#include\
    \ <iostream>\n\n#line 1 \"lib/Math/NumberTheory/big_integer.hpp\"\n\n\n\n/**\n\
    \ * @brief \u591A\u500D\u9577\u6574\u6570\n * @docs docs/Math/big_integer.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include\
    \ <iomanip>\n#include <sstream>\n#include <string>\n#include <string_view>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\nclass BigInteger {\n    static constexpr\
    \ int BASE_DIGIT = 9;\n    static constexpr int64_t BASE = 1e9;\n\n    int m_sign;\n\
    \    std::vector<int64_t> m_words;\n\n    bool validate(std::string_view sv) const\
    \ {\n        if(sv.empty()) return false;\n        const int len = sv.size();\n\
    \        int i = 0;\n        if(sv[0] == '+' or sv[0] == '-') {\n            if(len\
    \ < 2) return false;\n            i++;\n        }\n        for(; i < len; ++i)\
    \ {\n            if(!('0' <= sv[i] and sv[i] <= '9')) return false;\n        }\n\
    \        return true;\n    }\n    void convert_internal(std::string_view sv) {\n\
    \        const int len = sv.size();\n        const int n = (len + BASE_DIGIT -\
    \ 1) / BASE_DIGIT;\n        m_words.assign(n, 0);\n        int offset = 0;\n \
    \       for(int i = 0; i < n; ++i) {\n            for(int j = std::min(BASE_DIGIT,\
    \ len - offset) - 1; j >= 0; --j) m_words[i] = 10 * m_words[i] + (sv[len - offset\
    \ - 1 - j] - '0');\n            offset += BASE_DIGIT;\n        }\n        while(m_words.size()\
    \ > 1 and m_words.back() == 0) m_words.pop_back();\n        m_sign = (m_words.back()\
    \ == 0 ? 0 : 1);\n    }\n    void convert(std::string_view sv) {\n        if(sv[0]\
    \ == '+') {\n            convert_internal(sv.substr(1));\n            return;\n\
    \        }\n        if(sv[0] == '-') {\n            convert_internal(sv.substr(1));\n\
    \            negation();\n            return;\n        }\n        convert_internal(sv);\n\
    \    }\n    int compare(const std::vector<int64_t> &rhs) const {\n        const\
    \ int n = m_words.size(), m = rhs.size();\n        if(n < m) return -1;\n    \
    \    if(n > m) return 1;\n        for(int i = n - 1; i >= 0; --i) {\n        \
    \    if(m_words[i] != rhs[i]) return (m_words[i] < rhs[i] ? -1 : 1);\n       \
    \ }\n        return 0;\n    }\n    void addition(const std::vector<int64_t> &rhs)\
    \ {\n        int n = m_words.size();\n        const int m = rhs.size();\n    \
    \    if(n < m) n = m;\n        m_words.resize(n + 1, 0);\n        for(int i =\
    \ 0; i < m; ++i) {\n            m_words[i] += rhs[i];\n            if(m_words[i]\
    \ >= BASE) m_words[i] -= BASE, m_words[i + 1]++;  // carry.\n        }\n     \
    \   for(int i = m; i < n; ++i) {\n            if(m_words[i] < BASE) break;\n \
    \           m_words[i] -= BASE, m_words[i + 1]++;  // carry.\n        }\n    \
    \    if(m_words.back() == 0) m_words.pop_back();\n    }\n    void subtraction1(const\
    \ std::vector<int64_t> &rhs) {\n        const int n = m_words.size(), m = rhs.size();\n\
    \        for(int i = 0; i < m; ++i) {\n            m_words[i] -= rhs[i];\n   \
    \         if(m_words[i] < 0) m_words[i] += BASE, m_words[i + 1]--;  // carry.\n\
    \        }\n        for(int i = m; i < n - 1; ++i) {\n            if(m_words[i]\
    \ >= 0) break;\n            m_words[i] += BASE, m_words[i + 1]--;  // carry.\n\
    \        }\n        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();\n\
    \    }\n    void subtraction2(const std::vector<int64_t> &rhs) {\n        const\
    \ int n = rhs.size();\n        if(n > (int)m_words.size()) m_words.resize(n, 0);\n\
    \        for(int i = 0; i < n; ++i) {\n            m_words[i] -= rhs[i];\n   \
    \         if(m_words[i] > 0) m_words[i] -= BASE, m_words[i + 1]++;  // carry.\n\
    \        }\n        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();\n\
    \        for(int64_t &word : m_words) word = -word;\n    }\n\npublic:\n    BigInteger()\
    \ : m_sign(0), m_words({0}) {};\n    BigInteger(int64_t n) : m_sign(0), m_words({n})\
    \ {\n        if(n < 0) m_sign = -1, m_words[0] = -m_words[0];\n        else if(n\
    \ > 0) m_sign = 1;\n        while(m_words.back() >= BASE) {\n            int64_t\
    \ c = m_words.back() / BASE;\n            m_words.back() -= BASE * c;\n      \
    \      m_words.push_back(c);  // carry.\n        }\n    }\n    BigInteger(const\
    \ char *s) : BigInteger(std::string_view(s)) {}\n    BigInteger(const std::string\
    \ &s) : BigInteger(std::string_view(s)) {}\n    BigInteger(std::string_view sv)\
    \ {\n        assert(validate(sv));\n        convert(sv);\n    }\n\n    BigInteger\
    \ &operator+=(const BigInteger &rhs) {\n        if(rhs.is_zero()) return *this;\n\
    \        if(is_zero()) return *this = rhs;\n        if(m_sign == rhs.m_sign) {\n\
    \            addition(rhs.m_words);\n        } else {\n            int cmp = compare(rhs.m_words);\n\
    \            if(cmp < 0) {\n                subtraction2(rhs.m_words);\n     \
    \           negation();\n            } else if(cmp == 0) {\n                zeroing();\n\
    \            } else {\n                subtraction1(rhs.m_words);\n          \
    \  }\n        }\n        return *this;\n    }\n    BigInteger &operator-=(const\
    \ BigInteger &rhs) {\n        if(rhs.is_zero()) return *this;\n        if(is_zero())\
    \ {\n            *this = rhs;\n            negation();\n            return *this;\n\
    \        }\n        if(m_sign != rhs.m_sign) {\n            addition(rhs.m_words);\n\
    \        } else {\n            int cmp = compare(rhs.m_words);\n            if(cmp\
    \ < 0) {\n                subtraction2(rhs.m_words);\n                negation();\n\
    \            } else if(cmp == 0) {\n                zeroing();\n            }\
    \ else {\n                subtraction1(rhs.m_words);\n            }\n        }\n\
    \        return *this;\n    }\n    BigInteger &operator*=(const BigInteger &rhs)\
    \ {\n        if(is_zero()) return *this;\n        if(rhs.is_zero()) {\n      \
    \      zeroing();\n            return *this;\n        }\n        m_sign = m_sign\
    \ * rhs.m_sign;\n        const int n = m_words.size(), m = rhs.m_words.size();\n\
    \        std::vector<int64_t> res(n + m, 0);\n        for(int j = 0; j < m; ++j)\
    \ {\n            for(int i = 0; i < n; ++i) {\n                res[i + j] += m_words[i]\
    \ * rhs.m_words[j];\n                if(res[i + j] >= BASE) {\n              \
    \      int64_t c = res[i + j] / BASE;\n                    res[i + j] -= BASE\
    \ * c, res[i + j + 1] += c;  // carry.\n                }\n            }\n   \
    \     }\n        if(res.back() == 0) res.pop_back();\n        m_words = res;\n\
    \        return *this;\n    }\n\n    friend bool operator<(const BigInteger &lhs,\
    \ const BigInteger &rhs) {\n        if(lhs.m_sign == rhs.m_sign) {\n         \
    \   if(lhs.m_sign < 0) return lhs.compare(rhs.m_words) == 1;\n            return\
    \ lhs.compare(rhs.m_words) == -1;\n        }\n        return lhs.m_sign < rhs.m_sign;\n\
    \    }\n    friend bool operator>(const BigInteger &lhs, const BigInteger &rhs)\
    \ { return rhs < lhs; }\n    friend bool operator<=(const BigInteger &lhs, const\
    \ BigInteger &rhs) { return !(lhs > rhs); }\n    friend bool operator>=(const\
    \ BigInteger &lhs, const BigInteger &rhs) { return !(lhs < rhs); }\n    friend\
    \ BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs) { return\
    \ BigInteger(lhs) += rhs; }\n    friend BigInteger operator-(const BigInteger\
    \ &lhs, const BigInteger &rhs) { return BigInteger(lhs) -= rhs; }\n    friend\
    \ BigInteger operator*(const BigInteger &lhs, const BigInteger &rhs) { return\
    \ BigInteger(lhs) *= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, BigInteger &rhs) {\n        std::string s;\n        is >> s;\n        assert(rhs.validate(s));\n\
    \        rhs.convert(s);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BigInteger &rhs) {\n        os << (rhs.m_sign == -1 ? \"-\" : \"\"\
    ) << rhs.m_words.back();\n        for(auto itr = rhs.m_words.crbegin() + 1; itr\
    \ < rhs.m_words.crend(); ++itr) os << std::setw(BASE_DIGIT) << std::setfill('0')\
    \ << *itr;\n        return os;\n    }\n\n    bool is_zero() const { return sign()\
    \ == 0; }\n    int sign() const { return m_sign; }\n    void zeroing() {\n   \
    \     m_sign = 0;\n        m_words.assign(1, 0);\n    }\n    void negation() {\
    \ m_sign = -m_sign; }\n    std::string to_string() const {\n        std::ostringstream\
    \ oss;\n        oss << *this;\n        return oss.str();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"test/aoj-NTL_2_B-big_integer.test.cpp\"\n\nint main()\
    \ {\n    algorithm::BigInteger a, b;\n    std::cin >> a >> b;\n\n    auto &&ans\
    \ = a - b;\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_B\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/big_integer.hpp\"\
    \n\nint main() {\n    algorithm::BigInteger a, b;\n    std::cin >> a >> b;\n\n\
    \    auto &&ans = a - b;\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/big_integer.hpp
  isVerificationFile: true
  path: test/aoj-NTL_2_B-big_integer.test.cpp
  requiredBy: []
  timestamp: '2024-09-27 21:23:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_2_B-big_integer.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_2_B-big_integer.test.cpp
- /verify/test/aoj-NTL_2_B-big_integer.test.cpp.html
title: test/aoj-NTL_2_B-big_integer.test.cpp
---
