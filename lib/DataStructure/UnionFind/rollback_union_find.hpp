#ifndef ALGORITHM_ROLLBACK_UNION_FIND_HPP
#define ALGORITHM_ROLLBACK_UNION_FIND_HPP 1

/**
 * @brief Rollback付きUnion-Find
 * @docs docs/DataStructure/UnionFind/rollback_union_find.md
 */

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
    int m_gn;  // m_gn:=(グループ数).
    // m_par[x]:=(要素xの親). 0未満の場合，xは根であり，値の絶対値は属するグループのサイズを表す．
    std::vector<int> m_par;
    std::stack<std::tuple<int, int, int, int> > m_history;  // tuple of (x, m_par[x], y, m_par[y]).

public:
    RollbackUnionFind() : RollbackUnionFind(0) {}
    explicit RollbackUnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}

    // 現在のヒストリーのインデックスを返す．O(1).
    int index() const { return m_history.size(); }
    // 要素の総数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 要素xが属するグループ（根付き木）の根を返す．O(logN).
    int root(int x) const {
        assert(0 <= x and x < vn());
        if(m_par[x] < 0) return x;
        return root(m_par[x]);
    }
    // 要素xが属するグループのサイズを返す．O(logN).
    int size(int x) const {
        assert(0 <= x and x < vn());
        return -m_par[root(x)];
    }
    // 要素x, yが同じグループに属するか判定する．O(logN).
    bool is_same(int x, int y) const {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root(x) == root(y);
    }
    // 要素x, yが属するそれぞれのグループを併合する．O(logN).
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        x = root(x), y = root(y);
        m_history.emplace(x, m_par[x], y, m_par[y]);
        if(x == y) return false;
        if(size(x) < size(y)) std::swap(x, y);  // Merge technique (union by size).
        m_par[x] += m_par[y];
        m_par[y] = x;
        m_gn--;
        return true;
    }
    // 直前の状態に戻す．O(1).
    void rollback() {
        assert(index() >= 1);
        auto [x, value_x, y, value_y] = m_history.top();
        m_history.pop();
        m_par[x] = value_x, m_par[y] = value_y;
    }
    void reset() {
        m_gn = vn();
        std::fill(m_par.begin(), m_par.end(), -1);
        std::stack<std::tuple<int, int, int, int> >().swap(m_history);
    }
};

}  // namespace algorithm

#endif
