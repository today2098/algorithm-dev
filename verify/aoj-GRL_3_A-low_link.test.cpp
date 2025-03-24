#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include <iostream>

#include "../lib/Graph/Others/low_link.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    algorithm::LowLink lowlink(n);
    for(int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;

        lowlink.add_edge(s, t);
    }
    lowlink.lowlink();

    for(auto elem : lowlink.articulation_points()) std::cout << elem << "\n";
}
