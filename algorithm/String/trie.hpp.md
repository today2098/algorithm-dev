---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/String/trie.hpp\"\n\n\n\n#include <cassert>\n\
    #include <cstddef>\n#include <functional>\n#include <iterator>\n#include <map>\n\
    #include <memory>\n#include <ranges>\n#include <string>\n#include <string_view>\n\
    #include <utility>\n\nnamespace algorithm {\n\ntemplate <typename T, typename\
    \ Compare>\nclass TrieBase {\n    static_assert(std::is_invocable_r<bool, Compare,\
    \ T, T>::value);\n\npublic:\n    using value_type = T;\n    using size_type =\
    \ std::size_t;\n    using compare = Compare;\n\nprotected:\n    struct Node;\n\
    \    using node_pointer = std::unique_ptr<Node>;\n\n    struct Node {\n      \
    \  size_type total;                                   // total:=(\u81EA\u8EAB\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\
    \u7D20\u306E\u6570).\n        size_type cnt;                                 \
    \    // cnt:=(\u81EA\u8EAB\u3092\u672B\u5C3E\u3068\u3059\u308B\u8981\u7D20\u306E\
    \u6570).\n        std::map<value_type, node_pointer, compare> next;  // next[]:=(\u5B50\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n\n        Node() : total(0), cnt(0) {}\n   \
    \ };\n\n    node_pointer m_root;  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF\
    ).\n\n    template <std::forward_iterator Iter>\n    Node *find(const node_pointer\
    \ &p, Iter iter, Iter end) const {\n        if(!p) return nullptr;\n        if(iter\
    \ == end) return p.get();\n        return find(p->next[*iter], std::next(iter),\
    \ end);\n    }\n    template <std::forward_iterator Iter>\n    void add(node_pointer\
    \ &p, Iter iter, Iter end, size_type n) {  // top down.\n        if(!p) p = std::make_unique<Node>();\n\
    \        p->total += n;\n        if(iter == end) {\n            p->cnt += n;\n\
    \            return;\n        }\n        add(p->next[*iter], std::next(iter),\
    \ end, n);\n    }\n    template <std::forward_iterator Iter>\n    size_type sub(node_pointer\
    \ &p, Iter iter, Iter end, size_type n) {  // top down.\n        assert(p and\
    \ p->total >= n);\n        p->total -= n;\n        if(p->total == 0) {\n     \
    \       p.reset();\n            return n;\n        }\n        if(iter == end)\
    \ {\n            p->cnt -= n;\n            return n;\n        }\n        return\
    \ sub(p->next[*iter], std::next(iter), end, n);\n    }\n    template <std::forward_iterator\
    \ Iter>\n    size_type erase(node_pointer &p, Iter iter, Iter end) {  // bottom\
    \ up.\n        if(!p) return 0;\n        if(iter == end) {\n            size_type\
    \ res = p->cnt;\n            p->total -= res, p->cnt = 0;\n            if(p->total\
    \ == 0) p.reset();\n            return res;\n        }\n        size_type res\
    \ = erase(p->next[*iter], std::next(iter), end);\n        p->total -= res;\n \
    \       if(p->total == 0) p.reset();\n        return res;\n    }\n    template\
    \ <std::forward_iterator Iter>\n    size_type erase_by_prefix(node_pointer &p,\
    \ Iter iter, Iter end) {  // bottom up.\n        if(!p) return 0;\n        if(iter\
    \ == end) {\n            size_type res = p->total;\n            p.reset();\n \
    \           return res;\n        }\n        size_type res = erase_by_prefix(p->next[*iter],\
    \ std::next(iter), end);\n        p->total -= res;\n        if(p->total == 0)\
    \ p.reset();\n        return res;\n    }\n    template <class Sequence>\n    Sequence\
    \ get(const node_pointer &p, size_type k, size_type depth = 0) const {  // bottom\
    \ up.\n        if(k < p->cnt) return Sequence(depth, value_type());\n        k\
    \ -= p->cnt;\n        for(const auto &[key, next] : p->next) {\n            if(!next)\
    \ continue;\n            if(k < next->total) {\n                auto &&res = get<Sequence>(next,\
    \ k, depth + 1);\n                res[depth] = key;\n                return res;\n\
    \            }\n            k -= next->total;\n        }\n        assert(false);\
    \  // not reach here.\n    }\n    template <std::forward_iterator Iter>\n    std::pair<size_type,\
    \ size_type> lower_and_upper_bound(node_pointer &p, Iter iter, Iter end) const\
    \ {  // bottom up.\n        if(!p) return {0, 0};\n        if(iter == end) return\
    \ {0, p->cnt};\n        size_type offset = 0;\n        for(const auto &[key, next]\
    \ : p->next) {\n            if(key > *iter) break;\n            if(key == *iter)\
    \ {\n                auto &&[l, r] = lower_and_upper_bound(next, std::next(iter),\
    \ end);\n                return {l + offset, r + offset};\n            }\n   \
    \         offset += next->total;\n        }\n        return {offset, offset};\n\
    \    }\n    template <std::forward_iterator Iter>\n    std::vector<std::pair<size_type,\
    \ size_type>> get_nodes(const node_pointer &p, Iter iter, Iter end, size_type\
    \ depth = 0) const {  // bottom up.\n        if(!p) {\n            while(iter++\
    \ != end) ++depth;\n            return std::vector<std::pair<size_type, size_type>>(depth\
    \ + 1, {0, 0});  // return pairs of (total, cnt).\n        }\n        auto &&res\
    \ = (iter == end ? std::vector<std::pair<size_type, size_type>>(depth + 1, {0,\
    \ 0})\n                                  : get_nodes(p->next[*iter], std::next(iter),\
    \ end, depth + 1));\n        res[depth] = {p->total, p->cnt};\n        return\
    \ res;\n    }\n\npublic:\n    TrieBase() : m_root(nullptr) {}\n    ~TrieBase()\
    \ {\n        clear();\n    }\n\n    bool empty() const { return size() == 0; }\n\
    \    size_type size() const { return (m_root ? m_root->total : 0); }\n    template\
    \ <std::ranges::forward_range R>\n    bool exists(const R &r) const { return count(r)\
    \ > 0; }\n    template <std::ranges::forward_range R>\n    size_type count(const\
    \ R &r) const {\n        auto p = find(m_root, std::ranges::cbegin(r), std::ranges::cend(r));\n\
    \        return (p ? p->cnt : 0);\n    }\n    template <std::ranges::forward_range\
    \ R>\n    bool exists_by_prefix(const R &r) const { return count_by_prefix(r)\
    \ > 0; }\n    template <std::ranges::forward_range R>\n    size_type count_by_prefix(const\
    \ R &r) const {\n        auto p = find(m_root, std::ranges::cbegin(r), std::ranges::cend(r));\n\
    \        return (p ? p->total : 0);\n    }\n    template <std::ranges::forward_range\
    \ R>\n    void insert(const R &r, size_type n = 1) {\n        if(n == 0) return;\n\
    \        add(m_root, std::ranges::cbegin(r), std::ranges::cend(r), n);\n    }\n\
    \    template <std::ranges::forward_range R>\n    size_type erase(const R &r)\
    \ { return erase(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }\n  \
    \  template <std::ranges::forward_range R>\n    size_type erase(const R &r, size_type\
    \ n) {\n        if(n == 0) return 0;\n        return sub(m_root, std::ranges::cbegin(r),\
    \ std::ranges::cend(r), n);\n    }\n    template <std::ranges::forward_range R>\n\
    \    size_type erase_by_prefix(const R &r) { return erase_by_prefix(m_root, std::ranges::cbegin(r),\
    \ std::ranges::cend(r)); }\n    template <class Sequence>\n    Sequence kth_element(size_type\
    \ k) const {\n        assert(k < size());\n        return get<Sequence>(m_root,\
    \ k);\n    }\n    template <class Sequence>\n    Sequence min_element() const\
    \ { return kth_element<Sequence>(0); }\n    template <class Sequence>\n    Sequence\
    \ max_element() const { return kth_element<Sequence>(size() - 1); }\n    template\
    \ <std::ranges::forward_range R>\n    std::pair<size_type, size_type> lower_and_upper_bound(const\
    \ R &r) const { return lower_and_upper_bound(m_root, std::ranges::cbegin(r), std::ranges::cend(r));\
    \ }\n    template <std::ranges::forward_range R>\n    std::vector<std::pair<size_type,\
    \ size_type>> get_nodes(const R &r) const { return get_nodes(m_root, std::ranges::cbegin(r),\
    \ std::ranges::cend(r)); }\n    void clear() { m_root.reset(); }\n};\n\ntemplate\
    \ <typename T, typename Compare = std::less<T>>\nclass Trie : public TrieBase<T,\
    \ Compare> {\npublic:\n    using base_type = TrieBase<T, Compare>;\n    using\
    \ typename base_type::compare;\n    using typename base_type::size_type;\n   \
    \ using typename base_type::value_type;\n\n    std::vector<value_type> kth_element(size_type\
    \ k) const { return base_type::template kth_element<std::vector<value_type>>(k);\
    \ }\n    std::vector<value_type> min_element() const { return base_type::template\
    \ min_element<std::vector<value_type>>(); }\n    std::vector<value_type> max_element()\
    \ const { return base_type::template max_element<std::vector<value_type>>(); }\n\
    };\n\ntemplate <typename Compare>\nclass Trie<char, Compare> : public TrieBase<char,\
    \ Compare> {\npublic:\n    using base_type = TrieBase<char, Compare>;\n    using\
    \ typename base_type::compare;\n    using typename base_type::size_type;\n   \
    \ using typename base_type::value_type;\n\n    // \u591A\u91CD\u96C6\u5408\u5185\
    \u306B\u6587\u5B57\u5217sv\u304C\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0E\n    bool exists(std::string_view sv) const { return base_type::exists(sv);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u542B\u307E\u308C\u308B\u6587\
    \u5B57\u5217sv\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ count(std::string_view sv) const { return base_type::count(sv); }\n    // \u591A\
    \u91CD\u96C6\u5408\u5185\u306B\u63A5\u982D\u8F9Eprefix\u3092\u3082\u3064\u6587\
    \u5B57\u5217\u304C\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\
    \n    bool exists_by_prefix(std::string_view prefix) const { return base_type::exists_by_prefix(prefix);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u542B\u307E\u308C\u308B\u63A5\
    \u982D\u8F9Eprefix\u3092\u3082\u3064\u6587\u5B57\u5217\u306E\u500B\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0E\n    size_type count_by_prefix(std::string_view\
    \ prefix) const { return base_type::count_by_prefix(prefix); }\n    // \u591A\u91CD\
    \u96C6\u5408\u306B\u6587\u5B57\u5217sv\u3092n\u500B\u8FFD\u52A0\u3059\u308B\uFF0E\
    \n    void insert(std::string_view sv, size_type n = 1) { base_type::insert(sv,\
    \ n); }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u6587\u5B57\u5217sv\u3092\
    \u3059\u3079\u3066\u524A\u9664\u3059\u308B\uFF0E\n    void erase(std::string_view\
    \ sv) { base_type::erase(sv); }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u6587\
    \u5B57\u5217sv\u3092n\u500B\u524A\u9664\u3059\u308B\uFF0E\n    void erase(std::string_view\
    \ sv, size_type n) { base_type::erase(sv, n); }\n    // \u591A\u91CD\u96C6\u5408\
    \u304B\u3089\u63A5\u982D\u8F9Eprefix\u3092\u3082\u3064\u6587\u5B57\u5217\u3092\
    \u3059\u3079\u3066\u524A\u9664\u3059\u308B\uFF0E\n    void erase_by_prefix(std::string_view\
    \ prefix) { base_type::erase_by_prefix(prefix); }\n    // \u591A\u91CD\u96C6\u5408\
    \u5185\u306B\u304A\u3044\u3066\uFF0C\u8F9E\u66F8\u9806\u3067k\u756A\u76EE\u306B\
    \u5C0F\u3055\u3044\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n   \
    \ std::string kth_element(size_type k) const { return base_type::template kth_element<std::string>(k);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u304A\u3044\u3066\uFF0C\u8F9E\
    \u66F8\u9806\u3067\u6700\u3082\u5C0F\u3055\u3044\u6587\u5B57\u5217\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    std::string min_element() const { return base_type::template\
    \ min_element<std::string>(); }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u304A\
    \u3044\u3066\uFF0C\u8F9E\u66F8\u9806\u3067\u6700\u3082\u5927\u304D\u3044\u6587\
    \u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    std::string max_element()\
    \ const { return base_type::template max_element<std::string>(); }\n    std::pair<size_type,\
    \ size_type> lower_and_upper_bound(std::string_view sv) const { return base_type::lower_and_upper_bound(sv);\
    \ }\n    std::vector<std::pair<size_type, size_type>> get_nodes(std::string_view\
    \ sv) const { return base_type::get_nodes(sv); }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_TRIE_HPP\n#define ALGORITHM_TRIE_HPP 1\n\n#include <cassert>\n\
    #include <cstddef>\n#include <functional>\n#include <iterator>\n#include <map>\n\
    #include <memory>\n#include <ranges>\n#include <string>\n#include <string_view>\n\
    #include <utility>\n\nnamespace algorithm {\n\ntemplate <typename T, typename\
    \ Compare>\nclass TrieBase {\n    static_assert(std::is_invocable_r<bool, Compare,\
    \ T, T>::value);\n\npublic:\n    using value_type = T;\n    using size_type =\
    \ std::size_t;\n    using compare = Compare;\n\nprotected:\n    struct Node;\n\
    \    using node_pointer = std::unique_ptr<Node>;\n\n    struct Node {\n      \
    \  size_type total;                                   // total:=(\u81EA\u8EAB\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\
    \u7D20\u306E\u6570).\n        size_type cnt;                                 \
    \    // cnt:=(\u81EA\u8EAB\u3092\u672B\u5C3E\u3068\u3059\u308B\u8981\u7D20\u306E\
    \u6570).\n        std::map<value_type, node_pointer, compare> next;  // next[]:=(\u5B50\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n\n        Node() : total(0), cnt(0) {}\n   \
    \ };\n\n    node_pointer m_root;  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF\
    ).\n\n    template <std::forward_iterator Iter>\n    Node *find(const node_pointer\
    \ &p, Iter iter, Iter end) const {\n        if(!p) return nullptr;\n        if(iter\
    \ == end) return p.get();\n        return find(p->next[*iter], std::next(iter),\
    \ end);\n    }\n    template <std::forward_iterator Iter>\n    void add(node_pointer\
    \ &p, Iter iter, Iter end, size_type n) {  // top down.\n        if(!p) p = std::make_unique<Node>();\n\
    \        p->total += n;\n        if(iter == end) {\n            p->cnt += n;\n\
    \            return;\n        }\n        add(p->next[*iter], std::next(iter),\
    \ end, n);\n    }\n    template <std::forward_iterator Iter>\n    size_type sub(node_pointer\
    \ &p, Iter iter, Iter end, size_type n) {  // top down.\n        assert(p and\
    \ p->total >= n);\n        p->total -= n;\n        if(p->total == 0) {\n     \
    \       p.reset();\n            return n;\n        }\n        if(iter == end)\
    \ {\n            p->cnt -= n;\n            return n;\n        }\n        return\
    \ sub(p->next[*iter], std::next(iter), end, n);\n    }\n    template <std::forward_iterator\
    \ Iter>\n    size_type erase(node_pointer &p, Iter iter, Iter end) {  // bottom\
    \ up.\n        if(!p) return 0;\n        if(iter == end) {\n            size_type\
    \ res = p->cnt;\n            p->total -= res, p->cnt = 0;\n            if(p->total\
    \ == 0) p.reset();\n            return res;\n        }\n        size_type res\
    \ = erase(p->next[*iter], std::next(iter), end);\n        p->total -= res;\n \
    \       if(p->total == 0) p.reset();\n        return res;\n    }\n    template\
    \ <std::forward_iterator Iter>\n    size_type erase_by_prefix(node_pointer &p,\
    \ Iter iter, Iter end) {  // bottom up.\n        if(!p) return 0;\n        if(iter\
    \ == end) {\n            size_type res = p->total;\n            p.reset();\n \
    \           return res;\n        }\n        size_type res = erase_by_prefix(p->next[*iter],\
    \ std::next(iter), end);\n        p->total -= res;\n        if(p->total == 0)\
    \ p.reset();\n        return res;\n    }\n    template <class Sequence>\n    Sequence\
    \ get(const node_pointer &p, size_type k, size_type depth = 0) const {  // bottom\
    \ up.\n        if(k < p->cnt) return Sequence(depth, value_type());\n        k\
    \ -= p->cnt;\n        for(const auto &[key, next] : p->next) {\n            if(!next)\
    \ continue;\n            if(k < next->total) {\n                auto &&res = get<Sequence>(next,\
    \ k, depth + 1);\n                res[depth] = key;\n                return res;\n\
    \            }\n            k -= next->total;\n        }\n        assert(false);\
    \  // not reach here.\n    }\n    template <std::forward_iterator Iter>\n    std::pair<size_type,\
    \ size_type> lower_and_upper_bound(node_pointer &p, Iter iter, Iter end) const\
    \ {  // bottom up.\n        if(!p) return {0, 0};\n        if(iter == end) return\
    \ {0, p->cnt};\n        size_type offset = 0;\n        for(const auto &[key, next]\
    \ : p->next) {\n            if(key > *iter) break;\n            if(key == *iter)\
    \ {\n                auto &&[l, r] = lower_and_upper_bound(next, std::next(iter),\
    \ end);\n                return {l + offset, r + offset};\n            }\n   \
    \         offset += next->total;\n        }\n        return {offset, offset};\n\
    \    }\n    template <std::forward_iterator Iter>\n    std::vector<std::pair<size_type,\
    \ size_type>> get_nodes(const node_pointer &p, Iter iter, Iter end, size_type\
    \ depth = 0) const {  // bottom up.\n        if(!p) {\n            while(iter++\
    \ != end) ++depth;\n            return std::vector<std::pair<size_type, size_type>>(depth\
    \ + 1, {0, 0});  // return pairs of (total, cnt).\n        }\n        auto &&res\
    \ = (iter == end ? std::vector<std::pair<size_type, size_type>>(depth + 1, {0,\
    \ 0})\n                                  : get_nodes(p->next[*iter], std::next(iter),\
    \ end, depth + 1));\n        res[depth] = {p->total, p->cnt};\n        return\
    \ res;\n    }\n\npublic:\n    TrieBase() : m_root(nullptr) {}\n    ~TrieBase()\
    \ {\n        clear();\n    }\n\n    bool empty() const { return size() == 0; }\n\
    \    size_type size() const { return (m_root ? m_root->total : 0); }\n    template\
    \ <std::ranges::forward_range R>\n    bool exists(const R &r) const { return count(r)\
    \ > 0; }\n    template <std::ranges::forward_range R>\n    size_type count(const\
    \ R &r) const {\n        auto p = find(m_root, std::ranges::cbegin(r), std::ranges::cend(r));\n\
    \        return (p ? p->cnt : 0);\n    }\n    template <std::ranges::forward_range\
    \ R>\n    bool exists_by_prefix(const R &r) const { return count_by_prefix(r)\
    \ > 0; }\n    template <std::ranges::forward_range R>\n    size_type count_by_prefix(const\
    \ R &r) const {\n        auto p = find(m_root, std::ranges::cbegin(r), std::ranges::cend(r));\n\
    \        return (p ? p->total : 0);\n    }\n    template <std::ranges::forward_range\
    \ R>\n    void insert(const R &r, size_type n = 1) {\n        if(n == 0) return;\n\
    \        add(m_root, std::ranges::cbegin(r), std::ranges::cend(r), n);\n    }\n\
    \    template <std::ranges::forward_range R>\n    size_type erase(const R &r)\
    \ { return erase(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }\n  \
    \  template <std::ranges::forward_range R>\n    size_type erase(const R &r, size_type\
    \ n) {\n        if(n == 0) return 0;\n        return sub(m_root, std::ranges::cbegin(r),\
    \ std::ranges::cend(r), n);\n    }\n    template <std::ranges::forward_range R>\n\
    \    size_type erase_by_prefix(const R &r) { return erase_by_prefix(m_root, std::ranges::cbegin(r),\
    \ std::ranges::cend(r)); }\n    template <class Sequence>\n    Sequence kth_element(size_type\
    \ k) const {\n        assert(k < size());\n        return get<Sequence>(m_root,\
    \ k);\n    }\n    template <class Sequence>\n    Sequence min_element() const\
    \ { return kth_element<Sequence>(0); }\n    template <class Sequence>\n    Sequence\
    \ max_element() const { return kth_element<Sequence>(size() - 1); }\n    template\
    \ <std::ranges::forward_range R>\n    std::pair<size_type, size_type> lower_and_upper_bound(const\
    \ R &r) const { return lower_and_upper_bound(m_root, std::ranges::cbegin(r), std::ranges::cend(r));\
    \ }\n    template <std::ranges::forward_range R>\n    std::vector<std::pair<size_type,\
    \ size_type>> get_nodes(const R &r) const { return get_nodes(m_root, std::ranges::cbegin(r),\
    \ std::ranges::cend(r)); }\n    void clear() { m_root.reset(); }\n};\n\ntemplate\
    \ <typename T, typename Compare = std::less<T>>\nclass Trie : public TrieBase<T,\
    \ Compare> {\npublic:\n    using base_type = TrieBase<T, Compare>;\n    using\
    \ typename base_type::compare;\n    using typename base_type::size_type;\n   \
    \ using typename base_type::value_type;\n\n    std::vector<value_type> kth_element(size_type\
    \ k) const { return base_type::template kth_element<std::vector<value_type>>(k);\
    \ }\n    std::vector<value_type> min_element() const { return base_type::template\
    \ min_element<std::vector<value_type>>(); }\n    std::vector<value_type> max_element()\
    \ const { return base_type::template max_element<std::vector<value_type>>(); }\n\
    };\n\ntemplate <typename Compare>\nclass Trie<char, Compare> : public TrieBase<char,\
    \ Compare> {\npublic:\n    using base_type = TrieBase<char, Compare>;\n    using\
    \ typename base_type::compare;\n    using typename base_type::size_type;\n   \
    \ using typename base_type::value_type;\n\n    // \u591A\u91CD\u96C6\u5408\u5185\
    \u306B\u6587\u5B57\u5217sv\u304C\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\
    \u308B\uFF0E\n    bool exists(std::string_view sv) const { return base_type::exists(sv);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u542B\u307E\u308C\u308B\u6587\
    \u5B57\u5217sv\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    size_type\
    \ count(std::string_view sv) const { return base_type::count(sv); }\n    // \u591A\
    \u91CD\u96C6\u5408\u5185\u306B\u63A5\u982D\u8F9Eprefix\u3092\u3082\u3064\u6587\
    \u5B57\u5217\u304C\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\
    \n    bool exists_by_prefix(std::string_view prefix) const { return base_type::exists_by_prefix(prefix);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u542B\u307E\u308C\u308B\u63A5\
    \u982D\u8F9Eprefix\u3092\u3082\u3064\u6587\u5B57\u5217\u306E\u500B\u6570\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0E\n    size_type count_by_prefix(std::string_view\
    \ prefix) const { return base_type::count_by_prefix(prefix); }\n    // \u591A\u91CD\
    \u96C6\u5408\u306B\u6587\u5B57\u5217sv\u3092n\u500B\u8FFD\u52A0\u3059\u308B\uFF0E\
    \n    void insert(std::string_view sv, size_type n = 1) { base_type::insert(sv,\
    \ n); }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u6587\u5B57\u5217sv\u3092\
    \u3059\u3079\u3066\u524A\u9664\u3059\u308B\uFF0E\n    void erase(std::string_view\
    \ sv) { base_type::erase(sv); }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u6587\
    \u5B57\u5217sv\u3092n\u500B\u524A\u9664\u3059\u308B\uFF0E\n    void erase(std::string_view\
    \ sv, size_type n) { base_type::erase(sv, n); }\n    // \u591A\u91CD\u96C6\u5408\
    \u304B\u3089\u63A5\u982D\u8F9Eprefix\u3092\u3082\u3064\u6587\u5B57\u5217\u3092\
    \u3059\u3079\u3066\u524A\u9664\u3059\u308B\uFF0E\n    void erase_by_prefix(std::string_view\
    \ prefix) { base_type::erase_by_prefix(prefix); }\n    // \u591A\u91CD\u96C6\u5408\
    \u5185\u306B\u304A\u3044\u3066\uFF0C\u8F9E\u66F8\u9806\u3067k\u756A\u76EE\u306B\
    \u5C0F\u3055\u3044\u6587\u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n   \
    \ std::string kth_element(size_type k) const { return base_type::template kth_element<std::string>(k);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u304A\u3044\u3066\uFF0C\u8F9E\
    \u66F8\u9806\u3067\u6700\u3082\u5C0F\u3055\u3044\u6587\u5B57\u5217\u3092\u53D6\
    \u5F97\u3059\u308B\uFF0E\n    std::string min_element() const { return base_type::template\
    \ min_element<std::string>(); }\n    // \u591A\u91CD\u96C6\u5408\u5185\u306B\u304A\
    \u3044\u3066\uFF0C\u8F9E\u66F8\u9806\u3067\u6700\u3082\u5927\u304D\u3044\u6587\
    \u5B57\u5217\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n    std::string max_element()\
    \ const { return base_type::template max_element<std::string>(); }\n    std::pair<size_type,\
    \ size_type> lower_and_upper_bound(std::string_view sv) const { return base_type::lower_and_upper_bound(sv);\
    \ }\n    std::vector<std::pair<size_type, size_type>> get_nodes(std::string_view\
    \ sv) const { return base_type::get_nodes(sv); }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/String/trie.hpp
  requiredBy: []
  timestamp: '2025-07-30 11:40:53+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/String/trie.hpp
layout: document
title: "\u6587\u5B57\u5217\u5206\u5272"
---


## 概要

文字列を要素とする多重集合を管理するデータ構造．


## 参考

1. "トライ (データ構造)". Wikipedia. <https://ja.wikipedia.org/wiki/トライ_(データ構造)>.
1. "すごいTrie". Qiita. <https://qiita.com/minaminao/items/caf6d8147c7e70b6ae63>.
1. "トライ木(Trie木) の解説と実装【接頭辞(prefix) を利用したデータ構造】". アルゴリズムロジック. <https://algo-logic.info/trie-tree/>.


## 問題

- "E - Forbidden Prefix". AtCoder Beginner Contest 403. <https://atcoder.jp/contests/abc403/tasks/abc403_e>.
