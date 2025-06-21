#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP
#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// 重み付きUnion-Find．
template <typename T>
class PotentializedUnionFind {
public:
    using value_type = T;

private:
    int m_vn;  // m_vn:=(要素数).
    int m_gn;  // m_gn:=(集合の数).
    // m_par[x]:=(要素xの親). 0未満の場合，xは代表元であり，値の絶対値は属する集合のサイズを表す．
    std::vector<int> m_par;
    std::vector<value_type> m_h;  // m_h[x]:=(要素xのポテンシャル).

    int root_internal(int x) {
        if(m_par[x] < 0) return x;
        int rt = root_internal(m_par[x]);  // 経路圧縮．
        m_h[x] += m_h[m_par[x]];
        return m_par[x] = rt;
    }
    value_type potential_internal(int x) {
        root_internal(x);
        return m_h[x];
    }

public:
    PotentializedUnionFind() : PotentializedUnionFind(0) {}
    explicit PotentializedUnionFind(int n) : m_vn(n), m_gn(n), m_par(n, -1), m_h(n, 0) {
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
    int size(int x) { return -m_par[root(x)]; }
    // 要素xのポテンシャルを取得する．
    value_type potential(int x) {
        assert(0 <= x and x < vn());
        return potential_internal(x);
    }
    // 要素x, yが同じ集合に属するか判定する．
    bool is_same(int x, int y) { return root(x) == root(y); }
    // 要素xに対するyの相対ポテンシャルを求める．
    value_type diff(int x, int y) { return potential(y) - potential(x); }
    // diff(x,y)==d となるように，要素x, yが属するそれぞれの集合を合併する．
    bool unite(int x, int y, value_type d) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        d = potential_internal(x) + d - potential_internal(y);
        x = root_internal(x), y = root_internal(y);
        if(x == y) return false;     // Do nothing.
        if(-m_par[x] < -m_par[y]) {  // Merge technique (union by size).
            std::swap(x, y);
            d = -d;
        }
        m_par[x] += m_par[y];
        m_par[y] = x;
        m_h[y] = d;
        --m_gn;
        return true;
    }
    void reset() {
        m_gn = m_vn;
        std::fill(m_par.begin(), m_par.end(), -1);
        std::fill(m_h.begin(), m_h.end(), value_type());
    }
};

}  // namespace algorithm

#endif
