---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Convolution/number_theoretic_transform.hpp
    title: "Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: algorithm/Math/ModularArithmetic/modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 1 \"algorithm/Math/Convolution/number_theoretic_transform.hpp\"\
    \n\n\n\n/**\n * @brief Number Theoretic Transform\uFF08\u6570\u8AD6\u5909\u63DB\
    \uFF09\n * @docs docs/Math/Convolution/number_theoretic_transform.md\n */\n\n\
    #include <algorithm>\n#include <array>\n#include <cassert>\n#include <type_traits>\n\
    #include <utility>\n#line 15 \"algorithm/Math/Convolution/number_theoretic_transform.hpp\"\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#line\
    \ 5 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\nnamespace algorithm\
    \ {\n\nclass ModintBase {};\n\ntemplate <typename T>\nusing is_modint = std::is_base_of<ModintBase,\
    \ T>;\n\ntemplate <typename T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\
    \ntemplate <typename T>\nconcept modint = is_modint_v<T>;\n\n}  // namespace algorithm\n\
    \n\n#line 17 \"algorithm/Math/Convolution/number_theoretic_transform.hpp\"\n\n\
    namespace algorithm {\n\nnamespace ntt {\n\nconstexpr int MOD = 998'244'353; \
    \    // 998'244'353 = 2^23 * 7 * 17 + 1.\nconstexpr int MOD2 = 167'772'161;  \
    \  // 167'772'161 = 2^25 * 5 + 1.\nconstexpr int MOD3 = 469'762'049;    // 469'762'049\
    \ = 2^26 * 7 + 1.\nconstexpr int MOD4 = 754'974'721;    // 754'974'721 = 2^24\
    \ * 3^2 * 5 + 1.\nconstexpr int MOD5 = 1'107'296'257;  // 1'107'296'257 = 2^25\
    \ * 3 * 11 + 1.\nconstexpr int MOD6 = 1'224'736'769;  // 1'224'736'769 = 2^24\
    \ * 73 + 1.\nconstexpr int MOD7 = 1'711'276'033;  // 1'224'736'769 = 2^25 * 3\
    \ * 17 + 1.\nconstexpr int MOD8 = 1'811'939'329;  // 1'224'736'769 = 2^26 * 3^3\
    \ + 1.\n\n// \u7D20\u6570\u5224\u5B9A\uFF0EO(\u221AN).\ntemplate <typename Type>\n\
    constexpr bool is_prime(Type n) {\n    assert(n >= 0);\n    if(n < 2) return false;\n\
    \    if(n == 2) return true;\n    if(n % 2 == 0) return false;\n    for(Type p\
    \ = 3; p * p <= n; p += 2) {\n        if(n % p == 0) return false;\n    }\n  \
    \  return true;\n}\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\
    \u304D\uFF09\uFF0En^k (mod m) \u3092\u6C42\u3081\u308B\uFF0EO(logK).\nconstexpr\
    \ int mod_pow(long long n, long long k, int m) {\n    assert(k >= 0);\n    assert(m\
    \ >= 1);\n    long long res = 1;\n    n %= m;\n    while(k > 0) {\n        if(k\
    \ & 1LL) res = res * n % m;\n        n = n * n % m;\n        k >>= 1;\n    }\n\
    \    return res;\n}\n\n// \u7D20\u6570p\u3092\u6CD5\u3068\u3059\u308B\u6700\u5C0F\
    \u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\u308B\uFF0E\nconstexpr int primitive_root(int\
    \ p) {\n    assert(p >= 2);\n    if(p == 2) return 1;\n    if(p == MOD) return\
    \ 3;\n    if(p == MOD2) return 3;\n    if(p == MOD3) return 3;\n    if(p == MOD4)\
    \ return 11;\n    if(p == MOD5) return 10;\n    if(p == MOD6) return 3;\n    if(p\
    \ == MOD7) return 29;\n    if(p == MOD8) return 13;\n    assert(is_prime(p));\n\
    \    std::array<int, 20> divs({2});  // divs[]:=(p-1\u306E\u7D20\u56E0\u6570).\n\
    \    int cnt = 1;\n    int n = (p - 1) / 2;\n    while(n % 2 == 0) n /= 2;\n \
    \   for(int q = 3; q * q <= n; q += 2) {\n        if(n % q == 0) {\n         \
    \   divs[cnt++] = q;\n            while(n % q == 0) n /= q;\n        }\n    }\n\
    \    if(n > 1) divs[cnt++] = n;\n    for(int g = 2;; ++g) {\n        bool ok =\
    \ true;\n        for(int i = 0; i < cnt; ++i) {\n            if(mod_pow(g, (p\
    \ - 1) / divs[i], p) == 1) {\n                ok = false;\n                break;\n\
    \            }\n        }\n        if(ok) return g;\n    }\n}\n\n// Number Theoretic\
    \ Transform\uFF08\u6570\u8AD6\u5909\u63DB\uFF09.\n// \u5F15\u6570\u306E\u6570\u5217\
    \u306E\u9577\u3055\u306F2\u306E\u3079\u304D\u4E57\u3067\u3042\u308B\u3053\u3068\
    \uFF0EO(N*logN).\ntemplate <class mint, typename std::enable_if_t<is_modint_v<mint>,\
    \ bool> = false>\nvoid transform(std::vector<mint> &a, bool inv = false) {\n \
    \   const int n = a.size();\n    if(n == 0) return;\n    assert((mint::modulus()\
    \ - 1) % n == 0);\n    static bool first = true;\n    static std::array<mint,\
    \ 30> ws, inv_ws;  // ws[k]:=(2^k\u4E57\u6839), inv_ws[k]:=(2^k\u4E57\u6839\u306E\
    \u9006\u5143).\n    if(first) {\n        mint &&pr = primitive_root(mint::modulus());\n\
    \        int rank = 0;\n        while(!((mint::modulus() - 1) & 1 << rank)) rank++;\n\
    \        ws[rank] = pr.pow((mint::modulus() - 1) >> rank);\n        inv_ws[rank]\
    \ = ws[rank].inv();\n        for(int k = rank - 1; k >= 0; --k) {\n          \
    \  ws[k] = ws[k + 1] * ws[k + 1];\n            inv_ws[k] = inv_ws[k + 1] * inv_ws[k\
    \ + 1];\n        }\n        first = false;\n    }\n    int lb = 0;  // lb:=log2(n).\n\
    \    while(1 << lb < n) lb++;\n    assert(n == 1 << lb);\n    for(int i = 0; i\
    \ < n; ++i) {\n        int j = 0;\n        for(int k = 0; k < lb; ++k) j |= (i\
    \ >> k & 1) << (lb - 1 - k);\n        if(i < j) std::swap(a[i], a[j]);\n    }\n\
    \    for(int b = 1, k = 1; b < n; b <<= 1, ++k) {\n        mint w = 1;\n     \
    \   for(int i = 0; i < b; ++i) {\n            for(int j = 0; j < n; j += b <<\
    \ 1) {\n                mint &&tmp = a[i + j + b] * w;\n                a[i +\
    \ j + b] = a[i + j] - tmp;\n                a[i + j] += tmp;\n            }\n\
    \            w *= (inv ? inv_ws[k] : ws[k]);\n        }\n    }\n    if(inv) {\n\
    \        mint &&tmp = mint(n).inv();\n        for(int i = 0; i < n; ++i) a[i]\
    \ *= tmp;\n    }\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217a[],\
    \ b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\
    \u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename\
    \ Type>\nstd::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    const int n = a.size(), m = b.size();\n    if(n == 0 or m == 0) return\
    \ std::vector<Type>();\n    std::vector<Type> res(n + m - 1, 0);\n    for(int\
    \ i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j) res[i + j] += a[i]\
    \ * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n//\
    \ \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k]\
    \ \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0EO(N*logN).\n\
    template <class mint, typename std::enable_if_t<is_modint_v<mint>, bool> = false>\n\
    std::vector<mint> convolve(std::vector<mint> a, std::vector<mint> b) {\n    if(a.size()\
    \ == 0 or b.size() == 0) return std::vector<mint>();\n    const int n = a.size()\
    \ + b.size() - 1;\n    int m = 1;\n    while(m < n) m <<= 1;\n    a.resize(m,\
    \ 0), b.resize(m, 0);\n    transform(a), transform(b);\n    for(int i = 0; i <\
    \ m; ++i) a[i] *= b[i];\n    transform(a, true);\n    a.resize(n);\n    return\
    \ a;\n}\n\n}  // namespace ntt\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\n\n\n#line 5 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n#include <concepts>\n\
    #include <cstdint>\n#include <functional>\n#line 9 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n#line 8 \"\
    algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n\n#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
    \n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\nnamespace algorithm\
    \ {\n\nnamespace internal {\n\n// return x mod m.\ntemplate <std::unsigned_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t mod) { return x\
    \ % mod; }\n\n// return x mod m.\ntemplate <std::unsigned_integral Type>\nconstexpr\
    \ std::uint32_t modulo(Type x, std::int32_t mod) { return modulo(x, static_cast<std::uint32_t>(mod));\
    \ }\n\n// return x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t\
    \ modulo(Type x, std::uint32_t mod) {\n    x %= static_cast<std::int64_t>(mod);\n\
    \    if(x < 0) x += static_cast<std::int64_t>(mod);\n    return x;\n}\n\n// return\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t mod) {\n    x %= mod;\n    if(x < 0) x += mod;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return pair of (x, g)\
    \ s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.\nconstexpr std::pair<std::uint32_t,\
    \ std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {\n    if(a == 0) return\
    \ {0, m};\n    std::uint32_t s = m, t = a;\n    std::uint32_t u = m, v = 1;\n\
    \    while(true) {\n        std::uint32_t q = s / t;\n        s -= t * q, u -=\
    \ v * q;\n        if(s == 0) return {v, t};\n        q = t / s;\n        t -=\
    \ s * q, v += (m - u) * q;\n        if(t == 0) return {u, s};\n    }\n}\n\n} \
    \ // namespace internal\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\ntemplate <std::integral Type>\nconstexpr std::int64_t mod_inv(Type a, std::int32_t\
    \ m) {\n    assert(m >= 1);\n    auto [x, g] = internal::mod_inv(::algorithm::internal::modulo(a,\
    \ m), m);\n    assert(g == 1);\n    return x;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n#line 7 \"\
    algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// return n^k mod m.\nconstexpr\
    \ std::uint32_t mod_pow(std::uint64_t n, unsigned long long k, std::uint32_t mod)\
    \ {\n    std::uint64_t res = 1;\n    for(; k > 0; k >>= 1) {\n        if(k & 1ULL)\
    \ res = res * n % mod;\n        n = n * n % mod;\n    }\n    return res;\n}\n\n\
    }  // namespace internal\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0EO(log k).\ntemplate <std::integral Type>\nconstexpr\
    \ std::int64_t mod_pow(Type n, long long k, std::int32_t mod) {\n    assert(mod\
    \ >= 1);\n    auto r = ::algorithm::internal::modulo(n, mod);\n    if(k < 0) {\n\
    \        auto [x, g] = ::algorithm::internal::mod_inv(r, mod);\n        assert(g\
    \ == 1);\n        r = x, k = -k;\n    }\n    return internal::mod_pow(r, k, mod);\n\
    }\n\n}  // namespace algorithm\n\n\n#line 14 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <std::int32_t mod>\nclass Modint : public\
    \ ModintBase {\n    static_assert(mod >= 1);\n\n    std::uint32_t val;\n\n   \
    \ static constexpr std::uint32_t umod() { return mod; }\n\npublic:\n    constexpr\
    \ Modint() : val(0) {}\n    template <std::integral Type>\n    constexpr Modint(Type\
    \ val) : val(::algorithm::internal::modulo(val, mod)) {}\n\n    constexpr Modint\
    \ operator+() const { return Modint(*this); }\n    constexpr Modint operator-()\
    \ const {\n        if(val == 0) Modint();\n        return raw(umod() - val);\n\
    \    }\n    constexpr Modint &operator++() {\n        ++val;\n        if(val ==\
    \ umod()) val = 0;\n        return *this;\n    }\n    constexpr Modint &operator--()\
    \ {\n        if(val == 0) val = umod();\n        --val;\n        return *this;\n\
    \    }\n    constexpr Modint operator++(int) {\n        Modint res = *this;\n\
    \        ++(*this);\n        return res;\n    }\n    constexpr Modint operator--(int)\
    \ {\n        Modint res = *this;\n        --(*this);\n        return res;\n  \
    \  }\n    constexpr Modint &operator+=(const Modint &rhs) {\n        if(rhs.val\
    \ >= umod() - val) val -= umod();\n        val += rhs.val;\n        return *this;\n\
    \    }\n    constexpr Modint &operator-=(const Modint &rhs) {\n        if(rhs.val\
    \ > val) val += umod();\n        val -= rhs.val;\n        return *this;\n    }\n\
    \    constexpr Modint &operator*=(const Modint &rhs) {\n        val = static_cast<std::uint64_t>(val)\
    \ * rhs.val % umod();\n        return *this;\n    }\n    constexpr Modint &operator/=(const\
    \ Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend constexpr bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr\
    \ Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ += rhs; }\n    friend constexpr Modint operator-(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend constexpr\
    \ Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ /= rhs; }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs)\
    \ {\n        std::int64_t val;\n        is >> val;\n        rhs.val = ::algorithm::internal::modulo(val,\
    \ mod);\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr std::int32_t\
    \ modulus() { return mod; }\n    static constexpr Modint raw(std::uint32_t val)\
    \ {\n        Modint res;\n        res.val = val;\n        return res;\n    }\n\
    \n    constexpr std::int64_t value() const { return val; }\n    constexpr Modint\
    \ inv() const {\n        auto [x, g] = ::algorithm::internal::mod_inv(val, umod());\n\
    \        assert(g == 1);\n        return raw(x);\n    }\n    constexpr Modint\
    \ pow(long long k) const {\n        if(k < 0) return raw(::algorithm::internal::mod_pow(val,\
    \ -k, umod())).inv();\n        return raw(::algorithm::internal::mod_pow(val,\
    \ k, umod()));\n    }\n\n    friend constexpr Modint mod_inv(const Modint &a)\
    \ { return a.inv(); }\n    friend constexpr Modint mod_pow(const Modint &a, long\
    \ long k) { return a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\n\
    using mint1000000007 = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\
    template <std::int32_t mod>\nstruct std::hash<algorithm::Modint<mod>> {\n    std::size_t\
    \ operator()(const algorithm::Modint<mod> &ob) const { return ob.value(); }\n\
    };\n\n\n#line 8 \"verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n\n    std::vector<algorithm::mint998244353>\
    \ a(n), b(m);\n    for(auto &elem : a) std::cin >> elem;\n    for(auto &elem :\
    \ b) std::cin >> elem;\n\n    auto &&c = algorithm::ntt::convolve(a, b);\n   \
    \ for(const auto &elem : c) std::cout << elem << \" \";\n    std::cout << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../algorithm/Math/Convolution/number_theoretic_transform.hpp\"\
    \n#include \"../algorithm/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n\
    \    int n, m;\n    std::cin >> n >> m;\n\n    std::vector<algorithm::mint998244353>\
    \ a(n), b(m);\n    for(auto &elem : a) std::cin >> elem;\n    for(auto &elem :\
    \ b) std::cin >> elem;\n\n    auto &&c = algorithm::ntt::convolve(a, b);\n   \
    \ for(const auto &elem : c) std::cout << elem << \" \";\n    std::cout << std::endl;\n\
    }\n"
  dependsOn:
  - algorithm/Math/Convolution/number_theoretic_transform.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  - algorithm/Math/ModularArithmetic/mod_pow.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
  requiredBy: []
  timestamp: '2025-08-31 12:36:13+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
- /verify/verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp.html
title: verify/yosupo-convolution_mod-number_theoretic_transform.test.cpp
---
