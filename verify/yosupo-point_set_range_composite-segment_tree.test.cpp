#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#include "../algorithm/DataStructure/SegmentTree/segment_tree.hpp"
#include "../algorithm/Math/ModularArithmetic/modint.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = struct {
        algorithm::mint998244353 a;
        algorithm::mint998244353 b;
    };
    auto mapping = [](const S &f, algorithm::mint998244353 x) -> algorithm::mint998244353 {
        return f.a * x + f.b;
    };

    std::vector<S> v(n);
    for(auto &elem : v) std::cin >> elem.a >> elem.b;

    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b * rhs.a + rhs.b}; };
    constexpr auto e = []() -> S { return {1, 0}; };
    using monoid_type = algorithm::algebra::Monoid<S, op, e>;
    algorithm::SegmentTree<S, monoid_type> segtree(v);

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            algorithm::mint998244353 c, d;
            std::cin >> p >> c >> d;

            segtree.set(p, {c, d});
        } else {
            int l, r;
            int x;
            std::cin >> l >> r >> x;

            auto f = segtree.prod(l, r);
            auto ans = mapping(f, x);
            std::cout << ans << "\n";
        }
    }
}
