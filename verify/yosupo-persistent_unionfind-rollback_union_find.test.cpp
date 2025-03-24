#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <tuple>
#include <vector>

#include "../lib/DataStructure/UnionFind/rollback_union_find.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    // queries[k]:=(k番目のグラフに対するクエリ). tuple of (type, u, v, index).
    std::vector<std::vector<std::tuple<int, int, int, int> > > queries(q + 1);
    for(int i = 1; i <= q; ++i) {
        int t;
        int k;
        int u, v;
        std::cin >> t >> k >> u >> v;
        k++;

        queries[k].emplace_back(t, u, v, i);
    }

    std::vector<int> ans(q + 1, -1);
    algorithm::RollbackUnionFind uf(n);
    auto dfs = [&](auto self, int t, int u, int v, int i) -> void {
        if(t == 0) {
            bool flag = uf.unite(u, v);
            for(const auto &[nt, nu, nv, ni] : queries[i]) self(self, nt, nu, nv, ni);
            if(flag) uf.rollback();
        } else {
            ans[i] = uf.is_same(u, v);
        }
    };
    for(const auto &[t, u, v, i] : queries[0]) dfs(dfs, t, u, v, i);

    for(auto elem : ans) {
        if(elem != -1) std::cout << elem << "\n";
    }
}
