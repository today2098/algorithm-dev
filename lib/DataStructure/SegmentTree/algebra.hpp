#ifndef ALGORITHM_ALGEBRA_HPP
#define ALGORITHM_ALGEBRA_HPP

#include <algorithm>
#include <functional>
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

    constexpr value_type value() const { return val; }
};

template <typename T>
struct is_set : std::false_type {};

template <typename S>
struct is_set<Set<S>> : std::true_type {};

template <typename S, auto op>
class Semigroup : public Set<S> {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>);

    using base_type = Set<S>;

public:
    using value_type = typename base_type::value_type;

    constexpr Semigroup() : base_type() {}
    constexpr Semigroup(const value_type &val) : base_type(val) {}
    constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}

    friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup &rhs) { return Semigroup(op(lhs.val, rhs.val)); }

    static constexpr auto get_op() { return op; }
};

template <typename T>
struct is_semigroup : std::false_type {};

template <typename S, auto op>
struct is_semigroup<Semigroup<S, op>> : std::true_type {};

template <typename S, auto op, auto e>
class Monoid : public Semigroup<S, op> {
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);

    using base_type = Semigroup<S, op>;

public:
    using value_type = typename base_type::value_type;

    constexpr Monoid() : base_type() {}
    constexpr Monoid(const value_type &val) : base_type(val) {}
    constexpr Monoid(value_type &&val) : base_type(std::move(val)) {}

    friend constexpr Monoid operator*(const Monoid &lhs, const Monoid &rhs) { return Monoid(op(lhs.val, rhs.val)); }

    static constexpr Monoid one() { return Monoid(e()); }  // return identity element.
    static constexpr auto get_e() { return e; }
};

template <typename T>
struct is_monoid : std::false_type {};

template <typename S, auto op, auto e>
struct is_monoid<Monoid<S, op, e>> : std::true_type {};

namespace boperator {

template <typename S>
constexpr auto add = [](const S &lhs, const S &rhs) -> S { return lhs + rhs; };

template <typename S>
constexpr auto sub = [](const S &lhs, const S &rhs) -> S { return lhs - rhs; };

template <typename S>
constexpr auto mul = [](const S &lhs, const S &rhs) -> S { return lhs * rhs; };

template <typename S>
constexpr auto div = [](const S &lhs, const S &rhs) -> S { return lhs / rhs; };

template <typename S>
constexpr auto bit_and = [](const S &lhs, const S &rhs) -> S { return lhs & rhs; };

template <typename S>
constexpr auto bit_or = [](const S &lhs, const S &rhs) -> S { return lhs | rhs; };

template <typename S>
constexpr auto bit_xor = [](const S &lhs, const S &rhs) -> S { return lhs ^ rhs; };

template <typename S>
constexpr auto min = [](const S &lhs, const S &rhs) -> S { return std::min(lhs, rhs); };

template <typename S>
constexpr auto max = [](const S &lhs, const S &rhs) -> S { return std::max(lhs, rhs); };

template <typename S>
constexpr auto gcd = [](const S &lhs, const S &rhs) -> S { return std::gcd(lhs, rhs); };

template <typename S>
constexpr auto lcm = [](const S &lhs, const S &rhs) -> S { return std::lcm(lhs, rhs); };

}  // namespace boperator

namespace element {

template <typename S>
constexpr auto zero = []() -> S { return 0; };

template <typename S>
constexpr auto one = []() -> S { return 1; };

template <typename S>
constexpr auto min = []() -> S { return std::numeric_limits<S>::min(); };

template <typename S>
constexpr auto max = []() -> S { return std::numeric_limits<S>::max(); };

template <typename S>
constexpr auto lowest = []() -> S { return std::numeric_limits<S>::lowest(); };

}  // namespace element

namespace monoid {

template <typename S>
using range_minimum_query = Monoid<S, boperator::min<S>, element::max<S>>;

template <typename S>
using range_maximum_query = Monoid<S, boperator::max<S>, element::lowest<S>>;

template <typename S>
using range_sum_query = Monoid<S, boperator::add<S>, element::zero<S>>;

template <typename S>
using range_product_query = Monoid<S, boperator::mul<S>, element::one<S>>;

}  // namespace monoid

}  // namespace algebra

}  // namespace algorithm

#endif
