#ifndef ALGORITHM_BINARY_TRIE_HPP
#define ALGORITHM_BINARY_TRIE_HPP 1

#include <bitset>
#include <cassert>

namespace algorithm {

template <std::size_t w = 32>
class BinaryTrie {
public:
    using size_type = std::size_t;

private:
    struct Node {
        size_type cnt;  // cnt:=(自身を根とする部分木に含まれる要素の数).
        Node *ch[2];    // ch[]:=(子のポインタ).
        Node() : cnt(0), ch{nullptr, nullptr} {}
    };

    Node *m_root;           // m_root:=(根のポインタ).
    std::bitset<w> m_bias;  // m_bias:=(xorの操作値).

    Node *find(Node *p, const std::bitset<w> &x, std::size_t itr = w) const {
        if(!p) return nullptr;
        if(itr == 0) return p;
        return find(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr - 1);
    }
    Node *add(Node *p, size_type cnt, const std::bitset<w> &x, std::size_t itr = w) {  // top down.
        if(!p) p = new Node();
        p->cnt += cnt;
        if(itr == 0) return p;
        bool b = x[itr - 1] ^ m_bias[itr - 1];
        p->ch[b] = add(p->ch[b], cnt, x, itr - 1);
        return p;
    }
    Node *sub(Node *p, size_type cnt, const std::bitset<w> &x, std::size_t itr = w) {  // bottom up.
        assert(p and cnt <= p->cnt);
        if(itr > 0) {
            bool b = x[itr - 1] ^ m_bias[itr - 1];
            p->ch[b] = sub(p->ch[b], cnt, x, itr - 1);
        }
        if(p->cnt == cnt) {
            delete p;
            return p = nullptr;
        }
        p->cnt -= cnt;
        return p;
    }
    std::bitset<w> get(Node *p, size_type k, std::size_t itr = w) const {
        assert(p);
        if(itr == 0) return 0;
        bool b = m_bias[itr - 1];
        size_type m = (p->ch[b] ? p->ch[b]->cnt : 0);
        if(k < m) return get(p->ch[b], k, itr - 1);
        return get(p->ch[!b], k - m, itr - 1).set(itr - 1);
    }
    size_type get_lower(Node *p, const std::bitset<w> &x, std::size_t itr = w) const {
        if(!p or itr == 0) return 0;
        size_type res = get_lower(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr - 1);
        if(x[itr - 1] and p->ch[m_bias[itr - 1]]) res += p->ch[m_bias[itr - 1]]->cnt;
        return res;
    }
    size_type get_upper(Node *p, const std::bitset<w> &x, std::size_t itr = w) const {
        if(!p) return 0;
        if(itr == 0) return p->cnt;
        size_type res = get_upper(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr - 1);
        if(x[itr - 1] and p->ch[m_bias[itr - 1]]) res += p->ch[m_bias[itr - 1]]->cnt;
        return res;
    }
    Node *clear(Node *p) {
        if(!p) return nullptr;
        for(Node *&next : p->ch) next = clear(next);
        delete p;
        return p = nullptr;
    }

public:
    BinaryTrie() : m_root(nullptr), m_bias(0) {}
    ~BinaryTrie() {
        clear();
    }

    // 管理する非負整数値のビット長を取得する．
    static constexpr size_type word_size() { return w; }
    // 集合が空か判定する．O(1).
    bool empty() const { return !m_root; }
    // 集合の要素数を取得する．O(1).
    size_type size() const { return (m_root ? m_root->cnt : 0); }
    // 多重集合に非負整数xが含まれるか判定する．O(w).
    bool contains(const std::bitset<w> &x) const { return find(m_root, x); }
    // 多重集合に含まれる非負整数xの個数を取得する．O(w).
    size_type count(const std::bitset<w> &x) const {
        Node *p = find(m_root, x);
        return (p ? p->cnt : 0);
    }
    // 多重集合に非負整数xを追加する．O(w).
    void insert(const std::bitset<w> &x, size_type cnt = 1) {
        if(cnt == 0) return;
        m_root = add(m_root, cnt, x);
    }
    // 多重集合に非負整数xを削除する．O(w).
    void erase(const std::bitset<w> &x) { erase(x, count(x)); }
    void erase(const std::bitset<w> &x, size_type cnt) {
        if(cnt == 0) return;
        m_root = sub(m_root, cnt, x);
    }
    // 多重集合内でk番目に小さい非負整数を取得する．0-based index. O(w).
    std::bitset<w> kth_element(size_type k) const {
        assert(k < size());
        return get(m_root, k);
    }
    // 集合内で最小の非負整数を取得する．O(w).
    std::bitset<w> min_element() const {
        assert(!empty());
        return get(m_root, 0);
    }
    // 集合内で最大の非負整数を取得する．O(w).
    std::bitset<w> max_element() const {
        assert(!empty());
        return get(m_root, size() - 1);
    }
    // x以上である非負整数が現れる先頭の位置を取得する．O(w).
    size_type lower_bound(const std::bitset<w> &x) const { return get_lower(m_root, x); }
    // xより大きい非負整数が現れる先頭の位置を取得する．O(w).
    size_type upper_bound(const std::bitset<w> &x) const { return get_upper(m_root, x); }
    // 全要素に非負整数xを用いてxorの操作を行う．
    void xor_all(const std::bitset<w> &x) { m_bias ^= x; }
    void clear() { m_root = clear(m_root); }

    friend std::ostream &operator<<(std::ostream &os, const BinaryTrie &rhs) {
        std::bitset<w> x(0);
        auto dfs = [&](auto self, Node *p, size_type itr = w) -> void {
            if(!p) return;
            if(itr == 0) {
                os << "  {" << x;
                if(w <= 64) os << " (" << x.to_ullong() << ")";
                os << ", " << p->cnt << "}\n";
                return;
            }
            for(bool b : {0, 1}) {
                x[itr - 1] = b;
                self(self, p->ch[b ^ rhs.m_bias[itr - 1]], itr - 1);
            }
        };
        os << "[\n";
        dfs(dfs, rhs.m_root);
        return os << "]";
    }
};

}  // namespace algorithm

#endif
