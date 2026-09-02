class Solution {
public:
    int rec(vector<vector<int>>& obstacleGrid, int i, int j)
    {
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        int left=0;
        int up=0;
        left=rec(obstacleGrid,i,j-1);
        up=rec(obstacleGrid,i-1,j);
        return left+up;
    }
    int mem(vector<vector<int>>& obstacleGrid, int i, int j,vector<vector<int>> &dp)
    {
        if(obstacleGrid[i][j]==1) return dp[i][j]= 0;
        if(i==0 && j==0) return dp[i][j]= 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int up=0;
        if(j>0) left=mem(obstacleGrid,i,j-1,dp);
        if(i>0) up=mem(obstacleGrid,i-1,j,dp);
        return dp[i][j]=left+up;
    }
    void tab(vector<vector<int>>& obstacleGrid, int i, int j,vector<vector<int>> &dp){
        if(obstacleGrid[0][0] == 1)
        dp[0][0] = 0;
        else
        dp[0][0] = 1;
        for(int row=0; row<=i; row++){
            for(int col=0; col<=j; col++){
                if(row==0 && col==0) continue;
                if(obstacleGrid[row][col]==1) dp[row][col]=0;
                else{
                int left=0;
                int up=0;
                if(col>=1) left=dp[row][col-1];
                if(row>=1) up=dp[row-1][col];
                dp[row][col]=left+up;
                }
            }
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        //mem(obstacleGrid,m-1,n-1,dp);
        tab(obstacleGrid,m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};