---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/Math/NumberTheory/bigint.hpp
    title: algorithm/Math/NumberTheory/bigint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E
  bundledCode: "#line 1 \"verify/aoj-NTL_2_E-bigint.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E\"\n\n#include\
    \ <iostream>\n\n#line 1 \"algorithm/Math/NumberTheory/bigint.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n#include\
    \ <iomanip>\n#include <sstream>\n#include <string>\n#include <string_view>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u591A\u500D\u9577\
    \u6574\u6570\uFF0E\nclass Bigint {\n    static constexpr int32_t BASE = 1'000'000'000;\n\
    \    static constexpr size_t BASE_DIGIT = 9;\n\n    std::vector<int32_t> m_words;\n\
    \    bool m_neg;\n\n    explicit Bigint(const std::vector<int32_t> &words, bool\
    \ neg) : m_words(words), m_neg(neg) {}\n    explicit Bigint(std::vector<int32_t>\
    \ &&words, bool neg) : m_words(std::move(words)), m_neg(neg) {}\n\n    static\
    \ constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }\n    static\
    \ constexpr bool validate(std::string_view sv, size_t n) {\n        if(n == 0)\
    \ return false;\n        if(sv[0] == '+' or sv[0] == '-') return validate_unsigned(sv.substr(1),\
    \ n - 1);\n        return validate_unsigned(sv, n);\n    }\n    static constexpr\
    \ bool validate_unsigned(std::string_view sv, size_t n) {\n        if(n == 0)\
    \ return false;\n        return std::find_if_not(sv.cbegin(), sv.cend(), [](char\
    \ c) -> bool { return isdigit(c); }) == sv.cend();\n    }\n    static int compare(const\
    \ Bigint &lhs, const Bigint &rhs) {\n        if(lhs.m_neg ^ rhs.m_neg) return\
    \ (lhs.m_neg ? -1 : 1);\n        return compare(lhs.m_words, lhs.m_words.size(),\
    \ rhs.m_words, rhs.m_words.size());\n    }\n    static int compare(const std::vector<int32_t>\
    \ &lhs, ssize_t n, const std::vector<int32_t> &rhs, ssize_t m) {\n        if(n\
    \ < m) return -1;\n        if(n > m) return 1;\n        for(ssize_t i = n - 1;\
    \ i >= 0; --i) {\n            if(lhs[i] == rhs[i]) continue;\n            if(lhs[i]\
    \ < rhs[i]) return -1;\n            return 1;\n        }\n        return 0;\n\
    \    }\n    static int32_t add_store(int32_t &word, int32_t val) {\n        if(val\
    \ < 0) {\n            word = val + BASE;\n            return -1;\n        }\n\
    \        if(val < BASE) {\n            word = val;\n            return 0;\n  \
    \      }\n        word = val - BASE;\n        return 1;\n    }\n    static int32_t\
    \ store(int32_t &word, int64_t val) {\n        int32_t carry = val / BASE;\n \
    \       word = val - (int64_t)carry * BASE;\n        if(word < 0) word += BASE,\
    \ --carry;\n        return carry;\n    }\n    static size_t shrink(std::vector<int32_t>\
    \ &words) {\n        while(!words.empty() and words.back() == 0) words.pop_back();\n\
    \        return words.size();\n    }\n    static size_t zeroisation(std::vector<int32_t>\
    \ &words) {\n        words.clear();\n        return 0;\n    }\n    static size_t\
    \ negation(std::vector<int32_t> &words) {\n        int32_t ncarry = 0;\n     \
    \   for(int32_t &word : words) ncarry = add_store(word, -word + ncarry);\n   \
    \     return words.size();\n    }\n    static void addition(std::vector<int32_t>\
    \ &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {\n        n = std::max(n,\
    \ m);\n        lhs.resize(n, 0);\n        int32_t carry = 0;\n        for(size_t\
    \ i = 0; i < m; ++i) carry = add_store(lhs[i], lhs[i] + rhs[i] + carry);\n   \
    \     for(size_t i = m; i < n and carry > 0; ++i) carry = add_store(lhs[i], lhs[i]\
    \ + carry);\n        if(carry > 0) lhs.push_back(carry);\n    }\n    static bool\
    \ subtraction(std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t>\
    \ &rhs, size_t m) {\n        n = std::max(n, m);\n        lhs.resize(n, 0);\n\
    \        int32_t ncarry = 0;\n        for(size_t i = 0; i < m; ++i) ncarry = add_store(lhs[i],\
    \ lhs[i] - rhs[i] + ncarry);\n        for(size_t i = m; i < n and ncarry < 0;\
    \ ++i) ncarry = add_store(lhs[i], lhs[i] + ncarry);\n        if(ncarry < 0) negation(lhs);\n\
    \        shrink(lhs);\n        return ncarry < 0;\n    }\n    static std::vector<int32_t>\
    \ multiplication(const std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t>\
    \ &rhs, size_t m) {\n        std::vector<int32_t> res(n + m, 0);\n        for(size_t\
    \ j = 0; j < m; ++j) {\n            if(rhs[j] == 0) continue;\n            int32_t\
    \ carry = 0;\n            for(size_t i = 0; i < n; ++i) carry = store(res[i +\
    \ j], res[i + j] + (int64_t)lhs[i] * rhs[j] + carry);\n            res[j + n]\
    \ = carry;\n        }\n        shrink(res);\n        return res;\n    }\n    static\
    \ std::vector<int32_t> division(std::vector<int32_t> &lhs, ssize_t n, const std::vector<int32_t>\
    \ &rhs, ssize_t m) {\n        assert(m > 0);\n        if(n < m) return {};\n \
    \       std::vector<int32_t> res(n - m + 1);\n        auto bisearch = [&](ssize_t\
    \ offset) -> int32_t {\n            if(n - offset < m) return 0;\n           \
    \ auto eval = [&](int32_t d) -> bool {\n                int32_t ncarry = 0;\n\
    \                for(ssize_t i = 0; i < m; ++i) {\n                    int32_t\
    \ tmp;\n                    ncarry = store(tmp, lhs[i + offset] - (int64_t)rhs[i]\
    \ * d + ncarry);\n                }\n                int32_t last = (m + offset\
    \ < n ? lhs[m + offset] : 0) + ncarry;\n                return last >= 0;\n  \
    \          };\n            int32_t ok = 0, ng = BASE;\n            while(ng -\
    \ ok > 1) {\n                int32_t mid = ok + (ng - ok) / 2;\n             \
    \   (eval(mid) ? ok : ng) = mid;\n            }\n            return ok;\n    \
    \    };\n        auto sub = [&](ssize_t offset, int32_t d) -> void {\n       \
    \     int32_t ncarry = 0;\n            for(ssize_t i = 0; i < m; ++i) ncarry =\
    \ store(lhs[i + offset], lhs[i + offset] - (int64_t)rhs[i] * d + ncarry);\n  \
    \          if(m + offset < n) lhs.pop_back();\n            n = shrink(lhs);\n\
    \        };\n        for(ssize_t i = n - m; i >= 0; --i) {\n            res[i]\
    \ = bisearch(i);\n            if(res[i] > 0) sub(i, res[i]);\n        }\n    \
    \    if(res.back() == 0) res.pop_back();\n        return res;\n    }\n    void\
    \ normalize(std::string_view sv, size_t n) {\n        assert(n > 0);\n       \
    \ if(sv[0] == '+') {\n            normalize_unsigned(sv.substr(1), n - 1);\n \
    \           m_neg = false;\n        } else if(sv[0] == '-') {\n            normalize_unsigned(sv.substr(1),\
    \ n - 1);\n            m_neg = !m_words.empty();\n        } else {\n         \
    \   normalize_unsigned(sv, n);\n            m_neg = false;\n        }\n    }\n\
    \    void normalize_unsigned(std::string_view sv, size_t n) {\n        static\
    \ constexpr uint32_t digits[BASE_DIGIT] = {1, 10, 100, 1'000, 10'000, 100'000,\
    \ 1'000'000, 10'000'000, 100'000'000};\n        size_t m = (n + BASE_DIGIT - 1)\
    \ / BASE_DIGIT;\n        m_words.assign(m, 0);\n        auto iter = sv.crbegin();\n\
    \        for(size_t i = 0; i < m; ++i) {\n            for(size_t j = 0; j < BASE_DIGIT\
    \ and iter < sv.crend(); ++j, ++iter) m_words[i] += digits[j] * (*iter - '0');\n\
    \        }\n        shrink(m_words);\n    }\n\npublic:\n    Bigint() : m_words(),\
    \ m_neg(false) {};\n    Bigint(int64_t n) : m_words(), m_neg(n < 0) {\n      \
    \  n = std::abs(n);\n        while(n > 0) {\n            int32_t word;\n     \
    \       n = store(word, n);\n            m_words.push_back(word);\n        }\n\
    \    }\n    Bigint(const char *c) : Bigint(std::string_view(c)) {}\n    Bigint(std::string_view\
    \ s) {\n        std::stringstream ss;\n        ss << s;\n        ss >> *this;\n\
    \    }\n\n    explicit operator bool() const { return !is_zero(); }\n    Bigint\
    \ operator+() const { return Bigint(*this); }\n    Bigint operator-() const {\n\
    \        Bigint res = *this;\n        return res.negate();\n    }\n    Bigint\
    \ &operator++() { return *this += Bigint({1}, false); }\n    Bigint &operator--()\
    \ { return *this -= Bigint({1}, false); }\n    Bigint operator++(int) {\n    \
    \    Bigint res = *this;\n        ++(*this);\n        return res;\n    }\n   \
    \ Bigint operator--(int) {\n        Bigint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    Bigint &operator+=(const Bigint &rhs) {\n   \
    \     if(is_negative() ^ rhs.is_negative()) {\n            m_neg ^= subtraction(m_words,\
    \ m_words.size(), rhs.m_words, rhs.m_words.size());\n            if(m_words.empty())\
    \ m_neg = false;\n        } else {\n            addition(m_words, m_words.size(),\
    \ rhs.m_words, rhs.m_words.size());\n        }\n        return *this;\n    }\n\
    \    Bigint &operator-=(const Bigint &rhs) {\n        if(is_negative() ^ rhs.is_negative())\
    \ {\n            addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        } else {\n            m_neg ^= subtraction(m_words, m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n            if(m_words.empty()) m_neg = false;\n     \
    \   }\n        return *this;\n    }\n    Bigint &operator*=(const Bigint &rhs)\
    \ { return *this = (*this) * rhs; }\n    Bigint &operator/=(const Bigint &rhs)\
    \ {\n        assert(!rhs.is_zero());\n        m_words = division(m_words, m_words.size(),\
    \ rhs.m_words, rhs.m_words.size());\n        m_neg = (m_words.empty() ? false\
    \ : is_negative() ^ rhs.is_negative());\n        return *this;\n    }\n    Bigint\
    \ &operator%=(const Bigint &rhs) {\n        assert(!rhs.is_zero());\n        division(m_words,\
    \ m_words.size(), rhs.m_words, rhs.m_words.size());\n        if(m_words.empty())\
    \ m_neg = false;\n        return *this;\n    }\n\n    friend bool operator==(const\
    \ Bigint &lhs, const Bigint &rhs) { return lhs.m_words == rhs.m_words and lhs.m_neg\
    \ == rhs.m_neg; }\n    friend int operator<=>(const Bigint &lhs, const Bigint\
    \ &rhs) { return compare(lhs, rhs); }\n    friend Bigint operator+(const Bigint\
    \ &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs; }\n    friend Bigint operator-(const\
    \ Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) -= rhs; }\n    friend Bigint\
    \ operator*(const Bigint &lhs, const Bigint &rhs) {\n        if(lhs.is_zero()\
    \ or rhs.is_zero()) return Bigint();\n        return Bigint(multiplication(lhs.m_words,\
    \ lhs.m_words.size(), rhs.m_words, rhs.m_words.size()), lhs.is_negative() ^ rhs.is_negative());\n\
    \    }\n    friend Bigint operator/(const Bigint &lhs, const Bigint &rhs) { return\
    \ Bigint(lhs) /= rhs; }\n    friend Bigint operator%(const Bigint &lhs, const\
    \ Bigint &rhs) { return Bigint(lhs) %= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Bigint &rhs) {\n        std::string s;\n        is >> s;\n        assert(validate(s,\
    \ s.size()));\n        rhs.normalize(s, s.size());\n        return is;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Bigint &rhs) {\n\
    \        if(rhs.is_zero()) return os << 0;\n        auto iter = rhs.m_words.crbegin();\n\
    \        os << (rhs.is_negative() ? \"-\" : \"\") << *iter++;\n        for(; iter\
    \ < rhs.m_words.crend(); ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0')\
    \ << *iter;\n        return os;\n    }\n\n    static constexpr int32_t base()\
    \ { return BASE; }\n    static constexpr size_t base_digit() { return BASE_DIGIT;\
    \ }\n    const std::vector<int32_t> &words() const { return m_words; }\n    bool\
    \ is_zero() const { return m_words.empty(); }\n    bool is_negative() const {\
    \ return m_neg; }\n    int sign() const {\n        if(m_neg) return -1;\n    \
    \    return (m_words.empty() ? 0 : 1);\n    }\n    Bigint abs() const { return\
    \ Bigint(m_words, false); }\n    std::pair<Bigint, Bigint> divide(const Bigint\
    \ &divisor) const {\n        assert(!divisor.is_zero());\n        auto remain\
    \ = m_words;\n        auto &&quotient = division(remain, remain.size(), divisor.m_words,\
    \ divisor.m_words.size());\n        Bigint q(std::move(quotient), false), r(std::move(remain),\
    \ false);\n        if(!q.is_zero()) q.m_neg = is_negative() ^ divisor.is_negative();\n\
    \        if(!r.is_zero()) r.m_neg = is_negative();\n        return {q, r};\n \
    \   }\n    Bigint &zeroize() {\n        zeroisation(m_words), m_neg = false;\n\
    \        return *this;\n    }\n    Bigint &negate() {\n        if(!m_words.empty())\
    \ m_neg = !m_neg;\n        return *this;\n    }\n    std::string to_string() const\
    \ {\n        std::ostringstream oss;\n        oss << *this;\n        return oss.str();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/aoj-NTL_2_E-bigint.test.cpp\"\
    \n\nint main() {\n    algorithm::Bigint a, b;\n    std::cin >> a >> b;\n\n   \
    \ a %= b;\n    std::cout << a << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/Math/NumberTheory/bigint.hpp\"\
    \n\nint main() {\n    algorithm::Bigint a, b;\n    std::cin >> a >> b;\n\n   \
    \ a %= b;\n    std::cout << a << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/NumberTheory/bigint.hpp
  isVerificationFile: true
  path: verify/aoj-NTL_2_E-bigint.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj-NTL_2_E-bigint.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-NTL_2_E-bigint.test.cpp
- /verify/verify/aoj-NTL_2_E-bigint.test.cpp.html
title: verify/aoj-NTL_2_E-bigint.test.cpp
---
