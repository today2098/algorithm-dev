#ifndef ALGORITHM_POPCOUNT_HPP
#define ALGORITHM_POPCOUNT_HPP 1

/**
 * @brief Population Count (popcount)
 * @docs docs/Others/popcount.md
 */

#include <cstdint>

namespace algorithm {

constexpr int popcount32(uint32_t bit) {
    bit -= (bit >> 1) & 0x55555555U;
    bit = (bit & 0x33333333U) + ((bit >> 2) & 0x33333333U);
    bit = (bit + (bit >> 4)) & 0x0f0f0f0fU;
    bit += bit >> 8;
    bit += bit >> 16;
    return bit & 0x3fU;
}

constexpr int popcount64(uint64_t bit) {
    bit -= (bit >> 1) & 0x5555555555555555ULL;
    bit = (bit & 0x3333333333333333ULL) + ((bit >> 2) & 0x3333333333333333ULL);
    bit = (bit + (bit >> 4)) & 0x0f0f0f0f0f0f0f0fULL;
    bit += bit >> 8;
    bit += bit >> 16;
    bit += bit >> 32;
    return bit & 0x7fULL;
}

}  // namespace algorithm

#endif
