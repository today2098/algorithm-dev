#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include <iostream>

#include "../lib/Graph/ShortestPath/bellman_ford.hpp"

int main() {
    int n, m;
    int r;
    std::cin >> n >> m >> r;

    algorithm::bellman_ford::default_bellman_ford<int> bellman_ford(n, m);
    for(int i = 0; i < m; ++i) {
        int s, t;
        int d;
        std::cin >> s >> t >> d;

        bellman_ford.add_edge(s, t, d);
    }

    auto res = bellman_ford.bellman_ford(r);
    if(res) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return 0;
    }

    for(int i = 0; i < n; ++i) {
        auto ans = bellman_ford.distance(i);
        if(ans == bellman_ford.infinity()) std::cout << "INF" << "\n";
        else std::cout << ans << "\n";
    }
}
