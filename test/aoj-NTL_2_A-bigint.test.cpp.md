---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/NumberTheory/bigint.hpp
    title: lib/Math/NumberTheory/bigint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A
  bundledCode: "#line 1 \"test/aoj-NTL_2_A-bigint.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/Math/NumberTheory/bigint.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n\
    #include <deque>\n#include <iomanip>\n#include <sstream>\n#include <string>\n\
    #include <string_view>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u591A\u500D\u9577\u6574\u6570\uFF0E\nclass Bigint {\n    static constexpr\
    \ int64_t BASE = 1'000'000'000;\n    static constexpr size_t BASE_DIGIT = 9;\n\
    \n    std::vector<int64_t> m_words;\n    int m_sign;\n\n    explicit Bigint(const\
    \ std::vector<int64_t> &words, int sign) : m_words(words), m_sign(sign) {}\n\n\
    \    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }\n\
    \    static constexpr bool validate(std::string_view sv) {\n        size_t n =\
    \ sv.size();\n        if(n == 0) return false;\n        if(n == 1) return isdigit(sv[0]);\n\
    \        if(!(sv[0] == '+' or sv[0] == '-' or isdigit(sv[0]))) return false;\n\
    \        return std::find_if_not(sv.cbegin() + 1, sv.cend(), [](char c) -> bool\
    \ { return isdigit(c); }) == sv.cend();\n    }\n    static int compare(const Bigint\
    \ &lhs, const Bigint &rhs) {\n        if(lhs.sign() == rhs.sign()) return compare(lhs.m_words,\
    \ lhs.m_words.size(), rhs.m_words, rhs.m_words.size());\n        if(lhs.sign()\
    \ < rhs.sign()) return -1;\n        return 1;\n    }\n    static int compare(const\
    \ std::vector<int64_t> &lhs, ssize_t n, const std::vector<int64_t> &rhs, ssize_t\
    \ m) {\n        if(n < m) return -1;\n        if(n > m) return 1;\n        for(ssize_t\
    \ i = n - 1; i >= 0; --i) {\n            if(lhs[i] == rhs[i]) continue;\n    \
    \        return (lhs[i] < rhs[i] ? -1 : 1);\n        }\n        return 0;\n  \
    \  }\n    static void addition(std::vector<int64_t> &lhs, size_t n, const std::vector<int64_t>\
    \ &rhs, size_t m) {\n        n = std::max(n, m);\n        lhs.resize(n + 1, 0);\n\
    \        for(size_t i = 0; i < m; ++i) {\n            lhs[i] += rhs[i];\n    \
    \        if(lhs[i] >= BASE) lhs[i] -= BASE, lhs[i + 1]++;  // carry.\n       \
    \ }\n        for(size_t i = m; i < n; ++i) {\n            if(lhs[i] < BASE) break;\n\
    \            lhs[i] -= BASE, lhs[i + 1]++;  // carry.\n        }\n        if(lhs.back()\
    \ == 0) lhs.pop_back();\n    }\n    static int subtraction(std::vector<int64_t>\
    \ &lhs, ssize_t n, const std::vector<int64_t> &rhs, ssize_t m) {\n        n =\
    \ std::max(n, m);\n        lhs.resize(n, 0);\n        for(ssize_t i = 0; i < m;\
    \ ++i) lhs[i] -= rhs[i];\n        int sign = 0;\n        for(ssize_t i = n - 1;\
    \ i >= 0; --i) {\n            if(lhs[i] == 0) continue;\n            sign = (lhs[i]\
    \ < 0 ? -1 : 1);\n            break;\n        }\n        for(int64_t &word : lhs)\
    \ word *= sign;\n        for(ssize_t i = 0; i < n - 1; ++i) {\n            if(lhs[i]\
    \ < 0) lhs[i] += BASE, lhs[i + 1]--;  // carry.\n        }\n        while(!lhs.empty()\
    \ and lhs.back() == 0) lhs.pop_back();\n        return sign;\n    }\n    static\
    \ std::vector<int64_t> multiplication(const std::vector<int64_t> &lhs, size_t\
    \ n, const std::vector<int64_t> &rhs, size_t m) {\n        std::vector<int64_t>\
    \ res(n + m, 0);\n        for(size_t i = 0; i < n; ++i) {\n            for(size_t\
    \ j = 0; j < m; ++j) {\n                res[i + j] += lhs[i] * rhs[j];\n     \
    \           int64_t c = res[i + j] / BASE;\n                res[i + j] -= c *\
    \ BASE, res[i + j + 1] += c;  // carry.\n            }\n        }\n        while(!res.empty()\
    \ and res.back() == 0) res.pop_back();\n        return res;\n    }\n    static\
    \ std::pair<std::vector<int64_t>, std::deque<int64_t> > division(const std::vector<int64_t>\
    \ &lhs, ssize_t n, const std::vector<int64_t> &rhs, ssize_t m) {\n        assert(0\
    \ < m and m <= n);\n        std::vector<int64_t> quotient(n - m + 1);\n      \
    \  std::deque<int64_t> remain(lhs.cend() - m, lhs.cend());\n        auto bisearch\
    \ = [&remain, &rhs, m]() -> int64_t {\n            auto compare = [](const std::deque<int64_t>\
    \ &remain, std::vector<int64_t> rhs, ssize_t m, int64_t d) -> int {\n        \
    \        for(ssize_t i = 0; i < m; ++i) rhs[i] *= d;\n                for(ssize_t\
    \ i = 0; i < m - 1; ++i) {\n                    int64_t c = rhs[i] / BASE;\n \
    \                   rhs[i] -= c * BASE, rhs[i + 1] += c;\n                }\n\
    \                for(ssize_t i = m - 1; i >= 0; --i) {\n                    if(remain[i]\
    \ == rhs[i]) continue;\n                    return (remain[i] < rhs[i] ? -1 :\
    \ 1);\n                }\n                return 0;\n            };\n        \
    \    int64_t ok = 0, ng = BASE;\n            while(ng - ok > 1) {\n          \
    \      int64_t mid = ok + (ng - ok) / 2;\n                (compare(remain, rhs,\
    \ m, mid) >= 0 ? ok : ng) = mid;\n            }\n            return ok;\n    \
    \    };\n        for(ssize_t i = n - m; i >= 0; --i) {\n            quotient[i]\
    \ = bisearch();\n            for(ssize_t j = 0; j < m; ++j) {\n              \
    \  remain[j] -= quotient[i] * rhs[j];\n                if(j == m - 1) break;\n\
    \                int64_t c = (-remain[j] + BASE - 1) / BASE;\n               \
    \ remain[j] += c * BASE, remain[j + 1] -= c;  // carry.\n            }\n     \
    \       if(i == 0) break;\n            remain.push_front(lhs[i - 1]);\n      \
    \      remain[m - 1] += remain[m] * BASE;\n            remain.pop_back();\n  \
    \      }\n        if(quotient.back() == 0) quotient.pop_back();\n        while(!remain.empty()\
    \ and remain.back() == 0) remain.pop_back();\n        return {quotient, remain};\n\
    \    }\n    void normalize(std::string_view sv, size_t n) {\n        assert(n\
    \ > 0);\n        if(sv[0] == '+') {\n            normalize_without_sign(sv.substr(1),\
    \ n - 1);\n        } else if(sv[0] == '-') {\n            normalize_without_sign(sv.substr(1),\
    \ n - 1);\n            negation();\n        } else {\n            normalize_without_sign(sv,\
    \ n);\n        }\n    }\n    void normalize_without_sign(std::string_view sv,\
    \ size_t n) {\n        if(sv == \"0\") {\n            zeroize();\n           \
    \ return;\n        }\n        size_t m = (n + BASE_DIGIT - 1) / BASE_DIGIT;\n\
    \        m_words.assign(m, 0);\n        auto iter = sv.crbegin();\n        for(size_t\
    \ i = 0; i < m; ++i) {\n            int64_t d = 1;\n            for(size_t j =\
    \ 0; j < BASE_DIGIT; ++j) {\n                if(iter >= sv.crend()) break;\n \
    \               m_words[i] += (*iter - '0') * d;\n                iter++, d *=\
    \ 10;\n            }\n        }\n        while(!m_words.empty() and m_words.back()\
    \ == 0) m_words.pop_back();\n        m_sign = (m_words.empty() ? 0 : 1);\n   \
    \ }\n\npublic:\n    Bigint() : m_sign(0) {};\n    Bigint(int64_t n) : m_words({n}),\
    \ m_sign(1) {\n        if(n == 0) {\n            zeroize();\n            return;\n\
    \        }\n        if(n < 0) m_words[0] *= -1, m_sign = -1;\n        while(m_words.back()\
    \ >= BASE) {\n            int64_t c = m_words.back() / BASE;\n            m_words.back()\
    \ -= c * BASE;\n            m_words.push_back(c);  // carry.\n        }\n    }\n\
    \    Bigint(const char *c) : Bigint(std::string_view(c)) {}\n    Bigint(std::string_view\
    \ s) {\n        std::stringstream ss;\n        ss << s;\n        ss >> *this;\n\
    \    }\n\n    Bigint operator+() const { return Bigint(*this); }\n    Bigint operator-()\
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
    \ &operator/=(const Bigint &rhs) { return *this = (*this) / rhs; }\n    Bigint\
    \ &operator%=(const Bigint &rhs) {\n        assert(!rhs.is_zero());\n        int\
    \ cmp = compare(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n \
    \       if(cmp < 0) return *this;\n        if(cmp == 0) {\n            zeroize();\n\
    \            return *this;\n        }\n        auto &&remain = division(m_words,\
    \ m_words.size(), rhs.m_words, rhs.m_words.size()).second;\n        if(remain.empty())\
    \ zeroize();\n        else m_words.assign(remain.cbegin(), remain.cend());\n \
    \       return *this;\n    }\n\n    friend bool operator==(const Bigint &lhs,\
    \ const Bigint &rhs) { return lhs.sign() == rhs.sign() and lhs.m_words == rhs.m_words;\
    \ }\n    friend bool operator!=(const Bigint &lhs, const Bigint &rhs) { return\
    \ !(lhs == rhs); }\n    friend int operator<=>(const Bigint &lhs, const Bigint\
    \ &rhs) { return compare(lhs, rhs); }\n    friend Bigint operator+(const Bigint\
    \ &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs; }\n    friend Bigint operator-(const\
    \ Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) -= rhs; }\n    friend Bigint\
    \ operator*(const Bigint &lhs, const Bigint &rhs) {\n        if(lhs.is_zero()\
    \ or rhs.is_zero()) return zero();\n        return Bigint(multiplication(lhs.m_words,\
    \ lhs.m_words.size(), rhs.m_words, rhs.m_words.size()), lhs.sign() * rhs.sign());\n\
    \    }\n    friend Bigint operator/(const Bigint &lhs, const Bigint &rhs) {\n\
    \        assert(!rhs.is_zero());\n        int cmp = compare(lhs.m_words, lhs.m_words.size(),\
    \ rhs.m_words, rhs.m_words.size());\n        if(cmp < 0) return zero();\n    \
    \    if(cmp == 0) return Bigint({1}, lhs.sign() * rhs.sign());\n        return\
    \ Bigint(division(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()).first,\
    \ lhs.sign() * rhs.sign());\n    }\n    friend Bigint operator%(const Bigint &lhs,\
    \ const Bigint &rhs) { return Bigint(lhs) %= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Bigint &rhs) {\n        std::string s;\n        is >> s;\n        assert(validate(s));\n\
    \        rhs.normalize(s, s.size());\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Bigint &rhs) {\n        if(rhs.is_zero())\
    \ return os << 0;\n        os << (rhs.sign() < 0 ? \"-\" : \"\") << rhs.m_words.back();\n\
    \        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend();\
    \ ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0') << *iter;\n       \
    \ return os;\n    }\n\n    static Bigint zero() { return Bigint({}, 0); }\n  \
    \  static Bigint one() { return Bigint({1}, 1); }\n    bool is_zero() const {\
    \ return sign() == 0; }\n    bool is_minus() const { return sign() < 0; }\n  \
    \  Bigint abs() const { return Bigint(m_words, std::abs(sign())); }\n    std::pair<Bigint,\
    \ Bigint> divide(const Bigint &a) const {\n        assert(!a.is_zero());\n   \
    \     int cmp = compare(m_words, m_words.size(), a.m_words, a.m_words.size());\n\
    \        if(cmp < 0) return {zero(), *this};\n        if(cmp == 0) return {Bigint({1},\
    \ sign() * a.sign()), zero()};\n        auto &&[quotient, remain] = division(m_words,\
    \ m_words.size(), a.m_words, a.m_words.size());\n        return {Bigint(std::move(quotient),\
    \ sign() * a.sign()), Bigint(std::vector<int64_t>(remain.cbegin(), remain.cend()),\
    \ (remain.empty() ? 0 : sign()))};\n    }\n    Bigint pow(long long k) const {\n\
    \        assert(k >= 0);\n        Bigint res = 1, mul = *this;\n        while(k\
    \ > 0) {\n            if(k & 1LL) res *= mul;\n            mul *= mul;\n     \
    \       k >>= 1;\n        }\n        return res;\n    }\n    void zeroize() {\n\
    \        m_words.clear();\n        m_sign = 0;\n    }\n    void negation() { m_sign\
    \ *= -1; }\n    int sign() const { return m_sign; }\n    const std::vector<int64_t>\
    \ &words() const { return m_words; }\n    std::string to_string() const {\n  \
    \      std::ostringstream oss;\n        oss << *this;\n        return oss.str();\n\
    \    }\n\n    friend Bigint abs(const Bigint &a) { return a.abs(); }\n    friend\
    \ Bigint pow(Bigint a, long long k) { return a.pow(k); }\n};\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"test/aoj-NTL_2_A-bigint.test.cpp\"\n\nint main() {\n\
    \    algorithm::Bigint a, b;\n    std::cin >> a >> b;\n\n    auto ans = a + b;\n\
    \    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/2/NTL_2_A\"\
    \n\n#include <iostream>\n\n#include \"../lib/Math/NumberTheory/bigint.hpp\"\n\n\
    int main() {\n    algorithm::Bigint a, b;\n    std::cin >> a >> b;\n\n    auto\
    \ ans = a + b;\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - lib/Math/NumberTheory/bigint.hpp
  isVerificationFile: true
  path: test/aoj-NTL_2_A-bigint.test.cpp
  requiredBy: []
  timestamp: '2025-03-07 02:10:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_2_A-bigint.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_2_A-bigint.test.cpp
- /verify/test/aoj-NTL_2_A-bigint.test.cpp.html
title: test/aoj-NTL_2_A-bigint.test.cpp
---
