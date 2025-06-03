#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#include "../lib/DataStructure/SegmentTree/segment_tree.hpp"
#include "../lib/Math/ModularArithmetic/modint.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using Type = algorithm::mint998244353;
    using S = struct {
        Type a;
        Type b;
    };
    auto mapping = [](const S &f, Type x) -> Type {
        return x * f.a + f.b;
    };

    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b * rhs.a + rhs.b}; };
    constexpr auto e = []() -> S { return {1, 0}; };
    using monoid = algorithm::algebra::Monoid<S, op, e>;
    algorithm::SegmentTree<monoid> segtree(n);

    for(int i = 0; i < n; ++i) {
        Type a, b;
        std::cin >> a >> b;

        segtree.set(i, {a, b});
    }

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            Type c, d;
            std::cin >> p >> c >> d;

            segtree.set(p, {c, d});
        } else {
            int l, r;
            Type x;
            std::cin >> l >> r >> x;

            auto &&f = segtree.prod(l, r);
            auto &&ans = mapping(f, x);
            std::cout << ans << "\n";
        }
    }
}
