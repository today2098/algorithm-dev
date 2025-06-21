#ifndef ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP
#define ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// 部分永続Union-Find．
class PartiallyPersistentUnionFind {
    int m_now;  // m_now:=(現在時刻).
    int m_vn;   // m_vn:=(要素数).
    int m_gn;   // m_gn:=(集合の数).
    // m_par[x][]:=(要素xについて時刻tとその時刻における親parの情報リスト). pair of (t, par).
    // 値parが0未満の場合，xは代表元であり，値parの絶対値は属する集合のサイズを表す．
    std::vector<std::vector<std::pair<int, int>>> m_par;

    std::tuple<int, int, int> root_internal(int x) const {
        if(m_par[x].back().second < 0) return {m_par[x].back().first, x, -m_par[x].back().second};  // return tuple of (t, root, size).
        return root_internal(m_par[x].back().second);
    }
    std::tuple<int, int, int> root_internal(int x, int t) const {
        auto iter = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(), std::pair<int, int>(t, -m_vn));
        if(iter == m_par[x].cend() or iter->first > t) --iter;
        if(iter->second < 0) return {iter->first, x, -iter->second};  // return tuple of (t, root, size).
        return root_internal(iter->second, t);
    }

public:
    PartiallyPersistentUnionFind() : PartiallyPersistentUnionFind(0) {}
    explicit PartiallyPersistentUnionFind(int n)
        : m_now(0), m_vn(n), m_gn(n), m_par(n, std::vector<std::pair<int, int>>({{0, -1}})) {
        assert(n >= 0);
    }

    // 現在の時刻を取得する．
    int now() const { return m_now; }
    // 要素数を取得する．
    int vn() const { return m_vn; };
    // 要素数を取得する．
    int gn() const { return m_gn; };
    // 現時刻において要素xが属する集合の代表元を取得する．O(log N).
    int root(int x) const {
        assert(0 <= x and x < vn());
        return std::get<1>(root_internal(x));
    }
    // 時刻tにおいて要素xが属する集合の代表元を返す．O(log N).
    int root(int x, int t) const {
        assert(0 <= x and x < vn());
        assert(0 <= t and t <= now());
        return std::get<1>(root_internal(x, t));
    }
    // 現時刻において要素xが属する集合のサイズを取得する．O(log N).
    int size(int x) const {
        assert(0 <= x and x < vn());
        return std::get<2>(root_internal(x));
    }
    // 時刻tにおいて要素xが属する集合のサイズを取得する．O(log N).
    int size(int x, int t) const {
        assert(0 <= x and x < vn());
        assert(0 <= t and t <= now());
        return std::get<2>(root_internal(x, t));
    }
    // 現在において要素x, yが同じ集合に属するか判定する．O(log N).
    bool is_same(int x, int y) const { return root(x) == root(y); }
    // 時刻tにおいて要素x, yが同じ集合に属するか判定する．O(log N).
    bool is_same(int x, int y, int t) const { return root(x, t) == root(y, t); }
    // 要素x, yが属するそれぞれの集合を合併し，時間を+1進める．O(log N).
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        ++m_now;
        auto [_, xr, sz_x] = root_internal(x);
        auto [__, yr, sz_y] = root_internal(y);
        if(xr == yr) return false;
        if(sz_x < sz_y) std::swap(xr, yr);  // Merge technique (union by size).
        m_par[xr].emplace_back(m_now, -sz_x - sz_y);
        m_par[yr].emplace_back(m_now, xr);
        --m_gn;
        return true;
    }
    void reset() {
        m_now = 0, m_gn = m_vn;
        for(auto &history : m_par) history.resize(1);
    }
};

}  // namespace algorithm

#endif
