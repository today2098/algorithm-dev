#ifndef ALGORITHM_ALGEBRA_HPP
#define ALGORITHM_ALGEBRA_HPP

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <type_traits>
#include <utility>

namespace algorithm {

namespace algebra {

template <typename S>
class Set {
public:
    using value_type = S;

protected:
    value_type val;

public:
    constexpr Set() : val() {}
    constexpr Set(const value_type &val) : val(val) {}
    constexpr Set(value_type &&val) : val(std::move(val)) {}

    friend constexpr bool operator==(const Set &lhs, const Set &rhs) { return lhs.val == rhs.val; }
    friend std::istream &operator>>(std::istream &is, Set &rhs) { return is >> rhs.val; }
    friend std::ostream &operator<<(std::ostream &os, const Set &rhs) { return os << rhs.val; }

    constexpr value_type value() const { return val; }
};

template <typename S, auto op>
class Semigroup : public Set<S> {
    static_assert(std::is_invocable_r<S, decltype(op), S, S>::value);

public:
    using base_type = Set<S>;
    using value_type = typename base_type::value_type;

    constexpr Semigroup() : base_type() {}
    constexpr Semigroup(const value_type &val) : base_type(val) {}
    constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}

    friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup &rhs) { return Semigroup(op(lhs.val, rhs.val)); }

    static constexpr auto get_op() { return op; }
};

template <typename S, auto op, auto e>
class Monoid : public Semigroup<S, op> {
    static_assert(std::is_invocable_r<S, decltype(e)>::value);

public:
    using base_type = Semigroup<S, op>;
    using value_type = typename base_type::value_type;

    constexpr Monoid() : base_type() {}
    constexpr Monoid(const value_type &val) : base_type(val) {}
    constexpr Monoid(value_type &&val) : base_type(std::move(val)) {}

    friend constexpr Monoid operator*(const Monoid &lhs, const Monoid &rhs) { return Monoid(op(lhs.val, rhs.val)); }

    static constexpr auto get_e() { return e; }
    static constexpr Monoid one() { return Monoid(e()); }  // return identity element.
};

template <typename S, auto op, auto e, auto inverse>
class Group : public Monoid<S, op, e> {
    static_assert(std::is_invocable_r<S, decltype(inverse), S>::value);

public:
    using base_type = Monoid<S, op, e>;
    using value_type = typename base_type::value_type;

    constexpr Group() : base_type() {}
    constexpr Group(const value_type &val) : base_type(val) {}
    constexpr Group(value_type &&val) : base_type(std::move(val)) {}

    friend constexpr Group operator*(const Group &lhs, const Group &rhs) { return Group(op(lhs.val, rhs.val)); }

    static constexpr auto get_inverse() { return inverse; }
    static constexpr Group one() { return Group(e()); }                     // return identity element.
    constexpr Group inv() const { return Group(inverse(base_type::val)); }  // return inverse element.
};

template <typename F, auto compose, auto id, typename X, auto mapping>
class OperatorMonoid : public Monoid<F, compose, id> {
    static_assert(std::is_invocable_r<X, decltype(mapping), F, X>::value);

public:
    using base_type = Monoid<F, compose, id>;
    using value_type = typename base_type::value_type;
    using acted_type = X;

    constexpr OperatorMonoid() : base_type() {}
    constexpr OperatorMonoid(const value_type &val) : base_type(val) {}
    constexpr OperatorMonoid(value_type &&val) : base_type(std::move(val)) {}

    friend constexpr OperatorMonoid operator*(const OperatorMonoid &lhs, const OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.val, rhs.val)); }

    static constexpr auto get_mapping() { return mapping; }
    static constexpr OperatorMonoid one() { return OperatorMonoid(id()); }  // return identity mapping.
    constexpr acted_type act(const acted_type &x) const { return mapping(base_type::val, x); }
    template <class S>
    constexpr S act(const S &x) const {
        static_assert(std::is_base_of<Set<acted_type>, S>::value);
        return S(mapping(base_type::val, x.value()));
    }
};

