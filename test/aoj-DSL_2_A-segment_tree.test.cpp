#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <algorithm>
#include <iostream>

#include "../lib/DataStructure/SegmentTree/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = long long;
    constexpr S e = (1LL << 31) - 1;
    auto op = [](const S &lhs, const S &rhs) -> S { return std::min(lhs, rhs); };
    algorithm::SegmentTree<S> segtree(op, e, n);

    while(q--) {
        int com;
        std::cin >> com;

        if(com == 0) {
            int x;
            S y;
            std::cin >> x >> y;

            segtree.set(x, y);
        } else {
            int x, y;
            std::cin >> x >> y;
            y++;

            auto &&ans = segtree.prod(x, y);
            std::cout << ans << "\n";
        }
    }
}
