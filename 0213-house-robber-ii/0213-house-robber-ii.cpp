class Solution {
public:
    // Key idea is if you take first element you cant take last, so do normal
    // robbing from 0 to n-2.
    // if you take last element you cant take first, so do normal robbing from 1
    // to n-1. Then see what gives the max.
    int rec(vector<int>& nums, int start, int idx) {
        if (idx < start)
            return 0;
        if (idx == start)
            return nums[start];
        int pick = nums[idx] + rec(nums, start, idx - 2);
        int notpick = 0 + rec(nums, start, idx - 1);
        return max(pick, notpick);
    }
    int mem(vector<int>& nums, int start, int idx, vector<int>& dp) {
        if (idx < start)
            return 0;
        if (idx == start)
            return nums[start];
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + mem(nums, start, idx - 2, dp);
        int notpick = 0 + mem(nums, start, idx - 1, dp);
        return dp[idx] = max(pick, notpick);
    }
    // void tab(vector<int>& nums,int idx, int end,  vector<int> &dp){
    //     if(idx==0 || idx==1) dp[idx]=nums[idx];
    //     for(int i=2; i<=end; i++){
    //         int pick=INT_MIN;
    //         int notpick=INT_MIN;
    //         if(i-2>=0){
    //             if(idx>0 && i==2) continue;
    //             else pick=nums[i]+dp[i-2];
    //             }
    //         if(i-1>=0){
    //             if(idx>0 && i==2) continue;
    //             else notpick=0+dp[i-1];}
    //         dp[i]=max(pick,notpick);
    //     }
    // }
    void tab(vector<int>& nums, int start, int end, vector<int>& dp) {
        dp[start] = nums[start];
        if (start + 1 <= end) {
            dp[start + 1] = max(nums[start], nums[start + 1]);
        }
        for (int i = start + 2; i <= end; i++) {
            int pick = nums[i] + dp[i - 2];
            int notpick = dp[i - 1];
            dp[i] = max(pick, notpick);
        }
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        // int notlast=mem(nums,0,n-2,dp1);
        // int notfirst=mem(nums,1,n-1,dp2);
        // return max(notlast,notfirst);
        //tab(nums, 0, n - 2, dp1);
        //tab(nums, 1, n - 1, dp2);
        int start1=0;
        dp1[start1]=nums[start1];
        if(start1+1<=n-2) dp1[start1+1]=max(nums[start1],nums[start1+1]);
        for(int i=start1+2; i<=n-2; i++){
            dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
        }
        int start2=1;
        dp2[start2]=nums[start2];
        if(start2+1<=n-1) dp2[start2+1]=max(nums[start2],nums[start2+1]);
        for(int i=start2+2; i<=n-1; i++){
            dp2[i]=max(nums[i]+dp2[i-2],dp2[i-1]);
        }
        return max(dp1[n - 2], dp2[n - 1]);
    }
};