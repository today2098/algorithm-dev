#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"

#include <bitset>
#include <cassert>
#include <iostream>
#include <limits>
#include <random>

#include "../lib/Others/popcount.hpp"
#include "../lib/Utils/debug.hpp"

constexpr int naive_popcount(uint64_t bit) {
    int res = 0;
    while(bit) {
        res++;
        bit &= bit - 1;
    }
    return res;
}

int main() {
    constexpr int t = 10000;
    std::random_device seed;
    std::mt19937_64 rng(seed());

    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::min()) == 0);
    static_assert(algorithm::popcount32(std::numeric_limits<uint32_t>::max()) == 32);
    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::min()) == 0);
    static_assert(algorithm::popcount64(std::numeric_limits<uint64_t>::max()) == 64);

    std::uniform_int_distribution<uint32_t> uniform(std::numeric_limits<uint32_t>::min(),
                                                    std::numeric_limits<uint32_t>::max());
    for(int i = 0; i < t; ++i) {
        uint32_t arg = uniform(rng);
        auto target = algorithm::popcount32(arg);
        auto want = naive_popcount(arg);
        debug(i, std::bitset<32>(arg), target, want);

        assert(target == want);
    }

    std::uniform_int_distribution<uint64_t> uniform2(std::numeric_limits<uint64_t>::min(),
                                                     std::numeric_limits<uint64_t>::max());
    for(int i = 0; i < t; ++i) {
        uint64_t arg = uniform2(rng);
        auto target = algorithm::popcount64(arg);
        auto want = naive_popcount(arg);
        debug(i, std::bitset<64>(arg), arg, target, want);

        assert(target == want);
    }

    std::cout << "Hello World" << std::endl;
}
