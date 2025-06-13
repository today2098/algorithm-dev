#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <utility>
#include <vector>

#include "../lib/DataStructure/SegmentTree/binary_indexed_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using binary_indexed_tree = algorithm::binary_indexed_tree::range_sum_binary_indexed_tree<long long>;
    using group = binary_indexed_tree::group_type;

    std::vector<group> a(n);
    for(auto &elem : a) std::cin >> elem;

    binary_indexed_tree bit(std::move(a));

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
