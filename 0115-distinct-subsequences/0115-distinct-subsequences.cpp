class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.length();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (char ch : s) {
            for (int j = n; j >= 1; j--) {
                if (ch == t[j - 1]) {
                    if (dp[j] > INT_MAX - dp[j - 1]) {
                        dp[j] = INT_MAX;
                    }
                    else {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }
        return (int)dp[n];
    }
};