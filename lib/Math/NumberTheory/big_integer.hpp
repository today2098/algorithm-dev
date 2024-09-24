#ifndef ALGORITHM_BIG_INTEGER_HPP
#define ALGORITHM_BIG_INTEGER_HPP 1

/**
 * @brief 多倍長整数
 * @docs docs/Math/big_integer.md
 */

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace algorithm {

class BigInteger {
    static constexpr int BASE_DIGIT = 9;
    static constexpr int64_t BASE = 1e9;

    int m_sign;
    std::vector<int64_t> m_words;

    bool validate(std::string_view sv) const {
        if(sv.empty()) return false;
        const int len = sv.size();
        int i = 0;
        if(sv[0] == '+' or sv[0] == '-') {
            if(len < 2) return false;
            i++;
        }
        for(; i < len; ++i) {
            if(!('0' <= sv[i] and sv[i] <= '9')) return false;
        }
        return true;
    }
    void convert_internal(std::string_view sv) {
        const int len = sv.size();
        const int sz = (len + BASE_DIGIT - 1) / BASE_DIGIT;
        m_words.assign(sz, 0);
        int offset = 0;
        for(int i = 0; i < sz; ++i) {
            for(int j = std::min(BASE_DIGIT, len - offset) - 1; j >= 0; --j) m_words[i] = 10 * m_words[i] + (sv[len - offset - 1 - j] - '0');
            offset += BASE_DIGIT;
        }
        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();
        m_sign = (m_words.back() == 0 ? 0 : 1);
    }
    void convert(std::string_view sv) {
        if(sv[0] == '+') {
            convert_internal(sv.substr(1));
            return;
        }
        if(sv[0] == '-') {
            convert_internal(sv.substr(1));
            negation();
            return;
        }
        convert_internal(sv);
    }
    int compare(const std::vector<int64_t> &rhs) const {
        const int n = m_words.size(), m = rhs.size();
        if(n < m) return -1;
        if(n > m) return 1;
        for(int i = n - 1; i >= 0; --i) {
            if(m_words[i] < rhs[i]) return -1;
            if(m_words[i] > rhs[i]) return 1;
        }
        return 0;
    }
    void addition(const std::vector<int64_t> &rhs) {
        const int sz = rhs.size();
        if(sz > (int)m_words.size()) m_words.resize(sz, 0);
        for(int i = 0; i < sz; ++i) m_words[i] += rhs[i];
    }
    void subtraction(const std::vector<int64_t> &rhs) {
        const int sz = rhs.size();
        if(sz > (int)m_words.size()) m_words.resize(sz, 0);
        for(int i = 0; i < sz; ++i) m_words[i] -= rhs[i];
    }
    void carry() {
        const int sz = m_words.size();
        for(int i = 0; i < sz - 1; ++i) {
            if(m_words[i] < 0) {
                int64_t k = (-m_words[i] + BASE - 1) / BASE;
                m_words[i] += BASE * k;
                m_words[i + 1] -= k;
            } else if(10 <= m_words[i]) {
                int64_t k = m_words[i] / BASE;
                m_words[i] -= BASE * k;
                m_words[i + 1] += k;
            }
        }
        while(m_words.back() >= 10) {
            int64_t k = m_words.back() / BASE;
            m_words.back() -= BASE * k;
            m_words.push_back(k);
        }
        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();
    }

public:
    BigInteger() : m_sign(false), m_words(1, 0) {};
    BigInteger(const char *s) : BigInteger(std::string_view(s)) {}
    BigInteger(const std::string &s) : BigInteger(std::string_view(s)) {}
    BigInteger(std::string_view sv) {
        assert(validate(sv));
        convert(sv);
    }

    BigInteger &operator+=(const BigInteger &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = rhs;
        if(m_sign == rhs.m_sign) {
            addition(rhs.m_words);
            carry();
        } else {
            int cmp = compare(rhs.m_words);
            if(cmp < 0) {
                m_sign = -m_sign;
                subtraction(rhs.m_words);
                for(auto &word : m_words) word = -word;
                carry();
            } else if(cmp == 0) {
                m_sign = 0;
                m_words.assign(1, 0);
            } else {
                subtraction(rhs.m_words);
                carry();
            }
        }
        return *this;
    }
    BigInteger &operator-=(const BigInteger &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) {
            *this = rhs;
            negation();
            return *this;
        }
        if(m_sign != rhs.m_sign) {
            addition(rhs.m_words);
            carry();
        } else {
            int cmp = compare(rhs.m_words);
            if(cmp < 0) {
                m_sign = -m_sign;
                subtraction(rhs.m_words);
                for(auto &word : m_words) word = -word;
                carry();
            } else if(cmp == 0) {
                m_sign = 0;
                m_words.assign(1, 0);
            } else {
                subtraction(rhs.m_words);
                carry();
            }
        }
        return *this;
    }

    friend bool operator<(const BigInteger &lhs, const BigInteger &rhs) {
        if(lhs.m_sign == rhs.m_sign) {
            if(lhs.m_sign < 0) return lhs.compare(rhs.m_words) == 1;
            return lhs.compare(rhs.m_words) == -1;
        }
        return lhs.m_sign < rhs.m_sign;
    }
    friend bool operator>(const BigInteger &lhs, const BigInteger &rhs) { return rhs < lhs; }
    friend bool operator<=(const BigInteger &lhs, const BigInteger &rhs) { return !(lhs > rhs); }
    friend bool operator>=(const BigInteger &lhs, const BigInteger &rhs) { return !(lhs < rhs); }
    friend BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs) { return BigInteger(lhs) += rhs; }
    friend BigInteger operator-(const BigInteger &lhs, const BigInteger &rhs) { return BigInteger(lhs) -= rhs; }
    friend std::istream &operator>>(std::istream &is, BigInteger &rhs) {
        std::string s;
        is >> s;
        assert(rhs.validate(s));
        rhs.convert(s);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BigInteger &rhs) {
        os << (rhs.m_sign == -1 ? "-" : "") << rhs.m_words.back();
        for(auto itr = rhs.m_words.crbegin() + 1; itr < rhs.m_words.crend(); ++itr) os << std::setw(BASE_DIGIT) << std::setfill('0') << *itr;
        return os;
    }

    bool is_zero() const { return sign() == 0; }
    int sign() const { return m_sign; }
    void negation() { m_sign = -m_sign; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};

}  // namespace algorithm

#endif
