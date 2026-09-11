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
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int j=0; j<=n-1; j++){
        ans=min(ans,mem(triangle,m-1,j,n-1,dp));
        }
        return ans;
       //return solve(triangle,m-1,n-1);
    }
};