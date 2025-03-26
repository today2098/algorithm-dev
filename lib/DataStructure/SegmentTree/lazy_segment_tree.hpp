#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP
#define ALGORITHM_LAZY_SEGMENT_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <type_traits>
#include <vector>

namespace algorithm {

namespace lazysegmenttree {

// Lazy Segment Tree（遅延評価セグメント木）.
template <class S, auto op, auto e, class F, auto map, auto compose, auto id>
class LazySegmentTree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);
    static_assert(std::is_convertible_v<decltype(map), std::function<S(F, S)>>);
    static_assert(std::is_convertible_v<decltype(compose), std::function<F(F, F)>>);
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>);

public:
    using value_type = S;    // モノイドの型．
    using mapping_type = F;  // 写像の型．

private:
    int m_sz;                          // m_sz:=(要素数).
    int m_n;                           // m_n:=(完全二分木の葉数).
    int m_depth;                       // m_depth:=(完全二分木の深さ).
    std::vector<value_type> m_tree;    // m_tree(2n)[]:=(完全二分木). 1-based index.
    std::vector<mapping_type> m_lazy;  // m_lazy(n)[k]:=(m_tree[k]の子 (m_tree[2k], m_tree[2k+1]) に対する遅延評価).

    void apply_with_lazy(int k, const mapping_type &f) {
        m_tree[k] = map(f, m_tree[k]);
        if(k < m_n) m_lazy[k] = compose(f, m_lazy[k]);
    }
    void push(int k) {
        apply_with_lazy(k << 1, m_lazy[k]);
        apply_with_lazy(k << 1 | 1, m_lazy[k]);
        m_lazy[k] = id();
    }
    void update(int k) { m_tree[k] = op(m_tree[k << 1], m_tree[k << 1 | 1]); }
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
        m_tree.assign(2 * m_n, e());
        m_lazy.assign(m_n, id());
    }
    explicit LazySegmentTree(int n, const value_type &a) : LazySegmentTree(n) {
        std::fill(m_tree.begin() + m_n, m_tree.begin() + m_n + m_sz, a);
        build();
    }
    explicit LazySegmentTree(const std::vector<value_type> &v) : LazySegmentTree(v.size()) {
        std::copy(v.cbegin(), v.cend(), m_tree.begin() + m_n);
        build();
    }

    // 二項演算関数を取得する．
    static constexpr auto operation() { return op; }
    // モノイドの単位元を取得する．
    static constexpr auto identity() { return e; }
    // 写像を取得する．
    static constexpr auto mapping() { return map; }
    // 写像の合成関数を取得する．
    static constexpr auto composition() { return compose; }
    // 恒等写像を取得する．
    static constexpr auto identity_mapping() { return id; }
    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaに置き換える．O(logN).
    void set(int k, const value_type &a) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = a;
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // k番目の要素を写像fを用いて更新する．O(logN).
    void apply(int k, const mapping_type &f) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = map(f, m_tree[k]);
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,r)の要素を写像fを用いて更新する．O(logN).
    void apply(int l, int r, const mapping_type &f) {
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
    // k番目の要素を求める．O(logN).
    value_type prod(int k) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        return m_tree[k];
    }
    // 区間[l,r)の要素の総積 v[l]•v[l+1]•....•v[r-1] を求める．O(logN).
    value_type prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return e();
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if((l >> i) << i != l) push(l >> i);
            if((r >> i) << i != r) push((r - 1) >> i);
        }
        value_type &&val_l = e(), &&val_r = e();
        for(; l < r; l >>= 1, r >>= 1) {
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
        l += m_n;
        for(int i = m_depth; i >= 1; --i) push(l >> i);
        value_type &&val = e();
        do {
            while(!(l & 1)) l >>= 1;
            value_type &&tmp = op(val, m_tree[l]);
            if(!eval(tmp)) {
                while(l < m_n) {
                    push(l);
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
        r += m_n;
        for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);
        value_type &&val = e();
        do {
            --r;
            while(r > 1 and r & 1) r >>= 1;
            value_type &&tmp = m_op(m_tree[r], val);
            if(!eval(tmp)) {
                while(r < m_n) {
                    push(r);
                    r = r << 1 | 1;
                    tmp = op(m_tree[r], val);
                    if(eval(tmp)) val = tmp, --r;
                }
                return r - m_n + 1;
            }
            val = tmp;
        } while((r & -r) != r);  // (x&-x)==x のとき，xは2の階乗数．
        return 0;
    }
    void reset() {
        std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, e());
        std::fill(m_lazy.begin() + 1, m_lazy.end(), id());
    }
};

