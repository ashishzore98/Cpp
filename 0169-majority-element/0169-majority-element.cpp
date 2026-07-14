class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int ct = 0;
        for (int n : nums) {
            if (ct == 0)
                c = n;
            if (n == c)
                ct++;
            else
                ct--;
        }
        return c;
    }
};