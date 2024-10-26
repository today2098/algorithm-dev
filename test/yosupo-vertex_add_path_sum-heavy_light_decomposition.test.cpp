#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

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
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;

        hld.add_edge(u, v);
    }
    hld.build();

    algorithm::BIT0<long long> bitree(n);
    for(int i = 0; i < n; ++i) bitree.add(hld.vid(i), a[i]);

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            int x;
            std::cin >> p >> x;

            auto k = hld.vid(p);
            bitree.add(k, x);
        } else {
            int u, v;
            std::cin >> u >> v;

            long long ans = 0;
            auto &&ranges = hld.vertex_query_ranges(u, v);
            for(const auto &[l, r] : ranges) ans += bitree.sum(l, r);

            std::cout << ans << "\n";
        }
    }
}
