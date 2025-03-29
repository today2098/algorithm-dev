#ifndef ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP
#define ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <type_traits>
#include <utility>

namespace algorithm {

namespace dynamicsegmenttree {

// Dynamic Segment Tree（動的セグメント木）.
template <typename S, auto op, auto e>
class DynamicSegmentTree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);

public:
    using value_type = S;
    using size_type = std::size_t;

private:
    struct Node;
    using node_ptr = std::unique_ptr<Node>;

    struct Node {
        size_type index;
        value_type value;
        value_type product;
        node_ptr left, right;
        explicit Node(size_type index, const value_type &value) : index(index), value(value), product(value), left(nullptr), right(nullptr) {}
    };

    size_type m_sz;   // m_sz:=(要素数).
    node_ptr m_root;  // m_root:=(根のポインタ).

    void update(const node_ptr &p) const {
        assert(p);
        const value_type &lhs = (p->left ? p->left->product : e());
        const value_type &rhs = (p->right ? p->right->product : e());
        p->product = op(op(lhs, p->value), rhs);
    }
    void set(node_ptr &p, size_type k, value_type a, size_type l, size_type r) {
        assert(l <= k and k < r and r <= size());
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
    value_type prod(const node_ptr &p, size_type k, size_type l, size_type r) const {
        assert(l <= k and k < r and r <= size());
        if(!p) return e();
        if(p->index == k) return p->value;
        size_type mid = l + (r - l) / 2;
        return (k < mid ? prod(p->left, k, l, mid) : prod(p->right, k, mid, r));
    }
    value_type prod(const node_ptr &p, size_type l, size_type r, size_type nl, size_type nr) const {
        assert(l <= r and r <= size());
        assert(nl <= nr and nr <= size());
        if(!p or r <= nl or nr <= l) return e();
        if(l <= nl and nr <= r) return p->product;
        size_type mid = nl + (nr - nl) / 2;
        value_type &&tmp = prod(p->left, l, r, nl, mid);
        if(l <= p->index and p->index < r) tmp = op(tmp, p->value);
        return op(tmp, prod(p->right, l, r, mid, nr));
    }
    template <class Eval>
    size_type most_right(const node_ptr &p, size_type l, Eval eval, size_type nl, size_type nr, value_type &product) const {
        assert(l <= size());
        assert(nl <= nr and nr <= size());
        if(!p or nr <= l) return nr;
        if(l <= nl and eval(op(product, p->product))) {
            product = op(product, p->product);
            return nr;
        }
        size_type mid = nl + (nr - nl) / 2;
        size_type itr = most_right(p->left, l, eval, nl, mid, product);
        if(itr < mid) return itr;
        if(l <= p->index) {
            product = op(product, p->value);
            if(!eval(product)) return p->index;
        }
        return most_right(p->right, l, eval, mid, nr, product);
    }
    template <class Eval>
    size_type most_left(const node_ptr &p, size_type r, Eval eval, size_type nl, size_type nr, value_type &product) const {
        assert(r <= size());
        assert(nl <= nr and nr <= size());
        if(!p or r <= nl) return nl;
        if(nr <= r and eval(op(p->product, product))) {
            product = op(p->product, product);
            return nl;
        }
        size_type mid = nl + (nr - nl) / 2;
        size_type itr = most_left(p->right, r, eval, mid, nr, product);
        if(mid < itr) return itr;
        if(p->index < r) {
            product = op(p->value, product);
            if(!eval(product)) return p->index + 1;
        }
        return most_left(p->left, r, eval, nl, mid, product);
    }
    void reset(node_ptr &p, size_type l, size_type r, size_type nl, size_type nr) {
        assert(l <= r and r <= size());
        assert(nl <= nr and nr <= size());
        if(!p or r <= nl or nr <= l) return;
        if(l <= nl and nr <= r) {
            p.reset();
            return;
        }
        size_type mid = nl + (nr - nl) / 2;
        reset(p->left, l, r, nl, mid);
        reset(p->right, l, r, mid, nr);
        if(l <= p->index and p->index < r) p->value = e();
        update(p);
    }

public:
    DynamicSegmentTree() : DynamicSegmentTree(0) {};
    explicit DynamicSegmentTree(size_type n) : m_sz(n), m_root(nullptr) {}

    // 二項演算関数を取得する．
    static constexpr auto operation() { return op; }
    // 単位元を取得する．
    static constexpr auto identity() { return e; }
    // 要素数を取得する．
    size_type size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(logN).
    void set(size_type k, const value_type &a) {
        assert(k < size());
        set(m_root, k, a, 0, size());
    }
    // k番目の要素を取得する．O(logN).
    value_type prod(size_type k) const {
        assert(k < size());
        return prod(m_root, k, 0, size());
    }
    // 区間[l,r)の要素の総積 a[l]•a[l+1]•...•a[r-1] を求める．O(logN).
    value_type prod(size_type l, size_type r) const {
        assert(l <= r and r <= size());
        return prod(m_root, l, r, 0, size());
    }
    // 区間全体の要素の総積を取得する．O(1).
    value_type prod_all() const { return (m_root ? m_root->product : e()); }
    // eval(prod(l,-))==true となる区間の最右位値を二分探索する．
    // ただし，要素列の区間積には単調性があり，また eval(e)==true であること．O(logN).
    template <class Eval>
    size_type most_right(size_type l, Eval eval) const {
        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);
        assert(l <= size());
        assert(eval(e()));
        value_type &&product = e();
        return most_right(m_root, l, eval, 0, size(), product);
    }
    // eval(prod(-,r))==true となる区間の最左位値を二分探索する．
    // ただし，要素列の区間積には単調性があり，また eval(e)==true であること．O(logN).
    template <class Eval>
    size_type most_left(size_type r, Eval eval) const {
        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);
        assert(r <= size());
        assert(eval(e()));
        value_type &&product = e();
        return most_left(m_root, r, eval, 0, size(), product);
    }
    void reset() { m_root.reset(); }
    void reset(size_type l, size_type r) {
        assert(l <= r and r <= size());
        reset(m_root, l, r, 0, size());
    }
};

template <typename Type>
auto range_minimum_query(std::size_t n) {
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };
    return DynamicSegmentTree<S, op, e>(n);
}

template <typename Type>
auto range_maximum_query(std::size_t n) {
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest(); };
    return DynamicSegmentTree<S, op, e>(n);
}

template <typename Type>
auto range_sum_query(std::size_t n) {
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return lhs + rhs; };
    constexpr auto e = []() -> S { return 0; };
    return DynamicSegmentTree<S, op, e>(n);
}

}  // namespace dynamicsegmenttree

}  // namespace algorithm

#endif
