class Solution{
public:
    int maxArea(vector<int>& height){
        int l = 0;
        int r = height.size() - 1;
        int mW = 0;
        while (l < r){
            int w = r - l;
            int cH = min(height[l], height[r]);
            int a = w * cH;
            mW = max(mW, a);
            if (height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return mW;
    }
};
