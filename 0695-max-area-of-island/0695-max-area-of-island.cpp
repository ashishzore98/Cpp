class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        int area = 1;
        area += dfs(grid, row - 1, col); 
        area += dfs(grid, row + 1, col); 
        area += dfs(grid, row, col - 1); 
        area += dfs(grid, row, col + 1); 
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == 1) {
                    int area = dfs(grid, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};