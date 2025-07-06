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
    size_type m_k;                // m_k:=(階数).
    std::vector<value_type> m_a;  // m_a[]:=(初項数列).
    std::vector<value_type> m_d;  // m_d[]:=(係数数列).

    // f(n)->f(n+1). O(K).
    std::vector<value_type> add(const std::vector<value_type> &x) const {
        std::vector<value_type> y(m_k);
        y[0] = x[m_k - 1] * m_d[0];
        for(size_type i = 1; i < m_k; ++i) y[i] = x[i - 1] + x[m_k - 1] * m_d[i];
        return y;
    }
    // f(n)->f(2*n). O(K^2).
    std::vector<value_type> mul(const std::vector<value_type> &x) const {
        std::vector<value_type> y(m_k, 0);
        std::vector<value_type> t = x;
        for(size_type i = 0; i < m_k; ++i) {
            for(size_type j = 0; j < m_k; ++j) y[j] += x[i] * t[j];
            if(i == m_k - 1) break;
            t = add(t);
        }
        return y;
    }
    // f(n)を返す．O((K^2)*logN).
    std::vector<value_type> f(size_type n) const {
        if(n == 0) {
            std::vector<value_type> x(m_k, 0);
            x[0] = 1;
            return x;  // f(0).
        }
        std::vector<value_type> &&x = mul(f(n >> 1));
        if(n & 1ULL) x = add(x);
        return x;
    }

public:
    Kitamasa() : Kitamasa({0, 1}, {1, 1}) {}  // フィボナッチ数列．
    template <std::input_iterator InputIter>
    explicit Kitamasa(InputIter a_first, InputIter a_last, InputIter d_first, InputIter d_last) : m_a(a_first, a_last), m_d(d_first, d_last) {
        assert(m_a.size() >= 1);
        assert(m_a.size() == m_d.size());
        m_k = m_a.size();
    }
    explicit Kitamasa(std::vector<value_type> a, std::vector<value_type> d) : m_k(a.size()), m_a(std::move(a)), m_d(std::move(d)) {
        assert(m_a.size() >= 1);
        assert(m_a.size() == m_d.size());
    }

    value_type operator[](size_type n) const { return calc(n); }

    // a[n]を求める．O((K^2)*log N).
    value_type calc(size_type n) const {
        std::vector<value_type> &&x = f(n);
        value_type res = 0;
        for(size_type i = 0; i < m_k; ++i) res += m_a[i] * x[i];
        return res;
    }
    // a[l:r]を求める．O((K^2)*log(N) + K*(r-l)).
    std::vector<value_type> calc(size_type l, size_type r) const {
        assert(l < r);
        std::vector<value_type> res(r - l);
        std::vector<value_type> &&x = f(l);
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
