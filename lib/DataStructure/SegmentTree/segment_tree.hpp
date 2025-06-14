#ifndef ALGORITHM_SEGMENT_TREE_HPP
#define ALGORITHM_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

namespace segment_tree {

template <class Monoid>
class SegmentTree {
public:
    using monoid_type = Monoid;
    using value_type = monoid_type::value_type;

private:
    int m_sz;                         // m_sz:=(要素数).
    int m_n;                          // m_n:=(完全二分木の葉数).
    std::vector<monoid_type> m_tree;  // m_tree(2n)[]:=(完全二分木). 1-based index.

    void update(int k) { m_tree[k] = m_tree[k << 1] * m_tree[k << 1 | 1]; }
    void build() {
        for(int l = m_n >> 1, r = (m_n + m_sz - 1) >> 1; l >= 1; l >>= 1, r >>= 1) {
            for(int i = r; i >= l; --i) update(i);
        }
    }

public:
    // constructor. O(N).
    SegmentTree() : SegmentTree(0) {};
    explicit SegmentTree(int n) : m_sz(n), m_n(1) {
        assert(n >= 0);
        while(m_n < m_sz) m_n <<= 1;
        m_tree.assign(2 * m_n, monoid_type::one());
    }
    explicit SegmentTree(int n, const value_type &a) : SegmentTree(n, monoid_type(a)) {}
    explicit SegmentTree(int n, const monoid_type &a) : SegmentTree(n) {
        std::fill_n(m_tree.begin() + m_n, n, a);
        build();
    }
    template <std::input_iterator InputIter>
    explicit SegmentTree(InputIter first, InputIter last) : m_n(1), m_tree(first, last) {
        m_sz = m_tree.size();
        while(m_n < m_sz) m_n <<= 1;
        m_tree.reserve(2 * m_n);
        m_tree.insert(m_tree.begin(), m_n, monoid_type::one());
        m_tree.resize(2 * m_n, monoid_type::one());
        build();
    }
    template <typename T>
    explicit SegmentTree(std::initializer_list<T> il) : SegmentTree(il.begin(), il.end()) {}

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const value_type &a) { set(k, monoid_type(a)); }
    void set(int k, const monoid_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        m_tree[k] = a;
        while(k >>= 1) update(k);
    }
    // k番目の要素を取得する．O(1).
    value_type prod(int k) const {
        assert(0 <= k and k < size());
        return m_tree[k + m_n].value();
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    value_type prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        monoid_type &&val_l = monoid_type::one(), &&val_r = monoid_type::one();
        for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = val_l * m_tree[l++];
            if(r & 1) val_r = m_tree[--r] * val_r;
        }
        return (val_l * val_r).value();
    }
    // 区間全体の要素の総積を取得する．O(1).
    value_type prod_all() const { return m_tree[1].value(); }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <bool (*pred)(value_type)>
    int most_right(int l) const {
        return most_right(l, [](const value_type &x) -> bool { return pred(x); });
    }
    template <typename Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        assert(0 <= l and l <= size());
        assert(pred(monoid_type::one().value()));
        if(l == m_sz) return m_sz;
        l += m_n;
        monoid_type &&val = monoid_type::one();
        do {
            while(!(l & 1)) l >>= 1;
            monoid_type &&tmp = val * m_tree[l];
            if(!pred(tmp.value())) {
                while(l < m_n) {
                    l <<= 1;
                    tmp = val * m_tree[l];
                    if(pred(tmp.value())) val = tmp, ++l;
                }
                return l - m_n;
            }
            val = tmp, ++l;
        } while((l & -l) != l);
        return m_sz;
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <bool (*pred)(value_type)>
    int most_left(int r) const {
        return most_left(r, [](const value_type &x) -> bool { return pred(x); });
    }
    template <typename Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        assert(0 <= r and r <= size());
        assert(pred(monoid_type::one().value()));
        if(r == 0) return 0;
        r += m_n;
        monoid_type &&val = monoid_type::one();
        do {
            --r;
            while(r > 1 and (r & 1)) r >>= 1;
            monoid_type &&tmp = m_tree[r] * val;
            if(!pred(tmp.value())) {
                while(r < m_n) {
                    r = r << 1 | 1;
                    tmp = m_tree[r] * val;
                    if(pred(tmp.value())) val = tmp, --r;
                }
                return r + 1 - m_n;
            }
            val = tmp;
        } while((r & -r) != r);
        return 0;
    }
    void reset() { std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, monoid_type::one()); }

    friend std::ostream &operator<<(std::ostream &os, const SegmentTree &rhs) {
        os << "[\n";
        for(int l = 1, r = 2; r <= 2 * rhs.m_n; l <<= 1, r <<= 1) {
            for(int i = l; i < r; ++i) os << (i == l ? "  [" : " ") << rhs.m_tree[i].value();
            os << "]\n";
        }
        return os << "]";
    }
};

template <typename S>
using range_minimum_segment_tree = SegmentTree<algebra::monoid::minimum<S>>;

template <typename S>
using range_maximum_segment_tree = SegmentTree<algebra::monoid::maximum<S>>;

template <typename S>
using range_sum_segment_tree = SegmentTree<algebra::monoid::addition<S>>;

}  // namespace segment_tree

}  // namespace algorithm

#endif
