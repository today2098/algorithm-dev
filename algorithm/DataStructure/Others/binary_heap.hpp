#ifndef ALGORITHM_BINARY_HEAP_HPP
#define ALGORITHM_BINARY_HEAP_HPP 1

#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithm {

namespace binary_heap {

template <typename T, auto comp>
class BinaryHeap {
    static_assert(std::is_invocable_r<bool, decltype(comp), T, T>::value);

public:
    using value_type = T;
    using size_type = std::size_t;

private:
    std::vector<value_type> m_tree;  // m_tree[]:=(完全二分木).

    static constexpr size_type left(size_type k) { return k << 1; }
    static constexpr size_type right(size_type k) { return k << 1 | 1; }
    void shift_up(size_type k) {
        for(size_type p = k >> 1; p >= 1 and comp(m_tree[k - 1], m_tree[p - 1]); p >>= 1) {
            std::swap(m_tree[k - 1], m_tree[p - 1]);
            k = p;
        }
    }
    void shift_down(size_type k) {
        for(size_type l = left(k), r = right(k), end = size(); l <= end; l = left(k), r = right(k)) {
            if(r <= end and comp(m_tree[r - 1], m_tree[l - 1])) {
                if(comp(m_tree[k - 1], m_tree[r - 1])) break;
                std::swap(m_tree[k - 1], m_tree[r - 1]);
                k = r;
                continue;
            }
            if(comp(m_tree[k - 1], m_tree[l - 1])) break;
            std::swap(m_tree[k - 1], m_tree[l - 1]);
            k = l;
        }
    }
    void heapify() {
        for(size_type i = size() >> 1; i >= 1; --i) shift_down(i);
    }

public:
    // constructor. O(N).
    BinaryHeap() : m_tree(0) {}
    template <std::input_iterator InputIter>
    explicit BinaryHeap(InputIter first, InputIter last) : m_tree(first, last) {
        heapify();
    }
    template <typename U>
    explicit BinaryHeap(std::initializer_list<U> il) : BinaryHeap(il.begin(), il.end()) {}
    explicit BinaryHeap(const std::vector<value_type> &v) : m_tree(v) {
        heapify();
    }
    explicit BinaryHeap(std::vector<value_type> &&v) : m_tree(std::move(v)) {
        heapify();
    }

    // 比較関数を取得する．
    static constexpr auto compare() { return comp; }
    // 要素が空か判定する．O(1).
    bool empty() const { return m_tree.empty(); }
    // 要素数を取得する．O(1).
    size_type size() const { return m_tree.size(); }
    // 先頭要素の参照．O(1).
    value_type top() const {
        assert(!empty());
        return m_tree.front();
    }
    // 要素追加．O(log N).
    void push(const value_type &a) {
        m_tree.push_back(a);
        shift_up(size());
    }
    void push(value_type &&a) {
        m_tree.push_back(std::move(a));
        shift_up(size());
    }
    template <typename... Args>
    void emplace(Args &&...args) {
        m_tree.emplace_back(std::forward<Args>(args)...);
        shift_up(size());
    }
    // 先頭要素の削除．O(log N).
    value_type pop() {
        assert(!empty());
        value_type res = m_tree.front();
        m_tree.front() = m_tree.back();
        m_tree.pop_back();
        if(!empty()) shift_down(1);
        return res;
    }
    void reset() { m_tree.clear(); }

    friend std::ostream &operator<<(std::ostream &os, const BinaryHeap &rhs) {
        os << "[\n";
        for(int l = 1, r = 2, end = rhs.size(); l <= end; l <<= 1, r <<= 1) {
            for(int i = l; i < r and i <= end; ++i) os << (i == l ? "  [" : " ") << rhs.m_tree[i - 1];
            os << "]\n";
        }
        return os << "]";
    }
};

namespace internal {

template <typename T>
constexpr auto less = [](const T &lhs, const T &rhs) -> bool { return lhs < rhs; };

template <typename T>
constexpr auto greater = [](const T &lhs, const T &rhs) -> bool { return lhs > rhs; };

}  // namespace internal

template <typename T>
using min_heap = BinaryHeap<T, internal::greater<T>>;

template <typename T>
using max_heap = BinaryHeap<T, internal::greater<T>>;

}  // namespace binary_heap

}  // namespace algorithm

#endif
