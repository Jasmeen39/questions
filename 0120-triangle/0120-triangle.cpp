class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j, int end){
        //Two case: 1. same index "j" , 2. Next index "j+1"
        //Base case i=0 j==0 return vector[0][0]
        if(i==0 && j==0) return triangle[0][0];
        //Same index(j) but previous row
        int same=INT_MAX;
        if(i>0 && j!=end)same=solve(triangle,i-1,j, end-1);
        //Previous index(j-1) and previous row
        int notsame=INT_MAX;
        if(i>0 && j>0 && end>0) notsame=solve(triangle,i-1,j-1,end-1);
        int best = min(same, notsame);
        if(best == INT_MAX)
            return INT_MAX;

        return triangle[i][j] + best;
    }
    int mem(vector<vector<int>>& triangle, int i, int j, int end,vector<vector<int>>&dp){
        //Two case: 1. same index "j" , 2. Next index "j+1"
        //Base case i=0 j==0 return vector[0][0]
        if(i==0 && j==0) return dp[i][j]=triangle[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        //Same index(j) but previous row
        int same=INT_MAX;
        if(i>0 && j!=end)same=mem(triangle,i-1,j, end-1,dp);
        //Previous index(j-1) and previous row
        int notsame=INT_MAX;
        if(i>0 && j>0 && end>0) notsame=mem(triangle,i-1,j-1,end-1,dp);
        int best = min(same, notsame);
        if(best == INT_MAX)
            return dp[i][j]=INT_MAX;

        return dp[i][j]=triangle[i][j] + best;
    }

    void tabulation(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>&dp){
        dp[0][0]=triangle[0][0];
        for(int row=1; row<=i; row++){
            for(int col=0; col<=row; col++){
                if(col==0) dp[row][col]=triangle[row][col]+dp[row-1][col];
                else if(col==row) dp[row][col]=triangle[row][col]+dp[row-1][col-1];
                else dp[row][col]=triangle[row][col]+min(dp[row-1][col],dp[row-1][col-1]);
            }
        }
    }
    void so(vector<vector<int>>& triangle, int i, vector<int>&prev){
        prev[0]=triangle[0][0];
        for(int row=1; row<=i; row++){
            vector<int> curr(row+1);
            curr[0]=triangle[row][0]+prev[0];
            for(int col=1; col<row; col++){
                curr[col]=triangle[row][col]+min(prev[col], prev[col-1]);
            }
            curr[row]=triangle[row][row]+prev[row-1];
            prev=curr;
        }
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        int ans=INT_MAX;
    vector<int> prev(n);
    so(triangle,m-1,prev);
    for(int col=0; col<n; col++){
        ans=min(ans,prev[col]);
    }
       return ans;
    }
};