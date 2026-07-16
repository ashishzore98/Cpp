class Solution{
public:
    int trap(vector<int> &height){
        int l = 0;
        int r = height.size() - 1;
        int lM = 0;
        int rM = 0;
        int w = 0;
        while (l < r){
            if (height[l] < height[r]){
                if (height[l] >= lM){
                    lM = height[l];
                }
                else{
                    w += lM - height[l];
                }
                l++;
            }
            else{
                if (height[r] >= rM){
                    rM = height[r];
                }
                else{
                    w += rM - height[r];
                }
                r--;
            }
        }
        return w;
    }
};