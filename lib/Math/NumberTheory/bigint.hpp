#ifndef ALGORITHM_BIGINT_HPP
#define ALGORITHM_BIGINT_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace algorithm {

// 多倍長整数．
class Bigint {
    static constexpr int64_t BASE = 1'000'000'000;
    static constexpr size_t BASE_DIGIT = 9;

    std::vector<int64_t> m_words;
    int m_sign;

    explicit Bigint(const std::vector<int64_t> &words, int sign) : m_words(words), m_sign(sign) {}

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
            return (lhs[i] < rhs[i] ? -1 : 1);
        }
        return 0;
    }
    static void addition(std::vector<int64_t> &lhs, size_t n, const std::vector<int64_t> &rhs, size_t m) {
        n = std::max(n, m);
        lhs.resize(n + 1, 0);
        for(size_t i = 0; i < m; ++i) {
            lhs[i] += rhs[i];
            if(lhs[i] >= BASE) lhs[i] -= BASE, lhs[i + 1]++;  // carry.
        }
        for(size_t i = m; i < n; ++i) {
            if(lhs[i] < BASE) break;
            lhs[i] -= BASE, lhs[i + 1]++;  // carry.
        }
        if(lhs.back() == 0) lhs.pop_back();
    }
    static int subtraction(std::vector<int64_t> &lhs, ssize_t n, const std::vector<int64_t> &rhs, ssize_t m) {
        n = std::max(n, m);
        lhs.resize(n, 0);
        for(ssize_t i = 0; i < m; ++i) lhs[i] -= rhs[i];
        int sign = 0;
        for(ssize_t i = n - 1; i >= 0; --i) {
            if(lhs[i] == 0) continue;
            sign = (lhs[i] < 0 ? -1 : 1);
            break;
        }
        for(int64_t &word : lhs) word *= sign;
        for(ssize_t i = 0; i < n - 1; ++i) {
            if(lhs[i] < 0) lhs[i] += BASE, lhs[i + 1]--;  // carry.
        }
        while(!lhs.empty() and lhs.back() == 0) lhs.pop_back();
        return sign;
    }
    static std::vector<int64_t> multiplication(const std::vector<int64_t> &lhs, size_t n, const std::vector<int64_t> &rhs, size_t m) {
        std::vector<int64_t> res(n + m, 0);
        for(size_t i = 0; i < n; ++i) {
            for(size_t j = 0; j < m; ++j) {
                res[i + j] += lhs[i] * rhs[j];
                int64_t c = res[i + j] / BASE;
                res[i + j] -= c * BASE, res[i + j + 1] += c;  // carry.
            }
        }
        while(!res.empty() and res.back() == 0) res.pop_back();
        return res;
    }
    static std::pair<std::vector<int64_t>, std::deque<int64_t> > division(const std::vector<int64_t> &lhs, ssize_t n, const std::vector<int64_t> &rhs, ssize_t m) {
        assert(0 < m and m <= n);
        std::vector<int64_t> quotient(n - m + 1);
        std::deque<int64_t> remain(lhs.cend() - m, lhs.cend());
        auto bisearch = [&remain, &rhs, m]() -> int64_t {
            auto compare = [](const std::deque<int64_t> &remain, std::vector<int64_t> rhs, ssize_t m, int64_t d) -> int {
                for(ssize_t i = 0; i < m; ++i) rhs[i] *= d;
                for(ssize_t i = 0; i < m - 1; ++i) {
                    int64_t c = rhs[i] / BASE;
                    rhs[i] -= c * BASE, rhs[i + 1] += c;
                }
                for(ssize_t i = m - 1; i >= 0; --i) {
                    if(remain[i] == rhs[i]) continue;
                    return (remain[i] < rhs[i] ? -1 : 1);
                }
                return 0;
            };
            int64_t ok = 0, ng = BASE;
            while(ng - ok > 1) {
                int64_t mid = ok + (ng - ok) / 2;
                (compare(remain, rhs, m, mid) >= 0 ? ok : ng) = mid;
            }
            return ok;
        };
        for(ssize_t i = n - m; i >= 0; --i) {
            quotient[i] = bisearch();
            for(ssize_t j = 0; j < m; ++j) {
                remain[j] -= quotient[i] * rhs[j];
                if(j == m - 1) break;
                int64_t c = (-remain[j] + BASE - 1) / BASE;
                remain[j] += c * BASE, remain[j + 1] -= c;  // carry.
            }
            if(i == 0) break;
            remain.push_front(lhs[i - 1]);
            remain[m - 1] += remain[m] * BASE;
            remain.pop_back();
        }
        if(quotient.back() == 0) quotient.pop_back();
        while(!remain.empty() and remain.back() == 0) remain.pop_back();
        return {quotient, remain};
    }
    void normalize(std::string_view sv, size_t n) {
        assert(n > 0);
        if(sv[0] == '+') {
            normalize_without_sign(sv.substr(1), n - 1);
        } else if(sv[0] == '-') {
            normalize_without_sign(sv.substr(1), n - 1);
            negation();
        } else {
            normalize_without_sign(sv, n);
        }
    }
    void normalize_without_sign(std::string_view sv, size_t n) {
        if(sv == "0") {
            zeroize();
            return;
        }
        size_t m = (n + BASE_DIGIT - 1) / BASE_DIGIT;
        m_words.assign(m, 0);
        auto iter = sv.crbegin();
        for(size_t i = 0; i < m; ++i) {
            int64_t d = 1;
            for(size_t j = 0; j < BASE_DIGIT; ++j) {
                if(iter >= sv.crend()) break;
                m_words[i] += (*iter - '0') * d;
                iter++, d *= 10;
            }
        }
        while(!m_words.empty() and m_words.back() == 0) m_words.pop_back();
        m_sign = (m_words.empty() ? 0 : 1);
    }

