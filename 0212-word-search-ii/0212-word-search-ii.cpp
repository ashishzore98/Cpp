class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word;
    };
    TrieNode* root = new TrieNode();
    vector<string> result;
    void insert(const string& w) {
        TrieNode* node = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = w;
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if (!node->word.empty()) {          
            result.push_back(node->word);
            node->word.clear();             
        }
        board[i][j] = '#';
        static const int dirs[5] = {-1, 0, 1, 0, -1};
        for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (ni >= 0 && ni < (int)board.size() &&
                nj >= 0 && nj < (int)board[0].size())
                dfs(board, ni, nj, node);
        }
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto& w : words) insert(w);
        for (int i = 0; i < (int)board.size(); ++i)
            for (int j = 0; j < (int)board[0].size(); ++j)
                dfs(board, i, j, root);
        return result;
    }
};