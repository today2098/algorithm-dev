#ifndef ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP
#define ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP 1

/**
 * @brief Discrete Fourier Transform（離散フーリエ変換）
 * @docs docs/Math/Convolution/discrete_fourier_transform.md
 */

#include <algorithm>
#include <cmath>
#include <complex>
#include <type_traits>
#include <vector>

namespace algorithm {

namespace dft {

using D = double;

const D PI = std::acos(-1.0);

// Discrete Fourier Transform（離散フーリエ変換）. O(N^2).
void transform(std::vector<std::complex<D> > &a, bool inv = false) {
    if(a.size() == 0) return;
    const int n = a.size();
    std::vector<std::complex<D> > res(n, 0.0);
    D ang = 2 * PI / n;
    if(inv) ang = -ang;
    for(int i = 0; i < n; ++i) {
        D tmp = ang * i;
        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar<D>(1.0, tmp * j);
    }
    if(inv) {
        for(int i = 0; i < n; ++i) res[i] /= n;
    }
    a = res;
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
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N^2).
template <typename Type, typename std::enable_if_t<std::is_integral_v<Type>, bool> = false>
std::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();
    const int n = a.size() + b.size() - 1;
    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    transform(na), transform(nb);
    for(int i = 0; i < n; ++i) na[i] *= nb[i];
    transform(na, true);
    std::vector<Type> res(n);
    for(int i = 0; i < n; ++i) res[i] = na[i].real() + (na[i].real() < 0.0 ? -0.5 : 0.5);
    return res;
}

// 畳み込み．
// 数列a[], b[]に対して，c[i]=sum_{k=0}^{i} a[k]*b[i-k] となる数列c[]を求める．O(N^2).
template <typename Type, typename std::enable_if_t<std::is_floating_point_v<Type>, bool> = false>
std::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type> &b) {
    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();
    const int n = a.size() + b.size() - 1;
    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);
    std::copy(a.begin(), a.end(), na.begin());
    std::copy(b.begin(), b.end(), nb.begin());
    transform(na), transform(nb);
    for(int i = 0; i < n; ++i) na[i] *= nb[i];
    transform(na, true);
    std::vector<Type> res(n);
    for(int i = 0; i < n; ++i) res[i] = na[i].real();
    return res;
}

}  // namespace dft

}  // namespace algorithm

#endif
