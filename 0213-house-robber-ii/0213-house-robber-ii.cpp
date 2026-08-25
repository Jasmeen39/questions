class Solution {
public:
    // Key idea is if you take first element you cant take last, so do normal robbing from 0 to n-2.
    //if you take last element you cant take first, so do normal robbing from 1 to n-1. Then see what gives the max.
    int rec(vector<int>& nums,int start, int idx){
        if(idx<start) return 0;
        if(idx==start) return nums[start];
        int pick=nums[idx]+rec(nums,start,idx-2);
        int notpick=0+rec(nums,start,idx-1);
        return max(pick,notpick);
    }
    int mem(vector<int>& nums,int start, int idx,  vector<int> &dp){
        if(idx<start) return 0;
        if(idx==start) return nums[start];
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+mem(nums,start,idx-2,dp);
        int notpick=0+mem(nums,start,idx-1,dp);
        return dp[idx]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int notlast=mem(nums,0,n-2,dp1);
        int notfirst=mem(nums,1,n-1,dp2);
        return max(notlast,notfirst);
    }
};