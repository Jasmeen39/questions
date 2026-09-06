class Solution {
public:
    //int minsum=INT_MAX;
    int sum;
    int rec(int i, int j, vector<vector<int>>& grid){
        //two case left and up
        //base case is 0
        //if(i<0 || j<0) return 0;
        if(i==0 && j==0) return grid[i][j];
        int left=INT_MAX;
        if(j>0) left=rec(i,j-1,grid);
        int up=INT_MAX;
        if(i>0)up=rec(i-1,j,grid);
        //sum+=up;
        // int leftsum=grid[i][j]+left;
        // int upsum=grid[i][j]+up;
        return grid[i][j]+min(left,up);
    }
    int mem(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
        //two case left and up
        //base case is 0
        if(i==0 && j==0) return dp[i][j]=grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=INT_MAX;
        if(j>0) left=mem(i,j-1,grid,dp);
        int up=INT_MAX;
        if(i>0)up=mem(i-1,j,grid,dp);
        return dp[i][j]=grid[i][j]+min(left,up);
    }
    void tab (int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        dp[0][0]=grid[0][0];
        for(int row=0; row<=i; row++){
            for(int col=0; col<=j; col++){
                if(row==0 && col==0) continue;
                int left=INT_MAX;
                int up=INT_MAX;
                if(col>0) left=dp[row][col-1];
                if(row>0) up=dp[row-1][col];
                dp[row][col]=grid[row][col]+min(left,up);
            }
        }
    }
    void so(int i, int j, vector<vector<int>>& grid,vector<int> & prev ){
        prev[0]=grid[0][0];
        for(int col=1; col<=j; col++){
            prev[col]=prev[col-1]+grid[0][col];
        }
        for(int row=1; row<=i; row++){
            vector<int>curr(j+1,0);
            for(int col=0; col<=j; col++){
                if(col==0){
                    curr[col]=grid[row][col]+prev[col];
                    continue;
                } 
                else{
                    curr[col]=grid[row][col]+min(curr[col-1],prev[col]);
                }
            }
            prev=curr;
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        //return mem(m-1,n-1,grid,dp);
        //tab(m-1,n-1,grid,dp);
        //return dp[m-1][n-1];
        //return minsum;
        vector<int> prev(n);
        so(m-1,n-1,grid,prev);
        return prev[n-1];
    }
};