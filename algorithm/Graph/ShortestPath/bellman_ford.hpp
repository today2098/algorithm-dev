#ifndef ALGORITHM_BELLMAN_FORD_HPP
#define ALGORITHM_BELLMAN_FORD_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <tuple>
#include <type_traits>
#include <vector>

namespace algorithm {

namespace bellman_ford {

template <typename T, auto inf>
class BellmanFord {
    static_assert(std::is_invocable_r<T, decltype(inf)>::value);

public:
    using value_type = T;
    using weighted_edge_type = std::tuple<int, int, value_type>;  // tuple of (from, to, weight).

private:
    int m_vn;                                 // m_vn:=(ノード数).
    std::vector<weighted_edge_type> m_edges;  // m_edges[]:=(辺リスト).
    std::vector<value_type> m_d;              // m_d[t]:=(ノードsからtへの最短距離).
    std::vector<int> m_pre;                   // m_pre[t]:=(ノードtを訪問する直前のノード番号). 逆方向経路．

public:
    BellmanFord() : BellmanFord(0) {}
    explicit BellmanFord(int vn) : m_vn(vn), m_d(vn, inf()), m_pre(vn, -1) {
        assert(vn >= 0);
    }
    explicit BellmanFord(int vn, int en) : BellmanFord(vn) {
        assert(en >= 0);
        m_edges.reserve(en);
    }

    static constexpr value_type infinity() { return inf(); }
    // ノード数を返す．
    int order() const { return m_vn; }
    // 辺数を返す．
    int size() const { return m_edges.size(); }
    // 重み付き有向辺を張る．
    void add_edge(int from, int to, value_type weight) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_edges.emplace_back(from, to, weight);
    }
    // グラフ全体から負閉路を検出する．O(|V||E|).
    bool find_negative_cycle() const {
        std::vector<value_type> nd(m_vn, 0);
        for(int i = 0; i < m_vn; ++i) {
            bool update = false;
            for(const auto &[from, to, weight] : m_edges) {
                if(nd[to] > nd[from] + weight) {
                    nd[to] = nd[from] + weight;
                    update = true;
                }
            }
            if(!update) return false;  // 負閉路なし．
        }
        return true;  // 負閉路あり．
    }
    // ノードsから各ノードへの最短距離を求める．O(|V||E|).
    bool bellman_ford(int s) {
        assert(0 <= s and s < order());
        std::fill(m_d.begin(), m_d.end(), inf());
        m_d[s] = 0;
        std::fill(m_pre.begin(), m_pre.end(), -1);
        for(int i = 0; i < m_vn; ++i) {
            bool update = false;
            for(const auto &[from, to, weight] : m_edges) {
                if(m_d[from] == inf()) continue;
                if(m_d[to] > m_d[from] + weight) {
                    m_d[to] = m_d[from] + weight;
                    m_pre[to] = from;
                    update = true;
                }
            }
            if(!update) return false;  // 負閉路なし．
        }
        for(int i = 0; i < m_vn; ++i) {
            bool update = false;
            for(const auto &[from, to, weight] : m_edges) {
                if(m_d[from] == inf() or m_d[to] == -inf()) continue;
                if(m_d[from] == -inf() or m_d[to] > m_d[from] + weight) {
                    m_d[to] = -inf();
                    update = true;
                }
            }
            if(!update) break;
        }
        return true;  // 負閉路あり．
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
        if(distance(t) == -inf() or distance(t) == inf()) return path;
        for(; t != -1; t = m_pre[t]) path.push_back(t);
        path.shrink_to_fit();
        std::reverse(path.begin(), path.end());
        return path;
    }
};

template <typename T>
using default_bellman_ford = BellmanFord<T, std::numeric_limits<T>::max>;

}  // namespace bellman_ford

}  // namespace algorithm

#endif
