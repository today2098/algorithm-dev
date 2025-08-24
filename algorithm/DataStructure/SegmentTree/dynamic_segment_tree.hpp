#ifndef ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP
#define ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <memory>
#include <type_traits>
#include <utility>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

template <class Monoid>
class DynamicSegmentTreeBase {
public:
    using monoid_type = Monoid;
    using value_type = typename monoid_type::value_type;
    using size_type = std::size_t;

private:
    struct Node;
    using node_pointer = std::unique_ptr<Node>;

    struct Node {
        size_type idx;
        monoid_type val;
        monoid_type product;
        node_pointer left, right;

        explicit Node(size_type idx, const monoid_type &val) : idx(idx), val(val), product(val), left(nullptr), right(nullptr) {}
    };

    size_type m_sz;       // m_sz:=(要素数).
    node_pointer m_root;  // m_root:=(根のポインタ).

    void update(const node_pointer &p) const {
        p->product = p->val;
        if(p->left) p->product = p->left->product * p->product;
        if(p->right) p->product = p->product * p->right->product;
    }
    void set(node_pointer &p, size_type k, monoid_type a, size_type l, size_type r) {
        if(!p) {
            p = std::make_unique<Node>(k, a);
            return;
        }
        if(p->idx == k) {
            p->val = a;
            update(p);
            return;
        }
        size_type mid = l + (r - l) / 2;
        if(k < mid) {
            if(p->idx < k) std::swap(k, p->idx), std::swap(a, p->val);
            set(p->left, k, a, l, mid);
        } else {
            if(k < p->idx) std::swap(k, p->idx), std::swap(a, p->val);
            set(p->right, k, a, mid, r);
        }
        update(p);
    }
    monoid_type prod(const node_pointer &p, size_type k, size_type l, size_type r) const {
        if(!p) return monoid_type::one();
        if(p->idx == k) return p->val;
        size_type mid = l + (r - l) / 2;
        return (k < mid ? prod(p->left, k, l, mid) : prod(p->right, k, mid, r));
    }
    monoid_type prod(const node_pointer &p, size_type l, size_type r, size_type ll, size_type rr) const {
        if(!p or r <= ll or rr <= l) return monoid_type::one();
        if(l <= ll and rr <= r) return p->product;
        size_type mid = ll + (rr - ll) / 2;
        return prod(p->left, l, r, ll, mid) * (l <= p->idx and p->idx < r ? p->val : monoid_type::one()) * prod(p->right, l, r, mid, rr);
    }
    template <typename Pred>
    size_type most_right(const node_pointer &p, size_type l, Pred pred, size_type ll, size_type rr, monoid_type &product) const {
        if(!p or rr <= l) return rr;
        if(l <= ll and pred(product * p->product)) {
            product = product * p->product;
            return rr;
        }
        size_type mid = ll + (rr - ll) / 2;
        size_type itr = most_right(p->left, l, pred, ll, mid, product);
        if(itr < mid) return itr;
        if(l <= p->idx) {
            product = product * p->val;
            if(!pred(product)) return p->idx;
        }
        return most_right(p->right, l, pred, mid, rr, product);
    }
    template <typename Pred>
    size_type most_left(const node_pointer &p, size_type r, Pred pred, size_type ll, size_type rr, monoid_type &product) const {
        if(!p or r <= ll) return ll;
        if(rr <= r and pred(p->product * product)) {
            product = p->product * product;
            return ll;
        }
        size_type mid = ll + (rr - ll) / 2;
        size_type itr = most_left(p->right, r, pred, mid, rr, product);
        if(mid < itr) return itr;
        if(p->idx < r) {
            product = p->val * product;
            if(!pred(product)) return p->idx + 1;
        }
        return most_left(p->left, r, pred, ll, mid, product);
    }
    void reset(node_pointer &p, size_type l, size_type r, size_type ll, size_type rr) {
        if(!p or r <= ll or rr <= l) return;
        if(l <= ll and rr <= r) {
            p.reset();
            return;
        }
        size_type mid = ll + (rr - ll) / 2;
        reset(p->left, l, r, ll, mid);
        reset(p->right, l, r, mid, rr);
        if(l <= p->idx and p->idx < r) {
            if(!p->left and !p->right) {
                p.reset();
                return;
            }
            p->val = monoid_type::one();
        }
        update(p);
    }

public:
    DynamicSegmentTreeBase() : DynamicSegmentTreeBase(std::numeric_limits<size_type>::max()) {};
    explicit DynamicSegmentTreeBase(size_type n) : m_sz(n), m_root(nullptr) {}

