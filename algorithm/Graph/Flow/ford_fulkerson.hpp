#ifndef ALGORITHM_FORD_FULKERSON_HPP
#define ALGORITHM_FORD_FULKERSON_HPP 1

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

template <typename Flow>
class FordFulkerson {
public:
    using flow_type = Flow;

private:
    struct Edge {
        int to;         // to:=(行き先ノード).
        flow_type cap;  // cap:=(容量).
        int rev;        // rev:=(逆辺の位置). m_g[to][rev]が逆辺となる．

        explicit Edge(int to, flow_type cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    int m_vn;                                // m_vn:=(ノード数).
    std::vector<std::vector<Edge>> m_g;      // m_g[v][]:=(ノードvの隣接リスト).
    std::vector<std::pair<int, int>> m_pos;  // m_pos[]:=(i番目の辺の情報). pair of (from, index).

public:
    FordFulkerson() : FordFulkerson(0) {}
    explicit FordFulkerson(int n) : m_vn(n), m_g(n) {
        assert(n >= 0);
    }
    explicit FordFulkerson(int vn, int en) : FordFulkerson(vn) {
        assert(en >= 0);
        m_pos.reserve(en);
    }

    static constexpr flow_type infinity() { return std::numeric_limits<flow_type>::max(); }
    // ノード数を取得する．
    int order() const { return m_vn; }
    // 辺数を取得する．
    int size() const { return m_pos.size(); }
    // 容量capの有向辺を追加する．
    int add_edge(int from, int to, flow_type cap) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        assert(cap >= 0);
        int i = m_g[from].size(), j = m_g[to].size();
        if(from == to) ++j;
        m_g[from].emplace_back(to, cap, j);
        m_g[to].emplace_back(from, 0, i);
        m_pos.emplace_back(from, i);
        return size() - 1;
    }
    // ノードsからtへの最大流を求める．O(f*|E|).
    flow_type max_flow(int s, int t) { return max_flow(s, t, infinity()); }
    flow_type max_flow(int s, int t, flow_type flow) {
        assert(0 <= s and s < order());
        assert(0 <= t and t < order());
        flow_type res = 0;
        while(res < flow) {
            std::vector<bool> seen(m_vn, false);
            auto dfs = [&](auto self, int v, flow_type flow) -> flow_type {
                if(v == t) return flow;
                seen[v] = true;
                for(Edge &e : m_g[v]) {
                    if(seen[e.to] or e.cap == 0) continue;
                    flow_type res = self(self, e.to, std::min(flow, e.cap));
                    if(res == 0) continue;
                    e.cap -= res;
                    m_g[e.to][e.rev].cap += res;
                    return res;
                }
                return 0;
            };
            flow_type tmp = dfs(dfs, s, flow - res);
            if(tmp == 0) break;
            res += tmp;
        }
        return res;
    }
    // i番目の辺の情報を取得する．
    std::tuple<int, int, flow_type, flow_type> get_edge(int i) const {
        assert(0 <= i and i < size());
        const auto &[from, idx] = m_pos[i];
        const Edge &e = m_g[from][idx];
        return {from, e.to, e.cap + m_g[e.to][e.rev].cap, m_g[e.to][e.rev].cap};  // tuple of (from, to, capacity, flow).
    }
    // 最小カットにより，グラフ上のノードを分割する．
    std::vector<bool> min_cut(int s) const {
        assert(0 <= s and s < order());
        std::vector<bool> res(m_vn, false);
        std::queue<int> que({s});
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            if(res[v]) continue;
            res[v] = true;
            for(const Edge &e : m_g[v]) {
                if(!res[e.to] and e.cap > 0) que.push(e.to);
            }
        }
        return res;
    }
    void reset() {
        for(const auto &[from, idx] : m_pos) {
            Edge &e = m_g[from][idx];
            e.cap += m_g[e.to][e.rev].cap;
            m_g[e.to][e.rev].cap = 0;
        }
    }
};

}  // namespace algorithm

#endif
