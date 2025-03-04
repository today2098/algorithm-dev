#ifndef ALGORITHM_BIGINT_HPP
#define ALGORITHM_BIGINT_HPP 1

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace algorithm {

// 多倍長整数．
class Bigint {
    static constexpr int64_t BASE = 1'000'000'000;
    static constexpr size_t BASE_DIGIT = 9;

    std::vector<int64_t> m_words;
    int m_sign;

    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }
    static constexpr bool validate(std::string_view sv) {
        size_t n = sv.size();
        if(n == 0) return false;
        if(n == 1) return isdigit(sv[0]);
        if(!(sv[0] == '+' or sv[0] == '-' or isdigit(sv[0]))) return false;
        return std::find_if_not(sv.cbegin() + 1, sv.cend(), [](char c) -> bool { return isdigit(c); }) == sv.cend();
    }
    static int compare(const Bigint &lhs, const Bigint &rhs) {
        if(lhs.sign() == rhs.sign()) return compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size());
        if(lhs.sign() < rhs.sign()) return -1;
        return 1;
    }
    static int compare(const std::vector<int64_t> &lhs, ssize_t n, const std::vector<int64_t> &rhs, ssize_t m) {
        if(n < m) return -1;
        if(n > m) return 1;
        for(ssize_t i = n - 1; i >= 0; --i) {
            if(lhs[i] == rhs[i]) continue;
            if(lhs[i] < rhs[i]) return -1;
            return 1;
        }
        return 0;
    }
    void convert(std::string_view sv, size_t n) {
        if(sv[0] == '+') {
            convert_without_sign(sv.substr(1), n - 1);
        } else if(sv[0] == '-') {
            convert_without_sign(sv.substr(1), n - 1);
            negation();
        } else {
            convert_without_sign(sv, n);
        }
    }
    void convert_without_sign(std::string_view sv, size_t n) {
        size_t m = (n + BASE_DIGIT - 1) / BASE_DIGIT;
        m_words.assign(m, 0);
        auto iter = sv.crbegin();
        for(size_t i = 0; i < m; ++i) {
            int64_t d = 1;
            for(size_t j = 0; j < BASE_DIGIT; ++j) {
                if(iter >= sv.crend()) break;
                m_words[i] += d * (*iter - '0');
                iter++, d *= 10;
            }
        }
        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();
        m_sign = (m_words.back() == 0 ? 0 : 1);
    }
    void addition(const std::vector<int64_t> &rhs, size_t m) {
        size_t n = std::max(m_words.size(), m) + 1;
        m_words.resize(n, 0);
        for(size_t i = 0; i < m; ++i) {
            m_words[i] += rhs[i];
            if(m_words[i] >= BASE) m_words[i] -= BASE, m_words[i + 1]++;  // carry.
        }
        for(size_t i = m; i < n - 1; ++i) {
            if(m_words[i] < BASE) break;
            m_words[i] -= BASE, m_words[i + 1]++;  // carry.
        }
        if(m_words.back() == 0) m_words.pop_back();
    }
    int subtraction(const std::vector<int64_t> &rhs, ssize_t m) {
        ssize_t n = std::max<ssize_t>(m_words.size(), m);
        m_words.resize(n, 0);
        for(ssize_t i = 0; i < m; ++i) m_words[i] -= rhs[i];
        int sign = 0;
        for(ssize_t i = n - 1; i >= 0; --i) {
            if(m_words[i] == 0) continue;
            if(m_words[i] < 0) sign = -1;
            else sign = 1;
            break;
        }
        if(sign == -1) {
            for(auto &word : m_words) word *= -1;
        }
        for(ssize_t i = 0; i < n - 1; ++i) {
            if(m_words[i] < 0) m_words[i] += BASE, m_words[i + 1]--;  // carry.
        }
        while(m_words.size() > 1 and m_words.back() == 0) m_words.pop_back();
        return sign;
    }
    void multiplication(const std::vector<int64_t> &rhs, size_t m) {
        size_t n = m_words.size();
        std::vector<int64_t> res(n + m, 0);
        for(size_t i = 0; i < n; ++i) {
            for(size_t j = 0; j < m; ++j) {
                res[i + j] += m_words[i] * rhs[j];
                int64_t c = res[i + j] / BASE;
                res[i + j] -= BASE * c, res[i + j + 1] += c;  // carry.
            }
        }
        if(res.back() == 0) res.pop_back();
        m_words = res;
    }

public:
    Bigint() : m_words({0}), m_sign(0) {};
    Bigint(int64_t n) : m_words({n}), m_sign(0) {
        if(n < 0) m_words[0] = -m_words[0], m_sign = -1;
        else if(n > 0) m_sign = 1;
        while(m_words.back() >= BASE) {
            int64_t c = m_words.back() / BASE;
            m_words.back() -= BASE * c;
            m_words.push_back(c);  // carry.
        }
    }
    Bigint(const char *s) : Bigint(std::string_view(s)) {}
    explicit Bigint(std::string_view sv) {
        std::stringstream ss;
        ss << sv;
        ss >> *this;
    }

    Bigint operator+() const { return Bigint(*this); }
    Bigint operator-() const {
        Bigint res = *this;
        res.negation();
        return res;
    }
    Bigint &operator+=(const Bigint &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = rhs;
        if(sign() == rhs.sign()) addition(rhs.m_words, rhs.m_words.size());
        else m_sign *= subtraction(rhs.m_words, rhs.m_words.size());
        return *this;
    }
    Bigint &operator-=(const Bigint &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = -rhs;
        if(sign() == rhs.sign()) m_sign *= subtraction(rhs.m_words, rhs.m_words.size());
        else addition(rhs.m_words, rhs.m_words.size());
        return *this;
    }
    Bigint &operator*=(const Bigint &rhs) {
        if(is_zero()) return *this;
        if(rhs.is_zero()) {
            zeroing();
            return *this;
        }
        m_sign *= rhs.sign();
        multiplication(rhs.m_words, rhs.m_words.size());
        return *this;
    }

    friend bool operator==(const Bigint &lhs, const Bigint &rhs) { return lhs.sign() == rhs.sign() and lhs.m_words == rhs.m_words; }
    friend bool operator!=(const Bigint &lhs, const Bigint &rhs) { return !(lhs == rhs); }
    friend int operator<=>(const Bigint &lhs, const Bigint &rhs) { return compare(lhs, rhs); }
    friend Bigint operator+(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs; }
    friend Bigint operator-(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) -= rhs; }
    friend Bigint operator*(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) *= rhs; }
    friend std::istream &operator>>(std::istream &is, Bigint &rhs) {
        std::string s;
        is >> s;
        assert(validate(s));
        rhs.convert(s, s.size());
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Bigint &rhs) {
        os << (rhs.sign() < 0 ? "-" : "") << rhs.m_words.back();
        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0') << *iter;
        return os;
    }

    bool is_zero() const { return sign() == 0; }
    int sign() const { return m_sign; }
    const std::vector<int64_t> &words() const { return m_words; }
    void zeroing() {
        m_words.assign(1, 0);
        m_sign = 0;
    }
    void negation() { m_sign *= -1; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};

}  // namespace algorithm

#endif
