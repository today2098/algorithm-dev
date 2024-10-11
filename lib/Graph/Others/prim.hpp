#ifndef ALGORITHM_PRIM_HPP
#define ALGORITHM_PRIM_HPP 1

/**
 * @brief Prim's Algorithm（最小全域木）
 * @docs docs/Graph/Others/prim.md
 */

#include <cassert>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

namespace algorithm {

template <typename T>
class Prim {
    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(ノードvの隣接リスト). pair of (to, cost).

public:
    Prim() : Prim(0) {}
    explicit Prim(size_t vn) : m_g(vn) {}

    // ノード数を返す．
    int order() const { return m_g.size(); }
    // 重み付き無向辺を張る．
    void add_edge(int u, int v, T cost) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].emplace_back(v, cost);
        m_g[v].emplace_back(u, cost);
    }
    // 重み付き無向連結グラフにおける最小全域木のコストを求める．O(|E|*log|V|).
    T prim(int rt = 0) {
        assert(0 <= rt and rt < order());
        T res = 0;
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int> >, std::greater<std::pair<T, int> > > pque;
        pque.emplace(0, rt);
        std::vector<bool> seen(order(), false);
        while(!pque.empty()) {
            auto [cost, u] = pque.top();
            pque.pop();
            if(seen[u]) continue;
            seen[u] = true;
            res += cost;
            for(const auto &[v, cost] : m_g[u]) {
                if(!seen[v]) pque.emplace(cost, v);
            }
        }
        return res;
    }
};

}  // namespace algorithm

#endif
