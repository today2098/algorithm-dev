#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <queue>
#include <vector>

#include "../lib/Graph/Others/strongly_connected_components.hpp"

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

    std::cout << num << "\n";

    std::vector<int> degree(num, 0);
    for(const auto &edge : dag) {
        for(auto to : edge) degree[to]++;
    }

    std::queue<int> que;
    for(int i = 0; i < num; ++i) {
        if(degree[i] == 0) que.push(i);
    }
    while(!que.empty()) {
        auto id = que.front();
        que.pop();

        std::cout << sccs[id].size() << " ";
        for(auto v : sccs[id]) std::cout << v << " ";
        std::cout << "\n";

        for(auto id2 : dag[id]) {
            if(--degree[id2] == 0) que.push(id2);
        }
    }
}
