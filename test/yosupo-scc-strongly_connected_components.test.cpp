#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>

#include "../lib/Graph/Others/strongly_connected_components.hpp"
#include "../lib/Graph/Others/topological_sort.hpp"

int main() {
    int n;
    int m;
    std::cin >> n >> m;

    algorithm::SCC scc(n);
    for(int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;

        scc.add_edge(a, b);
    }

    auto &&[num, ids] = scc.decompose();
    auto &&sccs = scc.scc(num, ids);
    auto &&dag = scc.directed_acyclic_graph(num, ids);

    algorithm::TopologicalSort ts(num);
    for(int u = 0; u < num; ++u) {
        for(auto v : dag[u]) ts.add_edge(u, v);
    }
    auto &&v = ts.topological_sort();

    std::cout << num << "\n";
    for(auto id : v) {
        std::cout << sccs[id].size() << " ";
        for(auto v : sccs[id]) std::cout << v << " ";
        std::cout << "\n";
    }
}
