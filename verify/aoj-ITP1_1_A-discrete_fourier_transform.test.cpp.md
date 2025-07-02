---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Convolution/discrete_fourier_transform.hpp
    title: "Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\
      \u63DB\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <cassert>\n#include <cmath>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 1 \"algorithm/Math/Convolution/discrete_fourier_transform.hpp\"\
    \n\n\n\n/**\n * @brief Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/Convolution/discrete_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#line 11 \"algorithm/Math/Convolution/discrete_fourier_transform.hpp\"\
    \n#include <complex>\n#include <type_traits>\n#line 14 \"algorithm/Math/Convolution/discrete_fourier_transform.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace dft {\n\nusing D = double;\n\nconst D PI\
    \ = std::acos(-1.0);\n\n// Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\uFF09. O(N^2).\nvoid transform(std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    if(a.size() == 0) return;\n    const int n =\
    \ a.size();\n    std::vector<std::complex<D> > res(n, 0.0);\n    D ang = 2 * PI\
    \ / n;\n    if(inv) ang = -ang;\n    for(int i = 0; i < n; ++i) {\n        D tmp\
    \ = ang * i;\n        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar<D>(1.0,\
    \ tmp * j);\n    }\n    if(inv) {\n        for(int i = 0; i < n; ++i) res[i] /=\
    \ n;\n    }\n    a = res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217\
    a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\
    \u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename\
    \ Type>\nstd::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    const int n = a.size(), m = b.size();\n    if(n == 0 or m == 0) return\
    \ std::vector<Type>();\n    std::vector<Type> res(n + m - 1, 0);\n    for(int\
    \ i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j) res[i + j] += a[i]\
    \ * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n//\
    \ \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k]\
    \ \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate\
    \ <typename Type, typename std::enable_if_t<std::is_integral_v<Type>, bool> =\
    \ false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    std::vector<std::complex<D> >\
    \ na(n, 0.0), nb(n, 0.0);\n    std::copy(a.begin(), a.end(), na.begin());\n  \
    \  std::copy(b.begin(), b.end(), nb.begin());\n    transform(na), transform(nb);\n\
    \    for(int i = 0; i < n; ++i) na[i] *= nb[i];\n    transform(na, true);\n  \
    \  std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i] = na[i].real()\
    \ + (na[i].real() < 0.0 ? -0.5 : 0.5);\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0E\
    O(N^2).\ntemplate <typename Type, typename std::enable_if_t<std::is_floating_point_v<Type>,\
    \ bool> = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const\
    \ std::vector<Type> &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    std::vector<std::complex<D> >\
    \ na(n, 0.0), nb(n, 0.0);\n    std::copy(a.begin(), a.end(), na.begin());\n  \
    \  std::copy(b.begin(), b.end(), nb.begin());\n    transform(na), transform(nb);\n\
    \    for(int i = 0; i < n; ++i) na[i] *= nb[i];\n    transform(na, true);\n  \
    \  std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i] = na[i].real();\n\
    \    return res;\n}\n\n}  // namespace dft\n\n}  // namespace algorithm\n\n\n\
    #line 10 \"verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp\"\n\nint main()\
    \ {\n    constexpr int t = 100;\n    std::random_device seed;\n    std::mt19937_64\
    \ rng(seed());\n\n    constexpr double eps = 1e-6;\n    std::uniform_int_distribution<int>\
    \ uniform_n(1, 200);\n    std::uniform_real_distribution<double> uniform(-1e3,\
    \ 1e3);\n    for(int i = 0; i < t; ++i) {\n        const int n = uniform_n(rng),\
    \ m = uniform_n(rng);\n        std::vector<double> a(n), b(m);\n        for(auto\
    \ &elem : a) elem = uniform(rng);\n        for(auto &elem : b) elem = uniform(rng);\n\
    \n        auto &&target = algorithm::dft::convolve(a, b);\n        auto &&want\
    \ = algorithm::dft::convolve_naive(a, b);\n\n        assert(target.size() == size_t(n\
    \ + m - 1));\n        assert(want.size() == size_t(n + m - 1));\n        for(int\
    \ j = 0; j < n + m - 1; ++j) assert(std::abs(target[j] - want[j]) < eps);\n  \
    \  }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <cassert>\n#include <cmath>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"../algorithm/Math/Convolution/discrete_fourier_transform.hpp\"\
    \n\nint main() {\n    constexpr int t = 100;\n    std::random_device seed;\n \
    \   std::mt19937_64 rng(seed());\n\n    constexpr double eps = 1e-6;\n    std::uniform_int_distribution<int>\
    \ uniform_n(1, 200);\n    std::uniform_real_distribution<double> uniform(-1e3,\
    \ 1e3);\n    for(int i = 0; i < t; ++i) {\n        const int n = uniform_n(rng),\
    \ m = uniform_n(rng);\n        std::vector<double> a(n), b(m);\n        for(auto\
    \ &elem : a) elem = uniform(rng);\n        for(auto &elem : b) elem = uniform(rng);\n\
    \n        auto &&target = algorithm::dft::convolve(a, b);\n        auto &&want\
    \ = algorithm::dft::convolve_naive(a, b);\n\n        assert(target.size() == size_t(n\
    \ + m - 1));\n        assert(want.size() == size_t(n + m - 1));\n        for(int\
    \ j = 0; j < n + m - 1; ++j) assert(std::abs(target[j] - want[j]) < eps);\n  \
    \  }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - algorithm/Math/Convolution/discrete_fourier_transform.hpp
  isVerificationFile: true
  path: verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp
- /verify/verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp.html
title: verify/aoj-ITP1_1_A-discrete_fourier_transform.test.cpp
---
