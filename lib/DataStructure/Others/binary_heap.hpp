#ifndef ALGORITHM_BINARY_HEAP_HPP
#define ALGORITHM_BINARY_HEAP_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithm {

template <typename T, auto comp>
class BinaryHeap {
    static_assert(std::is_convertible_v<decltype(comp), std::function<bool(T, T)>>);

public:
    using value_type = T;
    using size_type = std::size_t;

private:
    std::vector<value_type> m_tree;  // m_tree[]:=(完全二分木).

    void shift_up(size_type k) {
        assert(k >= 1);
        for(size_type p = k >> 1; p >= 1; p >>= 1) {
            if(comp(m_tree[k - 1], m_tree[p - 1])) break;
            std::swap(m_tree[k - 1], m_tree[p - 1]);
            k = p;
        }
    }
    void shift_down(size_type k) {
        assert(k >= 1);
        for(size_type l = k << 1, r = k << 1 | 1, end = size(); l <= end; l = k << 1, r = k << 1 | 1) {
            if(r <= end and comp(m_tree[l - 1], m_tree[r - 1])) {
                if(comp(m_tree[r - 1], m_tree[k - 1])) break;
                std::swap(m_tree[r - 1], m_tree[k - 1]);
                k = r;
            } else {
                if(comp(m_tree[l - 1], m_tree[k - 1])) break;
                std::swap(m_tree[l - 1], m_tree[k - 1]);
                k = l;
            }
        }
    }
    void heapify() {
        for(size_type i = size() >> 1; i >= 1; --i) shift_down(i);
    }

public:
    // constructor. O(N).
    BinaryHeap() : m_tree() {}
    explicit BinaryHeap(const std::vector<value_type> &v) : m_tree(v) {
        heapify();
    }
    explicit BinaryHeap(std::vector<value_type> &&v) : m_tree(std::move(v)) {
        heapify();
    }

    // 比較関数を取得する．
    static constexpr auto compare() { return comp; }
    // 要素が空か判定する．O(1).
    bool empty() const { return size() == 0; }
    // 要素数を取得する．O(1).
    size_type size() const { return m_tree.size(); }
    // 先頭要素の参照．O(1).
    value_type top() const {
        assert(!empty());
        return m_tree[0];
    }
    // 要素追加．O(logN).
    void push(const value_type &a) {
        m_tree.push_back(a);
        shift_up(size());
    }
    // 先頭要素の削除．O(logN).
    value_type pop() {
        assert(!empty());
        value_type res = m_tree[0];
        m_tree[0] = m_tree[size() - 1];
        m_tree.pop_back();
        if(!empty()) shift_down(1);
        return res;
    }
    void reset() { m_tree.clear(); }
    void reserve(size_type cap) { m_tree.reserve(cap); }
    void shrink_to_fit() { m_tree.shrink_to_fit(); }
};

}  // namespace algorithm

#endif
