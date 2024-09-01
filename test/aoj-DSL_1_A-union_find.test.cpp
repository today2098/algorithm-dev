#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <iostream>

#include "../lib/DataStructure/UnionFind/union_find.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    algorithm::UnionFind uf(n);
    while(q--) {
        int com;
        int x, y;
        std::cin >> com >> x >> y;

        if(com == 0) uf.unite(x, y);
        else std::cout << uf.is_same(x, y) << "\n";
    }
}
