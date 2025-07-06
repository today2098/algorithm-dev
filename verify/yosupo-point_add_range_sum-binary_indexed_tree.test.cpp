#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <utility>
#include <vector>

#include "../algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using binary_indexed_tree_type = typename algorithm::binary_indexed_tree::range_sum_binary_indexed_tree<long long>;
    using group_type = typename binary_indexed_tree_type::group_type;

    std::vector<group_type> a(n);
    for(auto &elem : a) std::cin >> elem;

    binary_indexed_tree_type bit(std::move(a));

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;

            bit.add(p, x);
        } else {
            int l, r;
            std::cin >> l >> r;

            auto &&ans = bit.sum(l, r);
            std::cout << ans << "\n";
        }
    }
}
