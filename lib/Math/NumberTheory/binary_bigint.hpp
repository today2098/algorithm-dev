#ifndef ALGORITHM_BINARY_BIGINT_HPP
#define ALGORITHM_BINARY_BIGINT_HPP 1

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>

namespace algorithm {

class BinaryBigint {
    std::deque<uint32_t> m_words;

    explicit BinaryBigint(const std::deque<uint32_t> &words) : m_words(words) {}

    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }
    static constexpr bool isupper(char c) { return 'A' <= c and c <= 'F'; }
    static constexpr bool islower(char c) { return 'a' <= c and c <= 'f'; }
    static constexpr uint32_t to_dec(char c) {
        if(isdigit(c)) return c - '0';
        if(isupper(c)) return 10 + (c - 'A');
        return 10 + (c - 'a');
    }
    static constexpr bool validate(std::string_view sv) {
        if(sv == "") return false;
        return std::find_if_not(sv.cbegin(), sv.cend(), [](char c) -> bool { return isdigit(c) or isupper(c) or islower(c); }) == sv.cend();
    }
    static uint32_t store(uint32_t &word, uint64_t val) {
        word = val;
        return val >> 32;  // carry.
    }
    static uint64_t sub_store(uint32_t &word, uint64_t val) {
        uint64_t ncarry = store(word, val);
        if(ncarry) ncarry |= 0xffffffff00000000ULL;
        return ncarry;
    }
    static int compare(const BinaryBigint &lhs, const BinaryBigint &rhs) { return compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()); }
    static int compare(const std::deque<uint32_t> &lhs, ssize_t n, const std::deque<uint32_t> &rhs, ssize_t m) {
        if(n < m) return -1;
        if(n > m) return 1;
        for(ssize_t i = n - 1; i >= 0; --i) {
            if(lhs[i] == rhs[i]) continue;
            return (lhs[i] < rhs[i] ? -1 : 1);
        }
        return 0;
    }
    static void addition(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        uint32_t carry = 0;
        for(size_t i = 0; i < m; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + rhs[i] + carry);
        for(size_t i = m; i < n and carry; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + carry);
        if(carry) lhs.push_back(carry);
    }
    static void subtraction(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        uint64_t ncarry = 0;
        for(size_t i = 0; i < m; ++i) ncarry = sub_store(lhs[i], (uint64_t)lhs[i] - rhs[i] + ncarry);
        for(size_t i = m; i < n and ncarry; ++i) ncarry = sub_store(lhs[i], lhs[i] + ncarry);
        while(!lhs.empty() and !lhs.back()) lhs.pop_back();
    }
    static std::deque<uint32_t> multiplication(const std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {
        std::deque<uint32_t> res(n + m, 0);
        for(size_t i = 0; i < n; ++i) {
            uint32_t carry = 0;
            for(size_t j = 0; j < m; ++j) carry = store(res[i + j], res[i + j] + (uint64_t)lhs[i] * rhs[j] + carry);
            res[i + m] = carry;
        }
        while(!res.empty() and !res.back()) res.pop_back();
        return res;
    }
    static std::deque<uint32_t> division(std::deque<uint32_t> &lhs, ssize_t n, const std::deque<uint32_t> &rhs, ssize_t m) {
        assert(m > 0);
        std::deque<uint32_t> res;
        auto bisearch = [&](ssize_t offset) -> uint32_t {
            if(n - offset < m) return 0;
            auto eval = [&](uint32_t d) -> bool {
                uint32_t carry = 0;
                uint64_t ncarry = 0;
                for(ssize_t i = 0; i < m; ++i) {
                    uint32_t tmp;
                    carry = store(tmp, (uint64_t)rhs[i] * d + carry);
                    ncarry = sub_store(tmp, (uint64_t)lhs[i + offset] - tmp + ncarry);
                }
                uint64_t last = (uint64_t)(m + offset < n ? lhs.back() : 0) - carry + ncarry;
                return !(last & 0xffffffff00000000ULL);
            };
            uint64_t ok = 0, ng = (1ULL << 32);
            while(ng - ok > 1) {
                uint64_t mid = ok + (ng - ok) / 2;
                (eval(mid) ? ok : ng) = mid;
            }
            return ok;
        };
        auto sub = [&](ssize_t offset, uint32_t d) -> void {
            uint32_t carry = 0;
            uint64_t ncarry = 0;
            for(ssize_t i = 0; i < m; ++i) {
                uint32_t tmp = 0;
                carry = store(tmp, (uint64_t)rhs[i] * d + carry);
                ncarry = sub_store(lhs[i + offset], (uint64_t)lhs[i + offset] - tmp + ncarry);
            }
            if(m + offset < n) lhs.pop_back();
            while(offset < n and !lhs.back()) lhs.pop_back(), --n;
        };
        for(ssize_t i = n - m; i >= 0;) {
            uint32_t d = bisearch(i);
            res.push_front(d);
            sub(i, d);
            --i;
            while(!lhs.empty() and !lhs.back()) lhs.pop_back(), --n, --i;
        }
        if(!res.back()) res.pop_back();
        return res;
    }
    static void shift_left(std::deque<uint32_t> &words, size_t n, unsigned long long k) {
        if(n == 0) return;
        size_t t = k / 32;
        k -= 32ULL * t;
        uint32_t carry = 0;
        for(size_t i = 0; i < n; ++i) {
            uint32_t word = words[i];
            words[i] = word << k | carry;
            carry = word >> (32 - k);
        }
        if(carry) words.push_back(carry);
        for(size_t i = 0; i < t; ++i) words.push_front(0);
    }
    static void shift_right(std::deque<uint32_t> &words, size_t n, unsigned long long k) {
        if(k >= 32ULL * n) {
            words.clear();
            return;
        }
        size_t t = k / 32;
        for(size_t i = 0; i < t; ++i) words.pop_front();
        n -= t, k -= 32ULL * t;
        for(size_t i = 0; i < n - 1; ++i) words[i] = words[i + 1] << (32 - k) | words[i] >> k;
        words.back() >>= k;
        if(!words.back()) words.pop_back();
    }
    static void bit_and(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {
        n = std::min(n, m);
        lhs.resize(n);
        for(size_t i = 0; i < n; ++i) lhs[i] &= rhs[i];
        while(!lhs.empty() and !lhs.back()) lhs.pop_back();
    }
    static void bit_or(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        for(size_t i = 0; i < m; ++i) lhs[i] |= rhs[i];
    }
    static void bit_xor(std::deque<uint32_t> &lhs, size_t n, const std::deque<uint32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        for(size_t i = 0; i < m; ++i) lhs[i] ^= rhs[i];
        while(!lhs.empty() and !lhs.back()) lhs.pop_back();
    }
    void normalize(std::string_view sv, size_t n) {
        size_t m = (n + 7) / 8;
        m_words.assign(m, 0);
        auto iter = sv.crbegin();
        for(size_t i = 0; i < m; ++i) {
            for(unsigned j = 0; j < 32 and iter < sv.crend(); j += 4, ++iter) m_words[i] |= to_dec(*iter) << j;
        }
        while(!m_words.empty() and !m_words.back()) m_words.pop_back();
    }

public:
    BinaryBigint() : m_words() {}
    BinaryBigint(uint64_t n) : m_words({(uint32_t)n, uint32_t(n >> 32)}) {
        while(!m_words.empty() and !m_words.back()) m_words.pop_back();
    }
    BinaryBigint(const char *c) : BinaryBigint(std::string_view(c)) {}
    BinaryBigint(std::string_view sv) {
        std::stringstream ss;
        ss << sv;
        ss >> *this;
    }

    BinaryBigint &operator+=(const BinaryBigint &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = rhs;
        addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    BinaryBigint &operator-=(const BinaryBigint &rhs) {
        // assert(compare(*this, rhs) >= 0);  // lhs<rhs のとき，未定義動作．
        if(rhs.is_zero()) return *this;
        subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    BinaryBigint &operator*=(const BinaryBigint &rhs) { return *this = (*this) * rhs; }
    BinaryBigint &operator/=(const BinaryBigint &rhs) {
        assert(!rhs.is_zero());
        m_words = division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    BinaryBigint &operator%=(const BinaryBigint &rhs) {
        assert(!rhs.is_zero());
        division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    BinaryBigint &operator<<=(unsigned long long k) {
        shift_left(m_words, m_words.size(), k);
        return *this;
    }
    BinaryBigint &operator>>=(unsigned long long k) {
        shift_right(m_words, m_words.size(), k);
        return *this;
    }
    BinaryBigint &operator&=(const BinaryBigint &rhs) {
        bit_and(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    BinaryBigint &operator|=(const BinaryBigint &rhs) {
        bit_or(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    BinaryBigint &operator^=(const BinaryBigint &rhs) {
        bit_xor(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }

    friend bool operator==(const BinaryBigint &lhs, const BinaryBigint &rhs) { return lhs.m_words == rhs.m_words; }
    friend int operator<=>(const BinaryBigint &lhs, const BinaryBigint &rhs) { return compare(lhs, rhs); }
    friend BinaryBigint operator+(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) += rhs; }
    friend BinaryBigint operator-(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) -= rhs; }
    friend BinaryBigint operator*(const BinaryBigint &lhs, const BinaryBigint &rhs) {
        if(lhs.is_zero() or rhs.is_zero()) return BinaryBigint();
        return BinaryBigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()));
    }
    friend BinaryBigint operator/(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) /= rhs; }
    friend BinaryBigint operator%(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) %= rhs; }
    friend BinaryBigint operator<<(const BinaryBigint &lhs, unsigned long long k) { return BinaryBigint(lhs) <<= k; }
    friend BinaryBigint operator>>(const BinaryBigint &lhs, unsigned long long k) { return BinaryBigint(lhs) >>= k; }
    friend BinaryBigint operator&(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) &= rhs; }
    friend BinaryBigint operator|(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) |= rhs; }
    friend BinaryBigint operator^(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) ^= rhs; }
    friend std::istream &operator>>(std::istream &is, BinaryBigint &rhs) {
        std::string s;
        is >> s;
        assert(validate(s));
        rhs.normalize(s, s.size());
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BinaryBigint &rhs) {
        if(rhs.is_zero()) return os << 0;
        auto old = os.setf(std::ios_base::hex, std::ios_base::basefield);  // 16進数表示．
        os << rhs.m_words.back();
        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter) os << std::setw(8) << std::setfill('0') << *iter;
        os.flags(old);
        return os;
    }

    bool is_zero() const { return m_words.empty(); }
    void zeroize() { m_words.clear(); }
    std::pair<BinaryBigint, BinaryBigint> divide(const BinaryBigint &a) const {
        assert(!a.is_zero());
        auto remain = m_words;
        auto &&quotient = division(remain, remain.size(), a.m_words, a.m_words.size());
        return {BinaryBigint(std::move(quotient)), BinaryBigint(std::move(remain))};
    }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    const std::deque<uint32_t> &words() const { return m_words; }
};

}  // namespace algorithm

#endif
