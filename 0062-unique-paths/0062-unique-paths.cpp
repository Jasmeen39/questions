class Solution {
public:
    int ans=0;
    int mem(int  i, int j,vector<vector<int>> & dp){
        //Base case
        //if(i==m || j==n) return ;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int up=0;
        if(j>0)left = mem(i,j-1,dp); //left
        if(i>0)up=mem(i-1,j,dp); //up
        return dp[i][j]=left+up;
    }
    int uniquePaths(int m, int n) {
        //rec(m-1,n-1,m,n);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        ans=mem(m-1,n-1,dp);
        return ans; 
    }
};