#ifndef ALGORITHM_BIGINT_HPP
#define ALGORITHM_BIGINT_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace algorithm {

// 多倍長整数．
class Bigint {
    static constexpr int32_t BASE = 1'000'000'000;
    static constexpr size_t BASE_DIGIT = 9;

    std::vector<int32_t> m_words;
    int m_sign;

    explicit Bigint(const std::vector<int32_t> &words, int sign) : m_words(words), m_sign(sign) {}

    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }
    static constexpr bool validate(std::string_view sv) {
        size_t n = sv.size();
        if(n == 0) return false;
        if(n == 1) return isdigit(sv[0]);
        if(!(sv[0] == '+' or sv[0] == '-' or isdigit(sv[0]))) return false;
        return std::find_if_not(sv.cbegin() + 1, sv.cend(), [](char c) -> bool { return isdigit(c); }) == sv.cend();
    }
    static int32_t store(int32_t &word, int64_t val) {
        int32_t carry = val / BASE;
        word = val - (int64_t)carry * BASE;
        if(word < 0) word += BASE, --carry;
        return carry;
    }
    static int32_t add_store(int32_t &word, int64_t val) {
        if(val < 0) {
            word = val + BASE;
            return -1;
        }
        if(val < BASE) {
            word = val;
            return 0;
        }
        word = val - BASE;
        return 1;
    }
    static int compare(const Bigint &lhs, const Bigint &rhs) {
        if(lhs.sign() == rhs.sign()) return compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size());
        return (lhs.sign() < rhs.sign() ? -1 : 1);
    }
    static int compare(const std::vector<int32_t> &lhs, ssize_t n, const std::vector<int32_t> &rhs, ssize_t m) {
        if(n < m) return -1;
        if(n > m) return 1;
        for(ssize_t i = n - 1; i >= 0; --i) {
            if(lhs[i] == rhs[i]) continue;
            return (lhs[i] < rhs[i] ? -1 : 1);
        }
        return 0;
    }
    static void addition(std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        int32_t carry = 0;
        for(size_t i = 0; i < m; ++i) carry = add_store(lhs[i], (int64_t)lhs[i] + rhs[i] + carry);
        for(size_t i = m; i < n and carry != 0; ++i) carry = add_store(lhs[i], (int64_t)lhs[i] + carry);
        if(carry != 0) lhs.push_back(carry);
    }
    static int subtraction(std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {
        int sign = compare(lhs, n, rhs, m);
        if(sign == 0) {
            lhs.clear();
            return 0;
        }
        if(sign < 0) {
            lhs.resize(m, 0);
            int32_t carry = 0;
            for(size_t i = 0; i < m; ++i) carry = add_store(lhs[i], (int64_t)rhs[i] - lhs[i] + carry);
        } else {
            int32_t carry = 0;
            for(size_t i = 0; i < m; ++i) carry = add_store(lhs[i], (int64_t)lhs[i] - rhs[i] + carry);
            for(size_t i = m; i < n and carry != 0; ++i) carry = add_store(lhs[i], (int64_t)lhs[i] + carry);
        }
        while(!lhs.empty() and lhs.back() == 0) lhs.pop_back();
        return sign;
    }
    static std::vector<int32_t> multiplication(const std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {
        std::vector<int32_t> res(n + m, 0);
        for(size_t i = 0; i < n; ++i) {
            int32_t carry = 0;
            for(size_t j = 0; j < m; ++j) carry = store(res[i + j], res[i + j] + (int64_t)lhs[i] * rhs[j] + carry);
            res[i + m] = carry;
        }
        while(!res.empty() and res.back() == 0) res.pop_back();
        return res;
    }
    static std::vector<int32_t> division(std::vector<int32_t> &lhs, ssize_t n, const std::vector<int32_t> &rhs, ssize_t m) {
        assert(0 < m and m <= n);
        std::vector<int32_t> res(n - m + 1);
        auto bisearch = [&](ssize_t offset) -> int32_t {
            auto eval = [&](int32_t d) -> bool {
                int32_t carry = 0;
                for(ssize_t i = 0; i < m; ++i) {
                    int32_t tmp;
                    carry = store(tmp, lhs[i + offset] - (int64_t)rhs[i] * d + carry);
                }
                if(carry == 0) return true;
                return (m + offset < n ? lhs[m + offset] + carry >= 0 : false);
            };
            int32_t ok = 0, ng = BASE;
            while(ng - ok > 1) {
                int32_t mid = (ok + ng) / 2;
                (eval(mid) ? ok : ng) = mid;
            }
            return ok;
        };
        auto sub = [&](ssize_t offset, int32_t d) -> void {
            int32_t carry = 0;
            for(ssize_t i = 0; i < m; ++i) carry = store(lhs[i + offset], lhs[i + offset] - (int64_t)rhs[i] * d + carry);
            if(carry != 0) lhs[m + offset] += carry;
        };
        for(ssize_t i = n - m; i >= 0; --i) {
            res[i] = bisearch(i);
            sub(i, res[i]);
        }
        if(res.back() == 0) res.pop_back();
        while(!lhs.empty() and lhs.back() == 0) lhs.pop_back();
        return res;
    }
    void normalize(std::string_view sv, size_t n) {
        assert(n > 0);
        if(sv[0] == '+') {
            normalize_unsigned(sv.substr(1), n - 1);
        } else if(sv[0] == '-') {
            normalize_unsigned(sv.substr(1), n - 1);
            negation();
        } else {
            normalize_unsigned(sv, n);
        }
    }
    void normalize_unsigned(std::string_view sv, size_t n) {
        size_t m = (n + BASE_DIGIT - 1) / BASE_DIGIT;
        m_words.assign(m, 0);
        auto iter = sv.crbegin();
        for(size_t i = 0; i < m; ++i) {
            int32_t d = 1;
            for(size_t j = 0; j < BASE_DIGIT and iter < sv.crend(); ++j, ++iter, d *= 10) m_words[i] += (*iter - '0') * d;
        }
        while(!m_words.empty() and m_words.back() == 0) m_words.pop_back();
        m_sign = (m_words.empty() ? 0 : 1);
    }

public:
    Bigint() : m_words(), m_sign(0) {};
    Bigint(int64_t n) : Bigint() {
        if(n == 0) return;
        if(n < 0) n *= -1, m_sign = -1;
        else m_sign = 1;
        while(n > 0) {
            int32_t word;
            n = store(word, n);
            m_words.push_back(word);
        }
    }
    Bigint(const char *c) : Bigint(std::string_view(c)) {}
    Bigint(std::string_view s) {
        std::stringstream ss;
        ss << s;
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
        if(sign() == rhs.sign()) addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        else m_sign *= subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    Bigint &operator-=(const Bigint &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = -rhs;
        if(sign() == rhs.sign()) m_sign *= subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        else addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        return *this;
    }
    Bigint &operator*=(const Bigint &rhs) { return *this = (*this) * rhs; }
    Bigint &operator/=(const Bigint &rhs) {
        assert(!rhs.is_zero());
        if(is_zero()) return *this;
        m_words = division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        m_sign = sign() * rhs.sign();
        return *this;
    }
    Bigint &operator%=(const Bigint &rhs) {
        assert(!rhs.is_zero());
        if(is_zero()) return *this;
        division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        if(m_words.empty()) m_sign = 0;
        return *this;
    }

    friend bool operator==(const Bigint &lhs, const Bigint &rhs) { return lhs.sign() == rhs.sign() and lhs.m_words == rhs.m_words; }
    friend int operator<=>(const Bigint &lhs, const Bigint &rhs) { return compare(lhs, rhs); }
    friend Bigint operator+(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs; }
    friend Bigint operator-(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) -= rhs; }
    friend Bigint operator*(const Bigint &lhs, const Bigint &rhs) {
        if(lhs.is_zero() or rhs.is_zero()) return Bigint();
        return Bigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()), lhs.sign() * rhs.sign());
    }
    friend Bigint operator/(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) /= rhs; }
    friend Bigint operator%(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) %= rhs; }
    friend std::istream &operator>>(std::istream &is, Bigint &rhs) {
        std::string s;
        is >> s;
        assert(validate(s));
        rhs.normalize(s, s.size());
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Bigint &rhs) {
        if(rhs.is_zero()) return os << 0;
        os << (rhs.is_minus() ? "-" : "") << rhs.m_words.back();
        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0') << *iter;
        return os;
    }

    bool is_zero() const { return sign() == 0; }
    bool is_minus() const { return sign() < 0; }
    int sign() const { return m_sign; }
    Bigint abs() const { return Bigint(m_words, std::abs(sign())); }
    std::pair<Bigint, Bigint> divide(const Bigint &a) const {
        assert(!a.is_zero());
        if(is_zero()) return {Bigint(), Bigint()};
        auto remain = m_words;
        auto &&quotient = division(remain, remain.size(), a.m_words, a.m_words.size());
        return {Bigint(std::move(quotient), (quotient.empty() ? 0 : sign() * a.sign())), Bigint(std::move(remain), (remain.empty() ? 0 : sign()))};
    }
    void zeroize() {
        m_words.clear();
        m_sign = 0;
    }
    void negation() { m_sign *= -1; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    const std::vector<int32_t> &words() const { return m_words; }

    friend Bigint abs(const Bigint &a) { return a.abs(); }
};

}  // namespace algorithm

#endif
