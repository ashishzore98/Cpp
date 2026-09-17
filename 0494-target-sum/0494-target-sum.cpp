class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if (abs(target) > total) {
            return 0;
        }
        if ((total + target) % 2 != 0) {
            return 0;
        }
        int subsetSum = (total + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int sum = subsetSum; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }
        return dp[subsetSum];
    }
};