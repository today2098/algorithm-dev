#ifndef ALGORITHM_ROLLBACK_UNION_FIND_HPP
#define ALGORITHM_ROLLBACK_UNION_FIND_HPP 1

#include <algorithm>
#include <cassert>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

// Rollback付きUnion-Find．
class RollbackUnionFind {
    int m_vn;  // m_vn:=(要素数).
    int m_gn;  // m_gn:=(集合の数).
    // m_par[x]:=(要素xの親). 0未満の場合，xは代表元であり，値の絶対値は属する集合のサイズを表す．
    std::vector<int> m_par;
    std::stack<std::tuple<int, int, int, int>> m_history;  // tuple of (x, m_par[x], y, m_par[y]).

    int root_internal(int x) const {
        if(m_par[x] < 0) return x;
        return root_internal(m_par[x]);
    }

public:
    RollbackUnionFind() : RollbackUnionFind(0) {}
    explicit RollbackUnionFind(int n) : m_vn(n), m_gn(n), m_par(n, -1) {
        assert(n >= 0);
    }

    // 現在のヒストリーのインデックスを取得する．O(1).
    int index() const { return m_history.size(); }
    // 要素数を返す．
    int vn() const { return m_vn; };
    // 集合の数を返す．
    int gn() const { return m_gn; };
    // 要素xが属する集合の代表元を取得する．O(log N).
    int root(int x) const {
        assert(0 <= x and x < vn());
        return root_internal(x);
    }
    // 要素xが属する集合のサイズを取得する．O(log N).
    int size(int x) const { return -m_par[root(x)]; }
    // 要素x, yが同じグループに属するか判定する．O(log N).
    bool is_same(int x, int y) const { return root(x) == root(y); }
    // 要素x, yが属するそれぞれの集合を合併する．O(log N).
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        x = root_internal(x), y = root_internal(y);
        m_history.emplace(x, m_par[x], y, m_par[y]);
        if(x == y) return false;
        if(-m_par[x] < -m_par[y]) std::swap(x, y);  // Merge technique (union by size).
        m_par[x] += m_par[y];
        m_par[y] = x;
        --m_gn;
        return true;
    }
    // 直前の状態に戻す．O(1).
    void rollback() {
        assert(!m_history.empty());
        auto [x, xp, y, yp] = m_history.top();
        m_history.pop();
        m_par[x] = xp, m_par[y] = yp;
    }
    void reset() {
        m_gn = m_vn;
        std::fill(m_par.begin(), m_par.end(), -1);
        std::stack<std::tuple<int, int, int, int>>().swap(m_history);
    }
};

}  // namespace algorithm

#endif
