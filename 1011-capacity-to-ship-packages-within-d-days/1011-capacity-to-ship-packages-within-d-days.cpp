class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int a = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int rd = 1;
            int cw = 0;
            for (int w : weights) {
                if (cw + w > m) {
                    rd++;
                    cw = w;
                } else {
                    cw += w;
                }
            }
            if (rd <= days) {
                a = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return a;
    }
};