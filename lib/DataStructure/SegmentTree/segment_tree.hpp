#ifndef ALGORITHM_SEGMENT_TREE_HPP
#define ALGORITHM_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <limits>
#include <type_traits>
#include <vector>

namespace algorithm {

namespace segmenttree {

template <typename S, auto op, auto e>
class SegmentTree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);

public:
    using value_type = S;

private:
    int m_sz;                        // m_sz:=(要素数).
    int m_n;                         // m_n:=(完全二分木の葉数).
    std::vector<value_type> m_tree;  // m_tree(2n)[]:=(完全二分木). 1-based index.

    void update(int k) { m_tree[k] = op(m_tree[k << 1], m_tree[k << 1 | 1]); }
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
        m_tree.assign(2 * m_n, e());
    }
    explicit SegmentTree(int n, const value_type &a) : SegmentTree(n) {
        std::fill(m_tree.begin() + m_n, m_tree.begin() + m_n + m_sz, a);
        if(a != e()) build();
    }
    explicit SegmentTree(const std::vector<value_type> &v) : SegmentTree(v.size()) {
        std::copy(v.cbegin(), v.cend(), m_tree.begin() + m_n);
        build();
    }

    // 二項演算関数を取得する．
    static constexpr auto operation() { return op; }
    // 単位元を取得する．
    static constexpr auto identity() { return e; }
    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(logN).
    void set(int k, const value_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        m_tree[k] = a;
        while(k >>= 1) update(k);
    }
    // k番目の要素を取得する．O(1).
    value_type prod(int k) const {
        assert(0 <= k and k < size());
        return m_tree[k + m_n];
    }
    // 区間[l,r)の要素の総積 a[l]•a[l+1]•...•a[r-1] を求める．O(logN).
    value_type prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        value_type &&val_l = e(), &&val_r = e();
        for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = op(val_l, m_tree[l++]);
            if(r & 1) val_r = op(m_tree[--r], val_r);
        }
        return op(val_l, val_r);
    }
    // 区間全体の要素の総積を取得する．O(1).
    value_type prod_all() const { return m_tree[1]; }
    // eval(prod(l,-))==true となる区間の最右位値を二分探索する．
    // ただし，要素列の区間積には単調性があり，また eval(e)==true であること．O(logN).
    template <class Eval>
    int most_right(int l, Eval eval) const {
        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);
        assert(0 <= l and l <= size());
        assert(eval(e()));
        if(l == size()) return size();
        value_type &&val = e();
        l += m_n;
        do {
            while(!(l & 1)) l >>= 1;
            value_type &&tmp = op(val, m_tree[l]);
            if(!eval(tmp)) {
                while(l < m_n) {
                    l <<= 1;
                    tmp = op(val, m_tree[l]);
                    if(eval(tmp)) val = tmp, ++l;
                }
                return l - m_n;
            }
            val = tmp, ++l;
        } while((l & -l) != l);  // (x&-x)==x のとき，xは2の階乗数．
        return size();
    }
    // eval(prod(-,r))==true となる区間の最左位値を二分探索する．
    // ただし，要素列の区間積には単調性があり，また eval(e)==true であること．O(logN).
    template <class Eval>
    int most_left(int r, Eval eval) const {
        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);
        assert(0 <= r and r <= size());
        assert(eval(e()));
        if(r == 0) return 0;
        value_type &&val = e();
        r += m_n;
        do {
            --r;
            while(r > 1 and r & 1) r >>= 1;
            value_type &&tmp = op(m_tree[r], val);
            if(eval(tmp)) {
                while(r < m_n) {
                    r = r << 1 | 1;
                    tmp = op(m_tree[r], val);
                    if(eval(tmp)) val = tmp, --r;
                }
                return r + 1 - m_n;
            }
            val = tmp;
        } while((r & -r) != r);  // (x&-x)==x のとき，xは2の階乗数．
        return 0;
    }
    void reset() { std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, e()); }

    friend std::ostream &operator<<(std::ostream &os, const SegmentTree &rhs) {
        os << "[\n";
        for(int l = 1, r = 2; r <= 2 * rhs.m_n; l <<= 1, r <<= 1) {
            for(int i = l; i < r; ++i) os << (i == l ? "  [" : " ") << rhs.m_tree[i];
            os << "]\n";
        }
        return os << "]";
    }
};

template <typename Type>
auto range_minimum_query(int n) {
    assert(n >= 0);
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };
    return SegmentTree<S, op, e>(n);
}

template <typename Type>
auto range_minimum_query(const std::vector<Type> &v) {
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };
    return SegmentTree<S, op, e>(v);
}

template <typename Type>
auto range_maximum_query(int n) {
    assert(n >= 0);
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest(); };
    return SegmentTree<S, op, e>(n);
}

template <typename Type>
auto range_maximum_query(const std::vector<Type> &v) {
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest(); };
    return SegmentTree<S, op, e>(v);
}

template <typename Type>
auto range_sum_query(int n) {
    assert(n >= 0);
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return lhs + rhs; };
    constexpr auto e = []() -> S { return 0; };
    return SegmentTree<S, op, e>(n);
}

template <typename Type>
auto range_sum_query(const std::vector<Type> &v) {
    using S = Type;
    constexpr auto op = [](S lhs, S rhs) -> S { return lhs + rhs; };
    constexpr auto e = []() -> S { return 0; };
    return SegmentTree<S, op, e>(v);
}

}  // namespace segmenttree

}  // namespace algorithm

#endif
