#ifndef ALGORITHM_SEGMENT_TREE_HPP
#define ALGORITHM_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

template <class Monoid>
class SegmentTreeBase {
public:
    using monoid_type = Monoid;

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
    SegmentTreeBase() : SegmentTreeBase(0) {};
    explicit SegmentTreeBase(int n) : m_sz(n), m_n(1) {
        assert(n >= 0);
        while(m_n < m_sz) m_n <<= 1;
        m_tree.assign(2 * m_n, monoid_type::one());
    }
    explicit SegmentTreeBase(int n, const monoid_type &a) : SegmentTreeBase(n) {
        std::fill_n(m_tree.begin() + m_n, n, a);
        build();
    }
    template <std::input_iterator InputIter>
    explicit SegmentTreeBase(InputIter first, InputIter last) : m_n(1), m_tree(first, last) {
        m_sz = m_tree.size();
        while(m_n < m_sz) m_n <<= 1;
        m_tree.reserve(2 * m_n);
        m_tree.insert(m_tree.begin(), m_n, monoid_type::one());
        m_tree.resize(2 * m_n, monoid_type::one());
        build();
    }
    template <std::ranges::input_range R>
    explicit SegmentTreeBase(R &&r) : SegmentTreeBase(std::ranges::begin(r), std::ranges::end(r)) {}
    template <typename T>
    explicit SegmentTreeBase(std::initializer_list<T> il) : SegmentTreeBase(il.begin(), il.end()) {}

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const monoid_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        m_tree[k] = a;
        while(k >>= 1) update(k);
    }
    // k番目の要素を取得する．O(1).
    monoid_type prod(int k) const {
        assert(0 <= k and k < size());
        return m_tree[k + m_n];
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    monoid_type prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        monoid_type val_l = monoid_type::one(), val_r = monoid_type::one();
        for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = val_l * m_tree[l++];
            if(r & 1) val_r = m_tree[--r] * val_r;
        }
        return val_l * val_r;
    }
    // 区間全体の要素の総積を取得する．O(1).
    monoid_type prod_all() const { return m_tree[1]; }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, monoid_type>::value);
        assert(0 <= l and l <= size());
        assert(pred(monoid_type::one()));
        if(l == m_sz) return m_sz;
        l += m_n;
        monoid_type val = monoid_type::one();
        do {
            while(!(l & 1)) l >>= 1;
            monoid_type tmp = val * m_tree[l];
            if(!pred(tmp)) {
                while(l < m_n) {
                    l <<= 1;
                    tmp = val * m_tree[l];
                    if(pred(tmp)) val = tmp, ++l;
                }
                return l - m_n;
            }
            val = tmp, ++l;
        } while((l & -l) != l);
        return m_sz;
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, monoid_type>::value);
        assert(0 <= r and r <= size());
        assert(pred(monoid_type::one()));
        if(r == 0) return 0;
        r += m_n;
        monoid_type val = monoid_type::one();
        do {
            --r;
            while(r > 1 and (r & 1)) r >>= 1;
            monoid_type tmp = m_tree[r] * val;
            if(!pred(tmp)) {
                while(r < m_n) {
                    r = r << 1 | 1;
                    tmp = m_tree[r] * val;
                    if(pred(tmp)) val = tmp, --r;
                }
                return r + 1 - m_n;
            }
            val = tmp;
        } while((r & -r) != r);
        return 0;
    }
    void reset() { std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, monoid_type::one()); }

    friend std::ostream &operator<<(std::ostream &os, const SegmentTreeBase &rhs) {
        os << "[\n";
        for(int l = 1, r = 2; r <= 2 * rhs.m_n; l <<= 1, r <<= 1) {
            for(int i = l; i < r; ++i) os << (i == l ? "  [" : " ") << rhs.m_tree[i];
            os << "]\n";
        }
        return os << "]";
    }
};

template <typename S, class Monoid>
class SegmentTree : public SegmentTreeBase<Monoid> {
public:
    using base_type = SegmentTreeBase<Monoid>;
    using value_type = S;
    using typename base_type::monoid_type;

    // constructor. O(N).
    SegmentTree() : base_type() {};
    explicit SegmentTree(int n) : base_type(n) {}
    explicit SegmentTree(int n, const value_type &a) : base_type(n, a) {}
    template <std::input_iterator InputIter>
    explicit SegmentTree(InputIter first, InputIter last) : base_type(first, last) {}
    template <std::ranges::input_range R>
    explicit SegmentTree(R &&r) : base_type(std::forward<R>(r)) {}
    template <typename T>
    explicit SegmentTree(std::initializer_list<T> il) : SegmentTree(std::move(il)) {}

    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const value_type &a) { base_type::set(k, a); }
    // k番目の要素を取得する．O(1).
    value_type prod(int k) const { return base_type::prod(k).value(); }
    // 区間[l,r)の要素の総積を求める．O(log N).
    value_type prod(int l, int r) const { return base_type::prod(l, r).value(); }
    // 区間全体の要素の総積を取得する．O(1).
    value_type prod_all() const { return base_type::prod_all().value(); }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        return base_type::most_right(l, [&](const monoid_type &x) -> bool { return pred(x.value()); });
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        return base_type::most_left(r, [&](const monoid_type &x) -> bool { return pred(x.value()); });
    }
};

template <typename S>
using RangeMinimumSegmentTree = SegmentTree<S, algebra::monoid::minimum<S>>;

template <typename S>
using RangeMaximumSegmentTree = SegmentTree<S, algebra::monoid::maximum<S>>;

template <typename S>
using RangeSumSegmentTree = SegmentTree<S, algebra::monoid::addition<S>>;

template <typename S>
using RangeProductSegmentTree = SegmentTree<S, algebra::monoid::multiplication<S>>;

}  // namespace algorithm

#endif
