#ifndef ALGORITHM_POPCOUNT_HPP
#define ALGORITHM_POPCOUNT_HPP 1

#include <cstdint>

namespace algorithm {

constexpr int popcount32(uint32_t bit) {
    bit -= (bit >> 1) & 0x5555'5555U;
    bit = (bit & 0x3333'3333U) + ((bit >> 2) & 0x3333'3333U);
    bit = (bit + (bit >> 4)) & 0x0f0f'0f0fU;
    bit += bit >> 8;
    bit += bit >> 16;
    return bit & 0x0000'003fU;
}

constexpr int popcount64(uint64_t bit) {
    bit -= (bit >> 1) & 0x5555'5555'5555'5555ULL;
    bit = (bit & 0x3333'3333'3333'3333ULL) + ((bit >> 2) & 0x3333'3333'3333'3333ULL);
    bit = (bit + (bit >> 4)) & 0x0f0f'0f0f'0f0f'0f0fULL;
    bit += bit >> 8;
    bit += bit >> 16;
    bit += bit >> 32;
    return bit & 0x0000'0000'0000'007fULL;
}

}  // namespace algorithm

#endif
