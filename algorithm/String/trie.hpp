#ifndef ALGORITHM_TRIE_HPP
#define ALGORITHM_TRIE_HPP 1

#include <cassert>
#include <cstddef>
#include <functional>
#include <iterator>
#include <map>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>
#include <utility>

namespace algorithm {

template <typename T, typename Compare>
class TrieBase {
    static_assert(std::is_invocable_r<bool, Compare, T, T>::value);

public:
    using value_type = T;
    using size_type = std::size_t;
    using compare = Compare;

protected:
    struct Node;
    using node_pointer = std::unique_ptr<Node>;

    struct Node {
        size_type total;                                   // total:=(自身を根とする部分木に含まれる要素の数).
        size_type cnt;                                     // cnt:=(自身を末尾とする要素の数).
        std::map<value_type, node_pointer, compare> next;  // next[]:=(子のポインタ).

        Node() : total(0), cnt(0) {}
    };

    node_pointer m_root;  // m_root:=(根のポインタ).

    template <std::forward_iterator Iter>
    Node *find(const node_pointer &p, Iter iter, Iter end) const {
        if(!p) return nullptr;
        if(iter == end) return p.get();
        return find(p->next[*iter], std::next(iter), end);
    }
    template <std::forward_iterator Iter>
    void add(node_pointer &p, Iter iter, Iter end, size_type n) {  // top down.
        if(!p) p = std::make_unique<Node>();
        p->total += n;
        if(iter == end) {
            p->cnt += n;
            return;
        }
        add(p->next[*iter], std::next(iter), end, n);
    }
    template <std::forward_iterator Iter>
    size_type sub(node_pointer &p, Iter iter, Iter end, size_type n) {  // top down.
        assert(p and p->total >= n);
        p->total -= n;
        if(p->total == 0) {
            p.reset();
            return n;
        }
        if(iter == end) {
            p->cnt -= n;
            return n;
        }
        return sub(p->next[*iter], std::next(iter), end, n);
    }
    template <std::forward_iterator Iter>
    size_type erase(node_pointer &p, Iter iter, Iter end) {  // bottom up.
        if(!p) return 0;
        if(iter == end) {
            size_type res = p->cnt;
            p->total -= res, p->cnt = 0;
            if(p->total == 0) p.reset();
            return res;
        }
        size_type res = erase(p->next[*iter], std::next(iter), end);
        p->total -= res;
        if(p->total == 0) p.reset();
        return res;
    }
    template <std::forward_iterator Iter>
    size_type erase_by_prefix(node_pointer &p, Iter iter, Iter end) {  // bottom up.
        if(!p) return 0;
        if(iter == end) {
            size_type res = p->total;
            p.reset();
            return res;
        }
        size_type res = erase_by_prefix(p->next[*iter], std::next(iter), end);
        p->total -= res;
        if(p->total == 0) p.reset();
        return res;
    }
    template <class Sequence>
    Sequence get(const node_pointer &p, size_type k, size_type depth = 0) const {  // bottom up.
        if(k < p->cnt) return Sequence(depth, value_type());
        k -= p->cnt;
        for(const auto &[key, next] : p->next) {
            if(!next) continue;
            if(k < next->total) {
                auto &&res = get<Sequence>(next, k, depth + 1);
                res[depth] = key;
                return res;
            }
            k -= next->total;
        }
        assert(false);  // not reach here.
    }
    template <std::forward_iterator Iter>
    std::pair<size_type, size_type> lower_and_upper_bound(node_pointer &p, Iter iter, Iter end) const {  // bottom up.
        if(!p) return {0, 0};
        if(iter == end) return {0, p->cnt};
        size_type offset = 0;
        for(const auto &[key, next] : p->next) {
            if(key > *iter) break;
            if(key == *iter) {
                auto &&[l, r] = lower_and_upper_bound(next, std::next(iter), end);
                return {l + offset, r + offset};
            }
            offset += next->total;
        }
        return {offset, offset};
    }
    template <std::forward_iterator Iter>
    std::vector<std::pair<size_type, size_type>> get_nodes(const node_pointer &p, Iter iter, Iter end, size_type depth = 0) const {  // bottom up.
        if(!p) {
            while(iter++ != end) ++depth;
            return std::vector<std::pair<size_type, size_type>>(depth + 1, {0, 0});  // return pairs of (total, cnt).
        }
        auto &&res = (iter == end ? std::vector<std::pair<size_type, size_type>>(depth + 1, {0, 0})
                                  : get_nodes(p->next[*iter], std::next(iter), end, depth + 1));
        res[depth] = {p->total, p->cnt};
        return res;
    }

public:
    TrieBase() : m_root(nullptr) {}
    ~TrieBase() {
        clear();
    }

