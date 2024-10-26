#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp"
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
    hld.build(0);

    algorithm::BIT0<long long> bit(n);
    for(int i = 0; i < n; ++i) bit.add(hld.vid(i), a[i]);

    while(q--) {
        int t;
        int u;
        std::cin >> t >> u;

        if(t == 0) {
            int x;
            std::cin >> x;

            auto k = hld.vid(u);
            bit.add(k, x);
        } else {
            auto &&[l, r] = hld.subtree_vertex_query_range(u);
            long long ans = bit.sum(l, r);
            std::cout << ans << "\n";
        }
    }
}
