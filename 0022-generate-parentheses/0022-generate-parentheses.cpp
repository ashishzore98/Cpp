class Solution {
public:
    vector<string> res;
    void backtrack(string &current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            res.push_back(current);
            return;
        }
        if (open < n) {
            current.push_back('(');
            backtrack(current, open + 1, close, n);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            backtrack(current, open, close + 1, n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string current = "";
        backtrack(current, 0, 0, n);
        return res;
    }
};