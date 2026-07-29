class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int a = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                a = m;
                h = m - 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return a;
    }
    int findLast(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int a = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                a = m;
                l = m + 1;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                h = m - 1;
            }
        }
        return a;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};