#ifndef ALGORITHM_BINARY_HEAP_HPP
#define ALGORITHM_BINARY_HEAP_HPP 1

#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

namespace algorithm {

// 二分ヒープ
template <typename T>
class BinaryHeap {
    using Comp = std::function<bool(const T &, const T &)>;

    Comp m_comp;            // bool m_comp(T,T):=(比較演算子).
    std::vector<T> m_tree;  // m_tree[]:=(完全二分木). 1-based index.

    void shift_up(int k) {
        int par = k >> 1;
        while(1 <= par) {
            if(m_comp(m_tree[par], m_tree[k])) break;
            std::swap(m_tree[par], m_tree[k]);
            k = par;
            par >>= 1;
        }
    }
    void shift_down(int k) {
        int l = k << 1, r = k << 1 | 1;
        while(l <= size()) {
            if(size() < r or m_comp(m_tree[l], m_tree[r])) {
                if(m_comp(m_tree[k], m_tree[l])) break;
                std::swap(m_tree[k], m_tree[l]);
                k = l;
            } else {
                if(m_comp(m_tree[k], m_tree[r])) break;
                std::swap(m_tree[k], m_tree[r]);
                k = r;
            }
            l = k << 1, r = k << 1 | 1;
        }
    }
    void heapify() {
        for(int i = size() >> 1; i >= 1; --i) shift_down(i);
    }

public:
    // constructor. O(N).
    BinaryHeap() : BinaryHeap([](const T &a, const T &b) -> bool { return a > b; }) {}
    explicit BinaryHeap(size_t n) : BinaryHeap([](const T &a, const T &b) -> bool { return a > b; }, n) {}
    explicit BinaryHeap(const std::vector<T> &v) : BinaryHeap(v, [](const T &a, const T &b) -> bool { return a > b; }) {}
    explicit BinaryHeap(const std::vector<T> &v, size_t n) : BinaryHeap(v, [](const T &a, const T &b) -> bool { return a > b; }, n) {}
    explicit BinaryHeap(const Comp &comp) : m_comp(comp), m_tree(1) {}
    explicit BinaryHeap(const Comp &comp, size_t n) : BinaryHeap(comp) {
        m_tree.reserve(n + 1);
    }
    explicit BinaryHeap(const std::vector<T> &v, const Comp &comp) : m_comp(comp), m_tree(v.size() + 1) {
        std::copy(v.begin(), v.end(), m_tree.begin() + 1);
        heapify();
    }
    explicit BinaryHeap(const std::vector<T> &v, const Comp &comp, size_t n) : BinaryHeap(v, comp) {
        m_tree.reserve(n + 1);
    }

    // 要素が空か判定する．O(1).
    bool empty() const { return size() == 0; }
    // 要素数を返す．O(1).
    int size() const { return m_tree.size() - 1; }
    // 先頭要素の参照．O(1).
    T top() const {
        assert(!empty());
        return m_tree[1];
    }
    // 要素追加．O(logN).
    void push(const T &x) {
        m_tree.push_back(x);
        shift_up(size());
    }
    // 先頭要素の削除．O(logN).
    T pop() {
        assert(!empty());
        T res = m_tree[1];
        m_tree[1] = m_tree[size()];
        m_tree.pop_back();
        if(!empty()) shift_down(1);
        return res;
    }
    // ヒープ化．O(N).
    void heapify(const Comp &comp) {
        m_comp = comp;
        heapify();
    }
};

}  // namespace algorithm

#endif
