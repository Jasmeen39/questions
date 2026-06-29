class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // int n=nums.size();
        // vector<vector<int>> ans;
        // for(int i=0; i<n-2; i++){
        //     for(int j=i+1; j<n-1; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(nums[i]+nums[j]+nums[k]==0 && num[i]!=nums[j] nums[j]!=nums[k] nums[k]!=nums[i] ){
        //                 ans.push_back({nums[i], nums[j], nums[k]});
        //             };
        //         }
        //     }
        // }
        // return ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];

                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
            }
        }
        return res;
        
    }
};