#ifndef ALGORITHM_HEAVY_LIGHT_DECOMPOSITION_HPP
#define ALGORITHM_HEAVY_LIGHT_DECOMPOSITION_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

// Heavy-Light Decomposition（HL分解，重軽分解）.
class HLD {
    int m_vn;                           // m_vn:=(ノード数).
    std::vector<std::vector<int>> m_g;  // m_g[v][]:=(ノードvの隣接リスト). グラフは森であること．
    std::vector<int> m_par, m_head;     // m_par[v]:=(ノードvの親番号), m_head[v]:=(ノードvを含むheavy pathの端点).
    std::vector<int> m_sub;             // m_sub[v]:=(ノードvを根とする部分木のサイズ).
    std::vector<int> m_ord;             // m_ord[v]:=(ノードvの行きかけ順序).
    bool m_is_built;

    bool is_built() const { return m_is_built; }

public:
    // constructor. O(|V|).
    HLD() : HLD(0) {}
    explicit HLD(int vn) : m_is_built(false), m_vn(vn), m_g(vn), m_par(vn, -1), m_sub(vn, 1), m_head(vn, -1), m_ord(vn, -1) {
        assert(vn >= 0);
    }

    // ノード数を取得する．
    int order() const { return m_vn; }
    // 無向辺を張る．
    void add_edge(int u, int v) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].push_back(v);
        m_g[v].push_back(u);
    }
    // 木をHL分解する．O(|V|).
    void build() {
        auto dfs = [&](auto self, int u, int p) -> int {
            assert(m_par[u] == -1);  // グラフに閉路はないこと．
            m_par[u] = p, m_sub[u] = 1;
            if(m_g[u].size() > 1 and m_g[u][0] == p) std::swap(m_g[u][0], m_g[u].back());
            for(auto &v : m_g[u]) {
                if(v == p) continue;
                m_sub[u] += self(self, v, u);
                if(m_sub[v] > m_sub[m_g[u][0]]) std::swap(m_g[u][0], v);  // m_g[u][0]にheavy childを格納する．
            }
            return m_sub[u];
        };
        int next = 0;
        auto dfs2 = [&](auto self, int u, int p) -> void {
            m_ord[u] = next++;
            for(auto v : m_g[u]) {
                if(v == p) continue;
                m_head[v] = (v == m_g[u][0] ? m_head[u] : v);
                self(self, v, u);
            }
        };
        std::fill(m_par.begin(), m_par.end(), -1);
        std::fill(m_ord.begin(), m_ord.end(), -1);
        for(int v = 0, end = order(); v < end; ++v) {
            if(m_par[v] != -1) continue;
            dfs(dfs, v, -1);
            m_head[v] = v;
            dfs2(dfs2, v, -1);
        }
        m_is_built = true;
    }
    // ノードvの行きがけ順序における番号を取得する．
    int vertex_index(int v) const {
        assert(0 <= v and v < order());
        return m_ord[v];
    }
    const auto &vertex_index() const { return m_ord; }
    // パスu-vにおける頂点属性のクエリに対応する範囲を求める．O(log|V|).
    std::vector<std::pair<int, int>> vertex_query_ranges(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        assert(is_built());
        std::vector<std::pair<int, int>> res;
        do {
            if(m_ord[u] > m_ord[v]) std::swap(u, v);
            if(m_head[u] == m_head[v]) {
                res.emplace_back(m_ord[u], m_ord[v] + 1);
                return res;
            }
            res.emplace_back(m_ord[m_head[v]], m_ord[v] + 1);
            v = m_par[m_head[v]];
        } while(v != -1);
        return {};  // 非連結の場合．
    }
    // ノードvを根とする部分木における頂点属性のクエリに対応する範囲を求める．O(1).
    std::pair<int, int> vertex_query_range_of_subtree(int v) const {
        assert(0 <= v and v < order());
        assert(is_built());
        return {m_ord[v], m_ord[v] + m_sub[v]};
    }
    // 木上のノードuとvの最近共通祖先を求める．O(log|V|).
    int lca(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        assert(is_built());
        do {
            if(m_ord[u] > m_ord[v]) std::swap(u, v);
            if(m_head[u] == m_head[v]) return u;
            v = m_par[m_head[v]];
        } while(v != -1);
        return -1;  // 非連結の場合．
    }
};

}  // namespace algorithm

#endif
