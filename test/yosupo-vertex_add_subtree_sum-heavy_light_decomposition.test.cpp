#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <utility>
#include <vector>

#include "../lib/DataStructure/SegmentTree/binary_indexed_tree.hpp"
#include "../lib/Graph/Tree/heavy_light_decomposition.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &elem : a) std::cin >> elem;

    algorithm::HLD hld(n);
    for(int i = 1; i < n; ++i) {
        int p;
        std::cin >> p;

        hld.add_edge(p, i);
    }
    hld.build();

    std::vector<long long> b(n);
    for(int i = 0; i < n; ++i) b[hld.vertex_index()[i]] = a[i];
    algorithm::BIT bit(std::move(b));

    while(q--) {
        int t;
        int u;
        std::cin >> t >> u;

        if(t == 0) {
            int x;
            std::cin >> x;

            bit.add(hld.vertex_index(u), x);
        } else {
            auto &&[l, r] = hld.vertex_query_range_of_subtree(u);
            auto &&ans = bit.sum(l, r);
            std::cout << ans << "\n";
        }
    }
}