    bool empty() const { return size() == 0; }
    size_type size() const { return (m_root ? m_root->total : 0); }
    template <std::ranges::forward_range R>
    bool exists(const R &r) const { return count(r) > 0; }
    template <std::ranges::forward_range R>
    size_type count(const R &r) const {
        auto p = find(m_root, std::ranges::cbegin(r), std::ranges::cend(r));
        return (p ? p->cnt : 0);
    }
    template <std::ranges::forward_range R>
    bool exists_by_prefix(const R &r) const { return count_by_prefix(r) > 0; }
    template <std::ranges::forward_range R>
    size_type count_by_prefix(const R &r) const {
        auto p = find(m_root, std::ranges::cbegin(r), std::ranges::cend(r));
        return (p ? p->total : 0);
    }
    template <std::ranges::forward_range R>
    void insert(const R &r, size_type n = 1) {
        if(n == 0) return;
        add(m_root, std::ranges::cbegin(r), std::ranges::cend(r), n);
    }
    template <std::ranges::forward_range R>
    size_type erase(const R &r) { return erase(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }
    template <std::ranges::forward_range R>
    size_type erase(const R &r, size_type n) {
        if(n == 0) return 0;
        return sub(m_root, std::ranges::cbegin(r), std::ranges::cend(r), n);
    }
    template <std::ranges::forward_range R>
    size_type erase_by_prefix(const R &r) { return erase_by_prefix(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }
    template <class Sequence>
    Sequence kth_element(size_type k) const {
        assert(k < size());
        return get<Sequence>(m_root, k);
    }
    template <class Sequence>
    Sequence min_element() const { return kth_element<Sequence>(0); }
    template <class Sequence>
    Sequence max_element() const { return kth_element<Sequence>(size() - 1); }
    template <std::ranges::forward_range R>
    std::pair<size_type, size_type> lower_and_upper_bound(const R &r) const { return lower_and_upper_bound(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }
    template <std::ranges::forward_range R>
    std::vector<std::pair<size_type, size_type>> get_nodes(const R &r) const { return get_nodes(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }
    void clear() { m_root.reset(); }
};

template <typename T, typename Compare = std::less<T>>
class Trie : public TrieBase<T, Compare> {
public:
    using base_type = TrieBase<T, Compare>;
    using typename base_type::compare;
    using typename base_type::size_type;
    using typename base_type::value_type;

    std::vector<value_type> kth_element(size_type k) const { return base_type::template kth_element<std::vector<value_type>>(k); }
    std::vector<value_type> min_element() const { return base_type::template min_element<std::vector<value_type>>(); }
    std::vector<value_type> max_element() const { return base_type::template max_element<std::vector<value_type>>(); }
};

template <typename Compare>
class Trie<char, Compare> : public TrieBase<char, Compare> {
public:
    using base_type = TrieBase<char, Compare>;
    using typename base_type::compare;
    using typename base_type::size_type;
    using typename base_type::value_type;

    // 多重集合内に文字列svが含まれるか判定する．
    bool exists(std::string_view sv) const { return base_type::exists(sv); }
    // 多重集合内に含まれる文字列svの個数を取得する．
    size_type count(std::string_view sv) const { return base_type::count(sv); }
    // 多重集合内に接頭辞prefixをもつ文字列が含まれるか判定する．
    bool exists_by_prefix(std::string_view prefix) const { return base_type::exists_by_prefix(prefix); }
    // 多重集合内に含まれる接頭辞prefixをもつ文字列の個数を取得する．
    size_type count_by_prefix(std::string_view prefix) const { return base_type::count_by_prefix(prefix); }
    // 多重集合に文字列svをn個追加する．
    void insert(std::string_view sv, size_type n = 1) { base_type::insert(sv, n); }
    // 多重集合から文字列svをすべて削除する．
    void erase(std::string_view sv) { base_type::erase(sv); }
    // 多重集合から文字列svをn個削除する．
    void erase(std::string_view sv, size_type n) { base_type::erase(sv, n); }
    // 多重集合から接頭辞prefixをもつ文字列をすべて削除する．
    void erase_by_prefix(std::string_view prefix) { base_type::erase_by_prefix(prefix); }
    // 多重集合内において，辞書順でk番目に小さい文字列を取得する．
    std::string kth_element(size_type k) const { return base_type::template kth_element<std::string>(k); }
    // 多重集合内において，辞書順で最も小さい文字列を取得する．
    std::string min_element() const { return base_type::template min_element<std::string>(); }
    // 多重集合内において，辞書順で最も大きい文字列を取得する．
    std::string max_element() const { return base_type::template max_element<std::string>(); }
    std::pair<size_type, size_type> lower_and_upper_bound(std::string_view sv) const { return base_type::lower_and_upper_bound(sv); }
    std::vector<std::pair<size_type, size_type>> get_nodes(std::string_view sv) const { return base_type::get_nodes(sv); }
};

}  // namespace algorithm

#endif
