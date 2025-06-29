---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_A-segment_tree.test.cpp
    title: verify/aoj-DSL_2_A-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-segment_tree.test.cpp
    title: verify/aoj-DSL_2_B-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
    title: verify/yosupo-point_add_range_sum-segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
    title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/DataStructure/SegmentTree/segment_tree.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <cassert>\n#include <initializer_list>\n#include\
    \ <iostream>\n#include <iterator>\n#include <type_traits>\n#include <vector>\n\
    \n#line 1 \"lib/Math/Algebra/algebra.hpp\"\n\n\n\n#line 6 \"lib/Math/Algebra/algebra.hpp\"\
    \n#include <limits>\n#include <numeric>\n#line 9 \"lib/Math/Algebra/algebra.hpp\"\
    \n#include <utility>\n\nnamespace algorithm {\n\nnamespace algebra {\n\ntemplate\
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
    \ namespace algorithm\n\n\n#line 13 \"lib/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace segment_tree {\n\ntemplate <class Monoid>\n\
    class SegmentTree {\npublic:\n    using monoid_type = Monoid;\n    using value_type\
    \ = monoid_type::value_type;\n\nprivate:\n    int m_sz;                      \
    \   // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;                          // m_n:=(\u5B8C\
    \u5168\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    std::vector<monoid_type> m_tree;\
    \  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\n    void\
    \ update(int k) { m_tree[k] = m_tree[k << 1] * m_tree[k << 1 | 1]; }\n    void\
    \ build() {\n        for(int l = m_n >> 1, r = (m_n + m_sz - 1) >> 1; l >= 1;\
    \ l >>= 1, r >>= 1) {\n            for(int i = r; i >= l; --i) update(i);\n  \
    \      }\n    }\n\npublic:\n    // constructor. O(N).\n    SegmentTree() : SegmentTree(0)\
    \ {};\n    explicit SegmentTree(int n) : m_sz(n), m_n(1) {\n        assert(n >=\
    \ 0);\n        while(m_n < m_sz) m_n <<= 1;\n        m_tree.assign(2 * m_n, monoid_type::one());\n\
    \    }\n    explicit SegmentTree(int n, const value_type &a) : SegmentTree(n,\
    \ monoid_type(a)) {}\n    explicit SegmentTree(int n, const monoid_type &a) :\
    \ SegmentTree(n) {\n        std::fill_n(m_tree.begin() + m_n, n, a);\n       \
    \ build();\n    }\n    template <std::input_iterator InputIter>\n    explicit\
    \ SegmentTree(InputIter first, InputIter last) : m_n(1), m_tree(first, last) {\n\
    \        m_sz = m_tree.size();\n        while(m_n < m_sz) m_n <<= 1;\n       \
    \ m_tree.reserve(2 * m_n);\n        m_tree.insert(m_tree.begin(), m_n, monoid_type::one());\n\
    \        m_tree.resize(2 * m_n, monoid_type::one());\n        build();\n    }\n\
    \    template <typename T>\n    explicit SegmentTree(std::initializer_list<T>\
    \ il) : SegmentTree(il.begin(), il.end()) {}\n\n    // \u8981\u7D20\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n    //\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0E\
    O(log N).\n    void set(int k, const value_type &a) { set(k, monoid_type(a));\
    \ }\n    void set(int k, const monoid_type &a) {\n        assert(0 <= k and k\
    \ < size());\n        k += m_n;\n        m_tree[k] = a;\n        while(k >>= 1)\
    \ update(k);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0EO(1).\n    value_type prod(int k) const {\n        assert(0 <= k and\
    \ k < size());\n        return m_tree[k + m_n].value();\n    }\n    // \u533A\u9593\
    [l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n\
    \    value_type prod(int l, int r) const {\n        assert(0 <= l and l <= r and\
    \ r <= size());\n        monoid_type &&val_l = monoid_type::one(), &&val_r = monoid_type::one();\n\
    \        for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1) {\n            if(l\
    \ & 1) val_l = val_l * m_tree[l++];\n            if(r & 1) val_r = m_tree[--r]\
    \ * val_r;\n        }\n        return (val_l * val_r).value();\n    }\n    //\
    \ \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(1).\n    value_type prod_all() const { return m_tree[1].value();\
    \ }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\
    \u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\
    \u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n    template\
    \ <bool (*pred)(value_type)>\n    int most_right(int l) const {\n        return\
    \ most_right(l, [](const value_type &x) -> bool { return pred(x); });\n    }\n\
    \    template <typename Pred>\n    int most_right(int l, Pred pred) const {\n\
    \        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        assert(0 <= l and l <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        if(l == m_sz) return m_sz;\n        l += m_n;\n        monoid_type &&val\
    \ = monoid_type::one();\n        do {\n            while(!(l & 1)) l >>= 1;\n\
    \            monoid_type &&tmp = val * m_tree[l];\n            if(!pred(tmp.value()))\
    \ {\n                while(l < m_n) {\n                    l <<= 1;\n        \
    \            tmp = val * m_tree[l];\n                    if(pred(tmp.value()))\
    \ val = tmp, ++l;\n                }\n                return l - m_n;\n      \
    \      }\n            val = tmp, ++l;\n        } while((l & -l) != l);\n     \
    \   return m_sz;\n    }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\
    \u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\
    \uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\u7D20\u306F\
    pred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\
    \u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\
    \uFF0EO(log N).\n    template <bool (*pred)(value_type)>\n    int most_left(int\
    \ r) const {\n        return most_left(r, [](const value_type &x) -> bool { return\
    \ pred(x); });\n    }\n    template <typename Pred>\n    int most_left(int r,\
    \ Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        assert(0 <= r and r <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        if(r == 0) return 0;\n        r += m_n;\n        monoid_type &&val =\
    \ monoid_type::one();\n        do {\n            --r;\n            while(r > 1\
    \ and (r & 1)) r >>= 1;\n            monoid_type &&tmp = m_tree[r] * val;\n  \
    \          if(!pred(tmp.value())) {\n                while(r < m_n) {\n      \
    \              r = r << 1 | 1;\n                    tmp = m_tree[r] * val;\n \
    \                   if(pred(tmp.value())) val = tmp, --r;\n                }\n\
    \                return r + 1 - m_n;\n            }\n            val = tmp;\n\
    \        } while((r & -r) != r);\n        return 0;\n    }\n    void reset() {\
    \ std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, monoid_type::one());\
    \ }\n\n    friend std::ostream &operator<<(std::ostream &os, const SegmentTree\
    \ &rhs) {\n        os << \"[\\n\";\n        for(int l = 1, r = 2; r <= 2 * rhs.m_n;\
    \ l <<= 1, r <<= 1) {\n            for(int i = l; i < r; ++i) os << (i == l ?\
    \ \"  [\" : \" \") << rhs.m_tree[i].value();\n            os << \"]\\n\";\n  \
    \      }\n        return os << \"]\";\n    }\n};\n\ntemplate <typename S>\nusing\
    \ range_minimum_segment_tree = SegmentTree<algebra::monoid::minimum<S>>;\n\ntemplate\
    \ <typename S>\nusing range_maximum_segment_tree = SegmentTree<algebra::monoid::maximum<S>>;\n\
    \ntemplate <typename S>\nusing range_sum_segment_tree = SegmentTree<algebra::monoid::addition<S>>;\n\
    \n}  // namespace segment_tree\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SEGMENT_TREE_HPP\n#define ALGORITHM_SEGMENT_TREE_HPP 1\n\
    \n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n#include\
    \ <iostream>\n#include <iterator>\n#include <type_traits>\n#include <vector>\n\
    \n#include \"../../Math/Algebra/algebra.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ segment_tree {\n\ntemplate <class Monoid>\nclass SegmentTree {\npublic:\n  \
    \  using monoid_type = Monoid;\n    using value_type = monoid_type::value_type;\n\
    \nprivate:\n    int m_sz;                         // m_sz:=(\u8981\u7D20\u6570\
    ).\n    int m_n;                          // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\
    \u306E\u8449\u6570).\n    std::vector<monoid_type> m_tree;  // m_tree(2n)[]:=(\u5B8C\
    \u5168\u4E8C\u5206\u6728). 1-based index.\n\n    void update(int k) { m_tree[k]\
    \ = m_tree[k << 1] * m_tree[k << 1 | 1]; }\n    void build() {\n        for(int\
    \ l = m_n >> 1, r = (m_n + m_sz - 1) >> 1; l >= 1; l >>= 1, r >>= 1) {\n     \
    \       for(int i = r; i >= l; --i) update(i);\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    SegmentTree() : SegmentTree(0) {};\n    explicit\
    \ SegmentTree(int n) : m_sz(n), m_n(1) {\n        assert(n >= 0);\n        while(m_n\
    \ < m_sz) m_n <<= 1;\n        m_tree.assign(2 * m_n, monoid_type::one());\n  \
    \  }\n    explicit SegmentTree(int n, const value_type &a) : SegmentTree(n, monoid_type(a))\
    \ {}\n    explicit SegmentTree(int n, const monoid_type &a) : SegmentTree(n) {\n\
    \        std::fill_n(m_tree.begin() + m_n, n, a);\n        build();\n    }\n \
    \   template <std::input_iterator InputIter>\n    explicit SegmentTree(InputIter\
    \ first, InputIter last) : m_n(1), m_tree(first, last) {\n        m_sz = m_tree.size();\n\
    \        while(m_n < m_sz) m_n <<= 1;\n        m_tree.reserve(2 * m_n);\n    \
    \    m_tree.insert(m_tree.begin(), m_n, monoid_type::one());\n        m_tree.resize(2\
    \ * m_n, monoid_type::one());\n        build();\n    }\n    template <typename\
    \ T>\n    explicit SegmentTree(std::initializer_list<T> il) : SegmentTree(il.begin(),\
    \ il.end()) {}\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\
    \u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(log N).\n    void set(int k,\
    \ const value_type &a) { set(k, monoid_type(a)); }\n    void set(int k, const\
    \ monoid_type &a) {\n        assert(0 <= k and k < size());\n        k += m_n;\n\
    \        m_tree[k] = a;\n        while(k >>= 1) update(k);\n    }\n    // k\u756A\
    \u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type\
    \ prod(int k) const {\n        assert(0 <= k and k < size());\n        return\
    \ m_tree[k + m_n].value();\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    value_type prod(int l,\
    \ int r) const {\n        assert(0 <= l and l <= r and r <= size());\n       \
    \ monoid_type &&val_l = monoid_type::one(), &&val_r = monoid_type::one();\n  \
    \      for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1) {\n            if(l &\
    \ 1) val_l = val_l * m_tree[l++];\n            if(r & 1) val_r = m_tree[--r] *\
    \ val_r;\n        }\n        return (val_l * val_r).value();\n    }\n    // \u533A\
    \u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0EO(1).\n    value_type prod_all() const { return m_tree[1].value();\
    \ }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\
    \u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\
    \u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n    template\
    \ <bool (*pred)(value_type)>\n    int most_right(int l) const {\n        return\
    \ most_right(l, [](const value_type &x) -> bool { return pred(x); });\n    }\n\
    \    template <typename Pred>\n    int most_right(int l, Pred pred) const {\n\
    \        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        assert(0 <= l and l <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        if(l == m_sz) return m_sz;\n        l += m_n;\n        monoid_type &&val\
    \ = monoid_type::one();\n        do {\n            while(!(l & 1)) l >>= 1;\n\
    \            monoid_type &&tmp = val * m_tree[l];\n            if(!pred(tmp.value()))\
    \ {\n                while(l < m_n) {\n                    l <<= 1;\n        \
    \            tmp = val * m_tree[l];\n                    if(pred(tmp.value()))\
    \ val = tmp, ++l;\n                }\n                return l - m_n;\n      \
    \      }\n            val = tmp, ++l;\n        } while((l & -l) != l);\n     \
    \   return m_sz;\n    }\n    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\
    \u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\
    \uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\u7D20\u306F\
    pred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\
    \u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\
    \uFF0EO(log N).\n    template <bool (*pred)(value_type)>\n    int most_left(int\
    \ r) const {\n        return most_left(r, [](const value_type &x) -> bool { return\
    \ pred(x); });\n    }\n    template <typename Pred>\n    int most_left(int r,\
    \ Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred, value_type>::value);\n\
    \        assert(0 <= r and r <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        if(r == 0) return 0;\n        r += m_n;\n        monoid_type &&val =\
    \ monoid_type::one();\n        do {\n            --r;\n            while(r > 1\
    \ and (r & 1)) r >>= 1;\n            monoid_type &&tmp = m_tree[r] * val;\n  \
    \          if(!pred(tmp.value())) {\n                while(r < m_n) {\n      \
    \              r = r << 1 | 1;\n                    tmp = m_tree[r] * val;\n \
    \                   if(pred(tmp.value())) val = tmp, --r;\n                }\n\
    \                return r + 1 - m_n;\n            }\n            val = tmp;\n\
    \        } while((r & -r) != r);\n        return 0;\n    }\n    void reset() {\
    \ std::fill(m_tree.begin() + 1, m_tree.begin() + m_n + m_sz, monoid_type::one());\
    \ }\n\n    friend std::ostream &operator<<(std::ostream &os, const SegmentTree\
    \ &rhs) {\n        os << \"[\\n\";\n        for(int l = 1, r = 2; r <= 2 * rhs.m_n;\
    \ l <<= 1, r <<= 1) {\n            for(int i = l; i < r; ++i) os << (i == l ?\
    \ \"  [\" : \" \") << rhs.m_tree[i].value();\n            os << \"]\\n\";\n  \
    \      }\n        return os << \"]\";\n    }\n};\n\ntemplate <typename S>\nusing\
    \ range_minimum_segment_tree = SegmentTree<algebra::monoid::minimum<S>>;\n\ntemplate\
    \ <typename S>\nusing range_maximum_segment_tree = SegmentTree<algebra::monoid::maximum<S>>;\n\
    \ntemplate <typename S>\nusing range_sum_segment_tree = SegmentTree<algebra::monoid::addition<S>>;\n\
    \n}  // namespace segment_tree\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - lib/Math/Algebra/algebra.hpp
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/segment_tree.hpp
  requiredBy: []
  timestamp: '2025-06-14 20:38:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo-point_add_range_sum-segment_tree.test.cpp
  - verify/aoj-DSL_2_B-segment_tree.test.cpp
  - verify/aoj-DSL_2_A-segment_tree.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
documentation_of: lib/DataStructure/SegmentTree/segment_tree.hpp
layout: document
title: Segment Tree
---


## 概要

任意のモノイドを扱う「抽象セグメント木」．

あるモノイド $(S, \bullet: S \times S \rightarrow S, e \in S)$ において，長さ $N$ の要素列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対する次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新**：要素 $a_i$ を $x$ で更新する
- **区間取得**：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する

ここで「モノイド (monoid)」とは，次の性質を満たす組 $(S, \bullet : S \times S \rightarrow S, e \in S)$ による代数的構造のことをいう．

1. 結合律：$(a \bullet b) \bullet c = a \bullet (b \bullet c) \quad (\forall a, \forall b, \forall c \in S)$
1. 単位元の存在：$e \bullet a = a \bullet e = a \quad (e \in S, \forall a \in S)$

例えば，自然数全体 $\mathbb{N}$ は加法に関して $0$ を単位元にもつモノイドを成す．


## 説明

### algorithm::segment_tree::SegmentTree<Monoid>

|テンプレート引数|説明|
|---|---|
|`Monoid`|モノイドの型．`algorithm::algebra::Monoid` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`SegmentTree()`|デフォルトコンストラクタ．サイズゼロの `SegmentTree` オブジェクトを構築する．|-|
|`SegmentTree(n)`|コンストラクタ．`n` 個の単位元 `Monoid::one()` で初期化された要素をもつ `SegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`SegmentTree(n,a)`|コンストラクタ．`n` 個の `a` で初期化された要素をもつ `SegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`SegmentTree(first,last)`|コンストラクタ．イテレータ範囲 `[first,last)` の要素を用いて `SegmentTree` オブジェクトを構築する．|$\Theta(N)$|
|`SegmentTree(il)`|初期化子リスト `il` を受け取るコンストラクタ．`SegmentTree(il.begin(),il.end())` と等価．|$\Theta(N)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`set(k,a)`|`k` 番目の要素を `a` に置き換える．|$\Theta(\log N)$|
|`x=prod(k)`|`k` 番目の要素 `x` を取得する．|$\mathcal{O}(1)$|
|`x=prod(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log N)$|
|`x=prod_all()`|区間全体の要素の総積 `x` を求める．|$\mathcal{O}(1)$|
|`r=most_right(l,pred)`|`pred(prod(l,r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log N)$|
|`l=most_left(r,pred)`|`pred(prod(l,r))==true` となる区間の最左位置 `l` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log N)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(N)$|


## 参考

1. "SegTree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/segtree.html>.
1. "モノイド". Wikipedia. <https://ja.wikipedia.org/wiki/モノイド>.
1. rsk0315. "セグ木のお勉強を敬遠している人へ". えびちゃんの日記. HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/07/05/184929>.
1. "セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree>.
