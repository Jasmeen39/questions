class Solution {
public:
    //int area = 0;
    int maxarea = 0;
    void solve(vector<vector<int>>& grid,int m, int n, int i, int j,int & area) {
        area++;
        grid[i][j] = -1;
        if (i>=0 && i<m-1 && grid[i+1][j]==1) solve(grid, m, n, i + 1, j, area); // down
        if(i>0 && i<m && grid[i-1][j]==1) solve(grid, m, n, i - 1, j, area); // up
        if(j>=0 && j<n-1 && grid[i][j+1]==1) solve(grid, m, n, i, j + 1, area); // right
        if(j>0 && j<n && grid[i][j-1]==1) solve(grid, m, n, i, j - 1, area); // left
        maxarea = max(maxarea, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area=0;
                    solve(grid, m, n, i, j, area);
                }
            }
        }
        return maxarea;
    }
};