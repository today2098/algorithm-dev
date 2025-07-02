#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include <iostream>

#include "../algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::lazy_segment_tree::range_sum_range_add_lazy_segment_tree<long long> segtree(n, {0, 1});

    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            long long x;
            std::cin >> s >> t >> x;
            --s;

            segtree.apply(s, t, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            --s;

            auto &&ans = segtree.prod(s, t).val;
            std::cout << ans << "\n";
        }
    }
}
