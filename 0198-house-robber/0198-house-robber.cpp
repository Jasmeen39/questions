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
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        // int ans=rec(nums,n-1);
        // return ans;
        mem(nums, n - 1, dp);
        return dp[n - 1];
    }
};