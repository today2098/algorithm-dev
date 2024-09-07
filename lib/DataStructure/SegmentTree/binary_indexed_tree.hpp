#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_HPP 1

/**
 * @brief Binary Indexed Tree
 * @docs docs/DataStructure/SegmentTree/binary_indexed_tree.md
 */

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// Binary Indexed Tree.
template <typename T>
class BIT {
    int m_sz;               // m_sz:=(配列の要素数).
    std::vector<T> m_tree;  // 1-based index.

    void build() {
        for(int i = 1; i < size(); ++i) {
            int j = i + (i & -i);
            if(j <= size()) m_tree[j] += m_tree[i];
        }
    }

public:
    // constructor. O(N).
    BIT() : BIT(0) {};
    explicit BIT(size_t n, T a = 0) : m_sz(n), m_tree(n + 1, a) {
        if(a != 0) build();
    }
    explicit BIT(const std::vector<T> &v) : m_sz(v.size()), m_tree(v.size() + 1) {
        std::copy(v.begin(), v.end(), m_tree.begin() + 1);
        build();
    }

    // 要素数を返す．
    int size() const { return m_sz; }
    // k番目の要素にaを加算する．O(logN).
    void add(int k, T a) {
        assert(1 <= k and k <= size());
        for(; k <= size(); k += k & -k) m_tree[k] += a;
    }
    // 区間[1,r]の要素の総和を求める．O(logN).
    T sum(int r) const {
        assert(0 <= r and r <= size());
        T res = 0;
        for(; r > 0; r -= r & -r) res += m_tree[r];
        return res;
    }
    // 区間[l,r]の要素の総和を求める．O(logN).
    T sum(int l, int r) const {
        assert(1 <= l and l <= r and r <= size());
        return sum(r) - sum(l - 1);
    }
    // 全要素をaで埋める．O(N).
    void fill(T a = 0) {
        std::fill(m_tree.begin() + 1, m_tree.end(), a);
        if(a != 0) build();
    }
};

}  // namespace algorithm

#endif
