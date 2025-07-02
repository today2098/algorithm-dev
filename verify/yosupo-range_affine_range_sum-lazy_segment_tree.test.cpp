#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp"
#include "../algorithm/Math/ModularArithmetic/modint.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<algorithm::mint998244353> a(n);
    for(auto &elem : a) std::cin >> elem;

    algorithm::lazy_segment_tree::range_sum_range_affine_lazy_segment_tree<algorithm::mint998244353> segtree(a.cbegin(), a.cend());

    while(q--) {
        int type;
        int l, r;
        std::cin >> type >> l >> r;

        if(type == 0) {
            algorithm::mint998244353 b, c;
            std::cin >> b >> c;

            segtree.apply(l, r, {b, c});
        } else {
            auto &&ans = segtree.prod(l, r).val;
            std::cout << ans << "\n";
        }
    }
}
