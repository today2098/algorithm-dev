#ifndef ALGORITHM_MODINT_BASE_HPP
#define ALGORITHM_MODINT_BASE_HPP 1

#include <type_traits>

namespace algorithm {

class ModintBase {};

template <class T>
using is_modint = std::is_base_of<ModintBase, T>;

template <class T>
inline constexpr bool is_modint_v = is_modint<T>::value;

}  // namespace algorithm

#endif
