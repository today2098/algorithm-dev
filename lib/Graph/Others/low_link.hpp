#ifndef ALGORITHM_LOW_LINK_HPP
#define ALGORITHM_LOW_LINK_HPP 1

/**
 * @brief Low-Link（橋，関節点）
 * @docs docs/Graph/Others/low_link.md
 */

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

class LowLink {
    int m_vn;                                 // m_vn:=(頂点数).
    std::vector<std::vector<int> > m_g;       // m_g[v][]:=(頂点vの隣接リスト).
    std::vector<int> m_aps;                   // m_aps[]:=(関節点のリスト). Articulation points.
    std::vector<std::pair<int, int> > m_brs;  // m_brs[]:=(橋のリスト). Bridges.

    void dfs(int u, int p, std::vector<int> &ord, std::vector<int> &low, int &now) {
        ord[u] = low[u] = now++;
        int degree = 0;      // degree:=(DFS木での頂点uにおける葉方向への出次数).
        bool is_ap = false;  // is_ap:=(頂点uが関節点か).
        for(int v : m_g[u]) {
            if(v == p) continue;
            if(ord[v] == -1) {  // 頂点vが未訪問のとき．
                degree++;
                dfs(v, u, ord, low, now);
                low[u] = std::min(low[u], low[v]);
                if(ord[u] < low[v]) {  // 辺(u,v)が橋のとき．
                    if(u < v) m_brs.emplace_back(u, v);
                    else m_brs.emplace_back(v, u);
                }
                if(p != -1 and ord[u] <= low[v]) is_ap = true;  // 根以外で関節点のとき．
            } else {                                            // 辺(u,v)が後退辺のとき．
                low[u] = std::min(low[u], ord[v]);
            }
        }
        if(p == -1 and degree > 1) is_ap = true;  // 根が関節点のとき．
        if(is_ap) m_aps.push_back(u);
    }

public:
    // constructor. O(|V|).
    LowLink() : LowLink(0) {}
    explicit LowLink(size_t vn) : m_g(vn) {}

    // 頂点数を返す．
    int order() const { return m_vn; }
    // 無向辺を張る．
    void add_edge(int u, int v) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].push_back(v);
        m_g[v].push_back(u);
    }
    // 無向グラフの橋と関節点を求める．O(|V|+|E|).
    void lowlink() {
        m_aps.clear();
        m_brs.clear();
        // ord[v]:=(DFS木における頂点vの行きかけ順序).
        // low[v]:=(DFS木において，頂点vから葉方向への辺を0回以上，後退辺を高々1回用いて到達できる頂点wに対するord[w]の最小値).
        std::vector<int> ord(order(), -1), low(order());
        int now = 0;
        for(int v = 0; v < order(); ++v) {
            if(ord[v] == -1) dfs(v, -1, ord, low, now);
        }
        std::sort(m_aps.begin(), m_aps.end());
        std::sort(m_brs.begin(), m_brs.end());
    }
    // 関節点のリストを参照する．
    const std::vector<int> &articulation_points() const { return m_aps; }
    // 橋のリストを参照する．
    const std::vector<std::pair<int, int> > &bridges() const { return m_brs; }
};

}  // namespace algorithm

#endif
