#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <iostream>

#include "../lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::dynamic_segment_tree::range_minimum_dynamic_segment_tree<int> segtree(n);

    while(q--) {
        int com;
        std::cin >> com;

        if(com == 0) {
            int x;
            int y;
            std::cin >> x >> y;

            segtree.set(x, y);
        } else {
            int x, y;
            std::cin >> x >> y;
            ++y;

            auto &&ans = segtree.prod(x, y);
            std::cout << ans << "\n";
        }
    }
}
