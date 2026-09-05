class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int count;
        TrieNode() {
            count = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) {
            TrieNode* current = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (current->children[index] == nullptr) {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
                current->count++;
            }
        }
        vector<int> answer;
        for (string& word : words) {
            TrieNode* current = root;
            int score = 0;
            for (char ch : word) {
                int index = ch - 'a';
                current = current->children[index];
                score += current->count;
            }
            answer.push_back(score);
        }
        return answer;
    }
};