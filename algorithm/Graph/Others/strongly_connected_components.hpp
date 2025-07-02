#ifndef ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP
#define ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP 1

/**
 * @brief Strongly Connected Components（強連結成分分解）
 * @docs docs/Graph/Others/strongly_connected_components.md
 */

#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>
#include <vector>

namespace algorithm {

// Strongly Connected Components（強連結成分分解）.
class SCC {
    int m_vn;                            // m_vn:=(ノード数).
    std::vector<std::vector<int> > m_g;  // m_g[v][]:=(ノードvの隣接リスト).

public:
    SCC() : SCC(0) {}
    explicit SCC(int vn) : m_vn(vn), m_g(vn) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    // 有向辺を張る．
    void add_edge(int from, int to) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].push_back(to);
    }
    // 有向グラフを強連結成分分解する．return pair of (# of SCCs, SCC id of each nodes). O(|V|+|E|).
    std::pair<int, std::vector<int> > decompose() const {
        int num_sccs = 0;               // num_sccs:=(SCCの数).
        std::vector<int> ids(order());  // ids[v]:=(ノードvが属するSCCのID).
        // ord[v]:=(DFS木におけるノードvの行きがけ順序).
        // low[v]:=(DFS木において，ノードvから葉方向への辺を0回以上，後退辺を高々1回用いて到達できるノードwに対するord[w]の最小値).
        std::vector<int> ord(order(), -1), low(order());
        int now = 0;
        std::stack<int> visited;
        auto dfs = [&](auto self, int u) -> void {
            ord[u] = low[u] = now++;
            visited.push(u);
            for(int to : m_g[u]) {
                if(ord[to] == -1) {
                    self(self, to);
                    low[u] = std::min(low[u], low[to]);
                } else {
                    low[u] = std::min(low[u], ord[to]);
                }
            }
            if(low[u] == ord[u]) {
                while(true) {
                    int v = visited.top();
                    visited.pop();
                    ord[v] = order();  // inf.
                    ids[v] = num_sccs;
                    if(v == u) break;
                }
                num_sccs++;
            }
        };
        for(int v = 0; v < order(); ++v) {
            if(ord[v] == -1) dfs(dfs, v);
        }
        return {num_sccs, ids};
    }
    // 強連結成分ごとに各ノードをグループ分けする．
    std::vector<std::vector<int> > scc() const { return scc(decompose()); }
    std::vector<std::vector<int> > scc(const std::pair<int, std::vector<int> > &p) const { return scc(p.first, p.second); }
    std::vector<std::vector<int> > scc(int num, const std::vector<int> &ids) const {
        assert((int)ids.size() == order());
        std::vector<std::vector<int> > sccs(num);
        for(int v = 0; v < order(); ++v) {
            assert(0 <= ids[v] and ids[v] < num);
            sccs[ids[v]].push_back(v);
        }
        return sccs;
    }
    // 強連結成分から構成されるDAGを取得する．
    std::vector<std::vector<int> > directed_acyclic_graph(const std::pair<int, std::vector<int> > &p) const { return directed_acyclic_graph(p.first, p.second); }
    std::vector<std::vector<int> > directed_acyclic_graph(int num, const std::vector<int> &ids) const {
        assert((int)ids.size() == order());
        std::vector<std::vector<int> > dag(num);
        for(int u = 0; u < order(); ++u) {
            assert(0 <= ids[u] and ids[u] < num);
            for(int v : m_g[u]) {
                assert(0 <= ids[v] and ids[v] < num);
                if(ids[v] == ids[u]) continue;
                dag[ids[u]].push_back(ids[v]);
            }
        }
        for(std::vector<int> &edge : dag) {
            std::sort(edge.begin(), edge.end());
            edge.erase(std::unique(edge.begin(), edge.end()), edge.end());
        }
        return dag;
    }
};

}  // namespace algorithm

#endif
