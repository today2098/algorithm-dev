#ifndef ALGORITHM_DYNAMIC_MODINT_HPP
#define ALGORITHM_DYNAMIC_MODINT_HPP 1

#include <cassert>
#include <iostream>
#include <utility>

#include "modint_base.hpp"

namespace algorithm {

template <int id>
class DynamicModint : ModintBase {
    static int mod;
    long long val;

    void normalize() {
        if(val < -mod or mod <= val) val %= mod;
        if(val < 0) val += mod;
    }

public:
    DynamicModint() : DynamicModint(0) {}
    DynamicModint(long long val) : val(val) {
        assert(mod >= 1);
        normalize();
    }

    DynamicModint operator+() const { return DynamicModint(*this); }
    DynamicModint operator-() const { return (val == 0 ? DynamicModint(*this) : DynamicModint(mod - val)); }
    DynamicModint &operator++() {
        val++;
        if(val == mod) val = 0;
        return *this;
    }
    DynamicModint &operator--() {
        if(val == 0) val = mod;
        val--;
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
        val += rhs.val;
        if(val >= mod) val -= mod;
        return *this;
    }
    DynamicModint &operator-=(const DynamicModint &rhs) {
        val -= rhs.val;
        if(val < 0) val += mod;
        return *this;
    }
    DynamicModint &operator*=(const DynamicModint &rhs) {
        val = val * rhs.val % mod;
        return *this;
    }
    DynamicModint &operator/=(const DynamicModint &rhs) { return *this *= rhs.inv(); }

    friend bool operator==(const DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val == rhs.val; }
    friend bool operator!=(const DynamicModint &lhs, const DynamicModint &rhs) { return lhs.val != rhs.val; }
    friend DynamicModint operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) += rhs; }
    friend DynamicModint operator-(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }
    friend DynamicModint operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) *= rhs; }
    friend DynamicModint operator/(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }
    friend std::istream &operator>>(std::istream &is, DynamicModint &rhs) {
        is >> rhs.val;
        rhs.normalize();
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const DynamicModint &rhs) { return os << rhs.val; }

    static constexpr int get_id() { return id; }
    static int modulus() { return mod; }
    static void set_modulus(int mod) {
        assert(mod >= 1);
        DynamicModint::mod = mod;
    }
    long long value() const { return val; }
    DynamicModint inv() const {
        long long a = mod, b = val, u = 0, v = 1;
        while(b != 0) {
            long long t = a / b;
            a -= b * t, u -= v * t;
            std::swap(a, b), std::swap(u, v);
        }
        return DynamicModint(u);
    }
    DynamicModint pow(long long k) const {
        if(k < 0) return inv().pow(-k);
        DynamicModint res = 1, mul = *this;
        while(k > 0) {
            if(k & 1LL) res *= mul;
            mul *= mul;
            k >>= 1;
        }
        return res;
    }

    friend DynamicModint mod_inv(const DynamicModint &a) { return a.inv(); }
    friend DynamicModint mod_pow(const DynamicModint &a, long long k) { return a.pow(k); }
};

template <int id>
int DynamicModint<id>::mod = 1'000'000'007;

}  // namespace algorithm

#endif
