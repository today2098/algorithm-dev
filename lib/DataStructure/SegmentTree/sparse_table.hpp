#ifndef ALGORITHM_SPARSE_TABLE_HPP
#define ALGORITHM_SPARSE_TABLE_HPP 1

/**
 * @brief Sparse Table
 * @docs docs/DataStructure/SegmentTree/sparse_table.md
 */

#include <cassert>
#include <functional>
#include <vector>

namespace algorithm {

// 静的な数列に対し，結合則 (A•B)•C=A•(B•C) と冪等性 A•A=A が成り立つ演算（min/max, gcd/lcm, bitwise-and/orなど）の区間クエリを求める．
template <typename S>  // S:冪等半群の型.
class SparseTable {
    using Op = std::function<S(const S &, const S &)>;

    Op m_op;                               // S m_op(S,S):=(二項演算関数).
    int m_sz;                              // m_sz:=(要素数).
    std::vector<int> m_lb;                 // m_lb[x]:=floor(log2(x)).
    std::vector<std::vector<S> > m_table;  // m_table[k][i]:=(区間[i,i+2^k)の総積).

public:
    using value_type = S;

    // constructor. O(N*logN).
    SparseTable() {}
    explicit SparseTable(const Op &op, const std::vector<S> &v) : m_op(op), m_sz(v.size()), m_lb(v.size() + 1, 0) {
        for(int i = 2; i <= size(); ++i) m_lb[i] = m_lb[i >> 1] + 1;
        m_table.resize(m_lb[size()] + 1);
        m_table[0].assign(v.begin(), v.end());
        for(int k = 1; k <= m_lb[size()]; ++k) {
            int n = size() - (1 << k) + 1;
            m_table[k].resize(n);
            for(int i = 0; i < n; ++i) m_table[k][i] = m_op(m_table[k - 1][i], m_table[k - 1][i + (1 << (k - 1))]);
        }
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // 区間[l,r)の総積を求める．O(1).
    S fold(int l, int r) const {
        assert(0 <= l and l < r and r <= size());
        int k = m_lb[r - l];
        return m_op(m_table[k][l], m_table[k][r - (1 << k)]);
    }
};

}  // namespace algorithm

#endif