    // 要素数を取得する．
    size_type size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(size_type k, const monoid_type &a) {
        assert(k < size());
        set(m_root, k, a, 0, m_sz);
    }
    // k番目の要素を取得する．O(log N).
    monoid_type prod(size_type k) const {
        assert(k < size());
        return prod(m_root, k, 0, m_sz);
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    monoid_type prod(size_type l, size_type r) const {
        assert(l <= r and r <= size());
        return prod(m_root, l, r, 0, m_sz);
    }
    // 区間全体の要素の総積を取得する．O(1).
    monoid_type prod_all() const { return (m_root ? m_root->product : monoid_type::one()); }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    size_type most_right(size_type l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, monoid_type>::value);
        assert(l <= size());
        assert(pred(monoid_type::one()));
        monoid_type product = monoid_type::one();
        return most_right(m_root, l, pred, 0, m_sz, product);
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    size_type most_left(size_type r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, monoid_type>::value);
        assert(r <= size());
        assert(pred(monoid_type::one()));
        monoid_type product = monoid_type::one();
        return most_left(m_root, r, pred, 0, m_sz, product);
    }
    void reset(size_type k) {
        assert(k < size());
        reset(m_root, k, k + 1, 0, m_sz);
    }
    void reset(size_type l, size_type r) {
        assert(l <= r and r <= size());
        reset(m_root, l, r, 0, m_sz);
    }
    void reset() { m_root.reset(); }

    friend std::ostream &operator<<(std::ostream &os, const DynamicSegmentTreeBase &rhs) {
        os << "[";
        bool first = true;
        auto dfs = [&](auto self, const node_pointer &p) -> void {
            if(!p) return;
            self(self, p->left);
            os << (first ? "{" : " {") << p->idx << ", " << p->val << "}";
            first = false;
            self(self, p->right);
        };
        dfs(dfs, rhs.m_root);
        return os << "]";
    }
};

template <typename S, class Monoid>
class DynamicSegmentTree : public DynamicSegmentTreeBase<Monoid> {
public:
    using base_type = DynamicSegmentTreeBase<Monoid>;
    using typename base_type::monoid_type;
    using typename base_type::size_type;
    using value_type = S;

    DynamicSegmentTree() : base_type() {}
    explicit DynamicSegmentTree(size_type n) : base_type(n) {}

    // k番目の要素をaに置き換える．O(log N).
    void set(size_type k, const value_type &a) { base_type::set(k, monoid_type(a)); }
    // k番目の要素を取得する．O(log N).
    value_type prod(size_type k) const { return base_type::prod(k).value(); }
    // 区間[l,r)の要素の総積を求める．O(log N).
    value_type prod(size_type l, size_type r) const { return base_type::prod(l, r).value(); }
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
using RangeMinimumDynamicSegmentTree = DynamicSegmentTree<S, algebra::monoid::minimum<S>>;

template <typename S>
using RangeMaximumDynamicSegmentTree = DynamicSegmentTree<S, algebra::monoid::maximum<S>>;

template <typename S>
using RangeSumDynamicSegmentTree = DynamicSegmentTree<S, algebra::monoid::addition<S>>;

template <typename S>
using RangeProductDynamicSegmentTree = DynamicSegmentTree<S, algebra::monoid::multiplication<S>>;

}  // namespace algorithm

#endif
