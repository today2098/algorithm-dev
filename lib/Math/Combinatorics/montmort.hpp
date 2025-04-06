#ifndef ALGORITHM_MONTMORT_HPP
#define ALGORTIHM_MONTMORT_HPP 1

#include <cassert>
#include <cmath>
#include <vector>

namespace algorithm {

namespace montmort {

// COMPLETE_PERMUTATIONS_PROBABILITY:=(無限個の要素を並び替えたときに完全順列となる確率).
const double COMPLETE_PERMUTATIONS_PROBABILITY = std::exp(-1.0);

// 完全順列の総数，モンモール数．
template <int mod>
class Montmort {
    static_assert(mod >= 2);

private:
    int m_sz;
    std::vector<long long> m_montmort;  // m_montmort[k]:=(k項目のモンモール数).

public:
    Montmort() : Montmort(2) {}
    explicit Montmort(int n) : m_sz(n), m_montmort(n) {
        assert(n >= 2);
        m_montmort[0] = 1;
        m_montmort[1] = 0;
        for(int i = 2; i < m_sz; ++i) m_montmort[i] = (i - 1) * (m_montmort[i - 2] + m_montmort[i - 1]) % mod;
    }

    static constexpr int modulus() { return mod; }
    int size() const { return m_sz; }
    // k項目のモンモール数を取得する．O(1).
    long long montmort(int k) const {
        assert(0 <= k and k < size());
        return m_montmort[k];
    }
};

// モンモール数．O(K).
constexpr long long montmort(int k) {
    assert(k >= 0);
    long long a[2] = {1, 0};
    if(k < 2) return a[k];
    for(int i = 2; i <= k; ++i) {
        long long tmp = (i - 1) * (a[0] + a[1]);
        a[0] = a[1];
        a[1] = tmp;
    }
    return a[1];
}

// モンモール数（mod付き）．O(K).
constexpr long long montmort(int k, int mod) {
    assert(k >= 0);
    assert(mod >= 1);
    long long a[2] = {1, 0};
    if(k < 2) return a[k] % mod;
    for(int i = 2; i <= k; ++i) {
        long long tmp = (i - 1) * (a[0] + a[1]) % mod;
        a[0] = a[1];
        a[1] = tmp;
    }
    return a[1];
}

}  // namespace montmort

}  // namespace algorithm

#endif
