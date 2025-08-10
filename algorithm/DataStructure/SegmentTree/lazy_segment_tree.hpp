#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP
#define ALGORITHM_LAZY_SEGMENT_TREE_HPP 1

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

template <class ActedMonoid, class OperatorMonoid>
class LazySegmentTreeBase {
public:
    using acted_monoid_type = ActedMonoid;
    using operator_monoid_type = OperatorMonoid;
    using acted_value_type = typename acted_monoid_type::value_type;
    using operator_value_type = typename operator_monoid_type::value_type;

private:
    int m_sz;                                  // m_sz:=(要素数).
    int m_n;                                   // m_n:=(完全二分木の葉数).
    int m_depth;                               // m_depth:=(完全二分木の深さ).
    std::vector<acted_monoid_type> m_tree;     // m_tree(2n)[]:=(完全二分木). 1-based index.
    std::vector<operator_monoid_type> m_lazy;  // m_lazy(n)[k]:=(m_tree[k]の子 (m_tree[2k], m_tree[2k+1]) に対する遅延評価).

    void apply_with_lazy(int k, const operator_monoid_type &f) {
        m_tree[k] = f.act(m_tree[k]);
        if(k < m_n) m_lazy[k] = f * m_lazy[k];
    }
    void push(int k) {
        apply_with_lazy(k << 1, m_lazy[k]);
        apply_with_lazy(k << 1 | 1, m_lazy[k]);
        m_lazy[k] = operator_monoid_type::one();
    }
    void update(int k) { m_tree[k] = m_tree[k << 1] * m_tree[k << 1 | 1]; }
    void build() {
        for(int i = 1; i <= m_depth; ++i) {
            int l = m_n >> i, r = (m_n + m_sz - 1) >> i;
            for(int j = r; j >= l; --j) update(j);
        }
    }

public:
    // constructor. O(N).
    LazySegmentTreeBase() : LazySegmentTreeBase(0) {}
    explicit LazySegmentTreeBase(int n) : m_sz(n), m_n(1), m_depth(0) {
        assert(n >= 0);
        while(m_n < m_sz) m_n <<= 1, ++m_depth;
        m_tree.assign(2 * m_n, acted_monoid_type::one());
        m_lazy.assign(m_n, operator_monoid_type::one());
    }
    explicit LazySegmentTreeBase(int n, const acted_monoid_type &a) : LazySegmentTreeBase(n) {
        std::fill_n(m_tree.begin() + m_n, n, a);
        build();
    }
    template <std::input_iterator InputIter>
    explicit LazySegmentTreeBase(InputIter first, InputIter last) : m_n(1), m_depth(0), m_tree(first, last) {
        m_sz = m_tree.size();
        while(m_n < m_sz) m_n <<= 1, ++m_depth;
        m_tree.reserve(2 * m_n);
        m_tree.insert(m_tree.begin(), m_n, acted_monoid_type::one());
        m_tree.resize(2 * m_n, acted_monoid_type::one());
        m_lazy.resize(m_n, operator_monoid_type::one());
        build();
    }
    template <std::ranges::input_range R>
    explicit LazySegmentTreeBase(R &&r) : LazySegmentTreeBase(std::ranges::begin(r), std::ranges::end(r)) {}
    template <typename T>
    explicit LazySegmentTreeBase(std::initializer_list<T> il) : LazySegmentTreeBase(il.begin(), il.end()) {}

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const acted_monoid_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = a;
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // k番目の要素を作用素fを用いて更新する．O(log N).
    void apply(int k, const operator_monoid_type &f) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = f.act(m_tree[k]);
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,r)の要素を作用素fを用いて更新する．O(log N).
    void apply(int l, int r, const operator_monoid_type &f) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return;
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if((l >> i) << i != l) push(l >> i);
            if((r >> i) << i != r) push((r - 1) >> i);
        }
        for(int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
            if(ll & 1) apply_with_lazy(ll++, f);
            if(rr & 1) apply_with_lazy(--rr, f);
        }
        for(int i = 1; i <= m_depth; ++i) {
            if((l >> i) << i != l) update(l >> i);
            if((r >> i) << i != r) update((r - 1) >> i);
        }
    }
    // k番目の要素を求める．O(log N).
    acted_monoid_type prod(int k) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        return m_tree[k];
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    acted_monoid_type prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return acted_monoid_type::one();
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if((l >> i) << i != l) push(l >> i);
            if((r >> i) << i != r) push((r - 1) >> i);
        }
        acted_monoid_type val_l = acted_monoid_type::one(), val_r = acted_monoid_type::one();
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = val_l * m_tree[l++];
            if(r & 1) val_r = m_tree[--r] * val_r;
        }
        return val_l * val_r;
    }
    // 区間全体の要素の総積を取得する．O(1).
    acted_monoid_type prod_all() const { return m_tree[1]; }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <class Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, acted_monoid_type>::value);
        assert(0 <= l and l <= size());
        assert(pred(acted_monoid_type::one()));
        if(l == m_sz) return m_sz;
        l += m_n;
        for(int i = m_depth; i >= 1; --i) push(l >> i);
        acted_monoid_type val = acted_monoid_type::one();
        do {
            while(!(l & 1)) l >>= 1;
            acted_monoid_type tmp = val * m_tree[l];
            if(!pred(tmp)) {
                while(l < m_n) {
                    push(l);
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
    template <class Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, acted_monoid_type>::value);
        assert(0 <= r and r <= size());
        assert(pred(acted_monoid_type::one()));
        if(r == 0) return 0;
        r += m_n;
        for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);
        acted_monoid_type val = acted_monoid_type::one();
        do {
            --r;
            while(r > 1 and (r & 1)) r >>= 1;
            acted_monoid_type tmp = m_tree[r] * val;
            if(!pred(tmp)) {
                while(r < m_n) {
                    push(r);
                    r = r << 1 | 1;
                    tmp = m_tree[r] * val;
                    if(pred(tmp)) val = tmp, --r;
                }
                return r - m_n + 1;
            }
            val = tmp;
        } while((r & -r) != r);
        return 0;
    }
    void reset() {
        std::fill(m_tree.begin() + 1, m_tree.end(), acted_monoid_type::one());
        std::fill(m_lazy.begin() + 1, m_lazy.end(), operator_monoid_type::one());
    }

    friend std::ostream &operator<<(std::ostream &os, const LazySegmentTreeBase &rhs) {
        os << "{\n  [\n";
        for(int i = 0; i <= rhs.m_depth; ++i) {
            int l = 1 << i, r = 2 << i;
            for(int j = l; j < r; ++j) os << (j == l ? "    [" : " ") << rhs.m_tree[j];
            os << "]\n";
        }
        os << "  ],\n  [\n";
        for(int i = 0; i < rhs.m_depth; ++i) {
            int l = 1 << i, r = 2 << i;
            for(int j = l; j < r; ++j) os << (j == l ? "    [" : " ") << rhs.m_lazy[j];
            os << "]\n";
        }
        return os << "  ]\n}";
    }
};

