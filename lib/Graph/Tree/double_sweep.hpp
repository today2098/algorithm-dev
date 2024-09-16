#ifndef ALGORITHM_DOUBLE_SWEEP_HPP
#define ALGORITHM_DOUBLE_SWEEP_HPP 1

/**
 * @brief Double Sweep（木の直径）
 * @docs docs/Graph/Tree/double_sweep.md
 */

#include <algorithm>
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

namespace algorithm {

// 木の直径を求める．返り値は直径とその経路．O(|V|).
std::pair<int, std::vector<int> > double_sweep(const std::vector<std::vector<int> > &g, int s = 0) {
    const int vn = g.size();
    assert(0 <= s and s < vn);
    int furthest_node;
    std::vector<int> d(vn);
    std::vector<int> pre(vn);
    std::queue<int> que;
    auto bfs = [&](int s) -> void {
        std::fill(pre.begin(), pre.end(), -1);
        d[s] = 0, pre[s] = -2;
        que.push(s);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            furthest_node = u;
            for(int v : g[u]) {
                assert(0 <= v and v < vn);
                if(pre[v] != -1) continue;
                d[v] = d[u] + 1, pre[v] = u;
                que.push(v);
            }
        }
    };
    bfs(s);
    bfs(furthest_node);
    std::vector<int> path({furthest_node});
    path.reserve(d[furthest_node] + 1);
    for(int v = furthest_node; pre[v] != -2; v = pre[v]) path.push_back(pre[v]);
    return {d[furthest_node], path};  // pair of (diameter, path).
}

// 重み付き木の直径を求める．返り値は直径とその経路．O(|V|).
template <typename Type>
std::pair<Type, std::vector<int> > double_sweep(const std::vector<std::vector<std::pair<int, Type> > > &g, int s = 0) {
    const int vn = g.size();
    assert(0 <= s and s < vn);
    int furthest_node;
    std::vector<Type> d(vn);
    std::vector<int> pre(vn);
    std::queue<int> que;
    auto bfs = [&](int s) -> void {
        furthest_node = s;
        std::fill(pre.begin(), pre.end(), -1);
        d[s] = 0, pre[s] = -2;
        que.push(s);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            if(d[u] > d[furthest_node]) furthest_node = u;
            for(const auto &[v, cost] : g[u]) {
                assert(0 <= v and v < vn);
                if(pre[v] != -1) continue;
                d[v] = d[u] + cost, pre[v] = u;
                que.push(v);
            }
        }
    };
    bfs(s);
    bfs(furthest_node);
    std::vector<int> path({furthest_node});
    for(int v = furthest_node; pre[v] != -2; v = pre[v]) path.push_back(pre[v]);
    return {d[furthest_node], path};  // pair of (diameter, path).
}

}  // namespace algorithm

#endif
