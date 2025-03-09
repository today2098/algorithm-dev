---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/Math/NumberTheory/binary_bigint.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <deque>\n#include\
    \ <iomanip>\n#include <iterator>\n#include <sstream>\n#include <string>\n#include\
    \ <string_view>\n#include <utility>\n\nnamespace algorithm {\n\nclass BinaryBigint\
    \ {\n    std::deque<uint32_t> m_words;\n\n    explicit BinaryBigint(const std::deque<uint32_t>\
    \ &words) : m_words(words) {}\n\n    static constexpr bool isdigit(char c) { return\
    \ '0' <= c and c <= '9'; }\n    static constexpr bool isupper(char c) { return\
    \ 'A' <= c and c <= 'F'; }\n    static constexpr bool islower(char c) { return\
    \ 'a' <= c and c <= 'f'; }\n    static constexpr uint32_t to_dec(char c) {\n \
    \       if(isdigit(c)) return c - '0';\n        if(isupper(c)) return 10 + (c\
    \ - 'A');\n        return 10 + (c - 'a');\n    }\n    static constexpr bool validate(std::string_view\
    \ sv) {\n        if(sv == \"\") return false;\n        return std::find_if_not(sv.cbegin(),\
    \ sv.cend(), [](char c) -> bool { return isdigit(c) or isupper(c) or islower(c);\
    \ }) == sv.cend();\n    }\n    static uint32_t store(uint32_t &word, uint64_t\
    \ val) {\n        word = val;\n        return val >> 32;  // carry.\n    }\n \
    \   static uint64_t sub_store(uint32_t &word, uint64_t val) {\n        uint64_t\
    \ ncarry = store(word, val);\n        if(ncarry) ncarry |= 0xffffffff00000000ULL;\n\
    \        return ncarry;\n    }\n    static int compare(const BinaryBigint &lhs,\
    \ const BinaryBigint &rhs) { return compare(lhs.m_words, lhs.m_words.size(), rhs.m_words,\
    \ rhs.m_words.size()); }\n    static int compare(const std::deque<uint32_t> &lhs,\
    \ ssize_t n, const std::deque<uint32_t> &rhs, ssize_t m) {\n        if(n < m)\
    \ return -1;\n        if(n > m) return 1;\n        for(ssize_t i = n - 1; i >=\
    \ 0; --i) {\n            if(lhs[i] == rhs[i]) continue;\n            return (lhs[i]\
    \ < rhs[i] ? -1 : 1);\n        }\n        return 0;\n    }\n    static void addition(std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        n = std::max(n,\
    \ m);\n        lhs.resize(n, 0);\n        uint32_t carry = 0;\n        for(size_t\
    \ i = 0; i < m; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + rhs[i] + carry);\n\
    \        for(size_t i = m; i < n and carry; ++i) carry = store(lhs[i], (uint64_t)lhs[i]\
    \ + carry);\n        if(carry) lhs.push_back(carry);\n    }\n    static void subtraction(std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        n = std::max(n,\
    \ m);\n        lhs.resize(n, 0);\n        uint64_t ncarry = 0;\n        for(size_t\
    \ i = 0; i < m; ++i) ncarry = sub_store(lhs[i], (uint64_t)lhs[i] - rhs[i] + ncarry);\n\
    \        for(size_t i = m; i < n and ncarry; ++i) ncarry = sub_store(lhs[i], lhs[i]\
    \ + ncarry);\n        while(!lhs.empty() and !lhs.back()) lhs.pop_back();\n  \
    \  }\n    static std::deque<uint32_t> multiplication(const std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        std::deque<uint32_t>\
    \ res(n + m, 0);\n        for(size_t i = 0; i < n; ++i) {\n            uint32_t\
    \ carry = 0;\n            for(size_t j = 0; j < m; ++j) carry = store(res[i +\
    \ j], res[i + j] + (uint64_t)lhs[i] * rhs[j] + carry);\n            res[i + m]\
    \ = carry;\n        }\n        while(!res.empty() and !res.back()) res.pop_back();\n\
    \        return res;\n    }\n    static std::deque<uint32_t> division(std::deque<uint32_t>\
    \ &lhs, ssize_t n, const std::deque<uint32_t> &rhs, ssize_t m) {\n        assert(m\
    \ > 0);\n        std::deque<uint32_t> res;\n        auto bisearch = [&](ssize_t\
    \ offset) -> uint32_t {\n            if(n - offset < m) return 0;\n          \
    \  auto eval = [&](uint32_t d) -> bool {\n                uint32_t carry = 0;\n\
    \                uint64_t ncarry = 0;\n                for(ssize_t i = 0; i <\
    \ m; ++i) {\n                    uint32_t tmp;\n                    carry = store(tmp,\
    \ (uint64_t)rhs[i] * d + carry);\n                    ncarry = sub_store(tmp,\
    \ (uint64_t)lhs[i + offset] - tmp + ncarry);\n                }\n            \
    \    uint64_t last = (uint64_t)(m + offset < n ? lhs.back() : 0) - carry + ncarry;\n\
    \                return !(last & 0xffffffff00000000ULL);\n            };\n   \
    \         uint64_t ok = 0, ng = (1ULL << 32);\n            while(ng - ok > 1)\
    \ {\n                uint64_t mid = ok + (ng - ok) / 2;\n                (eval(mid)\
    \ ? ok : ng) = mid;\n            }\n            return ok;\n        };\n     \
    \   auto sub = [&](ssize_t offset, uint32_t d) -> void {\n            uint32_t\
    \ carry = 0;\n            uint64_t ncarry = 0;\n            for(ssize_t i = 0;\
    \ i < m; ++i) {\n                uint32_t tmp = 0;\n                carry = store(tmp,\
    \ (uint64_t)rhs[i] * d + carry);\n                ncarry = sub_store(lhs[i + offset],\
    \ (uint64_t)lhs[i + offset] - tmp + ncarry);\n            }\n            if(m\
    \ + offset < n) lhs.pop_back();\n            while(offset < n and !lhs.back())\
    \ lhs.pop_back(), --n;\n        };\n        for(ssize_t i = n - m; i >= 0;) {\n\
    \            uint32_t d = bisearch(i);\n            res.push_front(d);\n     \
    \       sub(i, d);\n            --i;\n            while(!lhs.empty() and !lhs.back())\
    \ lhs.pop_back(), --n, --i;\n        }\n        if(!res.back()) res.pop_back();\n\
    \        return res;\n    }\n    static void shift_left(std::deque<uint32_t> &words,\
    \ size_t n, unsigned long long k) {\n        if(n == 0) return;\n        size_t\
    \ t = k / 32;\n        k -= 32ULL * t;\n        uint32_t carry = 0;\n        for(size_t\
    \ i = 0; i < n; ++i) {\n            uint32_t word = words[i];\n            words[i]\
    \ = word << k | carry;\n            carry = word >> (32 - k);\n        }\n   \
    \     if(carry) words.push_back(carry);\n        for(size_t i = 0; i < t; ++i)\
    \ words.push_front(0);\n    }\n    static void shift_right(std::deque<uint32_t>\
    \ &words, size_t n, unsigned long long k) {\n        if(k >= 32ULL * n) {\n  \
    \          words.clear();\n            return;\n        }\n        size_t t =\
    \ k / 32;\n        for(size_t i = 0; i < t; ++i) words.pop_front();\n        n\
    \ -= t, k -= 32ULL * t;\n        for(size_t i = 0; i < n - 1; ++i) words[i] =\
    \ words[i + 1] << (32 - k) | words[i] >> k;\n        words.back() >>= k;\n   \
    \     if(!words.back()) words.pop_back();\n    }\n    static void bit_and(std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        n = std::min(n,\
    \ m);\n        lhs.resize(n);\n        for(size_t i = 0; i < n; ++i) lhs[i] &=\
    \ rhs[i];\n        while(!lhs.empty() and !lhs.back()) lhs.pop_back();\n    }\n\
    \    static void bit_or(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t>\
    \ &rhs, size_t m) {\n        n = std::max(n, m);\n        lhs.resize(n, 0);\n\
    \        for(size_t i = 0; i < m; ++i) lhs[i] |= rhs[i];\n    }\n    static void\
    \ bit_xor(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs,\
    \ size_t m) {\n        n = std::max(n, m);\n        lhs.resize(n, 0);\n      \
    \  for(size_t i = 0; i < m; ++i) lhs[i] ^= rhs[i];\n        while(!lhs.empty()\
    \ and !lhs.back()) lhs.pop_back();\n    }\n    void normalize(std::string_view\
    \ sv, size_t n) {\n        size_t m = (n + 7) / 8;\n        m_words.assign(m,\
    \ 0);\n        auto iter = sv.crbegin();\n        for(size_t i = 0; i < m; ++i)\
    \ {\n            for(unsigned j = 0; j < 32 and iter < sv.crend(); j += 4, ++iter)\
    \ m_words[i] |= to_dec(*iter) << j;\n        }\n        while(!m_words.empty()\
    \ and !m_words.back()) m_words.pop_back();\n    }\n\npublic:\n    BinaryBigint()\
    \ : m_words() {}\n    BinaryBigint(uint64_t n) : m_words({(uint32_t)n, uint32_t(n\
    \ >> 32)}) {\n        while(!m_words.empty() and !m_words.back()) m_words.pop_back();\n\
    \    }\n    BinaryBigint(const char *c) : BinaryBigint(std::string_view(c)) {}\n\
    \    BinaryBigint(std::string_view sv) {\n        std::stringstream ss;\n    \
    \    ss << sv;\n        ss >> *this;\n    }\n\n    BinaryBigint &operator+=(const\
    \ BinaryBigint &rhs) {\n        if(rhs.is_zero()) return *this;\n        if(is_zero())\
    \ return *this = rhs;\n        addition(m_words, m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n        return *this;\n    }\n    BinaryBigint &operator-=(const\
    \ BinaryBigint &rhs) {\n        // assert(compare(*this, rhs) >= 0);  // lhs<rhs\
    \ \u306E\u3068\u304D\uFF0C\u672A\u5B9A\u7FA9\u52D5\u4F5C\uFF0E\n        if(rhs.is_zero())\
    \ return *this;\n        subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    BinaryBigint &operator*=(const BinaryBigint\
    \ &rhs) { return *this = (*this) * rhs; }\n    BinaryBigint &operator/=(const\
    \ BinaryBigint &rhs) {\n        assert(!rhs.is_zero());\n        m_words = division(m_words,\
    \ m_words.size(), rhs.m_words, rhs.m_words.size());\n        return *this;\n \
    \   }\n    BinaryBigint &operator%=(const BinaryBigint &rhs) {\n        assert(!rhs.is_zero());\n\
    \        division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    BinaryBigint &operator<<=(unsigned long long\
    \ k) {\n        shift_left(m_words, m_words.size(), k);\n        return *this;\n\
    \    }\n    BinaryBigint &operator>>=(unsigned long long k) {\n        shift_right(m_words,\
    \ m_words.size(), k);\n        return *this;\n    }\n    BinaryBigint &operator&=(const\
    \ BinaryBigint &rhs) {\n        bit_and(m_words, m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n        return *this;\n    }\n    BinaryBigint &operator|=(const\
    \ BinaryBigint &rhs) {\n        bit_or(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    BinaryBigint &operator^=(const BinaryBigint\
    \ &rhs) {\n        bit_xor(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n\n    friend bool operator==(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return lhs.m_words == rhs.m_words; }\n    friend\
    \ int operator<=>(const BinaryBigint &lhs, const BinaryBigint &rhs) { return compare(lhs,\
    \ rhs); }\n    friend BinaryBigint operator+(const BinaryBigint &lhs, const BinaryBigint\
    \ &rhs) { return BinaryBigint(lhs) += rhs; }\n    friend BinaryBigint operator-(const\
    \ BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) -= rhs;\
    \ }\n    friend BinaryBigint operator*(const BinaryBigint &lhs, const BinaryBigint\
    \ &rhs) {\n        if(lhs.is_zero() or rhs.is_zero()) return BinaryBigint();\n\
    \        return BinaryBigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words,\
    \ rhs.m_words.size()));\n    }\n    friend BinaryBigint operator/(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) /= rhs; }\n    friend\
    \ BinaryBigint operator%(const BinaryBigint &lhs, const BinaryBigint &rhs) { return\
    \ BinaryBigint(lhs) %= rhs; }\n    friend BinaryBigint operator<<(const BinaryBigint\
    \ &lhs, unsigned long long k) { return BinaryBigint(lhs) <<= k; }\n    friend\
    \ BinaryBigint operator>>(const BinaryBigint &lhs, unsigned long long k) { return\
    \ BinaryBigint(lhs) >>= k; }\n    friend BinaryBigint operator&(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) &= rhs; }\n    friend\
    \ BinaryBigint operator|(const BinaryBigint &lhs, const BinaryBigint &rhs) { return\
    \ BinaryBigint(lhs) |= rhs; }\n    friend BinaryBigint operator^(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) ^= rhs; }\n    friend\
    \ std::istream &operator>>(std::istream &is, BinaryBigint &rhs) {\n        std::string\
    \ s;\n        is >> s;\n        assert(validate(s));\n        rhs.normalize(s,\
    \ s.size());\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryBigint &rhs) {\n        if(rhs.is_zero()) return os << 0;\n\
    \        auto old = os.setf(std::ios_base::hex, std::ios_base::basefield);  //\
    \ 16\u9032\u6570\u8868\u793A\uFF0E\n        os << rhs.m_words.back();\n      \
    \  for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter)\
    \ os << std::setw(8) << std::setfill('0') << *iter;\n        os.flags(old);\n\
    \        return os;\n    }\n\n    bool is_zero() const { return m_words.empty();\
    \ }\n    void zeroize() { m_words.clear(); }\n    std::pair<BinaryBigint, BinaryBigint>\
    \ divide(const BinaryBigint &a) const {\n        assert(!a.is_zero());\n     \
    \   auto remain = m_words;\n        auto &&quotient = division(remain, remain.size(),\
    \ a.m_words, a.m_words.size());\n        return {BinaryBigint(std::move(quotient)),\
    \ BinaryBigint(std::move(remain))};\n    }\n    std::string to_string() const\
    \ {\n        std::ostringstream oss;\n        oss << *this;\n        return oss.str();\n\
    \    }\n    const std::deque<uint32_t> &words() const { return m_words; }\n};\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_BIGINT_HPP\n#define ALGORITHM_BINARY_BIGINT_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include\
    \ <deque>\n#include <iomanip>\n#include <iterator>\n#include <sstream>\n#include\
    \ <string>\n#include <string_view>\n#include <utility>\n\nnamespace algorithm\
    \ {\n\nclass BinaryBigint {\n    std::deque<uint32_t> m_words;\n\n    explicit\
    \ BinaryBigint(const std::deque<uint32_t> &words) : m_words(words) {}\n\n    static\
    \ constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }\n    static\
    \ constexpr bool isupper(char c) { return 'A' <= c and c <= 'F'; }\n    static\
    \ constexpr bool islower(char c) { return 'a' <= c and c <= 'f'; }\n    static\
    \ constexpr uint32_t to_dec(char c) {\n        if(isdigit(c)) return c - '0';\n\
    \        if(isupper(c)) return 10 + (c - 'A');\n        return 10 + (c - 'a');\n\
    \    }\n    static constexpr bool validate(std::string_view sv) {\n        if(sv\
    \ == \"\") return false;\n        return std::find_if_not(sv.cbegin(), sv.cend(),\
    \ [](char c) -> bool { return isdigit(c) or isupper(c) or islower(c); }) == sv.cend();\n\
    \    }\n    static uint32_t store(uint32_t &word, uint64_t val) {\n        word\
    \ = val;\n        return val >> 32;  // carry.\n    }\n    static uint64_t sub_store(uint32_t\
    \ &word, uint64_t val) {\n        uint64_t ncarry = store(word, val);\n      \
    \  if(ncarry) ncarry |= 0xffffffff00000000ULL;\n        return ncarry;\n    }\n\
    \    static int compare(const BinaryBigint &lhs, const BinaryBigint &rhs) { return\
    \ compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()); }\n\
    \    static int compare(const std::deque<uint32_t> &lhs, ssize_t n, const std::deque<uint32_t>\
    \ &rhs, ssize_t m) {\n        if(n < m) return -1;\n        if(n > m) return 1;\n\
    \        for(ssize_t i = n - 1; i >= 0; --i) {\n            if(lhs[i] == rhs[i])\
    \ continue;\n            return (lhs[i] < rhs[i] ? -1 : 1);\n        }\n     \
    \   return 0;\n    }\n    static void addition(std::deque<uint32_t> &lhs, size_t\
    \ n, const std::deque<uint32_t> &rhs, size_t m) {\n        n = std::max(n, m);\n\
    \        lhs.resize(n, 0);\n        uint32_t carry = 0;\n        for(size_t i\
    \ = 0; i < m; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + rhs[i] + carry);\n\
    \        for(size_t i = m; i < n and carry; ++i) carry = store(lhs[i], (uint64_t)lhs[i]\
    \ + carry);\n        if(carry) lhs.push_back(carry);\n    }\n    static void subtraction(std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        n = std::max(n,\
    \ m);\n        lhs.resize(n, 0);\n        uint64_t ncarry = 0;\n        for(size_t\
    \ i = 0; i < m; ++i) ncarry = sub_store(lhs[i], (uint64_t)lhs[i] - rhs[i] + ncarry);\n\
    \        for(size_t i = m; i < n and ncarry; ++i) ncarry = sub_store(lhs[i], lhs[i]\
    \ + ncarry);\n        while(!lhs.empty() and !lhs.back()) lhs.pop_back();\n  \
    \  }\n    static std::deque<uint32_t> multiplication(const std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        std::deque<uint32_t>\
    \ res(n + m, 0);\n        for(size_t i = 0; i < n; ++i) {\n            uint32_t\
    \ carry = 0;\n            for(size_t j = 0; j < m; ++j) carry = store(res[i +\
    \ j], res[i + j] + (uint64_t)lhs[i] * rhs[j] + carry);\n            res[i + m]\
    \ = carry;\n        }\n        while(!res.empty() and !res.back()) res.pop_back();\n\
    \        return res;\n    }\n    static std::deque<uint32_t> division(std::deque<uint32_t>\
    \ &lhs, ssize_t n, const std::deque<uint32_t> &rhs, ssize_t m) {\n        assert(m\
    \ > 0);\n        std::deque<uint32_t> res;\n        auto bisearch = [&](ssize_t\
    \ offset) -> uint32_t {\n            if(n - offset < m) return 0;\n          \
    \  auto eval = [&](uint32_t d) -> bool {\n                uint32_t carry = 0;\n\
    \                uint64_t ncarry = 0;\n                for(ssize_t i = 0; i <\
    \ m; ++i) {\n                    uint32_t tmp;\n                    carry = store(tmp,\
    \ (uint64_t)rhs[i] * d + carry);\n                    ncarry = sub_store(tmp,\
    \ (uint64_t)lhs[i + offset] - tmp + ncarry);\n                }\n            \
    \    uint64_t last = (uint64_t)(m + offset < n ? lhs.back() : 0) - carry + ncarry;\n\
    \                return !(last & 0xffffffff00000000ULL);\n            };\n   \
    \         uint64_t ok = 0, ng = (1ULL << 32);\n            while(ng - ok > 1)\
    \ {\n                uint64_t mid = ok + (ng - ok) / 2;\n                (eval(mid)\
    \ ? ok : ng) = mid;\n            }\n            return ok;\n        };\n     \
    \   auto sub = [&](ssize_t offset, uint32_t d) -> void {\n            uint32_t\
    \ carry = 0;\n            uint64_t ncarry = 0;\n            for(ssize_t i = 0;\
    \ i < m; ++i) {\n                uint32_t tmp = 0;\n                carry = store(tmp,\
    \ (uint64_t)rhs[i] * d + carry);\n                ncarry = sub_store(lhs[i + offset],\
    \ (uint64_t)lhs[i + offset] - tmp + ncarry);\n            }\n            if(m\
    \ + offset < n) lhs.pop_back();\n            while(offset < n and !lhs.back())\
    \ lhs.pop_back(), --n;\n        };\n        for(ssize_t i = n - m; i >= 0;) {\n\
    \            uint32_t d = bisearch(i);\n            res.push_front(d);\n     \
    \       sub(i, d);\n            --i;\n            while(!lhs.empty() and !lhs.back())\
    \ lhs.pop_back(), --n, --i;\n        }\n        if(!res.back()) res.pop_back();\n\
    \        return res;\n    }\n    static void shift_left(std::deque<uint32_t> &words,\
    \ size_t n, unsigned long long k) {\n        if(n == 0) return;\n        size_t\
    \ t = k / 32;\n        k -= 32ULL * t;\n        uint32_t carry = 0;\n        for(size_t\
    \ i = 0; i < n; ++i) {\n            uint32_t word = words[i];\n            words[i]\
    \ = word << k | carry;\n            carry = word >> (32 - k);\n        }\n   \
    \     if(carry) words.push_back(carry);\n        for(size_t i = 0; i < t; ++i)\
    \ words.push_front(0);\n    }\n    static void shift_right(std::deque<uint32_t>\
    \ &words, size_t n, unsigned long long k) {\n        if(k >= 32ULL * n) {\n  \
    \          words.clear();\n            return;\n        }\n        size_t t =\
    \ k / 32;\n        for(size_t i = 0; i < t; ++i) words.pop_front();\n        n\
    \ -= t, k -= 32ULL * t;\n        for(size_t i = 0; i < n - 1; ++i) words[i] =\
    \ words[i + 1] << (32 - k) | words[i] >> k;\n        words.back() >>= k;\n   \
    \     if(!words.back()) words.pop_back();\n    }\n    static void bit_and(std::deque<uint32_t>\
    \ &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {\n        n = std::min(n,\
    \ m);\n        lhs.resize(n);\n        for(size_t i = 0; i < n; ++i) lhs[i] &=\
    \ rhs[i];\n        while(!lhs.empty() and !lhs.back()) lhs.pop_back();\n    }\n\
    \    static void bit_or(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t>\
    \ &rhs, size_t m) {\n        n = std::max(n, m);\n        lhs.resize(n, 0);\n\
    \        for(size_t i = 0; i < m; ++i) lhs[i] |= rhs[i];\n    }\n    static void\
    \ bit_xor(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs,\
    \ size_t m) {\n        n = std::max(n, m);\n        lhs.resize(n, 0);\n      \
    \  for(size_t i = 0; i < m; ++i) lhs[i] ^= rhs[i];\n        while(!lhs.empty()\
    \ and !lhs.back()) lhs.pop_back();\n    }\n    void normalize(std::string_view\
    \ sv, size_t n) {\n        size_t m = (n + 7) / 8;\n        m_words.assign(m,\
    \ 0);\n        auto iter = sv.crbegin();\n        for(size_t i = 0; i < m; ++i)\
    \ {\n            for(unsigned j = 0; j < 32 and iter < sv.crend(); j += 4, ++iter)\
    \ m_words[i] |= to_dec(*iter) << j;\n        }\n        while(!m_words.empty()\
    \ and !m_words.back()) m_words.pop_back();\n    }\n\npublic:\n    BinaryBigint()\
    \ : m_words() {}\n    BinaryBigint(uint64_t n) : m_words({(uint32_t)n, uint32_t(n\
    \ >> 32)}) {\n        while(!m_words.empty() and !m_words.back()) m_words.pop_back();\n\
    \    }\n    BinaryBigint(const char *c) : BinaryBigint(std::string_view(c)) {}\n\
    \    BinaryBigint(std::string_view sv) {\n        std::stringstream ss;\n    \
    \    ss << sv;\n        ss >> *this;\n    }\n\n    BinaryBigint &operator+=(const\
    \ BinaryBigint &rhs) {\n        if(rhs.is_zero()) return *this;\n        if(is_zero())\
    \ return *this = rhs;\n        addition(m_words, m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n        return *this;\n    }\n    BinaryBigint &operator-=(const\
    \ BinaryBigint &rhs) {\n        // assert(compare(*this, rhs) >= 0);  // lhs<rhs\
    \ \u306E\u3068\u304D\uFF0C\u672A\u5B9A\u7FA9\u52D5\u4F5C\uFF0E\n        if(rhs.is_zero())\
    \ return *this;\n        subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    BinaryBigint &operator*=(const BinaryBigint\
    \ &rhs) { return *this = (*this) * rhs; }\n    BinaryBigint &operator/=(const\
    \ BinaryBigint &rhs) {\n        assert(!rhs.is_zero());\n        m_words = division(m_words,\
    \ m_words.size(), rhs.m_words, rhs.m_words.size());\n        return *this;\n \
    \   }\n    BinaryBigint &operator%=(const BinaryBigint &rhs) {\n        assert(!rhs.is_zero());\n\
    \        division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    BinaryBigint &operator<<=(unsigned long long\
    \ k) {\n        shift_left(m_words, m_words.size(), k);\n        return *this;\n\
    \    }\n    BinaryBigint &operator>>=(unsigned long long k) {\n        shift_right(m_words,\
    \ m_words.size(), k);\n        return *this;\n    }\n    BinaryBigint &operator&=(const\
    \ BinaryBigint &rhs) {\n        bit_and(m_words, m_words.size(), rhs.m_words,\
    \ rhs.m_words.size());\n        return *this;\n    }\n    BinaryBigint &operator|=(const\
    \ BinaryBigint &rhs) {\n        bit_or(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n    BinaryBigint &operator^=(const BinaryBigint\
    \ &rhs) {\n        bit_xor(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());\n\
    \        return *this;\n    }\n\n    friend bool operator==(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return lhs.m_words == rhs.m_words; }\n    friend\
    \ int operator<=>(const BinaryBigint &lhs, const BinaryBigint &rhs) { return compare(lhs,\
    \ rhs); }\n    friend BinaryBigint operator+(const BinaryBigint &lhs, const BinaryBigint\
    \ &rhs) { return BinaryBigint(lhs) += rhs; }\n    friend BinaryBigint operator-(const\
    \ BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) -= rhs;\
    \ }\n    friend BinaryBigint operator*(const BinaryBigint &lhs, const BinaryBigint\
    \ &rhs) {\n        if(lhs.is_zero() or rhs.is_zero()) return BinaryBigint();\n\
    \        return BinaryBigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words,\
    \ rhs.m_words.size()));\n    }\n    friend BinaryBigint operator/(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) /= rhs; }\n    friend\
    \ BinaryBigint operator%(const BinaryBigint &lhs, const BinaryBigint &rhs) { return\
    \ BinaryBigint(lhs) %= rhs; }\n    friend BinaryBigint operator<<(const BinaryBigint\
    \ &lhs, unsigned long long k) { return BinaryBigint(lhs) <<= k; }\n    friend\
    \ BinaryBigint operator>>(const BinaryBigint &lhs, unsigned long long k) { return\
    \ BinaryBigint(lhs) >>= k; }\n    friend BinaryBigint operator&(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) &= rhs; }\n    friend\
    \ BinaryBigint operator|(const BinaryBigint &lhs, const BinaryBigint &rhs) { return\
    \ BinaryBigint(lhs) |= rhs; }\n    friend BinaryBigint operator^(const BinaryBigint\
    \ &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) ^= rhs; }\n    friend\
    \ std::istream &operator>>(std::istream &is, BinaryBigint &rhs) {\n        std::string\
    \ s;\n        is >> s;\n        assert(validate(s));\n        rhs.normalize(s,\
    \ s.size());\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryBigint &rhs) {\n        if(rhs.is_zero()) return os << 0;\n\
    \        auto old = os.setf(std::ios_base::hex, std::ios_base::basefield);  //\
    \ 16\u9032\u6570\u8868\u793A\uFF0E\n        os << rhs.m_words.back();\n      \
    \  for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter)\
    \ os << std::setw(8) << std::setfill('0') << *iter;\n        os.flags(old);\n\
    \        return os;\n    }\n\n    bool is_zero() const { return m_words.empty();\
    \ }\n    void zeroize() { m_words.clear(); }\n    std::pair<BinaryBigint, BinaryBigint>\
    \ divide(const BinaryBigint &a) const {\n        assert(!a.is_zero());\n     \
    \   auto remain = m_words;\n        auto &&quotient = division(remain, remain.size(),\
    \ a.m_words, a.m_words.size());\n        return {BinaryBigint(std::move(quotient)),\
    \ BinaryBigint(std::move(remain))};\n    }\n    std::string to_string() const\
    \ {\n        std::ostringstream oss;\n        oss << *this;\n        return oss.str();\n\
    \    }\n    const std::deque<uint32_t> &words() const { return m_words; }\n};\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/Math/NumberTheory/binary_bigint.hpp
  requiredBy: []
  timestamp: '2025-03-09 23:19:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/NumberTheory/binary_bigint.hpp
layout: document
title: "\u591A\u500D\u9577\u6574\u6570\uFF0816\u9032\u6570\uFF09"
---


## 概要

多倍長整数の演算をサポートする構造体．
内部では数値を2進数で管理しており，ビット演算もサポートする．
