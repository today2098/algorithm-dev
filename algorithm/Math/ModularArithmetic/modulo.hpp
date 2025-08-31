#ifndef ALGORITHM_MODULO_HPP
#define ALGORITHM_MODULO_HPP 1

#include <concepts>
#include <cstdint>

namespace algorithm {

namespace internal {

// return x mod m.
template <std::unsigned_integral Type>
constexpr std::uint32_t modulo(Type x, std::uint32_t mod) { return x % mod; }

// return x mod m.
template <std::unsigned_integral Type>
constexpr std::uint32_t modulo(Type x, std::int32_t mod) { return modulo(x, static_cast<std::uint32_t>(mod)); }

// return x mod m.
template <std::signed_integral Type>
constexpr std::uint32_t modulo(Type x, std::uint32_t mod) {
    x %= static_cast<std::int64_t>(mod);
    if(x < 0) x += static_cast<std::int64_t>(mod);
    return x;
}

// return x mod m.
template <std::signed_integral Type>
constexpr std::uint32_t modulo(Type x, std::int32_t mod) {
    x %= mod;
    if(x < 0) x += mod;
    return x;
}

}  // namespace internal

}  // namespace algorithm

#endif
