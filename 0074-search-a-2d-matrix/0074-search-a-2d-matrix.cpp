class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ro = matrix.size();
        int c = matrix[0].size();
        int l = 0;
        int r = ro * c - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int ro = m / c;
            int co = m % c;
            if (matrix[ro][co] == target)
                return true;
            if (matrix[ro][co] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
};