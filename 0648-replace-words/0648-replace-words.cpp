class Solution {
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
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEnd = true;
    }
    string findRoot(const string& word) {
        TrieNode* current = root;
        string prefix;
        for (char ch : word) {
            int index = ch - 'a';
            if (current->children[index] == nullptr) {
                return word;
            }
            prefix += ch;
            current = current->children[index];
            if (current->isEnd) {
                return prefix;
            }
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        for (const string& word : dictionary) {
            insert(word);
        }
        stringstream ss(sentence);
        string word;
        string result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += findRoot(word);
        }
        return result;
    }
};