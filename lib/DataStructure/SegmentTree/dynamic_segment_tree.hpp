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

namespace dynamic_segment_tree {

template <class Monoid>
class DynamicSegmentTree {
public:
    using monoid_type = Monoid;
    using value_type = monoid_type::value_type;
    using size_type = std::size_t;

private:
    struct Node;
    using node_pointer = std::unique_ptr<Node>;

    struct Node {
        size_type index;
        monoid_type value;
        monoid_type product;
        node_pointer left, right;

        explicit Node(size_type index, const monoid_type &value) : index(index), value(value), product(value), left(nullptr), right(nullptr) {}
    };

    size_type m_sz;       // m_sz:=(要素数).
    node_pointer m_root;  // m_root:=(根のポインタ).

    void update(const node_pointer &p) const {
        const monoid_type &lhs = (p->left ? p->left->product : monoid_type::one());
        const monoid_type &rhs = (p->right ? p->right->product : monoid_type::one());
        p->product = lhs * p->value * rhs;
    }
    void set(node_pointer &p, size_type k, monoid_type a, size_type l, size_type r) {
        if(!p) {
            p = std::make_unique<Node>(k, a);
            return;
        }
        if(p->index == k) {
            p->value = a;
            update(p);
            return;
        }
        size_type mid = l + (r - l) / 2;
        if(k < mid) {
            if(p->index < k) std::swap(k, p->index), std::swap(a, p->value);
            set(p->left, k, a, l, mid);
        } else {
            if(k < p->index) std::swap(k, p->index), std::swap(a, p->value);
            set(p->right, k, a, mid, r);
        }
        update(p);
    }
    monoid_type prod(const node_pointer &p, size_type k, size_type l, size_type r) const {
        if(!p) return monoid_type::one();
        if(p->index == k) return p->value;
        size_type mid = l + (r - l) / 2;
        return (k < mid ? prod(p->left, k, l, mid) : prod(p->right, k, mid, r));
    }
    monoid_type prod(const node_pointer &p, size_type l, size_type r, size_type ll, size_type rr) const {
        if(!p or r <= ll or rr <= l) return monoid_type::one();
        if(l <= ll and rr <= r) return p->product;
        size_type mid = ll + (rr - ll) / 2;
        return prod(p->left, l, r, ll, mid) * (l <= p->index and p->index < r ? p->value : monoid_type::one()) * prod(p->right, l, r, mid, rr);
    }
    template <typename Pred>
    size_type most_right(const node_pointer &p, size_type l, Pred pred, size_type ll, size_type rr, monoid_type &product) const {
        if(!p or rr <= l) return rr;
        if(l <= ll and pred((product * p->product).value())) {
            product = product * p->product;
            return rr;
        }
        size_type mid = ll + (rr - ll) / 2;
        size_type itr = most_right(p->left, l, pred, ll, mid, product);
        if(itr < mid) return itr;
        if(l <= p->index) {
            product = product * p->value;
            if(!pred(product.value())) return p->index;
        }
        return most_right(p->right, l, pred, mid, rr, product);
    }
    template <typename Pred>
    size_type most_left(const node_pointer &p, size_type r, Pred pred, size_type ll, size_type rr, monoid_type &product) const {
        if(!p or r <= ll) return ll;
        if(rr <= r and pred((p->product * product).value())) {
            product = p->product * product;
            return ll;
        }
        size_type mid = ll + (rr - ll) / 2;
        size_type itr = most_left(p->right, r, pred, mid, rr, product);
        if(mid < itr) return itr;
        if(p->index < r) {
            product = p->value * product;
            if(!pred(product.value())) return p->index + 1;
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
        if(l <= p->index and p->index < r) {
            if(!p->left and !p->right) {
                p.reset();
                return;
            }
            p->value = monoid_type::one();
        }
        update(p);
    }
    void print(std::ostream &os, const node_pointer &p, bool &first) const {
        if(!p) return;
        print(os, p->left, first);
        os << (first ? "{" : " {") << p->index << ", " << p->value << "}";
        first = false;
        print(os, p->right, first);
    }

public:
    DynamicSegmentTree() : DynamicSegmentTree(std::numeric_limits<size_type>::max()) {};
    explicit DynamicSegmentTree(size_type n) : m_sz(n), m_root(nullptr) {}

    // 要素数を取得する．
    size_type size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(log N).
    void set(size_type k, const value_type &a) { set(k, monoid_type(a)); }
    void set(size_type k, const monoid_type &a) {
        assert(k < size());
        set(m_root, k, a, 0, m_sz);
    }
    // k番目の要素を取得する．O(log N).
    value_type prod(size_type k) const {
        assert(k < size());
        return prod(m_root, k, 0, m_sz).value();
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    value_type prod(size_type l, size_type r) const {
        assert(l <= r and r <= size());
        return prod(m_root, l, r, 0, m_sz).value();
    }
    // 区間全体の要素の総積を取得する．O(1).
    value_type prod_all() const { return (m_root ? m_root->product : monoid_type::one()).value(); }
    // pred(prod(l,r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[l,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <bool (*pred)(value_type)>
    size_type most_right(size_type l) const {
        return most_right(l, [](const value_type &x) -> bool { return pred(x); });
    }
    template <typename Pred>
    size_type most_right(size_type l, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        assert(l <= size());
        assert(pred(monoid_type::one().value()));
        monoid_type &&product = monoid_type::one();
        return most_right(m_root, l, pred, 0, m_sz, product);
    }
    // pred(prod(l,r))==true となる区間の最左位値lを二分探索する．
    // ただし，区間[0,r)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <bool (*pred)(value_type)>
    size_type most_left(int r) const {
        return most_left(r, [](const value_type &x) -> bool { return pred(x); });
    }
    template <typename Pred>
    size_type most_left(size_type r, Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        assert(r <= size());
        assert(pred(monoid_type::one().value()));
        value_type &&product = monoid_type::one();
        return most_left(m_root, r, pred, 0, m_sz, product);
    }
    void reset(size_type k) { reset(m_root, k, k + 1, 0, m_sz); }
    void reset(size_type l, size_type r) {
        assert(l <= r and r <= size());
        reset(m_root, l, r, 0, m_sz);
    }
    void reset() { m_root.reset(); }

    friend std::ostream &operator<<(std::ostream &os, const DynamicSegmentTree &rhs) {
        os << "[";
        bool first = true;
        rhs.print(os, rhs.m_root, first);
        return os << "]";
    }
};

template <typename S>
using range_minimum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::minimum<S>>;

template <typename S>
using range_maximum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::maximum<S>>;

template <typename S>
using range_sum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::addition<S>>;

}  // namespace dynamic_segment_tree

}  // namespace algorithm

#endif
