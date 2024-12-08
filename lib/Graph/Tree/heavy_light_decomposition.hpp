#ifndef ALGORITHM_HEAVY_LIGHT_DECOMPOSITION_HPP
#define ALGORITHM_HEAVY_LIGHT_DECOMPOSITION_HPP 1

/**
 * @brief Heavy-Light Decomposition（HL分解，重軽分解）
 * @docs docs/Graph/Tree/heavy_light_decomposition.md
 */

#include <algorithm>
#include <cassert>
#include <functional>
#include <utility>
#include <vector>

namespace algorithm {

// Heavy-Light Decomposition（HL分解，重軽分解）.
class HLD {
    int m_vn;                            // m_vn:=(ノード数).
    std::vector<std::vector<int> > m_g;  // m_g[v][]:=(ノードvの隣接リスト). グラフは木であること．
    std::vector<int> m_par;              // m_par[v]:=(ノードvの親番号).
    std::vector<int> m_sub;              // m_sub[v]:=(ノードvを根とする部分木のサイズ).
    std::vector<int> m_head;             // m_head[v]:=(ノードvを含むheavy pathの端点).
    std::vector<int> m_ord;              // m_ord[v]:=(ノードvの行きかけ順序).

    int dfs1(int u, int p) {
        assert(m_par[u] == -1);  // グラフ上に閉路はないこと．
        m_par[u] = p;
        m_sub[u] = 1;
        if(m_g[u].size() > 1 and m_g[u][0] == p) std::swap(m_g[u][0], m_g[u].back());
        for(int &v : m_g[u]) {
            if(v == p) continue;
            m_sub[u] += dfs1(v, u);
            if(m_sub[v] > m_sub[m_g[u][0]]) std::swap(m_g[u][0], v);  // m_g[u][0]にheavy childを格納する．
        }
        return m_sub[u];
    }
    void dfs2(int u, int p, int &now) {
        m_ord[u] = now++;
        for(int v : m_g[u]) {
            if(v == p) continue;
            m_head[v] = (v == m_g[u][0] ? m_head[u] : v);
            dfs2(v, u, now);
        }
    }

public:
    // constructor. O(|V|).
    HLD() : HLD(0) {}
    explicit HLD(size_t vn) : m_vn(vn), m_g(vn), m_par(vn), m_sub(vn), m_head(vn), m_ord(vn, -1) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    // 無向辺を張る．
    void add_edge(int u, int v) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].push_back(v);
        m_g[v].push_back(u);
    }
    // 木をHL分解する．O(|V|).
    void build(int rt = 0) {
        assert(0 <= rt and rt < order());
        std::fill(m_par.begin(), m_par.end(), -1);
        dfs1(rt, -1);
        m_head[rt] = rt;
        std::fill(m_ord.begin(), m_ord.end(), -1);
        int now = 0;
        dfs2(rt, -1, now);
    }
    // ノードvの行きがけ順序における番号を返す．
    int vid(int v) const {
        assert(0 <= v and v < order());
        return m_ord[v];
    }
    // パスu-vにおける頂点属性のクエリに対応する範囲を返す．O(log|V|).
    std::vector<std::pair<int, int> > vertex_query_ranges(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(m_ord[u] == -1 or m_ord[v] == -1) return {};
        std::vector<std::pair<int, int> > res;
        while(true) {
            if(m_ord[u] > m_ord[v]) std::swap(u, v);
            if(m_head[u] == m_head[v]) {
                res.emplace_back(m_ord[u], m_ord[v] + 1);
                break;
            }
            res.emplace_back(m_ord[m_head[v]], m_ord[v] + 1);
            v = m_par[m_head[v]];
        }
        return res;
    }
    // ノードvを根とする部分木における頂点属性のクエリに対応する範囲を返す．O(1).
    std::pair<int, int> subtree_vertex_query_range(int v) const {
        assert(0 <= v and v < order());
        if(m_ord[v] == -1) return {-1, -1};
        return {m_ord[v], m_ord[v] + m_sub[v]};
    }
    // 木上のノードuとvの最近共通祖先を求める．O(log|V|).
    int lca(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(m_ord[u] == -1 or m_ord[v] == -1) return -1;
        while(true) {
            if(m_ord[u] > m_ord[v]) std::swap(u, v);
            if(m_head[u] == m_head[v]) return u;
            v = m_par[m_head[v]];
        }
    }
};

}  // namespace algorithm

#endif
