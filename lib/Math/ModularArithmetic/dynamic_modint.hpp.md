---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/ModularArithmetic/dynamic_modint.md
    document_title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
    links: []
  bundledCode: "#line 1 \"lib/Math/ModularArithmetic/dynamic_modint.hpp\"\n\n\n\n\
    /**\n * @brief \u52D5\u7684Modint\u69CB\u9020\u4F53\n * @docs docs/Math/ModularArithmetic/dynamic_modint.md\n\
    \ */\n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\n#line 1\
    \ \"lib/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n/**\n * @brief Modint\u69CB\
    \u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9\n * @docs docs/Math/ModularArithmetic/modint_base.md\n\
    \ */\n\n#include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\
    \ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate\
    \ <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\n}  //\
    \ namespace algorithm\n\n\n#line 14 \"lib/Math/ModularArithmetic/dynamic_modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint : ModintBase\
    \ {\n    static int mod;\n    long long val;\n\n    void normalize() {\n     \
    \   if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n\
    \    }\n\npublic:\n    DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long\
    \ long val_) : val(val_) {\n        assert(mod >= 1);\n        normalize();\n\
    \    }\n\n    DynamicModint operator+() const { return DynamicModint(*this); }\n\
    \    DynamicModint operator-() const { return (val == 0 ? DynamicModint(*this)\
    \ : DynamicModint(mod - val)); }\n    DynamicModint &operator++() {\n        val++;\n\
    \        if(val == mod) val = 0;\n        return *this;\n    }\n    DynamicModint\
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
    \ return lhs.val == rhs.val; }\n    friend bool operator!=(const DynamicModint\
    \ &lhs, const DynamicModint &rhs) { return lhs.val != rhs.val; }\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend std::istream\
    \ &operator>>(std::istream &is, DynamicModint &rhs) {\n        is >> rhs.val;\n\
    \        rhs.normalize();\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const DynamicModint &rhs) { return os << rhs.val;\
    \ }\n\n    static constexpr int get_id() { return id; }\n    static void set_modulus(int\
    \ mod_) {\n        assert(mod_ >= 1);\n        mod = mod_;\n    }\n    static\
    \ int modulus() { return mod; }\n    long long value() const { return val; }\n\
    \    DynamicModint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return DynamicModint(u);\n    }\n    DynamicModint pow(long\
    \ long k) const {\n        if(k < 0) return inv().pow(-k);\n        DynamicModint\
    \ res = 1, mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *=\
    \ mul;\n            mul *= mul;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    friend DynamicModint mod_inv(const DynamicModint &a) { return\
    \ a.inv(); }\n    friend DynamicModint mod_pow(const DynamicModint &a, long long\
    \ k) { return a.pow(k); }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod\
    \ = 1'000'000'007;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DYNAMIC_MODINT_HPP\n#define ALGORITHM_DYNAMIC_MODINT_HPP\
    \ 1\n\n/**\n * @brief \u52D5\u7684Modint\u69CB\u9020\u4F53\n * @docs docs/Math/ModularArithmetic/dynamic_modint.md\n\
    \ */\n\n#include <cassert>\n#include <iostream>\n#include <utility>\n\n#include\
    \ \"modint_base.hpp\"\n\nnamespace algorithm {\n\ntemplate <int id>\nclass DynamicModint\
    \ : ModintBase {\n    static int mod;\n    long long val;\n\n    void normalize()\
    \ {\n        if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val\
    \ += mod;\n    }\n\npublic:\n    DynamicModint() : DynamicModint(0) {}\n    DynamicModint(long\
    \ long val_) : val(val_) {\n        assert(mod >= 1);\n        normalize();\n\
    \    }\n\n    DynamicModint operator+() const { return DynamicModint(*this); }\n\
    \    DynamicModint operator-() const { return (val == 0 ? DynamicModint(*this)\
    \ : DynamicModint(mod - val)); }\n    DynamicModint &operator++() {\n        val++;\n\
    \        if(val == mod) val = 0;\n        return *this;\n    }\n    DynamicModint\
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
    \ return lhs.val == rhs.val; }\n    friend bool operator!=(const DynamicModint\
    \ &lhs, const DynamicModint &rhs) { return lhs.val != rhs.val; }\n    friend DynamicModint\
    \ operator+(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ += rhs; }\n    friend DynamicModint operator-(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) -= rhs; }\n    friend DynamicModint\
    \ operator*(const DynamicModint &lhs, const DynamicModint &rhs) { return DynamicModint(lhs)\
    \ *= rhs; }\n    friend DynamicModint operator/(const DynamicModint &lhs, const\
    \ DynamicModint &rhs) { return DynamicModint(lhs) /= rhs; }\n    friend std::istream\
    \ &operator>>(std::istream &is, DynamicModint &rhs) {\n        is >> rhs.val;\n\
    \        rhs.normalize();\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const DynamicModint &rhs) { return os << rhs.val;\
    \ }\n\n    static constexpr int get_id() { return id; }\n    static void set_modulus(int\
    \ mod_) {\n        assert(mod_ >= 1);\n        mod = mod_;\n    }\n    static\
    \ int modulus() { return mod; }\n    long long value() const { return val; }\n\
    \    DynamicModint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return DynamicModint(u);\n    }\n    DynamicModint pow(long\
    \ long k) const {\n        if(k < 0) return inv().pow(-k);\n        DynamicModint\
    \ res = 1, mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *=\
    \ mul;\n            mul *= mul;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    friend DynamicModint mod_inv(const DynamicModint &a) { return\
    \ a.inv(); }\n    friend DynamicModint mod_pow(const DynamicModint &a, long long\
    \ k) { return a.pow(k); }\n};\n\ntemplate <int id>\nint DynamicModint<id>::mod\
    \ = 1'000'000'007;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - lib/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: lib/Math/ModularArithmetic/dynamic_modint.hpp
  requiredBy: []
  timestamp: '2024-09-06 22:45:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/Math/ModularArithmetic/dynamic_modint.hpp
layout: document
redirect_from:
- /library/lib/Math/ModularArithmetic/dynamic_modint.hpp
- /library/lib/Math/ModularArithmetic/dynamic_modint.hpp.html
title: "\u52D5\u7684Modint\u69CB\u9020\u4F53"
---
## 概要

実行時に法が決まる「Modint構造体」．

インスタンスを生成する前に法とする自然数を設定する．

```cpp
DynamicModint<0>::set_modulus(17);
DynamicModint<1>::set_modulus(23);

DynamicModint<0> a = 28;
DynamicModint<1> b = 28;

cout << a << " " << b << endl;  // 11 5
```
