class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (searchHelper(word,
                                     index + 1,
                                     node->children[i])) {
                        return true;
                    }
                }
            }
            return false;
        }
        int childIndex = word[index] - 'a';
        if (node->children[childIndex] == nullptr) {
            return false;
        }
        return searchHelper(word,
                            index + 1,
                            node->children[childIndex]);
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */