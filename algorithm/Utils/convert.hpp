#ifndef ALGORITHM_CONVERT_HPP
#define ALGORITHM_CONVERT_HPP 1

namespace algorithm {

template <typename Type>
bool chmin(Type &a, const Type &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

template <typename Type>
bool chmax(Type &a, const Type &b) {
    if(a >= b) return false;
    a = b;
    return true;
}

}  // namespace algorithm

#endif
