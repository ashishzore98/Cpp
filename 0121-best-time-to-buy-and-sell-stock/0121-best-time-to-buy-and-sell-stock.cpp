class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = prices[0];
        int maxp = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minp) {
                minp = prices[i];
            }
            int p = prices[i] - minp;
            if (p > maxp) {
                maxp = p;
            }
        }
        return maxp;
    }
};