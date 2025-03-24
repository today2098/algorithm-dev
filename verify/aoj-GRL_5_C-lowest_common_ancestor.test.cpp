#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include <iostream>

#include "../lib/Graph/Tree/lowest_common_ancestor.hpp"

int main() {
    int n;
    std::cin >> n;

    algorithm::LCA lca(n);
    for(int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;

        for(int j = 0; j < k; ++j) {
            int c;
            std::cin >> c;

            lca.add_edge(i, c);
        }
    }
    lca.build();

    int q;
    std::cin >> q;

    while(q--) {
        int u, v;
        std::cin >> u >> v;

        auto ans = lca.lca(u, v);
        std::cout << ans << "\n";
    }
}
