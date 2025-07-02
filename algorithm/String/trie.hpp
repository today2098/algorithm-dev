#ifndef ALGORITHM_TRIE_HPP
#define ALGORITHM_TRIE_HPP 1

/**
 * @brief Trie木
 * @docs docs/String/trie.md
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <string>
#include <string_view>
#include <utility>

namespace algorithm {

// Trie木．
template <char BASE = 0, size_t N = 128>
class Trie {
public:
    using size_type = size_t;

private:
    struct Node {
        size_type cnt;             // cnt:=(自身を末尾とする要素の数).
        size_type total;           // total:=(自身を根とする部分木に含まれる要素の数).
        std::array<Node *, N> ch;  // ch[]:=(子のポインタ).

        Node() : cnt(0), total(0) {
            std::fill(ch.begin(), ch.end(), nullptr);
        }

        Node *&child(char key) { return ch.at(key - BASE); }
        const Node *&child(char key) const { return ch.at(key - BASE); }
    };

    Node *m_root;  // m_root:=(根のポインタ).

    Node *find(std::string_view sv) const {
        if(!m_root) return nullptr;
        Node *p = m_root;
        for(char c : sv) {
            p = p->child(c);
            if(!p) return nullptr;
        }
        return p;
    }
    Node *add(Node *p, std::string_view sv, int n, size_type cnt, int i = 0) {  // top down.
        if(!p) p = new Node();
        if(i == n) {
            p->cnt += cnt, p->total += cnt;
            return p;
        }
        p->total += cnt;
        p->child(sv[i]) = add(p->child(sv[i]), sv, n, cnt, i + 1);
        return p;
    }
    Node *sub(Node *p, std::string_view sv, int n, size_type cnt, int i = 0) {  // bottom up.
        assert(p and p->total >= cnt);
        if(i < n) p->child(sv[i]) = sub(p->child(sv[i]), sv, n, cnt, i + 1);
        else p->cnt -= cnt;
        p->total -= cnt;
        if(p->total == 0) {
            delete p;
            p = nullptr;
        }
        return p;
    }
    Node *erase_prefix_internal(Node *p, std::string_view sv, int n, int i = 0) {  // bottom up.
        if(!p) return nullptr;
        if(i == n) return clear_dfs(p);
        if(!p->child(sv[i])) return p;
        size_type pre = p->child(sv[i])->total;
        p->child(sv[i]) = erase_prefix_internal(p->child(sv[i]), sv, n, i + 1);
        p->total -= pre - (p->child(sv[i]) ? p->child(sv[i])->total : 0);
        if(p->total == 0) {
            delete p;
            p = nullptr;
        }
        return p;
    }
    std::pair<size_type, size_type> get_lower_and_upper(std::string_view sv) const {
        if(!m_root) return {0, 0};
        size_type itr = 0;
        Node *p = m_root;
        for(char c : sv) {
            itr += p->cnt;
            for(char d = BASE; d < c; ++d) {
                if(p->child(d)) itr += p->child(d)->total;
            }
            p = p->child(c);
            if(!p) break;
        }
        return {itr, itr + (p ? p->cnt : 0)};
    }
    void get(Node *p, size_type k, std::string &s, int i = 0) const {
        assert(p);
        if(k < p->cnt) {
            s.resize(i);
            return;
        }
        k -= p->cnt;
        for(size_t j = 0; j < N; ++j) {
            if(!p->ch[j]) continue;
            if(k < p->ch[j]->total) {
                get(p->ch[j], k, s, i + 1);
                s[i] = BASE + j;
                return;
            }
            k -= p->ch[j]->total;
        }
        assert(false);  // not reach here.
    }
    Node *clear_dfs(Node *p) {
        if(!p) return nullptr;
        for(Node *&next : p->ch) next = clear_dfs(next);
        delete p;
        return p = nullptr;
    }

public:
    Trie() : m_root(nullptr) {}
    ~Trie() {
        clear();
    }

    std::string operator[](size_type k) const { return kth_element(k); }

    // 集合が空かどうか判定する．O(1).
    bool empty() const { return size() == 0; }
    // 全要素数を返す．O(1).
    size_type size() const { return (m_root ? m_root->total : 0); }
    // 文字列svが集合に含まれるか判定する．O(|S|).
    size_type exists(std::string_view sv) const { return count(sv) > 0; }
    // 接頭辞がsvである文字列が集合に含まれるか判定する．O(|S|).
    size_type exists_prefix(std::string_view sv) const { return count_prefix(sv) > 0; }
    // 文字列svの要素数を返す．O(|S|).
    size_type count(std::string_view sv) const {
        Node *p = find(sv);
        return (p ? p->cnt : 0);
    }
    // 接頭辞がsvである文字列の要素数を返す．O(|S|).
    size_type count_prefix(std::string_view sv) const {
        Node *p = find(sv);
        return (p ? p->total : 0);
    }
    // 多重集合に文字列svを追加する．O(|S|).
    void insert(std::string_view sv, size_type cnt = 1) {
        if(cnt == 0) return;
        m_root = add(m_root, sv, sv.size(), cnt);
    }
    // 多重集合から文字列svを削除する．O(|S|).
    void erase(std::string_view sv) { erase(sv, count(sv)); }
    void erase(std::string_view sv, size_type cnt) {
        assert(count(sv) >= cnt);
        if(cnt == 0) return;
        m_root = sub(m_root, sv, sv.size(), cnt);
    }
    // 多重集合から接頭辞がsvである文字列を削除する．O(|S|*N).
    void erase_prefix(std::string_view sv) { m_root = erase_prefix_internal(m_root, sv, sv.size()); }
    // 辞書順でsv以上である文字列とsvより大きい文字列が現れる先頭の位置を取得する．O(|S|*N).
    std::pair<size_type, size_type> lower_and_upper_bound(std::string_view sv) const { return get_lower_and_upper(sv); }
    // 多重集合内において辞書順でk番目に小さい文字列を取得する．0-based index. O(|S|*N).
    std::string kth_element(size_type k) const {
        assert(k < size());
        std::string res;
        get(m_root, k, res);
        return res;
    }
    // 集合内において辞書順で最小の文字列を取得する．O(|S|*N).
    std::string min_element() const { return kth_element(0); }
    // 集合内において辞書順で最大の文字列を取得する．O(|S|*N).
    std::string max_element() const { return kth_element(size() - 1); }
    // 全要素を削除する．O(|S|*N).
    void clear() { m_root = clear_dfs(m_root); }
};

using DefaultTrie = Trie<'A', 58>;
using DefaultTrie2 = Trie<'0', 75>;

}  // namespace algorithm

#endif
