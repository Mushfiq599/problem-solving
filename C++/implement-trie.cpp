#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(const string &word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) node->children[ch] = new TrieNode();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(const string &word) {
        TrieNode* node = find(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(const string &prefix) {
        return find(prefix) != nullptr;
    }

private:
    TrieNode* root;

    TrieNode* find(const string &str) {
        TrieNode* node = root;
        for (char ch : str) {
            if (!node->children.count(ch)) return nullptr;
            node = node->children[ch];
        }
        return node;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;    // 1
    cout << trie.search("app") << endl;      // 0
    cout << trie.startsWith("app") << endl;  // 1
    trie.insert("app");
    cout << trie.search("app") << endl;      // 1
    return 0;
}