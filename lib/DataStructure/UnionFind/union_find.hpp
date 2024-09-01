#ifndef ALGORITHM_UNION_FIND_HPP
#define ALGORITHM_UNION_FIND_HPP 1

/**
 * @brief Union-Find（素集合データ構造）
 * @docs docs/DataStructure/UnionFind/union_find.md
 */

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

class UnionFind {
    int m_vn;  // m_vn:=(要素数).
    int m_gn;  // m_gn:=(グループ数).
    // m_par[x]:=(要素xの親番号). 0未満の場合，xは根であり，値の絶対値は属するグループのサイズを表す．
    std::vector<int> m_par;

public:
    UnionFind() : UnionFind(0) {}
    explicit UnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}

    // 要素の総数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 要素xが属するグループ（根付き木）の根番号を返す．O(α(N)).
    int root(int x) {
        assert(0 <= x and x < vn());
        if(m_par[x] < 0) return x;
        return m_par[x] = root(m_par[x]);  // 経路圧縮．
    }
    // 要素xが属するグループのサイズを返す．
    int size(int x) {
        assert(0 <= x and x < vn());
        return -m_par[root(x)];
    }
    // 要素x, yが同じグループに属するか判定する．
    bool is_same(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root(x) == root(y);
    }
    // 要素xが属するグループと要素yが属するグループとを併合する．
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        x = root(x), y = root(y);
        if(x == y) return false;                // Do nothing.
        if(size(x) < size(y)) std::swap(x, y);  // Merge technique (union by size).
        m_par[x] += m_par[y];
        m_par[y] = x;
        m_gn--;
        return true;
    }
    void reset() {
        m_gn = vn();
        std::fill(m_par.begin(), m_par.end(), -1);
    }
};

}  // namespace algorithm

#endif
