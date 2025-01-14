#ifndef ALGORITHM_INTERVAL_SET_HPP
#define ALGORITHM_INTERVAL_SET_HPP 1

#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#include <type_traits>
#include <utility>

namespace algorithm {

template <typename T, typename std::enable_if_t<std::is_arithmetic<T>::value, bool> = false>
class Interval {
    T l, u;

public:
    using value_type = T;

    Interval() : Interval(0, 0) {}
    explicit constexpr Interval(T l, T u) : l(l), u(u) {
        assert(l <= u);
    }

    constexpr Interval operator+=(T rhs) {
        l += rhs, u += rhs;
        return *this;
    }
    constexpr Interval operator-=(T rhs) {
        l -= rhs, u -= rhs;
        return *this;
    }
    constexpr Interval operator*=(T rhs) {
        l *= rhs, u *= rhs;
        return *this;
    }
    constexpr Interval operator+=(const Interval &rhs) {
        l += rhs.lower(), u += rhs.upper();
        return *this;
    }
    constexpr Interval operator-=(const Interval &rhs) {
        l -= rhs.lower(), u -= rhs.upper();
        return *this;
    }
    constexpr Interval operator*=(const Interval &rhs) { return *this = *this * rhs; }

    friend constexpr auto operator<=>(const Interval &lhs, const Interval &rhs) = default;
    friend constexpr Interval operator+(const Interval &lhs, T rhs) { return Interval(lhs) += rhs; }
    friend constexpr Interval operator-(const Interval &lhs, T rhs) { return Interval(lhs) -= rhs; }
    friend constexpr Interval operator*(const Interval &lhs, T rhs) { return Interval(lhs) *= rhs; }
    friend constexpr Interval operator+(const Interval &lhs, const Interval &rhs) { return Interval(lhs) += rhs; }
    friend constexpr Interval operator-(const Interval &lhs, const Interval &rhs) { return Interval(lhs) -= rhs; }
    friend constexpr Interval operator*(const Interval &lhs, const Interval &rhs) {
        return Interval(std::min({lhs.lower() * rhs.lower(), lhs.lower() * rhs.upper(), lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}),
                        std::max({lhs.lower() * rhs.lower(), lhs.lower() * rhs.upper(), lhs.upper() * rhs.lower(), lhs.upper() * rhs.upper()}));
    }
    friend std::ostream &operator<<(std::ostream &os, const Interval &a) { return os << "[" << a.lower() << ", " << a.upper() << ")"; }

    constexpr T lower() const { return l; }
    constexpr T upper() const { return u; }
    constexpr T width() const { return upper() - lower(); }
    constexpr bool contains(T x) const { return lower() <= x and x < upper(); }
    constexpr int contains(const Interval &a) const { return contains(a.lower(), a.upper()); }
    constexpr int contains(T l, T u) const {
        if(l <= lower() and upper() <= u) return 2;  // 区間全体を含む場合．
        if(upper() < l or u < lower()) return 0;     // 含まない場合．
        return 1;                                    // 区間の一部のみ含む場合．
    }

    friend constexpr Interval overlap(const Interval &a, const Interval &b) {
        T l = std::max(a.lower(), b.lower());
        T u = std::min(a.upper(), b.upper());
        return (l <= u ? Interval(l, u) : Interval(u, u));
    }
};

template <typename Type>
constexpr Interval<Type> overlap(std::initializer_list<Interval<Type> > list) {
    Interval<Type> res(std::numeric_limits<Type>::min(), std::numeric_limits<Type>::max());
    for(const auto &elem : list) res = overlap(res, elem);
    return res;
}

// Interval Set（連続していない区間を管理するクラス）
template <typename T, typename std::enable_if_t<std::is_arithmetic<T>::value, bool> = false>
class IntervalSet {
public:
    using interval = Interval<T>;

private:
    std::set<interval> m_st;  // m_st:=(区間の集合).

public:
    using iterator = std::set<interval>::iterator;
    using const_iterator = std::set<interval>::const_iterator;
    using reverse_iterator = std::set<interval>::reverse_iterator;
    using const_reverse_iterator = std::set<interval>::const_reverse_iterator;

