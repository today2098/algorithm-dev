#ifndef ALGORITHM_DIJKSTRA_HPP
#define ALGORITHM_DIJKSTRA_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <type_traits>
#include <utility>
#include <vector>

namespace algorithm {

namespace dijkstra {

template <typename T, auto inf>
class Dijkstra {
    static_assert(std::is_invocable_r<T, decltype(inf)>::value);

public:
    using value_type = T;
    using weighted_graph_type = std::vector<std::vector<std::pair<int, value_type>>>;

private:
    int m_vn;                     // m_vn:=(ノード数).
    weighted_graph_type m_g;      // m_g[v][]:=(ノードvの隣接リスト). pair of (to, weight).
    std::vector<value_type> m_d;  // m_d[t]:=(ノードsからtへの最短距離).
    std::vector<int> m_pre;       // m_pre[t]:=(ノードtを訪問する直前のノード番号). 逆方向経路．

public:
    Dijkstra() : Dijkstra(0) {}
    explicit Dijkstra(int vn) : m_vn(vn), m_g(vn), m_d(vn, inf()), m_pre(vn, -1) {
        assert(vn >= 0);
    }

    static constexpr value_type infinity() { return inf(); }
    // ノード数を返す．
    int order() const { return m_vn; }
    // 重み付き有向辺を張る．
    void add_edge(int from, int to, value_type weight) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].emplace_back(to, weight);
    }
    // ノードsから各ノードへの最短距離を求める．O(|E| log |V|).
    void dijkstra(int s) {
        assert(0 <= s and s < order());
        std::fill(m_d.begin(), m_d.end(), inf());
        m_d[s] = 0;
        std::fill(m_pre.begin(), m_pre.end(), -1);
        std::priority_queue<std::pair<value_type, int>, std::vector<std::pair<value_type, int>>, std::greater<std::pair<value_type, int>>> pque;
        pque.emplace(0, s);
        while(!pque.empty()) {
            const auto [dist, v] = pque.top();
            pque.pop();
            if(m_d[v] < dist) continue;
            for(const auto &[to, weight] : m_g[v]) {
                if(m_d[to] > m_d[v] + weight) {
                    m_d[to] = m_d[v] + weight;
                    m_pre[to] = v;
                    pque.emplace(m_d[to], to);
                }
            }
        }
    }
    // ノードsからtへの最短距離を取得する．
    value_type distance(int t) const {
        assert(0 <= t and t < order());
        return m_d[t];
    }
    // ノードsからtへの最短経路を復元する．
    std::vector<int> shortest_path(int t) const {
        assert(0 <= t and t < order());
        std::vector<int> path;
        if(distance(t) == inf()) return path;
        for(; t != -1; t = m_pre[t]) path.push_back(t);
        path.shrink_to_fit();
        std::reverse(path.begin(), path.end());
        return path;
    }
};

template <typename T>
using default_dijkstra = Dijkstra<T, std::numeric_limits<T>::max>;

}  // namespace dijkstra

}  // namespace algorithm

#endif
