#ifndef ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP
#define ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP 1

/**
 * @brief Partially Persistent Union-Find（部分永続Unionf-Find）
 * @docs docs/DataStructure/UnionFind/partially_persistent_union_find.md
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>

namespace algorithm {

// 部分永続Union-Find．
class PartiallyPersistentUnionFind {
    using pii = std::pair<int, int>;

    int m_now;  // m_now:=(現在時刻).
    int m_vn;   // m_vn:=(要素数).
    int m_gn;   // m_gn:=(グループ数).
    // m_par[x][]:=(要素xについて時刻tとその時刻における親parの情報リスト). pair of (t, par).
    // 値idが0未満の場合，xは根であり，値parの絶対値は属するグループのサイズを表す．
    std::vector<std::vector<pii> > m_par;

    static constexpr int infinity() { return std::numeric_limits<int>::max(); }

public:
    PartiallyPersistentUnionFind() : PartiallyPersistentUnionFind(0) {}
    explicit PartiallyPersistentUnionFind(size_t vn)
        : m_now(0), m_vn(vn), m_gn(vn), m_par(vn, std::vector<pii>({{0, -1}})) {}

    // 現在の時刻を返す．
    int now() const { return m_now; }
    // 要素の総数を返す．
    int vn() const { return m_vn; };
    // グループ数を返す．
    int gn() const { return m_gn; };
    // 現時刻において要素xが属するグループ（根付き木）の根を返す．O(logN).
    int root(int x) const {
        assert(0 <= x and x < vn());
        while(m_par[x].back().second >= 0) x = m_par[x].back().second;
        return x;
    }
    // 時刻tにおいて要素xが属するグループ（根付き木）の根を返す．O(logN).
    int root(int x, int t) const {
        assert(0 <= x and x < vn());
        assert(0 <= t and t <= now());
        auto itr = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(), pii(t, -infinity()));
        if(itr == m_par[x].cend() or itr->first > t) itr--;
        if(itr->second < 0) return x;
        return root(itr->second, t);
    }
    // 現時刻において要素xが属するグループのサイズを返す．O(logN).
    int size(int x) const {
        assert(0 <= x and x < vn());
        return -m_par[root(x)].back().second;
    }
    // 時刻tにおいて要素xが属するグループのサイズを返す．O(logN).
    int size(int x, int t) const {
        assert(0 <= x and x < vn());
        assert(0 <= t and t <= now());
        auto itr = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(), pii(t, -infinity()));
        if(itr == m_par[x].cend() or itr->first > t) itr--;
        if(itr->second < 0) return -itr->second;
        return size(itr->second, t);
    }
    // 現在において要素x, yが同じグループに属するか判定する．O(logN).
    bool is_same(int x, int y) const {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        return root(x) == root(y);
    }
    // 時刻tにおいて要素x, yが同じグループに属するか判定する．O(logN).
    bool is_same(int x, int y, int t) const {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        assert(0 <= t and t <= now());
        return root(x, t) == root(y, t);
    }
    // 要素x, yが属するそれぞれのグループを併合し，時間を+1進める．O(logN).
    bool unite(int x, int y) {
        assert(0 <= x and x < vn());
        assert(0 <= y and y < vn());
        m_now++;
        x = root(x), y = root(y);
        if(x == y) return false;
        int sz_x = -m_par[x].back().second;
        int sz_y = -m_par[y].back().second;
        if(sz_x < sz_y) std::swap(x, y);  // Merge technique (unite by size).
        m_par[x].emplace_back(now(), -sz_x - sz_y);
        m_par[y].emplace_back(now(), x);
        m_gn--;
        return true;
    }
    void reset() {
        m_now = 0;
        m_gn = vn();
        for(std::vector<pii> &history : m_par) history.resize(1);
    }
};

}  // namespace algorithm

#endif
