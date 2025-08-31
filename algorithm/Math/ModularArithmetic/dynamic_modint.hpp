#ifndef ALGORITHM_DYNAMIC_MODINT_HPP
#define ALGORITHM_DYNAMIC_MODINT_HPP 1

#include <cassert>
#include <cstdint>
#include <functional>
#include <iostream>
#include <utility>

#include "mod_inv.hpp"
#include "mod_pow.hpp"
#include "modint_base.hpp"
#include "modulo.hpp"

namespace algorithm {

template <int id>
class DynamicModint : public ModintBase {
    static std::uint32_t mod;
    std::uint32_t val;

public:
    DynamicModint() : val(0) {}
    template <std::integral Type>
    DynamicModint(Type val) : val(::algorithm::internal::modulo(val, mod)) {}

    DynamicModint operator+() const { return DynamicModint(*this); }
    DynamicModint operator-() const {
        if(val == 0) DynamicModint();
        return raw(mod - val);
    }
    DynamicModint &operator++() {
        ++val;
        if(val == mod) val = 0;
        return *this;
    }
    DynamicModint &operator--() {
        if(val == 0) val = mod;
        --val;
        return *this;
    }
    DynamicModint operator++(int) {
        DynamicModint res = *this;
        ++(*this);
        return res;
    }
    DynamicModint operator--(int) {
        DynamicModint res = *this;
        --(*this);
        return res;
    }
    DynamicModint &operator+=(const DynamicModint &rhs) {
        if(rhs.val >= mod - val) val -= mod;
        val += rhs.val;
        return *this;
    }
    DynamicModint &operator-=(const DynamicModint &rhs) {
        if(rhs.val > val) val += mod;
        val -= rhs.val;
        return *this;
    }
    DynamicModint &operator*=(const DynamicModint &rhs) {
        val = static_cast<std::uint64_t>(val) * rhs.val % mod;
        return *this;
    }
    DynamicModint &operator/=(const DynamicModint &rhs) { return *this *= rhs.inv(); }

    friend bool operator==(const DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }
    friend DynamicModint operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) += rhs; }
    friend DynamicModint operator-(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }
    friend DynamicModint operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) *= rhs; }
    friend DynamicModint operator/(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }
    friend std::istream &operator>>(std::istream &is, DynamicModint &rhs) {
        std::int64_t val;
        is >> val;
        rhs.val = ::algorithm::internal::modulo(val, mod);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const DynamicModint &rhs) { return os << rhs.val; }

    static constexpr int get_id() { return id; }
    static std::int32_t modulus() { return mod; }
    static void set_modulus(std::int32_t mod) {
        assert(mod >= 1);
        DynamicModint::mod = mod;
    }
    static DynamicModint raw(std::uint32_t val) {
        DynamicModint res;
        res.val = val;
        return res;
    }

    std::int64_t value() const { return val; }
    DynamicModint inv() const {
        auto [x, g] = ::algorithm::internal::mod_inv(val, mod);
        assert(g == 1);
        return raw(x);
    }
    DynamicModint pow(long long k) const {
        if(k < 0) return raw(::algorithm::internal::mod_pow(val, -k, mod)).inv();
        return raw(::algorithm::internal::mod_pow(val, k, mod));
    }

    friend DynamicModint mod_inv(const DynamicModint &a) { return a.inv(); }
    friend DynamicModint mod_pow(const DynamicModint &a, long long k) { return a.pow(k); }
};

template <int id>
std::uint32_t DynamicModint<id>::mod = 1'000'000'007;

}  // namespace algorithm

template <int id>
struct std::hash<algorithm::DynamicModint<id>> {
    std::size_t operator()(const algorithm::DynamicModint<id> &ob) const { return ob.value(); }
};

#endif
