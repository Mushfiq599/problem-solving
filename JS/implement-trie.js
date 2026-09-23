class TrieNode {
    constructor() {
        this.children = {};
        this.isEnd = false;
    }
}

class Trie {
    constructor() {
        this.root = new TrieNode();
    }

    insert(word) {
        let node = this.root;
        for (const ch of word) {
            if (!node.children[ch]) node.children[ch] = new TrieNode();
            node = node.children[ch];
        }
        node.isEnd = true;
    }

    search(word) {
        const node = this._find(word);
        return node !== null && node.isEnd;
    }

    startsWith(prefix) {
        return this._find(prefix) !== null;
    }

    _find(str) {
        let node = this.root;
        for (const ch of str) {
            if (!node.children[ch]) return null;
            node = node.children[ch];
        }
        return node;
    }
}

// Example usage / simple test harness
const trie = new Trie();
trie.insert("apple");
console.log(trie.search("apple"));    // true
console.log(trie.search("app"));      // false
console.log(trie.startsWith("app"));  // true
trie.insert("app");
console.log(trie.search("app"));      // true