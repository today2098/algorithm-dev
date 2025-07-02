#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include <iostream>

#include "../algorithm/Graph/Flow/dinic.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::Dinic<int> dinic(n, m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        int c;
        std::cin >> u >> v >> c;

        dinic.add_edge(u, v, c);
    }

    auto &&ans = dinic.max_flow(0, n - 1);
    std::cout << ans << std::endl;
}