public:
    Bigint() : m_sign(0) {};
    Bigint(int64_t n) : m_words({n}), m_sign(1) {
        if(n == 0) {
            zeroize();
            return;
        }
        if(n < 0) m_words[0] *= -1, m_sign = -1;
        while(m_words.back() >= BASE) {
            int64_t c = m_words.back() / BASE;
            m_words.back() -= c * BASE;
            m_words.push_back(c);  // carry.
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
    Bigint &operator/=(const Bigint &rhs) { return *this = (*this) / rhs; }
    Bigint &operator%=(const Bigint &rhs) {
        assert(!rhs.is_zero());
        int cmp = compare(m_words, m_words.size(), rhs.m_words, rhs.m_words.size());
        if(cmp < 0) return *this;
        if(cmp == 0) {
            zeroize();
            return *this;
        }
        auto &&remain = division(m_words, m_words.size(), rhs.m_words, rhs.m_words.size()).second;
        if(remain.empty()) zeroize();
        else m_words.assign(remain.cbegin(), remain.cend());
        return *this;
    }

    friend bool operator==(const Bigint &lhs, const Bigint &rhs) { return lhs.sign() == rhs.sign() and lhs.m_words == rhs.m_words; }
    friend bool operator!=(const Bigint &lhs, const Bigint &rhs) { return !(lhs == rhs); }
    friend int operator<=>(const Bigint &lhs, const Bigint &rhs) { return compare(lhs, rhs); }
    friend Bigint operator+(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) += rhs; }
    friend Bigint operator-(const Bigint &lhs, const Bigint &rhs) { return Bigint(lhs) -= rhs; }
    friend Bigint operator*(const Bigint &lhs, const Bigint &rhs) {
        if(lhs.is_zero() or rhs.is_zero()) return zero();
        return Bigint(multiplication(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()), lhs.sign() * rhs.sign());
    }
    friend Bigint operator/(const Bigint &lhs, const Bigint &rhs) {
        assert(!rhs.is_zero());
        int cmp = compare(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size());
        if(cmp < 0) return zero();
        if(cmp == 0) return Bigint({1}, lhs.sign() * rhs.sign());
        return Bigint(division(lhs.m_words, lhs.m_words.size(), rhs.m_words, rhs.m_words.size()).first, lhs.sign() * rhs.sign());
    }
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
        os << (rhs.sign() < 0 ? "-" : "") << rhs.m_words.back();
        for(auto iter = rhs.m_words.crbegin() + 1; iter < rhs.m_words.crend(); ++iter) os << std::setw(BASE_DIGIT) << std::setfill('0') << *iter;
        return os;
    }

    static Bigint zero() { return Bigint({}, 0); }
    static Bigint one() { return Bigint({1}, 1); }
    bool is_zero() const { return sign() == 0; }
    bool is_minus() const { return sign() < 0; }
    Bigint abs() const { return Bigint(m_words, std::abs(sign())); }
    std::pair<Bigint, Bigint> divide(const Bigint &a) const {
        assert(!a.is_zero());
        int cmp = compare(m_words, m_words.size(), a.m_words, a.m_words.size());
        if(cmp < 0) return {zero(), *this};
        if(cmp == 0) return {Bigint({1}, sign() * a.sign()), zero()};
        auto &&[quotient, remain] = division(m_words, m_words.size(), a.m_words, a.m_words.size());
        return {Bigint(std::move(quotient), sign() * a.sign()), Bigint(std::vector<int64_t>(remain.cbegin(), remain.cend()), (remain.empty() ? 0 : sign()))};
    }
    Bigint pow(long long k) const {
        assert(k >= 0);
        Bigint res = 1, mul = *this;
        while(k > 0) {
            if(k & 1LL) res *= mul;
            mul *= mul;
            k >>= 1;
        }
        return res;
    }
    void zeroize() {
        m_words.clear();
        m_sign = 0;
    }
    void negation() { m_sign *= -1; }
    int sign() const { return m_sign; }
    const std::vector<int64_t> &words() const { return m_words; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend Bigint abs(const Bigint &a) { return a.abs(); }
    friend Bigint pow(Bigint a, long long k) { return a.pow(k); }
};

}  // namespace algorithm

#endif
