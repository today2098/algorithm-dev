#ifndef ALGORITHM_SIGNED_BINARY_BIGINT_HPP
#define ALGORITHM_SIGNED_BINARY_BIGINT_HPP 1

#include "binary_bigint.hpp"

namespace algorithm {

class SignedBinaryBigint : public BinaryBigint {
    int m_sign;

    explicit SignedBinaryBigint(const std::deque<uint32_t> &words, int sign) : BinaryBigint(words), m_sign(sign) {}
    explicit SignedBinaryBigint(std::deque<uint32_t> &&words, int sign) : BinaryBigint(std::move(words)), m_sign(sign) {}

    static constexpr bool validate(std::string_view sv, size_t n) {
        if(n == 0) return false;
        if(sv[0] == '+' or sv[0] == '-') return BinaryBigint::validate(sv.substr(1), n - 1);
        return BinaryBigint::validate(sv, n);
    }
    static void negate_words(std::deque<uint32_t> &words, size_t n) {
        uint32_t carry = 1;
        for(size_t i = 0; i < n; ++i) carry = store(words[i], (uint64_t)~words[i] + carry);
        while(!words.empty() and !words.back()) words.pop_back();
    }
    static int compare(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) {
        if(lhs.sign() == rhs.sign()) return BinaryBigint::compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size());
        return (lhs.sign() < rhs.sign() ? -1 : 1);
    }
    void normalize(std::string_view sv, size_t n) {
        if(sv[0] == '+') {
            BinaryBigint::normalize(sv.substr(1), n - 1);
            m_sign = (BinaryBigint::is_zero() ? 0 : 1);
        } else if(sv[0] == '-') {
            BinaryBigint::normalize(sv.substr(1), n - 1);
            m_sign = (BinaryBigint::is_zero() ? 0 : -1);
        } else {
            BinaryBigint::normalize(sv, n);
            m_sign = (BinaryBigint::is_zero() ? 0 : 1);
        }
    }

public:
    SignedBinaryBigint() : BinaryBigint(), m_sign(0) {}
    SignedBinaryBigint(int64_t n) : BinaryBigint(std::abs(n)), m_sign(0) {
        if(n == 0) return;
        m_sign = (n < 0 ? -1 : 1);
    }
    SignedBinaryBigint(const char *c) : SignedBinaryBigint(std::string_view(c)) {}
    SignedBinaryBigint(std::string_view sv) {
        std::stringstream ss;
        ss << sv;
        ss >> *this;
    }

    SignedBinaryBigint operator+() const { return SignedBinaryBigint(*this); }
    SignedBinaryBigint operator-() const {
        SignedBinaryBigint res = *this;
        res.negate();
        return res;
    }
    SignedBinaryBigint &operator+=(const SignedBinaryBigint &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = rhs;
        if(sign() * rhs.sign() < 0) {
            auto ncarry = subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
            if(ncarry) negate_words(m_words, m_words.size()), negate();
            else if(BinaryBigint::is_zero()) m_sign = 0;
        } else {
            addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        }
        return *this;
    }
    SignedBinaryBigint &operator-=(const SignedBinaryBigint &rhs) {
        if(rhs.is_zero()) return *this;
        if(is_zero()) return *this = -rhs;
        if(sign() * rhs.sign() < 0) {
            BinaryBigint::operator+=(rhs);
        } else {
            auto ncarry = subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
            if(ncarry) negate_words(m_words, m_words.size()), negate();
            else if(BinaryBigint::is_zero()) m_sign = 0;
        }
        return *this;
    }
    SignedBinaryBigint &operator*=(const SignedBinaryBigint &rhs) { return *this = (*this) * rhs; }
    SignedBinaryBigint &operator/=(const SignedBinaryBigint &rhs) {
        BinaryBigint::operator/=(rhs);
        m_sign = (BinaryBigint::is_zero() ? 0 : sign() * rhs.sign());
        return *this;
    }
    SignedBinaryBigint &operator%=(const SignedBinaryBigint &rhs) {
        BinaryBigint::operator%=(rhs);
        if(BinaryBigint::is_zero()) m_sign = 0;
        return *this;
    }
    SignedBinaryBigint &operator<<=(unsigned long long k) = delete;
    SignedBinaryBigint &operator>>=(unsigned long long k) = delete;
    SignedBinaryBigint &operator&=(const SignedBinaryBigint &rhs) = delete;
    SignedBinaryBigint &operator|=(const SignedBinaryBigint &rhs) = delete;
    SignedBinaryBigint &operator^=(const SignedBinaryBigint &rhs) = delete;

    friend bool operator==(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) { return lhs.m_words == rhs.m_words and lhs.m_sign == rhs.m_sign; }
    friend int operator<=>(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) { return compare(lhs, rhs); }
    friend SignedBinaryBigint operator+(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) { return SignedBinaryBigint(lhs) += rhs; }
    friend SignedBinaryBigint operator-(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) { return SignedBinaryBigint(lhs) -= rhs; }
    friend SignedBinaryBigint operator*(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) {
        if(lhs.is_zero() or rhs.is_zero()) return SignedBinaryBigint();
        return SignedBinaryBigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()), lhs.sign() * rhs.sign());
    }
    friend SignedBinaryBigint operator/(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) { return SignedBinaryBigint(lhs) /= rhs; }
    friend SignedBinaryBigint operator%(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) { return SignedBinaryBigint(lhs) %= rhs; }
    friend SignedBinaryBigint operator<<(const SignedBinaryBigint &lhs, unsigned long long k) = delete;
    friend SignedBinaryBigint operator>>(const SignedBinaryBigint &lhs, unsigned long long k) = delete;
    friend SignedBinaryBigint operator&(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) = delete;
    friend SignedBinaryBigint operator|(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) = delete;
    friend SignedBinaryBigint operator^(const SignedBinaryBigint &lhs, const SignedBinaryBigint &rhs) = delete;
    friend std::istream &operator>>(std::istream &is, SignedBinaryBigint &rhs) {
        std::string s;
        is >> s;
        assert(validate(s, s.size()));
        rhs.normalize(s, s.size());
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const SignedBinaryBigint &rhs) { return os << (rhs.is_minus() ? "-" : "") << static_cast<BinaryBigint>(rhs); }

    bool is_zero() const { return sign() == 0; }
    bool is_minus() const { return sign() < 0; }
    int sign() const { return m_sign; }
    SignedBinaryBigint abs() const { return SignedBinaryBigint(m_words, std::abs(sign())); }
    std::pair<SignedBinaryBigint, SignedBinaryBigint> divide(const SignedBinaryBigint &a) const {
        assert(!a.is_zero());
        auto remain = m_words;
        auto &&quotient = division(remain, remain.size(), a.m_words, a.m_words.size());
        return {SignedBinaryBigint(std::move(quotient), (quotient.empty() ? 0 : sign() * a.sign())), SignedBinaryBigint(std::move(remain), (remain.empty() ? 0 : sign()))};
    }
    void zeroize() { m_words.clear(), m_sign = 0; }
    int negate() { return m_sign *= -1; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend SignedBinaryBigint abs(const SignedBinaryBigint &a) { return a.abs(); }
};

}  // namespace algorithm

#endif
