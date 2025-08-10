#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#include "../algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::RangeSumDynamicSegmentTree<int> segtree(n);

    while(q--) {
        int com;
        std::cin >> com;

        if(com == 0) {
            int x;
            int y;
            std::cin >> x >> y;
            --x;

            auto now = segtree.prod(x);
            segtree.set(x, now + y);
        } else {
            int x, y;
            std::cin >> x >> y;
            --x;

            auto ans = segtree.prod(x, y);
            std::cout << ans << "\n";
        }
    }
}
