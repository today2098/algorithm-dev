#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/DataStructure/SegmentTree/sparse_table.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    auto op = [](int a, int b) -> int { return std::min(a, b); };
    algorithm::SparseTable<int> sparse_table(op, a);

    while(q--) {
        int l, r;
        std::cin >> l >> r;

        auto &&ans = sparse_table.fold(l, r);
        std::cout << ans << "\n";
    }
}
