#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP
#define ALGORITHM_LAZY_SEGMENT_TREE_HPP 1

/**
 * @brief Lazy Segment Tree（遅延評価セグメント木）
 * @docs docs/DataStructure/SegmentTree/lazy_segment_tree.md
 */

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

namespace algorithm {

// Lazy Segment Tree（遅延評価セグメント木）.
template <class S, class F>  // S:モノイドの型, F:写像の型.
class LazySegTree {
    using Op = std::function<S(const S &, const S &)>;
    using Mapping = std::function<S(const F &, const S &)>;
    using Composition = std::function<F(const F &, const F &)>;

    Op m_op;                    // S m_op(S,S):=(二項演算関数). S×S→S.
    Mapping m_mapping;          // S m_mapping(F f,S x):=(写像). f(x).
    Composition m_composition;  // F m_composition(F f,F g):=(写像の合成). f∘g.
    S m_e;                      // m_e:=(単位元).
    F m_id;                     // m_id:=(恒等写像).
    int m_sz;                   // m_sz:=(要素数).
    int m_n;                    // m_n:=(完全二分木の葉数).
    int m_depth;                // m_depth:=(完全二分木の深さ).
    std::vector<S> m_tree;      // m_tree(2n)[]:=(完全二分木). 1-based index.
    std::vector<F> m_lazy;      // m_lazy(n)[k]:=(m_tree[k]の子 (m_tree[2k], m_tree[2k+1]) に対する遅延評価).

    void apply0(int k, const F &f) {
        assert(1 <= k and k < 2 * m_n);
        m_tree[k] = m_mapping(f, m_tree[k]);
        if(k < m_n) m_lazy[k] = m_composition(f, m_lazy[k]);
    }
    void push(int k) {
        assert(1 <= k and k < m_n);
        apply0(k << 1, m_lazy[k]);
        apply0(k << 1 | 1, m_lazy[k]);
        m_lazy[k] = identity_mapping();
    }
    void update(int k) {
        assert(1 <= k and k < m_n);
        m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 | 1]);
    }

