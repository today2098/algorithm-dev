#ifndef ALGORITHM_PRIMAL_DUAL_HPP
#define ALGORITHM_PRIMAL_DUAL_HPP 1

/**
 * @brief 最小費用流問題
 * @docs docs/Graph/Flow/primal_dual.md
 */

#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

template <typename Flow, typename Cost>  // Flow:容量の型, Cost:コストの型.
class PrimalDual {
    struct Edge {
        int to;     // to:=(行き先ノード).
        Flow cap;   // cap:=(容量).
        Cost cost;  // cost:=(単位コスト).
        int rev;    // rev:=(逆辺イテレータ).
        explicit Edge(int to_, Flow cap_, Cost cost_, int rev_) : to(to_), cap(cap_), cost(cost_), rev(rev_) {}
    };

    std::vector<std::vector<Edge> > m_g;      // m_g[v][]:=(ノードvの隣接リスト).
    std::vector<std::pair<int, int> > m_pos;  // m_pos[i]:=(i番目の辺情報). pair of (from, index).

    static constexpr Cost infinity_cost() { return std::numeric_limits<Cost>::max(); }
    void dijkstra(int s, const std::vector<Cost> &h, std::vector<Cost> &d, std::vector<int> &prev_v, std::vector<int> &prev_e,
                  std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int> >, std::greater<std::pair<Cost, int> > > &pque) {
        std::fill(d.begin(), d.end(), infinity_cost());
        d[s] = 0;
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [dist, v] = pque.top();
            pque.pop();
            if(d[v] < dist) continue;
            for(int i = 0, n = m_g[v].size(); i < n; ++i) {
                const Edge &e = m_g[v][i];
                Cost new_cost = e.cost + h[v] - h[e.to];
                if(e.cap > 0 and d[e.to] > d[v] + new_cost) {
                    d[e.to] = d[v] + new_cost;
                    prev_v[e.to] = v;
                    prev_e[e.to] = i;
                    pque.emplace(d[e.to], e.to);
                }
            }
        }
    }

public:
    PrimalDual() : PrimalDual(0) {}
    explicit PrimalDual(size_t vn) : m_g(vn) {}
    explicit PrimalDual(size_t vn, size_t en) : PrimalDual(vn) {
        m_pos.reserve(en);
    }

    static constexpr Flow infinity_flow() { return std::numeric_limits<Flow>::max(); }
    // ノード数を返す．
    int order() const { return m_g.size(); }
    // 辺数を返す.
    int size() const { return m_pos.size(); }
    // 容量cap[flows]，単位コストcost[cost/flow]の有向辺を追加する．
    int add_edge(int from, int to, Flow cap, Cost cost) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        assert(cap >= 0);
        assert(cost >= 0);
        int idx_from = m_g[from].size(), idx_to = m_g[to].size();
        if(from == to) idx_to++;
        m_g[from].emplace_back(to, cap, cost, idx_to);
        m_g[to].emplace_back(from, 0, -cost, idx_from);
        m_pos.emplace_back(from, idx_from);
        return size() - 1;
    }
    // ソースからシンクまでの最小費用[costs]（単位コスト[cost/flow]とフロー[flows]の積の総和）を求める．
    // 返り値は流量[flows]と最小費用[costs]．O(F*|E|*log|V|).
    std::pair<Flow, Cost> min_cost_flow(int s, int t) { return slope(s, t, infinity_flow()).back(); }
    std::pair<Flow, Cost> min_cost_flow(int s, int t, Flow flow) { return slope(s, t, flow).back(); }
    std::vector<std::pair<Flow, Cost> > slope(int s, int t) { return slope(s, t, infinity_flow()); }
    std::vector<std::pair<Flow, Cost> > slope(int s, int t, Flow flow) {
        assert(0 <= s and s < order());
        assert(0 <= t and t < order());
        Flow rest = flow;                                   // rest:=(残流量).
        Cost sum = 0;                                       // sum:=(合計費用).
        Cost prev_cost = -1;                                // prev_cost:=(直前のフローにおける単位コスト[cost/flow]).
        std::vector<std::pair<Flow, Cost> > res({{0, 0}});  // res[]:=(流量とコストの関係の折れ線). 値は狭義単調増加．
        std::vector<Cost> d(order());                       // d[v]:=(ノートsからvまでの最小単位コスト).
        std::vector<Cost> h(order(), 0);                    // h[v]:=(ノードvのポテンシャル).
        std::vector<int> prev_v(order());                   // prev_v[v]:=(ノードvの直前に訪れるノード). 逆方向経路．
        std::vector<int> prev_e(order());                   // prev_e[v]:=(ノードvの直前に通る辺). 逆方向経路．
        std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int> >, std::greater<std::pair<Cost, int> > > pque;
        while(rest > 0) {
            dijkstra(s, h, d, prev_v, prev_e, pque);
            if(d[t] == infinity_cost()) break;  // これ以上流せない場合．
            for(int v = 0, n = order(); v < n; ++v) h[v] += d[v];
            Flow tmp = rest;
            for(int v = t; v != s; v = prev_v[v]) tmp = std::min(tmp, m_g[prev_v[v]][prev_e[v]].cap);
            rest -= tmp;
            sum += h[t] * tmp;
            if(h[t] == prev_cost) res.pop_back();
            res.emplace_back(flow - rest, sum);
            for(int v = t; v != s; v = prev_v[v]) {
                Edge &e = m_g[prev_v[v]][prev_e[v]];
                e.cap -= tmp;
                m_g[v][e.rev].cap += tmp;
            }
            prev_cost = h[t];
        }
        return res;
    }
    // i番目の辺情報を返す．
    std::tuple<int, int, Flow, Cost, Flow> get_edge(int i) const {
        assert(0 <= i and i < size());
        const auto &[from, idx] = m_pos[i];
        const Edge &e = m_g[from][idx];
        return {from, e.to, e.cap + m_g[e.to][e.rev].cap, e.cost, m_g[e.to][e.rev].cap};  // tuple of (from, to, cap, cost, flow).
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
