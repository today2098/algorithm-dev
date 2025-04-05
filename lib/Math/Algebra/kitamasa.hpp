#ifndef ALGORITHM_KITAMASA_HPP
#define ALGORITHM_KITAMASA_HPP 1

#include <cassert>
#include <iterator>
#include <utility>
#include <vector>

namespace algorithm {

// きたまさ法．
template <typename T>
class Kitamasa {
public:
    using value_type = T;
    using size_type = std::size_t;

private:
    size_type m_k;       // m_k:=(階数).
    std::vector<T> m_a;  // m_a[]:=(初項数列).
    std::vector<T> m_c;  // m_c[]:=(係数数列).

    // f(n)->f(n+1). O(K).
    std::vector<T> add(const std::vector<T> &x) const {
        std::vector<T> y(m_k);
        y[0] = x[m_k - 1] * m_c[0];
        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_c[i];
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
        std::vector<T> &&x = mul(f(n >> 1));
        if(n & 1ULL) x = add(x);
        return x;
    }

public:
    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // フィボナッチ数列．
    explicit Kitamasa(std::vector<T> a, std::vector<T> c) : m_k(a.size()), m_a(std::move(a)), m_c(std::move(c)) {
        assert(m_a.size() >= 1);
        assert(m_a.size() == m_c.size());
    }
    template <std::input_iterator Iter>
    explicit Kitamasa(Iter a_first, Iter a_last, Iter d_first, Iter d_last) : m_a(a_first, a_last), m_c(d_first, d_last) {
        assert(m_a.size() >= 1);
        assert(m_a.size() == m_c.size());
        m_k = m_a.size();
    }

    T operator[](size_type n) const { return calc(n); }

    // a[n]を求める．O((K^2)*logN).
    T calc(size_type n) const {
        const std::vector<T> &&x = f(n);
        T res = 0;
        for(size_type i = 0; i < m_k; ++i) res += m_a[i] * x[i];
        return res;
    }
    // a[l:r]を求める．O((K^2)*logN+K*(r-l)).
    std::vector<T> calc(size_type l, size_type r) const {
        assert(l < r);
        std::vector<T> res(r - l);
        std::vector<T> &&x = f(l);
        for(size_type i = l; i < r; ++i) {
            for(size_type j = 0; j < m_k; ++j) res[i - l] += m_a[j] * x[j];
            if(i == r - 1) break;
            x = add(x);
        }
        return res;
    }
};

}  // namespace algorithm

#endif