public:
    // constructor. O(N).
    LazySegTree() {}
    explicit LazySegTree(const Op &op, const Mapping &mapping, const Composition &composition, const S &e, const F &id, size_t n)
        : m_op(op), m_mapping(mapping), m_composition(composition), m_e(e), m_id(id), m_sz(n), m_n(1), m_depth(0) {
        while(m_n < size()) m_n <<= 1, m_depth++;
        m_tree.assign(2 * m_n, identity());
        m_lazy.assign(m_n, identity_mapping());
    }
    explicit LazySegTree(const Op &op, const Mapping &mapping, const Composition &composition, const S &e, const F &id, const std::vector<S> &v)
        : LazySegTree(op, mapping, composition, e, id, v.size()) {
        std::copy(v.begin(), v.end(), m_tree.begin() + m_n);
        for(int i = m_n - 1; i >= 1; --i) update(i);
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // モノイドの単位元を返す．
    S identity() const { return m_e; }
    // 恒等写像を返す．
    F identity_mapping() const { return m_id; }
    // k番目の要素をaに置き換える．O(logN).
    void set(int k, const S &a) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = a;
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,-)の要素をv[]に置き換える．O(N).
    void set(int l, const std::vector<S> &v) {
        assert(0 <= l and l + (int)v.size() <= size());
        if(v.size() == 0) return;
        l += m_n;
        int r = l + (int)v.size();
        for(int i = m_depth; i >= 1; --i) {
            for(int j = l >> i, end = (r - 1) >> i; j <= end; ++j) push(j);
        }
        std::copy(v.begin(), v.end(), m_tree.begin() + l);
        for(int i = 1; i <= m_depth; ++i) {
            for(int j = l >> i, end = (r - 1) >> i; j <= end; ++j) update(j);
        }
    }
    // k番目の要素を写像fを用いて更新する．O(logN).
    void apply(int k, const F &f) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        m_tree[k] = m_mapping(f, m_tree[k]);
        for(int i = 1; i <= m_depth; ++i) update(k >> i);
    }
    // 区間[l,r)の要素を写像fを用いて更新する．O(logN).
    void apply(int l, int r, const F &f) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return;
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if((l >> i) << i != l) push(l >> i);
            if((r >> i) << i != r) push((r - 1) >> i);
        }
        for(int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if(l2 & 1) apply0(l2++, f);
            if(r2 & 1) apply0(--r2, f);
        }
        for(int i = 1; i <= m_depth; ++i) {
            if((l >> i) << i != l) update(l >> i);
            if((r >> i) << i != r) update((r - 1) >> i);
        }
    }
    // k番目の要素を求める．O(logN).
    S prod(int k) {
        assert(0 <= k and k < size());
        k += m_n;
        for(int i = m_depth; i >= 1; --i) push(k >> i);
        return m_tree[k];
    }
    // 区間[l,r)の要素の総積 v[l]•v[l+1]•....•v[r-1] を求める．O(logN).
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= size());
        if(l == r) return identity();
        l += m_n, r += m_n;
        for(int i = m_depth; i >= 1; --i) {
            if((l >> i) << i != l) push(l >> i);
            if((r >> i) << i != r) push((r - 1) >> i);
        }
        S val_l = identity(), val_r = identity();
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) val_l = m_op(val_l, m_tree[l++]);
            if(r & 1) val_r = m_op(m_tree[--r], val_r);
        }
        return m_op(val_l, val_r);
    }
    // 区間全体の要素の総積を返す．O(1).
    S prod_all() const { return m_tree[1]; }
    // jud(prod(l,-))==true となる区間の最右位値を二分探索する．
    // ただし，要素列には単調性があり，また jud(e)==true であること．O(logN).
    template <class Func = std::function<bool(const S &)> >
    int most_right(const Func &jud, int l) const {
        assert(jud(identity()) == true);
        assert(0 <= l and l <= size());
        if(l == size()) return size();
        l += m_n;
        for(int i = m_depth; i >= 1; --i) push(l >> i);
        S val = identity();
        do {
            while(!(l & 1)) l >>= 1;
            S &&tmp = m_op(val, m_tree[l]);
            if(!jud(tmp)) {
                while(l < m_n) {
                    push(l);
                    l <<= 1;
                    S &&tmp2 = m_op(val, m_tree[l]);
                    if(jud(tmp2)) val = tmp2, l++;
                }
                return l - m_n;
            }
            val = tmp, l++;
        } while((l & -l) != l);  // (x&-x)==x のとき，xは2の階乗数．
        return size();
    }
    // jud(prod(-,r))==true となる区間の最左位値を二分探索する．
    // ただし，要素列には単調性があり，また jud(e)==true であること．O(logN).
    template <class Func = std::function<bool(const S &)> >
    int most_left(const Func &jud, int r) const {
        assert(jud(identity()) == true);
        assert(0 <= r and r <= size());
        if(r == 0) return 0;
        r += m_n;
        for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);
        S val = identity();
        do {
            r--;
            while(r > 1 and r & 1) r >>= 1;
            S &&tmp = m_op(m_tree[r], val);
            if(!jud(tmp)) {
                while(r < m_n) {
                    push(r);
                    r = r << 1 | 1;
                    S &&tmp2 = m_op(m_tree[r], val);
                    if(jud(tmp2)) val = tmp2, r--;
                }
                return r - m_n + 1;
            }
            val = tmp;
        } while((r & -r) != r);  // (x&-x)==x のとき，xは2の階乗数．
        return 0;
    }
    void reset() {
        std::fill(m_tree.begin(), m_tree.end(), identity());
        std::fill(m_lazy.begin(), m_lazy.end(), identity_mapping());
    }
};

}  // namespace algorithm

#endif
