#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP
#define ALGORITHM_PASCAL_TRIANGLE_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

template <int mod>
class PascalTriangle {
    static_assert(mod >= 1);

    int m_sz;
    std::vector<std::vector<long long>> m_c;  // m_c[n][k]:=(C(n,n-k) and C(n,k)).

public:
    // constructor. O(N^2).
    PascalTriangle() : PascalTriangle(0) {}
    PascalTriangle(int n) : m_sz(n), m_c(n) {
        for(int i = 0; i < n; ++i) {
            const int m = (i + 2) / 2;
            m_c[i].resize(m);
            m_c[i][0] = 1 % mod;
            for(int j = 1; j < m; ++j) m_c[i][j] = (m_c[i - 1][j - 1] + (i - 1 - j < j ? m_c[i - 1][i - 1 - j] : m_c[i - 1][j])) % mod;
        }
    }

    static constexpr int modulus() { return mod; }
    // 組合せ．O(1).
    long long nCk(int n, int k) const {
        assert(n >= 0);
        assert(k >= 0);
        if(k > n) return 0;
        return (n - k < k ? m_c[n][n - k] : m_c[n][k]);
    }
};

}  // namespace algorithm

#endif
