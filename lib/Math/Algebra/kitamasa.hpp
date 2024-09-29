#ifndef ALGORITHM_KITAMASA_HPP
#define ALGORITHM_KITAMASA_HPP 1

/**
 * @brief きたまさ法
 * @docs docs/Math/Algebra/kitamasa.md
 */

#include <cassert>
#include <cstdint>
#include <vector>

namespace algorithm {

// きたまさ法．
// 線形漸化式 a[n]=d[0]*a[n-k]+d[1]*a[n-(k-1)]+....+d[k-1]*a[n-1] で表される数列の任意の項を求める．O((K^2)*logN).
template <typename T = long long>
class Kitamasa {
public:
    using size_type = uint64_t;

private:
    size_type m_k;       // m_k:=(階数).
    std::vector<T> m_a;  // m_a[]:=(初項数列).
    std::vector<T> m_d;  // m_d[]:=(係数数列).

    // f(n)->f(n+1). O(K).
    std::vector<T> add(const std::vector<T> &x) const {
        std::vector<T> y(m_k);
        y[0] = x[m_k - 1] * m_d[0];
        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];
        return y;
    }
    // f(n)->f(2*n). O(K^2).
    std::vector<T> mul(const std::vector<T> &x) const {
        std::vector<T> y(m_k, 0);
        std::vector<T> t = x;
        for(size_type i = 0; i < m_k; ++i) {
            for(size_type j = 0; j < m_k; ++j) y[j] += x[i] * t[j];
            if(i == m_k - 1) break;
            t = add(t);
        }
        return y;
    }
    // f(n)を返す．O((K^2)*logN).
    std::vector<T> f(size_type n) const {
        if(n == 0) {
            std::vector<T> x(m_k, 0);
            x[0] = 1;
            return x;  // f(0).
        }
        std::vector<T> &&x = mul(f(n / 2));
        if(n & 1ULL) x = add(x);
        return x;
    }

public:
    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // フィボナッチ数列．
    explicit Kitamasa(const std::vector<T> &a, const std::vector<T> &d) : m_k(a.size()), m_a(a), m_d(d) {
        assert(a.size() >= 1);
        assert(a.size() == d.size());
    }

    T operator[](size_type n) const { return calc(n); }

    // a[n]を求める．O((K^2)*logN).
    T calc(size_type n) const {
        T res = 0;
        const std::vector<T> &&x = f(n);
        for(size_type i = 0; i < m_k; ++i) res += x[i] * m_a[i];
        return res;
    }
    // a[l:r]を求める．O((K^2)*logN+K*(r-l)).
    std::vector<T> calc(size_type l, size_type r) const {
        assert(l < r);
        std::vector<T> res(r - l);
        std::vector<T> &&x = f(l);
        for(size_type i = l; i < r; ++i) {
            for(size_type j = 0; j < m_k; ++j) res[i - l] += x[j] * m_a[j];
            if(i == r - 1) break;
            x = add(x);
        }
        return res;
    }
};

}  // namespace algorithm

#endif
