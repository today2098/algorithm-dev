---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
    title: verify/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/Convolution/fast_fourier_transform.md
    document_title: "Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
      \u5909\u63DB\uFF09"
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Convolution/fast_fourier_transform.hpp\"\n\
    \n\n\n/**\n * @brief Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\
    \u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/Convolution/fast_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace fft {\n\nusing D = double;\n\nconst D PI = std::acos(-1.0);\n\
    \n// Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\
    \uFF09.\n// \u5F15\u6570\u306E\u6570\u5217\u306E\u9577\u3055\u306F2\u306E\u3079\
    \u304D\u4E57\u3067\u3042\u308B\u3053\u3068\uFF0EO(N*logN).\nvoid transform(std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    const int n = a.size();\n    if(n == 0) return;\n\
    \    int lb = 0;  // lb:=log2(n).\n    while(1 << lb < n) lb++;\n    assert(n\
    \ == 1 << lb);\n    for(int i = 0; i < n; ++i) {\n        int j = 0;\n       \
    \ for(int k = 0; k < lb; ++k) j |= (i >> k & 1) << (lb - 1 - k);\n        if(i\
    \ < j) std::swap(a[i], a[j]);\n    }\n    for(int b = 1; b < n; b <<= 1) {\n \
    \       D ang = PI / b;\n        if(inv) ang = -ang;\n        for(int i = 0; i\
    \ < b; ++i) {\n            std::complex<D> &&w = std::polar<D>(1.0, ang * i);\n\
    \            for(int j = 0; j < n; j += b << 1) {\n                std::complex<D>\
    \ &&tmp = a[i + j + b] * w;\n                a[i + j + b] = a[i + j] - tmp;\n\
    \                a[i + j] += tmp;\n            }\n        }\n    }\n    if(inv)\
    \ {\n        for(int i = 0; i < n; ++i) a[i] /= n;\n    }\n}\n\n// \u7573\u307F\
    \u8FBC\u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0E\
    O(N^2).\ntemplate <typename Type>\nstd::vector<Type> convolve_naive(const std::vector<Type>\
    \ &a, const std::vector<Type> &b) {\n    const int n = a.size(), m = b.size();\n\
    \    if(n == 0 or m == 0) return std::vector<Type>();\n    std::vector<Type> res(n\
    \ + m - 1, 0);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m;\
    \ ++j) res[i + j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\
    \u8FBC\u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0E\
    O(N*logN).\ntemplate <typename Type, typename std::enable_if_t<std::is_integral_v<Type>,\
    \ bool> = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const\
    \ std::vector<Type> &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n)\
    \ m <<= 1;\n    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    transform(na),\
    \ transform(nb);\n    for(int i = 0; i < m; ++i) na[i] *= nb[i];\n    transform(na,\
    \ true);\n    std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i]\
    \ = na[i].real() + (na[i].real() < 0.0 ? -0.5 : 0.5);\n    return res;\n}\n\n\
    // \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\
    \uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\
    \u3081\u308B\uFF0EO(N*logN).\ntemplate <typename Type, typename std::enable_if_t<std::is_floating_point_v<Type>,\
    \ bool> = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const\
    \ std::vector<Type> &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n)\
    \ m <<= 1;\n    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    transform(na),\
    \ transform(nb);\n    for(int i = 0; i < m; ++i) na[i] *= nb[i];\n    transform(na,\
    \ true);\n    std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i]\
    \ = na[i].real();\n    return res;\n}\n\n}  // namespace fft\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_FAST_FOURIER_TRANSFORM_HPP\n#define ALGORITHM_FAST_FOURIER_TRANSFORM_HPP\
    \ 1\n\n/**\n * @brief Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\
    \u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/Convolution/fast_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace fft {\n\nusing D = double;\n\nconst D PI = std::acos(-1.0);\n\
    \n// Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\
    \uFF09.\n// \u5F15\u6570\u306E\u6570\u5217\u306E\u9577\u3055\u306F2\u306E\u3079\
    \u304D\u4E57\u3067\u3042\u308B\u3053\u3068\uFF0EO(N*logN).\nvoid transform(std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    const int n = a.size();\n    if(n == 0) return;\n\
    \    int lb = 0;  // lb:=log2(n).\n    while(1 << lb < n) lb++;\n    assert(n\
    \ == 1 << lb);\n    for(int i = 0; i < n; ++i) {\n        int j = 0;\n       \
    \ for(int k = 0; k < lb; ++k) j |= (i >> k & 1) << (lb - 1 - k);\n        if(i\
    \ < j) std::swap(a[i], a[j]);\n    }\n    for(int b = 1; b < n; b <<= 1) {\n \
    \       D ang = PI / b;\n        if(inv) ang = -ang;\n        for(int i = 0; i\
    \ < b; ++i) {\n            std::complex<D> &&w = std::polar<D>(1.0, ang * i);\n\
    \            for(int j = 0; j < n; j += b << 1) {\n                std::complex<D>\
    \ &&tmp = a[i + j + b] * w;\n                a[i + j + b] = a[i + j] - tmp;\n\
    \                a[i + j] += tmp;\n            }\n        }\n    }\n    if(inv)\
    \ {\n        for(int i = 0; i < n; ++i) a[i] /= n;\n    }\n}\n\n// \u7573\u307F\
    \u8FBC\u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0E\
    O(N^2).\ntemplate <typename Type>\nstd::vector<Type> convolve_naive(const std::vector<Type>\
    \ &a, const std::vector<Type> &b) {\n    const int n = a.size(), m = b.size();\n\
    \    if(n == 0 or m == 0) return std::vector<Type>();\n    std::vector<Type> res(n\
    \ + m - 1, 0);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m;\
    \ ++j) res[i + j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\
    \u8FBC\u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\u3081\u308B\uFF0E\
    O(N*logN).\ntemplate <typename Type, typename std::enable_if_t<std::is_integral_v<Type>,\
    \ bool> = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const\
    \ std::vector<Type> &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n)\
    \ m <<= 1;\n    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    transform(na),\
    \ transform(nb);\n    for(int i = 0; i < m; ++i) na[i] *= nb[i];\n    transform(na,\
    \ true);\n    std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i]\
    \ = na[i].real() + (na[i].real() < 0.0 ? -0.5 : 0.5);\n    return res;\n}\n\n\
    // \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217a[], b[]\u306B\u5BFE\u3057\u3066\
    \uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c[]\u3092\u6C42\
    \u3081\u308B\uFF0EO(N*logN).\ntemplate <typename Type, typename std::enable_if_t<std::is_floating_point_v<Type>,\
    \ bool> = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const\
    \ std::vector<Type> &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    int m = 1;\n    while(m < n)\
    \ m <<= 1;\n    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    transform(na),\
    \ transform(nb);\n    for(int i = 0; i < m; ++i) na[i] *= nb[i];\n    transform(na,\
    \ true);\n    std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i]\
    \ = na[i].real();\n    return res;\n}\n\n}  // namespace fft\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Convolution/fast_fourier_transform.hpp
  requiredBy: []
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-ITP1_1_A-fast_fourier_transform.test.cpp
documentation_of: algorithm/Math/Convolution/fast_fourier_transform.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Convolution/fast_fourier_transform.hpp
- /library/algorithm/Math/Convolution/fast_fourier_transform.hpp.html
title: "Fast Fourier Transform\uFF08\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\
  \uFF09"
