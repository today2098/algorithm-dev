#ifndef ALGORITHM_INTERVAL_SET_HPP
#define ALGORITHM_INTERVAL_SET_HPP 1

#include <algorithm>
#include <cassert>
#include <compare>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#include <utility>

namespace algorithm {

namespace interval_set {

template <typename T>
class Interval : public std::pair<T, T> {
public:
    using value_type = T;
    using base_type = std::pair<value_type, value_type>;

    constexpr Interval() : Interval(0, 0) {}
    constexpr Interval(const value_type &l, const value_type &u) : base_type(l, u) {
        assert(l <= u);
    }
    constexpr Interval(value_type &&l, value_type &&u) : base_type(std::move(l), std::move(u)) {
        assert(lower() <= upper());
    }

    friend constexpr auto operator<=>(const Interval &lhs, const Interval &rhs) = default;
    friend std::ostream &operator<<(std::ostream &os, const Interval &interval) { return os << "[" << interval.lower() << ", " << interval.upper() << ")"; }

    static constexpr Interval all() { return {std::numeric_limits<value_type>::lowest(), std::numeric_limits<value_type>::max()}; }
    constexpr value_type lower() const { return this->first; }
    constexpr value_type upper() const { return this->second; }
    constexpr value_type width() const { return upper() - lower(); }
    constexpr bool contains(const value_type &x) const { return lower() <= x and x < upper(); }
    constexpr int contains(const Interval &a) const { return contains(a.lower(), a.upper()); }
    constexpr int contains(const value_type &l, const value_type &u) const {
        if(lower() <= l and u <= upper()) return 2;  // 区間[l,u)の全体を含む場合．
        if(u <= lower() or upper() <= l) return 0;   // 区間[l,u)を含まない場合．
        return 1;                                    // 区間[l,u)の一部のみ含む場合．
    }
    constexpr Interval overlap(const Interval &a) const { return overlap(a.lower(), a.upper()); }
    constexpr Interval overlap(const value_type &l, const value_type &u) const {
        l = std::max(l, lower()), u = std::min(u, upper());
        return (l <= u ? Interval(l, u) : Interval(u, u));
    }
};

template <typename Type>
constexpr Interval<Type> overlap(const Interval<Type> &a, const Interval<Type> &b) { return a.overlap(b); }

template <typename Type>
constexpr Interval<Type> overlap(std::initializer_list<Interval<Type>> il) {
    Interval<Type> res = Interval<Type>::all();
    for(const auto &elem : il) res = res.overlap(elem);
    return res;
}

// Interval Set（区間をsetで管理するデータ構造）.
template <typename T>
class IntervalSet {
public:
    using value_type = T;
    using size_type = std::size_t;
    using interval_type = Interval<value_type>;
    using iterator = std::set<interval_type>::const_iterator;
    using const_iterator = std::set<interval_type>::const_iterator;
    using reverse_iterator = std::set<interval_type>::const_reverse_iterator;
    using const_reverse_iterator = std::set<interval_type>::const_reverse_iterator;

private:
    std::set<interval_type> m_st;

    iterator lower_bound_internal(const value_type &l) const {
        auto iter = upper_bound_internal(l);
        return (l < std::prev(iter)->upper() ? std::prev(iter) : iter);
    }
    iterator upper_bound_internal(const value_type &u) const { return m_st.lower_bound(interval_type(u, u)); }

public:
    IntervalSet() {
        static_assert(lower_limit() < upper_limit());
        // 番兵を配置．
        m_st.emplace(lower_limit(), lower_limit());
        m_st.emplace(upper_limit(), upper_limit());
    }

    static constexpr value_type lower_limit() { return std::numeric_limits<value_type>::lowest(); }
    static constexpr value_type upper_limit() { return std::numeric_limits<value_type>::max(); }

    bool empty() const { return size() == 0; }
    size_type size() const { return m_st.size() - 2; }

    iterator insert(const interval_type &interval) { return insert(interval.lower(), interval.upper()); }
    iterator insert(value_type l, value_type u) {
        assert(lower_limit() < l and l <= u and u < upper_limit());
        if(l == u) return lower_bound_internal(l);
        iterator left = lower_bound_internal(l);
        if(std::prev(left)->upper() == l) --left;
        if(left->lower() < l) l = left->lower();
        iterator right = upper_bound_internal(u);
        if(right->lower() == u) ++right;
        if(u < std::prev(right)->upper()) u = std::prev(right)->upper();
        return m_st.emplace_hint(m_st.erase(left, right), l, u);
    }
    iterator erase(const interval_type &interval) { return erase(interval.lower(), interval.upper()); }
    iterator erase(const value_type &l, const value_type &u) {
        assert(lower_limit() < l and l <= u and u < upper_limit());
        if(l == u) return lower_bound_internal(l);
        iterator left = lower_bound_internal(l);
        iterator right = upper_bound_internal(u);
        value_type ll = left->lower();
        value_type uu = std::prev(right)->upper();
        auto iter = m_st.erase(left, right);
        if(u < uu) iter = m_st.emplace_hint(iter, u, uu);
        if(ll < l) m_st.emplace_hint(iter, ll, l);
        return iter;
    }
    iterator erase(iterator iter) { return m_st.erase(iter); }
    iterator erase(iterator left, iterator right) { return m_st.erase(left, right); }
    void clear() { m_st.erase(begin(), end()); }

    iterator lower_bound(const value_type &l) const {
        assert(lower_limit() < l and l < upper_limit());
        return lower_bound_internal(l);
    }
    iterator upper_bound(const value_type &u) const {
        assert(lower_limit() < u and u < upper_limit());
        return upper_bound_internal(u);
    }
    iterator find(const value_type &x) const {
        auto iter = lower_bound(x);
        return (iter->contains(x) ? iter : end());
    }
    std::pair<iterator, iterator> overlap_range(const interval_type &interval) const { return overlap_range(interval.lower(), interval.upper()); }
    std::pair<iterator, iterator> overlap_range(const value_type &l, const value_type &u) const {
        assert(lower_limit() < l and l <= u and u < upper_limit());
        return {lower_bound_internal(l), upper_bound_internal(u)};
    }
    bool contains(const value_type &x) const { return find(x) != end(); }
    int contains(const interval_type &interval) const { return contains(interval.lower(), interval.upper()); }
    int contains(const value_type &l, const value_type &u) const {
        assert(lower_limit() < l and l <= u and u < upper_limit());
        if(l == u) return 0;
        return lower_bound_internal(l)->contains(l, u);
    }
    // x以上で集合に含まれない最小の値 (mex: Minimum EXcluded value) を求める．O(log N).
    value_type mex(const value_type &x) const {
        auto iter = lower_bound(x);
        return (iter->contains(x) ? iter->upper() : x);
    }

    iterator begin() const { return std::next(m_st.begin()); }
    iterator end() const { return std::prev(m_st.end()); }
    iterator cbegin() const { return std::next(m_st.cbegin()); }
    iterator cend() const { return std::prev(m_st.cend()); }
    reverse_iterator rbegin() const { return std::next(m_st.rbegin()); }
    reverse_iterator rend() const { return std::prev(m_st.rend()); }
    reverse_iterator crbegin() const { return std::next(m_st.crbegin()); }
    reverse_iterator crend() const { return std::prev(m_st.crend()); }
};

}  // namespace interval_set

}  // namespace algorithm

#endif
