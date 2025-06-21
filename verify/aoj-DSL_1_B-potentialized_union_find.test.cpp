#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include <iostream>

#include "../lib/DataStructure/UnionFind/potentialized_union_find.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::PotentializedUnionFind<int> uf(n);

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int x, y;
            int z;
            std::cin >> x >> y >> z;

            uf.unite(x, y, z);
        } else {
            int x, y;
            std::cin >> x >> y;

            if(uf.is_same(x, y)) std::cout << uf.diff(x, y) << "\n";
            else std::cout << "?" << "\n";
        }
    }
}
