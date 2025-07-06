---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/DataStructure/SegmentTree/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint_base.hpp
    title: "Modint\u69CB\u9020\u4F53\u306E\u57FA\u5E95\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/yosupo-point_set_range_composite-segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#line 1 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    #line 8 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\n#include <iterator>\n\
    #include <type_traits>\n#include <vector>\n\n#line 1 \"algorithm/Math/Algebra/algebra.hpp\"\
    \n\n\n\n#line 6 \"algorithm/Math/Algebra/algebra.hpp\"\n#include <limits>\n#include\
    \ <numeric>\n#line 9 \"algorithm/Math/Algebra/algebra.hpp\"\n#include <utility>\n\
    \nnamespace algorithm {\n\nnamespace algebra {\n\ntemplate <typename S>\nclass\
    \ Set {\npublic:\n    using value_type = S;\n\nprotected:\n    value_type val;\n\
    \npublic:\n    constexpr Set() : val() {}\n    constexpr Set(const value_type\
    \ &val) : val(val) {}\n    constexpr Set(value_type &&val) : val(std::move(val))\
    \ {}\n\n    friend constexpr bool operator==(const Set &lhs, const Set &rhs) {\
    \ return lhs.value() == rhs.value(); }\n    friend std::istream &operator>>(std::istream\
    \ &is, Set &rhs) { return is >> rhs.val; }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Set &rhs) { return os << rhs.value(); }\n\n    constexpr value_type\
    \ value() const { return val; }\n};\n\ntemplate <typename S, auto op>\nclass Semigroup\
    \ : public Set<S> {\n    static_assert(std::is_invocable_r<S, decltype(op), S,\
    \ S>::value);\n\npublic:\n    using base_type = Set<S>;\n    using value_type\
    \ = typename base_type::value_type;\n\n    constexpr Semigroup() : base_type()\
    \ {}\n    constexpr Semigroup(const value_type &val) : base_type(val) {}\n   \
    \ constexpr Semigroup(value_type &&val) : base_type(std::move(val)) {}\n\n   \
    \ friend constexpr Semigroup operator*(const Semigroup &lhs, const Semigroup &rhs)\
    \ { return Semigroup(op(lhs.value(), rhs.value())); }\n\n    static constexpr\
    \ auto get_op() { return op; }\n};\n\ntemplate <typename S, auto op, auto e>\n\
    class Monoid : public Semigroup<S, op> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(e)>::value);\n\npublic:\n    using base_type = Semigroup<S, op>;\n\
    \    using value_type = typename base_type::value_type;\n\n    constexpr Monoid()\
    \ : base_type() {}\n    constexpr Monoid(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Monoid(value_type &&val) : base_type(std::move(val)) {}\n\n\
    \    friend constexpr Monoid operator*(const Monoid &lhs, const Monoid &rhs) {\
    \ return Monoid(op(lhs.value(), rhs.value())); }\n\n    static constexpr auto\
    \ get_e() { return e; }\n    static constexpr Monoid one() { return Monoid(e());\
    \ }  // return identity element.\n};\n\ntemplate <typename S, auto op, auto e,\
    \ auto inverse>\nclass Group : public Monoid<S, op, e> {\n    static_assert(std::is_invocable_r<S,\
    \ decltype(inverse), S>::value);\n\npublic:\n    using base_type = Monoid<S, op,\
    \ e>;\n    using value_type = typename base_type::value_type;\n\n    constexpr\
    \ Group() : base_type() {}\n    constexpr Group(const value_type &val) : base_type(val)\
    \ {}\n    constexpr Group(value_type &&val) : base_type(std::move(val)) {}\n\n\
    \    friend constexpr Group operator*(const Group &lhs, const Group &rhs) { return\
    \ Group(op(lhs.value(), rhs.value())); }\n\n    static constexpr auto get_inverse()\
    \ { return inverse; }\n    static constexpr Group one() { return Group(e()); }\
    \                    // return identity element.\n    constexpr Group inv() const\
    \ { return Group(inverse(this->value())); }  // return inverse element.\n};\n\n\
    template <typename F, auto compose, auto id, typename X, auto mapping>\nclass\
    \ OperatorMonoid : public Monoid<F, compose, id> {\n    static_assert(std::is_invocable_r<X,\
    \ decltype(mapping), F, X>::value);\n\npublic:\n    using base_type = Monoid<F,\
    \ compose, id>;\n    using value_type = typename base_type::value_type;\n    using\
    \ acted_type = X;\n\n    constexpr OperatorMonoid() : base_type() {}\n    constexpr\
    \ OperatorMonoid(const value_type &val) : base_type(val) {}\n    constexpr OperatorMonoid(value_type\
    \ &&val) : base_type(std::move(val)) {}\n\n    friend constexpr OperatorMonoid\
    \ operator*(const OperatorMonoid &lhs, const OperatorMonoid &rhs) { return OperatorMonoid(compose(lhs.value(),\
    \ rhs.value())); }\n\n    static constexpr auto get_mapping() { return mapping;\
    \ }\n    static constexpr OperatorMonoid one() { return OperatorMonoid(id());\
    \ }  // return identity mapping.\n    constexpr acted_type act(const acted_type\
    \ &x) const { return mapping(this->value(), x); }\n    template <class S>\n  \
    \  constexpr S act(const S &x) const {\n        static_assert(std::is_base_of<Set<acted_type>,\
    \ S>::value);\n        return S(mapping(this->value(), x.value()));\n    }\n};\n\
    \nnamespace element {\n\ntemplate <typename S>\nconstexpr auto zero = []() ->\
    \ S { return S(); };\n\ntemplate <typename S>\nconstexpr auto one = []() -> S\
    \ { return 1; };\n\ntemplate <typename S>\nconstexpr auto min = []() -> S { return\
    \ std::numeric_limits<S>::min(); };\n\ntemplate <typename S>\nconstexpr auto max\
    \ = []() -> S { return std::numeric_limits<S>::max(); };\n\ntemplate <typename\
    \ S>\nconstexpr auto one_below_max = []() -> S { return std::numeric_limits<S>::max()\
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
    \n}  // namespace algebra\n\n}  // namespace algorithm\n\n\n#line 13 \"algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
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
    \n}  // namespace segment_tree\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/ModularArithmetic/modint.hpp\"\
    \n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n\n#line 1 \"\
    algorithm/Math/ModularArithmetic/modint_base.hpp\"\n\n\n\n#line 5 \"algorithm/Math/ModularArithmetic/modint_base.hpp\"\
    \n\nnamespace algorithm {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing\
    \ is_modint = std::is_base_of<ModintBase, T>;\n\ntemplate <class T>\ninline constexpr\
    \ bool is_modint_v = is_modint<T>::value;\n\n}  // namespace algorithm\n\n\n#line\
    \ 8 \"algorithm/Math/ModularArithmetic/modint.hpp\"\n\nnamespace algorithm {\n\
    \ntemplate <int mod>\nclass Modint : ModintBase {\n    static_assert(mod >= 1);\n\
    \n    long long val;\n\n    constexpr void normalize() {\n        if(val < -mod\
    \ or mod <= val) val %= mod;\n        if(val < 0) val += mod;\n    }\n\npublic:\n\
    \    constexpr Modint() : val(0) {}\n    constexpr Modint(long long val) : val(val)\
    \ {\n        normalize();\n    }\n\n    constexpr Modint operator+() const { return\
    \ Modint(*this); }\n    constexpr Modint operator-() const {\n        if(val ==\
    \ 0) Modint();\n        Modint res = *this;\n        res.val = mod - res.val;\n\
    \        return res;\n    }\n    constexpr Modint &operator++() {\n        val++;\n\
    \        if(val == mod) val = 0;\n        return *this;\n    }\n    constexpr\
    \ Modint &operator--() {\n        if(val == 0) val = mod;\n        val--;\n  \
    \      return *this;\n    }\n    constexpr Modint operator++(int) {\n        Modint\
    \ res = *this;\n        ++(*this);\n        return res;\n    }\n    constexpr\
    \ Modint operator--(int) {\n        Modint res = *this;\n        --(*this);\n\
    \        return res;\n    }\n    constexpr Modint &operator+=(const Modint &rhs)\
    \ {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs) {\n     \
    \   val -= rhs.val;\n        if(val < 0) val += mod;\n        return *this;\n\
    \    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n        val = val\
    \ * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint &operator/=(const\
    \ Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend constexpr bool operator==(const\
    \ Modint &lhs, const Modint &rhs) { return lhs.val == rhs.val; }\n    friend constexpr\
    \ Modint operator+(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ += rhs; }\n    friend constexpr Modint operator-(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr Modint operator*(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) *= rhs; }\n    friend constexpr\
    \ Modint operator/(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ /= rhs; }\n    friend std::istream &operator>>(std::istream &is, Modint &rhs)\
    \ {\n        is >> rhs.val;\n        rhs.normalize();\n        return is;\n  \
    \  }\n    friend std::ostream &operator<<(std::ostream &os, const Modint &rhs)\
    \ { return os << rhs.val; }\n\n    static constexpr int modulus() { return mod;\
    \ }\n    constexpr long long value() const { return val; }\n    constexpr Modint\
    \ inv() const {\n        long long a = mod, b = val, u = 0, v = 1;\n        while(b\
    \ != 0) {\n            long long t = a / b;\n            a -= b * t, u -= v *\
    \ t;\n            std::swap(a, b), std::swap(u, v);\n        }\n        return\
    \ Modint(u);\n    }\n    constexpr Modint pow(long long k) const {\n        if(k\
    \ < 0) return inv().pow(-k);\n        Modint res = 1, mul = *this;\n        while(k\
    \ > 0) {\n            if(k & 1LL) res *= mul;\n            mul *= mul;\n     \
    \       k >>= 1;\n        }\n        return res;\n    }\n\n    friend constexpr\
    \ Modint mod_inv(const Modint &a) { return a.inv(); }\n    friend constexpr Modint\
    \ mod_pow(const Modint &a, long long k) { return a.pow(k); }\n};\n\nusing mint998244353\
    \ = Modint<998'244'353>;\nusing mint1000000007 = Modint<1'000'000'007>;\n\n} \
    \ // namespace algorithm\n\n\n#line 7 \"verify/yosupo-point_set_range_composite-segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = struct {\n        algorithm::mint998244353 a;\n        algorithm::mint998244353\
    \ b;\n    };\n    auto mapping = [](const S &f, algorithm::mint998244353 x) ->\
    \ algorithm::mint998244353 {\n        return f.a * x + f.b;\n    };\n\n    std::vector<S>\
    \ v(n);\n    for(auto &elem : v) std::cin >> elem.a >> elem.b;\n\n    constexpr\
    \ auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b\
    \ * rhs.a + rhs.b}; };\n    constexpr auto e = []() -> S { return {1, 0}; };\n\
    \    using monoid = algorithm::algebra::Monoid<S, op, e>;\n    algorithm::segment_tree::SegmentTree<monoid>\
    \ segtree(v.cbegin(), v.cend());\n\n    while(q--) {\n        int t;\n       \
    \ std::cin >> t;\n\n        if(t == 0) {\n            int p;\n            algorithm::mint998244353\
    \ c, d;\n            std::cin >> p >> c >> d;\n\n            segtree.set(p, {c,\
    \ d});\n        } else {\n            int l, r;\n            int x;\n        \
    \    std::cin >> l >> r >> x;\n\n            auto &&f = segtree.prod(l, r);\n\
    \            auto &&ans = mapping(f, x);\n            std::cout << ans << \"\\\
    n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#include \"../algorithm/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n#include \"../algorithm/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n\
    \    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using S = struct {\n \
    \       algorithm::mint998244353 a;\n        algorithm::mint998244353 b;\n   \
    \ };\n    auto mapping = [](const S &f, algorithm::mint998244353 x) -> algorithm::mint998244353\
    \ {\n        return f.a * x + f.b;\n    };\n\n    std::vector<S> v(n);\n    for(auto\
    \ &elem : v) std::cin >> elem.a >> elem.b;\n\n    constexpr auto op = [](const\
    \ S &lhs, const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b * rhs.a + rhs.b};\
    \ };\n    constexpr auto e = []() -> S { return {1, 0}; };\n    using monoid =\
    \ algorithm::algebra::Monoid<S, op, e>;\n    algorithm::segment_tree::SegmentTree<monoid>\
    \ segtree(v.cbegin(), v.cend());\n\n    while(q--) {\n        int t;\n       \
    \ std::cin >> t;\n\n        if(t == 0) {\n            int p;\n            algorithm::mint998244353\
    \ c, d;\n            std::cin >> p >> c >> d;\n\n            segtree.set(p, {c,\
    \ d});\n        } else {\n            int l, r;\n            int x;\n        \
    \    std::cin >> l >> r >> x;\n\n            auto &&f = segtree.prod(l, r);\n\
    \            auto &&ans = mapping(f, x);\n            std::cout << ans << \"\\\
    n\";\n        }\n    }\n}\n"
  dependsOn:
  - algorithm/DataStructure/SegmentTree/segment_tree.hpp
  - algorithm/Math/Algebra/algebra.hpp
  - algorithm/Math/ModularArithmetic/modint.hpp
  - algorithm/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-07-06 12:46:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_set_range_composite-segment_tree.test.cpp
- /verify/verify/yosupo-point_set_range_composite-segment_tree.test.cpp.html
title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
---
