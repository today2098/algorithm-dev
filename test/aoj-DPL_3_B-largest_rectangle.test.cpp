#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/3/DPL_3_B"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../lib/Others/largest_rectangle.hpp"

int main() {
    int h, w;
    std::cin >> h >> w;

    std::vector c(h, std::vector<char>(w));
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) std::cin >> c[i][j];
    }

    int ans = 0;
    std::vector<int> height(w, 0);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(c[i][j] == '0') height[j]++;
            else height[j] = 0;
        }

        auto &&ranges = algorithm::largest_rectangle(height);
        for(int j = 0; j < w; ++j) {
            const auto &[l, r] = ranges[j];
            auto tmp = height[j] * (r - l);
            ans = std::max(ans, tmp);
        }
    }

    std::cout << ans << std::endl;
}
