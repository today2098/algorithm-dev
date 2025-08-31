#ifndef ALGORITHM_MODINT_HPP
#define ALGORITHM_MODINT_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>
#include <functional>
#include <iostream>

#include "mod_inv.hpp"
#include "mod_pow.hpp"
#include "modint_base.hpp"
#include "modulo.hpp"

namespace algorithm {

template <std::int32_t mod>
class Modint : public ModintBase {
    static_assert(mod >= 1);

    std::uint32_t val;

    static constexpr std::uint32_t umod() { return mod; }

public:
    constexpr Modint() : val(0) {}
    template <std::integral Type>
    constexpr Modint(Type val) : val(::algorithm::internal::modulo(val, mod)) {}

    constexpr Modint operator+() const { return Modint(*this); }
    constexpr Modint operator-() const {
        if(val == 0) Modint();
        return raw(umod() - val);
    }
    constexpr Modint &operator++() {
        ++val;
        if(val == umod()) val = 0;
        return *this;
    }
    constexpr Modint &operator--() {
        if(val == 0) val = umod();
        --val;
        return *this;
    }
    constexpr Modint operator++(int) {
        Modint res = *this;
        ++(*this);
        return res;
    }
    constexpr Modint operator--(int) {
        Modint res = *this;
        --(*this);
        return res;
    }
    constexpr Modint &operator+=(const Modint &rhs) {
        if(rhs.val >= umod() - val) val -= umod();
        val += rhs.val;
        return *this;
    }
    constexpr Modint &operator-=(const Modint &rhs) {
        if(rhs.val > val) val += umod();
        val -= rhs.val;
        return *this;
    }
    constexpr Modint &operator*=(const Modint &rhs) {
        val = static_cast<std::uint64_t>(val) * rhs.val % umod();
        return *this;
    }
    constexpr Modint &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }

    friend constexpr bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }
    friend constexpr Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs) += rhs; }
    friend constexpr Modint operator-(const Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }
    friend constexpr Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }
    friend constexpr Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs) /= rhs; }
    friend std::istream &operator>>(std::istream &is, Modint &rhs) {
        std::int64_t val;
        is >> val;
        rhs.val = ::algorithm::internal::modulo(val, mod);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Modint &rhs) { return os << rhs.val; }

    static constexpr std::int32_t modulus() { return mod; }
    static constexpr Modint raw(std::uint32_t val) {
        Modint res;
        res.val = val;
        return res;
    }

    constexpr std::int64_t value() const { return val; }
    constexpr Modint inv() const {
        auto [x, g] = ::algorithm::internal::mod_inv(val, umod());
        assert(g == 1);
        return raw(x);
    }
    constexpr Modint pow(long long k) const {
        if(k < 0) return raw(::algorithm::internal::mod_pow(val, -k, umod())).inv();
        return raw(::algorithm::internal::mod_pow(val, k, umod()));
    }

    friend constexpr Modint mod_inv(const Modint &a) { return a.inv(); }
    friend constexpr Modint mod_pow(const Modint &a, long long k) { return a.pow(k); }
};

using mint998244353 = Modint<998'244'353>;
using mint1000000007 = Modint<1'000'000'007>;

}  // namespace algorithm

template <std::int32_t mod>
struct std::hash<algorithm::Modint<mod>> {
    std::size_t operator()(const algorithm::Modint<mod> &ob) const { return ob.value(); }
};

#endif
