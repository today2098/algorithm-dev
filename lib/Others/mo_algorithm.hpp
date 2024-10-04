#ifndef ALGORITHM_MO_ALGORITHM_HPP
#define ALGORITHM_MO_ALGORITHM_HPP 1

/**
 * @brief Mo's Algorithm（クエリ平方分割）
 * @docs docs/Others/mo_algorithm.md
 */

#include <algorithm>
#include <cassert>
#include <cmath>
#include <tuple>
#include <vector>

namespace algorithm {

// Mo's Algorithm（クエリ平方分割）.
class Mo {
    int m_len;                                          // m_len:=(区間の長さ).
    int m_q;                                            // m_q:=(クエリ数).
    std::vector<std::tuple<int, int, int> > m_queries;  // m_queries[i]:=(i番目の区間クエリ). tuple of (left, right, index).

    void sort_queries() {
        if(m_q == 0) return;
        const int width = std::max(m_len / (int)std::sqrt(m_q), 1);  // width:=N/√Q.
        std::sort(m_queries.begin(), m_queries.end(), [&width](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) -> bool {
            const auto &[al, ar, _] = a;
            const auto &[bl, br, __] = b;
            int a_block = al / width, b_block = bl / width;
            if(a_block == b_block) return (a_block & 1 ? ar > br : ar < br);
            return a_block < b_block;
        });
    }

public:
    Mo() : Mo(0) {}
    explicit Mo(size_t n) : m_len(n), m_q(0) {}
    explicit Mo(size_t n, size_t q) : Mo(n) {
        m_queries.reserve(q);
    }

    // 区間[l,r)についてのクエリを追加する．
    void insert(int l, int r) {
        assert(0 <= l and l < r and r <= m_len);
        m_queries.emplace_back(l, r, m_q++);
    }
    // 各クエリを実行する．O(Q*logQ+α*N*√Q).
    template <class F1, class F2, class F3>
    void execute(const F1 &add, const F2 &del, const F3 &solve) { execute(add, del, add, del, solve); }
    template <class F1, class F2, class F3, class F4, class F5>
    void execute(const F1 &add_l, const F2 &del_l, const F3 &add_r, const F4 &del_r, const F5 &solve) {
        sort_queries();
        int l = 0, r = 0;
        for(const auto &[nl, nr, idx] : m_queries) {
            while(nl < l) add_l(--l);
            while(r < nr) add_r(r++);
            while(l < nl) del_l(l++);
            while(nr < r) del_r(--r);
            solve(idx);
        }
    }
    void reset() {
        m_queries.clear();
        m_q = 0;
    }
};

}  // namespace algorithm

#endif
