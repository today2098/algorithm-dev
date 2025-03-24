#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// Binary Indexed Tree.
template <typename T>
class BIT {
public:
    using value_type = T;

private:
    int m_sz;  // m_sz:=(要素数).
    std::vector<value_type> m_tree;

    static constexpr int lsb(int bit) { return bit & -bit; }
    void build() {
        for(int i = 1, end = size(); i < end; ++i) {
            int j = i + lsb(i);
            if(j <= end) m_tree[j - 1] += m_tree[i - 1];
        }
    }

public:
    // constructor. O(N).
    BIT() : BIT(0) {};
    explicit BIT(int n) : m_sz(n), m_tree(n, value_type()) {
        assert(n >= 0);
    }
    explicit BIT(int n, const value_type &a) : m_sz(n), m_tree(n, a) {
        assert(n >= 0);
        if(a != value_type()) build();
    }
    explicit BIT(const std::vector<value_type> &v) : m_sz(v.size()), m_tree(v) {
        build();
    }
    explicit BIT(std::vector<value_type> &&v) : m_sz(v.size()), m_tree(std::move(v)) {
        build();
    }

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素にaを加算する．O(logN).
    void add(int k, const value_type &a) {
        assert(0 <= k and k < size());
        for(int i = k + 1, end = size(); i <= end; i += lsb(k)) m_tree[i - 1] += a;
    }
    // 区間[0,r)の要素の総和を求める．O(logN).
    T sum(int r) const {
        assert(0 <= r and r <= size());
        T res = value_type();
        for(int i = r; i >= 1; i -= lsb(i)) res += m_tree[i - 1];
        return res;
    }
    // 区間[l,r)の要素の総和を求める．O(logN).
    T sum(int l, int r) const {
        assert(0 <= l and l < r and r <= size());
        return sum(r) - sum(l);
    }
    void reset() { std::fill(m_tree.begin(), m_tree.end(), value_type()); }
};

}  // namespace algorithm

#endif