namespace element {

template <typename S>
constexpr auto zero = []() -> S { return S(); };

template <typename S>
constexpr auto one = []() -> S { return 1; };

template <typename S>
constexpr auto min = []() -> S { return std::numeric_limits<S>::min(); };

template <typename S>
constexpr auto max = []() -> S { return std::numeric_limits<S>::max(); };

template <typename S>
constexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max() - 1; };

template <typename S>
constexpr auto lowest = []() -> S { return std::numeric_limits<S>::lowest(); };

template <typename S>
constexpr auto one_above_lowest = []() -> S { return std::numeric_limits<S>::lowest() + 1; };

}  // namespace element

namespace unary_operator {

template <typename S>
constexpr auto identity = [](const S &val) -> S { return val; };

template <typename S>
constexpr auto negate = [](const S &val) -> S { return -val; };

}  // namespace unary_operator

namespace binary_operator {

template <typename T, typename S = T>
constexpr auto plus = [](const T &lhs, const S &rhs) -> S { return lhs + rhs; };

template <typename T, typename S = T>
constexpr auto mul = [](const T &lhs, const S &rhs) -> S { return lhs * rhs; };

template <typename T, typename S = T>
constexpr auto bit_and = [](const T &lhs, const S &rhs) -> S { return lhs & rhs; };

template <typename T, typename S = T>
constexpr auto bit_or = [](const T &lhs, const S &rhs) -> S { return lhs | rhs; };

template <typename T, typename S = T>
constexpr auto bit_xor = [](const T &lhs, const S &rhs) -> S { return lhs ^ rhs; };

template <typename T, typename S = T>
constexpr auto min = [](const T &lhs, const S &rhs) -> S { return std::min<S>(lhs, rhs); };

template <typename T, typename S = T>
constexpr auto max = [](const T &lhs, const S &rhs) -> S { return std::max<S>(lhs, rhs); };

template <typename T, typename S = T>
constexpr auto gcd = [](const T &lhs, const S &rhs) -> S { return std::gcd(lhs, rhs); };

template <typename T, typename S = T>
constexpr auto lcm = [](const T &lhs, const S &rhs) -> S { return std::lcm(lhs, rhs); };

template <typename F, auto id, typename X = F>
constexpr auto assign_if_not_id = [](const F &lhs, const X &rhs) -> X {
    static_assert(std::is_invocable_r<F, decltype(id)>::value);
    return (lhs == id() ? rhs : lhs);
};

}  // namespace binary_operator

namespace monoid {

template <typename S>
using minimum = Monoid<S, binary_operator::min<S>, element::max<S>>;

template <typename S>
using minimum_safe = Monoid<S, binary_operator::min<S>, element::one_below_max<S>>;

template <typename S>
using maximum = Monoid<S, binary_operator::max<S>, element::lowest<S>>;

template <typename S>
using maximum_safe = Monoid<S, binary_operator::max<S>, element::one_above_lowest<S>>;

template <typename S>
using addition = Monoid<S, binary_operator::plus<S>, element::zero<S>>;

template <typename S>
using multiplication = Monoid<S, binary_operator::mul<S>, element::one<S>>;

template <typename S>
using bit_xor = Monoid<S, binary_operator::bit_xor<S>, element::zero<S>>;

}  // namespace monoid

namespace group {

template <typename S>
using addition = Group<S, binary_operator::plus<S>, element::zero<S>, unary_operator::negate<S>>;

template <typename S>
using bit_xor = Group<S, binary_operator::bit_xor<S>, element::zero<S>, unary_operator::identity<S>>;

}  // namespace group

namespace operator_monoid {

template <typename F, typename X = F>
using assign_for_minimum = OperatorMonoid<
    F, binary_operator::assign_if_not_id<F, element::max<F>>, element::max<F>,
    X, binary_operator::assign_if_not_id<F, element::max<F>, X>>;

template <typename F, typename X = F>
using assign_for_maximum = OperatorMonoid<
    F, binary_operator::assign_if_not_id<F, element::lowest<F>>, element::lowest<F>,
    X, binary_operator::assign_if_not_id<F, element::lowest<F>, X>>;

template <typename F, typename X = F>
using addition = OperatorMonoid<
    F, binary_operator::plus<F>, element::zero<F>,
    X, binary_operator::plus<F, X>>;

}  // namespace operator_monoid

}  // namespace algebra

}  // namespace algorithm

#endif
