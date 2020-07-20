class Trie {
public:
    struct TrieNode {
        int p, e;
        TrieNode *next[26];
        TrieNode() {
            p = 0;
            e = 0;
            for (int i = 0; i < 26; ++i) next[i] = nullptr;
        }
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (auto &c : word) {
            node->p++;
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->p++;
        node->e++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for (auto &c : word) {
            if (!node->next[c - 'a']) return false;
            node = node->next[c - 'a'];
        }
        return node->e;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (auto &c : prefix) {
            if (!node->next[c - 'a']) return false;
            node = node->next[c - 'a'];
        }
        return node->p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */