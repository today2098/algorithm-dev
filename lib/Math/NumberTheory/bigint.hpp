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
    bool m_neg;

    explicit Bigint(const std::vector<int32_t> &words, bool neg) : m_words(words), m_neg(neg) {}
    explicit Bigint(std::vector<int32_t> &&words, bool neg) : m_words(std::move(words)), m_neg(neg) {}

    static constexpr bool isdigit(char c) { return '0' <= c and c <= '9'; }
    static constexpr bool validate(std::string_view sv, size_t n) {
        if(n == 0) return false;
        if(sv[0] == '+' or sv[0] == '-') return validate_words(sv.substr(1), n - 1);
        return validate_words(sv, n);
    }
    static constexpr bool validate_words(std::string_view sv, size_t n) {
        if(n == 0) return false;
        return std::find_if_not(sv.cbegin(), sv.cend(), [](char c) -> bool { return isdigit(c); }) == sv.cend();
    }
    static int compare(const Bigint &lhs, const Bigint &rhs) {
        if(lhs.isnegative() ^ rhs.isnegative()) return (lhs.isnegative() ? -1 : 1);
        return compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size());
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
    static int32_t add_store(int32_t &word, int32_t val) {
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
    static int32_t store(int32_t &word, int64_t val) {
        int32_t carry = val / BASE;
        word = val - (int64_t)carry * BASE;
        if(word < 0) word += BASE, --carry;
        return carry;
    }
    static void negation(std::vector<int32_t> &words) {
        int32_t ncarry = 0;
        for(int32_t &word : words) ncarry = add_store(word, -word + ncarry);
    }
    static size_t shrink(std::vector<int32_t> &words) {
        while(!words.empty() and words.back() == 0) words.pop_back();
        return words.size();
    }
    static void addition(std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        int32_t carry = 0;
        for(size_t i = 0; i < m; ++i) carry = add_store(lhs[i], lhs[i] + rhs[i] + carry);
        for(size_t i = m; i < n and carry > 0; ++i) carry = add_store(lhs[i], lhs[i] + carry);
        if(carry > 0) lhs.push_back(carry);
    }
    static bool subtraction(std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        int32_t ncarry = 0;
        for(size_t i = 0; i < m; ++i) ncarry = add_store(lhs[i], lhs[i] - rhs[i] + ncarry);
        for(size_t i = m; i < n and ncarry < 0; ++i) ncarry = add_store(lhs[i], lhs[i] + ncarry);
        if(ncarry < 0) negation(lhs);
        shrink(lhs);
        return ncarry < 0;
    }
    static std::vector<int32_t> multiplication(const std::vector<int32_t> &lhs, size_t n, const std::vector<int32_t> &rhs, size_t m) {
        std::vector<int32_t> res(n + m, 0);
        for(size_t i = 0; i < n; ++i) {
            int32_t carry = 0;
            for(size_t j = 0; j < m; ++j) carry = store(res[i + j], res[i + j] + (int64_t)lhs[i] * rhs[j] + carry);
            res[i + m] = carry;
        }
        shrink(res);
        return res;
    }
    static std::vector<int32_t> division(std::vector<int32_t> &lhs, ssize_t n, const std::vector<int32_t> &rhs, ssize_t m) {
        assert(m > 0);
        if(n < m) return {};
        std::vector<int32_t> res(n - m + 1);
        auto bisearch = [&](ssize_t offset) -> int32_t {
            if(n - offset < m) return 0;
            auto eval = [&](int32_t d) -> bool {
                int32_t carry = 0;
                for(size_t i = 0; i < m; ++i) {
                    int32_t tmp;
                    carry = store(tmp, lhs[i + offset] - (int64_t)d * rhs[i] + carry);
                }
                return (m + offset < n ? lhs.back() : 0) + carry >= 0;
            };
            int32_t ok = 0, ng = BASE;
            while(ng - ok > 1) {
                int32_t mid = ok + (ng - ok) / 2;
                (eval(mid) ? ok : ng) = mid;
            }
            return ok;
        };
        auto sub = [&](size_t offset, int32_t d) -> void {
            int32_t ncarry = 0;
            for(size_t i = 0; i < m; ++i) ncarry = store(lhs[i + offset], lhs[i + offset] - (int64_t)d * rhs[i] + ncarry);
            if(m + offset < n) lhs.pop_back(), --n;
            n = shrink(lhs);
        };
        for(ssize_t i = n - m; i >= 0; --i) {
            res[i] = bisearch(i);
            if(res[i] > 0) sub(i, res[i]);
        }
        if(res.back() == 0) res.pop_back();
        return res;
    }
    void normalize(std::string_view sv, size_t n) {
        assert(n > 0);
        if(sv[0] == '+') {
            normalize_words(sv.substr(1), n - 1);
            m_neg = false;
        } else if(sv[0] == '-') {
            normalize_words(sv.substr(1), n - 1);
            m_neg = !m_words.empty();
        } else {
            normalize_words(sv, n);
            m_neg = false;
        }
    }
    void normalize_words(std::string_view sv, size_t n) {
        size_t m = (n + BASE_DIGIT - 1) / BASE_DIGIT;
        m_words.assign(m, 0);
        auto iter = sv.crbegin();
        for(size_t i = 0; i < m; ++i) {
            int32_t d = 1;
            for(size_t j = 0; j < BASE_DIGIT and iter < sv.crend(); ++j, ++iter, d *= 10) m_words[i] += (*iter - '0') * d;
        }
        shrink(m_words);
    }

public:
    Bigint() : m_words(), m_neg(false) {};
    Bigint(int64_t n) : Bigint() {
        m_neg = (n < 0);
        n = std::abs(n);
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
        res.negate();
        return res;
    }
    Bigint &operator+=(const Bigint &rhs) {
        if(isnegative() ^ rhs.isnegative()) {
            m_neg ^= subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
            if(m_words.empty()) m_neg = false;
        } else {
            addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        }
        return *this;
    }
    Bigint &operator-=(const Bigint &rhs) {
        if(isnegative() ^ rhs.isnegative()) {
            addition(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        } else {
            m_neg ^= subtraction(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
            if(m_words.empty()) m_neg = false;
        }
        return *this;
    }
    Bigint &operator*=(const Bigint &rhs) { return *this = (*this) * rhs; }
    Bigint &operator/=(const Bigint &rhs) {
        assert(!rhs.iszero());
        m_words = division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        m_neg = (m_words.empty() ? false : isnegative() ^ rhs.isnegative());
        return *this;
    }
    Bigint &operator%=(const Bigint &rhs) {
        assert(!rhs.iszero());
        division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        if(m_words.empty()) m_neg = false;
        return *this;
    }

    friend bool operator==(const Bigint &lhs, const Bigint &rhs) { return lhs.m_words == rhs.m_words and lhs.isnegative() == rhs.isnegative(); }
    friend int operator<=>(const Bigint &lhs, const Bigint &rhs) { return compare(lhs, rhs); }
    friend Bigint operator+(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs; }
    friend Bigint operator-(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) -= rhs; }
    friend Bigint operator*(const Bigint &lhs, const Bigint &rhs) {
        if(lhs.iszero() or rhs.iszero()) return Bigint();
        return Bigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()), lhs.isnegative() ^ rhs.isnegative());
    }
    friend Bigint operator/(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) /= rhs; }
    friend Bigint operator%(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) %= rhs; }
    friend std::istream &operator>>(std::istream &is, Bigint &rhs) {
        std::string s;
        is >> s;
        assert(validate(s, s.size()));
        rhs.normalize(s, s.size());
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Bigint &rhs) {
        if(rhs.iszero()) return os << 0;
        os << (rhs.isnegative() ? "-" : "") << rhs.m_words.back();
        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0') << *iter;
        return os;
    }

    bool iszero() const { return m_words.empty(); }
    bool isnegative() const { return m_neg; }
    int sign() const {
        if(iszero()) return 0;
        return (isnegative() ? -1 : 1);
    }
    Bigint abs() const { return Bigint(m_words, false); }
    std::pair<Bigint, Bigint> divide(const Bigint &a) const {
        assert(!a.iszero());
        auto remain = m_words;
        auto &&quotient = division(remain, remain.size(), a.m_words, a.m_words.size());
        Bigint q(std::move(quotient), false), r(std::move(remain), false);
        if(!q.iszero()) q.m_neg = isnegative() ^ a.isnegative();
        if(!r.iszero()) q.m_neg = isnegative();
        return {q, r};
    }
    void zeroize() {
        m_words.clear();
        m_neg = false;
    }
    void negate() { m_neg = !m_neg; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    const std::vector<int32_t> &words() const { return m_words; }
};

}  // namespace algorithm

#endif
