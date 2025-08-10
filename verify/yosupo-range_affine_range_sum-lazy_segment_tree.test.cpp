#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp"
#include "../algorithm/Math/ModularArithmetic/modint.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &elem : a) std::cin >> elem;

    algorithm::RangeSumRangeAffineLazySegmentTree<algorithm::mint998244353> segtree(a);

    while(q--) {
        int type;
        int l, r;
        std::cin >> type >> l >> r;

        if(type == 0) {
            int b, c;
            std::cin >> b >> c;

            segtree.apply(l, r, {b, c});
        } else {
            auto ans = segtree.prod(l, r);
            std::cout << ans << "\n";
        }
    }
}
