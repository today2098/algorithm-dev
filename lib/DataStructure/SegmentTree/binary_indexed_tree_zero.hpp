#ifndef ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP 1

/**
 * @brief Binary Indexed Tree (0-based index)
 * @docs docs/DataStructure/SegmentTree/binary_indexed_tree_zero.md
 */

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// Binary Indexed Tree (0-based index).
template <typename T>
class BIT0 {
    int m_sz;               // m_sz:=(配列の要素数).
    std::vector<T> m_tree;  // 0-based index.

    void build() {
        for(int i = 0; i < size() - 1; ++i) {
            int j = i | (i + 1);
            if(j < size()) m_tree[j] += m_tree[i];
        }
    }

public:
    // constructor. O(N).
    BIT0() : BIT0(0) {};
    explicit BIT0(size_t n, T a = 0) : m_sz(n), m_tree(n, a) {
        if(a != 0) build();
    }
    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()), m_tree(v) {
        build();
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // k番目の要素にaを加算する．O(logN).
    void add(int k, T a) {
        assert(0 <= k and k < size());
        for(; k < size(); k |= k + 1) m_tree[k] += a;
    }
    // 区間[0,r)の要素の総和を求める．O(logN).
    T sum(int r) const {
        assert(0 <= r and r <= size());
        T res = 0;
        for(r = r - 1; r >= 0; r = (r & (r + 1)) - 1) res += m_tree[r];
        return res;
    }
    // 区間[l,r)の要素の総和を求める．O(logN).
    T sum(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        return sum(r) - sum(l);
    }
    // 全要素をaで埋める．O(N).
    void fill(T a = 0) {
        std::fill(m_tree.begin(), m_tree.end(), a);
        if(a != 0) build();
    }
};

}  // namespace algorithm

#endif
