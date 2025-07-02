#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include <iostream>

#include "../algorithm/Graph/Flow/primal_dual.hpp"

int main() {
    int n, m;
    int f;
    std::cin >> n >> m >> f;

    algorithm::PrimalDual<int, int> primal_dual(n, m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        int c;
        int d;
        std::cin >> u >> v >> c >> d;

        primal_dual.add_edge(u, v, c, d);
    }

    auto &&[flow, cost] = primal_dual.min_cost_flow(0, n - 1, f);
    if(flow < f) std::cout << -1 << std::endl;
    else std::cout << cost << std::endl;
}
