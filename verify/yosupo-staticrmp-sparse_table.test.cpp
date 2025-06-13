#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/sparse_table.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &elem : a) std::cin >> elem;

    algorithm::sparse_table::range_minimum_sparse_table<int> table(a.cbegin(), a.cend());

    while(q--) {
        int l, r;
        std::cin >> l >> r;

        auto &&ans = table.prod(l, r);
        std::cout << ans << "\n";
    }
}
