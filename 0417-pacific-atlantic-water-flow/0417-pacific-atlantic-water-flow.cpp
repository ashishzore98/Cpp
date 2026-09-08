class Solution {
public:
    int rows, cols;
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }
            if (visited[nr][nc]) {
                continue;
            }
            if (heights[nr][nc] < heights[r][c]) {
                continue;
            }
            dfs(nr, nc, heights, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );
        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );
        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific);
        }
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific);
        }
        for (int c = 0; c < cols; c++) {
            dfs(rows - 1, c, heights, atlantic);
        }
        for (int r = 0; r < rows; r++) {
            dfs(r, cols - 1, heights, atlantic);
        }
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};