#ifndef ALGORITHM_PASCAL_TRIANGLE_HPP
#define ALGORITHM_PASCAL_TRIANGLE_HPP 1

/**
 * @brief Pascal's Triangle（パスカルの三角形）
 * @docs docs/Math/Combinatorics/pascal_triangle.md
 */

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

template <typename Type = long long>
class PascalTriangle {
public:
    int m_mx;                             // m_mx:=(引数nの最大値).
    std::vector<std::vector<Type> > m_c;  // m_c[n][k]:=(C(n,k) and C(n,n-k)).

public:
    // constructor. O(N^2).
    PascalTriangle() : PascalTriangle(51e2) {}
    explicit PascalTriangle(int mx) : m_mx(mx), m_c(mx + 1) {
        assert(mx >= 0);
        for(int n = 0; n <= m_mx; ++n) {
            const int len = (n + 2) / 2;
            m_c[n].resize(len);
            m_c[n][0] = 1;
            for(int k = 1; k < len; ++k) m_c[n][k] = nCk(n - 1, k - 1) + nCk(n - 1, k);
        }
    }

    // 組合せ．O(1).
    Type nCk(int n, int k) const {
        assert(0 <= n and n <= m_mx);
        assert(k >= 0);
        if(k > n) return 0;
        return (k <= n - k ? m_c[n][k] : m_c[n][n - k]);
    }
    // 重複組合せ．O(1).
    Type nHk(int n, int k) const {
        assert(n >= 1 and k >= 0);
        return nCk(k + n - 1, k);
    }
};

}  // namespace algorithm

#endif
