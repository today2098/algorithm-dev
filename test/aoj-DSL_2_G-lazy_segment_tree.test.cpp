#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = struct {
        long long val;
        int size;
    };
    using F = long long;
    constexpr S e = (S){0, 0};
    constexpr F id = 0;
    auto op = [&](const S &lhs, const S &rhs) -> S { return (S){lhs.val + rhs.val, lhs.size + rhs.size}; };
    auto mapping = [&](const F &f, const S &x) -> S { return (S){x.val + f * x.size, x.size}; };
    auto composition = [&](const F &f, const F &g) -> F { return f + g; };
    algorithm::LazySegTree<S, F> segtree(op, mapping, composition, e, id, std::vector<S>(n, (S){0, 1}));

    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            long long x;
            std::cin >> s >> t >> x;
            s--;

            segtree.apply(s, t, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            s--;

            auto &&ans = segtree.prod(s, t).val;
            std::cout << ans << "\n";
        }
    }
}
