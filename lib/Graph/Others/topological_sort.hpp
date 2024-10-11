#ifndef ALGORITHM_TOPOLOGICAL_SORT_HPP
#define ALGORITHM_TOPOLOGICAL_SORT_HPP 1

/**
 * @brief Topological Sort（トポロジカルソート）
 * @docs docs/Graph/Others/topological_sort.md
 */

#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

class TopologicalSort {
    int m_vn;                            // m_vn:=(ノード数).
    std::vector<std::vector<int> > m_g;  // m_g[v]:=(ノードvの隣接リスト).

public:
    TopologicalSort() : TopologicalSort(0) {}
    explicit TopologicalSort(size_t vn) : m_vn(vn), m_g(vn) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    // 有向辺を張る．
    void add_edge(int from, int to) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].push_back(to);
    }
    // 有向非巡回グラフに対する任意のトポロジカルソートの解を求める．O(|V|+|E|).
    std::vector<int> topological_sort() const {
        std::vector<int> res;
        res.reserve(order());
        std::vector<int> deg(order(), 0);  // deg[v]:=(ノードvの入次数).
        for(const std::vector<int> &edges : m_g) {
            for(int to : edges) deg[to]++;
        }
        std::queue<int> que;
        for(int i = 0; i < order(); ++i) {
            if(deg[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            res.push_back(u);
            for(int v : m_g[u]) {
                if(--deg[v] == 0) que.push(v);
            }
        }
        if((int)res.size() != order()) return std::vector<int>();  // 閉路がある場合．
        return res;
    }
    // 考え得るトポロジカルソートの解を数え上げる．ノード数の実用上限目安は20程度．O(N*(2^N)).
    template <typename Type = long long>
    Type count_up() const {
        assert(order() <= 30);
        const int n = order();
        std::vector<int> b(n, 0);  // b[v]:=(ノードvの隣接リストにある行き先ノードの集合).
        for(int v = 0; v < n; ++v) {
            for(int to : m_g[v]) b[v] |= 1 << to;
        }
        std::vector<Type> dp(1 << n, 0);  // dp[S]:=(ノード集合Sにおける解の通り数).
        dp[0] = 1;
        for(int bit = 0; bit < 1 << n; ++bit) {
            for(int i = 0; i < n; ++i) {
                if(!(bit >> i & 1) and !(bit & b[i])) dp[bit | 1 << i] += dp[bit];
            }
        }
        return dp[(1 << n) - 1];
    }
};

}  // namespace algorithm

#endif
