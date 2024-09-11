#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    for(auto &in : a) std::cin >> in;

    algorithm::BIT0 bit(a);
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
