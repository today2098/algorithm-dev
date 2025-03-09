---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E
  bundledCode: "#line 1 \"test/aoj-NTL_2_E-bigint.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/bigint.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n\
    #include <iomanip>\n#include <sstream>\n#include <string>\n#include <string_view>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u591A\u500D\
    \u9577\u6574\u6570\uFF0E\nclass Bigint {\n    static constexpr int32_t BASE =\
    \ 1'000'000'000;\n    static constexpr size_t BASE_DIGIT = 9;\n\n    std::vector<int32_t>\
    \ m_words;\n    int m_sign;\n\n    explicit Bigint(const std::vector<int32_t>\
    \ &words, int sign) : m_words(words), m_sign(sign) {}\n\n    static constexpr\
    \ bool isdigit(char c) { return '0' <= c and c <= '9'; }\n    static constexpr\
    \ bool validate(std::string_view sv) {\n        size_t n = sv.size();\n      \
    \  if(n == 0) return false;\n        if(n == 1) return isdigit(sv[0]);\n     \
    \   if(!(sv[0] == '+' or sv[0] == '-' or isdigit(sv[0]))) return false;\n    \
    \    return std::find_if_not(sv.cbegin() + 1, sv.cend(), [](char c) -> bool {\
    \ return isdigit(c); }) == sv.cend();\n    }\n    static int32_t store(int32_t\
    \ &word, int64_t val) {\n        int32_t carry = val / BASE;\n        word = val\
    \ - (int64_t)carry * BASE;\n        if(word < 0) word += BASE, --carry;\n    \
    \    return carry;\n    }\n    static int32_t add_store(int32_t &word, int64_t\
    \ val) {\n        if(val < 0) {\n            word = val + BASE;\n            return\
    \ -1;\n        }\n        if(val < BASE) {\n            word = val;\n        \
    \    return 0;\n        }\n        word = val - BASE;\n        return 1;\n   \
    \ }\n    static int compare(const Bigint &lhs, const Bigint &rhs) {\n        if(lhs.sign()\
    \ == rhs.sign()) return compare(lhs.m_words, lhs.m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n        return (lhs.sign() < rhs.sign() ? -1 : 1);\n \
    \   }\n    static int compare(const std::vector<int32_t> &lhs, ssize_t n, const\
    \ std::vector<int32_t> &rhs, ssize_t m) {\n        if(n < m) return -1;\n    \
    \    if(n > m) return 1;\n        for(ssize_t i = n - 1; i >= 0; --i) {\n    \
    \        if(lhs[i] == rhs[i]) continue;\n            return (lhs[i] < rhs[i] ?\
    \ -1 : 1);\n        }\n        return 0;\n    }\n    static void addition(std::vector<int32_t>\
    \ &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {\n        n = std::max(n,\
    \ m);\n        lhs.resize(n, 0);\n        int32_t carry = 0;\n        for(size_t\
    \ i = 0; i < m; ++i) carry = add_store(lhs[i], (int64_t)lhs[i] + rhs[i] + carry);\n\
    \        for(size_t i = m; i < n and carry != 0; ++i) carry = add_store(lhs[i],\
    \ (int64_t)lhs[i] + carry);\n        if(carry != 0) lhs.push_back(carry);\n  \
    \  }\n    static int subtraction(std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t>\
    \ &rhs, size_t m) {\n        int sign = compare(lhs, n, rhs, m);\n        if(sign\
    \ == 0) {\n            lhs.clear();\n            return 0;\n        }\n      \
    \  if(sign < 0) {\n            lhs.resize(m, 0);\n            int32_t carry =\
    \ 0;\n            for(size_t i = 0; i < m; ++i) carry = add_store(lhs[i], (int64_t)rhs[i]\
    \ - lhs[i] + carry);\n        } else {\n            int32_t carry = 0;\n     \
    \       for(size_t i = 0; i < m; ++i) carry = add_store(lhs[i], (int64_t)lhs[i]\
    \ - rhs[i] + carry);\n            for(size_t i = m; i < n and carry != 0; ++i)\
    \ carry = add_store(lhs[i], (int64_t)lhs[i] + carry);\n        }\n        while(!lhs.empty()\
    \ and lhs.back() == 0) lhs.pop_back();\n        return sign;\n    }\n    static\
    \ std::vector<int32_t> multiplication(const std::vector<int32_t> &lhs, size_t\
    \ n, const std::vector<int32_t> &rhs, size_t m) {\n        std::vector<int32_t>\
    \ res(n + m, 0);\n        for(size_t i = 0; i < n; ++i) {\n            int32_t\
    \ carry = 0;\n            for(size_t j = 0; j < m; ++j) carry = store(res[i +\
    \ j], res[i + j] + (int64_t)lhs[i] * rhs[j] + carry);\n            res[i + m]\
    \ = carry;\n        }\n        while(!res.empty() and res.back() == 0) res.pop_back();\n\
    \        return res;\n    }\n    static std::vector<int32_t> division(std::vector<int32_t>\
    \ &lhs, ssize_t n, const std::vector<int32_t> &rhs, ssize_t m) {\n        assert(m\
    \ > 0);\n        if(n < m) return {};\n        std::vector<int32_t> res(n - m\
    \ + 1);\n        auto bisearch = [&](ssize_t offset) -> int32_t {\n          \
    \  auto eval = [&](int32_t d) -> bool {\n                int32_t carry = 0;\n\
    \                for(ssize_t i = 0; i < m; ++i) {\n                    int32_t\
    \ tmp;\n                    carry = store(tmp, lhs[i + offset] - (int64_t)rhs[i]\
    \ * d + carry);\n                }\n                if(carry == 0) return true;\n\
    \                return (m + offset < n ? lhs[m + offset] + carry >= 0 : false);\n\
    \            };\n            int32_t ok = 0, ng = BASE;\n            while(ng\
    \ - ok > 1) {\n                int32_t mid = (ok + ng) / 2;\n                (eval(mid)\
    \ ? ok : ng) = mid;\n            }\n            return ok;\n        };\n     \
    \   auto sub = [&](ssize_t offset, int32_t d) -> void {\n            int32_t carry\
    \ = 0;\n            for(ssize_t i = 0; i < m; ++i) carry = store(lhs[i + offset],\
    \ lhs[i + offset] - (int64_t)rhs[i] * d + carry);\n            if(carry != 0)\
    \ lhs[m + offset] += carry;\n        };\n        for(ssize_t i = n - m; i >= 0;\
    \ --i) {\n            res[i] = bisearch(i);\n            sub(i, res[i]);\n   \
    \     }\n        if(res.back() == 0) res.pop_back();\n        while(!lhs.empty()\
    \ and lhs.back() == 0) lhs.pop_back();\n        return res;\n    }\n    void normalize(std::string_view\
    \ sv, size_t n) {\n        assert(n > 0);\n        if(sv[0] == '+') {\n      \
    \      normalize_unsigned(sv.substr(1), n - 1);\n        } else if(sv[0] == '-')\
    \ {\n            normalize_unsigned(sv.substr(1), n - 1);\n            negation();\n\
    \        } else {\n            normalize_unsigned(sv, n);\n        }\n    }\n\
    \    void normalize_unsigned(std::string_view sv, size_t n) {\n        size_t\
    \ m = (n + BASE_DIGIT - 1) / BASE_DIGIT;\n        m_words.assign(m, 0);\n    \
    \    auto iter = sv.crbegin();\n        for(size_t i = 0; i < m; ++i) {\n    \
    \        int32_t d = 1;\n            for(size_t j = 0; j < BASE_DIGIT and iter\
    \ < sv.crend(); ++j, ++iter, d *= 10) m_words[i] += (*iter - '0') * d;\n     \
    \   }\n        while(!m_words.empty() and m_words.back() == 0) m_words.pop_back();\n\
    \        m_sign = (m_words.empty() ? 0 : 1);\n    }\n\npublic:\n    Bigint() :\
    \ m_words(), m_sign(0) {};\n    Bigint(int64_t n) : Bigint() {\n        if(n ==\
    \ 0) return;\n        if(n < 0) n *= -1, m_sign = -1;\n        else m_sign = 1;\n\
    \        while(n > 0) {\n            int32_t word;\n            n = store(word,\
    \ n);\n            m_words.push_back(word);\n        }\n    }\n    Bigint(const\
    \ char *c) : Bigint(std::string_view(c)) {}\n    Bigint(std::string_view s) {\n\
    \        std::stringstream ss;\n        ss << s;\n        ss >> *this;\n    }\n\
    \n    Bigint operator+() const { return Bigint(*this); }\n    Bigint operator-()\
    \ const {\n        Bigint res = *this;\n        res.negation();\n        return\
    \ res;\n    }\n    Bigint &operator+=(const Bigint &rhs) {\n        if(rhs.is_zero())\
    \ return *this;\n        if(is_zero()) return *this = rhs;\n        if(sign()\
    \ == rhs.sign()) addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        else m_sign *= subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    Bigint &operator-=(const Bigint &rhs) {\n \
    \       if(rhs.is_zero()) return *this;\n        if(is_zero()) return *this =\
    \ -rhs;\n        if(sign() == rhs.sign()) m_sign *= subtraction(m_words, m_words.size(),\
    \ rhs.m_words, rhs.m_words.size());\n        else addition(m_words, m_words.size(),\
    \ rhs.m_words, rhs.m_words.size());\n        return *this;\n    }\n    Bigint\
    \ &operator*=(const Bigint &rhs) { return *this = (*this) * rhs; }\n    Bigint\
    \ &operator/=(const Bigint &rhs) {\n        assert(!rhs.is_zero());\n        if(is_zero())\
    \ return *this;\n        m_words = division(m_words, m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n        m_sign = (m_words.empty() ? 0 : sign() * rhs.sign());\n\
    \        return *this;\n    }\n    Bigint &operator%=(const Bigint &rhs) {\n \
    \       assert(!rhs.is_zero());\n        if(is_zero()) return *this;\n       \
    \ division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n      \
    \  if(m_words.empty()) m_sign = 0;\n        return *this;\n    }\n\n    friend\
    \ bool operator==(const Bigint &lhs, const Bigint &rhs) { return lhs.sign() ==\
    \ rhs.sign() and lhs.m_words == rhs.m_words; }\n    friend int operator<=>(const\
    \ Bigint &lhs, const Bigint &rhs) { return compare(lhs, rhs); }\n    friend Bigint\
    \ operator+(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs;\
    \ }\n    friend Bigint operator-(const Bigint &lhs, const Bigint &rhs) { return\
    \ Bigint(lhs) -= rhs; }\n    friend Bigint operator*(const Bigint &lhs, const\
    \ Bigint &rhs) {\n        if(lhs.is_zero() or rhs.is_zero()) return Bigint();\n\
    \        return Bigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words,\
    \ rhs.m_words.size()), lhs.sign() * rhs.sign());\n    }\n    friend Bigint operator/(const\
    \ Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) /= rhs; }\n    friend Bigint\
    \ operator%(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) %= rhs;\
    \ }\n    friend std::istream &operator>>(std::istream &is, Bigint &rhs) {\n  \
    \      std::string s;\n        is >> s;\n        assert(validate(s));\n      \
    \  rhs.normalize(s, s.size());\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Bigint &rhs) {\n        if(rhs.is_zero())\
    \ return os << 0;\n        os << (rhs.is_minus() ? \"-\" : \"\") << rhs.m_words.back();\n\
    \        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend();\
    \ ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0') << *iter;\n       \
    \ return os;\n    }\n\n    bool is_zero() const { return sign() == 0; }\n    bool\
    \ is_minus() const { return sign() < 0; }\n    int sign() const { return m_sign;\
    \ }\n    Bigint abs() const { return Bigint(m_words, std::abs(sign())); }\n  \
    \  std::pair<Bigint, Bigint> divide(const Bigint &a) const {\n        assert(!a.is_zero());\n\
    \        if(is_zero()) return {Bigint(), Bigint()};\n        auto remain = m_words;\n\
    \        auto &&quotient = division(remain, remain.size(), a.m_words, a.m_words.size());\n\
    \        return {Bigint(std::move(quotient), (quotient.empty() ? 0 : sign() *\
    \ a.sign())), Bigint(std::move(remain), (remain.empty() ? 0 : sign()))};\n   \
    \ }\n    void zeroize() {\n        m_words.clear();\n        m_sign = 0;\n   \
    \ }\n    void negation() { m_sign *= -1; }\n    std::string to_string() const\
    \ {\n        std::ostringstream oss;\n        oss << *this;\n        return oss.str();\n\
    \    }\n    const std::vector<int32_t> &words() const { return m_words; }\n\n\
    \    friend Bigint abs(const Bigint &a) { return a.abs(); }\n};\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"test/aoj-NTL_2_E-bigint.test.cpp\"\n\nint main() {\n\
    \    algorithm::Bigint a, b;\n    std::cin >> a >> b;\n\n    auto ans = a % b;\n\
    \    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_E\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/bigint.hpp\"\n\n\
    int main() {\n    algorithm::Bigint a, b;\n    std::cin >> a >> b;\n\n    auto\
    \ ans = a % b;\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/bigint.hpp
  isVerificationFile: true
  path: test/aoj-NTL_2_E-bigint.test.cpp
  requiredBy: []
  timestamp: '2025-03-09 23:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_2_E-bigint.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_2_E-bigint.test.cpp
- /verify/test/aoj-NTL_2_E-bigint.test.cpp.html
title: test/aoj-NTL_2_E-bigint.test.cpp
---
