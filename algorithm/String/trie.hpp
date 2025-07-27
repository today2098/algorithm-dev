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
    using compare_type = Compare;

protected:
    struct Node;
    using node_pointer = std::unique_ptr<Node>;

    struct Node {
        size_type total;                                        // total:=(自身を根とする部分木に含まれる要素の数).
        size_type cnt;                                          // cnt:=(自身を末尾とする要素の数).
        std::map<value_type, node_pointer, compare_type> next;  // next[]:=(子のポインタ).

        Node() : total(0), cnt(0) {}
    };

    node_pointer m_root;  // m_root:=(根のポインタ).

    template <std::forward_iterator Iter>
    Node *find(Node *p, Iter iter, Iter end) const {
        if(!p) return nullptr;
        if(iter == end) return p;
        return find(p->next[*iter].get(), std::next(iter), end);
    }
    template <std::forward_iterator Iter>
    void add(node_pointer &p, Iter iter, Iter end, size_type cnt) {  // top down.
        if(!p) p = std::make_unique<Node>();
        p->total += cnt;
        if(iter == end) {
            p->cnt += cnt;
            return;
        }
        add(p->next[*iter], std::next(iter), end, cnt);
    }
    template <std::forward_iterator Iter>
    void sub(node_pointer &p, Iter iter, Iter end, size_type cnt) {  // top down.
        assert(p and p->total >= cnt);
        p->total -= cnt;
        if(p->total == 0) {
            p.reset();
            return;
        }
        if(iter == end) {
            p->cnt -= cnt;
            return;
        }
        sub(p->next[*iter], std::next(iter), end, cnt);
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
        size_type buf = 0;
        for(const auto &[key, next] : p->next | std::ranges::views::take_while([&](const auto &pair) { return pair.first <= *iter; })) {
            if(key == *iter) {
                auto &&[l, r] = lower_and_upper_bound(next, std::next(iter), end);
                return {l + buf, r + buf};
            }
            buf += next->total;
        }
        return {buf, buf};
    }
    template <std::forward_iterator Iter>
    size_type total_prefix(Node *p, Iter iter, Iter end) const {
        if(!p) return 0;
        if(iter == end) return p->cnt;
        return p->cnt + total_prefix(p->next[*iter].get(), std::next(iter), end);
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
        auto p = find(m_root.get(), std::ranges::cbegin(r), std::ranges::cend(r));
        return (p ? p->cnt : 0);
    }
    template <std::ranges::forward_range R>
    bool exists_by_prefix(const R &prefix) const { return count_by_prefix(prefix) > 0; }
    template <std::ranges::forward_range R>
    size_type count_by_prefix(const R &prefix) const {
        auto p = find(m_root.get(), std::ranges::cbegin(prefix), std::ranges::cend(prefix));
        return (p ? p->total : 0);
    }
    template <std::ranges::forward_range R>
    void insert(const R &r, size_type cnt = 1) {
        if(cnt == 0) return;
        add(m_root, std::ranges::cbegin(r), std::ranges::cend(r), cnt);
    }
    template <std::ranges::forward_range R>
    void erase(const R &r) { erase(r, count(r)); }
    template <std::ranges::forward_range R>
    void erase(const R &r, size_type cnt) {
        if(cnt == 0) return;
        sub(m_root, std::ranges::cbegin(r), std::ranges::cend(r), cnt);
    }
    template <std::ranges::forward_range R>
    void erase_by_prefix(const R &r) { erase_by_prefix(m_root, std::ranges::cbegin(r), std::ranges::cend(r)); }
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
    size_type total_prefix(const R &r) const { return total_prefix(m_root.get(), std::ranges::cbegin(r), std::ranges::cend(r)); }
    void clear() { m_root.reset(); }
};

template <typename T, typename Compare = std::less<T>>
class Trie : public TrieBase<T, Compare> {
public:
    using base_type = TrieBase<T, Compare>;
    using typename base_type::compare_type;
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
    using typename base_type::compare_type;
    using typename base_type::size_type;
    using typename base_type::value_type;

    bool exists(std::string_view sv) const { return base_type::exists(sv); }
    size_type count(std::string_view sv) const { return base_type::count(sv); }
    bool exists_by_prefix(std::string_view sv) const { return base_type::exists_by_prefix(sv); }
    size_type count_by_prefix(std::string_view sv) const { return base_type::count_by_prefix(sv); }
    void insert(std::string_view sv, size_type cnt = 1) { base_type::insert(sv, cnt); }
    void erase(std::string_view sv) { base_type::erase(sv); }
    void erase(std::string_view sv, size_type cnt) { base_type::erase(sv, cnt); }
    void erase_by_prefix(std::string_view sv) { base_type::erase_by_prefix(sv); }
    std::string kth_element(size_type k) const { return base_type::template kth_element<std::string>(k); }
    std::string min_element() const { return base_type::template min_element<std::string>(); }
    std::string max_element() const { return base_type::template max_element<std::string>(); }
    std::pair<size_type, size_type> lower_and_upper_bound(std::string_view sv) const { return base_type::lower_and_upper_bound(sv); }
    size_type total_prefix(std::string_view sv) const { return base_type::total_prefix(sv); }
};

}  // namespace algorithm

#endif
