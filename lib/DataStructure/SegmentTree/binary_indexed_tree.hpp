#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iterator>
#include <utility>
#include <vector>

namespace algorithm {

// Binary Indexed Tree.
template <typename T>
class BIT {
public:
    using value_type = T;

private:
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
    explicit BIT(int n) : BIT(n, value_type()) {}
    explicit BIT(int n, const value_type &a) : m_tree(n, a) {
        assert(n >= 0);
        if(a != value_type()) build();
    }
    template <std::input_iterator InputIter>
    explicit BIT(InputIter first, InputIter last) : m_tree(first, last) {
        build();
    }
    explicit BIT(std::initializer_list<value_type> il) : m_tree(il) {
        build();
    }
    explicit BIT(std::vector<value_type> &&v) : m_tree(std::move(v)) {
        build();
    }

    // 要素数を取得する．
    int size() const { return m_tree.size(); }
    // k番目の要素にaを加算する．O(log N).
    void add(int k, const value_type &a) {
        assert(0 <= k and k < size());
        for(int i = k + 1, end = size(); i <= end; i += lsb(i)) m_tree[i - 1] += a;
    }
    // 区間[0,r)の要素の総和を求める．O(log N).
    value_type sum(int r) const {
        assert(0 <= r and r <= size());
        value_type res = value_type();
        for(int i = r; i >= 1; i -= lsb(i)) res += m_tree[i - 1];
        return res;
    }
    // 区間[l,r)の要素の総和を求める．O(log N).
    value_type sum(int l, int r) const {
        assert(0 <= l and l < r and r <= size());
        return sum(r) - sum(l);
    }
    void reset() {
        std::fill(m_tree.begin(), m_tree.end(), value_type());
    }
};

}  // namespace algorithm

#endif
