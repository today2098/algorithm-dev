#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_A"

#include <iostream>

#include "../lib/Graph/Others/prim.hpp"

int main() {
    int n;
    std::cin >> n;

    algorithm::Prim<int> prim(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int a;
            std::cin >> a;

            if(i < j and a != -1) prim.add_edge(i, j, a);
        }
    }

    auto ans = prim.prim();
    std::cout << ans << std::endl;
}
