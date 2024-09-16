#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

#include <iostream>
#include <utility>
#include <vector>

#include "../lib/Graph/Tree/double_sweep.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int> > > g(n);
    for(int i = 0; i < n - 1; ++i) {
        int s, t;
        int w;
        std::cin >> s >> t >> w;

        g[s].emplace_back(t, w);
        g[t].emplace_back(s, w);
    }

    auto &&[ans, path] = algorithm::double_sweep(g);
    std::cout << ans << std::endl;
}
