#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>

#include "../algorithm/DataStructure/SegmentTree/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    for(auto &elem : a) std::cin >> elem;

    algorithm::segment_tree::range_sum_segment_tree<long long> segtree(a.cbegin(), a.cend());

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;

            auto &&now = segtree.prod(p);
            segtree.set(p, now + x);
        } else {
            int l, r;
            std::cin >> l >> r;

            auto &&ans = segtree.prod(l, r);
            std::cout << ans << "\n";
        }
    }
}
