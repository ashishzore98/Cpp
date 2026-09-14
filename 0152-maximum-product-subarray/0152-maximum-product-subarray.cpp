class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int answer = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int newMax = max({x, maxProd * x, minProd * x});
            int newMin = min({x, maxProd * x, minProd * x});
            maxProd = newMax;
            minProd = newMin;
            answer = max(answer, maxProd);
        }
        return answer;
    }
};