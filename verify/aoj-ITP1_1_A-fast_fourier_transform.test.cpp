#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "../lib/Math/Convolution/fast_fourier_transform.hpp"

int main() {
    constexpr int t = 100;
    std::random_device seed;
    std::mt19937_64 rng(seed());

    constexpr double eps = 1e-6;
    std::uniform_int_distribution<int> uniform_n(1, 200);
    std::uniform_real_distribution<double> uniform(-1e3, 1e3);
    for(int i = 0; i < t; ++i) {
        const int n = uniform_n(rng), m = uniform_n(rng);
        std::vector<double> a(n), b(m);
        for(auto &elem : a) elem = uniform(rng);
        for(auto &elem : b) elem = uniform(rng);

        auto &&target = algorithm::fft::convolve(a, b);
        auto &&want = algorithm::fft::convolve_naive(a, b);

        assert(target.size() == size_t(n + m - 1));
        assert(want.size() == size_t(n + m - 1));
        for(int j = 0; j < n + m - 1; ++j) assert(std::abs(target[j] - want[j]) < eps);
    }

    std::cout << "Hello World" << std::endl;
}
