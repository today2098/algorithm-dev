#ifndef ALGORITHM_INTEGER_INTERVAL_SET_HPP
#define ALGORITHM_INTEGER_INTERVAL_SET_HPP 1

/**
 * @brief Integer Interval Set（整数の集合を区間で管理するデータ構造）
 * @docs docs/DataStructure/Others/integer_interval_set.md
 */

#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#include <type_traits>
#include <utility>

namespace algorithm {

// Integer Interval Set（整数の集合を区間で管理するデータ構造）.
template <typename T, typename std::enable_if_t<std::is_integral<T>::value, bool> = false>
class IntegerIntervalSet {
    std::set<std::pair<T, T> > m_st;  // m_st:=(整数の集合). 連続している区間[l,r)をpair(l,r)で表現する．

public:
    IntegerIntervalSet() {
        static_assert(min_limit() < max_limit());
        // 番兵を配置．
        m_st.emplace(min_limit() - 2, min_limit() - 1);
        m_st.emplace(max_limit() + 1, max_limit() + 2);
    }

    static constexpr T min_limit() { return std::numeric_limits<T>::min() + 2; }
    static constexpr T max_limit() { return std::numeric_limits<T>::max() - 2; }
    // 整数xを追加する．O(logN).
    bool insert(T x) { return insert(x, x + 1); }
    // 区間[l,r)の整数を追加する．O(logN).
    bool insert(T l, T r) {
        assert(min_limit() <= l and l < r and r <= max_limit());
        auto iter1 = std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));
        auto [l1, r1] = *iter1;
        if(r <= r1) return false;  // 全て集合に含まれている場合．
        if(l <= r1) l = l1;
        else iter1++;
        auto iter3 = m_st.lower_bound(std::pair<T, T>(r, r));
        auto iter2 = std::prev(iter3);
        auto [l2, r2] = *iter2;
        auto [l3, r3] = *iter3;
        if(r == l3) {
            m_st.erase(iter1, ++iter3);
            m_st.emplace(l, r3);
        } else {
            m_st.erase(iter1, iter3);
            if(r <= r2) m_st.emplace(l, r2);
            else m_st.emplace(l, r);
        }
        return true;
    }
    // 整数xを削除する．O(logN).
    bool erase(T x) { return erase(x, x + 1); }
    // 区間[l,r)の整数を削除する．O(logN).
    bool erase(T l, T r) {
        assert(min_limit() <= l and l < r and r <= max_limit());
        auto iter1 = std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));
        auto iter3 = m_st.lower_bound(std::pair<T, T>(r, r));
        auto iter2 = std::prev(iter3);
        auto [l1, r1] = *iter1;
        auto [l2, r2] = *iter2;
        if(l < r1) {
            m_st.erase(iter1, iter3);
            if(l1 < l) m_st.emplace(l1, l);
        } else {
            if(iter1 == iter2) return false;  // 全て集合に含まれていない場合．
            m_st.erase(++iter1, iter3);
        }
        if(r < r2) m_st.emplace(r, r2);
        return true;
    }
    // 整数xが集合に含まれているか判定する．O(logN).
    int contains(T x) const { return contains(x, x + 1); }
    // 区間[l,r)の整数が集合に含まれているか判定する．O(logN).
    int contains(T l, T r) const {
        assert(min_limit() <= l and l < r and r <= max_limit());
        const auto &[_, pr] = *std::prev(m_st.lower_bound(std::pair<T, T>(l + 1, l + 1)));
        if(pr <= l) return 0;  // 全て含まれていない場合．
        if(pr < r) return 1;   // 一部のみ含まれている場合．
        return 2;              // 全て含まれている場合．
    }
    // x以上の整数で集合に含まれない最小の値 (mex: Minimum EXcluded value) を求める．O(logN).
    T mex(T x) const {
        assert(min_limit() <= x and x < max_limit());
        const auto &[_, r] = *std::prev(m_st.lower_bound(std::pair<T, T>(x + 1, x + 1)));
        return (x < r ? r : x);
    }

    friend std::ostream &operator<<(std::ostream &os, const IntegerIntervalSet &ob) {
        os << "[";
        const int n = ob.m_st.size();
        int cnt = 0;
        for(auto iter = ob.m_st.cbegin(); iter != ob.m_st.cend(); ++iter) {
            if(0 < cnt and cnt < n - 1) {
                const auto &[l, r] = *iter;
                os << (cnt == 1 ? "" : " ") << "[" << l << ", " << r << ")";
            }
            cnt++;
        }
        os << "]";
        return os;
    }
};

}  // namespace algorithm

#endif