template <typename Type>
auto range_minimum_query_and_range_update_query(int n) {
    assert(n >= 0);
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max() - 1; };
    constexpr auto id = []() -> F { return std::numeric_limits<F>::max(); };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto mapping = [id](F f, S x) -> S { return (f == id() ? x : f); };
    constexpr auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);
}

template <typename Type>
auto range_minimum_query_and_range_update_query(const std::vector<Type> &v) {
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max() - 1; };
    constexpr auto id = []() -> F { return std::numeric_limits<F>::max(); };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto mapping = [id](F f, S x) -> F { return (f == id() ? x : f); };
    constexpr auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(v);
}

template <typename Type>
auto range_minimum_query_and_range_add_query(int n) {
    assert(n >= 0);
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };
    constexpr auto id = []() -> F { return 0; };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto mapping = [](F f, S x) -> F { return x + f; };
    constexpr auto composition = [](F f, F g) -> F { return g + f; };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);
}

template <typename Type>
auto range_minimum_query_and_range_add_query(const std::vector<Type> &v) {
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };
    constexpr auto id = []() -> F { return 0; };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };
    constexpr auto mapping = [](F f, S x) -> S { return x + f; };
    constexpr auto composition = [](F f, F g) -> F { return g + f; };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(v);
}

template <typename Type>
auto range_maximum_query_and_range_update_query(int n) {
    assert(n >= 0);
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest() + 1; };
    constexpr auto id = []() -> F { return std::numeric_limits<F>::lowest(); };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto mapping = [id](F f, S x) -> S { return (f == id() ? x : f); };
    constexpr auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);
}

template <typename Type>
auto range_maximum_query_and_range_update_query(const std::vector<Type> &v) {
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest() + 1; };
    constexpr auto id = []() -> F { return std::numeric_limits<F>::lowest(); };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto mapping = [id](F f, S x) -> S { return (f == id() ? x : f); };
    constexpr auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(v);
}

template <typename Type>
auto range_maximum_query_and_range_add_query(int n) {
    assert(n >= 0);
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest(); };
    constexpr auto id = []() -> F { return 0; };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto mapping = [](F f, S x) -> S { return x + f; };
    constexpr auto composition = [](F f, F g) -> F { return g + f; };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n);
}

template <typename Type>
auto range_maximum_query_and_range_add_query(const std::vector<Type> &v) {
    using S = Type;
    using F = Type;
    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest(); };
    constexpr auto id = []() -> F { return 0; };
    constexpr auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };
    constexpr auto mapping = [](F f, S x) -> S { return x + f; };
    constexpr auto composition = [](F f, F g) -> F { return g + f; };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(v);
}

template <typename Type>
auto range_sum_query_and_range_update_query(int n) {
    assert(n >= 0);
    using S = struct {
        Type val;
        int size;
    };
    using F = Type;
    constexpr auto e = []() -> S { return {0, 0}; };
    constexpr auto id = []() -> F { return std::numeric_limits<F>::max(); };
    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.val + rhs.val, lhs.size + rhs.size}; };
    constexpr auto mapping = [id](F f, const S &x) -> S { return {(f == id() ? x.val : f * x.size), x.size}; };
    constexpr auto composition = [id](F f, F g) -> F { return (f == id() ? g : f); };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n, {0, 1});
}

template <typename Type>
auto range_sum_query_and_range_add_query(int n) {
    assert(n >= 0);
    using S = struct {
        Type val;
        int size;
    };
    using F = Type;
    constexpr auto e = []() -> S { return {0, 0}; };
    constexpr auto id = []() -> F { return 0; };
    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.val + rhs.val, lhs.size + rhs.size}; };
    constexpr auto mapping = [](F f, const S &x) -> S { return {x.val + f * x.size, x.size}; };
    constexpr auto composition = [](F f, F g) -> F { return g + f; };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n, {0, 1});
}

template <typename Type>
auto range_sum_query_and_range_affine_query(int n) {
    assert(n >= 0);
    using S = struct {
        Type val;
        int size;
    };
    using F = struct {
        Type a;
        Type b;
    };
    constexpr auto e = []() -> S { return {0, 0}; };
    constexpr auto id = []() -> F { return {1, 0}; };
    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.val + rhs.val, lhs.size + rhs.size}; };
    constexpr auto mapping = [](const F &f, const S &x) -> S { return {x.val * f.a + f.b * x.size, x.size}; };
    constexpr auto composition = [](const F &f, const F &g) -> F { return {g.a * f.a, g.b * f.a + f.b}; };
    return LazySegmentTree<S, op, e, F, mapping, composition, id>(n, {0, 1});
}

}  // namespace lazysegmenttree

}  // namespace algorithm

#endif
