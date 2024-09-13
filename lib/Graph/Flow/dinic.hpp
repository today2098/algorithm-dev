#ifndef ALGORITHM_DINIC_HPP
#define ALGORITHM_DINIC_HPP 1

/**
 * @brief Dinic's Algorithm（最大流問題）
 * @docs docs/Graph/Flow/dinic.md
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

template <typename T>  // T:容量の型.
class Dinic {
    struct Edge {
        int to;   // to:=(行き先ノード).
        T cap;    // cap:=(容量).
        int rev;  // rev:=(逆辺イテレータ).
        explicit Edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), rev(rev_) {}
    };

    std::vector<std::vector<Edge> > m_g;      // m_g[v][]:=(ノードvの隣接リスト).
    std::vector<std::pair<int, int> > m_pos;  // m_pos[i]:=(i番目の辺情報). pair of (from, index).

    T dfs(int v, int t, T flow, const std::vector<int> &d, std::vector<int> &iter) {
        if(v == t) return flow;
        for(int &i = iter[v], n = m_g[v].size(); i < n; ++i) {
            Edge &e = m_g[v][i];
            if(e.cap > 0 and d[e.to] > d[v]) {
                T &&res = dfs(e.to, t, std::min(flow, e.cap), d, iter);
                if(res > 0) {
                    e.cap -= res;
                    m_g[e.to][e.rev].cap += res;
                    return res;
                }
            }
        }
        return 0;
    }

public:
    Dinic() : Dinic(0) {}
    explicit Dinic(size_t vn) : m_g(vn) {}

    static constexpr T infinity() { return std::numeric_limits<T>::max(); }
    // ノード数を返す．
    int order() const { return m_g.size(); }
    // 辺数を返す.
    int size() const { return m_pos.size(); }
    // 容量capの有向辺を追加する．
    int add_edge(int from, int to, T cap) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        assert(cap >= 0);
        int idx_from = m_g[from].size(), idx_to = m_g[to].size();
        if(from == to) idx_to++;
        m_g[from].emplace_back(to, cap, idx_to);
        m_g[to].emplace_back(from, 0, idx_from);
        m_pos.emplace_back(from, idx_from);
        return size() - 1;
    }
    // ノードsからtへの最大流を求める．O((|V|^2)*|E|).
    T max_flow(int s, int t) { return max_flow(s, t, infinity()); }
    T max_flow(int s, int t, T flow) {
        assert(0 <= s and s < order());
        assert(0 <= t and t < order());
        T res = 0;
        std::vector<int> d(order());     // d[v]:=(ノードs-v間の増加パスの長さ).
        std::vector<int> iter(order());  // iter[v]:=(m_g[v][]の次に調べるべきイテレータ).
        while(res < flow) {
            // (1) BFS: ノードsと各ノード間の増加パスの長さを求める．
            std::fill(d.begin(), d.end(), -1);
            d[s] = 0;
            std::queue<int> que;
            que.push(s);
            while(!que.empty()) {
                int v = que.front();
                que.pop();
                for(const Edge &e : m_g[v]) {
                    if(e.cap > 0 and d[e.to] == -1) {
                        d[e.to] = d[v] + 1;
                        que.push(e.to);
                    }
                }
            }
            if(d[t] == -1) break;
            // (2) DFS: 増加パスを探す．
            std::fill(iter.begin(), iter.end(), 0);
            while(res < flow) {
                T &&tmp = dfs(s, t, flow - res, d, iter);
                if(tmp == 0) break;
                res += tmp;
            }
        }
        return res;
    }
    // i番目の辺情報を返す．
    std::tuple<int, int, T, T> get_edge(int i) const {
        assert(0 <= i and i < size());
        const auto &[from, idx] = m_pos[i];
        const Edge &e = m_g[from][idx];
        return {from, e.to, e.cap + m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};  // tuple of (from, to, cap, flow).
    }
    // 最小カットにより，グラフ上のノードを分割する．
    std::vector<bool> min_cut(int s) const {
        assert(0 <= s and s < order());
        std::vector<bool> res(order(), false);
        std::queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            if(res[v]) continue;
            res[v] = true;
            for(const Edge &e : m_g[v]) {
                if(e.cap > 0 and !res[e.to]) que.push(e.to);
            }
        }
        return res;
    }
    void reset() {
        for(const auto &[from, idx] : m_pos) {
            Edge &e = m_g[from][idx];
            e.cap = e.cap + m_g[e.to][e.rev].cap;
            m_g[e.to][e.rev].cap = 0;
        }
    }
};

}  // namespace algorithm

#endif
