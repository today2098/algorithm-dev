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

    static int s_sz;
    static std::vector<long long> s_montmort;  // m_montmort[k]:=(k項目のモンモール数).

    Montmort() = default;
    ~Montmort() = default;

public:
    static constexpr int modulus() { return mod; }
    // k項目のモンモール数を返す．O(1).
    static long long montmort(int k) {
        assert(k >= 0);
        if(s_sz <= k) resize(k + 1);
        return s_montmort[k];
    }
    static void resize(int sz) {
        assert(0 <= sz);
        if(sz < 2) sz = 2;
        s_montmort.resize(sz);
        for(int i = s_sz; i < sz; ++i) s_montmort[i] = (i - 1) * (s_montmort[i - 2] + s_montmort[i - 1]) % mod;
        s_sz = sz;
    }
};

template <int mod>
int Montmort<mod>::s_sz = 2;

template <int mod>
std::vector<long long> Montmort<mod>::s_montmort({1, 0});

// モンモール数．O(K).
constexpr long long montmort(int k) {
    assert(k >= 0);
    if(k == 0) return 1;
    long long a = 1, b = 0;
    for(int i = 2; i <= k; ++i) {
        long long c = (i - 1) * (a + b);
        a = b;
        b = c;
    }
    return b;
}

// モンモール数（mod付き）．O(K).
constexpr long long montmort(int k, int mod) {
    assert(k >= 0);
    assert(mod >= 1);
    if(k == 0) return 1 % mod;
    long long a = 1, b = 0;
    for(int i = 2; i <= k; ++i) {
        long long c = (i - 1) * (a + b) % mod;
        a = b;
        b = c;
    }
    return b;
}

}  // namespace montmort

}  // namespace algorithm

#endif
