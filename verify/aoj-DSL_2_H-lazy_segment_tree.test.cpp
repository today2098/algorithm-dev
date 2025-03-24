#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = int;
    using F = int;
    constexpr S e = 1e8;
    constexpr F id = 0;
    auto op = [&](const S &lhs, const S &rhs) -> S { return std::min(lhs, rhs); };
    auto mapping = [&](const F &f, const S &x) -> S { return x + f; };
    auto composition = [&](const F &f, const F &g) -> F { return f + g; };
    algorithm::LazySegTree<S, F> segtree(op, mapping, composition, e, id, std::vector<S>(n, 0));

    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            int x;
            std::cin >> s >> t >> x;
            t++;

            segtree.apply(s, t, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            t++;

            auto &&ans = segtree.prod(s, t);
            std::cout << ans << "\n";
        }
    }
}
