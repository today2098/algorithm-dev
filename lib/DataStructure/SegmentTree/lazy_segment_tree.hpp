#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP
#define ALGORITHM_LAZY_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

namespace algorithm {

template <class ActedMonoid, class OperatorMonoid>
class LazySegmentTree {
public:
    using acted_monoid_type = ActedMonoid;
    using operator_monoid_type = OperatorMonoid;
    using acted_value_type = acted_monoid_type::value_type;
    using operator_value_type = operator_monoid_type::value_type;

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
    void update(int k) {
        m_tree[k] = m_tree[k << 1] * m_tree[k << 1 | 1];
    }
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
        if(a == acted_monoid_type::one()) return;
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
    explicit LazySegmentTree(std::initializer_list<acted_value_type> il) : LazySegmentTree(il.begin(), il.end()) {}
    explicit LazySegmentTree(std::initializer_list<acted_monoid_type> il) : LazySegmentTree(il.begin(), il.end()) {}

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(int k, const acted_value_type &a) {
        set(k, acted_monoid_type(a));
    }
    void set(int k, const acted_monoid_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = a;
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // k番目の要素を作用素fを用いて更新する．O(log N).
    void apply(int k, const operator_value_type &f) {
        apply(k, operator_monoid_type(f));
    }
    void apply(int k, const operator_monoid_type &f) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = f.act(m_tree[k]);
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,r)の要素を作用素fを用いて更新する．O(log N).
    void apply(int l, int r, const operator_value_type &f) {
        apply(l, r, operator_monoid_type(f));
    }
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

}  // namespace algorithm

#endif
