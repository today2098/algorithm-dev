#ifndef ALGORITHM_BELLMAN_FORD_HPP
#define ALGORITHM_BELLMAN_FORD_HPP 1

/**
 * @brief Bellman-Ford Algorithm（単一始点最短経路）
 * @docs docs/Graph/ShortestPath/bellman_ford.md
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithm {

template <typename T>
class BellmanFord {
    struct Edge {
        int from, to;
        T cost;
        explicit Edge(int from_, int to_, T cost_) : from(from_), to(to_), cost(cost_) {}
    };

    int m_vn;                   // m_vn:=(ノード数).
    std::vector<Edge> m_edges;  // m_edges[]:=(辺リスト).
    std::vector<T> m_d;         // m_d[t]:=(ノードsからtへの最短距離).
    std::vector<int> m_pre;     // m_pre[t]:=(ノードtを訪問する直前のノード番号). 逆方向経路．

public:
    BellmanFord() : BellmanFord(0) {}
    explicit BellmanFord(size_t vn) : m_vn(vn), m_d(vn, infinity()), m_pre(vn, -1) {}
    explicit BellmanFord(size_t vn, size_t en) : BellmanFord(vn) {
        m_edges.reserve(en);
    }

    static constexpr T infinity() { return std::numeric_limits<T>::max(); }
    // ノード数を返す．
    int order() const { return m_vn; }
    // 辺数を返す．
    int size() const { return m_edges.size(); }
    // 重み付き有向辺を張る．
    void add_edge(int from, int to, T cost) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_edges.emplace_back(from, to, cost);
    }
    // グラフ全体から負閉路を検出する．O(|V|*|E|).
    bool find_negative_cycle() const {
        std::vector<T> nd(order(), 0);
        for(int i = 0; i < order(); ++i) {
            bool update = false;
            for(const auto &[from, to, cost] : m_edges) {
                if(nd[to] > nd[from] + cost) {
                    nd[to] = nd[from] + cost;
                    update = true;
                }
            }
            if(!update) return false;  // 負閉路なし．
        }
        return true;  // 負閉路あり．
    }
    // ノードsから各ノードへの最短距離を求める．O(|V|*|E|).
    bool bellman_ford(int s) {
        assert(0 <= s and s < order());
        std::fill(m_d.begin(), m_d.end(), infinity());
        std::fill(m_pre.begin(), m_pre.end(), -1);
        m_d[s] = 0;
        for(int i = 0; i < order(); ++i) {
            bool update = false;
            for(const auto &[from, to, cost] : m_edges) {
                if(m_d[from] == infinity()) continue;
                if(m_d[to] > m_d[from] + cost) {
                    m_d[to] = m_d[from] + cost;
                    m_pre[to] = from;
                    update = true;
                }
            }
            if(!update) return false;  // 負閉路なし．
        }
        for(int i = 0; i < order(); ++i) {
            bool update = false;
            for(const auto &[from, to, cost] : m_edges) {
                if(m_d[from] == infinity() or m_d[to] == -infinity()) continue;
                if(m_d[from] == -infinity() or m_d[to] > m_d[from] + cost) {
                    m_d[to] = -infinity();
                    update = true;
                }
            }
            if(!update) break;
        }
        return true;  // 負閉路あり．
    }
    // ノードsからtへの最短距離を返す．
    T distance(int t) const {
        assert(0 <= t and t < order());
        return m_d[t];
    }
    // ノードsからtへの最短経路を復元する．
    std::vector<int> shortest_path(int t) const {
        assert(0 <= t and t < order());
        std::vector<int> path;
        if(distance(t) == infinity() or distance(t) == -infinity()) return path;
        for(; t != -1; t = m_pre[t]) path.push_back(t);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

}  // namespace algorithm

#endif
