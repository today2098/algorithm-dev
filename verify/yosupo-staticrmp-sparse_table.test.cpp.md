---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/sparse_table.hpp
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo-staticrmp-sparse_table.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\n\n\n#include <cassert>\n#include <initializer_list>\n#line 7 \"algorithm/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n#include <iterator>\n#include <ranges>\n#line 10 \"algorithm/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\n#line 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"algorithm/Math/Algebra/algebra.hpp\"\n#include <limits>\n#include <numeric>\n\
    #include <type_traits>\n#include <utility>\n\nnamespace algorithm {\n\nnamespace\
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
    \n}  // namespace algebra\n\n}  // namespace algorithm\n\n\n#line 12 \"algorithm/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <class IdempotentSemigroup>\nclass SparseTableBase\
    \ {\npublic:\n    using semigroup_type = IdempotentSemigroup;\n    using value_type\
    \ = typename semigroup_type::value_type;\n    using size_type = std::size_t;\n\
    \nprivate:\n    size_type m_sz;                                    // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<size_type> m_lg;                       // m_lg[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<semigroup_type>> m_table;  // m_table[k][l]:=(\u533A\
    \u9593[l,l+2^k)\u306E\u7DCF\u7A4D).\n\npublic:\n    // constructor. O(N log N).\n\
    \    SparseTableBase() : m_sz(0), m_lg({0}), m_table({{}}) {}\n    template <std::input_iterator\
    \ InputIter>\n    explicit SparseTableBase(InputIter first, InputIter last) :\
    \ m_table(1, std::vector<semigroup_type>(first, last)) {\n        m_sz = m_table[0].size();\n\
    \        m_lg.assign(m_sz + 1, 0);\n        for(size_type i = 2; i <= m_sz; ++i)\
    \ m_lg[i] = m_lg[i >> 1] + 1;\n        m_table.resize(m_lg[m_sz] + 1);\n     \
    \   for(size_type k = 1; k <= m_lg[m_sz]; ++k) {\n            size_type n = m_sz\
    \ - (1U << k) + 1;\n            m_table[k].resize(n);\n            for(size_type\
    \ i = 0; i < n; ++i) m_table[k][i] = m_table[k - 1][i] * m_table[k - 1][i + (1U\
    \ << (k - 1))];\n        }\n    }\n    template <std::ranges::input_range R>\n\
    \    explicit SparseTableBase(R &&r) : SparseTableBase(std::ranges::begin(r),\
    \ std::ranges::end(r)) {}\n    template <typename T>\n    explicit SparseTableBase(std::initializer_list<T>\
    \ il) : SparseTableBase(il.begin(), il.end()) {}\n\n    // \u8981\u7D20\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0E\n    size_type size() const { return m_sz; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n\
    \    semigroup_type prod(size_type k) const {\n        assert(k < size());\n \
    \       return m_table[0][k];\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    semigroup_type prod(size_type\
    \ l, size_type r) const {\n        assert(l < r and r <= size());\n        size_type\
    \ k = m_lg[r - l];\n        return m_table[k][l] * m_table[k][r - (1U << k)];\n\
    \    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\
    \u6C42\u3081\u308B\uFF0EO(1).\n    semigroup_type prod_all() const {\n       \
    \ assert(size() > 0);\n        return m_table.back().front() * m_table.back().back();\n\
    \    }\n\n    friend std::ostream &operator<<(std::ostream &os, const SparseTableBase\
    \ &rhs) {\n        if(rhs.m_sz == 0) return os << \"[\\n]\";\n        os << \"\
    [\\n\";\n        for(size_type k = 0; k <= rhs.m_lg.back(); ++k) {\n         \
    \   for(int i = 0, end = rhs.m_table[k].size(); i < end; ++i) os << (i == 0 ?\
    \ \"  [\" : \" \") << rhs.m_table[k][i];\n            os << \"]\\n\";\n      \
    \  }\n        return os << \"]\";\n    }\n};\n\ntemplate <typename S, class IdempotentSemigroup>\n\
    class SparseTable : public SparseTableBase<IdempotentSemigroup> {\npublic:\n \
    \   using base_type = SparseTableBase<IdempotentSemigroup>;\n    using typename\
    \ base_type::semigroup_type;\n    using typename base_type::size_type;\n    using\
    \ value_type = S;\n\n    // constructor. O(N log N).\n    SparseTable() : base_type()\
    \ {}\n    template <std::input_iterator InputIter>\n    explicit SparseTable(InputIter\
    \ first, InputIter last) : base_type(first, last) {}\n    template <std::ranges::input_range\
    \ R>\n    explicit SparseTable(R &&r) : base_type(std::forward<R>(r)) {}\n   \
    \ template <typename T>\n    explicit SparseTable(std::initializer_list<T> il)\
    \ : base_type(std::move(il)) {}\n\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(size_type k) const {\
    \ return base_type::prod(k).value(); }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\uFF0EO(1).\n    value_type prod(size_type\
    \ l, size_type r) const { return base_type::prod(l, r).value(); }\n    // \u533A\
    \u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\
    \uFF0EO(1).\n    value_type prod_all() const { return base_type::prod_all().value();\
    \ }\n};\n\ntemplate <typename S>\nusing RangeMinimumSparseTable = SparseTable<S,\
    \ algebra::Semigroup<S, algebra::binary_operator::min<S>>>;\n\ntemplate <typename\
    \ S>\nusing RangeMaximumSparseTable = SparseTable<S, algebra::Semigroup<S, algebra::binary_operator::max<S>>>;\n\
    \ntemplate <typename S>\nusing RangeGcdSparseTable = SparseTable<S, algebra::Semigroup<S,\
    \ algebra::binary_operator::gcd<S>>>;\n\ntemplate <typename S>\nusing RangeLcmSparseTable\
    \ = SparseTable<S, algebra::Semigroup<S, algebra::binary_operator::lcm<S>>>;\n\
    \n}  // namespace algorithm\n\n\n#line 7 \"verify/yosupo-staticrmp-sparse_table.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::RangeMinimumSparseTable<int>\
    \ table(a);\n\n    while(q--) {\n        int l, r;\n        std::cin >> l >> r;\n\
    \n        auto ans = table.prod(l, r);\n        std::cout << ans << \"\\n\";\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../algorithm/DataStructure/SegmentTree/sparse_table.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &elem : a) std::cin >> elem;\n\n    algorithm::RangeMinimumSparseTable<int>\
    \ table(a);\n\n    while(q--) {\n        int l, r;\n        std::cin >> l >> r;\n\
    \n        auto ans = table.prod(l, r);\n        std::cout << ans << \"\\n\";\n\
    \    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/sparse_table.hpp
  - algorithm/Math/Algebra/algebra.hpp
  isVerificationFile: true
  path: verify/yosupo-staticrmp-sparse_table.test.cpp
  requiredBy: []
  timestamp: '2025-08-10 17:13:26+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-staticrmp-sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-staticrmp-sparse_table.test.cpp
- /verify/verify/yosupo-staticrmp-sparse_table.test.cpp.html
title: verify/yosupo-staticrmp-sparse_table.test.cpp
---
