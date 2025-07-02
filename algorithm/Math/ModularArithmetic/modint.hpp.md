---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: algorithm/Math/ModularArithmetic/modint_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
    title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - icon: ':x:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n\n\n\n#include\
    \ <iostream>\n#include <utility>\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace algorithm {\n\nclass ModintBase {};\n\
    \ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate\
    \ <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\n}  //\
    \ namespace algorithm\n\n\n#line 8 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n\
    \    static_assert(mod >= 1);\n\n    long long val;\n\n    constexpr void normalize()\
    \ {\n        if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val\
    \ += mod;\n    }\n\npublic:\n    constexpr Modint() : val(0) {}\n    constexpr\
    \ Modint(long long val) : val(val) {\n        normalize();\n    }\n\n    constexpr\
    \ Modint operator+() const { return Modint(*this); }\n    constexpr Modint operator-()\
    \ const {\n        if(val == 0) Modint();\n        Modint res = *this;\n     \
    \   res.val = mod - res.val;\n        return res;\n    }\n    constexpr Modint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator--() {\n        if(val == 0) val\
    \ = mod;\n        val--;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n     \
    \   val = val * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend\
    \ constexpr bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val\
    \ == rhs.val; }\n    friend constexpr Modint operator+(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) += rhs; }\n    friend constexpr Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr\
    \ Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ *= rhs; }\n    friend constexpr Modint operator/(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    constexpr long long value() const { return val; }\n   \
    \ constexpr Modint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return Modint(u);\n    }\n    constexpr Modint pow(long long\
    \ k) const {\n        if(k < 0) return inv().pow(-k);\n        Modint res = 1,\
    \ mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    friend constexpr Modint mod_inv(const Modint &a) { return a.inv();\
    \ }\n    friend constexpr Modint mod_pow(const Modint &a, long long k) { return\
    \ a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\nusing mint1000000007\
    \ = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MODINT_HPP\n#define ALGORITHM_MODINT_HPP 1\n\n#include\
    \ <iostream>\n#include <utility>\n\n#include \"modint_base.hpp\"\n\nnamespace\
    \ algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n    static_assert(mod\
    \ >= 1);\n\n    long long val;\n\n    constexpr void normalize() {\n        if(val\
    \ < -mod or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\n\
    public:\n    constexpr Modint() : val(0) {}\n    constexpr Modint(long long val)\
    \ : val(val) {\n        normalize();\n    }\n\n    constexpr Modint operator+()\
    \ const { return Modint(*this); }\n    constexpr Modint operator-() const {\n\
    \        if(val == 0) Modint();\n        Modint res = *this;\n        res.val\
    \ = mod - res.val;\n        return res;\n    }\n    constexpr Modint &operator++()\
    \ {\n        val++;\n        if(val == mod) val = 0;\n        return *this;\n\
    \    }\n    constexpr Modint &operator--() {\n        if(val == 0) val = mod;\n\
    \        val--;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n     \
    \   val = val * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend\
    \ constexpr bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val\
    \ == rhs.val; }\n    friend constexpr Modint operator+(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) += rhs; }\n    friend constexpr Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr\
    \ Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ *= rhs; }\n    friend constexpr Modint operator/(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    constexpr long long value() const { return val; }\n   \
    \ constexpr Modint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return Modint(u);\n    }\n    constexpr Modint pow(long long\
    \ k) const {\n        if(k < 0) return inv().pow(-k);\n        Modint res = 1,\
    \ mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    friend constexpr Modint mod_inv(const Modint &a) { return a.inv();\
    \ }\n    friend constexpr Modint mod_pow(const Modint &a, long long k) { return\
    \ a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\nusing mint1000000007\
    \ = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/modint.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/modint.hpp
layout: document
redirect_from:
- /library/algorithm/Math/ModularArithmetic/modint.hpp
- /library/algorithm/Math/ModularArithmetic/modint.hpp.html
title: algorithm/Math/ModularArithmetic/modint.hpp
---
