#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    for(auto &in : a) std::cin >> in;

    using S = long long;
    constexpr S e = 0;
    auto op = [](const S &lhs, const S &rhs) -> S { return lhs + rhs; };
    algorithm::SegmentTree<S> segtree(op, e, a);

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
