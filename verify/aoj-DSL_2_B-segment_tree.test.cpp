#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <iostream>

#include "../lib/DataStructure/SegmentTree/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using Type = int;
    auto &&segtree = algorithm::segmenttree::range_sum_query<Type>(n);
    while(q--) {
        int com;
        std::cin >> com;

        if(com == 0) {
            int x;
            Type y;
            std::cin >> x >> y;
            --x;

            auto &&now = segtree.prod(x);
            segtree.set(x, now + y);
        } else {
            int x, y;
            std::cin >> x >> y;
            --x;

            auto &&ans = segtree.prod(x, y);
            std::cout << ans << "\n";
        }
    }
}
