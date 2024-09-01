#ifndef ALGORITHM_SEGMENT_TREE_HPP
#define ALGORITHM_SEGMENT_TREE_HPP 1

/**
 * @brief Segment Tree
 * @docs docs/DataStructure/SegmentTree/segment_tree.md
 */

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

namespace algorithm {

template <typename S>
class SegmentTree {
    using Op = std::function<S(const S &, const S &)>;

    Op m_op;                // S m_op(S,S):=(二項演算関数).
    S m_e;                  // m_e:=(単位元).
    int m_sz;               // m_sz:=(要素数).
    int m_n;                // m_n:=(完全二分木の葉数).
    std::vector<S> m_tree;  // m_tree(2n)[]:=(完全二分木). 1-based index.

public:
    // constructor. O(N).
    SegmentTree() {};
    explicit SegmentTree(const Op &op, const S &e, size_t n) : m_op(op), m_e(e), m_sz(n), m_n(1) {
        while(m_n < size()) m_n <<= 1;
        m_tree.assign(2 * m_n, identity());
    }
    explicit SegmentTree(const Op &op, const S &e, const std::vector<S> &v) : SegmentTree(op, e, v.size()) {
        std::copy(v.begin(), v.end(), m_tree.begin() + m_n);
        for(int i = m_n - 1; i >= 1; --i) m_tree[i] = m_op(m_tree[i << 1], m_tree[i << 1 | 1]);
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // 単位元を返す．
    S identity() const { return m_e; }
    // k番目の要素をaに置き換える．O(logN).
    void set(int k, const S &a) {
        assert(0 <= k and k < size());
        k += m_n;
        m_tree[k] = a;
        while(k >>= 1) m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 | 1]);
    }
    // k番目の要素を返す．O(1).
    S prod(int k) const {
        assert(0 <= k and k < size());
        return m_tree[k + m_n];
    }
    // 区間[l,r)の要素の総積 v[l]•v[l+1]•...•v[r-1] を求める．O(logN).
    S prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        S val_l = identity(), val_r = identity();
        l += m_n, r += m_n;
        while(l < r) {
            if(l & 1) val_l = m_op(val_l, m_tree[l++]);
            if(r & 1) val_r = m_op(m_tree[--r], val_r);
            l >>= 1, r >>= 1;
        }
        return m_op(val_l, val_r);
    }
    // 区間全体の要素の総積を返す．O(1).
    S prod_all() const { return m_tree[1]; }
    // f(prod(l,-))==true となる区間の最右位値を二分探索する．
    // ただし，要素列には単調性があり，また f(e)==true であること．O(logN).
    template <class Func = std::function<bool(const S &)> >
    int most_right(const Func &f, int l) const {
        assert(f(identity()) == true);
        assert(0 <= l and l <= size());
        if(l == size()) return size();
        S val = identity();
        l += m_n;
        do {
            while(!(l & 1)) l >>= 1;
            S &&tmp = m_op(val, m_tree[l]);
            if(!f(tmp)) {
                while(l < m_n) {
                    l <<= 1;
                    S &&tmp2 = m_op(val, m_tree[l]);
                    if(f(tmp2)) val = tmp2, l++;
                }
                return l - m_n;
            }
            val = tmp, l++;
        } while((l & -l) != l);  // (x&-x)==x のとき，xは2の階乗数．
        return size();
    }
    // f(prod(-,r))==true となる区間の最左位値を二分探索する．
    // ただし，要素列には単調性があり，また f(e)==true であること．O(logN).
    template <class Func = std::function<bool(const S &)> >
    int most_left(const Func &f, int r) const {
        assert(f(identity()) == true);
        assert(0 <= r and r <= size());
        if(r == 0) return 0;
        S val = identity();
        r += m_n;
        do {
            r--;
            while(r > 1 and r & 1) r >>= 1;
            S &&tmp = m_op(m_tree[r], val);
            if(!f(tmp)) {
                while(r < m_n) {
                    r = (r << 1) | 1;
                    S &&tmp2 = m_op(m_tree[r], val);
                    if(f(tmp2)) val = tmp2, r--;
                }
                return r - m_n + 1;
            }
            val = tmp;
        } while((r & -r) != r);  // (x&-x)==x のとき，xは2の階乗数．
        return 0;
    }
    void reset() { std::fill(m_tree.begin(), m_tree.end(), identity()); }

    friend std::ostream &operator<<(std::ostream &os, const SegmentTree &segtree) {
        int l = 1, r = 2;
        os << "[\n";
        while(l < 2 * segtree.m_n) {
            os << "  [";
            for(int i = l; i < r; ++i) os << (i == l ? "" : " ") << segtree.m_tree[i];
            os << "]\n";
            l <<= 1, r <<= 1;
        }
        os << "]";
        return os;
    }
};

}  // namespace algorithm

#endif
