class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int randomIndex = left + rand() % (right - left + 1);
            int pivot = nums[randomIndex];
            int low = left;
            int mid = left;
            int high = right;
            while (mid <= high) {
                if (nums[mid] < pivot) {
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                }
                else if (nums[mid] > pivot) {
                    swap(nums[mid], nums[high]);
                    high--;
                }
                else {
                    mid++;
                }
            }
            if (target < low) {
                right = low - 1;
            }
            else if (target > high) {
                left = high + 1;
            }
            else {
                return pivot;
            }
        }
        return -1;
    }
};