class Solution {
public:
    int ans=0;
    int mem(int  i, int j,vector<vector<int>> & dp){
        //Base case
        //if(i==m || j==n) return ;
        if(i==0 && j==0) return dp[i][j]=1;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=0;
        int up=0;
        if(j>0)left = mem(i,j-1,dp); //left
        if(i>0)up=mem(i-1,j,dp); //up
        return dp[i][j]=left+up;
    }

    void tab(int  i, int j,vector<vector<int>> & dp){
        dp[0][0]=1;
        //if(1<=i)dp[1][0]=1;
        //if(1<=j)dp[0][1]=1;

        for(int row=0; row<=i; row++){
            for(int col=0; col<=j; col++){
                if(row == 0 && col == 0)
                continue;
                int left=0;
                if(col>0)left=dp[row][col-1];
                int up=0;
                if(row>0) up=dp[row-1][col];
                dp[row][col]=left+up;
            }
        }
    }
    void so(int  i, int j,vector<int> & dp){
        for(int row=1; row<=i; row++){
            for(int col=1; col<=j; col++){
                dp[col]=dp[col]+dp[col-1];
            }
        }
    }
    int uniquePaths(int m, int n) {
        //rec(m-1,n-1,m,n);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        //mem(m-1,n-1,dp);
        //tab(m-1,n-1,dp);
        //return dp[m-1][n-1]; 
        vector<int> newdp(n,1);
        so(m-1,n-1,newdp);
        return newdp[n-1];
    }
};