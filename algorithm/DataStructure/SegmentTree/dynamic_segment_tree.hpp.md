---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/Algebra/algebra.hpp
    title: "Algebraic Structure\uFF08\u4EE3\u6570\u7684\u69CB\u9020\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
    title: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj-DSL_2_B-dynamic_segment_tree.test.cpp
    title: verify/aoj-DSL_2_B-dynamic_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <limits>\n#include <memory>\n#include <type_traits>\n#include <utility>\n\n\
    #line 1 \"algorithm/Math/Algebra/algebra.hpp\"\n\n\n\n#line 7 \"algorithm/Math/Algebra/algebra.hpp\"\
    \n#include <numeric>\n#line 10 \"algorithm/Math/Algebra/algebra.hpp\"\n\nnamespace\
    \ algorithm {\n\nnamespace algebra {\n\ntemplate <typename S>\nclass Set {\npublic:\n\
    \    using value_type = S;\n\nprotected:\n    value_type val;\n\npublic:\n   \
    \ constexpr Set() : val() {}\n    constexpr Set(const value_type &val) : val(val)\
    \ {}\n    constexpr Set(value_type &&val) : val(std::move(val)) {}\n\n    friend\
    \ constexpr bool operator==(const Set &lhs, const Set &rhs) { return lhs.value()\
    \ == rhs.value(); }\n    friend std::istream &operator>>(std::istream &is, Set\
    \ &rhs) { return is >> rhs.val; }\n    friend std::ostream &operator<<(std::ostream\
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
    \n}  // namespace algebra\n\n}  // namespace algorithm\n\n\n#line 13 \"algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace dynamic_segment_tree {\n\ntemplate <class\
    \ Monoid>\nclass DynamicSegmentTree {\npublic:\n    using monoid_type = Monoid;\n\
    \    using value_type = monoid_type::value_type;\n    using size_type = std::size_t;\n\
    \nprivate:\n    struct Node;\n    using node_pointer = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        size_type index;\n        monoid_type value;\n  \
    \      monoid_type product;\n        node_pointer left, right;\n\n        explicit\
    \ Node(size_type index, const monoid_type &value) : index(index), value(value),\
    \ product(value), left(nullptr), right(nullptr) {}\n    };\n\n    size_type m_sz;\
    \       // m_sz:=(\u8981\u7D20\u6570).\n    node_pointer m_root;  // m_root:=(\u6839\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n\n    void update(const node_pointer &p) const\
    \ {\n        const monoid_type &lhs = (p->left ? p->left->product : monoid_type::one());\n\
    \        const monoid_type &rhs = (p->right ? p->right->product : monoid_type::one());\n\
    \        p->product = lhs * p->value * rhs;\n    }\n    void set(node_pointer\
    \ &p, size_type k, monoid_type a, size_type l, size_type r) {\n        if(!p)\
    \ {\n            p = std::make_unique<Node>(k, a);\n            return;\n    \
    \    }\n        if(p->index == k) {\n            p->value = a;\n            update(p);\n\
    \            return;\n        }\n        size_type mid = l + (r - l) / 2;\n  \
    \      if(k < mid) {\n            if(p->index < k) std::swap(k, p->index), std::swap(a,\
    \ p->value);\n            set(p->left, k, a, l, mid);\n        } else {\n    \
    \        if(k < p->index) std::swap(k, p->index), std::swap(a, p->value);\n  \
    \          set(p->right, k, a, mid, r);\n        }\n        update(p);\n    }\n\
    \    monoid_type prod(const node_pointer &p, size_type k, size_type l, size_type\
    \ r) const {\n        if(!p) return monoid_type::one();\n        if(p->index ==\
    \ k) return p->value;\n        size_type mid = l + (r - l) / 2;\n        return\
    \ (k < mid ? prod(p->left, k, l, mid) : prod(p->right, k, mid, r));\n    }\n \
    \   monoid_type prod(const node_pointer &p, size_type l, size_type r, size_type\
    \ ll, size_type rr) const {\n        if(!p or r <= ll or rr <= l) return monoid_type::one();\n\
    \        if(l <= ll and rr <= r) return p->product;\n        size_type mid = ll\
    \ + (rr - ll) / 2;\n        return prod(p->left, l, r, ll, mid) * (l <= p->index\
    \ and p->index < r ? p->value : monoid_type::one()) * prod(p->right, l, r, mid,\
    \ rr);\n    }\n    template <typename Pred>\n    size_type most_right(const node_pointer\
    \ &p, size_type l, Pred pred, size_type ll, size_type rr, monoid_type &product)\
    \ const {\n        if(!p or rr <= l) return rr;\n        if(l <= ll and pred((product\
    \ * p->product).value())) {\n            product = product * p->product;\n   \
    \         return rr;\n        }\n        size_type mid = ll + (rr - ll) / 2;\n\
    \        size_type itr = most_right(p->left, l, pred, ll, mid, product);\n   \
    \     if(itr < mid) return itr;\n        if(l <= p->index) {\n            product\
    \ = product * p->value;\n            if(!pred(product.value())) return p->index;\n\
    \        }\n        return most_right(p->right, l, pred, mid, rr, product);\n\
    \    }\n    template <typename Pred>\n    size_type most_left(const node_pointer\
    \ &p, size_type r, Pred pred, size_type ll, size_type rr, monoid_type &product)\
    \ const {\n        if(!p or r <= ll) return ll;\n        if(rr <= r and pred((p->product\
    \ * product).value())) {\n            product = p->product * product;\n      \
    \      return ll;\n        }\n        size_type mid = ll + (rr - ll) / 2;\n  \
    \      size_type itr = most_left(p->right, r, pred, mid, rr, product);\n     \
    \   if(mid < itr) return itr;\n        if(p->index < r) {\n            product\
    \ = p->value * product;\n            if(!pred(product.value())) return p->index\
    \ + 1;\n        }\n        return most_left(p->left, r, pred, ll, mid, product);\n\
    \    }\n    void reset(node_pointer &p, size_type l, size_type r, size_type ll,\
    \ size_type rr) {\n        if(!p or r <= ll or rr <= l) return;\n        if(l\
    \ <= ll and rr <= r) {\n            p.reset();\n            return;\n        }\n\
    \        size_type mid = ll + (rr - ll) / 2;\n        reset(p->left, l, r, ll,\
    \ mid);\n        reset(p->right, l, r, mid, rr);\n        if(l <= p->index and\
    \ p->index < r) {\n            if(!p->left and !p->right) {\n                p.reset();\n\
    \                return;\n            }\n            p->value = monoid_type::one();\n\
    \        }\n        update(p);\n    }\n    void print(std::ostream &os, const\
    \ node_pointer &p, bool &first) const {\n        if(!p) return;\n        print(os,\
    \ p->left, first);\n        os << (first ? \"{\" : \" {\") << p->index << \",\
    \ \" << p->value << \"}\";\n        first = false;\n        print(os, p->right,\
    \ first);\n    }\n\npublic:\n    DynamicSegmentTree() : DynamicSegmentTree(std::numeric_limits<size_type>::max())\
    \ {};\n    explicit DynamicSegmentTree(size_type n) : m_sz(n), m_root(nullptr)\
    \ {}\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(log N).\n    void set(size_type k,\
    \ const value_type &a) { set(k, monoid_type(a)); }\n    void set(size_type k,\
    \ const monoid_type &a) {\n        assert(k < size());\n        set(m_root, k,\
    \ a, 0, m_sz);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(log N).\n    value_type prod(size_type k) const {\n      \
    \  assert(k < size());\n        return prod(m_root, k, 0, m_sz).value();\n   \
    \ }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type prod(size_type l, size_type r) const {\n\
    \        assert(l <= r and r <= size());\n        return prod(m_root, l, r, 0,\
    \ m_sz).value();\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod_all()\
    \ const { return (m_root ? m_root->product : monoid_type::one()).value(); }\n\
    \    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\
    \u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\
    \u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n    template\
    \ <bool (*pred)(value_type)>\n    size_type most_right(size_type l) const {\n\
    \        return most_right(l, [](const value_type &x) -> bool { return pred(x);\
    \ });\n    }\n    template <typename Pred>\n    size_type most_right(size_type\
    \ l, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ value_type>::value);\n        assert(l <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        monoid_type &&product = monoid_type::one();\n        return most_right(m_root,\
    \ l, pred, 0, m_sz, product);\n    }\n    // pred(prod(l,r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\
    \u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\
    \u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(log N).\n    template <bool (*pred)(value_type)>\n    size_type\
    \ most_left(int r) const {\n        return most_left(r, [](const value_type &x)\
    \ -> bool { return pred(x); });\n    }\n    template <typename Pred>\n    size_type\
    \ most_left(size_type r, Pred pred) const {\n        static_assert(std::is_invocable_r<bool,\
    \ Pred, value_type>::value);\n        assert(r <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        value_type &&product = monoid_type::one();\n        return most_left(m_root,\
    \ r, pred, 0, m_sz, product);\n    }\n    void reset(size_type k) { reset(m_root,\
    \ k, k + 1, 0, m_sz); }\n    void reset(size_type l, size_type r) {\n        assert(l\
    \ <= r and r <= size());\n        reset(m_root, l, r, 0, m_sz);\n    }\n    void\
    \ reset() { m_root.reset(); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const DynamicSegmentTree &rhs) {\n        os << \"[\";\n        bool first\
    \ = true;\n        rhs.print(os, rhs.m_root, first);\n        return os << \"\
    ]\";\n    }\n};\n\ntemplate <typename S>\nusing range_minimum_dynamic_segment_tree\
    \ = DynamicSegmentTree<algebra::monoid::minimum<S>>;\n\ntemplate <typename S>\n\
    using range_maximum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::maximum<S>>;\n\
    \ntemplate <typename S>\nusing range_sum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::addition<S>>;\n\
    \n}  // namespace dynamic_segment_tree\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP\n#define ALGORITHM_DYNAMIC_SEGMENT_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <limits>\n#include <memory>\n#include <type_traits>\n#include <utility>\n\n\
    #include \"../../Math/Algebra/algebra.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ dynamic_segment_tree {\n\ntemplate <class Monoid>\nclass DynamicSegmentTree\
    \ {\npublic:\n    using monoid_type = Monoid;\n    using value_type = monoid_type::value_type;\n\
    \    using size_type = std::size_t;\n\nprivate:\n    struct Node;\n    using node_pointer\
    \ = std::unique_ptr<Node>;\n\n    struct Node {\n        size_type index;\n  \
    \      monoid_type value;\n        monoid_type product;\n        node_pointer\
    \ left, right;\n\n        explicit Node(size_type index, const monoid_type &value)\
    \ : index(index), value(value), product(value), left(nullptr), right(nullptr)\
    \ {}\n    };\n\n    size_type m_sz;       // m_sz:=(\u8981\u7D20\u6570).\n   \
    \ node_pointer m_root;  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\n\
    \    void update(const node_pointer &p) const {\n        const monoid_type &lhs\
    \ = (p->left ? p->left->product : monoid_type::one());\n        const monoid_type\
    \ &rhs = (p->right ? p->right->product : monoid_type::one());\n        p->product\
    \ = lhs * p->value * rhs;\n    }\n    void set(node_pointer &p, size_type k, monoid_type\
    \ a, size_type l, size_type r) {\n        if(!p) {\n            p = std::make_unique<Node>(k,\
    \ a);\n            return;\n        }\n        if(p->index == k) {\n         \
    \   p->value = a;\n            update(p);\n            return;\n        }\n  \
    \      size_type mid = l + (r - l) / 2;\n        if(k < mid) {\n            if(p->index\
    \ < k) std::swap(k, p->index), std::swap(a, p->value);\n            set(p->left,\
    \ k, a, l, mid);\n        } else {\n            if(k < p->index) std::swap(k,\
    \ p->index), std::swap(a, p->value);\n            set(p->right, k, a, mid, r);\n\
    \        }\n        update(p);\n    }\n    monoid_type prod(const node_pointer\
    \ &p, size_type k, size_type l, size_type r) const {\n        if(!p) return monoid_type::one();\n\
    \        if(p->index == k) return p->value;\n        size_type mid = l + (r -\
    \ l) / 2;\n        return (k < mid ? prod(p->left, k, l, mid) : prod(p->right,\
    \ k, mid, r));\n    }\n    monoid_type prod(const node_pointer &p, size_type l,\
    \ size_type r, size_type ll, size_type rr) const {\n        if(!p or r <= ll or\
    \ rr <= l) return monoid_type::one();\n        if(l <= ll and rr <= r) return\
    \ p->product;\n        size_type mid = ll + (rr - ll) / 2;\n        return prod(p->left,\
    \ l, r, ll, mid) * (l <= p->index and p->index < r ? p->value : monoid_type::one())\
    \ * prod(p->right, l, r, mid, rr);\n    }\n    template <typename Pred>\n    size_type\
    \ most_right(const node_pointer &p, size_type l, Pred pred, size_type ll, size_type\
    \ rr, monoid_type &product) const {\n        if(!p or rr <= l) return rr;\n  \
    \      if(l <= ll and pred((product * p->product).value())) {\n            product\
    \ = product * p->product;\n            return rr;\n        }\n        size_type\
    \ mid = ll + (rr - ll) / 2;\n        size_type itr = most_right(p->left, l, pred,\
    \ ll, mid, product);\n        if(itr < mid) return itr;\n        if(l <= p->index)\
    \ {\n            product = product * p->value;\n            if(!pred(product.value()))\
    \ return p->index;\n        }\n        return most_right(p->right, l, pred, mid,\
    \ rr, product);\n    }\n    template <typename Pred>\n    size_type most_left(const\
    \ node_pointer &p, size_type r, Pred pred, size_type ll, size_type rr, monoid_type\
    \ &product) const {\n        if(!p or r <= ll) return ll;\n        if(rr <= r\
    \ and pred((p->product * product).value())) {\n            product = p->product\
    \ * product;\n            return ll;\n        }\n        size_type mid = ll +\
    \ (rr - ll) / 2;\n        size_type itr = most_left(p->right, r, pred, mid, rr,\
    \ product);\n        if(mid < itr) return itr;\n        if(p->index < r) {\n \
    \           product = p->value * product;\n            if(!pred(product.value()))\
    \ return p->index + 1;\n        }\n        return most_left(p->left, r, pred,\
    \ ll, mid, product);\n    }\n    void reset(node_pointer &p, size_type l, size_type\
    \ r, size_type ll, size_type rr) {\n        if(!p or r <= ll or rr <= l) return;\n\
    \        if(l <= ll and rr <= r) {\n            p.reset();\n            return;\n\
    \        }\n        size_type mid = ll + (rr - ll) / 2;\n        reset(p->left,\
    \ l, r, ll, mid);\n        reset(p->right, l, r, mid, rr);\n        if(l <= p->index\
    \ and p->index < r) {\n            if(!p->left and !p->right) {\n            \
    \    p.reset();\n                return;\n            }\n            p->value\
    \ = monoid_type::one();\n        }\n        update(p);\n    }\n    void print(std::ostream\
    \ &os, const node_pointer &p, bool &first) const {\n        if(!p) return;\n \
    \       print(os, p->left, first);\n        os << (first ? \"{\" : \" {\") <<\
    \ p->index << \", \" << p->value << \"}\";\n        first = false;\n        print(os,\
    \ p->right, first);\n    }\n\npublic:\n    DynamicSegmentTree() : DynamicSegmentTree(std::numeric_limits<size_type>::max())\
    \ {};\n    explicit DynamicSegmentTree(size_type n) : m_sz(n), m_root(nullptr)\
    \ {}\n\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(log N).\n    void set(size_type k,\
    \ const value_type &a) { set(k, monoid_type(a)); }\n    void set(size_type k,\
    \ const monoid_type &a) {\n        assert(k < size());\n        set(m_root, k,\
    \ a, 0, m_sz);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(log N).\n    value_type prod(size_type k) const {\n      \
    \  assert(k < size());\n        return prod(m_root, k, 0, m_sz).value();\n   \
    \ }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(log N).\n    value_type prod(size_type l, size_type r) const {\n\
    \        assert(l <= r and r <= size());\n        return prod(m_root, l, r, 0,\
    \ m_sz).value();\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod_all()\
    \ const { return (m_root ? m_root->product : monoid_type::one()).value(); }\n\
    \    // pred(prod(l,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024r\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\uFF0C\u533A\u9593[l,n)\u306E\u8981\u7D20\u306Fpred(S)\u306B\u3088\u3063\
    \u3066\u533A\u5206\u5316\u3055\u308C\u3066\u3044\u308B\u3053\u3068\uFF0E\u307E\
    \u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(log N).\n    template\
    \ <bool (*pred)(value_type)>\n    size_type most_right(size_type l) const {\n\
    \        return most_right(l, [](const value_type &x) -> bool { return pred(x);\
    \ });\n    }\n    template <typename Pred>\n    size_type most_right(size_type\
    \ l, Pred pred) const {\n        static_assert(std::is_invocable_r<bool, Pred,\
    \ value_type>::value);\n        assert(l <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        monoid_type &&product = monoid_type::one();\n        return most_right(m_root,\
    \ l, pred, 0, m_sz, product);\n    }\n    // pred(prod(l,r))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024l\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u533A\u9593[0,r)\u306E\u8981\
    \u7D20\u306Fpred(S)\u306B\u3088\u3063\u3066\u533A\u5206\u5316\u3055\u308C\u3066\
    \u3044\u308B\u3053\u3068\uFF0E\u307E\u305F\uFF0Cpred(e)==true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(log N).\n    template <bool (*pred)(value_type)>\n    size_type\
    \ most_left(int r) const {\n        return most_left(r, [](const value_type &x)\
    \ -> bool { return pred(x); });\n    }\n    template <typename Pred>\n    size_type\
    \ most_left(size_type r, Pred pred) const {\n        static_assert(std::is_invocable_r<bool,\
    \ Pred, value_type>::value);\n        assert(r <= size());\n        assert(pred(monoid_type::one().value()));\n\
    \        value_type &&product = monoid_type::one();\n        return most_left(m_root,\
    \ r, pred, 0, m_sz, product);\n    }\n    void reset(size_type k) { reset(m_root,\
    \ k, k + 1, 0, m_sz); }\n    void reset(size_type l, size_type r) {\n        assert(l\
    \ <= r and r <= size());\n        reset(m_root, l, r, 0, m_sz);\n    }\n    void\
    \ reset() { m_root.reset(); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const DynamicSegmentTree &rhs) {\n        os << \"[\";\n        bool first\
    \ = true;\n        rhs.print(os, rhs.m_root, first);\n        return os << \"\
    ]\";\n    }\n};\n\ntemplate <typename S>\nusing range_minimum_dynamic_segment_tree\
    \ = DynamicSegmentTree<algebra::monoid::minimum<S>>;\n\ntemplate <typename S>\n\
    using range_maximum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::maximum<S>>;\n\
    \ntemplate <typename S>\nusing range_sum_dynamic_segment_tree = DynamicSegmentTree<algebra::monoid::addition<S>>;\n\
    \n}  // namespace dynamic_segment_tree\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/Algebra/algebra.hpp
  isVerificationFile: false
  path: algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-07-06 12:46:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
  - verify/aoj-DSL_2_B-dynamic_segment_tree.test.cpp
documentation_of: algorithm/DataStructure/SegmentTree/dynamic_segment_tree.hpp
layout: document
title: "Dynamic Segment Tree\uFF08\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
  \uFF09"
---


## 概要

通常の Segment tree は，全要素分の値を保持するための領域を用意する必要がある．
それに対し，「Dynamic segment tree（動的セグメント木）」は，必要な要素のみに対して更新時に動的に領域確保する．
つまり，扱う要素列の長さを $N$ ，更新のある要素数を $Q \leq N$ とすると，空間計算量は $\mathcal{O}(Q)$ となる．
特に $N$ の制約が大きく，また「クエリを先読みし，座標圧縮する」というテクニックが使えないオンラインクエリの場合に適する．

ただし，Segment tree と異なり次の制約をもつ．

- 初期化時，すべての要素は単位元である必要がある
- 一点取得の時間計算量が $\mathcal{O}(\log Q)$


## 説明

### algorithm::dynamic_segment_tree::DynamicSegmentTree<Monoid>

|テンプレート引数|説明|
|---|---|
|`Monoid`|モノイドの型．`algorithm::algebra::Monoid` を想定している．|

|コンストラクタ|説明|計算量|
|---|---|---|
|`DynamicSegmentTree()`|デフォルトコンストラクタ．`DynamicSegmentTree(n)` と等価．|$\mathcal{O}(1)$|
|`DynamicSegmentTree(n)`|コンストラクタ．要素数を `n` とした `DynamicSegmentTree` オブジェクトを構築する．全要素は単位元 `Monoid::one()` で初期化されるとみなす．|$\mathcal{O}(1)$|

|メンバ関数|説明|計算量|
|---|---|---|
|`x=size()`|要素数 `x` を取得する．|$\mathcal{O}(1)$|
|`set(k,a)`|`k` 番目の要素を `a` に置き換える．|$\mathcal{O}(\log Q)$|
|`x=prod(k)`|`k` 番目の要素 `x` を取得する．|$\mathcal{O}(Q)$|
|`x=prod(l,r)`|区間 `[l,r)` の要素の総積 `x` を求める．|$\mathcal{O}(\log Q)$|
|`x=prod_all()`|区間全体の要素の総積 `x` を求める．|$\mathcal{O}(1)$|
|`r=most_right(l,pred)`|`pred(prod(l,r))==true` となる区間の最右位置 `r` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log Q)$|
|`l=most_left(r,pred)`|`pred(prod(l,r))==true` となる区間の最左位置 `l` を二分探索する．ただし，区間 $[l,n)$ の要素は1項述語 `pred` によって区分化されていること．また，`pred(Monoid::one())==true` であること．|$\mathcal{O}(\log Q)$|
|`reset(k)`|`k` 番目の要素を単位元 `Monoid::one()` で初期化する．|$\mathcal{O}(Q)$|
|`reset(l,r)`|区間 `[l,r)` の要素を単位元 `Monoid::one()` で初期化する．|$\mathcal{O}(Q)$|
|`reset()`|全要素を単位元 `Monoid::one()` で初期化する．|$\Theta(Q)$|


## 参考

1. "Dynamic Segment Tree の ACL 風実装". HatenaBlog. <https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644>.


## 問題

- "D - タコヤキオイシクナール". AtCoder Regular Contest 008. AtCoder. <https://atcoder.jp/contests/arc008/tasks/arc008_4>.
