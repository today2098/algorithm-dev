#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>

#include "../algorithm/Math/Convolution/number_theoretic_transform.hpp"
#include "../algorithm/Math/ModularArithmetic/modint.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<algorithm::mint998244353> a(n), b(m);
    for(auto &elem : a) std::cin >> elem;
    for(auto &elem : b) std::cin >> elem;

    auto &&c = algorithm::ntt::convolve(a, b);
    for(const auto &elem : c) std::cout << elem << " ";
    std::cout << std::endl;
}
