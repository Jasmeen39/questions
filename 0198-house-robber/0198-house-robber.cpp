class Solution {
public:
    int rec(vector<int>& nums, int idx) {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;
        int pick = nums[idx] + rec(nums, idx - 2);
        int notpick = 0 + rec(nums, idx - 1);
        return max(pick, notpick);
    }
    int mem(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx == 0) return dp[0]=nums[0];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = nums[idx] + mem(nums, idx - 2, dp);
        int notpick = mem(nums, idx - 1, dp);
        return dp[idx] = max(pick, notpick);
    }
    void tab(vector<int>& nums, int idx, vector<int>& dp) {
        dp[0]=nums[0];
        int pick;
        int notpick;
        for(int i=1; i<=idx; i++){
            if(i==1){
                pick=nums[1];
                notpick=nums[0];
            }
            else{
            pick= nums[i]+dp[i-2];
            notpick=0+dp[i-1];
            }
            dp[i]=max(pick,notpick);
        }
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // // int ans=rec(nums,n-1);
        // // return ans;
        // // mem(nums, n - 1, dp);
        // tab(nums,n-1,dp);
        // return dp[n - 1];
        if(n==1) return nums[0];
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            int curr=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};