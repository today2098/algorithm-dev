---
data:
  _extendedDependsOn: []
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
    #include <algorithm>\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <limits>\n#include <type_traits>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace segmenttree {\n\ntemplate <typename S, auto op, auto e>\nclass\
    \ SegmentTree {\n    static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>);\n    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);\n\
    \npublic:\n    using value_type = S;\n\nprivate:\n    int m_sz;              \
    \          // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;                      \
    \   // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    std::vector<value_type>\
    \ m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\
    \n    void update(int k) { m_tree[k] = op(m_tree[k << 1], m_tree[k << 1 | 1]);\
    \ }\n    void build() {\n        for(int l = m_n >> 1, r = (m_n + m_sz - 1) >>\
    \ 1; l >= 1; l >>= 1, r >>= 1) {\n            for(int i = r; i >= l; --i) update(i);\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    SegmentTree() : SegmentTree(0)\
    \ {};\n    explicit SegmentTree(int n) : m_sz(n), m_n(1) {\n        assert(n >=\
    \ 0);\n        while(m_n < m_sz) m_n <<= 1;\n        m_tree.assign(2 * m_n, e());\n\
    \    }\n    explicit SegmentTree(int n, const value_type &a) : SegmentTree(n)\
    \ {\n        std::fill(m_tree.begin() + m_n, m_tree.begin() + m_n + m_sz, a);\n\
    \        if(a != e()) build();\n    }\n    explicit SegmentTree(const std::vector<value_type>\
    \ &v) : SegmentTree(v.size()) {\n        std::copy(v.cbegin(), v.cend(), m_tree.begin()\
    \ + m_n);\n        build();\n    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto operation() {\
    \ return op; }\n    // \u5358\u4F4D\u5143\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n\
    \    static constexpr auto identity() { return e; }\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \uFF0EO(logN).\n    void set(int k, const value_type &a) {\n        assert(0 <=\
    \ k and k < size());\n        k += m_n;\n        m_tree[k] = a;\n        while(k\
    \ >>= 1) update(k);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(int k) const {\n        assert(0\
    \ <= k and k < size());\n        return m_tree[k + m_n];\n    }\n    // \u533A\
    \u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D a[l]\u2022a[l+1]\u2022...\u2022\
    a[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    value_type prod(int l, int\
    \ r) const {\n        assert(0 <= l and l <= r and r <= size());\n        value_type\
    \ &&val_l = e(), &&val_r = e();\n        for(l += m_n, r += m_n; l < r; l >>=\
    \ 1, r >>= 1) {\n            if(l & 1) val_l = op(val_l, m_tree[l++]);\n     \
    \       if(r & 1) val_r = op(m_tree[--r], val_r);\n        }\n        return op(val_l,\
    \ val_r);\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\
    \u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod_all() const\
    \ { return m_tree[1]; }\n    // eval(prod(l,-))==true \u3068\u306A\u308B\u533A\
    \u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\
    \uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\u9593\u7A4D\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F eval(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Eval>\n  \
    \  int most_right(int l, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(value_type)>>);\n        assert(0 <= l and l <= size());\n\
    \        assert(eval(e()));\n        if(l == size()) return size();\n        value_type\
    \ &&val = e();\n        l += m_n;\n        do {\n            while(!(l & 1)) l\
    \ >>= 1;\n            value_type &&tmp = op(val, m_tree[l]);\n            if(!eval(tmp))\
    \ {\n                while(l < m_n) {\n                    l <<= 1;\n        \
    \            tmp = op(val, m_tree[l]);\n                    if(eval(tmp)) val\
    \ = tmp, ++l;\n                }\n                return l - m_n;\n          \
    \  }\n            val = tmp, ++l;\n        } while((l & -l) != l);  // (x&-x)==x\
    \ \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return\
    \ size();\n    }\n    // eval(prod(-,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\
    \u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n   \
    \ // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\u9593\u7A4D\u306B\u306F\
    \u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F eval(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(logN).\n    template <class Eval>\n    int most_left(int\
    \ r, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);\n\
    \        assert(0 <= r and r <= size());\n        assert(eval(e()));\n       \
    \ if(r == 0) return 0;\n        value_type &&val = e();\n        r += m_n;\n \
    \       do {\n            --r;\n            while(r > 1 and r & 1) r >>= 1;\n\
    \            value_type &&tmp = op(m_tree[r], val);\n            if(eval(tmp))\
    \ {\n                while(r < m_n) {\n                    r = r << 1 | 1;\n \
    \                   tmp = op(m_tree[r], val);\n                    if(eval(tmp))\
    \ val = tmp, --r;\n                }\n                return r + 1 - m_n;\n  \
    \          }\n            val = tmp;\n        } while((r & -r) != r);  // (x&-x)==x\
    \ \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return\
    \ 0;\n    }\n    void reset() { std::fill(m_tree.begin() + 1, m_tree.begin() +\
    \ m_n + m_sz, e()); }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const SegmentTree &rhs) {\n        os << \"[\\n\";\n        for(int l = 1, r\
    \ = 2; r <= 2 * rhs.m_n; l <<= 1, r <<= 1) {\n            for(int i = l; i < r;\
    \ ++i) os << (i == l ? \"  [\" : \" \") << rhs.m_tree[i];\n            os << \"\
    ]\\n\";\n        }\n        return os << \"]\";\n    }\n};\n\ntemplate <typename\
    \ Type>\nauto range_minimum_query(int n) {\n    assert(n >= 0);\n    using S =\
    \ Type;\n    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs,\
    \ rhs); };\n    constexpr auto e = []() -> S { return std::numeric_limits<S>::max();\
    \ };\n    return SegmentTree<S, op, e>(n);\n}\n\ntemplate <typename Type>\nauto\
    \ range_minimum_query(const std::vector<Type> &v) {\n    using S = Type;\n   \
    \ constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };\n\
    \    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };\n\
    \    return SegmentTree<S, op, e>(v);\n}\n\ntemplate <typename Type>\nauto range_maximum_query(int\
    \ n) {\n    assert(n >= 0);\n    using S = Type;\n    constexpr auto op = [](S\
    \ lhs, S rhs) -> S { return std::max(lhs, rhs); };\n    constexpr auto e = []()\
    \ -> S { return std::numeric_limits<S>::lowest(); };\n    return SegmentTree<S,\
    \ op, e>(n);\n}\n\ntemplate <typename Type>\nauto range_maximum_query(const std::vector<Type>\
    \ &v) {\n    using S = Type;\n    constexpr auto op = [](S lhs, S rhs) -> S {\
    \ return std::max(lhs, rhs); };\n    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest();\
    \ };\n    return SegmentTree<S, op, e>(v);\n}\n\ntemplate <typename Type>\nauto\
    \ range_sum_query(int n) {\n    assert(n >= 0);\n    using S = Type;\n    constexpr\
    \ auto op = [](S lhs, S rhs) -> S { return lhs + rhs; };\n    constexpr auto e\
    \ = []() -> S { return 0; };\n    return SegmentTree<S, op, e>(n);\n}\n\ntemplate\
    \ <typename Type>\nauto range_sum_query(const std::vector<Type> &v) {\n    using\
    \ S = Type;\n    constexpr auto op = [](S lhs, S rhs) -> S { return lhs + rhs;\
    \ };\n    constexpr auto e = []() -> S { return 0; };\n    return SegmentTree<S,\
    \ op, e>(v);\n}\n\n}  // namespace segmenttree\n\n}  // namespace algorithm\n\n\
    \n"
  code: "#ifndef ALGORITHM_SEGMENT_TREE_HPP\n#define ALGORITHM_SEGMENT_TREE_HPP 1\n\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <limits>\n#include <type_traits>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nnamespace segmenttree {\n\ntemplate <typename S, auto op, auto e>\nclass\
    \ SegmentTree {\n    static_assert(std::is_convertible_v<decltype(op), std::function<S(S,\
    \ S)>>);\n    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>);\n\
    \npublic:\n    using value_type = S;\n\nprivate:\n    int m_sz;              \
    \          // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;                      \
    \   // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    std::vector<value_type>\
    \ m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\
    \n    void update(int k) { m_tree[k] = op(m_tree[k << 1], m_tree[k << 1 | 1]);\
    \ }\n    void build() {\n        for(int l = m_n >> 1, r = (m_n + m_sz - 1) >>\
    \ 1; l >= 1; l >>= 1, r >>= 1) {\n            for(int i = r; i >= l; --i) update(i);\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    SegmentTree() : SegmentTree(0)\
    \ {};\n    explicit SegmentTree(int n) : m_sz(n), m_n(1) {\n        assert(n >=\
    \ 0);\n        while(m_n < m_sz) m_n <<= 1;\n        m_tree.assign(2 * m_n, e());\n\
    \    }\n    explicit SegmentTree(int n, const value_type &a) : SegmentTree(n)\
    \ {\n        std::fill(m_tree.begin() + m_n, m_tree.begin() + m_n + m_sz, a);\n\
    \        if(a != e()) build();\n    }\n    explicit SegmentTree(const std::vector<value_type>\
    \ &v) : SegmentTree(v.size()) {\n        std::copy(v.cbegin(), v.cend(), m_tree.begin()\
    \ + m_n);\n        build();\n    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto operation() {\
    \ return op; }\n    // \u5358\u4F4D\u5143\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n\
    \    static constexpr auto identity() { return e; }\n    // \u8981\u7D20\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    int size() const { return m_sz; }\n\
    \    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\
    \uFF0EO(logN).\n    void set(int k, const value_type &a) {\n        assert(0 <=\
    \ k and k < size());\n        k += m_n;\n        m_tree[k] = a;\n        while(k\
    \ >>= 1) update(k);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod(int k) const {\n        assert(0\
    \ <= k and k < size());\n        return m_tree[k + m_n];\n    }\n    // \u533A\
    \u9593[l,r)\u306E\u8981\u7D20\u306E\u7DCF\u7A4D a[l]\u2022a[l+1]\u2022...\u2022\
    a[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    value_type prod(int l, int\
    \ r) const {\n        assert(0 <= l and l <= r and r <= size());\n        value_type\
    \ &&val_l = e(), &&val_r = e();\n        for(l += m_n, r += m_n; l < r; l >>=\
    \ 1, r >>= 1) {\n            if(l & 1) val_l = op(val_l, m_tree[l++]);\n     \
    \       if(r & 1) val_r = op(m_tree[--r], val_r);\n        }\n        return op(val_l,\
    \ val_r);\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\
    \u7A4D\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n    value_type prod_all() const\
    \ { return m_tree[1]; }\n    // eval(prod(l,-))==true \u3068\u306A\u308B\u533A\
    \u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\
    \uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\u9593\u7A4D\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F eval(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Eval>\n  \
    \  int most_right(int l, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval,\
    \ std::function<bool(value_type)>>);\n        assert(0 <= l and l <= size());\n\
    \        assert(eval(e()));\n        if(l == size()) return size();\n        value_type\
    \ &&val = e();\n        l += m_n;\n        do {\n            while(!(l & 1)) l\
    \ >>= 1;\n            value_type &&tmp = op(val, m_tree[l]);\n            if(!eval(tmp))\
    \ {\n                while(l < m_n) {\n                    l <<= 1;\n        \
    \            tmp = op(val, m_tree[l]);\n                    if(eval(tmp)) val\
    \ = tmp, ++l;\n                }\n                return l - m_n;\n          \
    \  }\n            val = tmp, ++l;\n        } while((l & -l) != l);  // (x&-x)==x\
    \ \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return\
    \ size();\n    }\n    // eval(prod(-,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\
    \u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n   \
    \ // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306E\u533A\u9593\u7A4D\u306B\u306F\
    \u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F eval(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(logN).\n    template <class Eval>\n    int most_left(int\
    \ r, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval, std::function<bool(value_type)>>);\n\
    \        assert(0 <= r and r <= size());\n        assert(eval(e()));\n       \
    \ if(r == 0) return 0;\n        value_type &&val = e();\n        r += m_n;\n \
    \       do {\n            --r;\n            while(r > 1 and r & 1) r >>= 1;\n\
    \            value_type &&tmp = op(m_tree[r], val);\n            if(eval(tmp))\
    \ {\n                while(r < m_n) {\n                    r = r << 1 | 1;\n \
    \                   tmp = op(m_tree[r], val);\n                    if(eval(tmp))\
    \ val = tmp, --r;\n                }\n                return r + 1 - m_n;\n  \
    \          }\n            val = tmp;\n        } while((r & -r) != r);  // (x&-x)==x\
    \ \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return\
    \ 0;\n    }\n    void reset() { std::fill(m_tree.begin() + 1, m_tree.begin() +\
    \ m_n + m_sz, e()); }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const SegmentTree &rhs) {\n        os << \"[\\n\";\n        for(int l = 1, r\
    \ = 2; r <= 2 * rhs.m_n; l <<= 1, r <<= 1) {\n            for(int i = l; i < r;\
    \ ++i) os << (i == l ? \"  [\" : \" \") << rhs.m_tree[i];\n            os << \"\
    ]\\n\";\n        }\n        return os << \"]\";\n    }\n};\n\ntemplate <typename\
    \ Type>\nauto range_minimum_query(int n) {\n    assert(n >= 0);\n    using S =\
    \ Type;\n    constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs,\
    \ rhs); };\n    constexpr auto e = []() -> S { return std::numeric_limits<S>::max();\
    \ };\n    return SegmentTree<S, op, e>(n);\n}\n\ntemplate <typename Type>\nauto\
    \ range_minimum_query(const std::vector<Type> &v) {\n    using S = Type;\n   \
    \ constexpr auto op = [](S lhs, S rhs) -> S { return std::min(lhs, rhs); };\n\
    \    constexpr auto e = []() -> S { return std::numeric_limits<S>::max(); };\n\
    \    return SegmentTree<S, op, e>(v);\n}\n\ntemplate <typename Type>\nauto range_maximum_query(int\
    \ n) {\n    assert(n >= 0);\n    using S = Type;\n    constexpr auto op = [](S\
    \ lhs, S rhs) -> S { return std::max(lhs, rhs); };\n    constexpr auto e = []()\
    \ -> S { return std::numeric_limits<S>::lowest(); };\n    return SegmentTree<S,\
    \ op, e>(n);\n}\n\ntemplate <typename Type>\nauto range_maximum_query(const std::vector<Type>\
    \ &v) {\n    using S = Type;\n    constexpr auto op = [](S lhs, S rhs) -> S {\
    \ return std::max(lhs, rhs); };\n    constexpr auto e = []() -> S { return std::numeric_limits<S>::lowest();\
    \ };\n    return SegmentTree<S, op, e>(v);\n}\n\ntemplate <typename Type>\nauto\
    \ range_sum_query(int n) {\n    assert(n >= 0);\n    using S = Type;\n    constexpr\
    \ auto op = [](S lhs, S rhs) -> S { return lhs + rhs; };\n    constexpr auto e\
    \ = []() -> S { return 0; };\n    return SegmentTree<S, op, e>(n);\n}\n\ntemplate\
    \ <typename Type>\nauto range_sum_query(const std::vector<Type> &v) {\n    using\
    \ S = Type;\n    constexpr auto op = [](S lhs, S rhs) -> S { return lhs + rhs;\
    \ };\n    constexpr auto e = []() -> S { return 0; };\n    return SegmentTree<S,\
    \ op, e>(v);\n}\n\n}  // namespace segmenttree\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/DataStructure/SegmentTree/segment_tree.hpp
  requiredBy: []
  timestamp: '2025-03-27 00:27:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj-DSL_2_A-segment_tree.test.cpp
  - verify/yosupo-point_add_range_sum-segment_tree.test.cpp
  - verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  - verify/aoj-DSL_2_B-segment_tree.test.cpp
documentation_of: lib/DataStructure/SegmentTree/segment_tree.hpp
layout: document
title: Segment Tree
---


## 概要

長さ $N$ の要素列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対して，次のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- **一点更新**：要素 $a_i$ を $x$ で更新する
- **区間取得**：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する

本ライブラリで実装している Segment Tree は，いわゆる「抽象セグメント木」であり，オブジェクトを定義する際に扱うモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ を定義する．

ここで「モノイド」とは，集合 $S$ とその上の二項演算 $\bullet : S \times S \rightarrow S$ をもち，以下の条件を満たす代数構造のことをいう．

- 結合律：$(a \bullet b) \bullet c = a \bullet (b \bullet c) \quad (\forall a, \forall b, \forall c \in S)$
- 単位元の存在：$e \bullet a = a \bullet e = a \quad (e \in S, \forall a \in S)$

例えば，整数全体は加法あるいは乗法に関してモノイドを成す．


## 参考文献

1. "SegTree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/segtree.html>.
1. "モノイド". Wikipedia. <https://ja.wikipedia.org/wiki/モノイド>.
1. rsk0315. "セグ木のお勉強を敬遠している人へ". えびちゃんの日記. HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/07/05/184929>.
1. "セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree>.
