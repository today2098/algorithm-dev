#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP
#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP 1

/**
 * @brief 重み付きUnion-Find
 * @docs docs/DataStructure/UnionFind/potentialized_union_find.md
 */

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// 重み付きUnion-Find．
template <typename T>
class PotentializedUnionFind {
    int m_vn;  // m_vn:=(要素数).
    int m_gn;  // m_gn:=(グループ数).
    // m_par[x]:=(要素xの親). 0未満の場合，xは根であり，値の絶対値は属するグループのサイズを表す．
    std::vector<int> m_par;
    std::vector<T> m_h;  // m_h[x]:=(要素xのポテンシャル).

public:
    PotentializedUnionFind() : PotentializedUnionFind(0) {}
    explicit PotentializedUnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1), m_h(vn, 0) {}

    // 要素の総数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 要素xが属するグループ（根付き木）の根を返す．O(α(N)).
    int root(int x) {
        assert(0 <= x and x < vn());
        if(m_par[x] < 0) return x;
        int rt = root(m_par[x]);  // 経路圧縮．
        m_h[x] += m_h[m_par[x]];
        return m_par[x] = rt;
    }
    // 要素xが属するグループのサイズを返す．
    int size(int x) {
        assert(0 <= x and x < vn());
        return -m_par[root(x)];
    }
    // 要素xのポテンシャルを返す．
    T potential(int x) {
        assert(0 <= x and x < vn());
        root(x);
        return m_h[x];
    }
    // 要素x, yが同じグループに属するか判定する．
    bool is_same(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root(x) == root(y);
    }
    // 要素xに対するyの相対ポテンシャルを返す．
    T diff(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return potential(y) - potential(x);
    }
    // diff(x,y)==d となるように，要素x, yが属するそれぞれのグループを併合する．
    bool unite(int x, int y, T d) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        d = potential(x) + d - potential(y);
        x = root(x), y = root(y);
        if(x == y) return false;     // Do nothing.
        if(-m_par[x] < -m_par[y]) {  // Merge technique (union by size).
            std::swap(x, y);
            d = -d;
        }
        m_par[x] += m_par[y];
        m_par[y] = x;
        m_h[y] = d;
        m_gn--;
        return true;
    }
    void reset() {
        m_gn = vn();
        std::fill(m_par.begin(), m_par.end(), -1);
        std::fill(m_h.begin(), m_h.end(), 0);
    }
};

}  // namespace algorithm

#endif