template <typename S, typename F, class ActedMonoid, class OperatorMonoid>
class LazySegmentTree : public LazySegmentTreeBase<ActedMonoid, OperatorMonoid> {
public:
    using base_type = LazySegmentTreeBase<ActedMonoid, OperatorMonoid>;
    using typename base_type::acted_monoid_type;
    using typename base_type::operator_monoid_type;
    using acted_value_type = S;
    using operator_value_type = F;

    // constructor. O(N).
    LazySegmentTree() : base_type() {}
    explicit LazySegmentTree(int n) : base_type(n) {}
    explicit LazySegmentTree(int n, const acted_value_type &a) : base_type(n, a) {}
    template <std::input_iterator InputIter>
    explicit LazySegmentTree(InputIter first, InputIter last) : base_type(first, last) {}
    template <std::ranges::input_range R>
    explicit LazySegmentTree(R &&r) : base_type(std::forward<R>(r)) {}
    template <typename T>
    explicit LazySegmentTree(std::initializer_list<T> il) : base_type(std::move(il)) {}

    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const acted_value_type &a) { base_type::set(k, a); }
    // k番目の要素を作用素fを用いて更新する．O(log N).
    void apply(int k, const operator_value_type &f) { base_type::apply(k, f); }
    // 区間[l,r)の要素を作用素fを用いて更新する．O(log N).
    void apply(int l, int r, const operator_value_type &f) { base_type::apply(l, r, f); }
    // k番目の要素を求める．O(log N).
    acted_value_type prod(int k) { return base_type::prod(k).value(); }
    // 区間[l,r)の要素の総積を求める．O(log N).
    acted_value_type prod(int l, int r) { return base_type::prod(l, r).value(); }
    // 区間全体の要素の総積を取得する．O(1).
    acted_value_type prod_all() const { return base_type::prod_all().value(); }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, acted_value_type>::value);
        return base_type::most_right(l, [&](const acted_monoid_type &x) -> bool { return pred(x.value()); });
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, acted_value_type>::value);
        return base_type::most_left(r, [&](const acted_monoid_type &x) -> bool { return pred(x.value()); });
    }
};

