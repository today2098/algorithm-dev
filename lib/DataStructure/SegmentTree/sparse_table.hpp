#ifndef ALGORITHM_SPARSE_TABLE_HPP
#define ALGORITHM_SPARSE_TABLE_HPP 1

#include <cassert>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithm {

// 静的な数列に対し，結合則 (A•B)•C=A•(B•C) と冪等性 A•A=A が成り立つ演算（min, max, gcd, lcm, bitwise-and, bitwise-orなど）の区間クエリを求める．
template <typename S, auto op>
class SparseTable {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);

public:
    using value_type = S;
    using size_type = std::size_t;
    using iterator = std::vector<value_type>::const_iterator;
    using const_iterator = std::vector<value_type>::const_iterator;
    using reverse_iterator = std::vector<value_type>::const_reverse_iterator;
    using const_reverse_iterator = std::vector<value_type>::const_reverse_iterator;

private:
    size_type m_sz;                                // m_sz:=(要素数).
    std::vector<size_type> m_lg;                   // m_lg[x]:=floor(log2(x)).
    std::vector<std::vector<value_type>> m_table;  // m_table[k][l]:=(区間[l,l+2^k)の総積).

    void build() {
        for(size_type i = 2; i <= m_sz; ++i) m_lg[i] = m_lg[i >> 1] + 1;
        m_table.resize(m_lg[m_sz] + 1);
        for(size_type k = 1; k <= m_lg[size()]; ++k) {
            size_type n = m_sz - (1U << k) + 1;
            m_table[k].resize(n);
            for(size_type i = 0; i < n; ++i) m_table[k][i] = op(m_table[k - 1][i], m_table[k - 1][i + (1U << (k - 1))]);
        }
    }

public:
    // constructor. O(N*logN).
    SparseTable() : m_sz(0) {}
    explicit SparseTable(const std::vector<value_type> &v) : m_sz(v.size()), m_lg(v.size() + 1, 0), m_table(1, v) {
        build();
    }
    explicit SparseTable(std::vector<value_type> &&v) : m_sz(v.size()), m_lg(v.size() + 1, 0), m_table(1) {
        m_table[0] = std::move(v);
        build();
    }

    // 二項演算関数を取得する．
    static constexpr auto operation() { return op; }
    // 要素数を取得する．
    size_type size() const { return m_sz; }
    // k番目の要素を取得する．O(1).
    value_type prod(size_type k) const {
        assert(k < size());
        return m_table[0][k];
    }
    // 区間[l,r)の総積を求める．O(1).
    value_type prod(size_type l, size_type r) const {
        assert(l < r and r <= size());
        size_type k = m_lg[r - l];
        return op(m_table[k][l], m_table[k][r - (1U << k)]);
    }

    const_iterator begin() const { return m_table[0].begin(); }
    const_iterator end() const { return m_table[0].end(); }
    const_iterator cbegin() const { return m_table[0].cbegin(); }
    const_iterator cend() const { return m_table[0].cend(); }
    const_reverse_iterator rbegin() const { return m_table[0].rbegin(); }
    const_reverse_iterator rend() const { return m_table[0].rend(); }
    const_reverse_iterator crbegin() const { return m_table[0].crbegin(); }
    const_reverse_iterator crend() const { return m_table[0].crend(); }
};

}  // namespace algorithm

#endif
