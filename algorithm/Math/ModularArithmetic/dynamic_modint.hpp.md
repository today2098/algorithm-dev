---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n\
    \n\n#include <cassert>\n#include <functional>\n#include <iostream>\n#include <utility>\n\
    \n#line 1 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#include\
    \ <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <typename\
    \ T>\nstruct is_modint : std::is_base_of<ModintBase, std::remove_cv_t<std::remove_reference_t<T>>>\
    \ {};\n\ntemplate <typename T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\
    \n}  // namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/dynamic_modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint : ModintBase\
    \ {\n    static int mod;\n    long long val;\n\n    void normalize() {\n     \
    \   if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n\
    \    }\n\npublic:\n    DynamicModint() : val(0) {}\n    DynamicModint(long long\
    \ val) : val(val) {\n        normalize();\n    }\n\n    DynamicModint operator+()\
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
    \        for(; k > 0; k >>= 1) {\n            if(k & 1LL) res *= mul;\n      \
    \      mul *= mul;\n        }\n        return res;\n    }\n\n    friend DynamicModint\
    \ mod_inv(const DynamicModint &a) { return a.inv(); }\n    friend DynamicModint\
    \ mod_pow(const DynamicModint &a, long long k) { return a.pow(k); }\n};\n\ntemplate\
    \ <int id>\nint DynamicModint<id>::mod = 1'000'000'007;\n\n}  // namespace algorithm\n\
    \ntemplate <int id>\nstruct std::hash<algorithm::DynamicModint<id>> {\n    std::size_t\
    \ operator()(const algorithm::DynamicModint<id> &ob) const { return ob.value();\
    \ }\n};\n\n\n"
  code: "#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n#define ALGORITHM_DYNAMIC_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <functional>\n#include <iostream>\n#include\
    \ <utility>\n\n#include \"modint_base.hpp\"\n\nnamespace algorithm {\n\ntemplate\
    \ <int id>\nclass DynamicModint : ModintBase {\n    static int mod;\n    long\
    \ long val;\n\n    void normalize() {\n        if(val < -mod or mod <= val) val\
    \ %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n    DynamicModint()\
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
    \        for(; k > 0; k >>= 1) {\n            if(k & 1LL) res *= mul;\n      \
    \      mul *= mul;\n        }\n        return res;\n    }\n\n    friend DynamicModint\
    \ mod_inv(const DynamicModint &a) { return a.inv(); }\n    friend DynamicModint\
    \ mod_pow(const DynamicModint &a, long long k) { return a.pow(k); }\n};\n\ntemplate\
    \ <int id>\nint DynamicModint<id>::mod = 1'000'000'007;\n\n}  // namespace algorithm\n\
    \ntemplate <int id>\nstruct std::hash<algorithm::DynamicModint<id>> {\n    std::size_t\
    \ operator()(const algorithm::DynamicModint<id> &ob) const { return ob.value();\
    \ }\n};\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2025-08-10 09:02:12+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/Math/ModularArithmetic/dynamic_modint.hpp
layout: document
title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
---


## 概要

実行時に法が決まる Modint 構造体．

インスタンスを生成する前に法とする自然数を設定する．

```cpp
DynamicModint<0>::set_modulus(17);
DynamicModint<1>::set_modulus(23);

DynamicModint<0> a = 28;
DynamicModint<1> b = 28;

cout << a << " " << b << endl;  // 11 5
```
