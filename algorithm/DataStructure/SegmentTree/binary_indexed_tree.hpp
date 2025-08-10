#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP
#define ALGORITHM_BINARY_INDEXED_TREE_HPP 1

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

#include "../../Math/Algebra/algebra.hpp"

namespace algorithm {

template <class AbelianGroup>
class BITBase {
public:
    using group_type = AbelianGroup;

private:
    int m_sz;
    std::vector<group_type> m_tree;

    static constexpr int lsb(int bit) { return bit & -bit; }
    group_type sum_internal(int r) const {
        group_type res = group_type::one();
        for(; r >= 1; r -= lsb(r)) res = res * m_tree[r - 1];
        return res;
    }
    void build() {
        for(int i = 1; i < m_sz; ++i) {
            int j = i + lsb(i);
            if(j <= m_sz) m_tree[j - 1] = m_tree[j - 1] * m_tree[i - 1];
        }
    }

public:
    // constructor. O(N).
    BITBase() : m_sz(0) {};
    explicit BITBase(int n) : m_sz(n), m_tree(n, group_type::one()) {
        assert(n >= 0);
    }
    explicit BITBase(int n, const group_type &a) : m_sz(n), m_tree(n, a) {
        assert(n >= 0);
        build();
    }
    template <std::input_iterator InputIter>
    explicit BITBase(InputIter first, InputIter last) : m_tree(first, last) {
        m_sz = m_tree.size();
        build();
    }
    template <std::ranges::input_range R>
    explicit BITBase(R &&r) : BITBase(std::ranges::begin(r), std::ranges::end(r)) {}
    template <typename T>
    explicit BITBase(std::initializer_list<T> il) : BITBase(il.begin(), il.end()) {}
    explicit BITBase(std::vector<group_type> &&v) : m_tree(std::move(v)) {
        m_sz = m_tree.size();
        build();
    }

    // 要素数を取得する．
    int size() const { return m_sz; }
    // k番目の要素をaとの積の結果に置き換える．O(log N).
    void add(int k, const group_type &a) {
        assert(0 <= k and k < size());
        for(int i = k + 1; i <= m_sz; i += lsb(i)) m_tree[i - 1] = m_tree[i - 1] * a;
    }
    // 区間[0,r)の要素の総積を求める．O(log N).
    group_type sum(int r) const {
        assert(0 <= r and r <= size());
        return sum_internal(r);
    }
    // 区間[l,r)の要素の総積を求める．O(log N).
    group_type sum(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        return sum_internal(r) * sum_internal(l).inv();
    }
    // 全要素の総積を求める．O(log N).
    group_type sum_all() const { return sum_internal(m_sz); }
    // pred(sum(r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[0,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_right(Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, group_type>::value);
        assert(pred(group_type::one()));
        int r = 0;
        group_type val = group_type::one();
        for(int i = 1; i <= m_sz and pred(m_tree[i - 1]); i <<= 1) r = i, val = m_tree[i - 1];
        for(int len = r >> 1; len > 0; len >>= 1) {
            if(r + len <= m_sz and pred(val * m_tree[r + len - 1])) {
                r += len;
                val = val * m_tree[r - 1];
            }
        }
        return r;
    }
    void reset() { std::fill(m_tree.begin(), m_tree.end(), group_type::one()); }
};

template <typename S, class AbelianGroup>
class BIT : public BITBase<AbelianGroup> {
public:
    using base_type = BITBase<AbelianGroup>;
    using value_type = S;
    using typename base_type::group_type;

    // constructor. O(N).
    BIT() : base_type() {}
    explicit BIT(int n) : base_type(n) {}
    explicit BIT(int n, const value_type &a) : base_type(n, a) {}
    template <std::input_iterator InputIter>
    explicit BIT(InputIter first, InputIter last) : base_type(first, last) {}
    template <std::ranges::input_range R>
    explicit BIT(R &&r) : base_type(std::forward<R>(r)) {}
    template <typename T>
    explicit BIT(std::initializer_list<T> il) : base_type(std::move(il)) {}
    explicit BIT(std::vector<group_type> &&v) : base_type(std::move(v)) {}

    // k番目の要素をaとの積の結果に置き換える．O(log N).
    void add(int k, const value_type &a) { base_type::add(k, a); }
    // 区間[0,r)の要素の総積を求める．O(log N).
    value_type sum(int r) const { return base_type::sum(r).value(); }
    // 区間[l,r)の要素の総積を求める．O(log N).
    value_type sum(int l, int r) const { return base_type::sum(l, r).value(); }
    // 全要素の総積を求める．O(log N).
    value_type sum_all() const { return base_type::sum_all().value(); }
    // pred(sum(r))==true となる区間の最右位値rを二分探索する．
    // ただし，区間[0,n)の要素はpred(S)によって区分化されていること．また，pred(e)==true であること．O(log N).
    template <typename Pred>
    int most_right(Pred pred) const {
        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);
        return base_type::most_right([&](const group_type &x) -> bool { return pred(x.value()); });
    }
};

template <typename S>
using RangeSumBIT = BIT<S, algebra::group::addition<S>>;

template <typename S>
using RangeXorBIT = BIT<S, algebra::group::bit_xor<S>>;

}  // namespace algorithm

#endif
