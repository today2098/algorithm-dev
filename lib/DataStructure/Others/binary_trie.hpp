#ifndef ALGORITHM_BINARY_TRIE_HPP
#define ALGORITHM_BINARY_TRIE_HPP 1

#include <bitset>
#include <cassert>

namespace algorithm {

// Binary Trie（非負整数値を要素とする多重集合）.
template <std::size_t B = 32>  // B:ビット長.
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
    std::bitset<B> m_bias;  // m_bias:=(xorの操作値).

    Node *find(const std::bitset<B> &x) const {
        if(!m_root) return nullptr;
        Node *p = m_root;
        for(size_type i = B; i--;) {
            p = p->ch[x[i] ^ m_bias[i]];
            if(!p) return nullptr;
        }
        return p;
    }
    Node *add(Node *p, const std::bitset<B> &x, size_type cnt, size_type itr = B) {  // top down.
        assert(cnt > 0);
        if(!p) p = new Node();
        p->cnt += cnt;
        if(itr == 0) return p;
        bool b = x[itr - 1] ^ m_bias[itr - 1];
        p->ch[b] = add(p->ch[b], x, cnt, itr - 1);
        return p;
    }
    Node *sub(Node *p, const std::bitset<B> &x, size_type cnt, size_type itr = B) {  // bottom up.
        assert(p and 0 < cnt and cnt <= p->cnt);
        if(itr > 0) {
            bool b = x[itr - 1] ^ m_bias[itr - 1];
            p->ch[b] = sub(p->ch[b], x, cnt, itr - 1);
        }
        if(p->cnt == cnt) {
            delete p;
            return p = nullptr;
        }
        p->cnt -= cnt;
        return p;
    }
    std::bitset<B> get(Node *p, size_type k, size_type itr = B) const {
        assert(p);
        if(itr == 0) return 0;
        bool b = m_bias[itr - 1];
        size_type m = (p->ch[b] ? p->ch[b]->cnt : 0);
        if(k < m) return get(p->ch[b], k, itr - 1);
        return get(p->ch[!b], k - m, itr - 1).set(itr - 1);
    }
    size_type get_lower(Node *p, const std::bitset<B> &x, size_type itr = B) const {
        if(!p or itr == 0) return 0;
        size_type res = get_lower(p->ch[x[itr - 1] ^ m_bias[itr - 1]], x, itr - 1);
        if(x[itr - 1] and p->ch[m_bias[itr - 1]]) res += p->ch[m_bias[itr - 1]]->cnt;
        return res;
    }
    size_type get_upper(Node *p, const std::bitset<B> &x, size_type itr = B) const {
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

    std::bitset<B> operator[](size_type k) const { return kth_element(k); }

    // 管理する非負整数値のビット長を取得する．
    static constexpr size_type bit_length() { return B; }
    // 集合が空かどうか判定する．O(1).
    bool empty() const { return !m_root; }
    // 全要素数を取得する．O(1).
    size_type size() const { return (m_root ? m_root->cnt : 0); }
    // 値xの要素が集合に含まれるか判定する．O(B).
    bool contains(const std::bitset<B> &x) const { return find(x); }
    // 値xの要素数を取得する．O(B).
    size_type count(const std::bitset<B> &x) const {
        Node *p = find(x);
        return (p ? p->cnt : 0);
    }
    // 多重集合に値xの要素を追加する．O(B).
    void insert(const std::bitset<B> &x, size_type cnt = 1) {
        if(cnt == 0) return;
        m_root = add(m_root, x, cnt);
    }
    // 多重集合から値xの要素を削除する．O(B).
    void erase(const std::bitset<B> &x) { erase(x, count(x)); }
    void erase(const std::bitset<B> &x, size_type cnt) {
        if(cnt == 0) return;
        m_root = sub(m_root, x, cnt);
    }
    // 多重集合内でk番目に小さい要素値を取得する．0-based index. O(B).
    std::bitset<B> kth_element(size_type k) const {
        assert(k < size());
        return get(m_root, k);
    }
    // 集合内で最小の要素値を取得する．O(B).
    std::bitset<B> min_element() const { return kth_element(0); }
    // 集合内で最大の要素値を取得する．O(B).
    std::bitset<B> max_element() const { return kth_element(size() - 1); }
    // 値x以上である要素が現れる先頭の位置を取得する．O(B).
    size_type lower_bound(const std::bitset<B> &x) const { return get_lower(m_root, x); }
    // 値xより大きい要素が現れる先頭の位置を取得する．O(B).
    size_type upper_bound(const std::bitset<B> &x) const { return get_upper(m_root, x); }
    // xorの操作に用いる値を取得する．
    std::bitset<B> bias() const { return m_bias; }
    // 全要素値にxorの操作を行う．O(B).
    void xor_all(const std::bitset<B> &x) { m_bias ^= x; }
    // 全要素を削除する．
    void clear() { m_root = clear(m_root); }

    friend std::ostream &operator<<(std::ostream &os, const BinaryTrie &ob) {
        std::bitset<B> x(0);
        auto dfs = [&](auto self, Node *p, size_type itr = B) -> void {
            if(!p) return;
            if(itr == 0) {
                os << "  {" << x;
                if(B <= 64) os << "(" << x.to_ullong() << ")";
                os << ", " << p->cnt << "}\n";
                return;
            }
            for(bool b : {0, 1}) {
                x[itr - 1] = b;
                b ^= ob.m_bias[itr - 1];
                self(self, p->ch[b], itr - 1);
            }
        };
        os << "[\n";
        dfs(dfs, ob.m_root);
        return os << "]";
    }
};

}  // namespace algorithm

#endif
