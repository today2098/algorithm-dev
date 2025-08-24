#ifndef ALGORITHM_MODINT_BASE_HPP
#define ALGORITHM_MODINT_BASE_HPP 1

#include <type_traits>

namespace algorithm {

class ModintBase {};

template <typename T>
struct is_modint : std::is_base_of<ModintBase, std::remove_cv_t<std::remove_reference_t<T>>> {};

template <typename T>
inline constexpr bool is_modint_v = is_modint<T>::value;

}  // namespace algorithm

#endif
