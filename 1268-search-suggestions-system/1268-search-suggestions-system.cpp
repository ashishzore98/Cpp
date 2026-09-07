class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        vector<int> suggestions;
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
public:
    vector<vector<string>> suggestedProducts(
        vector<string>& products,
        string searchWord
    ) {
        sort(products.begin(), products.end());
        root = new TrieNode();
        for (int i = 0; i < products.size(); i++) {
            TrieNode* node = root;
            for (char c : products[i]) {
                int index = c - 'a';
                if (node->children[index] == nullptr) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
                if (node->suggestions.size() < 3) {
                    node->suggestions.push_back(i);
                }
            }
        }
        vector<vector<string>> result;
        TrieNode* node = root;
        bool found = true;
        for (char c : searchWord) {
            if (!found) {
                result.push_back({});
                continue;
            }
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                found = false;
                result.push_back({});
                continue;
            }
            node = node->children[index];
            vector<string> current;
            for (int productIndex : node->suggestions) {
                current.push_back(products[productIndex]);
            }
            result.push_back(current);
        }
        return result;
    }
};