---
## 概要

高速フーリエ変換 (FFT: Fast Fourier Transform) を用いた畳み込みを行う．

具体的には，長さ $N$ の数列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ と長さ $M$ の数列 $\lbrace b_0, b_1, \ldots, b_{M-1} \rbrace$ に対して，

$$
c_i = \sum_{k=0}^{i} a_k b_{i-k}
$$

となる長さ $N + M - 1$ の数列 $\lbrace c_0, c_1, \ldots, c_{N+M-1} \rbrace$ を $\mathcal{O}((N + M) \log (N + M))$ で求める．

数列の長さや要素の値が大きくなると，誤差も大きくなることに注意．


## 参考文献

1. "高速フーリエ変換". Wikipedia. <https://ja.wikipedia.org/wiki/高速フーリエ変換>.
1. AngrySadEight. "高速フーリエ変換・数論変換を改めて理解しようという話". Qiita. <https://qiita.com/AngrySadEight/items/0dfde26060daaf6a2fda>.
1. tatyam. "【競プロer向け】FFT を習得しよう！". 東京工業大学で活動するデジタル創作. <https://trap.jp/post/1386/>.
1. "競プロのための高速フーリエ変換". <https://www.creativ.xyz/fast-fourier-transform/>.


## 問題

- "C - 高速フーリエ変換". AtCoder Typical Contest 001. AtCoder. <https://atcoder.jp/contests/atc001/tasks/fft_c>.
