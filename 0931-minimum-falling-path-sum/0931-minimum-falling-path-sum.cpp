class Solution {
public:
    int minsum=INT_MAX;
    //int sum=0;
    int solve (int m, int row, int col, vector<vector<int>>& matrix,vector<vector<int>>& dp ){
        //Base case
        if(row==m){
            return 0;
        }
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int left=INT_MAX;
        if( col>=1) left=solve(m,row+1,col-1,matrix,dp);
        int down=solve(m,row+1,col,matrix,dp);
        int right=INT_MAX;
        if(col < m-1) right=solve(m,row+1,col+1,matrix,dp);
        return dp[row][col]=matrix[row][col]+min({left,down,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(m,INT_MAX));
            // for(int j=0; j<m; j++){
            //     ans=min(ans,solve(m,0,j,matrix,dp));
            // }
        for(int col=0; col<m; col++){
            dp[m-1][col]=matrix[m-1][col];
        }
        for(int row=m-2; row>=0; row--){
            for(int col=0; col<m; col++){
                int down=dp[row+1][col];
                int left=INT_MAX;
                if(col>0) left=dp[row+1][col-1];
                int right=INT_MAX;
                if(col<m-1) right=dp[row+1][col+1];
                dp[row][col]=matrix[row][col]+min({left,down,right});
            }
        }
        for(int col=0; col<m; col++){
            ans=min(ans,dp[0][col]);
        }
        return ans;
    }
};