    IntervalSet() {
        static_assert(min_limit() < max_limit());
        // 番兵を配置．
        m_st.emplace(std::numeric_limits<T>::min(), std::numeric_limits<T>::min());
        m_st.emplace(std::numeric_limits<T>::max(), std::numeric_limits<T>::max());
    }

    static constexpr T min_limit() { return std::numeric_limits<T>::min() + 1; }
    static constexpr T max_limit() { return std::numeric_limits<T>::max() - 1; }
    // 区間追加．O(logN).
    iterator insert(const interval &interval) { return insert(interval.lower(), interval.upper()); }
    iterator insert(T l, T r) {
        assert(min_limit() <= l and l < r and r <= max_limit());
        auto left = lower_bound(l);
        auto right = upper_bound(r);
        if(left == std::prev(right) and left->lower() <= l and r <= left->upper()) return left;
        if(left->lower() <= l) l = left->lower();
        if(r <= std::prev(right)->upper()) r = std::prev(right)->upper();
        return m_st.emplace_hint(m_st.erase(left, right), l, r);
    }
    // 区間削除．O(logN).
    iterator erase(const interval &interval) { return erase(interval.lower(), interval.upper()); }
    iterator erase(T l, T r) {
        assert(min_limit() <= l and l < r and r <= max_limit());
        auto left = lower_bound(l);
        auto right = upper_bound(r);
        T ll = left->lower(), rr = std::prev(right)->upper();
        auto iter = m_st.erase(left, right);
        if(r < rr) iter = m_st.emplace_hint(iter, r, rr);
        if(ll < l) m_st.emplace_hint(iter, ll, l);
        return iter;
    }
    // 集合に含まれているか判定する．O(logN).
    bool contains(T x) const {
        assert(min_limit() <= x and x < max_limit());
        auto iter = std::prev(upper_bound(x));
        return iter->lower() <= x and x < iter->upper();
    }
    // 集合に含まれているか判定する．O(logN).
    int contains(const interval &interval) const { return contains(interval.lower(), interval.upper()); }
    int contains(T l, T r) const {
        assert(min_limit() <= l and l < r and r <= max_limit());
        auto left = lower_bound(l);
        auto right = upper_bound(r);
        if(left == right) return 0;                                                           // 含まない場合．
        if(left == std::prev(right) and left->lower() <= l and r <= left->upper()) return 2;  // 区間全体を含む場合．
        return 1;                                                                             // 区間の一部のみ含む場合．
    }
    // x以上で集合に含まれない最小の値 (mex: Minimum EXcluded value) を求める．O(logN).
    T mex(T x) const {
        auto iter = lower_bound(x);
        return (x < iter->upper() ? iter->upper() : x);
    }
    void clear() { m_st.erase(begin(), end()); }

    const_iterator begin() const { return std::next(m_st.begin()); }
    const_iterator cbegin() const { return std::next(m_st.cbegin()); }
    const_iterator end() const { return std::prev(m_st.end()); }
    const_iterator cend() const { return std::prev(m_st.cend()); }
    const_reverse_iterator rbegin() const { return std::next(m_st.rbegin()); }
    const_reverse_iterator crbegin() const { return std::next(m_st.crbegin()); }
    const_reverse_iterator rend() const { return std::prev(m_st.rend()); }
    const_reverse_iterator crend() const { return std::prev(m_st.crend()); }
    const_iterator lower_bound(T x) const {
        assert(min_limit() <= x and x < max_limit());
        auto iter = m_st.lower_bound(interval(x + 1, x + 1));
        auto pre = std::prev(iter);
        return (x < pre->upper() ? pre : iter);
    }
    const_iterator upper_bound(T x) const {
        assert(min_limit() <= x and x < max_limit());
        return m_st.lower_bound(interval(x + 1, x + 1));
    }
    iterator erase(const_iterator iter) { return m_st.erase(iter); }
    iterator erase(const_iterator l, const_iterator r) { return m_st.erase(l, r); }
};

}  // namespace algorithm

#endif
