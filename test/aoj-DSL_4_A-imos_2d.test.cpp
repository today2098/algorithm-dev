#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/4/DSL_4_A"

#include <iostream>

#include "../lib/Others/compress.hpp"
#include "../lib/Others/imos_2d.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ys(2 * n), xs(2 * n);
    for(int i = 0; i < n; ++i) std::cin >> xs[2 * i] >> ys[2 * i] >> xs[2 * i + 1] >> ys[2 * i + 1];

    auto key_y = algorithm::compress(ys);
    auto key_x = algorithm::compress(xs);

    const int h = key_y.size(), w = key_x.size();
    algorithm::Imos2D<int> imos(h - 1, w - 1);
    for(int i = 0; i < n; ++i) imos.add(ys[2 * i], xs[2 * i], ys[2 * i + 1], xs[2 * i + 1], 1);
    imos.build();

    long long ans = 0;
    for(int i = 0; i < h - 1; ++i) {
        for(int j = 0; j < w - 1; ++j) {
            if(imos.get(i, j) > 0) {
                long long tmp = (long long)(key_y[i + 1] - key_y[i]) * (key_x[j + 1] - key_x[j]);
                ans += tmp;
            }
        }
    }

    std::cout << ans << std::endl;
}
