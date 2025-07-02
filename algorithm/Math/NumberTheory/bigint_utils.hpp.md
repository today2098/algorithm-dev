---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algorithm/Math/NumberTheory/bigint.hpp
    title: algorithm/Math/NumberTheory/bigint.hpp
  - icon: ':x:'
    path: algorithm/Math/NumberTheory/binary_bigint.hpp
    title: algorithm/Math/NumberTheory/binary_bigint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/bigint_utils.hpp\"\n\n\n\n#line\
    \ 1 \"algorithm/Math/NumberTheory/bigint.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <iomanip>\n#include\
    \ <sstream>\n#include <string>\n#include <string_view>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u591A\u500D\u9577\u6574\u6570\uFF0E\
    \nclass Bigint {\n    static constexpr int32_t BASE = 1'000'000'000;\n    static\
    \ constexpr size_t BASE_DIGIT = 9;\n\n    std::vector<int32_t> m_words;\n    bool\
    \ m_neg;\n\n    explicit Bigint(const std::vector<int32_t> &words, bool neg) :\
    \ m_words(words), m_neg(neg) {}\n    explicit Bigint(std::vector<int32_t> &&words,\
    \ bool neg) : m_words(std::move(words)), m_neg(neg) {}\n\n    static constexpr\
    \ bool isdigit(char c) { return '0' <= c and c <= '9'; }\n    static constexpr\
    \ bool validate(std::string_view sv, size_t n) {\n        if(n == 0) return false;\n\
    \        if(sv[0] == '+' or sv[0] == '-') return validate_unsigned(sv.substr(1),\
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
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/NumberTheory/binary_bigint.hpp\"\
    \n\n\n\n#line 7 \"algorithm/Math/NumberTheory/binary_bigint.hpp\"\n#include <deque>\n\
    #line 9 \"algorithm/Math/NumberTheory/binary_bigint.hpp\"\n#include <iostream>\n\
    #line 14 \"algorithm/Math/NumberTheory/binary_bigint.hpp\"\n\nnamespace algorithm\
    \ {\n\nclass BinaryBigint {\n    static constexpr uint64_t BASE = 0x0000000100000000ULL;\n\
    \    static constexpr size_t BASE_DIGIT = 32;\n    static constexpr uint32_t SIGNBIT[2]\
    \ = {0x00000000U, 0xffffffffU};\n\n    std::deque<uint32_t> m_words;\n    uint32_t\
    \ m_signbit;\n\n    explicit BinaryBigint(const std::deque<uint32_t> &words, uint32_t\
    \ signbit) : m_words(words), m_signbit(signbit) {}\n    explicit BinaryBigint(std::deque<uint32_t>\
    \ &&words, uint32_t signbit) : m_words(std::move(words)), m_signbit(signbit) {}\n\
    \n    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }\n\
    \    static constexpr bool isupper(char c) { return 'A' <= c and c <= 'F'; }\n\
    \    static constexpr bool islower(char c) { return 'a' <= c and c <= 'f'; }\n\
    \    static constexpr uint32_t ctoi(char c) {\n        if(isdigit(c)) return c\
    \ - '0';\n        if(isupper(c)) return 10 + (c - 'A');\n        return 10 + (c\
    \ - 'a');\n    }\n    static constexpr bool validate(std::string_view sv, size_t\
    \ n) {\n        if(n == 0) return false;\n        if(sv[0] == '+' or sv[0] ==\
    \ '-') return validate_unsigned(sv.substr(1), n - 1);\n        return validate_unsigned(sv,\
    \ n);\n    }\n    static constexpr bool validate_unsigned(std::string_view sv,\
    \ size_t n) {\n        if(n == 0) return false;\n        return std::find_if_not(sv.cbegin(),\
    \ sv.cend(), [](char c) -> bool { return isdigit(c) or isupper(c) or islower(c);\
    \ }) == sv.cend();\n    }\n    static int compare(const BinaryBigint &lhs, const\
    \ BinaryBigint &rhs) { return compare(lhs.m_words, lhs.m_words.size(), lhs.m_signbit,\
    \ rhs.m_words, rhs.m_words.size(), rhs.m_signbit); }\n    static int compare(const\
    \ std::deque<uint32_t> &lhs, ssize_t n, uint32_t lsb, const std::deque<uint32_t>\
    \ &rhs, ssize_t m, uint32_t rsb) {\n        if(lsb ^ rsb) return (lsb ? -1 : 1);\n\
    \        if(n < m) return (lsb ? 1 : -1);\n        if(n > m) return (lsb ? -1\
    \ : 1);\n        for(ssize_t i = n - 1; i >= 0; --i) {\n            if(lhs[i]\
    \ == rhs[i]) continue;\n            if(lhs[i] < rhs[i]) return -1;\n         \
    \   return 1;\n        }\n        return 0;\n    }\n    static uint32_t store(uint32_t\
    \ &word, uint64_t val) {\n        word = val;\n        return val >> BASE_DIGIT;\
    \  // return carry.\n    }\n    static size_t shrink(std::deque<uint32_t> &words,\
    \ uint32_t signbit) {\n        while(!words.empty() and words.back() == signbit)\
    \ words.pop_back();\n        return words.size();\n    }\n    static size_t zeroisation(std::deque<uint32_t>\
    \ &words, uint32_t &signbit) {\n        words.clear(), signbit = SIGNBIT[0];\n\
    \        return 0;\n    }\n    static size_t negation(std::deque<uint32_t> &words,\
    \ uint32_t &signbit) {\n        words.push_back(signbit);\n        uint32_t ncarry\
    \ = 1;\n        for(uint32_t &word : words) ncarry = store(word, (uint64_t)~word\
    \ + ncarry);\n        signbit = ~signbit + ncarry;\n        return shrink(words,\
    \ signbit);\n    }\n    static uint32_t bitwise_not(std::deque<uint32_t> &words,\
    \ uint32_t &signbit) {\n        for(uint32_t &word : words) word = ~word;\n  \
    \      signbit = ~signbit;\n        return words.size();\n    }\n    static void\
    \ addition(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t>\
    \ &rhs, size_t m, uint32_t rsb) {\n        n = std::max(n, m) + 1;\n        lhs.resize(n,\
    \ lsb);\n        uint32_t carry = 0;\n        for(size_t i = 0; i < m; ++i) carry\
    \ = store(lhs[i], (uint64_t)lhs[i] + rhs[i] + carry);\n        for(size_t i =\
    \ m; i < n and rsb + carry; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + rsb\
    \ + carry);\n        lsb = lsb + rsb + carry;\n        shrink(lhs, lsb);\n   \
    \ }\n    static void subtraction(std::deque<uint32_t> &lhs, size_t n, uint32_t\
    \ &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {\n        n\
    \ = std::max(n, m) + 1;\n        lhs.resize(n, lsb);\n        uint32_t ncarry\
    \ = 1;\n        for(size_t i = 0; i < m; ++i) ncarry = store(lhs[i], (uint64_t)lhs[i]\
    \ + ~rhs[i] + ncarry);\n        for(size_t i = m; i < n and ~rsb + ncarry; ++i)\
    \ ncarry = store(lhs[i], (uint64_t)lhs[i] + ~rsb + ncarry);\n        lsb = lsb\
    \ + ~rsb + ncarry;\n        shrink(lhs, lsb);\n    }\n    static std::pair<std::deque<uint32_t>,\
    \ uint32_t> multiplication(const std::deque<uint32_t> &lhs, size_t n, uint32_t\
    \ lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {\n        std::deque<uint32_t>\
    \ words(n + m, 0);\n        uint32_t signbit = lsb ^ rsb;\n        for(size_t\
    \ j = 0; j < m; ++j) {\n            if(!rhs[j]) continue;\n            uint32_t\
    \ carry = 0;\n            for(size_t i = 0; i < n; ++i) carry = store(words[i\
    \ + j], words[i + j] + (uint64_t)lhs[i] * rhs[j] + carry);\n            words[j\
    \ + n] = carry;\n        }\n        if(rsb) {\n            uint32_t ncarry = 1;\n\
    \            for(size_t i = 0; i < n; ++i) ncarry = store(words[i + m], (uint64_t)words[i\
    \ + m] + ~lhs[i] + ncarry);\n        }\n        if(lsb) {\n            uint32_t\
    \ ncarry = 1;\n            for(size_t j = 0; j < m; ++j) ncarry = store(words[j\
    \ + n], (uint64_t)words[j + n] + ~rhs[j] + ncarry);\n        }\n        shrink(words,\
    \ signbit);\n        return {words, signbit};\n    }\n    static std::pair<std::deque<uint32_t>,\
    \ uint32_t> division(std::deque<uint32_t> &lhs, ssize_t n, uint32_t &lsb, const\
    \ std::deque<uint32_t> &rhs, ssize_t m, uint32_t rsb) {\n        if(m == 0) {\n\
    \            assert(rsb != SIGNBIT[0]);\n            auto words = lhs;\n     \
    \       uint32_t signbit = lsb;\n            negation(words, signbit), zeroisation(lhs,\
    \ lsb);\n            return {words, signbit};\n        }\n        if(lsb ^ rsb)\
    \ {\n            n = negation(lhs, lsb);\n            auto &&[words, signbit]\
    \ = division(lhs, n, lsb, rhs, m, rsb);\n            negation(words, signbit),\
    \ negation(lhs, lsb);\n            return {words, signbit};\n        }\n     \
    \   std::deque<uint32_t> words;\n        uint32_t signbit = SIGNBIT[0];\n    \
    \    lhs.push_back(lsb), ++n;\n        auto bisearch = [&](ssize_t offset) ->\
    \ uint32_t {\n            auto eval = [&](uint32_t d) -> bool {\n            \
    \    uint32_t tmp;\n                uint32_t carry = 0, ncarry = 1;\n        \
    \        for(ssize_t i = 0; i < m; ++i) {\n                    carry = store(tmp,\
    \ (uint64_t)rhs[i] * d + carry);\n                    ncarry = store(tmp, (uint64_t)lhs[i\
    \ + offset] + ~tmp + ncarry);\n                }\n                carry = store(tmp,\
    \ (uint64_t)rsb * d + carry);\n                ncarry = store(tmp, (uint64_t)lhs[m\
    \ + offset] + ~tmp + ncarry);\n                uint32_t last = lsb + ~(rsb * d\
    \ + carry) + ncarry;\n                return last == lsb;\n            };\n  \
    \          uint64_t ok = 0, ng = BASE;\n            while(ng - ok > 1) {\n   \
    \             uint64_t mid = ok + (ng - ok) / 2;\n                (eval(mid) ?\
    \ ok : ng) = mid;\n            }\n            return ok;\n        };\n       \
    \ auto sub = [&](ssize_t offset, uint32_t d) -> void {\n            uint32_t carry\
    \ = 0, ncarry = 1;\n            for(ssize_t i = 0; i < m; ++i) {\n           \
    \     uint32_t tmp;\n                carry = store(tmp, (uint64_t)rhs[i] * d +\
    \ carry);\n                ncarry = store(lhs[i + offset], (uint64_t)lhs[i + offset]\
    \ + ~tmp + ncarry);\n            }\n            lhs.pop_back();\n        };\n\
    \        for(ssize_t i = n - m - 1; i >= 0; --i) {\n            uint32_t d = bisearch(i);\n\
    \            words.push_front(d);\n            sub(i, d);\n        }\n       \
    \ shrink(words, signbit), n = shrink(lhs, lsb);\n        if(lsb and compare(lhs,\
    \ n, lsb, rhs, m, rsb) == 0) addition(words, words.size(), signbit, {1}, 1, SIGNBIT[0]),\
    \ zeroisation(lhs, lsb);\n        return {words, signbit};\n    }\n    static\
    \ void shift_left(std::deque<uint32_t> &words, size_t n, uint32_t signbit, size_t\
    \ k) {\n        size_t t = k / BASE_DIGIT;\n        k -= 32ULL * t;\n        uint32_t\
    \ carry = 0;\n        for(size_t i = 0; i < n; ++i) {\n            uint32_t word\
    \ = words[i];\n            words[i] = word << k | carry;\n            carry =\
    \ word >> (BASE_DIGIT - k);\n        }\n        words.push_back(signbit << k |\
    \ carry);\n        for(size_t i = 0; i < t; ++i) words.push_front(SIGNBIT[0]);\n\
    \        shrink(words, signbit);\n    }\n    static void shift_right(std::deque<uint32_t>\
    \ &words, size_t n, uint32_t signbit, size_t k) {\n        if(k >= 32ULL * n)\
    \ {\n            words.clear();\n            return;\n        }\n        size_t\
    \ t = k / BASE_DIGIT;\n        for(size_t i = 0; i < t; ++i) words.pop_front();\n\
    \        n -= t, k -= 32ULL * t;\n        for(size_t i = 0; i < n - 1; ++i) words[i]\
    \ = words[i + 1] << (BASE_DIGIT - k) | words[i] >> k;\n        words[n - 1] =\
    \ signbit << (BASE_DIGIT - k) | words[n - 1] >> k;\n        shrink(words, signbit);\n\
    \    }\n    static void bitwise_and(std::deque<uint32_t> &lhs, size_t n, uint32_t\
    \ &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {\n        n\
    \ = std::max(n, m);\n        lhs.resize(n, lsb);\n        for(size_t i = 0; i\
    \ < m; ++i) lhs[i] &= rhs[i];\n        for(size_t i = m; i < n; ++i) lhs[i] &=\
    \ rsb;\n        lsb &= rsb;\n        shrink(lhs, lsb);\n    }\n    static void\
    \ bitwise_or(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t>\
    \ &rhs, size_t m, uint32_t rsb) {\n        n = std::max(n, m);\n        lhs.resize(n,\
    \ lsb);\n        for(size_t i = 0; i < m; ++i) lhs[i] |= rhs[i];\n        for(size_t\
    \ i = m; i < n; ++i) lhs[i] |= rsb;\n        lsb |= rsb;\n        shrink(lhs,\
    \ lsb);\n    }\n    static void bitwise_xor(std::deque<uint32_t> &lhs, size_t\
    \ n, uint32_t &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {\n\
    \        n = std::max(n, m);\n        lhs.resize(n, lsb);\n        for(size_t\
    \ i = 0; i < m; ++i) lhs[i] ^= rhs[i];\n        for(size_t i = m; i < n; ++i)\
    \ lhs[i] ^= rsb;\n        lsb ^= rsb;\n        shrink(lhs, lsb);\n    }\n    static\
    \ bool bitwise_test(const std::deque<uint32_t> &words, size_t n, uint32_t signbit,\
    \ size_t pos) {\n        size_t t = pos / BASE_DIGIT;\n        pos -= BASE_DIGIT\
    \ * t;\n        if(t < n) return words[t] >> pos & 1U;\n        return signbit;\n\
    \    }\n    static void bitwise_set(std::deque<uint32_t> &words, size_t n, uint32_t\
    \ signbit, size_t pos) {\n        size_t t = pos / BASE_DIGIT;\n        pos -=\
    \ BASE_DIGIT * t;\n        if(t < n) {\n            words[t] |= 1U << pos;\n \
    \           shrink(words, signbit);\n            return;\n        }\n        if(signbit)\
    \ return;\n        words.resize(t + 1, SIGNBIT[0]);\n        words[t] |= 1U <<\
    \ pos;\n    }\n    static void bitwise_reset(std::deque<uint32_t> &words, size_t\
    \ n, uint32_t signbit, size_t pos) {\n        size_t t = pos / BASE_DIGIT;\n \
    \       pos -= BASE_DIGIT * t;\n        if(t < n) {\n            words[t] &= ~(1U\
    \ << pos);\n            shrink(words, signbit);\n            return;\n       \
    \ }\n        if(!signbit) return;\n        words.resize(t + 1, SIGNBIT[1]);\n\
    \        words[t] &= ~(1U << pos);\n    }\n    void normalize(std::string_view\
    \ sv, size_t n) {\n        assert(n > 0);\n        if(sv[0] == '+') {\n      \
    \      normalize_unsigned(sv.substr(1), n - 1);\n        } else if(sv[0] == '-')\
    \ {\n            normalize_unsigned(sv.substr(1), n - 1);\n            negation(m_words,\
    \ m_signbit);\n        } else {\n            normalize_unsigned(sv, n);\n    \
    \    }\n    }\n    void normalize_unsigned(std::string_view sv, size_t n) {\n\
    \        size_t m = (n + 7) / 8;\n        m_words.assign(m, SIGNBIT[0]);\n   \
    \     auto iter = sv.crbegin();\n        for(size_t i = 0; i < m; ++i) {\n   \
    \         for(size_t j = 0; j < BASE_DIGIT and iter < sv.crend(); j += 4, ++iter)\
    \ m_words[i] |= ctoi(*iter) << j;\n        }\n        shrink(m_words, SIGNBIT[0]);\n\
    \        m_signbit = SIGNBIT[0];\n    }\n\npublic:\n    BinaryBigint() : m_words(),\
    \ m_signbit(SIGNBIT[0]) {}\n    BinaryBigint(int64_t n) : m_words({(uint32_t)n,\
    \ uint32_t(n >> BASE_DIGIT)}), m_signbit(SIGNBIT[n < 0]) {\n        shrink(m_words,\
    \ m_signbit);\n    }\n    BinaryBigint(const char *c) : BinaryBigint(std::string_view(c))\
    \ {}\n    BinaryBigint(std::string_view sv) {\n        std::stringstream ss;\n\
    \        ss << sv;\n        ss >> *this;\n    }\n\n    explicit operator bool()\
    \ const { return !is_zero(); }\n    BinaryBigint operator+() const { return BinaryBigint(*this);\
    \ }\n    BinaryBigint operator-() const {\n        BinaryBigint res = *this;\n\
    \        return res.negate();\n    }\n    BinaryBigint operator~() const {\n \
    \       BinaryBigint res = *this;\n        return res.bitwise_not();\n    }\n\
    \    BinaryBigint &operator++() {\n        addition(m_words, m_words.size(), m_signbit,\
    \ {1}, 1, SIGNBIT[0]);\n        return *this;\n    }\n    BinaryBigint &operator--()\
    \ {\n        addition(m_words, m_words.size(), m_signbit, {}, 0, SIGNBIT[1]);\n\
    \        return *this;\n    }\n    BinaryBigint operator++(int) {\n        BinaryBigint\
    \ res = *this;\n        ++(*this);\n        return res;\n    }\n    BinaryBigint\
    \ operator--(int) {\n        BinaryBigint res = *this;\n        --(*this);\n \
    \       return res;\n    }\n    BinaryBigint &operator+=(const BinaryBigint &rhs)\
    \ {\n        addition(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(),\
    \ rhs.m_signbit);\n        return *this;\n    }\n    BinaryBigint &operator-=(const\
    \ BinaryBigint &rhs) {\n        subtraction(m_words, m_words.size(), m_signbit,\
    \ rhs.m_words, rhs.m_words.size(), rhs.m_signbit);\n        return *this;\n  \
    \  }\n    BinaryBigint &operator*=(const BinaryBigint &rhs) { return *this = (*this)\
    \ * rhs; }\n    BinaryBigint &operator/=(const BinaryBigint &rhs) {\n        assert(!rhs.is_zero());\n\
    \        auto &&[words, signbit] = division(m_words, m_words.size(), m_signbit,\
    \ rhs.m_words, rhs.m_words.size(), rhs.m_signbit);\n        m_words = std::move(words),\
    \ m_signbit = signbit;\n        return *this;\n    }\n    BinaryBigint &operator%=(const\
    \ BinaryBigint &rhs) {\n        assert(!rhs.is_zero());\n        division(m_words,\
    \ m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);\n\
    \        return *this;\n    }\n    BinaryBigint &operator<<=(size_t k) {\n   \
    \     shift_left(m_words, m_words.size(), m_signbit, k);\n        return *this;\n\
    \    }\n    BinaryBigint &operator>>=(size_t k) {\n        shift_right(m_words,\
    \ m_words.size(), m_signbit, k);\n        return *this;\n    }\n    BinaryBigint\
    \ &operator&=(const BinaryBigint &rhs) {\n        bitwise_and(m_words, m_words.size(),\
    \ m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);\n        return\
    \ *this;\n    }\n    BinaryBigint &operator|=(const BinaryBigint &rhs) {\n   \
    \     bitwise_or(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(),\
    \ rhs.m_signbit);\n        return *this;\n    }\n    BinaryBigint &operator^=(const\
    \ BinaryBigint &rhs) {\n        bitwise_xor(m_words, m_words.size(), m_signbit,\
    \ rhs.m_words, rhs.m_words.size(), rhs.m_signbit);\n        return *this;\n  \
    \  }\n\n    friend bool operator==(const BinaryBigint &lhs, const BinaryBigint\
    \ &rhs) { return lhs.m_words == rhs.m_words and lhs.m_signbit == rhs.m_signbit;\
    \ }\n    friend int operator<=>(const BinaryBigint &lhs, const BinaryBigint &rhs)\
    \ { return compare(lhs, rhs); }\n    friend BinaryBigint operator+(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) += rhs; }\n    friend\
    \ BinaryBigint operator-(const BinaryBigint &lhs, const BinaryBigint &rhs) { return\
    \ BinaryBigint(lhs) -= rhs; }\n    friend BinaryBigint operator*(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) {\n        if(lhs.is_zero() or rhs.is_zero())\
    \ return BinaryBigint();\n        auto &&[words, signbit] = multiplication(lhs.m_words,\
    \ lhs.m_words.size(), lhs.m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);\n\
    \        return BinaryBigint(std::move(words), signbit);\n    }\n    friend BinaryBigint\
    \ operator/(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs)\
    \ /= rhs; }\n    friend BinaryBigint operator%(const BinaryBigint &lhs, const\
    \ BinaryBigint &rhs) { return BinaryBigint(lhs) %= rhs; }\n    friend BinaryBigint\
    \ operator<<(const BinaryBigint &lhs, size_t k) { return BinaryBigint(lhs) <<=\
    \ k; }\n    friend BinaryBigint operator>>(const BinaryBigint &lhs, size_t k)\
    \ { return BinaryBigint(lhs) >>= k; }\n    friend BinaryBigint operator&(const\
    \ BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) &= rhs;\
    \ }\n    friend BinaryBigint operator|(const BinaryBigint &lhs, const BinaryBigint\
    \ &rhs) { return BinaryBigint(lhs) |= rhs; }\n    friend BinaryBigint operator^(const\
    \ BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) ^= rhs;\
    \ }\n    friend std::istream &operator>>(std::istream &is, BinaryBigint &rhs)\
    \ {\n        std::string s;\n        is >> s;\n        assert(validate(s, s.size()));\n\
    \        rhs.normalize(s, s.size());\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const BinaryBigint &rhs) {\n        if(rhs.is_negative())\
    \ return os << \"-\" << -rhs;\n        if(rhs.is_zero()) return os << 0;\n   \
    \     auto old = os.setf(std::ios_base::hex, std::ios_base::basefield);  // 16\u9032\
    \u6570\u8868\u793A\uFF0E\n        auto iter = rhs.m_words.crbegin();\n       \
    \ os << *iter++;\n        for(; iter < rhs.m_words.crend(); ++iter) os << std::setw(8)\
    \ << std::setfill('0') << *iter;\n        os.flags(old);\n        return os;\n\
    \    }\n\n    static constexpr uint64_t base() { return BASE; }\n    static constexpr\
    \ size_t base_digit() { return BASE_DIGIT; }\n    const std::deque<uint32_t> &words()\
    \ const { return m_words; }\n    uint32_t signbit() const { return m_signbit;\
    \ }\n    bool is_zero() const { return m_words.empty() and !m_signbit; }\n   \
    \ bool is_negative() const { return m_signbit; }\n    int sign() const {\n   \
    \     if(m_signbit) return -1;\n        return (m_words.empty() ? 0 : 1);\n  \
    \  }\n    BinaryBigint abs() const { return (is_negative() ? -(*this) : BinaryBigint(*this));\
    \ }\n    std::pair<BinaryBigint, BinaryBigint> divide(const BinaryBigint &divisor)\
    \ const {\n        assert(!divisor.is_zero());\n        auto remain = *this;\n\
    \        auto &&[words, signbit] = division(remain.m_words, remain.m_words.size(),\
    \ remain.m_signbit, divisor.m_words, divisor.m_words.size(), divisor.m_signbit);\n\
    \        return {BinaryBigint(std::move(words), signbit), std::move(remain)};\n\
    \    }\n    BinaryBigint &zeroise() {\n        zeroisation(m_words, m_signbit);\n\
    \        return *this;\n    }\n    BinaryBigint &negate() {\n        negation(m_words,\
    \ m_signbit);\n        return *this;\n    }\n    BinaryBigint &bitwise_not() {\n\
    \        bitwise_not(m_words, m_signbit);\n        return *this;\n    }\n    bool\
    \ test(size_t k) const { return bitwise_test(m_words, m_words.size(), m_signbit,\
    \ k); }\n    BinaryBigint &set(size_t k, bool val = true) {\n        if(!val)\
    \ return reset(k);\n        bitwise_set(m_words, m_words.size(), m_signbit, k);\n\
    \        return *this;\n    }\n    BinaryBigint &reset(size_t k) {\n        bitwise_reset(m_words,\
    \ m_words.size(), m_signbit, k);\n        return *this;\n    }\n    std::string\
    \ to_string() const {\n        std::ostringstream oss;\n        oss << *this;\n\
    \        return oss.str();\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 6 \"algorithm/Math/NumberTheory/bigint_utils.hpp\"\n\nnamespace algorithm {\n\
    \nBinaryBigint dtoh(const Bigint &a) {\n    BinaryBigint res;\n    for(auto iter\
    \ = a.words().crbegin(); iter < a.words().crend(); ++iter) {\n        res *= Bigint::base();\n\
    \        res += *iter;\n    }\n    if(a.is_negative()) res.negate();\n    return\
    \ res;\n};\n\nBigint htod(const BinaryBigint &a) {\n    if(a.is_negative()) return\
    \ htod(-a).negate();\n    Bigint res;\n    for(auto iter = a.words().crbegin();\
    \ iter < a.words().crend(); ++iter) {\n        res *= BinaryBigint::base();\n\
    \        res += *iter;\n    }\n    return res;\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_BIGINT_UTILS_HPP\n#define ALGORITHM_BIGINT_UTILS_HPP 1\n\
    \n#include \"bigint.hpp\"\n#include \"binary_bigint.hpp\"\n\nnamespace algorithm\
    \ {\n\nBinaryBigint dtoh(const Bigint &a) {\n    BinaryBigint res;\n    for(auto\
    \ iter = a.words().crbegin(); iter < a.words().crend(); ++iter) {\n        res\
    \ *= Bigint::base();\n        res += *iter;\n    }\n    if(a.is_negative()) res.negate();\n\
    \    return res;\n};\n\nBigint htod(const BinaryBigint &a) {\n    if(a.is_negative())\
    \ return htod(-a).negate();\n    Bigint res;\n    for(auto iter = a.words().crbegin();\
    \ iter < a.words().crend(); ++iter) {\n        res *= BinaryBigint::base();\n\
    \        res += *iter;\n    }\n    return res;\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn:
  - algorithm/Math/NumberTheory/bigint.hpp
  - algorithm/Math/NumberTheory/binary_bigint.hpp
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/bigint_utils.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/NumberTheory/bigint_utils.hpp
layout: document
redirect_from:
- /library/algorithm/Math/NumberTheory/bigint_utils.hpp
- /library/algorithm/Math/NumberTheory/bigint_utils.hpp.html
title: algorithm/Math/NumberTheory/bigint_utils.hpp
---
