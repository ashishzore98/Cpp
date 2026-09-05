class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];
            for (string& word : dictionary) {
                int len = word.length();
                if (i + len <= n &&
                    s.substr(i, len) == word) {
                    dp[i] = min(dp[i], dp[i + len]);
                }
            }
        }
        return dp[0];
    }
};