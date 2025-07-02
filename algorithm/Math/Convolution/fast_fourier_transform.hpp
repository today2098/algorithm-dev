#ifndef ALGORITHM_FAST_FOURIER_TRANSFORM_HPP
#define ALGORITHM_FAST_FOURIER_TRANSFORM_HPP 1

/**
 * @brief Fast Fourier Transform（高速フーリエ変換）
 * @docs docs/Math/Convolution/fast_fourier_transform.md
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithm {

namespace fft {

using D = double;

const D PI = std::acos(-1.0);

// Fast Fourier Transform（高速フーリエ変換）.
// 引数の数列の長さは2のべき乗であること．O(N*logN).
void transform(std::vector<std::complex<D> > &a, bool inv = false) {
    const int n = a.size();
    if(n == 0) return;
    int lb = 0;  // lb:=log2(n).
    while(1 << lb < n) lb++;
    assert(n == 1 << lb);
    for(int i = 0; i < n; ++i) {
        int j = 0;
        for(int k = 0; k < lb; ++k) j |= (i >> k & 1) << (lb - 1 - k);
        if(i < j) std::swap(a[i], a[j]);
    }
    for(int b = 1; b < n; b <<= 1) {
        D ang = PI / b;
        if(inv) ang = -ang;
        for(int i = 0; i < b; ++i) {
            std::complex<D> &&w = std::polar<D>(1.0, ang * i);
            for(int j = 0; j < n; j += b << 1) {
                std::complex<D> &&tmp = a[i + j + b] * w;
                a[i + j + b] = a[i + j] - tmp;
                a[i + j] += tmp;
            }
        }
    }
    if(inv) {
        for(int i = 0; i < n; ++i) a[i] /= n;
    }
}

// 畳み込み．
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N^2).
template <typename Type>
std::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type> &b) {
    const int n = a.size(), m = b.size();
    if(n == 0 or m == 0) return std::vector<Type>();
    std::vector<Type> res(n + m - 1, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) res[i + j] += a[i] * b[j];
    }
    return res;
}

// 畳み込み．
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N*logN).
template <typename Type, typename std::enable_if_t<std::is_integral_v<Type>, bool> = false>
std::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();
    const int n = a.size() + b.size() - 1;
    int m = 1;
    while(m < n) m <<= 1;
    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    transform(na), transform(nb);
    for(int i = 0; i < m; ++i) na[i] *= nb[i];
    transform(na, true);
    std::vector<Type> res(n);
    for(int i = 0; i < n; ++i) res[i] = na[i].real() + (na[i].real() < 0.0 ? -0.5 : 0.5);
    return res;
}

// 畳み込み．
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N*logN).
template <typename Type, typename std::enable_if_t<std::is_floating_point_v<Type>, bool> = false>
std::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();
    const int n = a.size() + b.size() - 1;
    int m = 1;
    while(m < n) m <<= 1;
    std::vector<std::complex<D> > na(m, 0.0), nb(m, 0.0);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    transform(na), transform(nb);
    for(int i = 0; i < m; ++i) na[i] *= nb[i];
    transform(na, true);
    std::vector<Type> res(n);
    for(int i = 0; i < n; ++i) res[i] = na[i].real();
    return res;
}

}  // namespace fft

}  // namespace algorithm

#endif
