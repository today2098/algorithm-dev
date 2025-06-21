#ifndef ALGORITHM_UNION_FIND_HPP
#define ALGORITHM_UNION_FIND_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

class UnionFind {
    int m_vn;  // m_vn:=(要素数).
    int m_gn;  // m_gn:=(集合の数).
    // m_par[x]:=(要素xの親). 0未満の場合，xは代表元であり，値の絶対値は属する集合のサイズを表す．
    std::vector<int> m_par;

    int root_internal(int x) {
        if(m_par[x] < 0) return x;
        return m_par[x] = root_internal(m_par[x]);  // 経路圧縮．
    }

public:
    UnionFind() : UnionFind(0) {}
    explicit UnionFind(int n) : m_vn(n), m_gn(n), m_par(n, -1) {
        assert(n >= 0);
    }

    // 要素数を取得する．
    int vn() const { return m_vn; };
    // 集合の数を取得する．
    int gn() const { return m_gn; };
    // 要素xが属する集合の代表元を取得する．
    int root(int x) {
        assert(0 <= x and x < vn());
        return root_internal(x);
    }
    // 要素xが属する集合のサイズを取得する．
    int size(int x) {
        assert(0 <= x and x < vn());
        return -m_par[root_internal(x)];
    }
    // 要素x, yが同じ集合に属するか判定する．
    bool is_same(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root_internal(x) == root_internal(y);
    }
    // 要素x, yが属するそれぞれの集合を合併する．
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        x = root_internal(x), y = root_internal(y);
        if(x == y) return false;                    // Do nothing.
        if(-m_par[x] < -m_par[y]) std::swap(x, y);  // Merge technique (union by size).
        m_par[x] += m_par[y];
        m_par[y] = x;
        --m_gn;
        return true;
    }
    void reset() {
        m_gn = m_vn;
        std::fill(m_par.begin(), m_par.end(), -1);
    }
};

}  // namespace algorithm

#endif
