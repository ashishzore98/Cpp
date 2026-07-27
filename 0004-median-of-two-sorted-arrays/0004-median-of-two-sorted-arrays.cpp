class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int x = nums1.size();
        int y = nums2.size();
        int l = 0;
        int h = x;
        while (l <= h) {
            int pX = (l + h) / 2;
            int pY = (x + y + 1) / 2 - pX;
            int mLfX = (pX == 0) ? INT_MIN : nums1[pX - 1];
            int mRtX = (pX == x) ? INT_MAX : nums1[pX];
            int mLfY = (pY == 0) ? INT_MIN : nums2[pY - 1];
            int mRtY = (pY == y) ? INT_MAX : nums2[pY];
            if (mLfX <= mRtY && mLfY <= mRtX) {
                if ((x + y) % 2 == 0) {
                    return (max(mLfX, mLfY) +
                            min(mRtX, mRtY)) / 2.0;
                }
                return max(mLfX, mLfY);
            }
            else if (mLfX > mRtY) {
                h = pX - 1;
            }
            else {
                l = pX + 1;
            }
        }
        return 0.0;
    }
};