#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include <utility>
#include <vector>

#include "../algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp"
#include "../algorithm/Graph/Tree/heavy_light_decomposition.hpp"

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

    using binary_indexed_tree = algorithm::binary_indexed_tree::range_sum_binary_indexed_tree<long long>;
    using group = binary_indexed_tree::group_type;

    std::vector<group> b(n);
    for(int i = 0; i < n; ++i) b[hld.vertex_index()[i]] = a[i];

    binary_indexed_tree bit(std::move(b));

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            int x;
            std::cin >> p >> x;

            bit.add(hld.vertex_index(p), x);
        } else {
            int u, v;
            std::cin >> u >> v;

            long long ans = 0;
            auto &&ranges = hld.vertex_query_ranges(u, v);
            for(const auto &[l, r] : ranges) ans += bit.sum(l, r);

            std::cout << ans << "\n";
        }
    }
}
