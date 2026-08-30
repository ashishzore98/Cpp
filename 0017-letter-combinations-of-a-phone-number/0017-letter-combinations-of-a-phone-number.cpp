class Solution {
public:
    vector<string> result;
    string current;
    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(string& digits, int index) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = phone[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        backtrack(digits, 0);
        return result;
    }
};