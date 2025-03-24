#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include <utility>
#include <vector>

#include "../lib/Graph/Tree/double_sweep.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, long long> > > g(n);
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;

        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    auto &&[d, path] = algorithm::double_sweep(g);

    std::cout << d << " " << path.size() << "\n";
    for(auto v : path) std::cout << v << " ";
    std::cout << std::endl;
}
