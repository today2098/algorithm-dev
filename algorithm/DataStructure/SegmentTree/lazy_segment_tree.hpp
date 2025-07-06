#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP
#define ALGORITHM_LAZY_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

template <class ActedMonoid, class OperatorMonoid>
class LazySegmentTree {
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
    LazySegmentTree() : LazySegmentTree(0) {}
    explicit LazySegmentTree(int n) : m_sz(n), m_n(1), m_depth(0) {
        assert(n >= 0);
        while(m_n < m_sz) m_n <<= 1, ++m_depth;
        m_tree.assign(2 * m_n, acted_monoid_type::one());
        m_lazy.assign(m_n, operator_monoid_type::one());
    }
    explicit LazySegmentTree(int n, const acted_value_type &a) : LazySegmentTree(n, acted_monoid_type(a)) {}
    explicit LazySegmentTree(int n, const acted_monoid_type &a) : LazySegmentTree(n) {
        std::fill_n(m_tree.begin() + m_n, n, a);
        build();
    }
    template <std::input_iterator InputIter>
    explicit LazySegmentTree(InputIter first, InputIter last) : m_n(1), m_depth(0), m_tree(first, last) {
        m_sz = m_tree.size();
        while(m_n < m_sz) m_n <<= 1, ++m_depth;
        m_tree.reserve(2 * m_n);
        m_tree.insert(m_tree.begin(), m_n, acted_monoid_type::one());
        m_tree.resize(2 * m_n, acted_monoid_type::one());
        m_lazy.resize(m_n, operator_monoid_type::one());
        build();
    }
    template <typename T>
    explicit LazySegmentTree(std::initializer_list<T> il) : LazySegmentTree(il.begin(), il.end()) {}

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const acted_value_type &a) { set(k, acted_monoid_type(a)); }
    void set(int k, const acted_monoid_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = a;
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // k番目の要素を作用素fを用いて更新する．O(log N).
    void apply(int k, const operator_value_type &f) { apply(k, operator_monoid_type(f)); }
    void apply(int k, const operator_monoid_type &f) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = f.act(m_tree[k]);
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,r)の要素を作用素fを用いて更新する．O(log N).
    void apply(int l, int r, const operator_value_type &f) { apply(l, r, operator_monoid_type(f)); }
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
    acted_value_type prod(int k) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        return m_tree[k].value();
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    acted_value_type prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return acted_monoid_type::one().value();
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if((l >> i) << i != l) push(l >> i);
            if((r >> i) << i != r) push((r - 1) >> i);
        }
        acted_monoid_type &&val_l = acted_monoid_type::one(), &&val_r = acted_monoid_type::one();
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = val_l * m_tree[l++];
            if(r & 1) val_r = m_tree[--r] * val_r;
        }
        return (val_l * val_r).value();
    }
    // 区間全体の要素の総積を取得する．O(1).
    acted_value_type prod_all() const { return m_tree[1].value(); }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <bool (*pred)(acted_value_type)>
    int most_right(int l) const {
        return most_right(l, [](const acted_value_type &x) -> bool { return pred(x); });
    }
    template <class Pred>
    int most_right(int l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, acted_value_type>::value);
        assert(0 <= l and l <= size());
        assert(pred(acted_monoid_type::one().value()));
        if(l == m_sz) return m_sz;
        l += m_n;
        for(int i = m_depth; i >= 1; --i) push(l >> i);
        acted_monoid_type &&val = acted_monoid_type::one();
        do {
            while(!(l & 1)) l >>= 1;
            acted_monoid_type &&tmp = val * m_tree[l];
            if(!pred(tmp.value())) {
                while(l < m_n) {
                    push(l);
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
    template <bool (*pred)(acted_value_type)>
    int most_left(int r) const {
        return most_left(r, [](const acted_value_type &x) -> bool { return pred(x); });
    }
    template <class Pred>
    int most_left(int r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, acted_value_type>::value);
        assert(0 <= r and r <= size());
        assert(pred(acted_monoid_type::one().value()));
        if(r == 0) return 0;
        r += m_n;
        for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);
        acted_monoid_type &&val = acted_monoid_type::one();
        do {
            --r;
            while(r > 1 and (r & 1)) r >>= 1;
            acted_monoid_type &&tmp = m_tree[r] * val;
            if(!pred(tmp.value())) {
                while(r < m_n) {
                    push(r);
                    r = r << 1 | 1;
                    tmp = m_tree[r] * val;
                    if(pred(tmp.value())) val = tmp, --r;
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

    friend std::ostream &operator<<(std::ostream &os, const LazySegmentTree &rhs) {
        os << "{\n  [\n";
        for(int i = 0; i <= rhs.m_depth; ++i) {
            int l = 1 << i, r = 2 << i;
            for(int j = l; j < r; ++j) os << (j == l ? "    [" : " ") << rhs.m_tree[j].value();
            os << "]\n";
        }
        os << "  ],\n  [\n";
        for(int i = 0; i < rhs.m_depth; ++i) {
            int l = 1 << i, r = 2 << i;
            for(int j = l; j < r; ++j) os << (j == l ? "    [" : " ") << rhs.m_lazy[j].value();
            os << "]\n";
        }
        return os << "  ]\n}";
    }
};

namespace lazy_segment_tree {

namespace detail {

namespace range_sum_range_update {

template <typename T>
struct S {
    T val;
    int size;

    constexpr S() : S(T(), 0) {}
    constexpr S(const T &val) : S(val, 1) {}
    constexpr S(const T &val, int size) : val(val), size(size) {}

    friend constexpr S operator+(const S &lhs, const S &rhs) { return {lhs.val + rhs.val, lhs.size + rhs.size}; }
    friend std::ostream &operator<<(std::ostream &os, const S &rhs) { return os << "{" << rhs.val << ", " << rhs.size << "}"; }
};

template <typename T>
using acted_monoid = algebra::Monoid<S<T>, algebra::binary_operator::plus<S<T>>, algebra::element::zero<S<T>>>;

template <typename F>
constexpr auto id = algebra::element::max<F>;

template <typename F>
constexpr auto compose = algebra::binary_operator::assign_if_not_id<F, id<F>>;

template <typename F, typename T = F>
constexpr auto mapping = [](const F &f, const S<T> &x) -> S<T> {
    static_assert(std::is_invocable_r<F, decltype(id<F>)>::value);
    return {(f == id<F>() ? x.val : f * x.size), x.size};
};

template <typename F, typename T = F>
using operator_monoid = algebra::OperatorMonoid<F, compose<F>, id<F>, S<T>, mapping<F, T>>;

}  // namespace range_sum_range_update

namespace range_sum_range_add {

template <typename T>
using S = range_sum_range_update::S<T>;

template <typename T>
using acted_monoid = range_sum_range_update::acted_monoid<T>;

template <typename F>
constexpr auto id = algebra::element::zero<F>;

template <typename F>
constexpr auto compose = algebra::binary_operator::plus<F>;

template <typename F, typename T = F>
constexpr auto mapping = [](const F &f, const S<T> &x) -> S<T> { return {x.val + f * x.size, x.size}; };

template <typename F, typename T = F>
using operator_monoid = algebra::OperatorMonoid<F, compose<F>, id<F>, S<T>, mapping<F, T>>;

}  // namespace range_sum_range_add

namespace range_sum_range_affine {

template <typename T>
using S = range_sum_range_update::S<T>;

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
constexpr auto mapping = [](const F<U> &f, const S<T> &x) -> S<T> { return {f.a * x.val + f.b * x.size, x.size}; };

template <typename U, typename T = U>
using operator_monoid = algebra::OperatorMonoid<F<U>, compose<U>, id<U>, S<T>, mapping<U, T>>;

}  // namespace range_sum_range_affine

}  // namespace detail

template <typename S, typename F = S>
using range_minimum_range_update_lazy_segment_tree = LazySegmentTree<algebra::monoid::minimum_safe<S>, algebra::operator_monoid::assign_for_minimum<F, S>>;

template <typename S, typename F = S>
using range_minimum_range_add_lazy_segment_tree = LazySegmentTree<algebra::monoid::minimum<S>, algebra::operator_monoid::addition<F, S>>;

template <typename S, typename F = S>
using range_maximum_range_update_lazy_segment_tree = LazySegmentTree<algebra::monoid::maximum_safe<S>, algebra::operator_monoid::assign_for_maximum<F, S>>;

template <typename S, typename F = S>
using range_maximum_range_add_lazy_segment_tree = LazySegmentTree<algebra::monoid::maximum<S>, algebra::operator_monoid::addition<F, S>>;

template <typename T, typename F = T>
using range_sum_range_update_lazy_segment_tree = LazySegmentTree<detail::range_sum_range_update::acted_monoid<T>, detail::range_sum_range_update::operator_monoid<F, T>>;

template <typename T, typename F = T>
using range_sum_range_add_lazy_segment_tree = LazySegmentTree<detail::range_sum_range_add::acted_monoid<T>, detail::range_sum_range_add::operator_monoid<F, T>>;

template <typename T, typename U = T>
using range_sum_range_affine_lazy_segment_tree = LazySegmentTree<detail::range_sum_range_affine::acted_monoid<T>, detail::range_sum_range_affine::operator_monoid<U, T>>;

}  // namespace lazy_segment_tree

}  // namespace algorithm

#endif
