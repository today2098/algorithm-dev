---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
    title: algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
    title: algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp
    title: algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp
  - icon: ':question:'
    path: algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp
    title: algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp
  - icon: ':question:'
    path: algorithm/DataStructure/SegmentTree/segment_tree.hpp
    title: algorithm/DataStructure/SegmentTree/segment_tree.hpp
  - icon: ':x:'
    path: algorithm/DataStructure/SegmentTree/sparse_table.hpp
    title: algorithm/DataStructure/SegmentTree/sparse_table.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
    title: verify/aoj-2842-binary_indexed_tree_2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
    title: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_A-segment_tree.test.cpp
    title: verify/aoj-DSL_2_A-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
    title: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-dynamic_segment_tree.test.cpp
    title: verify/aoj-DSL_2_B-dynamic_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-segment_tree.test.cpp
    title: verify/aoj-DSL_2_B-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_F-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_F-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_H-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_H-lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_I-lazy_segment_tree.test.cpp
    title: verify/aoj-DSL_2_I-lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
    title: verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
    title: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
    title: verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo-staticrmp-sparse_table.test.cpp
    title: verify/yosupo-staticrmp-sparse_table.test.cpp
  - icon: ':x:'
    path: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - icon: ':x:'
    path: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
    title: verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <iostream>\n#include <limits>\n#include <numeric>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace algorithm {\n\nnamespace algebra {\n\ntemplate\
    \ <typename S>\nclass Set {\npublic:\n    using value_type = S;\n\nprotected:\n\
    \    value_type val;\n\npublic:\n    constexpr Set() : val() {}\n    constexpr\
    \ Set(const value_type &val) : val(val) {}\n    constexpr Set(value_type &&val)\
    \ : val(std::move(val)) {}\n\n    friend constexpr bool operator==(const Set &lhs,\
    \ const Set &rhs) { return lhs.val == rhs.val; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Set &rhs) { return is >> rhs.val; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Set &rhs) { return os << rhs.val; }\n\n    constexpr value_type value()\
    \ const { return val; }\n};\n\ntemplate <typename S, auto op>\nclass Semigroup\
    \ : public Set<S> {\n    static_assert(std::is_invocable_r<S, decltype(op), S,\
    \ S>::value);\n\n    using base_type = Set<S>;\n\npublic:\n    using value_type\
    \ = typename base_type::value_type;\n\n    constexpr Semigroup() : base_type()\
    \ {}\n    constexpr Semigroup(const value_type &val) : base_type(val) {}\n   \
    \ constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}\n\n   \
    \ friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup &rhs)\
    \ { return Semigroup(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_op()\
    \ { return op; }\n};\n\ntemplate <typename S, auto op, auto e>\nclass Monoid :\
    \ public Semigroup<S, op> {\n    static_assert(std::is_invocable_r<S, decltype(e)>::value);\n\
    \n    using base_type = Semigroup<S, op>;\n\npublic:\n    using value_type = typename\
    \ base_type::value_type;\n\n    constexpr Monoid() : base_type() {}\n    constexpr\
    \ Monoid(const value_type &val) : base_type(val) {}\n    constexpr Monoid(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr Monoid operator*(const\
    \ Monoid &lhs, const Monoid &rhs) { return Monoid(op(lhs.val, rhs.val)); }\n\n\
    \    static constexpr auto get_e() { return e; }\n    static constexpr Monoid\
    \ one() { return Monoid(e()); }  // return identity element.\n};\n\ntemplate <typename\
    \ S, auto op, auto e, auto inverse>\nclass Group : public Monoid<S, op, e> {\n\
    \    static_assert(std::is_invocable_r<S, decltype(inverse), S>::value);\n\n \
    \   using base_type = Monoid<S, op, e>;\n\npublic:\n    using value_type = typename\
    \ base_type::value_type;\n\n    constexpr Group() : base_type() {}\n    constexpr\
    \ Group(const value_type &val) : base_type(val) {}\n    constexpr Group(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr Group operator*(const\
    \ Group &lhs, const Group &rhs) { return Group(op(lhs.val, rhs.val)); }\n\n  \
    \  static constexpr auto get_inverse() { return inverse; }\n    static constexpr\
    \ Group one() { return Group(e()); }                // return identity element.\n\
    \    constexpr Group inv() const { return Group(inverse(this->val)); }  // return\
    \ inverse element.\n};\n\ntemplate <typename F, auto compose, auto id, typename\
    \ X, auto mapping>\nclass OperatorMonoid : public Monoid<F, compose, id> {\n \
    \   static_assert(std::is_invocable_r<X, decltype(mapping), F, X>::value);\n\n\
    \    using base_type = Monoid<F, compose, id>;\n\npublic:\n    using value_type\
    \ = typename base_type::value_type;\n    using acted_value_type = X;\n\n    constexpr\
    \ OperatorMonoid() : base_type() {}\n    constexpr OperatorMonoid(const value_type\
    \ &val) : base_type(val) {}\n    constexpr OperatorMonoid(value_type &&val) :\
    \ base_type(std::move(val)) {}\n\n    friend constexpr OperatorMonoid operator*(const\
    \ OperatorMonoid &lhs, const OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.val,\
    \ rhs.val)); }\n\n    static constexpr auto get_mapping() { return mapping; }\n\
    \    static constexpr OperatorMonoid one() { return OperatorMonoid(id()); }  //\
    \ return identity mapping.\n    constexpr acted_value_type act(const acted_value_type\
    \ &x) const { return mapping(this->val, x); }\n    template <class S>\n    constexpr\
    \ S act(const S &x) const {\n        static_assert(std::is_base_of<Set<acted_value_type>,\
    \ S>::value);\n        return S(mapping(this->val, x.value()));\n    }\n};\n\n\
    namespace element {\n\ntemplate <typename S>\nconstexpr auto zero = []() -> S\
    \ { return S(); };\n\ntemplate <typename S>\nconstexpr auto one = []() -> S {\
    \ return 1; };\n\ntemplate <typename S>\nconstexpr auto min = []() -> S { return\
    \ std::numeric_limits<S>::min(); };\n\ntemplate <typename S>\nconstexpr auto max\
    \ = []() -> S { return std::numeric_limits<S>::max(); };\n\ntemplate <typename\
    \ S>\nconstexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max()\
    \ - 1; };\n\ntemplate <typename S>\nconstexpr auto lowest = []() -> S { return\
    \ std::numeric_limits<S>::lowest(); };\n\ntemplate <typename S>\nconstexpr auto\
    \ one_above_lowest = []() -> S { return std::numeric_limits<S>::lowest() + 1;\
    \ };\n\n}  // namespace element\n\nnamespace uoperator {\n\ntemplate <typename\
    \ S>\nconstexpr auto identity = [](const S &val) -> S { return val; };\n\ntemplate\
    \ <typename S>\nconstexpr auto negate = [](const S &val) -> S { return -val; };\n\
    \n}  // namespace uoperator\n\nnamespace boperator {\n\ntemplate <typename T,\
    \ typename S = T>\nconstexpr auto plus = [](const T &lhs, const S &rhs) -> S {\
    \ return lhs + rhs; };\n\ntemplate <typename T, typename S = T>\nconstexpr auto\
    \ mul = [](const T &lhs, const S &rhs) -> S { return lhs * rhs; };\n\ntemplate\
    \ <typename T, typename S = T>\nconstexpr auto bit_and = [](const T &lhs, const\
    \ S &rhs) -> S { return lhs & rhs; };\n\ntemplate <typename T, typename S = T>\n\
    constexpr auto bit_or = [](const T &lhs, const S &rhs) -> S { return lhs | rhs;\
    \ };\n\ntemplate <typename T, typename S = T>\nconstexpr auto bit_xor = [](const\
    \ T &lhs, const S &rhs) -> S { return lhs ^ rhs; };\n\ntemplate <typename T, typename\
    \ S = T>\nconstexpr auto min = [](const T &lhs, const S &rhs) -> S { return std::min<S>(lhs,\
    \ rhs); };\n\ntemplate <typename T, typename S = T>\nconstexpr auto max = [](const\
    \ T &lhs, const S &rhs) -> S { return std::max<S>(lhs, rhs); };\n\ntemplate <typename\
    \ T, typename S = T>\nconstexpr auto gcd = [](const T &lhs, const S &rhs) -> S\
    \ { return std::gcd(lhs, rhs); };\n\ntemplate <typename T, typename S = T>\nconstexpr\
    \ auto lcm = [](const T &lhs, const S &rhs) -> S { return std::lcm(lhs, rhs);\
    \ };\n\ntemplate <typename F, auto id, typename X = F>\nconstexpr auto assign_if_not_id\
    \ = [](const F &lhs, const X &rhs) -> X {\n    static_assert(std::is_invocable_r<F,\
    \ decltype(id)>::value);\n    return (lhs == id() ? rhs : lhs);\n};\n\n}  // namespace\
    \ boperator\n\nnamespace monoid {\n\ntemplate <typename S>\nusing minimum = Monoid<S,\
    \ boperator::min<S>, element::max<S>>;\n\ntemplate <typename S>\nusing minimum_safe\
    \ = Monoid<S, boperator::min<S>, element::one_below_max<S>>;\n\ntemplate <typename\
    \ S>\nusing maximum = Monoid<S, boperator::max<S>, element::lowest<S>>;\n\ntemplate\
    \ <typename S>\nusing maximum_safe = Monoid<S, boperator::max<S>, element::one_above_lowest<S>>;\n\
    \ntemplate <typename S>\nusing addition = Monoid<S, boperator::plus<S>, element::zero<S>>;\n\
    \ntemplate <typename S>\nusing multiplication = Monoid<S, boperator::mul<S>, element::one<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Monoid<S, boperator::bit_xor<S>, element::zero<S>>;\n\
    \n}  // namespace monoid\n\nnamespace group {\n\ntemplate <typename S>\nusing\
    \ addition = Group<S, boperator::plus<S>, element::zero<S>, uoperator::negate<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Group<S, boperator::bit_xor<S>, element::zero<S>,\
    \ uoperator::identity<S>>;\n\n}  // namespace group\n\nnamespace operator_monoid\
    \ {\n\ntemplate <typename F, typename X = F>\nusing assign_for_minimum = OperatorMonoid<\n\
    \    F, boperator::assign_if_not_id<F, element::max<F>>, element::max<F>,\n  \
    \  X, boperator::assign_if_not_id<F, element::max<F>, X>>;\n\ntemplate <typename\
    \ F, typename X = F>\nusing assign_for_maximum = OperatorMonoid<\n    F, boperator::assign_if_not_id<F,\
    \ element::lowest<F>>, element::lowest<F>,\n    X, boperator::assign_if_not_id<F,\
    \ element::lowest<F>, X>>;\n\ntemplate <typename F, typename X = F>\nusing addition\
    \ = OperatorMonoid<F, boperator::plus<F>, element::zero<F>, X, boperator::plus<F,\
    \ X>>;\n\n}  // namespace operator_monoid\n\n}  // namespace algebra\n\n}  //\
    \ namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_ALGEBRA_HPP\n#define ALGORITHM_ALGEBRA_HPP\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <limits>\n#include <numeric>\n#include\
    \ <type_traits>\n#include <utility>\n\nnamespace algorithm {\n\nnamespace algebra\
    \ {\n\ntemplate <typename S>\nclass Set {\npublic:\n    using value_type = S;\n\
    \nprotected:\n    value_type val;\n\npublic:\n    constexpr Set() : val() {}\n\
    \    constexpr Set(const value_type &val) : val(val) {}\n    constexpr Set(value_type\
    \ &&val) : val(std::move(val)) {}\n\n    friend constexpr bool operator==(const\
    \ Set &lhs, const Set &rhs) { return lhs.val == rhs.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Set &rhs) { return is >> rhs.val; }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Set &rhs) { return os << rhs.val;\
    \ }\n\n    constexpr value_type value() const { return val; }\n};\n\ntemplate\
    \ <typename S, auto op>\nclass Semigroup : public Set<S> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(op), S, S>::value);\n\n    using base_type = Set<S>;\n\npublic:\n \
    \   using value_type = typename base_type::value_type;\n\n    constexpr Semigroup()\
    \ : base_type() {}\n    constexpr Semigroup(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}\n\
    \n    friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup\
    \ &rhs) { return Semigroup(op(lhs.val, rhs.val)); }\n\n    static constexpr auto\
    \ get_op() { return op; }\n};\n\ntemplate <typename S, auto op, auto e>\nclass\
    \ Monoid : public Semigroup<S, op> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(e)>::value);\n\n    using base_type = Semigroup<S, op>;\n\npublic:\n\
    \    using value_type = typename base_type::value_type;\n\n    constexpr Monoid()\
    \ : base_type() {}\n    constexpr Monoid(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Monoid(value_type &&val) : base_type(std::move(val)) {}\n\n\
    \    friend constexpr Monoid operator*(const Monoid &lhs, const Monoid &rhs) {\
    \ return Monoid(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_e()\
    \ { return e; }\n    static constexpr Monoid one() { return Monoid(e()); }  //\
    \ return identity element.\n};\n\ntemplate <typename S, auto op, auto e, auto\
    \ inverse>\nclass Group : public Monoid<S, op, e> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(inverse), S>::value);\n\n    using base_type = Monoid<S, op, e>;\n\n\
    public:\n    using value_type = typename base_type::value_type;\n\n    constexpr\
    \ Group() : base_type() {}\n    constexpr Group(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Group(value_type &&val) : base_type(std::move(val)) {}\n\n\
    \    friend constexpr Group operator*(const Group &lhs, const Group &rhs) { return\
    \ Group(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_inverse() {\
    \ return inverse; }\n    static constexpr Group one() { return Group(e()); } \
    \               // return identity element.\n    constexpr Group inv() const {\
    \ return Group(inverse(this->val)); }  // return inverse element.\n};\n\ntemplate\
    \ <typename F, auto compose, auto id, typename X, auto mapping>\nclass OperatorMonoid\
    \ : public Monoid<F, compose, id> {\n    static_assert(std::is_invocable_r<X,\
    \ decltype(mapping), F, X>::value);\n\n    using base_type = Monoid<F, compose,\
    \ id>;\n\npublic:\n    using value_type = typename base_type::value_type;\n  \
    \  using acted_value_type = X;\n\n    constexpr OperatorMonoid() : base_type()\
    \ {}\n    constexpr OperatorMonoid(const value_type &val) : base_type(val) {}\n\
    \    constexpr OperatorMonoid(value_type &&val) : base_type(std::move(val)) {}\n\
    \n    friend constexpr OperatorMonoid operator*(const OperatorMonoid &lhs, const\
    \ OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.val, rhs.val)); }\n\
    \n    static constexpr auto get_mapping() { return mapping; }\n    static constexpr\
    \ OperatorMonoid one() { return OperatorMonoid(id()); }  // return identity mapping.\n\
    \    constexpr acted_value_type act(const acted_value_type &x) const { return\
    \ mapping(this->val, x); }\n    template <class S>\n    constexpr S act(const\
    \ S &x) const {\n        static_assert(std::is_base_of<Set<acted_value_type>,\
    \ S>::value);\n        return S(mapping(this->val, x.value()));\n    }\n};\n\n\
    namespace element {\n\ntemplate <typename S>\nconstexpr auto zero = []() -> S\
    \ { return S(); };\n\ntemplate <typename S>\nconstexpr auto one = []() -> S {\
    \ return 1; };\n\ntemplate <typename S>\nconstexpr auto min = []() -> S { return\
    \ std::numeric_limits<S>::min(); };\n\ntemplate <typename S>\nconstexpr auto max\
    \ = []() -> S { return std::numeric_limits<S>::max(); };\n\ntemplate <typename\
    \ S>\nconstexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max()\
    \ - 1; };\n\ntemplate <typename S>\nconstexpr auto lowest = []() -> S { return\
    \ std::numeric_limits<S>::lowest(); };\n\ntemplate <typename S>\nconstexpr auto\
    \ one_above_lowest = []() -> S { return std::numeric_limits<S>::lowest() + 1;\
    \ };\n\n}  // namespace element\n\nnamespace uoperator {\n\ntemplate <typename\
    \ S>\nconstexpr auto identity = [](const S &val) -> S { return val; };\n\ntemplate\
    \ <typename S>\nconstexpr auto negate = [](const S &val) -> S { return -val; };\n\
    \n}  // namespace uoperator\n\nnamespace boperator {\n\ntemplate <typename T,\
    \ typename S = T>\nconstexpr auto plus = [](const T &lhs, const S &rhs) -> S {\
    \ return lhs + rhs; };\n\ntemplate <typename T, typename S = T>\nconstexpr auto\
    \ mul = [](const T &lhs, const S &rhs) -> S { return lhs * rhs; };\n\ntemplate\
    \ <typename T, typename S = T>\nconstexpr auto bit_and = [](const T &lhs, const\
    \ S &rhs) -> S { return lhs & rhs; };\n\ntemplate <typename T, typename S = T>\n\
    constexpr auto bit_or = [](const T &lhs, const S &rhs) -> S { return lhs | rhs;\
    \ };\n\ntemplate <typename T, typename S = T>\nconstexpr auto bit_xor = [](const\
    \ T &lhs, const S &rhs) -> S { return lhs ^ rhs; };\n\ntemplate <typename T, typename\
    \ S = T>\nconstexpr auto min = [](const T &lhs, const S &rhs) -> S { return std::min<S>(lhs,\
    \ rhs); };\n\ntemplate <typename T, typename S = T>\nconstexpr auto max = [](const\
    \ T &lhs, const S &rhs) -> S { return std::max<S>(lhs, rhs); };\n\ntemplate <typename\
    \ T, typename S = T>\nconstexpr auto gcd = [](const T &lhs, const S &rhs) -> S\
    \ { return std::gcd(lhs, rhs); };\n\ntemplate <typename T, typename S = T>\nconstexpr\
    \ auto lcm = [](const T &lhs, const S &rhs) -> S { return std::lcm(lhs, rhs);\
    \ };\n\ntemplate <typename F, auto id, typename X = F>\nconstexpr auto assign_if_not_id\
    \ = [](const F &lhs, const X &rhs) -> X {\n    static_assert(std::is_invocable_r<F,\
    \ decltype(id)>::value);\n    return (lhs == id() ? rhs : lhs);\n};\n\n}  // namespace\
    \ boperator\n\nnamespace monoid {\n\ntemplate <typename S>\nusing minimum = Monoid<S,\
    \ boperator::min<S>, element::max<S>>;\n\ntemplate <typename S>\nusing minimum_safe\
    \ = Monoid<S, boperator::min<S>, element::one_below_max<S>>;\n\ntemplate <typename\
    \ S>\nusing maximum = Monoid<S, boperator::max<S>, element::lowest<S>>;\n\ntemplate\
    \ <typename S>\nusing maximum_safe = Monoid<S, boperator::max<S>, element::one_above_lowest<S>>;\n\
    \ntemplate <typename S>\nusing addition = Monoid<S, boperator::plus<S>, element::zero<S>>;\n\
    \ntemplate <typename S>\nusing multiplication = Monoid<S, boperator::mul<S>, element::one<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Monoid<S, boperator::bit_xor<S>, element::zero<S>>;\n\
    \n}  // namespace monoid\n\nnamespace group {\n\ntemplate <typename S>\nusing\
    \ addition = Group<S, boperator::plus<S>, element::zero<S>, uoperator::negate<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Group<S, boperator::bit_xor<S>, element::zero<S>,\
    \ uoperator::identity<S>>;\n\n}  // namespace group\n\nnamespace operator_monoid\
    \ {\n\ntemplate <typename F, typename X = F>\nusing assign_for_minimum = OperatorMonoid<\n\
    \    F, boperator::assign_if_not_id<F, element::max<F>>, element::max<F>,\n  \
    \  X, boperator::assign_if_not_id<F, element::max<F>, X>>;\n\ntemplate <typename\
    \ F, typename X = F>\nusing assign_for_maximum = OperatorMonoid<\n    F, boperator::assign_if_not_id<F,\
    \ element::lowest<F>>, element::lowest<F>,\n    X, boperator::assign_if_not_id<F,\
    \ element::lowest<F>, X>>;\n\ntemplate <typename F, typename X = F>\nusing addition\
    \ = OperatorMonoid<F, boperator::plus<F>, element::zero<F>, X, boperator::plus<F,\
    \ X>>;\n\n}  // namespace operator_monoid\n\n}  // namespace algebra\n\n}  //\
    \ namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/Algebra/algebra.hpp
  requiredBy:
  - algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp
  - algorithm/DataStructure/SegmentTree/binary_indexed_tree_2d.hpp
  - algorithm/DataStructure/SegmentTree/lazy_segment_tree.hpp
  - algorithm/DataStructure/SegmentTree/sparse_table.hpp
  - algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
  - algorithm/DataStructure/SegmentTree/segment_tree.hpp
  timestamp: '2025-07-03 00:41:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj-2842-binary_indexed_tree_2d.test.cpp
  - verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
  - verify/yosupo-point_add_range_sum-segment_tree.test.cpp
  - verify/aoj-DSL_2_I-lazy_segment_tree.test.cpp
  - verify/aoj-DSL_2_B-segment_tree.test.cpp
  - verify/yosupo-staticrmp-sparse_table.test.cpp
  - verify/aoj-DSL_2_H-lazy_segment_tree.test.cpp
  - verify/yosupo-range_affine_range_sum-lazy_segment_tree.test.cpp
  - verify/yosupo-vertex_add_path_sum-heavy_light_decomposition.test.cpp
  - verify/aoj-DSL_2_A-segment_tree.test.cpp
  - verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  - verify/yosupo-vertex_add_subtree_sum-heavy_light_decomposition.test.cpp
  - verify/aoj-DSL_2_F-lazy_segment_tree.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - verify/aoj-DSL_2_B-dynamic_segment_tree.test.cpp
  - verify/yosupo-point_add_range_sum-binary_indexed_tree.test.cpp
  - verify/aoj-DSL_2_G-lazy_segment_tree.test.cpp
documentation_of: algorithm/Math/Algebra/algebra.hpp
layout: document
redirect_from:
- /library/algorithm/Math/Algebra/algebra.hpp
- /library/algorithm/Math/Algebra/algebra.hpp.html
title: algorithm/Math/Algebra/algebra.hpp
---
