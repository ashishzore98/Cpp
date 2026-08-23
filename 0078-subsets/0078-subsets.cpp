class Solution {
public:
    vector<vector<int>> r;
    void backtrack(int index, vector<int>& subset, vector<int>& nums) {
        r.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(i + 1, subset, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(0, subset, nums);
        return r;
    }
};