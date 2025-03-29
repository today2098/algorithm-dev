---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp
    title: "Dynamic Segment Tree\uFF08\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n\n#line 1 \"lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#line\
    \ 8 \"lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\n#include <limits>\n\
    #include <memory>\n#include <type_traits>\n#include <utility>\n\nnamespace algorithm\
    \ {\n\nnamespace dynamicsegmenttree {\n\n// Dynamic Segment Tree\uFF08\u52D5\u7684\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09.\ntemplate <typename S, auto op, auto\
    \ e>\nclass DynamicSegmentTree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>);\n    static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>);\n\npublic:\n    using value_type = S;\n    using size_type\
    \ = std::size_t;\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        size_type index;\n        value_type value;\n   \
    \     value_type product;\n        node_ptr left, right;\n        explicit Node(size_type\
    \ index, const value_type &value) : index(index), value(value), product(value),\
    \ left(nullptr), right(nullptr) {}\n    };\n\n    size_type m_sz;   // m_sz:=(\u8981\
    \u7D20\u6570).\n    node_ptr m_root;  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\
    \u30BF).\n\n    void update(const node_ptr &p) const {\n        assert(p);\n \
    \       const value_type &lhs = (p->left ? p->left->product : e());\n        const\
    \ value_type &rhs = (p->right ? p->right->product : e());\n        p->product\
    \ = op(op(lhs, p->value), rhs);\n    }\n    void set(node_ptr &p, size_type k,\
    \ value_type a, size_type l, size_type r) {\n        assert(l <= k and k < r and\
    \ r <= size());\n        if(!p) {\n            p = std::make_unique<Node>(k, a);\n\
    \            return;\n        }\n        if(p->index == k) {\n            p->value\
    \ = a;\n            update(p);\n            return;\n        }\n        size_type\
    \ mid = l + (r - l) / 2;\n        if(k < mid) {\n            if(p->index < k)\
    \ std::swap(k, p->index), std::swap(a, p->value);\n            set(p->left, k,\
    \ a, l, mid);\n        } else {\n            if(k < p->index) std::swap(k, p->index),\
    \ std::swap(a, p->value);\n            set(p->right, k, a, mid, r);\n        }\n\
    \        update(p);\n    }\n    value_type prod(const node_ptr &p, size_type k,\
    \ size_type l, size_type r) const {\n        assert(l <= k and k < r and r <=\
    \ size());\n        if(!p) return e();\n        if(p->index == k) return p->value;\n\
    \        size_type mid = l + (r - l) / 2;\n        return (k < mid ? prod(p->left,\
    \ k, l, mid) : prod(p->right, k, mid, r));\n    }\n    value_type prod(const node_ptr\
    \ &p, size_type l, size_type r, size_type nl, size_type nr) const {\n        assert(l\
    \ <= r and r <= size());\n        assert(nl <= nr and nr <= size());\n       \
    \ if(!p or r <= nl or nr <= l) return e();\n        if(l <= nl and nr <= r) return\
    \ p->product;\n        size_type mid = nl + (nr - nl) / 2;\n        value_type\
    \ &&tmp = prod(p->left, l, r, nl, mid);\n        if(l <= p->index and p->index\
    \ < r) tmp = op(tmp, p->value);\n        return op(tmp, prod(p->right, l, r, mid,\
    \ nr));\n    }\n    template <class Eval>\n    size_type most_right(const node_ptr\
    \ &p, size_type l, Eval eval, size_type nl, size_type nr, value_type &product)\
    \ const {\n        assert(l <= size());\n        assert(nl <= nr and nr <= size());\n\
    \        if(!p or nr <= l) return nr;\n        if(l <= nl and eval(op(product,\
    \ p->product))) {\n            product = op(product, p->product);\n          \
    \  return nr;\n        }\n        size_type mid = nl + (nr - nl) / 2;\n      \
    \  size_type itr = most_right(p->left, l, eval, nl, mid, product);\n        if(itr\
    \ < mid) return itr;\n        if(l <= p->index) {\n            product = op(product,\
    \ p->value);\n            if(!eval(product)) return p->index;\n        }\n   \
    \     return most_right(p->right, l, eval, mid, nr, product);\n    }\n    template\
    \ <class Eval>\n    size_type most_left(const node_ptr &p, size_type r, Eval eval,\
    \ size_type nl, size_type nr, value_type &product) const {\n        assert(r <=\
    \ size());\n        assert(nl <= nr and nr <= size());\n        if(!p or r <=\
    \ nl) return nl;\n        if(nr <= r and eval(op(p->product, product))) {\n  \
    \          product = op(p->product, product);\n            return nl;\n      \
    \  }\n        size_type mid = nl + (nr - nl) / 2;\n        size_type itr = most_left(p->right,\
    \ r, eval, mid, nr, product);\n        if(mid < itr) return itr;\n        if(p->index\
    \ < r) {\n            product = op(p->value, product);\n            if(!eval(product))\
    \ return p->index + 1;\n        }\n        return most_left(p->left, r, eval,\
    \ nl, mid, product);\n    }\n    void reset(node_ptr &p, size_type l, size_type\
    \ r, size_type nl, size_type nr) {\n        assert(l <= r and r <= size());\n\
    \        assert(nl <= nr and nr <= size());\n        if(!p or r <= nl or nr <=\
    \ l) return;\n        if(l <= nl and nr <= r) {\n            p.reset();\n    \
    \        return;\n        }\n        size_type mid = nl + (nr - nl) / 2;\n   \
    \     reset(p->left, l, r, nl, mid);\n        reset(p->right, l, r, mid, nr);\n\
    \        if(l <= p->index and p->index < r) p->value = e();\n        update(p);\n\
    \    }\n\npublic:\n    DynamicSegmentTree() : DynamicSegmentTree(0) {};\n    explicit\
    \ DynamicSegmentTree(size_type n) : m_sz(n), m_root(nullptr) {}\n\n    // \u4E8C\
    \u9805\u6F14\u7B97\u95A2\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static\
    \ constexpr auto operation() { return op; }\n    // \u5358\u4F4D\u5143\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    static constexpr auto identity() { return e; }\n\
    \    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\
    a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(logN).\n    void set(size_type k,\
    \ const value_type &a) {\n        assert(k < size());\n        set(m_root, k,\
    \ a, 0, size());\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(logN).\n    value_type prod(size_type k) const {\n       \
    \ assert(k < size());\n        return prod(m_root, k, 0, size());\n    }\n   \
    \ // \u533A\u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D a[l]\u2022a[l+1]\u2022\
    ...\u2022a[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    value_type prod(size_type\
    \ l, size_type r) const {\n        assert(l <= r and r <= size());\n        return\
    \ prod(m_root, l, r, 0, size());\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\
    \u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type\
    \ prod_all() const { return (m_root ? m_root->product : e()); }\n    // eval(prod(l,-))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306E\u533A\u9593\u7A4D\u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\
    \u307E\u305F eval(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template\
    \ <class Eval>\n    size_type most_right(size_type l, Eval eval) const {\n   \
    \     static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);\n\
    \        assert(l <= size());\n        assert(eval(e()));\n        value_type\
    \ &&product = e();\n        return most_right(m_root, l, eval, 0, size(), product);\n\
    \    }\n    // eval(prod(-,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\
    \u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\
    \u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\u9593\u7A4D\u306B\u306F\u5358\
    \u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F eval(e)==true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(logN).\n    template <class Eval>\n    size_type most_left(size_type\
    \ r, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);\n\
    \        assert(r <= size());\n        assert(eval(e()));\n        value_type\
    \ &&product = e();\n        return most_left(m_root, r, eval, 0, size(), product);\n\
    \    }\n    void reset() { m_root.reset(); }\n    void reset(size_type l, size_type\
    \ r) {\n        assert(l <= r and r <= size());\n        reset(m_root, l, r, 0,\
    \ size());\n    }\n};\n\ntemplate <typename Type>\nauto range_minimum_query(std::size_t\
    \ n) {\n    using S = Type;\n    constexpr auto op = [](S lhs, S rhs) -> S { return\
    \ std::min(lhs, rhs); };\n    constexpr auto e = []() -> S { return std::numeric_limits<S>::max();\
    \ };\n    return DynamicSegmentTree<S, op, e>(n);\n}\n\ntemplate <typename Type>\n\
    auto range_maximum_query(std::size_t n) {\n    using S = Type;\n    constexpr\
    \ auto op = [](S lhs, S rhs) -> S { return std::max(lhs, rhs); };\n    constexpr\
    \ auto e = []() -> S { return std::numeric_limits<S>::lowest(); };\n    return\
    \ DynamicSegmentTree<S, op, e>(n);\n}\n\ntemplate <typename Type>\nauto range_sum_query(std::size_t\
    \ n) {\n    using S = Type;\n    constexpr auto op = [](S lhs, S rhs) -> S { return\
    \ lhs + rhs; };\n    constexpr auto e = []() -> S { return 0; };\n    return DynamicSegmentTree<S,\
    \ op, e>(n);\n}\n\n}  // namespace dynamicsegmenttree\n\n}  // namespace algorithm\n\
    \n\n#line 6 \"verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using Type = int;\n\
    \    auto &&segtree = algorithm::dynamicsegmenttree::range_minimum_query<Type>(n);\n\
    \    while(q--) {\n        int com;\n        std::cin >> com;\n\n        if(com\
    \ == 0) {\n            int x;\n            Type y;\n            std::cin >> x\
    \ >> y;\n\n            segtree.set(x, y);\n        } else {\n            int x,\
    \ y;\n            std::cin >> x >> y;\n            ++y;\n\n            auto &&ans\
    \ = segtree.prod(x, y);\n            std::cout << ans << \"\\n\";\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ Type = int;\n    auto &&segtree = algorithm::dynamicsegmenttree::range_minimum_query<Type>(n);\n\
    \    while(q--) {\n        int com;\n        std::cin >> com;\n\n        if(com\
    \ == 0) {\n            int x;\n            Type y;\n            std::cin >> x\
    \ >> y;\n\n            segtree.set(x, y);\n        } else {\n            int x,\
    \ y;\n            std::cin >> x >> y;\n            ++y;\n\n            auto &&ans\
    \ = segtree.prod(x, y);\n            std::cout << ans << \"\\n\";\n        }\n\
    \    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/dynamic_segment_tree.hpp
  isVerificationFile: true
  path: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-29 15:29:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
- /verify/verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp.html
title: verify/aoj-DSL_2_A-dynamic_segment_tree.test.cpp
---