template <typename T>
struct LengthAwareType {
    using value_type = T;

    value_type val;
    int len;

    constexpr LengthAwareType() : val(value_type()), len(0) {}
    constexpr LengthAwareType(const value_type &val) : val(val), len(1) {}
    constexpr LengthAwareType(const value_type &val, int len) : val(val), len(len) {}

    friend constexpr LengthAwareType operator+(const LengthAwareType &lhs, const LengthAwareType &rhs) { return {lhs.val + rhs.val, lhs.len + rhs.len}; }
    friend std::ostream &operator<<(std::ostream &os, const LengthAwareType &rhs) { return os << "{" << rhs.val << ", " << rhs.len << "}"; }
};

template <typename T, typename S, typename F, class ActedMonoid, class OperatorMonoid>
class LengthAwareLazySegmentTree : public LazySegmentTree<S, F, ActedMonoid, OperatorMonoid> {
public:
    using base_type = LazySegmentTree<S, F, ActedMonoid, OperatorMonoid>;
    using typename base_type::acted_monoid_type;
    using typename base_type::acted_value_type;
    using typename base_type::operator_monoid_type;
    using typename base_type::operator_value_type;
    using value_type = T;

    // constructor. O(N).
    LengthAwareLazySegmentTree() : base_type() {}
    explicit LengthAwareLazySegmentTree(int n) : base_type(n, value_type()) {}
    explicit LengthAwareLazySegmentTree(int n, const value_type &a) : base_type(n, a) {}
    template <std::input_iterator InputIter>
    explicit LengthAwareLazySegmentTree(InputIter first, InputIter last) : LengthAwareLazySegmentTree(std::ranges::subrange(first, last)) {}
    template <std::ranges::input_range R>
    explicit LengthAwareLazySegmentTree(R &&r) : base_type(std::ranges::transform_view(r, [](const auto &x) -> acted_value_type { return static_cast<acted_value_type>(x); })) {}
    template <typename U>
    explicit LengthAwareLazySegmentTree(std::initializer_list<U> il) : LengthAwareLazySegmentTree(il.begin(), il.end()) {}

    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const value_type &a) { base_type::set(k, a); }
    // k番目の要素を求める．O(log N).
    value_type prod(int k) { return base_type::prod(k).val; }
    // 区間[l,r)の要素の総積を求める．O(log N).s
    value_type prod(int l, int r) { return base_type::prod(l, r).val; }
    // 区間全体の要素の総積を取得する．O(1).
    value_type prod_all() const { return base_type::prod_all().val; }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        return base_type::most_right(l, [&](const acted_value_type &x) -> bool { return pred(x.val); });
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        return base_type::most_left(r, [&](const acted_value_type &x) -> bool { return pred(x.val); });
    }
};

