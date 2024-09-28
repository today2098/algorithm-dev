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
        const int n = (len + BASE_DIGIT - 1) / BASE_DIGIT;
        m_words.assign(n, 0);
        int offset = 0;
        for(int i = 0; i < n; ++i) {
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
            if(m_words[i] != rhs[i]) return (m_words[i] < rhs[i] ? -1 : 1);
        }
        return 0;
    }
    void addition(const std::vector<int64_t> &rhs) {
        int n = m_words.size();
        const int m = rhs.size();
        if(n < m) n = m;
        m_words.resize(n + 1, 0);
        for(int i = 0; i < m; ++i) {
            m_words[i] += rhs[i];
            if(m_words[i] >= BASE) m_words[i] -= BASE, m_words[i + 1]++;  // carry.
        }
        for(int i = m; i < n; ++i) {
            if(m_words[i] < BASE) break;
            m_words[i] -= BASE, m_words[i + 1]++;  // carry.
        }
        if(m_words.back() == 0) m_words.pop_back();
    }
    void subtraction1(const std::vector<int64_t> &rhs) {
        const int n = m_words.size(), m = rhs.size();
        for(int i = 0; i < m; ++i) {
            m_words[i] -= rhs[i];
            if(m_words[i] < 0) m_words[i] += BASE, m_words[i + 1]--;  // carry.
        }
        for(int i = m; i < n - 1; ++i) {
            if(m_words[i] >= 0) break;
            m_words[i] += BASE, m_words[i + 1]--;  // carry.
        }
        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();
    }
    void subtraction2(const std::vector<int64_t> &rhs) {
        const int n = rhs.size();
        if(n > (int)m_words.size()) m_words.resize(n, 0);
        for(int i = 0; i < n; ++i) {
            m_words[i] -= rhs[i];
            if(m_words[i] > 0) m_words[i] -= BASE, m_words[i + 1]++;  // carry.
        }
        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();
        for(int64_t &word : m_words) word = -word;
    }

public:
    BigInteger() : m_sign(0), m_words({0}) {};
    BigInteger(int64_t n) : m_sign(0), m_words({n}) {
        if(n < 0) m_sign = -1, m_words[0] = -m_words[0];
        else if(n > 0) m_sign = 1;
        while(m_words.back() >= BASE) {
            int64_t c = m_words.back() / BASE;
            m_words.back() -= BASE * c;
            m_words.push_back(c);  // carry.
        }
    }
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
        } else {
            int cmp = compare(rhs.m_words);
            if(cmp < 0) {
                subtraction2(rhs.m_words);
                negation();
            } else if(cmp == 0) {
                zeroing();
            } else {
                subtraction1(rhs.m_words);
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
        } else {
            int cmp = compare(rhs.m_words);
            if(cmp < 0) {
                subtraction2(rhs.m_words);
                negation();
            } else if(cmp == 0) {
                zeroing();
            } else {
                subtraction1(rhs.m_words);
            }
        }
        return *this;
    }
    BigInteger &operator*=(const BigInteger &rhs) {
        if(is_zero()) return *this;
        if(rhs.is_zero()) {
            zeroing();
            return *this;
        }
        m_sign = m_sign * rhs.m_sign;
        const int n = m_words.size(), m = rhs.m_words.size();
        std::vector<int64_t> res(n + m, 0);
        for(int j = 0; j < m; ++j) {
            for(int i = 0; i < n; ++i) {
                res[i + j] += m_words[i] * rhs.m_words[j];
                if(res[i + j] >= BASE) {
                    int64_t c = res[i + j] / BASE;
                    res[i + j] -= BASE * c, res[i + j + 1] += c;  // carry.
                }
            }
        }
        if(res.back() == 0) res.pop_back();
        m_words = res;
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
    friend BigInteger operator*(const BigInteger &lhs, const BigInteger &rhs) { return BigInteger(lhs) *= rhs; }
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
    void zeroing() {
        m_sign = 0;
        m_words.assign(1, 0);
    }
    void negation() { m_sign = -m_sign; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};

}  // namespace algorithm

#endif
