#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include <iostream>

#include "../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using Type = int;
    auto &&segtree = algorithm::lazysegmenttree::range_minimum_query_and_range_add_query<Type>(n);
    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            Type x;
            std::cin >> s >> t >> x;
            ++t;

            segtree.apply(s, t, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            ++t;

            auto &&ans = segtree.prod(s, t);
            std::cout << ans << "\n";
        }
    }
}
