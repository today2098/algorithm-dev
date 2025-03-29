#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "../lib/DataStructure/SegmentTree/sparse_table.hpp"
#include "../lib/Utils/debug.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = int;
    std::vector<S> a(n);
    for(auto &elem : a) std::cin >> elem;

    auto op = [](S a, S b) -> S { return std::min(a, b); };
    algorithm::SparseTable<S, op> sparse_table(std::move(a));
    debug(sparse_table);
    debug(a);

    while(q--) {
        int l, r;
        std::cin >> l >> r;

        auto &&ans = sparse_table.prod(l, r);
        std::cout << ans << "\n";
    }
}
