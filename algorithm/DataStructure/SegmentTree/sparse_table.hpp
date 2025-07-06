#ifndef ALGORITHM_SPARSE_TABLE_HPP
#define ALGORITHM_SPARSE_TABLE_HPP 1

#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <vector>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

template <class IdempotentSemigroup>
class SparseTable {
public:
    using semigroup_type = IdempotentSemigroup;
    using value_type = typename semigroup_type::value_type;
    using size_type = std::size_t;

private:
    size_type m_sz;                                    // m_sz:=(要素数).
    std::vector<size_type> m_lg;                       // m_lg[x]:=floor(log2(x)).
    std::vector<std::vector<semigroup_type>> m_table;  // m_table[k][l]:=(区間[l,l+2^k)の総積).

public:
    // constructor. O(N log N).
    SparseTable() : m_sz(0), m_lg({0}), m_table({{}}) {}
    template <std::input_iterator InputIter>
    explicit SparseTable(InputIter first, InputIter last) : m_table(1, std::vector<semigroup_type>(first, last)) {
        m_sz = m_table[0].size();
        m_lg.assign(m_sz + 1, 0);
        for(size_type i = 2; i <= m_sz; ++i) m_lg[i] = m_lg[i >> 1] + 1;
        m_table.resize(m_lg[m_sz] + 1);
        for(size_type k = 1; k <= m_lg[m_sz]; ++k) {
            size_type n = m_sz - (1U << k) + 1;
            m_table[k].resize(n);
            for(size_type i = 0; i < n; ++i) m_table[k][i] = m_table[k - 1][i] * m_table[k - 1][i + (1U << (k - 1))];
        }
    }
    template <typename T>
    explicit SparseTable(std::initializer_list<T> il) : SparseTable(il.begin(), il.end()) {}

    // 要素数を取得する．
    size_type size() const { return m_sz; }
    // k番目の要素を取得する．O(1).
    value_type prod(size_type k) const {
        assert(k < size());
        return m_table[0][k].value();
    }
    // 区間[l,r)の要素の総積を求める．O(1).
    value_type prod(size_type l, size_type r) const {
        assert(l < r and r <= size());
        size_type k = m_lg[r - l];
        return (m_table[k][l] * m_table[k][r - (1U << k)]).value();
    }
    // 区間全体の要素の総積を求める．O(1).
    value_type prod_all() const {
        assert(size() > 0);
        return (m_table.back().front() * m_table.back().back()).value();
    }

    friend std::ostream &operator<<(std::ostream &os, const SparseTable &rhs) {
        if(rhs.m_sz == 0) return os << "[\n]";
        os << "[\n";
        for(size_type k = 0; k <= rhs.m_lg.back(); ++k) {
            for(int i = 0, end = rhs.m_table[k].size(); i < end; ++i) os << (i == 0 ? "  [" : " ") << rhs.m_table[k][i];
            os << "]\n";
        }
        return os << "]";
    }
};

namespace sparse_table {

template <typename S>
using range_minimum_sparse_table = SparseTable<algebra::Semigroup<S, algebra::binary_operator::min<S>>>;

template <typename S>
using range_maximum_sparse_table = SparseTable<algebra::Semigroup<S, algebra::binary_operator::max<S>>>;

template <typename S>
using range_gcd_sparse_table = SparseTable<algebra::Semigroup<S, algebra::binary_operator::gcd<S>>>;

template <typename S>
using range_lcm_sparse_table = SparseTable<algebra::Semigroup<S, algebra::binary_operator::lcm<S>>>;

}  // namespace sparse_table

}  // namespace algorithm

#endif
