#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>

#include "../lib/DataStructure/SegmentTree/lazy_segment_tree.hpp"
#include "../lib/Math/ModularArithmetic/modint.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using Type = algorithm::mint998244353;
    auto &&segtree = algorithm::lazysegmenttree::range_sum_query_and_range_affine_query<Type>(n);
    for(int i = 0; i < n; ++i) {
        Type a;
        std::cin >> a;

        segtree.set(i, {a, 1});
    }

    while(q--) {
        int type;
        int l, r;
        std::cin >> type >> l >> r;

        if(type == 0) {
            Type b, c;
            std::cin >> b >> c;

            segtree.apply(l, r, {b, c});
        } else {
            auto &&ans = segtree.prod(l, r).val;
            std::cout << ans << "\n";
        }
    }
}
