class Solution {
private:
    struct TrieNode {
        int child[26];
        int wordIndex;
        vector<int> palindromeSuffix;
        TrieNode() {
            fill(child, child + 26, -1);
            wordIndex = -1;
        }
    };
    vector<TrieNode> trie;
    bool isPalindrome(const string& word, int left, int right) {
        while (left < right) {
            if (word[left] != word[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void insertWord(const string& word, int index) {
        int node = 0;
        for (int i = word.length() - 1; i >= 0; i--) {
            if (isPalindrome(word, 0, i)) {
                trie[node].palindromeSuffix.push_back(index);
            }
            int c = word[i] - 'a';
            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }
            node = trie[node].child[c];
        }
        trie[node].wordIndex = index;
        trie[node].palindromeSuffix.push_back(index);
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        trie.clear();
        trie.push_back(TrieNode());
        for (int i = 0; i < words.size(); i++) {
            insertWord(words[i], i);
        }
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            int node = 0;
            for (int j = 0; j < words[i].length(); j++) {
                int index = trie[node].wordIndex;
                if (index != -1 && index != i && isPalindrome(words[i], j, words[i].length() - 1)) {
                    result.push_back({i, index});
                }
                int c = words[i][j] - 'a';
                if (trie[node].child[c] == -1) {
                    node = -1;
                    break;
                }
                node = trie[node].child[c];
            }
            if (node != -1) {
                for (int index : trie[node].palindromeSuffix) {
                    if (index != i) {
                        result.push_back({i, index});
                    }
                }
            }
        }
        return result;
    }
};