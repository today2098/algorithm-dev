---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: algorithm/Math/ModularArithmetic/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n\
    \n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\n#line 1 \"\
    algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#include <type_traits>\n\
    \nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint\
    \ = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr bool\
    \ is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n\n#line 9\
    \ \"algorithm/Math/ModularArithmetic/dynamic_modint.hpp\"\n\nnamespace algorithm\
    \ {\n\ntemplate <int id>\nclass DynamicModint : ModintBase {\n    static int mod;\n\
    \    long long val;\n\n    void normalize() {\n        if(val < -mod or mod <=\
    \ val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n    DynamicModint()\
    \ : val(0) {}\n    DynamicModint(long long val) : val(val) {\n        normalize();\n\
    \    }\n\n    DynamicModint operator+() const { return DynamicModint(*this); }\n\
    \    DynamicModint operator-() const {\n        if(val == 0) DynamicModint();\n\
    \        DynamicModint res = *this;\n        res.val = mod - res.val;\n      \
    \  return res;\n    }\n    DynamicModint &operator++() {\n        val++;\n   \
    \     if(val == mod) val = 0;\n        return *this;\n    }\n    DynamicModint\
    \ &operator--() {\n        if(val == 0) val = mod;\n        val--;\n        return\
    \ *this;\n    }\n    DynamicModint operator++(int) {\n        DynamicModint res\
    \ = *this;\n        ++(*this);\n        return res;\n    }\n    DynamicModint\
    \ operator--(int) {\n        DynamicModint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    DynamicModint &operator+=(const DynamicModint\
    \ &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n     \
    \   return *this;\n    }\n    DynamicModint &operator-=(const DynamicModint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    DynamicModint &operator*=(const DynamicModint &rhs) {\n \
    \       val = val * rhs.val % mod;\n        return *this;\n    }\n    DynamicModint\
    \ &operator/=(const DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n   \
    \ friend bool operator==(const DynamicModint &lhs, const DynamicModint &rhs) {\
    \ return lhs.val == rhs.val; }\n    friend DynamicModint operator+(const DynamicModint\
    \ &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) += rhs; }\n    friend\
    \ DynamicModint operator-(const DynamicModint &lhs, const DynamicModint &rhs)\
    \ { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint operator*(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) *=\
    \ rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const DynamicModint\
    \ &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n\
    \        return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const DynamicModint &rhs) { return os << rhs.val; }\n\n    static constexpr\
    \ int get_id() { return id; }\n    static int modulus() { return mod; }\n    static\
    \ void set_modulus(int mod) {\n        assert(mod >= 1);\n        DynamicModint::mod\
    \ = mod;\n    }\n    long long value() const { return val; }\n    DynamicModint\
    \ inv() const {\n        long long a = mod, b = val, u = 0, v = 1;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ DynamicModint(u);\n    }\n    DynamicModint pow(long long k) const {\n     \
    \   if(k < 0) return inv().pow(-k);\n        DynamicModint res = 1, mul = *this;\n\
    \        while(k > 0) {\n            if(k & 1LL) res *= mul;\n            mul\
    \ *= mul;\n            k >>= 1;\n        }\n        return res;\n    }\n\n   \
    \ friend DynamicModint mod_inv(const DynamicModint &a) { return a.inv(); }\n \
    \   friend DynamicModint mod_pow(const DynamicModint &a, long long k) { return\
    \ a.pow(k); }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod = 1'000'000'007;\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n#define ALGORITHM_DYNAMIC_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\n#include\
    \ \"modint_base.hpp\"\n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint\
    \ : ModintBase {\n    static int mod;\n    long long val;\n\n    void normalize()\
    \ {\n        if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val\
    \ += mod;\n    }\n\npublic:\n    DynamicModint() : val(0) {}\n    DynamicModint(long\
    \ long val) : val(val) {\n        normalize();\n    }\n\n    DynamicModint operator+()\
    \ const { return DynamicModint(*this); }\n    DynamicModint operator-() const\
    \ {\n        if(val == 0) DynamicModint();\n        DynamicModint res = *this;\n\
    \        res.val = mod - res.val;\n        return res;\n    }\n    DynamicModint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    DynamicModint &operator--() {\n        if(val == 0) val =\
    \ mod;\n        val--;\n        return *this;\n    }\n    DynamicModint operator++(int)\
    \ {\n        DynamicModint res = *this;\n        ++(*this);\n        return res;\n\
    \    }\n    DynamicModint operator--(int) {\n        DynamicModint res = *this;\n\
    \        --(*this);\n        return res;\n    }\n    DynamicModint &operator+=(const\
    \ DynamicModint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -=\
    \ mod;\n        return *this;\n    }\n    DynamicModint &operator-=(const DynamicModint\
    \ &rhs) {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    DynamicModint &operator*=(const DynamicModint &rhs) {\n \
    \       val = val * rhs.val % mod;\n        return *this;\n    }\n    DynamicModint\
    \ &operator/=(const DynamicModint &rhs) { return *this *= rhs.inv(); }\n\n   \
    \ friend bool operator==(const DynamicModint &lhs, const DynamicModint &rhs) {\
    \ return lhs.val == rhs.val; }\n    friend DynamicModint operator+(const DynamicModint\
    \ &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) += rhs; }\n    friend\
    \ DynamicModint operator-(const DynamicModint &lhs, const DynamicModint &rhs)\
    \ { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint operator*(const\
    \ DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs) *=\
    \ rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const DynamicModint\
    \ &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, DynamicModint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n\
    \        return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const DynamicModint &rhs) { return os << rhs.val; }\n\n    static constexpr\
    \ int get_id() { return id; }\n    static int modulus() { return mod; }\n    static\
    \ void set_modulus(int mod) {\n        assert(mod >= 1);\n        DynamicModint::mod\
    \ = mod;\n    }\n    long long value() const { return val; }\n    DynamicModint\
    \ inv() const {\n        long long a = mod, b = val, u = 0, v = 1;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ DynamicModint(u);\n    }\n    DynamicModint pow(long long k) const {\n     \
    \   if(k < 0) return inv().pow(-k);\n        DynamicModint res = 1, mul = *this;\n\
    \        while(k > 0) {\n            if(k & 1LL) res *= mul;\n            mul\
    \ *= mul;\n            k >>= 1;\n        }\n        return res;\n    }\n\n   \
    \ friend DynamicModint mod_inv(const DynamicModint &a) { return a.inv(); }\n \
    \   friend DynamicModint mod_pow(const DynamicModint &a, long long k) { return\
    \ a.pow(k); }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod = 1'000'000'007;\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
layout: document
redirect_from:
- /library/algorithm/Math/ModularArithmetic/dynamic_modint.hpp
- /library/algorithm/Math/ModularArithmetic/dynamic_modint.hpp.html
title: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
---
