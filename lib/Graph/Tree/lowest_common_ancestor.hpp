#ifndef ALGORITHM_LOWEST_COMMON_ANCESTOR_HPP
#define ALGORITHM_LOWEST_COMMON_ANCESTOR_HPP 1

/**
 * @brief Lowest Common Ancestor（最近共通祖先）
 * @docs docs/Graph/Tree/lowest_common_ancestor.md
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <map>
#include <numeric>
#include <stack>
#include <utility>
#include <vector>

namespace algorithm {

// Lowest Common Ancestor（最近共通祖先）.
template <typename T = int>  // T:Type of cost.
class LCA {
    int m_vn;                                           // m_vn:=(ノード数).
    int m_lb;                                           // m_lb:=ceiling(log2(vn)).
    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(ノードvの隣接リスト). pair of (to, cost). グラフは木であること．
    std::vector<std::vector<int> > m_par;               // m_par[k][v]:=(ノードvから2^k回遡って到達する親ノード). 親ノードがいない場合は-1．
    std::vector<int> m_depth;                           // m_depth[v]:=(ノードvの深さ).
    std::vector<T> m_dist;                              // m_dist[v]:=(根からノードvまでの距離).
    std::vector<std::vector<T> > m_mx_cost;             // m_mx_cost[k][v]:=(ノードvから2^k回遡上するパスの中での最大コスト).
    std::vector<int> m_ord;                             // m_ord[v]:=(DFS木におけるノードvの行きかけ順序).

    void dfs(int u, int p, int depth, T distance, int &now) {
        assert(m_ord[u] == -1);  // グラフ上に閉路はないこと．
        m_ord[u] = now++;
        m_depth[u] = depth, m_dist[u] = distance;
        for(const auto &[v, cost] : m_g[u]) {
            if(v == p) continue;
            m_par[0][v] = u, m_mx_cost[0][v] = cost;
            dfs(v, u, depth + 1, distance + cost, now);
        }
    }
    // ノードvからk回遡上するパスの中での最大コストを求める．O(log|V|).
    T max_cost_internal(int v, int k) const {
        T res = -infinity();
        for(int i = 0; i < m_lb; ++i) {
            if(k >> i & 1) {
                res = std::max(res, m_mx_cost[i][v]);
                v = m_par[i][v];
            }
        }
        return res;
    }

public:
    // constructor. O(|V|*log|V|).
    LCA() : LCA(0) {}
    explicit LCA(size_t vn) : m_vn(vn), m_lb(1), m_g(vn), m_depth(vn, 0), m_dist(vn, 0), m_ord(vn) {
        while(1 << m_lb < order()) m_lb++;
        m_par.assign(m_lb, std::vector<int>(order(), -1));
        m_mx_cost.assign(m_lb, std::vector<T>(order(), -infinity()));
        std::iota(m_ord.begin(), m_ord.end(), 0);
    }

    static constexpr T infinity() { return std::numeric_limits<T>::max(); }
    // ノード数を返す．
    int order() const { return m_vn; }
    // 無向辺を張る．ノードuとvは非連結であること．
    void add_edge(int u, int v, T cost = 0) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].emplace_back(v, cost);
        m_g[v].emplace_back(u, cost);
    }
    // 祖先木を構築する．O(|V|*log|V|).
    void build(const std::vector<int> &rts = {}) {
        assert(std::find_if(rts.cbegin(), rts.cend(), [&](int v) -> bool { return !(0 <= v and v < order()); }) == rts.cend());
        std::fill(m_par[0].begin(), m_par[0].end(), -1);
        std::fill(m_mx_cost[0].begin(), m_mx_cost[0].end(), -infinity());
        std::fill(m_ord.begin(), m_ord.end(), -1);
        int now = 0;
        for(int rt : rts) {
            if(m_ord[rt] == -1) dfs(rt, -1, 0, 0, now);
        }
        for(int v = 0; v < order(); ++v) {
            if(m_ord[v] == -1) dfs(v, -1, 0, 0, now);
        }
        for(int k = 0; k < m_lb - 1; ++k) {
            for(int v = 0; v < order(); ++v) {
                if(m_par[k][v] == -1) {
                    m_par[k + 1][v] = -1;
                    m_mx_cost[k + 1][v] = -infinity();
                } else {
                    m_par[k + 1][v] = m_par[k][m_par[k][v]];
                    m_mx_cost[k + 1][v] = std::max(m_mx_cost[k][v], m_mx_cost[k][m_par[k][v]]);
                }
            }
        }
    }
    // ノードvの祖先をk代遡る．O(log|V|).
    int trace_back(int v, int k) const {
        assert(0 <= v and v < order());
        assert(0 <= k and k < order());
        if(k > m_depth[v]) return -1;
        for(int i = 0; i < m_lb; ++i) {
            if(k >> i & 1) v = m_par[i][v];
        }
        return v;
    }
    // 木上のノードuとvの最近共通祖先を求める．2つのノードが非連結の場合，-1を返す．O(log|V|).
    int lca(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(m_depth[u] > m_depth[v]) std::swap(u, v);
        v = trace_back(v, m_depth[v] - m_depth[u]);  // 同じ深さに合わせる．
        if(u == v) return u;
        for(int k = m_lb - 1; k >= 0; --k) {
            if(m_par[k][u] != m_par[k][v]) u = m_par[k][u], v = m_par[k][v];  // 異なったら根に近づける．
        }
        return m_par[0][u];
    }
    // ノードvの深さを返す．O(1).
    T depth(int v) const {
        assert(0 <= v and v < order());
        return m_depth[v];
    }
    // ノードu, v間の長さを求める．O(log|V|).
    int length(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        int w = lca(u, v);
        if(w == -1) return -1;
        return m_depth[u] + m_depth[v] - 2 * m_depth[w];
    }
    // 根とノードv間の距離を返す．O(1).
    T distance(int v) const {
        assert(0 <= v and v < order());
        return m_dist[v];
    }
    // ノードu, v間の距離を求める．O(log|V|).
    T distance(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        int w = lca(u, v);
        if(w == -1) return infinity();
        return m_dist[u] + m_dist[v] - 2 * m_dist[w];
    }
    // ノードu, v間のパスにおける最大コストを求める．O(log|V|).
    T max_cost(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        int w = lca(u, v);
        if(w == -1) return -infinity();
        T res = -infinity();
        res = std::max(res, max_cost_internal(u, depth(u) - depth(w)));
        res = std::max(res, max_cost_internal(v, depth(v) - depth(w)));
        return res;
    }
    // 木の圧縮．
    // 任意の頂点集合とそのLCAからなる，頂点同士の関係性を維持した木を作成する．O(K*log|V|).
    std::map<int, std::vector<int> > auxiliary_tree(std::vector<int> &vs) const {
        assert(std::find_if(vs.cbegin(), vs.cend(), [&](int v) -> bool { return !(0 <= v and v < order()); }) == vs.cend());
        const int n = vs.size();
        if(n == 0) return std::map<int, std::vector<int> >();
        std::map<int, std::vector<int> > res;  // res[v][]:=(圧縮した木におけるノードvの隣接リスト).
        auto comp = [&](int u, int v) -> bool { return m_ord[u] < m_ord[v]; };
        std::sort(vs.begin(), vs.end(), comp);
        vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
        std::stack<int> st;
        st.push(vs[0]);
        for(int i = 1; i < n; ++i) {
            int w = lca(vs[i - 1], vs[i]);
            if(w == -1) {
                while(st.size() > 1) {
                    int v = st.top();
                    st.pop();
                    res[st.top()].push_back(v);
                    res[v].push_back(st.top());
                }
                res[st.top()];  // for unconnected node.
                st.pop();
            } else if(w != vs[i - 1]) {
                int v = st.top();
                st.pop();
                while(!st.empty() and m_depth[st.top()] > m_depth[w]) {
                    res[st.top()].push_back(v);
                    res[v].push_back(st.top());
                    v = st.top();
                    st.pop();
                }
                if(st.empty() or st.top() != w) {
                    st.push(w);
                    vs.push_back(w);
                }
                res[w].push_back(v);
                res[v].push_back(w);
            }
            st.push(vs[i]);
        }
        while(st.size() > 1) {
            int v = st.top();
            st.pop();
            res[st.top()].push_back(v);
            res[v].push_back(st.top());
        }
        res[st.top()];  // for unconnected node.
        std::sort(vs.begin(), vs.end(), comp);
        return res;
    }
};

}  // namespace algorithm

#endif
