#ifndef ALGORITHM_TABLE_HPP
#define ALGORITHM_TABLE_HPP 1

/**
 * @brief 多次元配列生成
 * @docs docs/Utils/table.md
 */

#include <vector>

namespace algorithm {

template <typename Type>
std::vector<Type> table(size_t n, const Type &val) { return std::vector<Type>(n, val); }

template <typename... Args>
auto table(size_t n, const Args &...args) { return std::vector(n, table(args...)); }

}  // namespace algorithm

#endif
