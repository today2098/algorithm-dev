#ifndef ALGORITHM_BIGINT_UTILS_HPP
#define ALGORITHM_BIGINT_UTILS_HPP 1

#include "bigint.hpp"
#include "binary_bigint.hpp"

namespace algorithm {

BinaryBigint dtoh(const Bigint &a) {
    BinaryBigint res;
    for(auto iter = a.words().crbegin(); iter < a.words().crend(); ++iter) {
        res *= Bigint::base();
        res += *iter;
    }
    if(a.is_negative()) res.negate();
    return res;
};

Bigint htod(const BinaryBigint &a) {
    if(a.is_negative()) return htod(-a).negate();
    Bigint res;
    for(auto iter = a.words().crbegin(); iter < a.words().crend(); ++iter) {
        res *= BinaryBigint::base();
        res += *iter;
    }
    return res;
};

}  // namespace algorithm

#endif
