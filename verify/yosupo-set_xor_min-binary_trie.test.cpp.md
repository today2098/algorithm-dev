---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/DataStructure/Others/binary_trie.hpp
    title: "Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\u7D20\u3068\
      \u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/yosupo-set_xor_min-binary_trie.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include <iostream>\n\
    \n#line 1 \"lib/DataStructure/Others/binary_trie.hpp\"\n\n\n\n/**\n * @brief Binary\
    \ Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\u7D20\u3068\u3059\u308B\
    \u591A\u91CD\u96C6\u5408\uFF09\n * @docs docs/DataStructure/Others/binary_trie.md\n\
    \ */\n\n#include <bitset>\n#include <cassert>\n#include <cstddef>\n\nnamespace\
    \ algorithm {\n\n// Binary Trie\uFF08\u975E\u8CA0\u6574\u6570\u5024\u3092\u8981\
    \u7D20\u3068\u3059\u308B\u591A\u91CD\u96C6\u5408\uFF09.\ntemplate <size_t B =\
    \ 32>  // B:\u30D3\u30C3\u30C8\u9577.\nclass BinaryTrie {\npublic:\n    using\
    \ size_type = size_t;\n\nprivate:\n    struct Node {\n        size_type cnt; \
    \ // cnt:=(\u81EA\u8EAB\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\
    \u307E\u308C\u308B\u8981\u7D20\u306E\u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n        Node() : cnt(0), ch{nullptr, nullptr}\
    \ {}\n    };\n\n    Node *m_root;           // m_root:=(\u6839\u306E\u30DD\u30A4\
    \u30F3\u30BF).\n    std::bitset<B> m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u5024\
    ).\n\n    Node *find(const std::bitset<B> &x) const {\n        if(!m_root) return\
    \ nullptr;\n        Node *p = m_root;\n        for(int i = B - 1; i >= 0; --i)\
    \ {\n            p = p->ch[x[i] ^ m_bias[i]];\n            if(!p) return nullptr;\n\
    \        }\n        return p;\n    }\n    Node *add(Node *p, const std::bitset<B>\
    \ &x, size_type cnt, int shift = B - 1) {  // top down.\n        if(!p) p = new\
    \ Node();\n        p->cnt += cnt;\n        if(shift >= 0) {\n            bool\
    \ b = x[shift] ^ m_bias[shift];\n            p->ch[b] = add(p->ch[b], x, cnt,\
    \ shift - 1);\n        }\n        return p;\n    }\n    Node *sub(Node *p, const\
    \ std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // bottom up.\n    \
    \    assert(p and p->cnt >= cnt);\n        if(shift >= 0) {\n            bool\
    \ b = x[shift] ^ m_bias[shift];\n            p->ch[b] = sub(p->ch[b], x, cnt,\
    \ shift - 1);\n        }\n        p->cnt -= cnt;\n        if(p->cnt == 0) {\n\
    \            delete p;\n            p = nullptr;\n        }\n        return p;\n\
    \    }\n    std::bitset<B> get(Node *p, size_type k, int shift = B - 1) const\
    \ {\n        assert(p);\n        if(shift < 0) return 0;\n        bool b = m_bias[shift];\n\
    \        size_type m = (p->ch[b] ? p->ch[b]->cnt : 0);\n        if(k < m) return\
    \ get(p->ch[b], k, shift - 1);\n        return get(p->ch[!b], k - m, shift - 1)\
    \ | std::bitset<B>(0).set(shift);\n    }\n    size_type get_lower(Node *p, const\
    \ std::bitset<B> &x, int shift = B - 1) const {\n        if(!p) return 0;\n  \
    \      if(shift < 0) return 0;\n        size_type res = get_lower(p->ch[x[shift]\
    \ ^ m_bias[shift]], x, shift - 1);\n        if(x[shift] and p->ch[m_bias[shift]])\
    \ res += p->ch[m_bias[shift]]->cnt;\n        return res;\n    }\n    size_type\
    \ get_upper(Node *p, const std::bitset<B> &x, int shift = B - 1) const {\n   \
    \     if(!p) return 0;\n        if(shift < 0) return p->cnt;\n        size_type\
    \ res = get_upper(p->ch[x[shift] ^ m_bias[shift]], x, shift - 1);\n        if(x[shift]\
    \ and p->ch[m_bias[shift]]) res += p->ch[m_bias[shift]]->cnt;\n        return\
    \ res;\n    }\n    Node *clear_dfs(Node *p) {\n        if(!p) return nullptr;\n\
    \        for(Node *&next : p->ch) next = clear_dfs(next);\n        delete p;\n\
    \        return p = nullptr;\n    }\n    void print_dfs(std::ostream &os, Node\
    \ *p, std::bitset<B> &x, int shift = B - 1) const {\n        if(shift < 0) {\n\
    \            os << \"  {0b\" << x;\n            if(B <= 64) os << \" (\" << x.to_ullong()\
    \ << \")\";\n            os << \", \" << p->cnt << \"}\\n\";\n            return;\n\
    \        }\n        for(bool b : {0, 1}) {\n            x[shift] = b;\n      \
    \      b ^= m_bias[shift];\n            if(p->ch[b]) print_dfs(os, p->ch[b], x,\
    \ shift - 1);\n        }\n    }\n\npublic:\n    BinaryTrie() : m_root(nullptr),\
    \ m_bias(0) {}\n    ~BinaryTrie() {\n        clear();\n    }\n\n    std::bitset<B>\
    \ operator[](size_type k) const { return kth_element(k); }\n\n    // \u7BA1\u7406\
    \u3059\u308B\u975E\u8CA0\u6574\u6570\u5024\u306E\u30D3\u30C3\u30C8\u9577\u3092\
    \u8FD4\u3059\uFF0E\n    static constexpr size_t bit_length() { return B; }\n \
    \   // \u96C6\u5408\u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0EO(1).\n    bool empty() const { return !m_root; }\n    // \u5168\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(1).\n    size_type size() const { return (m_root\
    \ ? m_root->cnt : 0); }\n    // \u5024x\u306E\u8981\u7D20\u304C\u96C6\u5408\u306B\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(B).\n    bool exists(const\
    \ std::bitset<B> &x) const { return find(x); }\n    // \u5024x\u306E\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(B).\n    size_type count(const std::bitset<B>\
    \ &x) const {\n        Node *p = find(x);\n        return (p ? p->cnt : 0);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u5024x\u306E\u8981\u7D20\u3092\u8FFD\
    \u52A0\u3059\u308B\uFF0EO(B).\n    void insert(const std::bitset<B> &x, size_type\
    \ cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root, x, cnt);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u5024x\u306E\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B\uFF0EO(B).\n    void erase(const std::bitset<B> &x) {\
    \ erase(x, count(x)); }\n    void erase(const std::bitset<B> &x, size_type cnt)\
    \ {\n        assert(count(x) >= cnt);\n        if(cnt == 0) return;\n        m_root\
    \ = sub(m_root, x, cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067k\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0E0-based index. O(B).\n    std::bitset<B> kth_element(size_type k) const\
    \ {\n        assert(k < size());\n        return get(m_root, k);\n    }\n    //\
    \ \u96C6\u5408\u5185\u3067\u6700\u5C0F\u306E\u8981\u7D20\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    std::bitset<B> min_element() const { return kth_element(0);\
    \ }\n    // \u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u8981\u7D20\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    std::bitset<B> max_element() const {\
    \ return kth_element(size() - 1); }\n    // \u5024x\u4EE5\u4E0A\u3067\u3042\u308B\
    \u8981\u7D20\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0EO(B).\n    size_type lower_bound(const std::bitset<B>\
    \ &x) const { return get_lower(m_root, x); }\n    // \u5024x\u3088\u308A\u5927\
    \u304D\u3044\u8981\u7D20\u304C\u73FE\u308C\u308B\u5148\u982D\u306E\u4F4D\u7F6E\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    size_type upper_bound(const std::bitset<B>\
    \ &x) const { return get_upper(m_root, x); }\n    // xor\u306E\u64CD\u4F5C\u306B\
    \u7528\u3044\u308B\u5024\u3092\u8FD4\u3059\uFF0E\n    std::bitset<B> bias() const\
    \ { return m_bias; }\n    // \u5168\u8981\u7D20\u5024\u306Bxor\u306E\u64CD\u4F5C\
    \u3092\u884C\u3046\uFF0EO(B).\n    void xor_all(const std::bitset<B> &x) { m_bias\
    \ ^= x; }\n    // \u5168\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0E\n   \
    \ void clear() { m_root = clear_dfs(m_root); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const BinaryTrie &ob) {\n        std::bitset<B> x(0);\n        os << \"\
    [\\n\";\n        if(ob.m_root) ob.print_dfs(os, ob.m_root, x);\n        os <<\
    \ \"]\";\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 6 \"verify/yosupo-set_xor_min-binary_trie.test.cpp\"\n\nint main() {\n    int\
    \ q;\n    std::cin >> q;\n\n    algorithm::BinaryTrie<30> trie;\n    while(q--)\
    \ {\n        int t;\n        unsigned int x;\n        std::cin >> t >> x;\n\n\
    \        if(t == 0) {\n            if(!trie.exists(x)) trie.insert(x);\n     \
    \   } else if(t == 1) {\n            if(trie.exists(x)) trie.erase(x, 1);\n  \
    \      } else {\n            trie.xor_all(x);\n            auto ans = trie.min_element().to_ulong();\n\
    \            trie.xor_all(x);\n\n            std::cout << ans << \"\\n\";\n  \
    \      }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <iostream>\n\n#include \"../lib/DataStructure/Others/binary_trie.hpp\"\n\nint\
    \ main() {\n    int q;\n    std::cin >> q;\n\n    algorithm::BinaryTrie<30> trie;\n\
    \    while(q--) {\n        int t;\n        unsigned int x;\n        std::cin >>\
    \ t >> x;\n\n        if(t == 0) {\n            if(!trie.exists(x)) trie.insert(x);\n\
    \        } else if(t == 1) {\n            if(trie.exists(x)) trie.erase(x, 1);\n\
    \        } else {\n            trie.xor_all(x);\n            auto ans = trie.min_element().to_ulong();\n\
    \            trie.xor_all(x);\n\n            std::cout << ans << \"\\n\";\n  \
    \      }\n    }\n}\n"
  dependsOn:
  - lib/DataStructure/Others/binary_trie.hpp
  isVerificationFile: true
  path: verify/yosupo-set_xor_min-binary_trie.test.cpp
  requiredBy: []
  timestamp: '2025-03-24 18:16:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo-set_xor_min-binary_trie.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo-set_xor_min-binary_trie.test.cpp
- /verify/verify/yosupo-set_xor_min-binary_trie.test.cpp.html
title: verify/yosupo-set_xor_min-binary_trie.test.cpp
---