namespace lazy_segment_tree {

namespace detail {

namespace range_sum_range_update {

template <typename T>
using S = LengthAwareType<T>;

template <typename T>
constexpr auto e = algebra::element::zero<S<T>>;

template <typename T>
constexpr auto op = algebra::binary_operator::plus<S<T>>;

template <typename T>
using acted_monoid = algebra::Monoid<S<T>, op<T>, e<T>>;

template <typename F>
constexpr auto id = algebra::element::max<F>;

template <typename F>
constexpr auto compose = algebra::binary_operator::assign_if_not_id<F, id<F>>;

template <typename F, typename T = F>
constexpr auto mapping = [](const F &f, const S<T> &x) -> S<T> { return {(f == id<F>() ? x.val : f * x.len), x.len}; };

template <typename F, typename T = F>
using operator_monoid = algebra::OperatorMonoid<F, compose<F>, id<F>, S<T>, mapping<F, T>>;

}  // namespace range_sum_range_update

namespace range_sum_range_add {

template <typename T>
using S = range_sum_range_update::S<T>;

template <typename T>
constexpr auto e = range_sum_range_update::e<T>;

template <typename T>
constexpr auto op = range_sum_range_update::op<T>;

template <typename T>
using acted_monoid = range_sum_range_update::acted_monoid<T>;

template <typename F>
constexpr auto id = algebra::element::zero<F>;

template <typename F>
constexpr auto compose = algebra::binary_operator::plus<F>;

template <typename F, typename T = F>
constexpr auto mapping = [](const F &f, const S<T> &x) -> S<T> { return {x.val + f * x.len, x.len}; };

template <typename F, typename T = F>
using operator_monoid = algebra::OperatorMonoid<F, compose<F>, id<F>, S<T>, mapping<F, T>>;

}  // namespace range_sum_range_add

namespace range_sum_range_affine {

template <typename T>
using S = range_sum_range_update::S<T>;

template <typename T>
constexpr auto e = range_sum_range_update::e<T>;

template <typename T>
constexpr auto op = range_sum_range_update::op<T>;

template <typename T>
using acted_monoid = range_sum_range_update::acted_monoid<T>;

template <typename U>
struct F {
    U a;
    U b;

    constexpr F() : F(U(), U()) {}
    constexpr F(const U &a, const U &b) : a(a), b(b) {}

    friend constexpr F operator*(const F &lhs, const F &rhs) { return {lhs.a * rhs.a, lhs.a * rhs.b + lhs.b}; }
    friend std::ostream &operator<<(std::ostream &os, const F &rhs) { return os << "{" << rhs.a << ", " << rhs.b << "}"; }
};

template <typename U>
constexpr auto id = []() -> F<U> { return {1, 0}; };

template <typename U>
constexpr auto compose = algebra::binary_operator::mul<F<U>>;

template <typename U, typename T = U>
constexpr auto mapping = [](const F<U> &f, const S<T> &x) -> S<T> { return {f.a * x.val + f.b * x.len, x.len}; };

template <typename U, typename T = U>
using operator_monoid = algebra::OperatorMonoid<F<U>, compose<U>, id<U>, S<T>, mapping<U, T>>;

}  // namespace range_sum_range_affine

}  // namespace detail

}  // namespace lazy_segment_tree

using namespace lazy_segment_tree;

template <typename S, typename F = S>
using RangeMinimumRangeUpdateLazySegmentTree = LazySegmentTree<S, F, algebra::monoid::minimum_safe<S>, algebra::operator_monoid::assign_for_minimum<F, S>>;

template <typename S, typename F = S>
using RangeMinimumRangeAddLazySegmentTree = LazySegmentTree<S, F, algebra::monoid::minimum<S>, algebra::operator_monoid::addition<F, S>>;

template <typename S, typename F = S>
using RangeMaximumRangeUpdateLazySegmentTree = LazySegmentTree<S, F, algebra::monoid::maximum_safe<S>, algebra::operator_monoid::assign_for_maximum<F, S>>;

template <typename S, typename F = S>
using RangeMaximumRangeAddLazySegmentTree = LazySegmentTree<S, F, algebra::monoid::maximum<S>, algebra::operator_monoid::addition<F, S>>;

template <typename T, typename F = T>
using RangeSumRangeUpdateLazySegmentTree = LengthAwareLazySegmentTree<T, detail::range_sum_range_update::S<T>, F, detail::range_sum_range_update::acted_monoid<T>, detail::range_sum_range_update::operator_monoid<F, T>>;

template <typename T, typename F = T>
using RangeSumRangeAddLazySegmentTree = LengthAwareLazySegmentTree<T, detail::range_sum_range_add::S<T>, F, detail::range_sum_range_add::acted_monoid<T>, detail::range_sum_range_add::operator_monoid<F, T>>;

template <typename T, typename U = T>
using RangeSumRangeAffineLazySegmentTree = LengthAwareLazySegmentTree<T, detail::range_sum_range_affine::S<T>, detail::range_sum_range_affine::F<U>, detail::range_sum_range_affine::acted_monoid<T>, detail::range_sum_range_affine::operator_monoid<U, T>>;

}  // namespace algorithm

#endif
