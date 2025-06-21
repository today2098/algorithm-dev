---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/DataStructure/Others/binary_trie.hpp
    title: "Binary Trie\uFF08\u4E8C\u5206\u30C8\u30E9\u30A4\u6728\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/yosupo-set_xor_min-binary_trie.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include <iostream>\n\
    \n#line 1 \"lib/DataStructure/Others/binary_trie.hpp\"\n\n\n\n#include <bitset>\n\
    #include <cassert>\n\nnamespace algorithm {\n\ntemplate <std::size_t w = 32>\n\
    class BinaryTrie {\npublic:\n    using size_type = std::size_t;\n\nprivate:\n\
    \    struct Node {\n        size_type cnt;  // cnt:=(\u81EA\u8EAB\u3092\u6839\u3068\
    \u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u306E\
    \u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\u306E\u30DD\u30A4\u30F3\u30BF\
    ).\n        Node() : cnt(0), ch{nullptr, nullptr} {}\n    };\n\n    Node *m_root;\
    \           // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n    std::bitset<w>\
    \ m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u5024).\n\n    Node *find(Node *p,\
    \ const std::bitset<w> &x, std::size_t itr = w) const {\n        if(!p) return\
    \ nullptr;\n        if(itr == 0) return p;\n        return find(p->ch[x[itr -\
    \ 1] ^ m_bias[itr - 1]], x, itr - 1);\n    }\n    Node *add(Node *p, size_type\
    \ cnt, const std::bitset<w> &x, std::size_t itr = w) {  // top down.\n       \
    \ if(!p) p = new Node();\n        p->cnt += cnt;\n        if(itr == 0) return\
    \ p;\n        bool b = x[itr - 1] ^ m_bias[itr - 1];\n        p->ch[b] = add(p->ch[b],\
    \ cnt, x, itr - 1);\n        return p;\n    }\n    Node *sub(Node *p, size_type\
    \ cnt, const std::bitset<w> &x, std::size_t itr = w) {  // bottom up.\n      \
    \  assert(p and cnt <= p->cnt);\n        if(itr > 0) {\n            bool b = x[itr\
    \ - 1] ^ m_bias[itr - 1];\n            p->ch[b] = sub(p->ch[b], cnt, x, itr -\
    \ 1);\n        }\n        if(p->cnt == cnt) {\n            delete p;\n       \
    \     return p = nullptr;\n        }\n        p->cnt -= cnt;\n        return p;\n\
    \    }\n    std::bitset<w> get(Node *p, size_type k, std::size_t itr = w) const\
    \ {\n        assert(p);\n        if(itr == 0) return 0;\n        bool b = m_bias[itr\
    \ - 1];\n        size_type m = (p->ch[b] ? p->ch[b]->cnt : 0);\n        if(k <\
    \ m) return get(p->ch[b], k, itr - 1);\n        return get(p->ch[!b], k - m, itr\
    \ - 1).set(itr - 1);\n    }\n    size_type get_lower(Node *p, const std::bitset<w>\
    \ &x, std::size_t itr = w) const {\n        if(!p or itr == 0) return 0;\n   \
    \     size_type res = get_lower(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr -\
    \ 1);\n        if(x[itr - 1] and p->ch[m_bias[itr - 1]]) res += p->ch[m_bias[itr\
    \ - 1]]->cnt;\n        return res;\n    }\n    size_type get_upper(Node *p, const\
    \ std::bitset<w> &x, std::size_t itr = w) const {\n        if(!p) return 0;\n\
    \        if(itr == 0) return p->cnt;\n        size_type res = get_upper(p->ch[x[itr\
    \ - 1] ^ m_bias[itr - 1]], x, itr - 1);\n        if(x[itr - 1] and p->ch[m_bias[itr\
    \ - 1]]) res += p->ch[m_bias[itr - 1]]->cnt;\n        return res;\n    }\n   \
    \ Node *clear(Node *p) {\n        if(!p) return nullptr;\n        for(Node *&next\
    \ : p->ch) next = clear(next);\n        delete p;\n        return p = nullptr;\n\
    \    }\n\npublic:\n    BinaryTrie() : m_root(nullptr), m_bias(0) {}\n    ~BinaryTrie()\
    \ {\n        clear();\n    }\n\n    // \u7BA1\u7406\u3059\u308B\u975E\u8CA0\u6574\
    \u6570\u5024\u306E\u30D3\u30C3\u30C8\u9577\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    \n    static constexpr size_type word_size() { return w; }\n    // \u96C6\u5408\
    \u304C\u7A7A\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const\
    \ { return !m_root; }\n    // \u96C6\u5408\u306E\u8981\u7D20\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(1).\n    size_type size() const { return (m_root ? m_root->cnt\
    \ : 0); }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570x\u304C\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(w).\n    bool contains(const\
    \ std::bitset<w> &x) const { return find(m_root, x); }\n    // \u591A\u91CD\u96C6\
    \u5408\u306B\u542B\u307E\u308C\u308B\u975E\u8CA0\u6574\u6570x\u306E\u500B\u6570\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    size_type count(const std::bitset<w>\
    \ &x) const {\n        Node *p = find(m_root, x);\n        return (p ? p->cnt\
    \ : 0);\n    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570\
    x\u3092\u8FFD\u52A0\u3059\u308B\uFF0EO(w).\n    void insert(const std::bitset<w>\
    \ &x, size_type cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root,\
    \ cnt, x);\n    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u975E\u8CA0\u6574\u6570\
    x\u3092\u524A\u9664\u3059\u308B\uFF0EO(w).\n    void erase(const std::bitset<w>\
    \ &x) { erase(x, count(x)); }\n    void erase(const std::bitset<w> &x, size_type\
    \ cnt) {\n        if(cnt == 0) return;\n        m_root = sub(m_root, cnt, x);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067k\u756A\u76EE\u306B\u5C0F\u3055\
    \u3044\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E0-based index.\
    \ O(w).\n    std::bitset<w> kth_element(size_type k) const {\n        assert(k\
    \ < size());\n        return get(m_root, k);\n    }\n    // \u96C6\u5408\u5185\
    \u3067\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(w).\n    std::bitset<w> min_element() const {\n        assert(!empty());\n\
    \        return get(m_root, 0);\n    }\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\
    \u306E\u975E\u8CA0\u6574\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    std::bitset<w>\
    \ max_element() const {\n        assert(!empty());\n        return get(m_root,\
    \ size() - 1);\n    }\n    // x\u4EE5\u4E0A\u3067\u3042\u308B\u975E\u8CA0\u6574\
    \u6570\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(w).\n    size_type lower_bound(const std::bitset<w> &x) const\
    \ { return get_lower(m_root, x); }\n    // x\u3088\u308A\u5927\u304D\u3044\u975E\
    \u8CA0\u6574\u6570\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(w).\n    size_type upper_bound(const std::bitset<w>\
    \ &x) const { return get_upper(m_root, x); }\n    // \u5168\u8981\u7D20\u306B\u975E\
    \u8CA0\u6574\u6570x\u3092\u7528\u3044\u3066xor\u306E\u64CD\u4F5C\u3092\u884C\u3046\
    \uFF0E\n    void xor_all(const std::bitset<w> &x) { m_bias ^= x; }\n    void clear()\
    \ { m_root = clear(m_root); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryTrie &rhs) {\n        std::bitset<w> x(0);\n        auto dfs\
    \ = [&](auto self, Node *p, size_type itr = w) -> void {\n            if(!p) return;\n\
    \            if(itr == 0) {\n                os << \"  {\" << x;\n           \
    \     if(w <= 64) os << \" (\" << x.to_ullong() << \")\";\n                os\
    \ << \", \" << p->cnt << \"}\\n\";\n                return;\n            }\n \
    \           for(bool b : {0, 1}) {\n                x[itr - 1] = b;\n        \
    \        self(self, p->ch[b ^ rhs.m_bias[itr - 1]], itr - 1);\n            }\n\
    \        };\n        os << \"[\\n\";\n        dfs(dfs, rhs.m_root);\n        return\
    \ os << \"]\";\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"verify/yosupo-set_xor_min-binary_trie.test.cpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    algorithm::BinaryTrie<30>\
    \ trie;\n\n    while(q--) {\n        int t;\n        unsigned x;\n        std::cin\
    \ >> t >> x;\n\n        if(t == 0) {\n            if(!trie.contains(x)) trie.insert(x);\n\
    \        } else if(t == 1) {\n            if(trie.contains(x)) trie.erase(x, 1);\n\
    \        } else {\n            trie.xor_all(x);\n            auto ans = trie.min_element().to_ulong();\n\
    \            trie.xor_all(x);\n\n            std::cout << ans << \"\\n\";\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <iostream>\n\n#include \"../lib/DataStructure/Others/binary_trie.hpp\"\n\nint\
    \ main() {\n    int q;\n    std::cin >> q;\n\n    algorithm::BinaryTrie<30> trie;\n\
    \n    while(q--) {\n        int t;\n        unsigned x;\n        std::cin >> t\
    \ >> x;\n\n        if(t == 0) {\n            if(!trie.contains(x)) trie.insert(x);\n\
    \        } else if(t == 1) {\n            if(trie.contains(x)) trie.erase(x, 1);\n\
    \        } else {\n            trie.xor_all(x);\n            auto ans = trie.min_element().to_ulong();\n\
    \            trie.xor_all(x);\n\n            std::cout << ans << \"\\n\";\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/Others/binary_trie.hpp
  isVerificationFile: true
  path: verify/yosupo-set_xor_min-binary_trie.test.cpp
  requiredBy: []
  timestamp: '2025-06-16 01:20:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo-set_xor_min-binary_trie.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-set_xor_min-binary_trie.test.cpp
- /verify/verify/yosupo-set_xor_min-binary_trie.test.cpp.html
title: verify/yosupo-set_xor_min-binary_trie.test.cpp
---
