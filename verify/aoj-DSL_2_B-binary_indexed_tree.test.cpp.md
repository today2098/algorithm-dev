---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #include <iterator>\n#include <ranges>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#line\
    \ 6 \"algorithm/Math/Algebra/algebra.hpp\"\n#include <limits>\n#include <numeric>\n\
    #line 10 \"algorithm/Math/Algebra/algebra.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ algebra {\n\ntemplate <typename S>\nclass Set {\npublic:\n    using value_type\
    \ = S;\n\nprotected:\n    value_type val;\n\npublic:\n    constexpr Set() : val()\
    \ {}\n    constexpr Set(const value_type &val) : val(val) {}\n    constexpr Set(value_type\
    \ &&val) : val(std::move(val)) {}\n\n    friend constexpr bool operator==(const\
    \ Set &lhs, const Set &rhs) { return lhs.val == rhs.val; }\n    friend std::istream\
    \ &operator>>(std::istream &is, Set &rhs) { return is >> rhs.val; }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Set &rhs) { return os << rhs.val;\
    \ }\n\n    constexpr value_type value() const { return val; }\n};\n\ntemplate\
    \ <typename S, auto op>\nclass Semigroup : public Set<S> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(op), S, S>::value);\n\npublic:\n    using base_type = Set<S>;\n   \
    \ using value_type = typename base_type::value_type;\n\n    constexpr Semigroup()\
    \ : base_type() {}\n    constexpr Semigroup(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}\n\
    \n    friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup\
    \ &rhs) { return Semigroup(op(lhs.val, rhs.val)); }\n\n    static constexpr auto\
    \ get_op() { return op; }\n};\n\ntemplate <typename S, auto op, auto e>\nclass\
    \ Monoid : public Semigroup<S, op> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(e)>::value);\n\npublic:\n    using base_type = Semigroup<S, op>;\n\
    \    using value_type = typename base_type::value_type;\n\n    constexpr Monoid()\
    \ : base_type() {}\n    constexpr Monoid(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Monoid(value_type &&val) : base_type(std::move(val)) {}\n\n\
    \    friend constexpr Monoid operator*(const Monoid &lhs, const Monoid &rhs) {\
    \ return Monoid(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_e()\
    \ { return e; }\n    static constexpr Monoid one() { return Monoid(e()); }  //\
    \ return identity element.\n};\n\ntemplate <typename S, auto op, auto e, auto\
    \ inverse>\nclass Group : public Monoid<S, op, e> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(inverse), S>::value);\n\npublic:\n    using base_type = Monoid<S, op,\
    \ e>;\n    using value_type = typename base_type::value_type;\n\n    constexpr\
    \ Group() : base_type() {}\n    constexpr Group(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Group(value_type &&val) : base_type(std::move(val)) {}\n\n\
    \    friend constexpr Group operator*(const Group &lhs, const Group &rhs) { return\
    \ Group(op(lhs.val, rhs.val)); }\n\n    static constexpr auto get_inverse() {\
    \ return inverse; }\n    static constexpr Group one() { return Group(e()); } \
    \                    // return identity element.\n    constexpr Group inv() const\
    \ { return Group(inverse(base_type::val)); }  // return inverse element.\n};\n\
    \ntemplate <typename F, auto compose, auto id, typename X, auto mapping>\nclass\
    \ OperatorMonoid : public Monoid<F, compose, id> {\n    static_assert(std::is_invocable_r<X,\
    \ decltype(mapping), F, X>::value);\n\npublic:\n    using base_type = Monoid<F,\
    \ compose, id>;\n    using value_type = typename base_type::value_type;\n    using\
    \ acted_type = X;\n\n    constexpr OperatorMonoid() : base_type() {}\n    constexpr\
    \ OperatorMonoid(const value_type &val) : base_type(val) {}\n    constexpr OperatorMonoid(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr OperatorMonoid\
    \ operator*(const OperatorMonoid &lhs, const OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.val,\
    \ rhs.val)); }\n\n    static constexpr auto get_mapping() { return mapping; }\n\
    \    static constexpr OperatorMonoid one() { return OperatorMonoid(id()); }  //\
    \ return identity mapping.\n    constexpr acted_type act(const acted_type &x)\
    \ const { return mapping(base_type::val, x); }\n    template <class S>\n    constexpr\
    \ S act(const S &x) const {\n        static_assert(std::is_base_of<Set<acted_type>,\
    \ S>::value);\n        return S(mapping(base_type::val, x.value()));\n    }\n\
    };\n\nnamespace element {\n\ntemplate <typename S>\nconstexpr auto zero = []()\
    \ -> S { return S(); };\n\ntemplate <typename S>\nconstexpr auto one = []() ->\
    \ S { return 1; };\n\ntemplate <typename S>\nconstexpr auto min = []() -> S {\
    \ return std::numeric_limits<S>::min(); };\n\ntemplate <typename S>\nconstexpr\
    \ auto max = []() -> S { return std::numeric_limits<S>::max(); };\n\ntemplate\
    \ <typename S>\nconstexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max()\
    \ - 1; };\n\ntemplate <typename S>\nconstexpr auto lowest = []() -> S { return\
    \ std::numeric_limits<S>::lowest(); };\n\ntemplate <typename S>\nconstexpr auto\
    \ one_above_lowest = []() -> S { return std::numeric_limits<S>::lowest() + 1;\
    \ };\n\n}  // namespace element\n\nnamespace unary_operator {\n\ntemplate <typename\
    \ S>\nconstexpr auto identity = [](const S &val) -> S { return val; };\n\ntemplate\
    \ <typename S>\nconstexpr auto negate = [](const S &val) -> S { return -val; };\n\
    \n}  // namespace unary_operator\n\nnamespace binary_operator {\n\ntemplate <typename\
    \ T, typename S = T>\nconstexpr auto plus = [](const T &lhs, const S &rhs) ->\
    \ S { return lhs + rhs; };\n\ntemplate <typename T, typename S = T>\nconstexpr\
    \ auto mul = [](const T &lhs, const S &rhs) -> S { return lhs * rhs; };\n\ntemplate\
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
    \ binary_operator\n\nnamespace monoid {\n\ntemplate <typename S>\nusing minimum\
    \ = Monoid<S, binary_operator::min<S>, element::max<S>>;\n\ntemplate <typename\
    \ S>\nusing minimum_safe = Monoid<S, binary_operator::min<S>, element::one_below_max<S>>;\n\
    \ntemplate <typename S>\nusing maximum = Monoid<S, binary_operator::max<S>, element::lowest<S>>;\n\
    \ntemplate <typename S>\nusing maximum_safe = Monoid<S, binary_operator::max<S>,\
    \ element::one_above_lowest<S>>;\n\ntemplate <typename S>\nusing addition = Monoid<S,\
    \ binary_operator::plus<S>, element::zero<S>>;\n\ntemplate <typename S>\nusing\
    \ multiplication = Monoid<S, binary_operator::mul<S>, element::one<S>>;\n\ntemplate\
    \ <typename S>\nusing bit_xor = Monoid<S, binary_operator::bit_xor<S>, element::zero<S>>;\n\
    \n}  // namespace monoid\n\nnamespace group {\n\ntemplate <typename S>\nusing\
    \ addition = Group<S, binary_operator::plus<S>, element::zero<S>, unary_operator::negate<S>>;\n\
    \ntemplate <typename S>\nusing bit_xor = Group<S, binary_operator::bit_xor<S>,\
    \ element::zero<S>, unary_operator::identity<S>>;\n\n}  // namespace group\n\n\
    namespace operator_monoid {\n\ntemplate <typename F, typename X = F>\nusing assign_for_minimum\
    \ = OperatorMonoid<\n    F, binary_operator::assign_if_not_id<F, element::max<F>>,\
    \ element::max<F>,\n    X, binary_operator::assign_if_not_id<F, element::max<F>,\
    \ X>>;\n\ntemplate <typename F, typename X = F>\nusing assign_for_maximum = OperatorMonoid<\n\
    \    F, binary_operator::assign_if_not_id<F, element::lowest<F>>, element::lowest<F>,\n\
    \    X, binary_operator::assign_if_not_id<F, element::lowest<F>, X>>;\n\ntemplate\
    \ <typename F, typename X = F>\nusing addition = OperatorMonoid<\n    F, binary_operator::plus<F>,\
    \ element::zero<F>,\n    X, binary_operator::plus<F, X>>;\n\n}  // namespace operator_monoid\n\
    \n}  // namespace algebra\n\n}  // namespace algorithm\n\n\n#line 14 \"algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <class AbelianGroup>\nclass BITBase {\n\
    public:\n    using group_type = AbelianGroup;\n\nprivate:\n    int m_sz;\n   \
    \ std::vector<group_type> m_tree;\n\n    static constexpr int lsb(int bit) { return\
    \ bit & -bit; }\n    group_type sum_internal(int r) const {\n        group_type\
    \ res = group_type::one();\n        for(; r >= 1; r -= lsb(r)) res = res * m_tree[r\
    \ - 1];\n        return res;\n    }\n    void build() {\n        for(int i = 1;\
    \ i < m_sz; ++i) {\n            int j = i + lsb(i);\n            if(j <= m_sz)\
    \ m_tree[j - 1] = m_tree[j - 1] * m_tree[i - 1];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BITBase() : m_sz(0) {};\n    explicit BITBase(int\
    \ n) : m_sz(n), m_tree(n, group_type::one()) {\n        assert(n >= 0);\n    }\n\
    \    explicit BITBase(int n, const group_type &a) : m_sz(n), m_tree(n, a) {\n\
    \        assert(n >= 0);\n        build();\n    }\n    template <std::input_iterator\
    \ InputIter>\n    explicit BITBase(InputIter first, InputIter last) : m_tree(first,\
    \ last) {\n        m_sz = m_tree.size();\n        build();\n    }\n    template\
    \ <std::ranges::input_range R>\n    explicit BITBase(R &&r) : BITBase(std::ranges::begin(r),\
    \ std::ranges::end(r)) {}\n    template <typename T>\n    explicit BITBase(std::initializer_list<T>\
    \ il) : BITBase(il.begin(), il.end()) {}\n    explicit BITBase(std::vector<group_type>\
    \ &&v) : m_tree(std::move(v)) {\n        m_sz = m_tree.size();\n        build();\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u3068\u306E\u7A4D\u306E\u7D50\u679C\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0E\
    O(log N).\n    void add(int k, const group_type &a) {\n        assert(0 <= k and\
    \ k < size());\n        for(int i = k + 1; i <= m_sz; i += lsb(i)) m_tree[i -\
    \ 1] = m_tree[i - 1] * a;\n    }\n    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    group_type sum(int r)\
    \ const {\n        assert(0 <= r and r <= size());\n        return sum_internal(r);\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\
    \u3081\u308B\uFF0EO(log N).\n    group_type sum(int l, int r) const {\n      \
    \  assert(0 <= l and l <= r and r <= size());\n        return sum_internal(r)\
    \ * sum_internal(l).inv();\n    }\n    // \u5168\u8981\u7D20\u306E\u7DCF\u7A4D\
    \u3092\u6C42\u3081\u308B\uFF0EO(log N).\n    group_type sum_all() const { return\
    \ sum_internal(m_sz); }\n    // pred(sum(r))==true \u3068\u306A\u308B\u533A\u9593\
    \u306E\u6700\u53F3\u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\
    \n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\
    \u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\
    \uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ N).\n    template <typename Pred>\n    int most_right(Pred pred) const {\n \
    \       static_assert(std::is_invocable_r<bool, Pred, group_type>::value);\n \
    \       assert(pred(group_type::one()));\n        int r = 0;\n        group_type\
    \ val = group_type::one();\n        for(int i = 1; i <= m_sz and pred(m_tree[i\
    \ - 1]); i <<= 1) r = i, val = m_tree[i - 1];\n        for(int len = r >> 1; len\
    \ > 0; len >>= 1) {\n            if(r + len <= m_sz and pred(val * m_tree[r +\
    \ len - 1])) {\n                r += len;\n                val = val * m_tree[r\
    \ - 1];\n            }\n        }\n        return r;\n    }\n    void reset()\
    \ { std::fill(m_tree.begin(), m_tree.end(), group_type::one()); }\n};\n\ntemplate\
    \ <typename S, class AbelianGroup>\nclass BIT : public BITBase<AbelianGroup> {\n\
    public:\n    using base_type = BITBase<AbelianGroup>;\n    using typename base_type::group_type;\n\
    \    using value_type = S;\n\n    // constructor. O(N).\n    BIT() : base_type()\
    \ {}\n    explicit BIT(int n) : base_type(n) {}\n    explicit BIT(int n, const\
    \ value_type &a) : base_type(n, a) {}\n    template <std::input_iterator InputIter>\n\
    \    explicit BIT(InputIter first, InputIter last) : base_type(first, last) {}\n\
    \    template <std::ranges::input_range R>\n    explicit BIT(R &&r) : base_type(std::forward<R>(r))\
    \ {}\n    template <typename T>\n    explicit BIT(std::initializer_list<T> il)\
    \ : base_type(std::move(il)) {}\n    explicit BIT(std::vector<group_type> &&v)\
    \ : base_type(std::move(v)) {}\n\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u3068\u306E\u7A4D\u306E\u7D50\u679C\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0E\
    O(log N).\n    void add(int k, const value_type &a) { base_type::add(k, a); }\n\
    \    // \u533A\u9593[0,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type sum(int r) const { return base_type::sum(r).value();\
    \ }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type sum(int l, int r) const { return base_type::sum(l,\
    \ r).value(); }\n    // \u5168\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type sum_all() const { return base_type::sum_all().value();\
    \ }\n    // pred(sum(r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\uFF0C\u533A\u9593[0,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\
    \u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\
    \u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n    template\
    \ <typename Pred>\n    int most_right(Pred pred) const {\n        static_assert(std::is_invocable_r<bool,\
    \ Pred, value_type>::value);\n        return base_type::most_right([&](const group_type\
    \ &x) -> bool { return pred(x.value()); });\n    }\n};\n\ntemplate <typename S>\n\
    using RangeSumBIT = BIT<S, algebra::group::addition<S>>;\n\ntemplate <typename\
    \ S>\nusing RangeXorBIT = BIT<S, algebra::group::bit_xor<S>>;\n\n}  // namespace\
    \ algorithm\n\n\n#line 6 \"verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp\"\n\
    \nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::RangeSumBIT<int>\
    \ bit(n);\n\n    while(q--) {\n        int com;\n        std::cin >> com;\n\n\
    \        if(com == 0) {\n            int x;\n            int y;\n            std::cin\
    \ >> x >> y;\n            --x;\n\n            bit.add(x, y);\n        } else {\n\
    \            int x, y;\n            std::cin >> x >> y;\n            --x;\n\n\
    \            auto ans = bit.sum(x, y);\n            std::cout << ans << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::RangeSumBIT<int>\
    \ bit(n);\n\n    while(q--) {\n        int com;\n        std::cin >> com;\n\n\
    \        if(com == 0) {\n            int x;\n            int y;\n            std::cin\
    \ >> x >> y;\n            --x;\n\n            bit.add(x, y);\n        } else {\n\
    \            int x, y;\n            std::cin >> x >> y;\n            --x;\n\n\
    \            auto ans = bit.sum(x, y);\n            std::cout << ans << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/binary_indexed_tree.hpp
  - algorithm/Math/Algebra/algebra.hpp
  isVerificationFile: true
  path: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  requiredBy: []
  timestamp: '2025-08-10 17:13:26+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
- /verify/verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp.html
title: verify/aoj-DSL_2_B-binary_indexed_tree.test.cpp
---
