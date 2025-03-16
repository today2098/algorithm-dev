#ifndef ALGORITHM_BINARY_BIGINT_HPP
#define ALGORITHM_BINARY_BIGINT_HPP 1

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>

namespace algorithm {

class BinaryBigint {
    static constexpr uint64_t BASE = 0x0000000100000000ULL;
    static constexpr size_t BASE_DIGIT = 32;
    static constexpr uint32_t SIGNBIT[2] = {0x00000000U, 0xffffffffU};

    std::deque<uint32_t> m_words;
    uint32_t m_signbit;

    explicit BinaryBigint(const std::deque<uint32_t> &words, uint32_t signbit) : m_words(words), m_signbit(signbit) {}
    explicit BinaryBigint(std::deque<uint32_t> &&words, uint32_t signbit) : m_words(std::move(words)), m_signbit(signbit) {}

    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }
    static constexpr bool isupper(char c) { return 'A' <= c and c <= 'F'; }
    static constexpr bool islower(char c) { return 'a' <= c and c <= 'f'; }
    static constexpr uint32_t ctoi(char c) {
        if(isdigit(c)) return c - '0';
        if(isupper(c)) return 10 + (c - 'A');
        return 10 + (c - 'a');
    }
    static constexpr bool validate(std::string_view sv, size_t n) {
        if(n == 0) return false;
        if(sv[0] == '+' or sv[0] == '-') return validate_unsigned(sv.substr(1), n - 1);
        return validate_unsigned(sv, n);
    }
    static constexpr bool validate_unsigned(std::string_view sv, size_t n) {
        if(n == 0) return false;
        return std::find_if_not(sv.cbegin(), sv.cend(), [](char c) -> bool { return isdigit(c) or isupper(c) or islower(c); }) == sv.cend();
    }
    static int compare(const BinaryBigint &lhs, const BinaryBigint &rhs) { return compare(lhs.m_words, lhs.m_words.size(), lhs.m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit); }
    static int compare(const std::deque<uint32_t> &lhs, ssize_t n, uint32_t lsb, const std::deque<uint32_t> &rhs, ssize_t m, uint32_t rsb) {
        if(lsb ^ rsb) return (lsb ? -1 : 1);
        if(n < m) return (lsb ? 1 : -1);
        if(n > m) return (lsb ? -1 : 1);
        for(ssize_t i = n - 1; i >= 0; --i) {
            if(lhs[i] == rhs[i]) continue;
            if(lhs[i] < rhs[i]) return -1;
            return 1;
        }
        return 0;
    }
    static uint32_t store(uint32_t &word, uint64_t val) {
        word = val;
        return val >> BASE_DIGIT;  // return carry.
    }
    static size_t shrink(std::deque<uint32_t> &words, uint32_t signbit) {
        while(!words.empty() and words.back() == signbit) words.pop_back();
        return words.size();
    }
    static size_t zeroisation(std::deque<uint32_t> &words, uint32_t &signbit) {
        words.clear(), signbit = SIGNBIT[0];
        return 0;
    }
    static size_t negation(std::deque<uint32_t> &words, uint32_t &signbit) {
        words.push_back(signbit);
        uint32_t ncarry = 1;
        for(uint32_t &word : words) ncarry = store(word, (uint64_t)~word + ncarry);
        signbit = ~signbit + ncarry;
        return shrink(words, signbit);
    }
    static uint32_t bitwise_not(std::deque<uint32_t> &words, uint32_t &signbit) {
        for(uint32_t &word : words) word = ~word;
        signbit = ~signbit;
        return words.size();
    }
    static void addition(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {
        n = std::max(n, m) + 1;
        lhs.resize(n, lsb);
        uint32_t carry = 0;
        for(size_t i = 0; i < m; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + rhs[i] + carry);
        for(size_t i = m; i < n and rsb + carry; ++i) carry = store(lhs[i], (uint64_t)lhs[i] + rsb + carry);
        lsb = lsb + rsb + carry;
        shrink(lhs, lsb);
    }
    static void subtraction(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {
        n = std::max(n, m) + 1;
        lhs.resize(n, lsb);
        uint32_t ncarry = 1;
        for(size_t i = 0; i < m; ++i) ncarry = store(lhs[i], (uint64_t)lhs[i] + ~rhs[i] + ncarry);
        for(size_t i = m; i < n and ~rsb + ncarry; ++i) ncarry = store(lhs[i], (uint64_t)lhs[i] + ~rsb + ncarry);
        lsb = lsb + ~rsb + ncarry;
        shrink(lhs, lsb);
    }
    static std::pair<std::deque<uint32_t>, uint32_t> multiplication(const std::deque<uint32_t> &lhs, size_t n, uint32_t lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {
        std::deque<uint32_t> words(n + m, 0);
        uint32_t signbit = lsb ^ rsb;
        for(size_t i = 0; i < n; ++i) {
            if(!lhs[i]) continue;
            uint32_t carry = 0;
            for(size_t j = 0; j < m; ++j) carry = store(words[i + j], words[i + j] + (uint64_t)lhs[i] * rhs[j] + carry);
            words[i + m] = carry;
        }
        if(rsb) {
            uint32_t ncarry = 1;
            for(size_t i = 0; i < n; ++i) ncarry = store(words[i + m], (uint64_t)words[i + m] + ~lhs[i] + ncarry);
        }
        if(lsb) {
            uint32_t ncarry = 1;
            for(size_t j = 0; j < m; ++j) ncarry = store(words[j + n], (uint64_t)words[j + n] + ~rhs[j] + ncarry);
        }
        shrink(words, signbit);
        return {words, signbit};
    }
    static std::pair<std::deque<uint32_t>, uint32_t> division(std::deque<uint32_t> &lhs, ssize_t n, uint32_t &lsb, const std::deque<uint32_t> &rhs, ssize_t m, uint32_t rsb) {
        if(m == 0) {
            assert(rsb != SIGNBIT[0]);
            auto words = lhs;
            uint32_t signbit = lsb;
            negation(words, signbit), zeroisation(lhs, lsb);
            return {words, signbit};
        }
        if(lsb ^ rsb) {
            n = negation(lhs, lsb);
            auto &&[words, signbit] = division(lhs, n, lsb, rhs, m, rsb);
            negation(words, signbit), negation(lhs, lsb);
            return {words, signbit};
        }
        std::deque<uint32_t> words;
        uint32_t signbit = SIGNBIT[0];
        lhs.push_back(lsb), ++n;
        auto bisearch = [&](ssize_t offset) -> uint32_t {
            auto eval = [&](uint32_t d) -> bool {
                uint32_t tmp;
                uint32_t carry = 0, ncarry = 1;
                for(ssize_t i = 0; i < m; ++i) {
                    carry = store(tmp, (uint64_t)rhs[i] * d + carry);
                    ncarry = store(tmp, (uint64_t)lhs[i + offset] + ~tmp + ncarry);
                }
                carry = store(tmp, (uint64_t)rsb * d + carry);
                ncarry = store(tmp, (uint64_t)lhs[m + offset] + ~tmp + ncarry);
                uint32_t last = lsb + ~(rsb * d + carry) + ncarry;
                return last == lsb;
            };
            uint64_t ok = 0, ng = BASE;
            while(ng - ok > 1) {
                uint64_t mid = ok + (ng - ok) / 2;
                (eval(mid) ? ok : ng) = mid;
            }
            return ok;
        };
        auto sub = [&](ssize_t offset, uint32_t d) -> void {
            uint32_t carry = 0, ncarry = 1;
            for(ssize_t i = 0; i < m; ++i) {
                uint32_t tmp;
                carry = store(tmp, (uint64_t)rhs[i] * d + carry);
                ncarry = store(lhs[i + offset], (uint64_t)lhs[i + offset] + ~tmp + ncarry);
            }
            store(lhs[m + offset], lhs[m + offset] + ~(rsb * d + carry) + ncarry);
            lhs.pop_back();
        };
        for(ssize_t i = n - m - 1; i >= 0; --i) {
            uint32_t d = bisearch(i);
            words.push_front(d);
            sub(i, d);
        }
        shrink(words, signbit), n = shrink(lhs, lsb);
        if(lsb and compare(lhs, n, lsb, rhs, m, rsb) == 0) addition(words, words.size(), signbit, {1}, 1, SIGNBIT[0]), zeroisation(lhs, lsb);
        return {words, signbit};
    }
    static void shift_left(std::deque<uint32_t> &words, size_t n, uint32_t signbit, size_t k) {
        size_t t = k / BASE_DIGIT;
        k -= 32ULL * t;
        uint32_t carry = 0;
        for(size_t i = 0; i < n; ++i) {
            uint32_t word = words[i];
            words[i] = word << k | carry;
            carry = word >> (BASE_DIGIT - k);
        }
        words.push_back(signbit << k | carry);
        for(size_t i = 0; i < t; ++i) words.push_front(SIGNBIT[0]);
        shrink(words, signbit);
    }
    static void shift_right(std::deque<uint32_t> &words, size_t n, uint32_t signbit, size_t k) {
        if(k >= 32ULL * n) {
            words.clear();
            return;
        }
        size_t t = k / BASE_DIGIT;
        for(size_t i = 0; i < t; ++i) words.pop_front();
        n -= t, k -= 32ULL * t;
        for(size_t i = 0; i < n - 1; ++i) words[i] = words[i + 1] << (BASE_DIGIT - k) | words[i] >> k;
        words[n - 1] = signbit << (BASE_DIGIT - k) | words[n - 1] >> k;
        shrink(words, signbit);
    }
    static void bitwise_and(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {
        n = std::max(n, m);
        lhs.resize(n, lsb);
        for(size_t i = 0; i < m; ++i) lhs[i] &= rhs[i];
        for(size_t i = m; i < n; ++i) lhs[i] &= rsb;
        lsb &= rsb;
        shrink(lhs, lsb);
    }
    static void bitwise_or(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {
        n = std::max(n, m);
        lhs.resize(n, lsb);
        for(size_t i = 0; i < m; ++i) lhs[i] |= rhs[i];
        for(size_t i = m; i < n; ++i) lhs[i] |= rsb;
        lsb |= rsb;
        shrink(lhs, lsb);
    }
    static void bitwise_xor(std::deque<uint32_t> &lhs, size_t n, uint32_t &lsb, const std::deque<uint32_t> &rhs, size_t m, uint32_t rsb) {
        n = std::max(n, m);
        lhs.resize(n, lsb);
        for(size_t i = 0; i < m; ++i) lhs[i] ^= rhs[i];
        for(size_t i = m; i < n; ++i) lhs[i] ^= rsb;
        lsb ^= rsb;
        shrink(lhs, lsb);
    }
    static bool bitwise_test(const std::deque<uint32_t> &words, size_t n, uint32_t signbit, size_t pos) {
        size_t t = pos / BASE_DIGIT;
        pos -= BASE_DIGIT * t;
        if(t < n) return words[t] >> pos & 1U;
        return signbit;
    }
    static void bitwise_set(std::deque<uint32_t> &words, size_t n, uint32_t signbit, size_t pos) {
        size_t t = pos / BASE_DIGIT;
        pos -= BASE_DIGIT * t;
        if(t < n) {
            words[t] |= 1U << pos;
            shrink(words, signbit);
            return;
        }
        if(signbit) return;
        words.resize(t + 1, SIGNBIT[0]);
        words[t] |= 1U << pos;
    }
    static void bitwise_reset(std::deque<uint32_t> &words, size_t n, uint32_t signbit, size_t pos) {
        size_t t = pos / BASE_DIGIT;
        pos -= BASE_DIGIT * t;
        if(t < n) {
            words[t] &= ~(1U << pos);
            shrink(words, signbit);
            return;
        }
        if(!signbit) return;
        words.resize(t + 1, SIGNBIT[1]);
        words[t] &= ~(1U << pos);
    }
    void normalize(std::string_view sv, size_t n) {
        assert(n > 0);
        if(sv[0] == '+') {
            normalize_unsigned(sv.substr(1), n - 1);
        } else if(sv[0] == '-') {
            normalize_unsigned(sv.substr(1), n - 1);
            negation(m_words, m_signbit);
        } else {
            normalize_unsigned(sv, n);
        }
    }
    void normalize_unsigned(std::string_view sv, size_t n) {
        size_t m = (n + 7) / 8;
        m_words.assign(m, SIGNBIT[0]);
        auto iter = sv.crbegin();
        for(size_t i = 0; i < m; ++i) {
            for(size_t j = 0; j < BASE_DIGIT and iter < sv.crend(); j += 4, ++iter) m_words[i] |= ctoi(*iter) << j;
        }
        shrink(m_words, SIGNBIT[0]);
        m_signbit = SIGNBIT[0];
    }

public:
    BinaryBigint() : m_words(), m_signbit(SIGNBIT[0]) {}
    BinaryBigint(int64_t n) : m_words({(uint32_t)n, uint32_t(n >> BASE_DIGIT)}), m_signbit(SIGNBIT[n < 0]) {
        shrink(m_words, m_signbit);
    }
    BinaryBigint(const char *c) : BinaryBigint(std::string_view(c)) {}
    BinaryBigint(std::string_view sv) {
        std::stringstream ss;
        ss << sv;
        ss >> *this;
    }

    explicit operator bool() const { return !is_zero(); }
    BinaryBigint operator+() const { return BinaryBigint(*this); }
    BinaryBigint operator-() const {
        BinaryBigint res = *this;
        return res.negate();
    }
    BinaryBigint operator~() const {
        BinaryBigint res = *this;
        return res.bitwise_not();
    }
    BinaryBigint &operator+=(const BinaryBigint &rhs) {
        addition(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return *this;
    }
    BinaryBigint &operator-=(const BinaryBigint &rhs) {
        subtraction(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return *this;
    }
    BinaryBigint &operator*=(const BinaryBigint &rhs) { return *this = (*this) * rhs; }
    BinaryBigint &operator/=(const BinaryBigint &rhs) {
        assert(!rhs.is_zero());
        auto &&[words, signbit] = division(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        m_words = std::move(words), m_signbit = signbit;
        return *this;
    }
    BinaryBigint &operator%=(const BinaryBigint &rhs) {
        assert(!rhs.is_zero());
        division(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return *this;
    }
    BinaryBigint &operator<<=(size_t k) {
        shift_left(m_words, m_words.size(), m_signbit, k);
        return *this;
    }
    BinaryBigint &operator>>=(size_t k) {
        shift_right(m_words, m_words.size(), m_signbit, k);
        return *this;
    }
    BinaryBigint &operator&=(const BinaryBigint &rhs) {
        bitwise_and(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return *this;
    }
    BinaryBigint &operator|=(const BinaryBigint &rhs) {
        bitwise_or(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return *this;
    }
    BinaryBigint &operator^=(const BinaryBigint &rhs) {
        bitwise_xor(m_words, m_words.size(), m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return *this;
    }

    friend bool operator==(const BinaryBigint &lhs, const BinaryBigint &rhs) { return lhs.m_words == rhs.m_words and lhs.m_signbit == rhs.m_signbit; }
    friend int operator<=>(const BinaryBigint &lhs, const BinaryBigint &rhs) { return compare(lhs, rhs); }
    friend BinaryBigint operator+(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) += rhs; }
    friend BinaryBigint operator-(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) -= rhs; }
    friend BinaryBigint operator*(const BinaryBigint &lhs, const BinaryBigint &rhs) {
        if(lhs.is_zero() or rhs.is_zero()) return BinaryBigint();
        auto &&[words, signbit] = multiplication(lhs.m_words, lhs.m_words.size(), lhs.m_signbit, rhs.m_words, rhs.m_words.size(), rhs.m_signbit);
        return BinaryBigint(std::move(words), signbit);
    }
    friend BinaryBigint operator/(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) /= rhs; }
    friend BinaryBigint operator%(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) %= rhs; }
    friend BinaryBigint operator<<(const BinaryBigint &lhs, size_t k) { return BinaryBigint(lhs) <<= k; }
    friend BinaryBigint operator>>(const BinaryBigint &lhs, size_t k) { return BinaryBigint(lhs) >>= k; }
    friend BinaryBigint operator&(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) &= rhs; }
    friend BinaryBigint operator|(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) |= rhs; }
    friend BinaryBigint operator^(const BinaryBigint &lhs, const BinaryBigint &rhs) { return BinaryBigint(lhs) ^= rhs; }
    friend std::istream &operator>>(std::istream &is, BinaryBigint &rhs) {
        std::string s;
        is >> s;
        assert(validate(s, s.size()));
        rhs.normalize(s, s.size());
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BinaryBigint &rhs) {
        if(rhs.signbit()) return os << "-" << -rhs;
        if(rhs.is_zero()) return os << 0;
        auto old = os.setf(std::ios_base::hex, std::ios_base::basefield);  // 16進数表示．
        auto iter = rhs.m_words.crbegin();
        os << *iter++;
        for(; iter < rhs.m_words.crend(); ++iter) os << std::setw(8) << std::setfill('0') << *iter;
        os.flags(old);
        return os;
    }

    static constexpr uint64_t base() { return BASE; }
    static constexpr size_t base_digit() { return BASE_DIGIT; }
    const std::deque<uint32_t> &words() const { return m_words; }
    bool signbit() const { return m_signbit; }
    bool is_zero() const { return m_words.empty() and !m_signbit; }
    int sign() const {
        if(is_zero()) return 0;
        return (signbit() ? -1 : 1);
    }
    std::pair<BinaryBigint, BinaryBigint> divide(const BinaryBigint &divisor) const {
        assert(!divisor.is_zero());
        auto remain = *this;
        auto &&[words, signbit] = division(remain.m_words, remain.m_words.size(), remain.m_signbit, divisor.m_words, divisor.m_words.size(), divisor.m_signbit);
        return {BinaryBigint(std::move(words), signbit), std::move(remain)};
    }
    BinaryBigint &zeroise() {
        zeroisation(m_words, m_signbit);
        return *this;
    }
    BinaryBigint &negate() {
        negation(m_words, m_signbit);
        return *this;
    }
    BinaryBigint &bitwise_not() {
        bitwise_not(m_words, m_signbit);
        return *this;
    }
    bool test(size_t k) const { return bitwise_test(m_words, m_words.size(), m_signbit, k); }
    BinaryBigint &set(size_t k, bool val = true) {
        if(!val) return reset(k);
        bitwise_set(m_words, m_words.size(), m_signbit, k);
        return *this;
    }
    BinaryBigint &reset(size_t k) {
        bitwise_reset(m_words, m_words.size(), m_signbit, k);
        return *this;
    }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};

}  // namespace algorithm

#endif
