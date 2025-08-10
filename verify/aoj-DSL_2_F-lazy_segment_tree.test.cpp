#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include <iostream>

#include "../algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::RangeMinimumRangeUpdateLazySegmentTree<unsigned> segtree(n, (1U << 31) - 1);

    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            unsigned x;
            std::cin >> s >> t >> x;
            ++t;

            segtree.apply(s, t, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            ++t;

            auto ans = segtree.prod(s, t);
            std::cout << ans << "\n";
        }
    }
}
