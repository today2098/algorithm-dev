#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include <iostream>

#include "../lib/Graph/Flow/ford_fulkerson.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::FordFulkerson<int> ford_fulkerson(n, m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        int c;
        std::cin >> u >> v >> c;

        ford_fulkerson.add_edge(u, v, c);
    }

    auto &&ans = ford_fulkerson.max_flow(0, n - 1);
    std::cout << ans << std::endl;
}
