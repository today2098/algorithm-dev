---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/SegmentTree/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: lib/Math/ModularArithmetic/modint_base.hpp
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
    \n\n#include <iostream>\n\n#line 1 \"lib/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#line\
    \ 8 \"lib/DataStructure/SegmentTree/segment_tree.hpp\"\n#include <limits>\n#include\
    \ <type_traits>\n#include <vector>\n\nnamespace algorithm {\n\nnamespace segmenttree\
    \ {\n\ntemplate <typename S, auto op, auto e>\nclass SegmentTree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>);\n    static_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>);\n\npublic:\n    using value_type = S;\n\nprivate:\n  \
    \  int m_sz;                        // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;\
    \                         // m_n:=(\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u8449\u6570\
    ).\n    std::vector<value_type> m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\
    \u6728). 1-based index.\n\n    void update(int k) { m_tree[k] = op(m_tree[k <<\
    \ 1], m_tree[k << 1 | 1]); }\n    void build() {\n        for(int l = m_n >> 1,\
    \ r = (m_n + m_sz - 1) >> 1; l >= 1; l >>= 1, r >>= 1) {\n            for(int\
    \ i = r; i >= l; --i) update(i);\n        }\n    }\n\npublic:\n    // constructor.\
    \ O(N).\n    SegmentTree() : SegmentTree(0) {};\n    explicit SegmentTree(int\
    \ n) : m_sz(n), m_n(1) {\n        assert(n >= 0);\n        while(m_n < m_sz) m_n\
    \ <<= 1;\n        m_tree.assign(2 * m_n, e());\n    }\n    explicit SegmentTree(int\
    \ n, const value_type &a) : SegmentTree(n) {\n        std::fill(m_tree.begin()\
    \ + m_n, m_tree.begin() + m_n + m_sz, a);\n        if(a != e()) build();\n   \
    \ }\n    explicit SegmentTree(const std::vector<value_type> &v) : SegmentTree(v.size())\
    \ {\n        std::copy(v.cbegin(), v.cend(), m_tree.begin() + m_n);\n        build();\n\
    \    }\n\n    // \u4E8C\u9805\u6F14\u7B97\u95A2\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E\n    static constexpr auto operation() { return op; }\n    // \u5358\u4F4D\
    \u5143\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    static constexpr auto identity()\
    \ { return e; }\n    // \u8981\u7D20\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\
    \u3092a\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(logN).\n    void set(int k,\
    \ const value_type &a) {\n        assert(0 <= k and k < size());\n        k +=\
    \ m_n;\n        m_tree[k] = a;\n        while(k >>= 1) update(k);\n    }\n   \
    \ // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(1).\n\
    \    value_type prod(int k) const {\n        assert(0 <= k and k < size());\n\
    \        return m_tree[k + m_n];\n    }\n    // \u533A\u9593[l,r)\u306E\u8981\u7D20\
    \u306E\u7DCF\u7A4D a[l]\u2022a[l+1]\u2022...\u2022a[r-1] \u3092\u6C42\u3081\u308B\
    \uFF0EO(logN).\n    value_type prod(int l, int r) const {\n        assert(0 <=\
    \ l and l <= r and r <= size());\n        value_type &&val_l = e(), &&val_r =\
    \ e();\n        for(l += m_n, r += m_n; l < r; l >>= 1, r >>= 1) {\n         \
    \   if(l & 1) val_l = op(val_l, m_tree[l++]);\n            if(r & 1) val_r = op(m_tree[--r],\
    \ val_r);\n        }\n        return op(val_l, val_r);\n    }\n    // \u533A\u9593\
    \u5168\u4F53\u306E\u8981\u7D20\u306E\u7DCF\u7A4D\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(1).\n    value_type prod_all() const { return m_tree[1]; }\n    // eval(prod(l,-))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306E\u533A\u9593\u7A4D\u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\
    \u307E\u305F eval(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template\
    \ <class Eval>\n    int most_right(int l, Eval eval) const {\n        static_assert(std::is_convertible_v<Eval,\
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
    \n#line 1 \"lib/Math/ModularArithmetic/modint.hpp\"\n\n\n\n#line 5 \"lib/Math/ModularArithmetic/modint.hpp\"\
    \n#include <utility>\n\n#line 1 \"lib/Math/ModularArithmetic/modint_base.hpp\"\
    \n\n\n\n#line 5 \"lib/Math/ModularArithmetic/modint_base.hpp\"\n\nnamespace algorithm\
    \ {\n\nclass ModintBase {};\n\ntemplate <class T>\nusing is_modint = std::is_base_of<ModintBase,\
    \ T>;\n\ntemplate <class T>\ninline constexpr bool is_modint_v = is_modint<T>::value;\n\
    \n}  // namespace algorithm\n\n\n#line 8 \"lib/Math/ModularArithmetic/modint.hpp\"\
    \n\nnamespace algorithm {\n\ntemplate <int mod>\nclass Modint : ModintBase {\n\
    \    static_assert(mod >= 1);\n\n    long long val;\n\n    constexpr void normalize()\
    \ {\n        if(val < -mod or mod <= val) val %= mod;\n        if(val < 0) val\
    \ += mod;\n    }\n\npublic:\n    constexpr Modint() : val(0) {}\n    constexpr\
    \ Modint(long long val) : val(val) {\n        normalize();\n    }\n\n    constexpr\
    \ Modint operator+() const { return Modint(*this); }\n    constexpr Modint operator-()\
    \ const {\n        if(val == 0) Modint();\n        Modint res = *this;\n     \
    \   res.val = mod - res.val;\n        return res;\n    }\n    constexpr Modint\
    \ &operator++() {\n        val++;\n        if(val == mod) val = 0;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator--() {\n        if(val == 0) val\
    \ = mod;\n        val--;\n        return *this;\n    }\n    constexpr Modint operator++(int)\
    \ {\n        Modint res = *this;\n        ++(*this);\n        return res;\n  \
    \  }\n    constexpr Modint operator--(int) {\n        Modint res = *this;\n  \
    \      --(*this);\n        return res;\n    }\n    constexpr Modint &operator+=(const\
    \ Modint &rhs) {\n        val += rhs.val;\n        if(val >= mod) val -= mod;\n\
    \        return *this;\n    }\n    constexpr Modint &operator-=(const Modint &rhs)\
    \ {\n        val -= rhs.val;\n        if(val < 0) val += mod;\n        return\
    \ *this;\n    }\n    constexpr Modint &operator*=(const Modint &rhs) {\n     \
    \   val = val * rhs.val % mod;\n        return *this;\n    }\n    constexpr Modint\
    \ &operator/=(const Modint &rhs) { return *this *= rhs.inv(); }\n\n    friend\
    \ constexpr bool operator==(const Modint &lhs, const Modint &rhs) { return lhs.val\
    \ == rhs.val; }\n    friend constexpr Modint operator+(const Modint &lhs, const\
    \ Modint &rhs) { return Modint(lhs) += rhs; }\n    friend constexpr Modint operator-(const\
    \ Modint &lhs, const Modint &rhs) { return Modint(lhs) -= rhs; }\n    friend constexpr\
    \ Modint operator*(const Modint &lhs, const Modint &rhs) { return Modint(lhs)\
    \ *= rhs; }\n    friend constexpr Modint operator/(const Modint &lhs, const Modint\
    \ &rhs) { return Modint(lhs) /= rhs; }\n    friend std::istream &operator>>(std::istream\
    \ &is, Modint &rhs) {\n        is >> rhs.val;\n        rhs.normalize();\n    \
    \    return is;\n    }\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Modint &rhs) { return os << rhs.val; }\n\n    static constexpr int modulus()\
    \ { return mod; }\n    constexpr long long value() const { return val; }\n   \
    \ constexpr Modint inv() const {\n        long long a = mod, b = val, u = 0, v\
    \ = 1;\n        while(b != 0) {\n            long long t = a / b;\n          \
    \  a -= b * t, u -= v * t;\n            std::swap(a, b), std::swap(u, v);\n  \
    \      }\n        return Modint(u);\n    }\n    constexpr Modint pow(long long\
    \ k) const {\n        if(k < 0) return inv().pow(-k);\n        Modint res = 1,\
    \ mul = *this;\n        while(k > 0) {\n            if(k & 1LL) res *= mul;\n\
    \            mul *= mul;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n\n    friend constexpr Modint mod_inv(const Modint &a) { return a.inv();\
    \ }\n    friend constexpr Modint mod_pow(const Modint &a, long long k) { return\
    \ a.pow(k); }\n};\n\nusing mint998244353 = Modint<998'244'353>;\nusing mint1000000007\
    \ = Modint<1'000'000'007>;\n\n}  // namespace algorithm\n\n\n#line 7 \"verify/yosupo-point_set_range_composite-segment_tree.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ Type = algorithm::mint998244353;\n    using S = struct {\n        Type a;\n\
    \        Type b;\n    };\n    auto mapping = [](const S &f, Type x) -> Type {\n\
    \        return x * f.a + f.b;\n    };\n\n    constexpr auto op = [](const S &lhs,\
    \ const S &rhs) -> S { return {lhs.a * rhs.a, lhs.b * rhs.a + rhs.b}; };\n   \
    \ constexpr auto e = []() -> S { return {1, 0}; };\n    algorithm::segmenttree::SegmentTree<S,\
    \ op, e> segtree(n);\n\n    for(int i = 0; i < n; ++i) {\n        Type a, b;\n\
    \        std::cin >> a >> b;\n\n        segtree.set(i, {a, b});\n    }\n\n   \
    \ while(q--) {\n        int t;\n        std::cin >> t;\n\n        if(t == 0) {\n\
    \            int p;\n            Type c, d;\n            std::cin >> p >> c >>\
    \ d;\n\n            segtree.set(p, {c, d});\n        } else {\n            int\
    \ l, r;\n            Type x;\n            std::cin >> l >> r >> x;\n\n       \
    \     auto &&f = segtree.prod(l, r);\n            auto &&ans = mapping(f, x);\n\
    \            std::cout << ans << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include <iostream>\n\n#include \"../lib/DataStructure/SegmentTree/segment_tree.hpp\"\
    \n#include \"../lib/Math/ModularArithmetic/modint.hpp\"\n\nint main() {\n    int\
    \ n;\n    int q;\n    std::cin >> n >> q;\n\n    using Type = algorithm::mint998244353;\n\
    \    using S = struct {\n        Type a;\n        Type b;\n    };\n    auto mapping\
    \ = [](const S &f, Type x) -> Type {\n        return x * f.a + f.b;\n    };\n\n\
    \    constexpr auto op = [](const S &lhs, const S &rhs) -> S { return {lhs.a *\
    \ rhs.a, lhs.b * rhs.a + rhs.b}; };\n    constexpr auto e = []() -> S { return\
    \ {1, 0}; };\n    algorithm::segmenttree::SegmentTree<S, op, e> segtree(n);\n\n\
    \    for(int i = 0; i < n; ++i) {\n        Type a, b;\n        std::cin >> a >>\
    \ b;\n\n        segtree.set(i, {a, b});\n    }\n\n    while(q--) {\n        int\
    \ t;\n        std::cin >> t;\n\n        if(t == 0) {\n            int p;\n   \
    \         Type c, d;\n            std::cin >> p >> c >> d;\n\n            segtree.set(p,\
    \ {c, d});\n        } else {\n            int l, r;\n            Type x;\n   \
    \         std::cin >> l >> r >> x;\n\n            auto &&f = segtree.prod(l, r);\n\
    \            auto &&ans = mapping(f, x);\n            std::cout << ans << \"\\\
    n\";\n        }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/SegmentTree/segment_tree.hpp
  - lib/Math/ModularArithmetic/modint.hpp
  - lib/Math/ModularArithmetic/modint_base.hpp
  isVerificationFile: true
  path: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
  requiredBy: []
  timestamp: '2025-03-28 09:06:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-point_set_range_composite-segment_tree.test.cpp
- /verify/verify/yosupo-point_set_range_composite-segment_tree.test.cpp.html
title: verify/yosupo-point_set_range_composite-segment_tree.test.cpp
---
